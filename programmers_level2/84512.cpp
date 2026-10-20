#include <string>
#include <vector>

using namespace std;

void DFS(const string &gather, const string &word, string &w, int &idx, bool &finish)
{
    if ((int)w.size() >= 6)
        return;
    if (word == w)
    {
        idx++;
        finish = true;
        return;
    }

    if (w != "")
        idx++;

    for (int i = 0; i < (int)gather.size(); i++)
    {
        if (finish)
            return;
        w += gather[i];
        DFS(gather, word, w, idx, finish);
        w.pop_back();
    }

    return;
}

int solution(string word)
{
    string gather = "AEIOU";
    string w;
    int idx = 0;
    bool finish = false;
    DFS(gather, word, w, idx, finish);
    return idx;
}