#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int solution(vector<string> board)
{
    int answer = -1;
    vector<vector<int>> dist(board.size(), vector<int>(board[0].size(), -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] == 'R')
            {
                q.push({i, j});
                dist[i][j] = 0;
                break;
            }

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        if (board[y][x] == 'G')
            return dist[y][x];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            while (true)
            {
                if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size() || board[ny][nx] == 'D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
                ny += dy[i];
                nx += dx[i];
            }

            if (dist[ny][nx] != -1)
                continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return answer;
}