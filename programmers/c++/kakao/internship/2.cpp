//튜플
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 501;
int n = 0;
vector<int> solution(string s)
{
    vector<int> answer;
    vector<vector<int>> ss;
    vector<int> temp;
    ss.resize(MAX);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == ',')
            continue;
        if (s[i] == '}')
        {
            if(s[i-1] == '}')
                break;
            ss[temp.size() - 1] = temp;
            temp.clear();
            n++;
        }
        else
            temp.push_back(s[i] - '0');
    }
    for (int i = 0; i < n; i++)
    {
       
        for (int e : ss[i])
        {
            cout << e<<" ";
        }
        cout <<'\n';

    }
    int sum = 0;
    int tempsum = ss[0][0];
    answer.push_back(tempsum);
    for (int i = 1; i < n; i++)
    {
        sum = 0;
        for (int e : ss[i])
        {
            sum += e;
        }
        answer.push_back(sum - tempsum);
        tempsum = sum;
    }

    return answer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "{{20,111},{111}}";
    vector<int> ans = solution(s);
    for (int e : ans)
    {
        cout << e << " ";
    }
    return 0;
}