//괄호 9012번
//stack으로 풀이
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
const int MAX = 50;
char ps[MAX];
void psResult(int n, bool result[]);
int main()
{
    int n;
    cin >> n;
    bool *result = new bool[n];
    for (int i = 0; i < n; i++)
    {
        psResult(i, result);
    }
    for (int i = 0; i < n; i++)
    {
        if (result[i] == false)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }
    delete[] result;
    return 0;
}
void psResult(int n, bool result[])
{
    stack<char> s;
    cin >> ps;
    int len = strlen(ps);
    for (int i = 0; i < len; i++)
    {
        if (ps[i] == '(')
        {
            s.push(ps[i]);
        }
        else
        {
            if (s.size() == 0)
            {
                result[n] = false;
                return;
            }
            s.pop();
        }
    }
    if (s.size() == 0)
        result[n] = true;
    else
    {
        result[n] = false;
    }
}

/*
//string 으로도 가능
//stack으로 풀이
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int MAX = 50;
//char ps[MAX];

void psResult(int n, string ps[], bool result[]);
int main()
{
    int n;
    cin >> n;
    bool *result = new bool[n];
    string *ps = new string [n];
   
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
        psResult(i, ps, result);
    }
    for (int i = 0; i < n; i++)
    {
        if (result[i] == false)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }
    delete[] result;
    delete[] ps;
    return 0;
}
void psResult(int n, string ps[], bool result[])
{
    stack<char> s;
    for (int i = 0; i < ps[n].length(); i++)
    {
        if (ps[n][i] == '(')
        {
            s.push(ps[n][i]);
        }
        else
        {
            if (s.size() == 0)
            {
                result[n] = false;
                return;
            }
            s.pop();
        }
    }
    if (s.size() == 0)
        result[n] = true;
    else
    {
        result[n] = false;
    }
}
*/