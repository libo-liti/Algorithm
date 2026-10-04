#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    int p1 = 0, p2 = queue1.size(), cnt = 0;
    long long totalSum = 0, queue1Sum = 0, half;
    vector<int> v;

    for (auto i : queue1)
    {
        v.push_back(i);
        totalSum += i;
        queue1Sum += i;
    }
    for (auto i : queue2)
    {
        v.push_back(i);
        totalSum += i;
    }

    if (totalSum % 2 == 1)
        return -1;
    half = totalSum / 2;

    int n = v.size();
    int limit = n * 2;

    while (cnt <= limit)
    {
        if (queue1Sum == half)
            return cnt;

        if (queue1Sum < half)
        {
            queue1Sum += v[p2 % n];
            p2++;
        }
        else
        {
            queue1Sum -= v[p1 % n];
            p1++;
        }
        cnt++;
    }

    return answer;
}