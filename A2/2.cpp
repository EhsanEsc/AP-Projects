#include<bits/stdc++.h>

using namespace std;

void findValids(map<string,bool>&valid)
{
  ifstream fl("words.txt");
  string str ;

  while(fl >> str)
  {
    valid[str] = true ;
  }
}

void solve(string str , map<string,bool>&valid , int sz = 0 , vector<string>vec = vector<string>() )
{
  if(sz==str.size())
  {
    for(auto s:vec)
      cout << s << " " ;
    cout << endl ;
    return ;
  }

  for(int i=sz;i<str.size();i++)
  {
    string word = str.substr(sz,i-sz+1) ;
    
    if(valid[word])
    {
      vec.push_back(word) ;
      solve(str,valid,i+1,vec) ;
      vec.pop_back() ;
    }
  }
}

int main()
{
  string str ;
  map<string,bool> valid ;

  findValids(valid) ;

  while(cin>>str)
  {
    solve(str,valid) ;
    cout << "***" << endl ;
  }

  return 0;
}
