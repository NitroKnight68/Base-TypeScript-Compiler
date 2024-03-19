// Ignored
/* Ignored */

function trialFunction (param1: number) {
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

    return 3;
}