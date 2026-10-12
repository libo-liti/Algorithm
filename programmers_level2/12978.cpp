#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int cnt = 0;
    vector<int> dist(N + 1, -1);
    vector<vector<pair<int, int>>> graph(N + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (const auto &r : road)
    {
        graph[r[0]].push_back({r[2], r[1]});
        graph[r[1]].push_back({r[2], r[0]});
    }

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [edge, node] = pq.top();
        pq.pop();

        if (dist[node] != -1)
            continue;
        dist[node] = edge;

        for (const auto &e : graph[node])
            if (dist[e.second] == -1)
                pq.push({edge + e.first, e.second});
    }

    for (int i = 1; i <= N; i++)
        if (dist[i] <= K)
            cnt++;
    return cnt;
}