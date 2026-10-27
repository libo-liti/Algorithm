#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int number = 1000000007;
    dp[1][0] = 1;
    dp[0][1] = 1;

    for (int i = 0; i < (int)puddles.size(); i++)
    {
        int row = puddles[i][1];
        int col = puddles[i][0];

        graph[row][col] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (graph[i][j] == -1)
                continue;

            if (i == 1)
                dp[i][j] = dp[i][j - 1];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] % number) + (dp[i][j - 1] % number);
        }
    }
    return dp[n][m] % number;
}