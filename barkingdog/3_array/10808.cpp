#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int ALPHA = 26;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    int alpha[ALPHA] = {0,};

    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        alpha[word[i] - 'a']++;
    }
    for (int i = 0; i < ALPHA; i++)
    {
        cout << alpha[i] << " ";
    }
    return 0;
}