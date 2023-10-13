let myArray = [2, 3, 1, 4, 5, 2];
let myNewList = []
let i = 0;
let j = 0;

const isSorted = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
const sortCheck = (arr) => {
    //base condition
    if (isSorted(arr)) {
        myNewList = arr;
        return;
    }
    else if (arr[i] < arr[j]) {
        i++;
        j++;
        sortCheck(arr);
    }
    else {
        //for swapping 2 values in array
        [arr[i], arr[j]] = [arr[j], arr[i]];
        i = 0;
        j = 1;
        sortCheck(arr);
    }
}
sortCheck(myArray);
console.log(myNewList);