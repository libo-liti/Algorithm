#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int> &parent)
{
    parent[find(a, parent)] = find(b, parent);
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    for (const auto &c : costs)
    {
        if (find(c[0], parent) != find(c[1], parent))
        {
            unite(c[0], c[1], parent);
            answer += c[2];
        }
    }

    return answer;
}