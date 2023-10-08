let cards = ["Hearts", "Diamonds", "Clubs", "Spades"]; 
let values = [ 
	"Ace","King","Queen","Jack", 
	"2", "3", "4", "5", "6", 
	"7", "8", "9", "10", 
]; 

let res = []; 

for (let card in cards) { 
	for (let value in values) { 
		res.push(values[value] + " of " + cards[card]); 
	} 
} 

for (let i = res.length - 1; i > 0; i--) { 
	let j = Math.floor(Math.random() * (i + 1)); 
	[res[i], res[j]] = [res[j], res[i]]; 
} 

console.log(res); 
