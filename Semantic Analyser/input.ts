// Ignored
/* Ignored */

import { importedValue1, importedValue2 } from "../Syntax Analyser/input";

function trialFunction (param1: number, param2: string) {
    let valueNumber:number = 3;
    const valueBoolean:boolean = true;
    var valueExpression:number = 5 * 6;

    if(valueNumber > valueExpression && valueBoolean == true){
        console.log("ABC");
    }
    else{
        console.log(valueBoolean);
    }

    let loopValue:number = 10;
    while(loopValue) {
        loopValue = loopValue - 1;  
    }

    console.log(valueNumber + 1);
}