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


struct node {
    int endmark;
    node* next[26 + 1];
    node()
    {
        endmark = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void insert(string& str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark ++;
}

ll alabu(node* cur)
{
    ll cnt = 1;
    cnt += cur->endmark;
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            cnt += alabu(cur->next[i]);
    cnt++;
    return cnt;
}



void solve(int tc)
{
    int n; cin >> n;
    root =  new node();
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        insert(s, s.size());
    }
    cout << alabu(root) - 2<< '\n';
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
