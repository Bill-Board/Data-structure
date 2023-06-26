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
class QUQU{
    public:
    int num_element, ekhn, last;
    vector<int> a;
    QUQU(){
        num_element = last = 0;
        ekhn = -1;
    }
    void qpush(int val){
        a.push_back(val);
        ekhn++;
        num_element ++;
    }
    int qtop(){
        return a[last];
    }
    void qpop(){
        if(num_element)
            last++, num_element--;
    }
    bool isempty(){
        return num_element==0;
    }
};
bool is_bpt(int ind, vector<vector<int>>& g, vector<int> &visi){
    cout << ind << '\n';
    QUQU q;
    q.qpush(ind);
    visi[ind] = 0;
    while(!q.isempty()){
        int val = q.qtop();q.qpop();
        cout << "val " << val << '\n';
        for(auto i: g[val]){
            cout << "i " << i << " clr " << visi[val] << " " << visi[i] << '\n';
            if(visi[i]==visi[val]) return false;
            if(visi[i]==-1)
                visi[i] = visi[val]^1,q.qpush(i);
        }
    }
    cout << "YES\n";
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visi(n, -1);
    bool ans = true;
    for(int i = 0; i<n; i++){
        if(visi[i]!=-1) continue;
        ans &= is_bpt(i, graph, visi);
    }
    return ans;
}

void solve(int tc)
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << isBipartite(g) << '\n';
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
