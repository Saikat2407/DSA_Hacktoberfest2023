// map: data stored in key-value form (unique key only)
let array = [["a1", "Harshal"], ["a2", "darshan"], ["a2", "darshan3"]]
let map = new Map(array);
console.log(map);
map.delete("a2");
console.log(map);
console.log(map.get("a1"))
map.set("a2", "again one")
console.log(map);
map.forEach((Element, index) => {
    console.log(index, Element);
})