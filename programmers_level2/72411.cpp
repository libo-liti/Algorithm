#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void DFS(const string &order, string s, int remain, int index, map<string, int> &m)
{
    if (remain == 0)
    {
        m[s]++;
        return;
    }
    for (int i = index; i < (int)order.size(); i++)
        DFS(order, s + order[i], remain - 1, i + 1, m);

    return;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<string, int> m;
    vector<int> cntMax(11, 1);
    for (auto order : orders)
    {
        sort(order.begin(), order.end());
        for (auto n : course)
            DFS(order, "", n, 0, m);
    }

    for (auto [order, num] : m)
    {
        int size = order.size();
        if (cntMax[size] < num)
            cntMax[size] = num;
    }

    for (auto [order, num] : m)
    {
        int size = order.size();
        if (cntMax[size] == num && num >= 2)
            answer.push_back(order);
    }
    return answer;
}