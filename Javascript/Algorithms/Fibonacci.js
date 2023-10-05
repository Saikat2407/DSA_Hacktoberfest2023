const { log } = require("console");

const readline = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question("Enter a input : ", Num => {
    console.log(Fibonacci(Num));
    readline.close();
});

const Fibonacci = (n) => {
    let a = [0, 1];
    for (let i = 2; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a;

}


