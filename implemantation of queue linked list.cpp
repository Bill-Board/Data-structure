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
class node{
public:
    int val;
    node* right;
};
class QUQU{
public:
    int num_element;
    node *ekhn, *last;
    QUQU(){
        num_element= 0;
        ekhn = new node();
        last = ekhn;
    }
    void qpush(int val){
        ekhn -> val = val;
        node* n = new node();
        ekhn->right = n;
        ekhn = ekhn->right;
        num_element ++;
    }
    int qtop(){
        return last->val;
    }
    void qpop(){
        node* de = last;
        last = last->right;
        delete(de);
        num_element--;
    }
    bool isempty(){
        return num_element==0;
    }
};

void solve(int tc)
{
    QUQU a;
    while(1){
        int t; cin >> t;
        if(t == 1){/// push
            int x; cin >> x;
            a.qpush(x);
        }
        else if(t==2){ /// top
            if(a.isempty())
                cout << "empty\n";
            else
                cout << a.qtop() << '\n';
        }
        else if(t==3){
            if(a.isempty())
                cout << "empty\n";
            else
                a.qpop();
        }
        else {
            QUQU b = a;
            while(!b.isempty())
                cout << b.qtop() << ' ', b.qpop();
            cout << "\n\n";
        }

    }
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
