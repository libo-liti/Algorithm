#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> graph(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < (int)costs.size(); i++)
    {
        graph[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        graph[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;
        answer += cost;

        for (const auto &[distance, next] : graph[node])
        {
            if (!visited[next])
                pq.push({distance, next});
        }
    }

    return answer;
}