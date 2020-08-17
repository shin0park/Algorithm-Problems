//4949번 균형잡힌 세상
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;
const int MAX = 100;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool result = true;
    while (1)
    {
        string input;
        stack<char> s;
        getline(cin, input);
        if (input == ".") break;
        for (auto i : input)
        {
            if (i == '[' || i == '('){
                s.push(i);
            }
            else if (i == ']' || i == ')'){
                if (s.empty()){
                    result = false;
                    break;
                }
                else{
                    char c = s.top();
                    if ((c == '[' && i == ']') || (c == '(' && i == ')'))
                        s.pop();
                    else{
                        result = false;
                        break;
                    }
                }
            }
        }
        if (!s.empty()) result = false;
        if(result) cout << "yes" << '\n';
        else cout << "no" << '\n';
       
        result = true;
    }

    return 0;
}