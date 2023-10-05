let a = [-5, -4, -3, -2, 0, 2, 4, 6, 8]

const ans = a.reduce((a, b) => {
    // console.log(a);
    return a + b;
})
console.log(ans);
if (ans) console.log("not zero");
else console.log("zero");