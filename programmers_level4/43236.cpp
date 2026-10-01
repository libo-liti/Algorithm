#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPass(int candi, int limit, const vector<int> &rocks, int distance)
{
    int count = 0;
    int prev = 0;

    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i] - prev < candi)
            count++;
        else
            prev = rocks[i];
    }

    if (distance - prev < candi)
        count++;

    return count <= limit;
}

int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0;
    sort(rocks.begin(), rocks.end());

    int low = 1;
    int high = distance;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        bool isPass = IsPass(mid, n, rocks, distance);

        if (isPass)
        {
            low = mid + 1;
            answer = mid;
        }
        else
            high = mid - 1;
    }
    return answer;
}