function bubbleSort(arr: number[], size: number) {
    for (let i: number = 0; i < size; i++) {
        for (let j: number = 0; j < size; j++) {
            if (arr[j] > arr[j + 1]) {
                let temp: number = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

let inputArray: number[] = [2, 9, 1, 5, 8];
let inputSize: number = 5;
bubbleSort(inputArray, inputSize);
