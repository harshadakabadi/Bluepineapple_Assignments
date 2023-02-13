#include <bits/stdc++.h>
using namespace std;
int printFrequency(string str)
{
	map<string, int> M;
	string word = "";
	int count=0;
	for (int i = 0; i < str.size(); i++) {
	if (str[i] == ' ') 
	{
		if (M.find(word) == M.end()) {
				M.insert(make_pair(word, 1));
				word = "";
			}
		else {
				M[word]++;
				word = "";
			}
		}
		else
			word += str[i];
	}
	if (M.find(word) == M.end())
		M.insert(make_pair(word, 1));
	else
		M[word]++;
	for (auto& it : M) {
		count=it.second;
		cout << it.first << " - "
			<< it.second
			<< endl;
	}
	return count;
}
void testPrintFrequency(int expectedOutcome)
{
	string myText;
	int result;
	ifstream MyReadFile("FrequencyFile1.txt");
	getline (MyReadFile, myText); 
	cout << myText<<"\n";
	result=printFrequency(myText);
	if(result==expectedOutcome)
	{
		printf("successful\n");
	}
	else
	{	
		printf("unsuccessful\n");
		
	}
	MyReadFile.close();
}
int main()
{
	//string str = "Geeks For Geeks";

	//printFrequency(str);
	int expectedOutcome;
	ifstream MyReadFile("FrequencyOfWordsFile.txt");
	MyReadFile>>expectedOutcome; 
	testPrintFrequency(expectedOutcome);	
	MyReadFile.close();
	return 0;
}
