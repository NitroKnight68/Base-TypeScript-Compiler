function swap(arr: number[], idx1: number, idx2: number) {
    const temp: number = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

function partition(arr: number[], lo: number, hi: number) {
    const pivot: number = arr[hi];
    let idx: number = lo - 1;

    for (let i: number = lo; i < hi; i++) {
        if (arr[i] <= pivot) {
            idx++;
            swap(arr, i, idx);
        }
    }
    idx++;
    swap(arr, hi, idx);
    return idx;
}

function quickSort(arr: number[], lo: number, hi: number) {
    const pivotIndex: number = partition(arr, lo, hi);
    quickSort(arr, lo, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, hi);
}

let arrayInput: number[] = [2, 9, 1, 5, 8];
let arrayLength: number = 5;
quickSort(arrayInput, 0, arrayLength - 1);
