#include <stdio.h>

int checkPerfectNumber(int num)
{
	int sum = 0 , i ;
	if(num > 1)
	{
		for( i = 1 ; i < num ; i++)
		{
			if ( num % i == 0 )
			{
			    sum = sum + i;
			    
			}	
		}
		if(sum == num)
	    {
	    	 return 1;
		}
	    else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
			
}

int TestPerfectNumber(int num , int ExpectedValue)
{
	if(checkPerfectNumber(num) == ExpectedValue)
	{
		printf("successful for %d \n" , num);
	}
	else
	{
		printf("Unsuccessful for %d \n" , num);
	}
}
int main(){
	
	/*int num = 1;
	while( num < 15)
	{
		if(num == 6)
		{
			TestPerfectNumber( num , 1);
		}
		else
		{
			TestPerfectNumber( num , 0);
		}	
		num++;
    }*/
    FILE* ptr;
    int num,expected;
    ptr = fopen("perfectNumberFile.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&num);
    fscanf(ptr,"%d",&expected);
 	TestPerfectNumber(num,expected);   
    fclose(ptr);
    return 0;
    
}
