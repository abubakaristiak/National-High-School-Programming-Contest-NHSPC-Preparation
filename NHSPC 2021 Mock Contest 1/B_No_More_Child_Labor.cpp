#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_MASK = 1 << 10;

void solve() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int N, M;
        cin >> N >> M;
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        // Forward DP: from (1,1) to (i,j)
        vector<vector<vector<int>>> forward(N + 2, vector<vector<int>>(M + 2, vector<int>(MAX_MASK, 0)));
        int c = grid[0][0] - 'a';
        int mask = 1 << c;
        forward[1][1][mask] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (i == 1 && j == 1) continue;
                int current_char = grid[i-1][j-1] - 'a';
                int current_mask = 1 << current_char;
                for (int prev_mask = 0; prev_mask < MAX_MASK; ++prev_mask) {
                    int cnt = 0;
                    if (i > 1) cnt = (cnt + forward[i-1][j][prev_mask]) % MOD;
                    if (j > 1) cnt = (cnt + forward[i][j-1][prev_mask]) % MOD;
                    if (cnt > 0) {
                        int new_mask = prev_mask ^ current_mask;
                        forward[i][j][new_mask] = (forward[i][j][new_mask] + cnt) % MOD;
                    }
                }
            }
        }

        // Backward DP: from (i,j) to (N,M)
        vector<vector<vector<int>>> backward(N + 2, vector<vector<int>>(M + 2, vector<int>(MAX_MASK, 0)));
        c = grid[N-1][M-1] - 'a';
        mask = 1 << c;
        backward[N][M][mask] = 1;
        for (int i = N; i >= 1; --i) {
            for (int j = M; j >= 1; --j) {
                if (i == N && j == M) continue;
                int current_char = grid[i-1][j-1] - 'a';
                int current_mask = 1 << current_char;
                for (int prev_mask = 0; prev_mask < MAX_MASK; ++prev_mask) {
                    int cnt = 0;
                    if (i < N) cnt = (cnt + backward[i+1][j][prev_mask]) % MOD;
                    if (j < M) cnt = (cnt + backward[i][j+1][prev_mask]) % MOD;
                    if (cnt > 0) {
                        int new_mask = prev_mask ^ current_mask;
                        backward[i][j][new_mask] = (backward[i][j][new_mask] + cnt) % MOD;
                    }
                }
            }
        }

        vector<vector<int>> res(N, vector<int>(M, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int total = 0;
                int current_char = grid[i-1][j-1] - 'a';
                int current_mask = 1 << current_char;
                for (int m1 = 0; m1 < MAX_MASK; ++m1) {
                    int cnt1 = forward[i][j][m1];
                    if (cnt1 == 0) continue;
                    for (int m2 = 0; m2 < MAX_MASK; ++m2) {
                        int cnt2 = backward[i][j][m2];
                        if (cnt2 == 0) continue;
                        int combined = m1 ^ m2;
                        if ((combined & (combined - 1)) == 0) {
                            total = (total + 1LL * cnt1 * cnt2) % MOD;
                        }
                    }
                }
                res[i-1][j-1] = total;
            }
        }

        cout << "Case " << case_num << ":\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << res[i][j] << (j == M-1 ? '\n' : ' ');
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}