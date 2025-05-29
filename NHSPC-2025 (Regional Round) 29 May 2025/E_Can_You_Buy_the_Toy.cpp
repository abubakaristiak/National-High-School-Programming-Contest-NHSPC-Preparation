/*
 * Bismillahir Rahmanir Raheem
 *
 * * * * Coder   : abubakaristiak
 * * * * Created : 2025-05-29 || 22:12:03
 * * * * File    : E_Can_You_Buy_the_Toy.cpp
*//*
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

bool isPrime(int n){
    if(n<=1){
        return false;
    }if(n<=2){
        return true;
    }if(n%2==0){
        return false;
    }
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void solve() {
    int n; cin >> n;
    if(n==1){
        cno;
    }else cyes;
    
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