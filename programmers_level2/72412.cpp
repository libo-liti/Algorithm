#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

void DFS(const vector<string> &words, string word, int depth, map<string, vector<int>> &m)
{
    if (depth == 4)
    {
        m[word].push_back(stoi(words[4]));
        return;
    }

    DFS(words, word + words[depth], depth + 1, m);
    DFS(words, word + "-", depth + 1, m);

    return;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    map<string, vector<int>> m;

    for (auto &str : info)
    {
        stringstream ss(str);
        string word;

        vector<string> words;
        while (ss >> word)
            words.push_back(word);
        DFS(words, "", 0, m);
    }

    for (auto &[key, value] : m)
        sort(value.begin(), value.end());

    for (auto &str : query)
    {
        stringstream ss(str);
        string word;

        vector<string> words;
        string key = "";
        while (ss >> word)
            if (word != "and")
                words.push_back(word);
        int score = stoi(words.back());
        words.pop_back();

        for (auto i : words)
            key += i;

        auto iter = m.find(key);
        if (iter == m.end())
        {
            answer.push_back(0);
            continue;
        }
        auto &scores = iter->second;
        auto it = lower_bound(scores.begin(), scores.end(), score);
        answer.push_back(scores.end() - it);
    }

    return answer;
}