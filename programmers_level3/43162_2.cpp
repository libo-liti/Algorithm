#include <string>
#include <vector>

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

int solution(int n, vector<vector<int>> computers)
{
    int answer = n;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < (int)computers.size(); i++)
    {
        for (int j = 0; j < (int)computers[i].size(); j++)
        {
            if (computers[i][j] && find(i, parent) != find(j, parent))
            {
                unite(i, j, parent);
                answer--;
            }
        }
    }

    return answer;
}