//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<int,int>;

const int N=200005;
ll mod= 1e9+7;

int p_tion(vector<int>&a, int l, int h){
    int p = a[h], i = l - 1; /// p means pivot;
    for(int j = l; j< h; j ++){
        if(a[j] < p)
            swap(a[++i], a[j]);
    }
    swap(a[i+1],a[h]);
    return i+1;
}

void quicksort(vector<int> &a, int l, int h){
    if(l >= h)return;
    int pos = p_tion(a, l, h);
    quicksort(a, l, pos-1);
    quicksort(a, pos+1, h);
}

void solve(int tc)
{
    vector<int> a({6,7,5,2,8,0,12,9,14,6,2});
    int n = a.size();
    quicksort(a, 0, n-1);
    for(auto i: a)
        cout << i << ' ';
    cout << '\n';
}



signed main()
{
    int test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
