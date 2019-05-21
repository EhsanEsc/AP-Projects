#include <iostream>
#include <string>

#define NULL '\0'

using namespace std;

string removeDuplicates(string input, char lastElement)
{
	if((input[0] == NULL) && (input.size() == 0))
		return input;
	if(input[0] == lastElement)
		return removeDuplicates(input.substr(1), lastElement);
	else
		return input[0] + removeDuplicates(input.substr(1), input[0]);
}

int main()
{
	string input;
	while(cin >> input)
		cout << removeDuplicates(input, NULL) << endl;		
}