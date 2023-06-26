 //BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<iterator>
#include<cstdlib>
#define IOS   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test IOS long long t;cin >> t;while(t--)
#define ses   "\n"
#define whp   " "
#define mxi 3000008
#define REP(i,a,b) for(int i=a; i<b; i++)
#define rep0(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
//set <int, greater <int> > ::iterator it;
//vector<pair<int,int> >a;
//memset(arr,0,sizeof(hg));
///  string single character erase-
///             s.erase(s.begin()+x); where s is st ring name
///               ans x is index;
typedef long long v99;
typedef unsigned long long ull;
using namespace std;
v99 fx[4]= {1,-1,0,0};
v99 fy[4]= {0,0,1,-1};
bool A[mxi];
char str[mxi];
int tree[mxi][26];
int maxIdx;

void changeFreq(int x, int value)
{
	while(x <= maxIdx)
	{
		tree[x] += value;
		x += x & -x;
	}
}

int query(int x)
{
	int sum = 0;
	while(x > 0)
	{
		sum += tree[x];
		x -= x & -x;
	}
	return sum;
}

void update(int i, int j,int value)
{
	changeFreq(i, value);
	changeFreq(j+1,-value);
}
int main()
{

}

