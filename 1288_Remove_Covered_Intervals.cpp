#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {

    if (a[0] == b[0])
        return a[1] > b[1];

    return a[0] < b[0];
}

int removeCoveredIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(), compare);

    int count = 1;
    int maxEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][1] <= maxEnd) {
            continue;
        }

        count++;
        maxEnd = max(maxEnd, intervals[i][1]);
    }

    return count;
}

int main() {

    vector<vector<int>> intervals = {
        {1,4},
        {3,6},
        {2,8}
    };

    cout << "Remaining Intervals = "
         << removeCoveredIntervals(intervals);

    return 0;
}