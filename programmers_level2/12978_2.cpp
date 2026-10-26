#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
using p = pair<int, int>;

int solution(int N, vector<vector<int>> road, int K)
{
    vector<vector<p>> graph(N + 1);
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<p, vector<p>, greater<p>> pq;
    int answer = 0;

    for (const auto &r : road)
    {
        graph[r[0]].push_back({r[2], r[1]});
        graph[r[1]].push_back({r[2], r[0]});
    }

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (const auto &[nextCost, nextNode] : graph[node])
        {
            if (dist[nextNode] > dist[node] + nextCost)
            {
                pq.push({dist[node] + nextCost, nextNode});
                dist[nextNode] = dist[node] + nextCost;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }
    return answer;
}