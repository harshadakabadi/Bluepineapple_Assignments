
#include<iostream>                       
#include<cstring>   
#include"date_expection.h"
#include"Date.h"
using namespace std;
class Date
{
	private:                    
		int yy,mm,dd,month[13];
	public:                     
		int operator - (Date d2);
		Date operator -(int num);
		Date operator + (int num);
		friend ostream & operator << (ostream &ptr, Date &obj);	
		Date()      
		{
			yy=0;
			mm=0;
			dd=0;
			month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
			month[4] = month[6] = month[9] = month[11] = 30;
			month[2] = 28;
		}	
		Date(string yy,string mm,string dd)    
		{
			month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
			month[4] = month[6] = month[9] = month[11] = 30;
			month[2] = 28;
			if(checkinteger(yy)==1 && ToInt(yy)>=1000 && ToInt(yy)<=9999 )
			{
				this->yy=ToInt(yy);
			}
			else
			{
				InvalidYYException e;
				throw e;
			}
			if(checkinteger(mm)==1 && ToInt(mm)>=1 && ToInt(mm)<=12 )
			{
				this->mm=ToInt(mm);
			}
			else
			{
				InvalidMMException e;
				throw e;
			}
			if(checkinteger(dd)==1 && checkdate(ToInt(yy),ToInt(mm),ToInt(dd))==1 && ToInt(dd)>0 && ToInt(dd)<32)
			{
				this->dd=ToInt(dd);
			}
			else
			{
				InvalidDDException e;
				throw e;
			}
		}
		/*accessors and mutators*/
		void setYear(string yy)
		{
			if(checkinteger(yy)==1 && ToInt(yy)>=1000 && ToInt(yy)<=9999 )
			{
				this->yy=ToInt(yy);
			}
			else
			{
				InvalidYYException e;
				throw e;
			}
		}
		int getYear()
		{
			return yy;
		}
		void setMonth(string mm)
		{
			if(checkinteger(mm)==1 && ToInt(mm)>=1 && ToInt(mm)<=12 )
			{
				this->mm=ToInt(mm);
			}
			else
			{
				InvalidMMException e;
				throw e;
			}
		}
		int getMonth()
		{
			return mm;
		}
		void setDay(string dd)
		{
			if(checkinteger(dd)==1 && checkdate(yy,mm,ToInt(dd))==1 && ToInt(dd)>0 && ToInt(dd)<32)
			{
				this->dd=ToInt(dd);
			}
			else
			{
				InvalidDDException e;
				throw e;
			}
		}
		int getDay()
		{
			return dd;
		}
};
int Date :: operator - (Date d2)              //operator overload -
{
	int nod = 0;
	if (yy < d2.yy || (yy == d2.yy && mm < d2.mm) || (yy == d2.yy && mm == d2.mm && dd < d2.dd))
		cout << "\nSubtraction not possible\n";
	else
	{
		while ((yy!=d2.yy) || (mm!=d2.mm) || (dd!=d2.dd))
		{
			nod ++;
			d2.dd ++;
			if ((d2.yy % 4 == 0 && d2.mm == 2)? d2.dd> 29 : d2.dd > month[d2.mm])
			{
				d2.dd = 1;
				d2.mm++;
			}
			if(d2.mm>12)
			{
				d2.mm = 1;
				d2.yy++;
			}
		}		
	}
	return nod;
}

Date Date::operator + (int num)      //operator overloading + 
{
	while(num!=0)
	{
		num--;
		dd ++;
		if ((yy % 4 == 0 && mm == 2) ? dd>29 : dd > month[mm])
		{
			dd = 1;
			mm++;
		}
		if (mm > 12)
		{
			mm = 1;
			yy++;
		}
	}
	return *this;
}

Date Date::operator - (int num)
{
	int i=0;
	while(i!=num)
	{
		i++;
		dd --;
		
	if(dd<1 && (yy%4==0 || yy%40==0))
	{	
		if (mm==1 || mm==2 || mm==4 || mm==6 || mm==8 || mm==9 || mm==11)
		{
			dd =31 ;
			mm--;
		}
		else if(mm==5 || mm==7 || mm==10 || mm==12)
		{
			dd=30;
			mm--;
		}
		else if(mm=3)
		{
			dd=29;
			mm--;
		}
	}
	else if(dd<1 &&(yy%4!=0 || yy%4!=0))
	{
		if (mm==1 || mm==2 || mm==4 || mm==6 || mm==8 || mm==9 || mm==11)
		{
			dd =31 ;
			mm--;
		}
		else if(mm==5 || mm==7 || mm==10 || mm==12)
		{
			dd=30;
			mm--;
		}
		else if(mm=3)
		{
			dd=28;
			mm--;
		}
	}
		if (mm < 1)
		{
			mm = 12;
			yy--;
		}
	}
	return *this;
}
ostream &operator << (ostream& ptr, Date &obj)
{
	ptr << "Date : " << obj.dd << "/" << obj.mm << "/" << obj.yy;
	return ptr;
}
void setDate()
{
	string yy,mm,dd;
	int i;
	Date d1,d2;
	cout<<"\nEnter Date 1: "<<endl;
	bool invalid=true;
	while(invalid)
	{
		try
		{
			cout<<"Enter year (yyyy):"<<endl;
			getline(cin,yy);
			d1.setYear(yy);
			invalid=false;
		}
		catch(InvalidYYException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	invalid=true;
	while(invalid)
	{
		try
		{
			cout<<"Enter month (mm):"<<endl;
			getline(cin,mm);
			d1.setMonth(mm);
			invalid=false;
		}
		catch(InvalidMMException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	invalid=true;	
	while(invalid)
	{
		try
		{
			cout<<"Enter day (dd):"<<endl;
			getline(cin,dd);
			d1.setDay(dd);
			invalid=false;
		}
		catch(InvalidDDException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	cout<<"\nEnter Date 2: "<<endl;
	invalid=true;
	while(invalid)
	{
		try
		{
			cout<<"Enter year (yyyy):"<<endl;
			getline(cin,yy);
			d2.setYear(yy);
			invalid=false;
		}
		catch(InvalidYYException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	invalid=true;
	while(invalid)
	{
		try
		{
			cout<<"Enter month (mm):"<<endl;
			getline(cin,mm);
			d2.setMonth(mm);
			invalid=false;
		}
		catch(InvalidMMException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	invalid=true;	
	while(invalid)
	{
		try
		{
			cout<<"Enter day (dd):"<<endl;
			getline(cin,dd);
			d2.setDay(dd);
			invalid=false;
		}
		catch(InvalidDDException e)
		{
			cerr<<e.what()<<endl;
			invalid=true;		
		}
		catch(exception e)
		{
			cerr<<e.what()<<endl;
			invalid=true;
		}
	}
	cout<<"Date 1 :"<<d1<<endl;
	cout<<"Date 2 :"<<d2<<endl;
	int no_of_days=d1-d2;
	cout<<"\nNo of days is "<<no_of_days<<endl;

	cout<<"\n\n";
}
int main()
{
	int ch;
	do
	{
		cout<<"\t\t\t1.To Continue"
			<<"\n\t\t\t0.To Exit";
		bool invalid=true;
		do
		{
			try
			{
				string str;
				cout<<"\nEnter your choice :";
				getline(cin,str);
				if(checkinteger(str)==1)
				{
					ch=ToInt(str);
					invalid=false;
				}
				else
				{
					InvalidNumException e;
					throw e;
				}
			}
			catch(InvalidNumException e)
			{
				cerr<<e.what()<<endl;
				invalid=true;
			}
			catch(exception e)
			{
				cerr<<e.what()<<endl;
				invalid=true;
			}
		}while(invalid);
		
		switch(ch)
		{
			case 1:setDate();break;
			case 0:exit(0);break;
			default:cout<<"Invalid Choice\n";	
		}	
		cout<<"\n------------------------------------------------------------------------\n\n";
	}while(ch!=0);
}
