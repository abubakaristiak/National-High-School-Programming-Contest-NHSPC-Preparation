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

int fipMatrix(vector<vector<int>> &mat){
    int m=mat.size();
    int n=m/2;
    int res=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int v1=mat[i][j];
            int v2=mat[i][m-1-j];
            int v3=mat[m-1-i][j];
            int v4=mat[m-1-i][m-1-j];

            res+=max({v1,v2,v3,v4});
        }
    }
    return res;
}


void solve() {
    int n; cin >> n;
    int sz=2*n;

    vector<vector<int>> mat(sz, vector<int>(sz));
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            cin >> mat[i][j];
        }
    }
    cout << fipMatrix(mat) << endl;
}


int main() {
    fast();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;

    // Alhamdulillah
}