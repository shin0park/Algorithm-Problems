//실행시 g++ 파일이름 ./a//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
char place[50][50] ={0};
int n = 0;
vector<int> candy;

int maxCandy();
void brute (int x,int y); 
int main (){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> place[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            brute(i,j);
        }
    }
    int maxElementIndex = max_element(candy.begin(),candy.end()) - candy.begin();
    cout <<candy[maxElementIndex];
}

int maxCandy(){
    int temp = 1;
    vector<int> count;

    for(int i = 0; i<n; i++){
        temp = 1;
        for(int j = 0; j<n; j++){
            if(j != 0){
                if(place[i][j-1] == place[i][j]){
                    temp++;
                    if(j == n-1){
                        count.push_back(temp);
                    }
                }else{
                    count.push_back(temp);
                    temp = 1;
                }
            }
        }
    }
    temp = 1;
    for(int i = 0; i<n; i++){
        temp = 1;
        for(int j = 0; j<n; j++){
            if(j != 0){
                if(place[j-1][i] == place[j][i]){
                    temp++;
                    if(j == n-1){
                        count.push_back(temp);
                    }
                }else{
                    count.push_back(temp);
                    temp = 1;
                }
            }
        }
    }
    int maxElementIndex = max_element(count.begin(),count.end()) - count.begin();
    return count[maxElementIndex];
}

void brute (int x,int y) {
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    char temp;

    for(int i=0; i<4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
             if(place[x][y] != place[nx][ny]){
                temp = place[x][y];
                place[x][y] = place[nx][ny];
                place[nx][ny] = temp;
                candy.push_back(maxCandy());
                temp = place[x][y];
                place[x][y] = place[nx][ny];
                place[nx][ny] = temp;
            }
        }
    }
    return;
}