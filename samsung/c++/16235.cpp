//나무 재테크
//단순 vector 시간초과
//이유: 새로태어난 나무의 수는 매우 많은데 그것까지 포함해서 sort를 같이 한이유로보임
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 11;
int board[MAX][MAX];
int given[MAX][MAX];
int n, m, k;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
typedef pair<pair<int, int>, int> pp;
vector<pp> plant;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> given[i][j];
            board[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++)
    {
        pp t;
        cin >> t.first.first >> t.first.second >> t.second;
        plant.push_back(t);
    }
    vector<int> die;
    while (k--)
    {
        //spring
        sort(plant.begin(), plant.end());
        int x, y, age;
        int size = plant.size();
        for (int i = 0; i < size; i++)
        {
            x = plant[i].first.first;
            y = plant[i].first.second;
            age = plant[i].second;
            if (age <= board[x][y])
            {
                board[x][y] -= age;
                plant[i].second++;
            }
            else
                die.push_back(i);
        }
        //summer
        int idx = 0;
        for (auto e : die)
        {
            x = plant[e - idx].first.first;
            y = plant[e - idx].first.second;
            int gage = plant[e - idx].second / 2;
            board[x][y] += gage;
            plant.erase(plant.begin() + e - idx);
            idx++;
        }
        die.clear();
        int nx, ny;
        //fall
        size = plant.size();
        for (int i = 0; i < size; i++)
        {
            if (plant[i].second % 5 == 0)
            {
                x = plant[i].first.first;
                y = plant[i].first.second;
                for (int i = 0; i < 8; i++)
                {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (nx <= 0 || nx > n || ny <= 0 || ny > n)
                        continue;
                    plant.push_back({{nx, ny}, 1});
                }
            }
        }
        //winter
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                board[i][j] += given[i][j];
            }
        }
    }
    cout << plant.size();
    return 0;
}