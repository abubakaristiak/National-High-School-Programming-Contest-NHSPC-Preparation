#include <bits/stdc++.h>
using namespace std;

void flush_print(int x) {
    cout << x << endl;
    cout.flush();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << "Start" << endl;
        cout.flush();

        int n;
        cin >> n;

        // List of all primes ≤ 100
        vector<int> primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97
        };

        bool all_divisible = false;
        for (int p : primes) {
            flush_print(p);
            int count;
            cin >> count;

            if (count == n) {
                all_divisible = true;
                break;  // We found a common divisor
            }
        }

        if (all_divisible) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        cout.flush();

        string verdict;
        cin >> verdict;
        if (verdict != "Correct") {
            return 0;  // Stop the program if verdict is Incorrect
        }
    }
    return 0;
} 
