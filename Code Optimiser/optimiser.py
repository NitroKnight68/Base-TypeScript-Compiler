import re
import sys

def isTemporary(s):
    return bool(re.match(r"^t[0-9]*$", s))


def isIdentifier(s):
    return bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s))


def showICG(allLines):
    for line in allLines:
        print(line.strip())


def createSubexpressions(allLines):
    expressions = {}
    variables = {}
    for line in allLines:
        tokens = line.split()
        if len(tokens) == 5:
            if tokens[0] in variables and variables[tokens[0]] in expressions:
                print(tokens[0], variables[tokens[0]], expressions[variables[tokens[0]]])
                del expressions[variables[tokens[0]]]
            expressionRHS = tokens[2] + " " + tokens[3] + " " + tokens[4]
            if expressionRHS not in expressions:
                expressions[expressionRHS] = tokens[0]
                if isIdentifier(tokens[2]):
                    variables[tokens[2]] = expressionRHS
                if isIdentifier(tokens[4]):
                    variables[tokens[4]] = expressionRHS
    return expressions


def eliminateCommonSubexpressions(allLines):
    expressions = createSubexpressions(allLines)
    updatedAllLines = allLines[:]
    for i in range(len(allLines)) :
        tokens = allLines[i].split()
        if len(tokens) == 5 :
            expressionRHS = tokens[2] + " " + tokens[3] + " " + tokens[4]
            if expressionRHS in expressions and expressions[expressionRHS] != tokens[0]:
                updatedAllLines[i] = tokens[0] + " " + tokens[1] + " " + expressions[expressionRHS]
    return updatedAllLines


def evaluateExpression(expression) :
    tokens = expression.split()
    if len(tokens) != 5 :
        return expression
    acceptedOperators = {"+", "-", "*", "/", "*", "&", "|", "^", "==", ">=", "<=", "!=", ">", "<"}
    if tokens[1] != "=" or tokens[3] not in acceptedOperators:
        return expression
    if tokens[2].isdigit() and tokens[4].isdigit() :
        return " ".join([tokens[0], tokens[1], str(eval(str(tokens[2] + tokens[3] + tokens[4])))])
    if tokens[2].isdigit() or tokens[4].isdigit() : #Replace the identifier with a number and evaluate
        op1 = "5" if isIdentifier(tokens[2]) else tokens[2]
        op2 = "5" if isIdentifier(tokens[4]) else tokens[4]
        op = tokens[3]
        try :
            result = int(eval(op1+op+op2))
            if result == 0 : #multiplication with 0
                return " ".join([tokens[0],tokens[1], "0"])
            elif result == 5 : #add zero, subtract 0, multiply 1, divide 1
                if isIdentifier(tokens[2]) and tokens[4].isdigit() :
                    return " ".join([tokens[0], tokens[1], tokens[2]])
                elif isIdentifier(tokens[4]) and tokens[2].isdigit():
                    return " ".join([tokens[0], tokens[1], tokens[4]])
            elif result == -5 and tokens[2] == "0" : # 0 - id
                return " ".join([tokens[0], tokens[1], "-"+tokens[4]])
            return " ".join(tokens)
        except NameError :
            return expression
        except ZeroDivisionError :
            print("Division By Zero!")
            quit()
    return expression


def constantFolding(allLines) :
    for i in range(len(allLines)):
        if ('=' in allLines[i] and allLines[i].count('=') == 1):
            lhs, rhs = allLines[i].split('=')
            try:
                result = eval(rhs)
                allLines[i] = lhs + '= ' + str(result)
            except:
                pass
    updatedAllLines = []
    for line in allLines :
        updatedAllLines.append(evaluateExpression(line))
    return allLines


'''def constantFolding(allLines):
    updatedAllLines = []
    for line in allLines :
        updatedAllLines.append(evaluateExpression(line))
    return updatedAllLines'''

def constantPropagation(lines):
    variables = {}
    for i in range(len(lines)):
        if '=' in lines[i]:
            lhs, rhs = lines[i].split('=')
            # Check if RHS is a constant or contains constants
            rhs_tokens = rhs.split()
            for j, token in enumerate(rhs_tokens):
                if token in variables:
                    rhs_tokens[j] = variables[token]
                elif token.isdigit():
                    rhs_tokens[j] = token  # Replace the constant with itself
            lines[i] = lhs + '= ' + ' '.join(rhs_tokens)
            # Update the variable dictionary if the assignment is to a temporary variable
            if lhs.strip().startswith('t'):
                variables[lhs.strip()] = ' '.join(rhs_tokens)
    return lines

'''def constantPropagation(lines):
    
    variables = {}
    temp_to_remove = []
    for i in range(len(lines)):
        if ('=' in lines[i] and lines[i].count('=') == 1):
            lhs, rhs = lines[i].split('=')
            try:
                if (isinstance(eval(rhs), (int, float)) and 't' in lhs):
                    variables[lhs.strip()] = rhs.strip()
                    temp_to_remove.append(i)
            except:
                exp = rhs.split(' ')
                for j in range(len(exp)):
                    if exp[j] in variables:
                        exp[j] = variables[exp[j]]
                lines[i] = lhs + '=' + ' '.join(exp)
    return lines'''
                
def strengthReductionAndInductionVariableOptimization(lines, variables):
    for index, line in enumerate(lines):
        tokens = line.split()
        if len(tokens) == 5 and tokens[3] == '*' and (tokens[4] == '2' or tokens[2] == '2'):
            variable = tokens[2] if tokens[4] == '2' else tokens[4]
            if variable in variables:
                lines[index] = f"{tokens[0]} = {variable} + {variable}"
    return lines

def optimizeUsingNextUseInfo(lines, variables):
    # Simple next use optimization: Remove lines where the variable is not used again.
    usage = {var: i for i, var in enumerate(reversed(variables), 1)}
    optimized_lines = []
    for line in lines:
        tokens = line.split()
        if len(tokens) >= 3 and tokens[0] in usage:
            optimized_lines.append(line)
    return optimized_lines


def deadCodeElimination(allLines):
    definedTempVars = set()
    usedTempVars = set()
    for line in allLines:
        tokens = line.split()
        
        if not tokens:
            continue
        if isTemporary(tokens[0]):
            definedTempVars.add(tokens[0])
        for token in tokens[1:]:
            if isTemporary(token) and token in definedTempVars:
                usedTempVars.add(token)

    liveTempVars = usedTempVars.copy()
    additionalScan = True

    while additionalScan:
        additionalScan = False
        for line in reversed(allLines):
            tokens = line.split()
            if not tokens:
                continue
            if tokens[0] in liveTempVars:
                for token in tokens[2:]:  # Skip the '=' operator at tokens[1]
                    if isTemporary(token) and token not in liveTempVars:
                        liveTempVars.add(token)
                        additionalScan = True

    updatedAllLines = []
    for line in allLines:
        tokens = line.split()
        if not tokens:
            continue
        if tokens[0] in liveTempVars or not isTemporary(tokens[0]):
            updatedAllLines.append(line)

    return updatedAllLines


if __name__ == "__main__":
    with open("output_file.txt","r") as inFile, open("output_file_final.txt", "w") as outFile:
        for line in inFile:
            if not line.isspace():
                outFile.write(line)
    
    allLines = []
    f = open("output_file_final.txt", "r")
    for line in f:
        allLines.append(line)
    f.close()

    print("\n")

    icgAfterEliminationOfCommonSubexpressions = eliminateCommonSubexpressions(allLines)
    icgAfterConstantFolding = constantFolding(icgAfterEliminationOfCommonSubexpressions)
    icgAfterConstantPropagation = constantPropagation(icgAfterEliminationOfCommonSubexpressions)
    icgAfterConstantFolding2 = constantFolding(icgAfterConstantPropagation)
    icgAfterConstantPropagation2 = constantPropagation(icgAfterConstantFolding2)

    variables = set()
    for line in icgAfterConstantPropagation2:
        tokens = line.split()
        if len(tokens) >= 3:
            variables.add(tokens[0])
    variables=list(variables)
    icgAfterStrengthReduction = strengthReductionAndInductionVariableOptimization(icgAfterConstantFolding, variables)
    icgAfterNextUseInfoOptimization = optimizeUsingNextUseInfo(icgAfterStrengthReduction, variables)
    
    
    icgAfterDeadCodeElimination = deadCodeElimination(icgAfterStrengthReduction)
    print("Optimized ICG: \n")
    showICG(icgAfterDeadCodeElimination)

    print("\n")
    