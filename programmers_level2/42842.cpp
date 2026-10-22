#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    for (int i = 1; i * i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            int row = i;
            int col = yellow / i;

            if ((row + 2) * (col + 2) - yellow == brown)
                return answer = {col + 2, row + 2};
        }
    }
    return answer;
}