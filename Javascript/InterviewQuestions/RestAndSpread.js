//Rest Operator
const addNumber = (a, b, c, ...others) => {
    console.log(others);
    return a + b + c;

}
const res = addNumber(3, 5, 4, 9, 30, 85);
console.log(res);


//Spread Operator
//1️⃣: with array
let names = ["Harshal", "Darshan", "Tushar"];

const getNames = (x, y, z) => {
    console.log(x, y, z)

}
getNames(names[0], names[1], names[2]);
getNames(...names); //es 6+ feature
getNames(names);

//2️⃣: with object
//rest
let students = {
    name: "Harshal",
    age: 19,
    hobbies: ["Cricket", "Singing"],
}
const { age, ...rest } = students;
console.log(rest);

//spread
let newStudent = {
    ...students,
    skills: ["javascript", "Javacore"]
}
console.log(newStudent);