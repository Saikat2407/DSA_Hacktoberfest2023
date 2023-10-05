let a = [-5, -4, -3, -2, 0, 2, 2, 4, 6, 8]
// output ->[-4,4]

//time complexity = o(n^2)
const getSumPairZero = (arr) => {
    for (let i of arr) {
        for (let j = 1; j < a.length; j++) {
            if (i + a[j] == 0) {
                console.log(`[${i},${arr[j]}]`)
                return true;
            }
        }
    }
}

console.log(getSumPairZero(a));

//optimize solution for sorted array

const Optimize = (arr) => {
    let left = 0;
    let right = arr.length - 1
    // console.log(left, right);

    while (left < right) {
        if ((arr[left] + arr[right]) == 0) {
            console.log(`[${arr[left]}, ${arr[right]}]`);
            return true;
        }
        else if ((arr[left] + arr[right]) > 0) {
            right--;
        }
        else if ((arr[left] + arr[right]) < 0) {
            left++;
        }
    }

}
Optimize(a);