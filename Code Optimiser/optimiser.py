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
                print(tokens[0], variables[tokens[0]],
                      expressions[variables[tokens[0]]])
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
    for i in range(len(allLines)):
        tokens = allLines[i].split()
        if len(tokens) == 5:
            expressionRHS = tokens[2] + " " + tokens[3] + " " + tokens[4]
            if expressionRHS in expressions and expressions[expressionRHS] != tokens[0]:
                updatedAllLines[i] = tokens[0] + " " + \
                    tokens[1] + " " + expressions[expressionRHS]
    return updatedAllLines


def evaluateExpression(expression):
    tokens = expression.split()
    if len(tokens) != 5:
        return expression
    acceptedOperators = {"+", "-", "*", "/", "*", "&",
                         "|", "^", "==", ">=", "<=", "!=", ">", "<"}
    if tokens[1] != "=" or tokens[3] not in acceptedOperators:
        return expression
    if tokens[2].isdigit() and tokens[4].isdigit():
        return " ".join([tokens[0], tokens[1], str(eval(str(tokens[2] + tokens[3] + tokens[4])))])
    # Replace the identifier with a number and evaluate
    if tokens[2].isdigit() or tokens[4].isdigit():
        op1 = "5" if isIdentifier(tokens[2]) else tokens[2]
        op2 = "5" if isIdentifier(tokens[4]) else tokens[4]
        op = tokens[3]
        try:
            result = int(eval(op1+op+op2))
            if result == 0:  # multiplication with 0
                return " ".join([tokens[0], tokens[1], "0"])
            elif result == 5:  # add zero, subtract 0, multiply 1, divide 1
                if isIdentifier(tokens[2]) and tokens[4].isdigit():
                    return " ".join([tokens[0], tokens[1], tokens[2]])
                elif isIdentifier(tokens[4]) and tokens[2].isdigit():
                    return " ".join([tokens[0], tokens[1], tokens[4]])
            elif result == -5 and tokens[2] == "0":  # 0 - id
                return " ".join([tokens[0], tokens[1], "-"+tokens[4]])
            return " ".join(tokens)
        except NameError:
            return expression
        except ZeroDivisionError:
            print("Division By Zero!")
            quit()
    return expression


def constantFolding(allLines):
    updatedAllLines = []
    for line in allLines:
        updatedAllLines.append(evaluateExpression(line))
    return updatedAllLines


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
    # Use a set to track all defined temporary variables
    definedTempVars = set()
    # Use a set to track all temporary variables that are actually used
    usedTempVars = set()

    # First, identify all defined and used temporary variables
    for line in allLines:
        tokens = line.split()

        if not tokens:
            continue
        if isTemporary(tokens[0]):
            definedTempVars.add(tokens[0])
        # Check for usage in the rest of the tokens
        for token in tokens[1:]:
            if isTemporary(token) and token in definedTempVars:
                usedTempVars.add(token)

    # Calculate the 'live' temporary variables
    liveTempVars = usedTempVars.copy()
    additionalScan = True

    while additionalScan:
        additionalScan = False
        for line in reversed(allLines):
            tokens = line.split()
            if not tokens:
                continue
            # If the output of the line is a temp var that contributes to a live temp var, mark its inputs as live
            if tokens[0] in liveTempVars:
                for token in tokens[2:]:  # Skip the '=' operator at tokens[1]
                    if isTemporary(token) and token not in liveTempVars:
                        liveTempVars.add(token)
                        additionalScan = True

    # Build the updated list of lines, excluding dead code
    updatedAllLines = []
    for line in allLines:
        tokens = line.split()
        if not tokens:
            continue
        # Include the line if the defined temporary variable is live, or if the line does not define a temp var
        if tokens[0] in liveTempVars or not isTemporary(tokens[0]):
            updatedAllLines.append(line)

    return updatedAllLines


"""
def deadCodeElimination(allLines) :
    num_lines = len(allLines)
    definedTempVars = set()
    for line in allLines :
        tokens = line.split()
        if isTemporary(tokens[0]) :
            definedTempVars.add(tokens[0])
    usefulTempVars = set()
    for line in allLines :
        tokens = line.split()
        if len(tokens) >= 2 :
            if isTemporary(tokens[1]) :
                usefulTempVars.add(tokens[1])
        if len(tokens) >= 3 :
            if isTemporary(tokens[2]) :
                usefulTempVars.add(tokens[2])
    unwantedTempVars = definedTempVars - usefulTempVars
    updatedAllLines = []
    for line in allLines :
        tokens = line.split()
        if tokens[0] not in unwantedTempVars :
            updatedAllLines.append(line)
    if num_lines == len(updatedAllLines) :
        return updatedAllLines
    return deadCodeElimination(updatedAllLines)
"""

if __name__ == "__main__":
    with open("icg_base.txt", "r") as inFile, open("icg_final.txt", "w") as outFile:
        for line in inFile:
            if not line.isspace():
                outFile.write(line)

    allLines = []
    f = open("icg_final.txt", "r")
    for line in f:
        allLines.append(line)
    f.close()

    # Elimination of Common Subexpressions
    icgAfterEliminationOfCommonSubexpressions = eliminateCommonSubexpressions(
        allLines)
    # print("ICG after eliminating common subexpressions: \n")
    # showICG(icgAfterEliminationOfCommonSubexpressions)
    # print("\n")

    # Constant folding
    icgAfterConstantFolding = constantFolding(
        icgAfterEliminationOfCommonSubexpressions)
    # print("ICG after constant folding: \n")
    # showICG(icgAfterConstantFolding)
    # print("\n")

    # Strength Reduction and Induction Variable Optimization
    variables = set()
    for line in icgAfterConstantFolding:
        tokens = line.split()
        if len(tokens) >= 3:
            variables.add(tokens[0])
    variables = list(variables)
    icgAfterStrengthReduction = strengthReductionAndInductionVariableOptimization(
        icgAfterConstantFolding, variables)
    # print("Optimized ICG after strength reduction and induction variable optimization: \n")
    # showICG(icgAfterStrengthReduction)
    # print("\n")

    # Next Use Information Optimization
    icgAfterNextUseInfoOptimization = optimizeUsingNextUseInfo(
        icgAfterStrengthReduction, variables)
    # print("Optimized ICG after using next use information: \n")
    # showICG(icgAfterNextUseInfoOptimization)
    # print("\n")

    # Dead Code Elimination
    icgAfterDeadCodeElimination = deadCodeElimination(icgAfterConstantFolding)
    showICG(icgAfterDeadCodeElimination)
    # print("\n")

    # print("Optimization done by eliminating", len(allLines)-len(icgAfterDeadCodeElimination), "lines.")
