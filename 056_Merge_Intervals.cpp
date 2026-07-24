#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {

        if (current[1] >= intervals[i][0]) {

            current[1] = max(current[1], intervals[i][1]);

        }

        else {

            ans.push_back(current);

            current = intervals[i];
        }
    }

    ans.push_back(current);

    return ans;
}

int main() {

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:" << endl;

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}