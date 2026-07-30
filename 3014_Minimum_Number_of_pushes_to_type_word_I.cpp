#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {

        int ans = 0;

        for (int i = 0; i < word.length(); i++) {
            ans += (i / 8) + 1;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string word1 = "abcde";
    cout << "Output: " << obj.minimumPushes(word1) << endl;

    string word2 = "xycdefghij";
    cout << "Output: " << obj.minimumPushes(word2) << endl;

    string word3 = "abcdefghijklmnopqrstuvwxyz";
    cout << "Output: " << obj.minimumPushes(word3) << endl;

    return 0;
}