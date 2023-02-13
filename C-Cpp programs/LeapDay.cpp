#include<stdio.h>
int checkDate(int yy,int mm,int dd)     //function to validate date
{
	int temp=0;
	if(dd<1 || dd>31 || mm<1 || mm>12)
		temp=-1;
	if((yy%4==0 && yy%100!=0) || yy%400==0)
	{
		if(mm==2)
		{
			if(dd>0 && dd<30)
			{
				temp=1;
			}
			else
			{
				temp=-1;
			}
		}
	}
	else 
	{
		if(mm==2)
		{
			if(dd>0 && dd<29)
			{
				temp=1;
			}
			else
			{
				temp=-1;
			}
		}
	}
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
	{
		if(dd>0 && dd<32)
		{
			temp= 1;
		}
		else
		{
			temp= -1;
		}
	}
	else if(mm==4 || mm==6 || mm==9 || mm==11)
	{
		if(dd>0 && dd<31)
		{
			temp= 1;
		}
		else
		{
			temp= -1;
		}
	}
	return temp;
}
int checkLeapDay(int dd,int mm,int yyyy)
{
    if((yyyy%4==0 && yyyy%100!=0) || yyyy%400==0)
    {
        if(dd==29 && mm==2)
        {
            return 1;
        }   
    }
    else
    {
        return 0;
    }
}
void testCheckLeapDayFunc(int dd,int mm,int yyyy,int expectedOutcome)
{
    if(checkLeapDay(dd,mm,yyyy)==expectedOutcome)
    {
        printf("Successful for %d-%d-%d",dd,mm,yyyy);
    }
    else
    {
        printf("Unsuccessful for %d-%d-%d",dd,mm,yyyy);
    }
}
int main() {
    // Write C++ code here
    //testCheckLeapDayFunc(29,2,2000,1);
    //int year=2600,expectedOutcome=1,day;
    /*for(int i=1;i<=4;i++)
    {
        testCheckLeapDayFunc(29,2,year,expectedOutcome);
        year=year+100;
        expectedOutcome=0;
    }
    year=1996,day=25,expectedOutcome=0;
    for(int i=1;i<=5;i++)
    {
        if(day==29)
        {
            expectedOutcome=1;
        }
        testCheckLeapDayFunc(day++,2,year,expectedOutcome);
    }
    
    return 0;*/
    int dd , mm ,yyyy;
    FILE* ptr;
    int num,e;
    ptr = fopen("LeapDayFile.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&dd);
     fscanf(ptr,"%d",&mm);
      fscanf(ptr,"%d",&yyyy);
    fscanf(ptr,"%d",&e);
    //num=getw(ptr);
 	  testCheckLeapDayFunc(dd,mm, yyyy,e);   
    fclose(ptr);
    return 0;
}

