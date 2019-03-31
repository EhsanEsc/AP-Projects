#include<bits/stdc++.h>

using namespace std;

string fix(string str)
{
  if(str.size()==0)
    return "";

  string ans = fix(str.substr(0,str.size()-1)) ;
  if(ans.back()!=str.back())
    ans += str.back() ;

  return ans ;
}

int main()
{
  string str ;
  
  while(cin>>str)
  {
    cout << fix(str) << endl ;
  }

  return 0 ;
}
