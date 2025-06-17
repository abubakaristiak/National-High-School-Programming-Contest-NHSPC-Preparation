#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    // Initialize DP: first and last characters, and current length
    char first_char = words[0][0];
    char last_char = words[0].back();
    int current_length = words[0].size();

    for (int i = 1; i < n; ++i) {
        string word = words[i];
        char word_first = word[0];
        char word_last = word.back();
        int word_length = word.size();

        // Option 1: Place the current word before the existing concatenated word
        int new_length1 = current_length + word_length;
        char new_first1 = word_first;
        char new_last1 = last_char;
        if (word_last == first_char) {
            new_length1 -= 1;
        }

        // Option 2: Place the current word after the existing concatenated word
        int new_length2 = current_length + word_length;
        char new_first2 = first_char;
        char new_last2 = word_last;
        if (last_char == word_first) {
            new_length2 -= 1;
        }

        // Choose the option that gives the maximum length
        if (new_length1 > new_length2) {
            current_length = new_length1;
            first_char = new_first1;
            last_char = new_last1;
        } else {
            current_length = new_length2;
            first_char = new_first2;
            last_char = new_last2;
        }
    }

    cout << current_length << endl;
    return 0;
}