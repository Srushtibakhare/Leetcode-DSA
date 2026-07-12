#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int> arr)
{
    vector<int> sorted = arr;

    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> rank;

    int currentRank = 1;

    for (int num : sorted)
    {
        if (rank.find(num) == rank.end())
        {
            rank[num] = currentRank++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rank[arr[i]];
    }

    return arr;
}

int main()
{
    vector<int> arr = {40, 10, 20, 30};

    vector<int> result = arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}