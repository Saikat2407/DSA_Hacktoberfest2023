const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function questionAsync(question) {
    return new Promise((resolve) => {
        rl.question(question, (answer) => {
            resolve(answer);
        });
    });
}

async function processCases() {
    const numCases = await questionAsync("Enter a number of cases: ");

    for (let i = 0; i < numCases; i++) {
        const input = await questionAsync("Enter an input: ");
        const num = parseInt(input);
        console.log(PowerOfTwo(num));
    }

    rl.close(); // Close readline interface when done.
}

processCases();

const PowerOfTwo = (n) => {
    if (n < 1) {
        return false;
    }
    while (n > 1) {
        if (n % 2 !== 0) {
            return false;

        }
        n = n / 2;

    }
    return true;

}