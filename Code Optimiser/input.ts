// Ignored
/* Ignored */

import { importedValue1, importedValue2 } from "../Syntax Analyser/input";

let numberArray: number[] = [5, 6, 7];

function trialFunction(param1: number, param2: string) {
    let valueNumber: number = 3;
    const valueBoolean: boolean = true;
    var valueExpression: number = 5 * 6 + 7 * 4;

    if (valueNumber > valueExpression && 3 > 4) {
        console.log("Hello");
        valueNumber = valueNumber + 5;
    } else {
        console.log(valueBoolean);
        valueNumber = valueNumber - 2;
    }

    while (valueNumber < 5 || 3 < 4) {
        valueExpression = valueExpression + 7;
        while (true) {
            valueNumber = valueNumber * 2;
        }
        valueNumber = valueNumber + 1;
    }

    return valueNumber;
}

function trialFunction2(param1: number, param2: string) {
    let valueNumber: number = 3;
    const valueBoolean: boolean = true;
    var valueExpression: number = 5 * 6 + 7 * 4;

    if (valueNumber > valueExpression && 3 > 4) {
        console.log("Hello");
        valueNumber = valueNumber + 5;
    } else {
        console.log(valueBoolean);
        valueNumber = valueNumber - 2;
    }
}
