let a = [1, 2, 3, 4, 2];
let b = [1, 4, 9, 16, 4];


const checkSquare = (arr1, arr2) => {
    let map1 = {};
    let map2 = {};

    for (item of arr1) {
        map1[item] = (map1[item] || 0) + 1;
    }
    console.log(map1)
    for (item of arr2) {
        map2[item] = (map2[item] || 0) + 1;
    }
    console.log(map2)

    for (let key in map1) {
        console.log("key", key);
        //check thet square of key exist in map 2 ??
        if (!map2[key * key]) {
            return false;
        }
        //value compare
        if (map1[key] !== map2[key * key]) {
            return false;
        }
    }
    return true;
}
console.log(checkSquare(a, b))