const Addition = (a) => {
    return (b) => {
        return (c) => {
            return a + b + c;
        }
    }
}


//not a right way
let res = Addition(2); //closure strore in lexical scope
let ans1 = res(3);
let ans = ans1(5);
console.log(ans);

//right way
let rightway = Addition(2)(3)(4);
console.log(rightway);