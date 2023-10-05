const users = [
    { username: "harshal234", email: "harshalskahar389@gmail.com" },
    { username: "darshan", email: "darshan389@gmail.com" },
    { username: "tushar", email: "tushar@gmail.com" },
    { username: "ridham", email: "ritham389@gmail.com" },

]

const isUserExist = (arr, value) => {
    for (let item of arr) {
        if (item['username'] == value || item['email'] == value) {
            console.log(item)
            return true;
        }
    }
    return false;
}
console.log(isUserExist(users, "harshalskahar389@gmail.com"));