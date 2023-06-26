//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<ll,ll>;

const int N=900005;
const long long inf = 1e14 + 9;
ll mod= 1e9+7;

ll a[N];
template <typename T>
struct st{
    #define lc (n<<1)
    #define rc ((n<<1)+1)

    vector<T> t, lazy;

    st(T n){
        t.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }
    inline void push(int n, int b, int e){
        if (lazy[n] == 0)
            return;
        t[n] += lazy[n];
        if (b != e) {
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
        }
        lazy[n] = 0;
    }

    inline T combine(T a, T b){
        return max(a,b);
    }
    inline void pull(int n){
        t[n]=max(t[lc],t[rc]);
    }
    void update (int n, int b, int e, int i, int j, T v){
        push(n, b, e);
        if(j<b || i>e) return;
        if(i<=b and j>=e){
            lazy[n]=v;
            push(n, b, e);
            return ;
        }
        int mid=(b+e)>>1;
        update(lc, b, mid, i, j, v);
        update(rc, mid+1, e, i, j, v);
        pull(n);
    }

    T query(int n, int b, int e, int i, int j){
        push(n, b, e);
        if(i>e || j<b) return -inf;
        if(i<=b and e<=j) return t[n];
        int mid=(b+e)>>1;
        return combine(query(lc, b,mid, i,j), query(rc, mid+1, e, i, j));
    }
};

void solve(int tc)
{
    int n, k; cin >> n >> k;
    vector<ll> a (n), pre(n+1);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    st<ll> s(k);
    for(int i = 0;i<k; i++)
        s.update(1, 0 , k - 1, i, i, pre[i+1]);
    ll ans = s.query(1 , 0 , k-1, 0, k-1);
    for(int i = 0, j = k; i<n; i++, j++){
        if(j < n){
            s.update(1, 0 , k -1, 0, k - 1, -a[i]);
            ll v = pre[j+1] - pre[i+1];
            s.update(1, 0, k - 1, i % k, i % k, v);
        }
        else{
            s.update(1, 0 , k -1, 0, k - 1, -a[i]);
            ll v = -1e9;
            s.update(1, 0, k - 1, i % k, i % k, v);
        }
        ans = max(ans, s.query(1 , 0 , k-1, 0, k-1));
    }
    cout << ans << '\n';
}



signed main()
{
    int test_case=1;
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}
