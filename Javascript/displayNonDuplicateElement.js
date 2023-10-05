let array = [1, 2, 3, 3, 4, 6, 6, 1];
let obj = {};
let ans = [];

for (ele of array) {
    obj[ele] = (obj[ele] || 0) + 1;
}
for (ele of array) {
    if (obj[ele] === 1) {
        ans.push(ele);
    }
}
console.log("using if condition ", ans);
let newAns = array.filter((ele) => obj[ele] === 1);
console.log("using filter method ", newAns);

