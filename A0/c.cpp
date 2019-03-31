// In The Name Of God

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+22;

int main()
{
  int n,m ;
  string c[N] , ans[N];
//  char ans[N][N] ;

  cin>>n>>m ;
  if(n>N || m>N)
  {
  //  cout << "!!!" ;
  //  return 0 ;
  }
  //for(int i=0;i<n;i++)
  //  for(int j=0;j<m;j++)
  //    cin>>c[i][j] ;
  for(int i=0;i<n;i++)
    cin>>c[i] ;
  for(int j=0;j<m;j++)
  {
    for(int i=0;i<n;i++)
    {
      int k=i , r=i , cnt=0 ;
      while(k<n && c[k][j]!='#')
      {
        cnt += (c[k][j]=='.') ;
        k ++ ;
      }
      for(int w=0;w<cnt;w++)
      {
      //  ans[r][j] = '.' ;
        ans[r]+='.' ;
        r++ ;
      }
      for(int w=0;w<k-i-cnt;w++)
      {
    //    ans[r][j]='a' ;
        ans[r]+='a' ;
        r++ ;
      }
      if(k!=n)
      {
    //    ans[r][j]='#' ;
        ans[r]+='#' ;
      }
      i=k ;
    }
  }
  for(int i=0;i<n;i++)
  {
    cout << ans[i] << endl ;
  }


  return 0;
}
