#include<stdio.h>
#include<stdlib.h>

int CheckPalindrome(char str[20])
{
	int length , i;
	length = strlen(str);
	int flag=0;
	for(i=0 ; i<length ; i++)
	{
		if(str[i] != str[length-i-1])
		{
			flag=1;
			break;
		}
	}
    if(flag)
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

void TestPalindrome(char str[20] , int ExpectedOutput)
{
	if(CheckPalindrome( str) == ExpectedOutput)
	{
		printf("for %s successful\n",str);
	}
	else
	{
		printf("for %s is unsuccessful\n",str);
	}
}

int main()
{
	/*char str[20];
	TestPalindrome("wow" , 1);
	TestPalindrome("malylam" , 1);
	TestPalindrome("harshada" , 0);*/
	
	FILE* ptr;
    char ch[10];
    int expected;
    ptr = fopen("palindromeFile.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    fscanf(ptr,"%s",ch);
    fscanf(ptr,"%d",&expected);
 	TestPalindrome(ch,expected);   
    fclose(ptr);
    return 0;
}

	
