let a = [1, 2, 3, 4, 5, 6, 7, 8, 9] // total element = 10

const findLargest = (arr, num) => {
    if (num > arr.length) throw new Error("Num is not greater than array");
    else {
        let max = 0;
        for (let i = 0; i < arr.length - num + 1; i++) {
            let tmp = 0;
            for (let j = 0; j < num; j++) {
                // console.log(i, j);
                tmp += arr[i + j];
            }
            if (tmp > max) {
                max = tmp;
            }
        }
        return max;
    }
}
console.log(findLargest(a,3));