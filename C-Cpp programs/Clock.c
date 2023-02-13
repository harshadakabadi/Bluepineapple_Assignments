#include<stdio.h>
int actualHour=0,actualMinutes=0;
int validateTime(int hour,int minutes)
{
	if(hour<0 || hour>23 || minutes<0 || minutes>59)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void actualTimeClock(int hour,int minutes,int x)
{
    int totalValueOfX=hour*x;
    if(totalValueOfX>=60 && totalValueOfX<+120)
    {
        totalValueOfX=totalValueOfX-x;
    }
    else if(totalValueOfX>120 && totalValueOfX<=180)
    {
        totalValueOfX=totalValueOfX-2*x;
    }
    else if(totalValueOfX>180 && totalValueOfX<=240)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
    else if(totalValueOfX>240 && totalValueOfX<=300)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
    else if(totalValueOfX>300 && totalValueOfX<=360)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
	int totalNoOfMintutes=hour*60+minutes;
	actualMinutes=totalNoOfMintutes-totalValueOfX;
	actualHour=actualMinutes/60;
	actualMinutes=actualMinutes%60;
}
int main()
{
	int hour,minutes,x,choice=1;
	do
	{
	    printf("Enter the hour: ");
	scanf("%d",&hour);
	printf("Enter the minutes: ");
	scanf("%d",&minutes);
	if(validateTime(hour,minutes)==0)
	{
		printf("Invalid Time\n");
		break;
	}
	printf("Enter the x: ");
	scanf("%d",&x);
	if(x<0)
	{
		printf("Invalid value of X\n");
	}
	if(validateTime(0,x)==0)
	{
		printf("Invalid value of x\n");
		break;
	}
	actualTimeClock(hour,minutes,x);
	printf("Actual time is %d hours %d minutes",actualHour,actualMinutes);
	printf("\nDo you want to continue? ");
	scanf("%d",&choice);
	}while(choice);
	return 0;
}
