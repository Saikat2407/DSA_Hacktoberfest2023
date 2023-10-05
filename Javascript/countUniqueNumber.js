let a = [1, 1, 3, 3, 2, 2, 55, 55, 65, 4, 34, 99, 32, 23, 23];

const UniqueNumber = (arr) => {
    if (arr.length === 0) return new Error("Array is empty")
    let i = 0;
    for (let j = 1; j < arr.length; j++) {
        if (arr[i] !== arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}
console.log(UniqueNumber(a));