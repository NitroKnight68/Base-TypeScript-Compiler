// Ignored
/* Ignored */

import { importedValue1, importedValue2 } from "../Syntax Analyser/input";

function trialFunction(param1: number, param2: string) {
    let valueNumber: number = 3;
    const valueBoolean: boolean = true;
    var valueExpression: number = 5 * 6 + 7 * 4;

    if (valueNumber > valueExpression) {
        console.log("ABC");
        valueNumber = valueNumber + 5;
    } else {
        console.log(valueBoolean);
        valueNumber = valueNumber - 2;
    }

    return valueNumber;
}
