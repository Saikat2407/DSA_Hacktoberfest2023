//hoisting : interpreter appears to move the all declaration to the top of the code before execution
//javascript hoistinf is a process to javascript engine can function , variable & classes initialization push top of the code 

greet();
//function initialization is can push top of the code via javascript engine
function greet() {
    console.log("Harshal");
}

console.log(a); //undefied, if i use let or const datatype then we got error (can't access variable before the initialization)
var a = 8; //Now value set but variable can set top of the code
//Declaration hoisted to the top but initialization (set value in variable) is not

console.log(a);