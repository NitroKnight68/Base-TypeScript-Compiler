// Ignored
/* Ignored */

let valueString: string = "Dru";
let valueNumber: number = 789;
let valueFloat: number = 0.123_456;

type Employee = {
    id: number;
    name: string;
};

type Details = Employee | undefined;

function checkEmployee(emp: Employee) {
    if (emp.id && emp.name) {
        return true;
    } else {
        return false;
    }
}

console.log(valueNumber);
