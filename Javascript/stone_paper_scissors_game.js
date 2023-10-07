const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const choices = ['rock', 'paper', 'scissors'];

function computerChoice() {
    const randomIndex = Math.floor(Math.random() * 3);
    return choices[randomIndex];
}

function determineWinner(playerChoice, computerChoice) {
    if (playerChoice === computerChoice) {
        return 'It\'s a tie!';
    } else if (
        (playerChoice === 'rock' && computerChoice === 'scissors') ||
        (playerChoice === 'paper' && computerChoice === 'rock') ||
        (playerChoice === 'scissors' && computerChoice === 'paper')
    ) {
        return 'You win!';
    } else {
        return 'Computer wins!';
    }
}

rl.question('Choose rock, paper, or scissors: ', (playerChoice) => {
    playerChoice = playerChoice.toLowerCase();
    if (!choices.includes(playerChoice)) {
        console.log('Invalid choice. Please choose rock, paper, or scissors.');
        rl.close();
    } else {
        const computer = computerChoice();
        console.log(`Computer chose ${computer}`);
        const result = determineWinner(playerChoice, computer);
        console.log(result);
        rl.close();
    }
});
