#include <iostream>
#include <vector>

using namespace std;

string determineWinner(int N, vector<int>& A) {
    bool allEqual = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] != A[0]) {
            allEqual = false;
            break;
        }
    }

    if (allEqual) {
        if (A[0] == 1) {
            // All baskets have exactly 1 orange
            if (N % 2 == 1) {
                return "Prosanto";
            } else {
                return "Sudipto";
            }
        } else {
            // All baskets have the same number of oranges > 1
            return "Sudipto";
        }
    } else {
        // Baskets have differing counts
        int xorSum = 0;
        for (int num : A) {
            xorSum ^= num;
        }
        if (xorSum != 0) {
            return "Prosanto";
        } else {
            return "Sudipto";
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << determineWinner(N, A) << endl;
    }

    return 0;
}