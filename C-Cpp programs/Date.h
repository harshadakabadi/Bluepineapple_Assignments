#include"validations1.h"  //userdefined header file               
using namespace std;
int checkdate(int yy,int mm,int dd)     //function to validate date
{
	if(yy%4 ==0 || yy%40==0)
	{
		if(mm==2)
		{
			if(dd>0 && dd<30)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	else if(yy%4!=0 || yy%40!=0)
	{
		if(mm==2)
		{
			if(dd>0 && dd<29)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
	{
		if(dd>0 && dd<32)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if(mm==4 || mm==6 || mm==9 || mm==11)
	{
		if(dd>0 && dd<31)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}

