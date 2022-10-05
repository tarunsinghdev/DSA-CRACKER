#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

        queue<pair<pair<int, int>, int>> q;

        q.push({{KnightPos[0], KnightPos[1]}, 0});
        pair<pair<int, int>, int> t;
        int x, y;
        bool visit[N + 1][N + 1];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                visit[i][j] = false;

        visit[KnightPos[0]][KnightPos[1]] = true;

        while (!q.empty())
        {
            t = q.front();
            q.pop();

            if (t.first.first == TargetPos[0] && t.first.second == TargetPos[1])
                return t.second;

            for (int i = 0; i < 8; i++)
            {
                x = t.first.first + dx[i];
                y = t.first.second + dy[i];

                if ((x >= 1 && x <= N && y >= 1 && y <= N) && !visit[x][y])
                {
                    visit[x][y] = true;
                    q.push({{x, y}, t.second + 1});
                }
            }
        }
    }
}