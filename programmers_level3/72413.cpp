#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int minFare = 40000001;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 20000001));

    for (const auto &fare : fares)
    {
        graph[fare[0]][fare[1]] = fare[2];
        graph[fare[1]][fare[0]] = fare[2];
    }

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (graph[s][i] + graph[i][a] + graph[i][b] < minFare)
            minFare = graph[s][i] + graph[i][a] + graph[i][b];
    }

    return minFare;
}