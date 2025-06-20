#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long a, L, G;
    cin >> a >> L >> G;

    // check basic divisibility
    if (L % a != 0 || L % G != 0) {
        cout << -1 << "\n";
        return 0;
    }

    long long La = L / a; // L is divisible by a
    // check for overflow: La * G <= LLONG_MAX
    if (La > LLONG_MAX / G) {
        cout << -1 << "\n";
        return 0;
    }

    long long b = La * G;

    long long gg = gcd(a, b);
    long long ll = a / gg * b; // lcm
    if (gg == G && ll == L) {
        cout << b << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
