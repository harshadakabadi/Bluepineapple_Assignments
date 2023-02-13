#include <stdio.h>

int countDigits(int n)
{
   int count = 0;
   if(n!=0)
   {
       while(n){
           count++;
           n = n/10;
       }
   }
   else if(n == 0)
   {
       count=1;
   }
   else{
       count=0;
   }
   return count;
}

int TestNumberOfDigits(int num , int digit)
{
    if( countDigits(num) == digit )
    {
        printf("case successful for %d\n ",num);
    }
    else
    {
        printf("case unsuccessful for %d\n ",num);
    }
}


int main() {
   
    FILE* ptr;
    int num,expected;
    ptr = fopen("countOfDigitsFile.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&num);
    fscanf(ptr,"%d",&expected);
 	TestNumberOfDigits(num,expected);   
    fclose(ptr);
    
    return 0;
    
   
   
}
