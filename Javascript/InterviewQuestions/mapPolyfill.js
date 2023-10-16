Array.prototype.myMap = function(callback){
  let arr = [];
  let val;
  for(let i=0;i<this.length ;i++){
    val = callback(this[i])
    arr.push(val)
  }
  return arr;
  
}
