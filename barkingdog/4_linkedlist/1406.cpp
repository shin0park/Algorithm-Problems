//1406 에디터
#include <iostream>
#include <cstdio>
#include <list>
#include <string>
using namespace std;

list<char> l;
list<char>::iterator t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int m;
    char input, inputX;
    cin >> s;
    cin >> m;
    for (auto e : s)
    {
        l.push_back(e);
    }
    t = l.end();

    for (int i = 0; i < m; i++)
    {
        cin >> input;

        switch (input)
        {
        case 'P':
            cin >> inputX;
            l.insert(t, inputX);
            break;
        case 'L':
            if (l.begin() != t)
                t--;
            break;
        case 'D':
            if (l.end() != t)
                t++;
            break;
        default:
            if (l.begin() != t)
            {
                t--;
                t = l.erase(t);
            }
            break;
        }
    }
    for (auto i : l)
        cout << i;
    return 0;
}