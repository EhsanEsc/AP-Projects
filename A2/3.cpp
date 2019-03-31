#include<bits/stdc++.h>

using namespace std;

#define IN freopen("in.txt","r",stdin)

const int N = 2e5+22 ;

bool valid(int x,int y,int h,int w)
{
  if(x>=h || x<0) return false;
  if(y>=w || w<0) return false;
  return true ;
}

vector<string> solve(string c[N],int h,int w)
{
  int dirx[4] = {0,0,1,-1} ;
  int diry[4] = {1,-1,0,0} ;
  string dirc[4] = {"R","L","D","U"} ;

  int cnt = 0 ;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cnt += (c[i][j]=='o') ;
  if(cnt==1)
    return vector<string>() ;

  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(c[i][j]!='o') continue ;

      for(int k=0;k<4;k++)
      {
          int deadx = i+dirx[k]   ;
          int deady = j+diry[k]   ;
          int movex = i+2*dirx[k] ;
          int movey = j+2*diry[k] ;

          if(!valid(movex,movey,h,w))
            continue ;
          if(c[deadx][deady]!='o') continue ;
          if(c[movex][movey]!='#') continue ;

          c[deadx][deady] = c[i][j] = '#' ;
          c[movex][movey] = 'o' ;
          vector<string> res = solve(c,h,w) ;

          if(res.size()==0 || res.back()!="Failed")
          {
            string word ="" ;
            word += to_string(i+1) + " " ;
            word += to_string(j+1) + " ";
            word += dirc[k] ;
            res.push_back(word) ;
            return res;
          }

          c[deadx][deady] = c[i][j] = 'o' ;
          c[movex][movey] = '#' ;
      }
    }
  }

  return vector<string>(1 , "Failed") ;
}

int main()
{
  //IN ;
  int h,w ;
  string c[N];

  cin >> h >> w ;
  for(int i=0;i<h;i++)
    cin >> c[i] ;

  vector<string> res = solve(c,h,w) ;

  if(res.size() && res.back()=="Failed")
    cout << "Bad map configuration!" << endl ;
  else
  {
    cout << "Insane!" << endl ;
    for(int i=res.size()-1;i>=0;i--)
    {
      cout << res[i] << endl ;
    }
  }

  return 0 ;
}
