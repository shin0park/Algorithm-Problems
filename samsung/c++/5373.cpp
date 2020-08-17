//Å¥ºù
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAX = 1001;
int t, n;
char cube[6][12] = {
    {'o', 'o', 'o', 'b', 'b', 'b', 'r', 'r', 'r', 'g', 'g', 'g'},
    {'o', 'o', 'o', 'g', 'g', 'g', 'r', 'r', 'r', 'b', 'b', 'b'},
    {'w', 'w', 'w', 'b', 'b', 'b', 'y', 'y', 'y', 'g', 'g', 'g'},
    {'w', 'w', 'w', 'g', 'g', 'g', 'y', 'y', 'y', 'b', 'b', 'b'},
    {'w', 'w', 'w', 'o', 'o', 'o', 'y', 'y', 'y', 'r', 'r', 'r'},
    {'w', 'w', 'w', 'r', 'r', 'r', 'y', 'y', 'y', 'o', 'o', 'o'}};
vector<pair<char, char>> moving;
void changed(int index, int tan)
{
    char tmp1, tmp2, tmp3;
    if (tan = '+')
    {
        tmp1 = cube[index][9];
        tmp2 = cube[index][10];
        tmp3 = cube[index][11];
        for (int i = 11; i > 2; i--)
        {
            cube[index][i] = cube[index][i - 3];
        }
        cube[index][0] = tmp1;
        cube[index][0] = tmp2;
        cube[index][0] = tmp3;
    }
    else
    {
        tmp1 = cube[index][0];
        tmp2 = cube[index][1];
        tmp3 = cube[index][2];
        for (int i = 0; i < 9; i++)
        {
            cube[index][i] = cube[index][i + 3];
        }
        cube[index][9] = tmp1;
        cube[index][10] = tmp2;
        cube[index][11] = tmp3;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    string tmp;
    t = 1;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            moving.push_back({tmp[1], tmp[0]});
        }
    }
    for (int i = 0; i < n; i++)
    {
        switch (moving[i].second)
        {
        case 'U':
            /* code */
            break;
        case 'D':
            break;
        case 'F':
            /* code */
            break;
        case 'B':
            break;
        case 'L':
            /* code */
            break;
        case 'R':
            break;

        default:
            break;
        }
    }
    return 0;
}