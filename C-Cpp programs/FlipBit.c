#include<stdio.h>
int byte[8];
    
void getBinary(int num){
    int i = 7;
    while(num){
        byte[i] = num % 2;
        num = num / 2;
        i--; 
    }
}

void flipBit(){
    int flipFromLeft = 3;
    
    if(byte[flipFromLeft-1] == 0){
            byte[flipFromLeft-1] = 1;    
    }
    else{
        byte[flipFromLeft-1] = 0;
    }
}
void main(){
    int num = 234;

    getBinary(num);

    int i;
    printf("Binary representation of %d = ",num);
    for(i = 0; i < 8; i++){
        printf("%d",byte[i]);
    }

    flipBit();

    printf("\n After Flip Binary representation = ");
    for(i = 0; i < 8; i++){
        printf("%d",byte[i]);
    }
    
    int pos = 7;
    int decimalval = 0;
    i = 1;
    int remainder = 0;
    
    while(pos>=0){
        remainder = byte[pos--];
        decimalval = decimalval + remainder * i;
        i = i * 2;
    }
    printf("\n Equivalent hexadecimal value: %X", decimalval);
}
