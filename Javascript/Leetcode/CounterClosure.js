
const createCounter = (n) => {
    return () => {
        return n++;

    };
};


const counter = createCounter(10)
console.log(counter())
console.log(counter())
console.log(counter())


