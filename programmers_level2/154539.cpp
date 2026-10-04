#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    int size = (int)numbers.size();

    vector<int> answer(size, -1);
    stack<int> indexes;

    for (int i = 0; i < size; i++)
    {
        while (!indexes.empty() && numbers[i] > numbers[indexes.top()])
        {
            answer[indexes.top()] = numbers[i];
            indexes.pop();
        }
        indexes.push(i);
    }

    return answer;
}