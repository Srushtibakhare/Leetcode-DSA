#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    string digits = "123456789";
    vector<int> answer;

    int lowLength = to_string(low).length();
    int highLength = to_string(high).length();

    for (int len = lowLength; len <= highLength; len++)
    {
        for (int start = 0; start + len <= 9; start++)
        {
            int number = stoi(digits.substr(start, len));

            if (number >= low && number <= high)
            {
                answer.push_back(number);
            }
        }
    }

    return answer;
}

int main()
{
    int low = 100;
    int high = 300;

    vector<int> result = sequentialDigits(low, high);

    cout << "Sequential Digits: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}