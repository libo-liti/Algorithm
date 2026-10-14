#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;
    vector<int> dist(n + 1, -1);
    vector<vector<int>> graph(n + 1);
    queue<int> q;

    q.push(destination);
    dist[destination] = 0;

    for (const auto &road : roads)
    {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto next : graph[node])
        {
            if (dist[next] == -1)
            {
                q.push(next);
                dist[next] = dist[node] + 1;
            }
        }
    }

    for (const auto &node : sources)
        answer.push_back(dist[node]);

    return answer;
}