#include <stdio.h>

int CountDigitOccurences(int num)
{
	 int digits[]= {0,1,2,3,4,5,6,7,8,9 };
	 int CountDigit[] = {0,0,0,0,0,0,0,0,0,0};
	 int result = 0 , i ,count=0;

	 while (num > 0)
	 {
	 	result = num % 10;
	 	for( i = 0 ; i <= 9 ; i++)
	 	{
	 		if( digits[i] == result)
	 		{
	 			CountDigit[i] = CountDigit[i] + 1;
	 		}
		}
		num = num/10;
	 }
	 
	 return CountDigit;
	
}

void TestCountDigitOccurences(int num , int *arr)
{
	int *a = CountDigitOccurences(num);
	int count = 0 , i = 0 ;
	while(i <= 9)
	{
		if(arr[i] != a[i])
		{
			break;
		}
		i++;
		count++;
	}
	if( count == 10)
	{
		printf("Test successful for %d\n", num);
	}
	else
	{
		printf("Test unsuccessful for %d\n", num);
	}
	
}
int main(void) {

    int num;
   /* int expectedOutcome[10] = {0,1,2,1,0,0,0,0,0,0};
    TestCountDigitOccurences(num,expectedOutcome);*/
    
    FILE *ptr;
    ptr = fopen("OccurencesFile.txt", "r");

    //read file into array
    int ExpectedArray[10];
    int i;

	fscanf(ptr,"%d",&num);
    for (i = 0; i < 10; i++)
    {
        fscanf(ptr, "%d", &ExpectedArray[i]);
    }
    TestCountDigitOccurences(num,ExpectedArray);
    
    
  return 0;

}

