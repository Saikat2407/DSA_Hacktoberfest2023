let array = [1, 2, 4, 7, 5, 8];
let min = 1;
let max = Math.max(...array);
let missingArray = [];
// console.log(max);
for (let i = min; i <= max; i++) {
    if (!array.includes(i)) {
        missingArray.push(i);
    }
}
console.log(missingArray);