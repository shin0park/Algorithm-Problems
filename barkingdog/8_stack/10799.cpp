//10799 쇠막대기
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    int sumBar = 0;
    cin >> input;
    stack<char> s;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '('){
            s.push(i);
        }
        else{
            s.pop();
            if (input[i - 1] == ')')
                sumBar++;
            else if (!s.empty()){
                sumBar += s.size();
            }
        }
    }
    cout << sumBar;
    return 0;
}