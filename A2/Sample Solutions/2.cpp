#include <iostream>
#include <fstream>
#include <vector>

#define FILE_NAME "words.txt"
#define END_OF_STREAM "***"
#define FAIL_OPEN_MSG "Can't open dictionary file!"
using namespace std;

vector <string> makeDictionary(){
    vector <string> dictionary;
    ifstream dict;
    string word;
    dict.open(FILE_NAME);
    if (dict.is_open())
		while(dict >> word)
            dictionary.push_back(word);
    else{
        cerr << FAIL_OPEN_MSG << endl;
        exit(1);
    }
    dict.close();
    return dictionary;
}
  
bool dictionaryContains(const string &word, const vector <string> &dictionary){
    int n = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < dictionary.size(); i++)
        if (dictionary[i].compare(word) == 0) 
            return true; 
    return false; 
}

void wordBreak(string str, int n, string result, const vector <string> &dictionary){
    for (int i=1; i<=n; i++) {
        string prefix = str.substr(0, i); 
        if (dictionaryContains(prefix, dictionary)){
            if (i == n) { 
                result += prefix; 
                cout << result << endl;
                return; 
            } 
            wordBreak(str.substr(i, n-i), n-i, result + prefix + " ", dictionary);
        } 
    }
}

int main(){
    vector <string> dictionary;
    string input;

    dictionary = makeDictionary();
    while(cin >> input){    
        wordBreak(input, input.size(), "", dictionary);
        cout << END_OF_STREAM <<endl;
    }
    return 0; 
}