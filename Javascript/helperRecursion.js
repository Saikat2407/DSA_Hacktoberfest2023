let a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

const findOdd = (arr) => {
    let result = [];
    const helperRecursive = (inputArray) => {
        console.log("Calling...");
        if (inputArray.length === 0) {
            return;
        } if (inputArray[0] % 2 !== 0) {
            result.push(inputArray[0]);
        }
        helperRecursive(inputArray.slice(1));
    }
    helperRecursive(arr);
    return result;
}

const res = findOdd(a);
console.log(res);
