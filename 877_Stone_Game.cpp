#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

int main() {

    Solution obj;

    vector<int> piles = {5,3,4,5};

    if(obj.stoneGame(piles))
        cout << "Alex Wins";
    else
        cout << "Lee Wins";

    return 0;
}