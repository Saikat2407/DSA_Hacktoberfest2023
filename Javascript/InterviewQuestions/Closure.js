var sum = function (a) {
    console.log("Live Viewers " + a);
    var c = 4;
    return function (b) {
        return a + b + c;
    }
}
const store = sum(5);
console.log(store(6));

var multiplication = function (a, b, c) {
    return {
        getMulTwo: function () {
            return a * b;
        },
        getMulThree: function () {
            return a * b * c
        }
    }
}

var storeMul = multiplication(3, 4, 5);
console.log(storeMul.getMulTwo());
console.log(storeMul.getMulThree());