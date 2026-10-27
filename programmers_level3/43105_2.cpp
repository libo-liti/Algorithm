#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    vector<int> dp((int)triangle.size(), 0);
    dp[0] = triangle[0][0];

    for (int i = 1; i < (int)triangle.size(); i++)
    {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j--)
            dp[j] = max(dp[j - 1], dp[j]) + triangle[i][j];
        dp[0] += triangle[i][0];
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
    return 0;
}