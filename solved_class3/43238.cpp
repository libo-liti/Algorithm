#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long start = 1, middle = 0, end;
    end = (long long)*min_element(times.begin(), times.end()) * n;

    while (start < end)
    {
        middle = (start + end) / 2;
        long long sum = 0;
        for (const auto &time : times)
            sum += (middle / time);

        if (n <= sum)
            end = middle;
        else
            start = middle + 1;
    }
    answer = start;

    return answer;
}