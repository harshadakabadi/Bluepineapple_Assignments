class stack{
    constructor(){
        this.item = [];
    }
    push(element){
        this.item.push(element);
    }
    pop()
    {
        if (this.item.length == 0)
        {
            return "stack is empty";
        }
        return this.item.pop();
    }
    printStack()
    {
        let str = "";
        for (let i = 0; i < this.item.length; i++)
            str = str + this.item[i] + " ";
        return str;
    }
    peek()
    {
        return this.item[this.item.length - 1];
    }
    isExist(element)
    {
        for(let i=0; i < this.item.length-1 ;i++)
        {
            if(this.item[i] === element )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

}
let s1 = new stack();
s1.push(1);
s1.push(2);
s1.push(3);
console.log(s1.printStack());
console.log(s1.isExist(5));









