#include <stdio.h>
int checkForAlphabet(char ch[])
{
    if((ch[0]>='a' && ch[0]<='z')||(ch[0]>='A' && ch[0]<='Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void TestcheckForAlphabet(char ch[],int expectedOutcome)
{
	if(checkForAlphabet(ch)==expectedOutcome)
	{
		printf("Successful \n");
	}
	else
	{
		printf("Unsuccessful \n");		
	}
}
int main() {
    // Write C++ code here
    /*char ch;
    int choice=1;
    do
    {
        printf("enter a character :");
        scanf("%s",ch);
        if(checkForAlphabet(ch))
        {
            printf("alphabet\n");
        }
        else
        {
            printf("not an alphabet\n");
        }
        printf("Do you want to continue? ");
        scanf("%d",&choice);
    }while(choice);*/
    FILE *ptr;
    ptr = fopen("alphabetFile.txt", "r");
    int Expectedoutcome;
    char ch[1];
	if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
	fscanf(ptr,"%c",ch);
    fscanf(ptr, "%d", &Expectedoutcome);
    TestcheckForAlphabet(ch,Expectedoutcome);
    fclose(ptr);    
    return 0;
}
