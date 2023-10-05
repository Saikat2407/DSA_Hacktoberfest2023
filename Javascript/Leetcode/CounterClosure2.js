const createCounter = (init) => {
    var store = init;
    const increment = () => {
        return ++init;
    }
    const reset = () => {
        init = store;
        return init;

    }
    const decrement = () => {
        return --init;
    }
    return { increment, decrement, reset };
};


const counter = createCounter(5)
console.log(counter.increment()); // 6
console.log(counter.reset()); // 5
console.log(counter.decrement()); // 4
