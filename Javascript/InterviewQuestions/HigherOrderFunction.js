//Higher order functions : A Higher order take callbacks (functions) as a arguments & perform some operations in that callbacks
//forEach
//filter
//map
//sort
//reduce

const compnies = [
    { name: "Google", category: "Product Based", start: 1998, end: 2025 },
    { name: "Microsoft", category: "Product Based", start: 1993, end: 2028 },
    { name: "Apple", category: "Service Based", start: 1858, end: 2023 },
    { name: "IBM", category: "Product Based", start: 1902, end: 1999 },
    { name: "Xiaomi", category: "Service Based", start: 2002, end: 2020 },
]

const age = [33, 23, 43, 64, 92, 29, 23, 53, 57, 47, 30, 25];


//forEach
compnies.forEach((element, index) => {
    console.log(index, element);
})

//filter method
let filterbycompnies = compnies.filter((element) => {
    return element.category == "Product Based";

})
console.log(filterbycompnies);

//map functions
const dummy = compnies.map((element, index) => {
    return `${index} ${element.name} ${element.category}`;
})
console.log(dummy);

//sort function
sortedArray = compnies.sort((a, b) => a.start - b.start);
console.log(sortedArray);

//reduce

const sumofage = age.reduce(((a, b) => a + b), 0);
console.log(sumofage);
