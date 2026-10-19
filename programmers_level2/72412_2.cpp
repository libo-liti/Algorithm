#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

void DFS(const vector<string> &words, map<string, vector<int>> &m, string key, int cnt)
{
    if (cnt == 4)
    {
        m[key].push_back(stoi(words.back()));
        return;
    }

    DFS(words, m, key + words[cnt], cnt + 1);
    DFS(words, m, key + "-", cnt + 1);

    return;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    map<string, vector<int>> m;

    for (const auto &content : info)
    {
        stringstream ss(content);
        vector<string> words;
        string word;
        while (ss >> word)
            words.push_back(word);

        DFS(words, m, "", 0);
    }

    for (auto &[key, value] : m)
        sort(value.begin(), value.end());

    for (const auto &content : query)
    {
        stringstream ss(content);
        vector<string> words;
        string word, key = "";

        while (ss >> word)
        {
            if (word == "and")
                continue;
            words.push_back(word);
        }
        int score = stoi(words.back());
        words.pop_back();

        for (const auto &s : words)
            key += s;

        auto it = m.find(key);
        if (it == m.end())
        {
            answer.push_back(0);
            continue;
        }

        const auto &scores = it->second;
        auto iter = lower_bound(scores.begin(), scores.end(), score);
        answer.push_back(scores.end() - iter);
    }

    return answer;
}