const { log } = require("console");

const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question("Enter a input : ", Num => {
    console.log(Factorial(Num));
    readline.close();
});



const Factorial = (n) => {
    let a = [1, 1];
    for (let i = 2; i < n; i++) {
        a[i] = a[i - 1] * i;
    }
    return a;

}