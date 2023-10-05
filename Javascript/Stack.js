class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class Stack{
    constructor(data){
        const newNode = new Node(data)
        this.top = newNode
        this.length = 1
    }
    push(data){
        const newNode = new Node(data)
        if(!this.length){
            this.top = newNode
        }else{
            newNode.next = this.top
            this.top = newNode
        }
        this.length++
        return this
    }
    pop(){

        if(!this.length)
        return undefined

        let temp = this.top
        if(this.length == 1){
            
            this.top = temp.next
            temp.next = null
        }
        this.length--
        return temp
    }

    peek(){
        return this.top.data
    }
}

const s1 = new Stack(10)
console.log("Before pushing")
console.log(JSON.stringify(s1))
s1.push(20)
s1.push(30)
s1.push(40)
s1.push(50)
console.log("After pushing")
console.log(JSON.stringify(s1))
s1.pop()
s1.pop()
console.log("After popping")
console.log(JSON.stringify(s1))

console.log(`Peek: ${s1.peek()}`)