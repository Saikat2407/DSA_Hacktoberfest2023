let str = "Harshal Kahar";

const findMaxOccursChar = (s) => {
    let map = {};
    // console.log(s.split(""));
    s.split("").forEach((element) => {
        map[element] = map[element] ? map[element] + 1 : 1;
    })
    console.log(map);
    let max = 0;
    for (key in map) {
        // console.log(map[key]);
        if (max < map[key]) {
            max = map[key]
            char = key
        }

    }
    console.log("max", max, "key", char);

}
findMaxOccursChar(str);