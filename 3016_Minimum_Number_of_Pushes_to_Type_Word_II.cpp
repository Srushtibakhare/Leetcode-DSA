#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minimumPushes(string word) {
    int freq[26] = {0};

    // Count frequency of each character
    for (char c : word) {
        freq[c - 'a']++;
    }

    // Most frequent characters get the cheapest positions
    sort(freq, freq + 26, greater<int>());

    int totalPushes = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            break;

        int pushesNeeded = (i / 8) + 1;
        totalPushes += pushesNeeded * freq[i];
    }

    return totalPushes;
}

int main() {
    string word;

    cout << "Enter word: ";
    cin >> word;

    cout << "Minimum pushes: " << minimumPushes(word) << endl;

    return 0;
}