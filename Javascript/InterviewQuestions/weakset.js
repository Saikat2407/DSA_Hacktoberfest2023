//weak set : only stores objects
//can't iterated

let ws = new WeakSet();
let obj1 = { "Name": "Harshal" }
let obj2 = {};
ws.add(obj1)
ws.add(obj2);
console.log(ws.has(obj1))