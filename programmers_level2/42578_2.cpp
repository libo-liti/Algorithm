#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m;

    for (const auto &clothe : clothes)
        m[clothe[1]]++;

    for (const auto &[key, value] : m)
        answer *= (value + 1);

    return answer - 1;
}