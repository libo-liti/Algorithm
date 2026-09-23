#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int maxIndex = 0, target = location, count = 0;
    queue<int> q(deque<int>(priorities.begin(), priorities.end()));
    sort(priorities.begin(), priorities.end(), greater<int>());

    while (!q.empty())
    {
        int value = q.front();
        bool isPop = (value >= priorities[maxIndex]) ? true : false;

        if (isPop)
        {
            maxIndex++;
            count++;
            if (target == 0)
                break;
            target--;
            q.pop();
        }
        else
        {
            target = (target == 0) ? q.size() - 1 : target - 1;
            q.pop();
            q.push(value);
        }
    }
    answer = count;
    return answer;
}