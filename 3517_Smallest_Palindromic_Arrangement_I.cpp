#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string smallestPalindrome(string s) {

    vector<int> freq(26, 0);

    // Count frequency of each character
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    string left = "";
    string middle = "";

    // Build left half and middle
    for (int i = 0; i < 26; i++) {

        left += string(freq[i] / 2, char(i + 'a'));

        if (freq[i] % 2 == 1) {
            middle = char(i + 'a');
        }
    }

    // Right half
    string right = left;
    reverse(right.begin(), right.end());

    return left + middle + right;
}

int main() {

    string s = "cccaaaccc";

    cout << "Smallest Palindrome = "
         << smallestPalindrome(s);

    return 0;
}