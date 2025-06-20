/*
||-----------------------------------||
||        Abu Bakar Istiak           ||
||     Chattogram Polytechnic        ||
||        Department of CST          ||
||    abubakar119147@gmail.com       ||
||-----------------------------------||
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define pi pair<ll, ll>
#define vi vector<ll>
#define vpi vector<pi>
#define pb push_back
#define endl "\n"
#define sp " "
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define cyes cout << "Yes\n"
#define cno cout << "No\n"
#define sz(x) (ll)(x).size()
#define minus cout << -1 << endl
#define zero cout << 0 << endl
#define MAX 100000
#define MOD 998244353
#define afor(i,a,b) for (ll i = (a); i < (b); ++i)
#define rfor(i,a,b) for (ll i = (a); i >= (b); --i)
#define asort(v) sort((v).begin(), (v).end())
#define rsort(v) sort((v).begin(), (v).end(), greater<>())
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool specialChar(char ch){
    return ch=='@' || ch=='!' || ch=='#' || ch=='$' || ch=='&';
}
        
void solve() {
    string s; cin >> s;
    int n=s.length();
    int s_cnt=0, b_cnt=0, d_cnt=0, sp_cnt=0;
    for(char ch:s){
        if(ch>='a' && ch<='z'){
            s_cnt++;
        }else if(ch>='A' && ch<='Z'){
            b_cnt++;
        }else if(isdigit(ch)){
            d_cnt++;
        }else if(specialChar(ch)){
            sp_cnt++;
        }
    }
    int rq=n/3;
    if(s.length()>=8 && d_cnt>=1 && sp_cnt>=1 && s_cnt>=rq && b_cnt>=rq ){
        cyes;
    }else cno;
}


int main() {
    fast();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;

    // Alhamdulillah
}