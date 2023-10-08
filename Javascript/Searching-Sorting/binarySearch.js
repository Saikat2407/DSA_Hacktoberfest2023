//Divide & Conquerer Technique
//find the index of given no in a sorted array
let a = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20];

const binarySearch = (arr, search, left, right) => {
    while (left <= right) {
        console.log("how many times")
        let mid = Number.parseInt((left + right) / 2);
        if (arr[mid] === search) {
            return mid + 1;
        }
        else if (arr[mid] < search) {
            console.log("left side ")
            left = mid + 1;
        }
        else {
            console.log("right side")
            right = mid - 1;
        }
    }
    return -1;
}

console.log(binarySearch(a, 17, 0, a.length - 1));