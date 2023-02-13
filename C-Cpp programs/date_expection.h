#include<iostream>
#include <exception>
using namespace std;

class InvalidYYException : public exception{
	public:

 	const char* what() const throw()
 	{
		return "Invalid Year Error\n";
	}	
};
class InvalidMMException : public exception{
public:

 	const char* what() const throw()
 	{
	 	return "Invalid Month Error\n";
	}	
};
class InvalidNumException : public exception{
	public:

 	const char* what() const throw()
 	{
 		return "Invalid Number Error\n";
	}	
};
class InvalidDDException : public exception{
public:

 	const char* what() const throw()
 	{
	 	return "Invalid Day Error\n";
	}	
};
