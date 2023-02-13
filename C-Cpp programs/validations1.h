#include<iostream>
#include<cstring>
#include <sstream>
using namespace std;
int validateISBN(string s)
{
	int len=s.length(),flag=0,i;  
	if(len!=13)
	{
		return -1;	
	}     
	for(i=0;i<len;i++)
	{
		if((s[i]>='0' && s[i]<='9') || s[i]=='-')
		{
			flag++;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s[i]=='-' && s[i+1]=='-')
		{
			return -1;
		}
	}
	if(s[0]=='-' || s[len-1]=='-')
	{
		return -1;
	}
	if(flag==13)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
/*used for name*/
int checkstring(string s) 
{
	int len=s.length(),flag=0;       
	for(int i=0;i<len;i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==' ')
		{
			flag++;
		}
	}
	if(flag==len)
	{
		return 1;               
	}
	else
	{
		return -1;
	}
}
int checkspaces(string s)    
{
	int len=s.length(),flag=0; 
	for(int i=0;i<len;i++)
	{
		if(s[i]==' ')
		{
			flag++;
		}
	}
	if(flag==len)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int checkstring2(string s) 
{
	if(s.length()>=1)
	{
		int len=s.length(),flag=0;       
		for(int i=0;i<len;i++)
		{
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			{
				flag++;
			}
		}
		if(flag==len)
		{
			return 1;               
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}
/*addressline*/
int checkstring1(string s)
{
	int len=s.length(),flag=0;
	for(int i=0;i<len;i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==' ')
		{
			flag++;
		}
	}
	if(len==0)
	{
		return -1;
	}
	if(flag>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
/*allows all numbers*/
int checkinteger(string s)
{
	int len=s.length(),flag=0;  
	for(int i=0;i<len;i++)
	{
	/*	if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==' '
		  ||s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$'
	      || s[i] == '%' || s[i] == '^' || s[i] == '&' || s[i] == '*'
	      || s[i] == '(' || s[i] == ')' || s[i] == '-' || s[i] == '{'
	      || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == ':'
	      || s[i] == ';' || s[i] == '"' || s[i] == '\'' || s[i] == '<'
	      || s[i] == '>' || s[i] == '.' || s[i] == '/' || s[i] == '?'
	      || s[i] == '~' || s[i] == '`' || s[i] == '+' || s[i] == ',')*/
	    if(!(s[i]>='0' && s[i]<='9'))  
		{
			flag=0;
		}
		else
		{
			flag++;
		}
	}
	if(flag>0)   
	{
		if(s[0]=='+' || s[0]=='-')
		{
			flag++;
		}
	}
	if(len==0)
	{
		return -1;
	}
	if(flag==len)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
//isdigit(str)
int checkint()
{
	string str;
	int n1;
	getline(cin,str);
	stringstream ss;
	if(checkinteger(str)==1 && str.length()!=0)
	{
		ss<<str;
		ss>>n1;
	}
	else
	{
		while(checkinteger(str)==-1 || str.length()==0)
		{
			cout<<"Invalid input\nEnter again :";
			getline(cin,str);
		}
		ss<<str;
		ss>>n1;
	}
	return n1;
}
int checkfloat(string s)
{
	int len=s.length(),flag1=0,flag2=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			flag2++;
		}
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' 
		   || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='.' )
		{
			flag1++;
		}
		else
		{
			flag1=0;
		}
	}
	if(flag1>0)   
	{
		if(s[0]=='+' || s[0]=='-')
		{
			flag1++;
		}
	}
	if(len==0)
	{
		return -1;
	}
	if(len==1 && flag1==1 && flag2==1)
	{
		return -1;
	}
	if(flag1==len && (flag2==1 || flag2==0))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
float checkfloat1()
{
	string str;
	float n1;
	getline(cin,str);
	stringstream ss;
	if(checkfloat(str)==1 && str.length()!=0)
	{
		ss<<str;
		ss>>n1;
	}
	else
	{
		while(checkfloat(str)==-1 || str.length()==0)
		{
			cout<<"Invalid input\nEnter again :";
			getline(cin,str);
		}
		ss<<str;
		ss>>n1;
	}
	return n1;
}
string stringLower(string upTxt)
{
	for (int i = 0; i < upTxt.length(); i++)
  	{
  		if(upTxt[i] >= 'A' && upTxt[i] <= 'Z')
  		{
  			upTxt[i] = upTxt[i] + 32;
		}
  	}
  	return upTxt;
}
int ToInt(string s)
{
	int n;
	stringstream ss;
	ss<<s;
	ss>>n;
	return n; 
}
float ToFloat(string s)
{
	float n;
	stringstream ss;
	ss<<s;
	ss>>n;
	return n; 
}
string ToString(int n)
{
	string str;
	stringstream ss;
	ss<<n;
	ss>>str;
	return str;
}
string ToString1(float n)
{
	string str;
	stringstream ss;
	ss<<n;
	ss>>str;
	return str;
}
