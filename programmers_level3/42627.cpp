#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    int sumTime = 0, currentTime = 0, idx = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    sort(jobs.begin(), jobs.end());

    while (idx < (int)jobs.size() || !pq.empty())
    {
        if (pq.empty() && jobs[idx][0] > currentTime)
            currentTime = jobs[idx][0];

        while (idx < (int)jobs.size() && jobs[idx][0] <= currentTime)
        {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        auto [process, request] = pq.top();
        pq.pop();

        currentTime += process;
        sumTime += (currentTime - request);
    }

    return sumTime / (int)jobs.size();
}