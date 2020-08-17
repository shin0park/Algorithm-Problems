//재귀호출을 이용한 완전탐색
//n중 for문을 수행시 재귀함수 사용.
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 105;
char result[MAX] = {
    0,
};
bool check[MAX] = {0,};
int n, r;
void recursion(int x);

int main()
{
    cin >> n >> r;
    recursion(0);
    return 0;
}
void recursion(int x)
{
    if (x >= r)
    {
        cout << result<<endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!check[i])
            {
                result[x] = i + 'a';
                check[i] = true;
                recursion(x + 1);
                check[i] = false;
            }
        }
    }
}
