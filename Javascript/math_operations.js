// JavaScript ES6. You can import these functions to do simple Mathematical operations

// Function to add two numbers
export const add = (a, b) => a + b;

// Function to subtract two numbers
export const subtract = (a, b) => a - b;

// Function to multiply two numbers
export const multiply = (a, b) => a * b;

// Function to divide two numbers
export const divide = (a, b) => (b === 0 ? "Division by zero is not allowed" : a / b);

// Function to calculate the percentage of a number
export const percentage = (value, percent) => (value * percent) / 100;