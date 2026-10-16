#include <string>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>> &dungeons, int remain, int cnt, int &best, vector<bool> &visited)
{
    if (cnt > best)
        best = cnt;

    for (int i = 0; i < (int)dungeons.size(); i++)
    {
        if (dungeons[i][0] <= remain && !visited[i])
        {
            visited[i] = true;
            DFS(dungeons, remain - dungeons[i][1], cnt + 1, best, visited);
            visited[i] = false;
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int best = 0;
    vector<bool> visited((int)dungeons.size(), false);

    DFS(dungeons, k, 0, best, visited);

    return best;
}