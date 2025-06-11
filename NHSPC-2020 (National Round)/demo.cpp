#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long a, b, c, m;
        cin >> a >> b >> c >> m;

        vector<long long> stack;
        vector<long long> max_stack;
        vector<long long> min_stack;
        long long xor_result = 0;
        long long V_prev = b;

        for (int i = 0; i < N; ++i) {
            long long V_i = (a * V_prev + c) % m;
            V_prev = V_i;

            if (V_i % 2 == 1) {
                // Type 1: add X = V_i
                stack.push_back(V_i);
                // Update max_stack
                if (max_stack.empty()) {
                    max_stack.push_back(V_i);
                } else {
                    max_stack.push_back(max(V_i, max_stack.back()));
                }
                // Update min_stack
                if (min_stack.empty()) {
                    min_stack.push_back(V_i);
                } else {
                    min_stack.push_back(min(V_i, min_stack.back()));
                }
            } else {
                // Type 2: remove last element
                if (!stack.empty()) {
                    stack.pop_back();
                    max_stack.pop_back();
                    min_stack.pop_back();
                }
            }

            // Calculate beauty
            long long beauty = 0;
            if (!stack.empty()) {
                beauty = max_stack.back() + min_stack.back();
            }
            xor_result ^= beauty;
        }

        cout << xor_result << '\n';
    }
}

int main() {
    solve();
    return 0;
}