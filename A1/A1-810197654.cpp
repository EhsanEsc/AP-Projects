// In The Name Of God
#include<bits/stdc++.h>

#define pb push_back
#define IN freopen("3.in","r",stdin)
#define OUT freopen("out.txt","w",stdout)

using namespace std;

const int N = 1e3+22 ;

string getWord(string &ln)
{
	if(ln=="") return "" ;
	int i=0 ;
	while(i<ln.size() && ln[i]==' ')
	{
		i++ ;
	}
	ln = ln.substr(i) ;
	if(ln=="") return "" ;

	while(i<ln.size() && ln[i]!=' ')
	{
		i++ ;
	}
	string res = ln.substr(0,i) ;
	if(i!=ln.size())
		ln = ln.substr(i+1);
	else
		ln = "" ;
	return res ;
}

void finishIt(int cnt)
{
	cout << "Syntax error at line " << cnt << endl ;
	exit(0) ;
	return ;
}

void finishInput(int cnt)
{
	cout << "Unexpected end of input" << endl ;
	exit(0) ;
	return ;
}

int findVal(string str,map<string,int>&val)
{
	if(str[0]>='0' && str[0]<='9')
	{
		int res = 0;
		for(int i=0;i<str.size();i++)
		{
			res*=10 ;
			res+=(str[i]-'0');
		}
		return res;
	}
	else
	{
		return val[str] ;
	}
}

void splitLine(string &ln)
{
	string ret = "" ;
	while(true)
	{
		string str = getWord(ln) ;
		if(str=="")
			break;
		for(int i=0,j=0;i<str.size();i++)
		{
			if(str[i]=='+' || str[i]=='!' || str[i]=='-' || str[i]=='?' || str[i]=='=')
			{
				ret += str.substr(i,1) + " " ;
			}
			else if(str[i]>='0' && str[i]<='9')
			{
				j=i ;
				while(j<str.size() && str[j]>='0' && str[j]<='9')
				{
					j++ ;
				}
				ret += str.substr(i,j-i) + " " ;
			}
			else
			{
				j=i ;
				while(j<str.size() && (!(str[j]=='+' || str[j]=='!' || str[j]=='-' || str[j]=='?' || str[j]=='=')))
				{
					j++ ;
				}
				ret += str.substr(i,j-i) + " " ;
				i=j-1 ;
			}
		}
	}
	ln = ret ;
}

int main()
{
	//IN ;// OUT ;
	int ted=0 ;
	vector<int>vtype ;
	vector<string>vname ;
	vector<string>vvecminus[N] , vvecplus[N] ;
	vector<int>vin ;
	map<string,int>val ;

	for(int cnt=1;;cnt++)
	{
		string ln ;
		getline(cin,ln) ;
		splitLine(ln) ;
		string str = getWord(ln) ;
		if(str=="")
		{
			vtype.pb(0) ;
			vname.pb("") ;
			continue ;
		}
		if(str=="run")
			break;
		else if(str=="?")
		{
			str = getWord(ln) ;
			vtype.pb(1) ;
			vname.pb(str) ;
			str = getWord(ln) ;
			if(str!="")
				finishIt(cnt) ;
		}
		else if(str=="!")
		{
			str = getWord(ln) ;
			vtype.pb(2) ;
			vname.pb(str) ;
			str = getWord(ln) ;
			if(str!="")
				finishIt(cnt) ;
		}
		else
		{
			vtype.pb(3) ;
			vname.pb(str) ;
			str = getWord(ln) ;
			if(str!="=")
				finishIt(cnt) ;
			int cur = 1 ; // 1+ 2- 3Na
			while(true)
			{
				str = getWord(ln) ;
				if(str=="")
				{
					if(cur!=3)
						finishIt(cnt) ;
					break;
				}
				if(str=="+" || str=="-")
				{
					if(cur!=3)
						finishIt(cnt) ;
					if(str=="+")
						cur = 1;
					else
						cur = 2;
				}
				else
				{
					if(cur==3)
						finishIt(cnt) ;
					if(cur==1)
						vvecplus[ted].pb(str) ;
					else
						vvecminus[ted].pb(str) ;
					cur = 3 ;
				}
			}
			ted++;
		}
	}
	ted = 0;
	int num;
	while(cin>>num)
	{
		vin.pb(num) ;
	}
	int tin=0 ;

	for(int i=0;i<vtype.size();i++)
	{
		if(vtype[i]==0)
		{
			continue ;
		}
		if(vtype[i]==1)
		{
			string str = vname[i] ;
			if(tin==vin.size())
				finishInput(i+1) ;
			val[str] = vin[tin] ;
			tin++;
		}
		else if(vtype[i]==2)
		{
			cout << val[vname[i]] << endl ;
		}
		else if(vtype[i]==3)
		{
			int res=0;
			for(auto s:vvecminus[ted])
			{
				res -= findVal(s,val) ;
			}
			for(auto s:vvecplus[ted])
			{
				res += findVal(s,val) ;
			}
			val[vname[i]] = res ;
			ted++ ;
		}
	}

	return 0 ;
}
