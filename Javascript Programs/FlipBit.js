let byte = new Array(8);
function getBinary( num){
    let i = 7;
    while(num){
        byte[i] = num % 2;
        num = num / 2;
        i--; 
    }
}

function flipBit(){
     flipFromLeft = 3;
    
    if(byte[flipFromLeft-1] == 0){
            byte[flipFromLeft-1] = 1;    
    }
    else{
        byte[flipFromLeft-1] = 0;
    }
}
function validateFlipBit(num,exceptedOutcome)
{
    getBinary(num);
    flipBit();
    let count=0;
    for(let i=0;i<8;i++)
    {
        if(byte[i]==exceptedOutcome[i])
        {
            count++;
        }
    }
    if(count==8)
    {
        console.log("Successful");
    }
    else{
        console.log("Unsuccessful");
    }
}
let exceptedOutcome=[1,1,0,0,1,0,1,0];
validateFlipBit(234,exceptedOutcome);
