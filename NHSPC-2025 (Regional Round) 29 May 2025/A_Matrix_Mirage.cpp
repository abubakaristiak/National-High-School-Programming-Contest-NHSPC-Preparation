// according to gemini
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

bool is_valid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool find_path(int r, int c, int n, int m, int x, const vector<vector<int>>& v, vector<vector<bool>>& visited) {
    if (!is_valid(r, c, n, m) || v[r][c] == -1 || visited[r][c]) {
        return false;
    }
    visited[r][c] = true;
    if (v[r][c] == x) {
        return true;
    }
    return find_path(r + 1, c, n, m, x, v, visited) || find_path(r, c - 1, n, m, x, v, visited);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    int x; cin >> x;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    if (find_path(0, m - 1, n, m, x, v, visited)) {
        yes;
    } else {
        no;
    }
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