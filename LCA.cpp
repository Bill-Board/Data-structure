//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME


// Shoeb Akibul Islam
// Dept of ICE, NSTU


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using namespace __gnu_pbds;

typedef long long v99;
typedef unsigned long long ull;
typedef long double dll;
typedef complex<double> pov99;
#define dua ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define i_love_u_huu dua long long t;cin >> t;while(t--)
#define ses   "\n"
#define whp   " "
#define mxi 200003
#define mp make_pair
#define pii pair<v99, v99>
#define pf prv99f
#define sf scanf
#define ff first
#define yes cout<<"YES"<<ses;
#define no cout<<"NO"<<ses;
#define sob(z)  (z).begin(), (z).end()
#define ss second
#define pb push_back
#define rep0(i,a,b) for(v99 i=a; i<b; i++)
#define rep1(i,a,b) for(v99 i=a; i<=b; i++)
#define rep0in(i,a,b) for(v99 i=a-1; i>=b; i--)
#define rep1in(i,a,b) for(v99 i=a; i>b; i--)
#define repv(i,a) for(auto i=a.begin(); i!=a.end();++i)
#define INF 0x3f3f3f3f
#define CLR(a,b) memset(a,b,sizeof(a));
#define PI acos(-1)
#define what_is(x) cerr<<x<<ses;
#define vc    vector<char>
#define vll    vector<v99>
#define vs    vector<string>
#define dqll   deque<v99>
#define dqc   deque<char>
#define lll   list<v99>
#define lic   list<char>

//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 100002
v99 L[mx]; //লেভেল
v99 P[mx][22]; //স্পার্স টেবিল
v99 T[mx]; //প্যারেন্ট
vector<v99> g[mx];
void dfs(v99 from,v99 u,v99 dep)
{
    T[u]=from;
    L[u]=dep;
    for(v99 i=0;i<(v99)g[u].size();i++)
    {
        v99 v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

v99 lca_query(v99 p, v99 q) //N=নোড সংখ্যা
  {
      v99 tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        v99 next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(v99 N)
  {
      memset (P,-1,sizeof(P)); //শুরুতে সবগুলো ঘরে -১ থাকবে
      v99 i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

void solve()
{
    /// code is here->
    g[0].pb(1);
	g[0].pb(2);
	g[2].pb(3);
	g[2].pb(4);
	dfs(0, 0, 0);
	lca_init(5);
	cout<<lca_query(3,4)<<ses;
}



signed main()
{
    //dua
    //freopen("data.out","w",stdout);
    //while(1)
    //i_love_u_huu
    solve();
    return 0;
}



      ///  Alhamdulillah...
