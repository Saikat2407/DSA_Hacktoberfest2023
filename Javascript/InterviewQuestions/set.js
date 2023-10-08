//set :It contains only unique values in array from not key-value form

let myArray = [1, 2, 3, 4, 4]
let set = new Set(myArray);
console.log(set.size);
set.add("Harshal")
console.log(set);
set.delete(4)
console.log(set);
set.add({ name: "Harshal S. Kahar" })
console.log(set);
console.log(set.has("Harshal"));
set.forEach((element) => {
    console.log(element);
})
set.clear();
console.log(set);


