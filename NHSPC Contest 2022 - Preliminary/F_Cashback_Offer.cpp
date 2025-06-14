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


void solve() {
    string s; cin >> s;
    map<char,int> mp;
    for(char ch:s){
        mp[ch]=(ch-'a'+1)*100;
    }

    int res=0;
    for(auto ch:s){
        res+=mp[ch];
    }
    
    cout << res << endl;
}



// TODO: CPU Limit-deep
// int main() {
//     fast();
//     int t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;

//     // Alhamdulillah
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// // Cashback of a prefix
// ll cashback_value(const string& prefix) {
//     ll sum = 0;
//     for (char ch : prefix) {
//         sum += (ch - 'a' + 1) * 100;
//     }
//     return sum;
// }

// // KMP prefix function to count overlapping occurrences
// vector<int> build_prefix_function(const string& pattern) {
//     int m = pattern.size();
//     vector<int> lps(m, 0);
//     for (int i = 1, len = 0; i < m; ) {
//         if (pattern[i] == pattern[len]) {
//             lps[i++] = ++len;
//         } else if (len) {
//             len = lps[len - 1];
//         } else {
//             lps[i++] = 0;
//         }
//     }
//     return lps;
// }

// int count_occurrences(const string& text, const string& pattern) {
//     int n = text.size();
//     int m = pattern.size();
//     vector<int> lps = build_prefix_function(pattern);

//     int i = 0, j = 0, count = 0;
//     while (i < n) {
//         if (text[i] == pattern[j]) {
//             i++; j++;
//         }
//         if (j == m) {
//             count++;
//             j = lps[j - 1]; // allow overlap
//         } else if (i < n && text[i] != pattern[j]) {
//             if (j) j = lps[j - 1];
//             else i++;
//         }
//     }
//     return count;
// }

// void solve() {
//     string s;
//     cin >> s;
//     int n = s.size();
//     ll max_cashback = 0;
//     string prefix = "";

//     for (int i = 0; i < n; ++i) {
//         prefix += s[i];
//         ll value = cashback_value(prefix);
//         int occ = count_occurrences(s, prefix);
//         max_cashback = max(max_cashback, value * occ);
//     }
//     cout << max_cashback << '\n';
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) solve();
// }
