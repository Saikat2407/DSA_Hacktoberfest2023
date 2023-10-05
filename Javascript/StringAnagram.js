const isAnagram = (s1, s2) => {
    if (s1.length !== s2.length) return false;

    let obj = {};

    for (let letter of s1) {
        obj[letter] = (obj[letter] || 0) + 1;
    }
    console.log(obj);

    for (let letter of s2) {
        if (!obj[letter]) return false
        obj[letter]--;
    }
    return true;
}

console.log(isAnagram('hellwo', 'llheo'));