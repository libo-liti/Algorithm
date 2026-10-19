#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void DFS(unordered_set<int> &candi, vector<bool> &visited, const string &numbers, string number)
{
    for (int i = 0; i < (int)numbers.size(); i++)
    {
        if (!visited[i])
        {
            number += numbers[i];
            visited[i] = true;
            candi.insert(stoi(number));
            DFS(candi, visited, numbers, number);
            number.pop_back();
            visited[i] = false;
        }
    }
    return;
}

int solution(string numbers)
{
    int answer = 0;
    vector<bool> prime;
    vector<bool> visited((int)numbers.size(), false);
    unordered_set<int> candi;

    DFS(candi, visited, numbers, "");

    int n = *max_element(candi.begin(), candi.end());
    prime.resize(n + 2, true);

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            prime[j] = false;
    }

    for (const auto &content : candi)
    {
        if (prime[content])
            answer++;
    }

    return answer;
}