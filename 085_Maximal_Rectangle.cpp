#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangle(vector<int>& heights)
{
    stack<pair<int,int>> st;
    int maxArea = 0;

    for(int i = 0; i < heights.size(); i++)
    {
        int start = i;

        while(!st.empty() && st.top().second > heights[i])
        {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();

            maxArea = max(maxArea, height * (i - index));

            start = index;
        }

        st.push({start, heights[i]});
    }

    while(!st.empty())
    {
        int index = st.top().first;
        int height = st.top().second;
        st.pop();

        maxArea = max(maxArea, height * ((int)heights.size() - index));
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    if(matrix.empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols,0);

    int ans = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j]=='1')
                heights[j]++;
            else
                heights[j]=0;
        }

        ans = max(ans, largestRectangle(heights));
    }

    return ans;
}

int main()
{
    vector<vector<char>> matrix =
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Largest Rectangle = "
         << maximalRectangle(matrix)
         << endl;

    return 0;
}