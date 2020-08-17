#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n,m;
char place[9][9];
vector<pair<int,int>> emptyPlace;
int safeNum = 0;
int maxSafeNum = 0;
vector<int> zero;

void combinationSTL(vector<int> set, int n, int r);
void replace(vector<int> zero);
void dfs(int m, int n, int startX, int startY, bool visit[9][9], char temp[9][9]);
void viruss();

int main (){
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> place[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(place[i][j] == '0'){
                emptyPlace.push_back(pair<int,int>(i,j));
            }
        }
    }
    vector<int> index;
    combinationSTL(index, emptyPlace.size(), 3);
    cout << maxSafeNum;
    return 0;
}

void combinationSTL(vector<int> set, int n, int r) {
	for (int j = 0; j < n - r; ++j)
		set.push_back(0);
	for (int j = 0; j < r; ++j)
		set.push_back(1);
	do {
		for (int j = 0; j < n; ++j){
            if (set[j]){
                zero.push_back(j);
            } 
        }
        replace(zero);
        zero.clear();
	} while (next_permutation(set.begin(), set.end()));
    return;
}
void replace(vector<int> zero ){
    int x[3],y[3];
    for(int i = 0; i<3;i++){
        x[i]= emptyPlace[zero[i]].first;
        y[i]= emptyPlace[zero[i]].second;
        place[x[i]][y[i]] = '1';
    }
    viruss();
    for(int i = 0; i<3;i++){
        x[i]= emptyPlace[zero[i]].first;
        y[i]= emptyPlace[zero[i]].second;
        place[x[i]][y[i]] = '0';
    }
}
void dfs(int m, int n, int startX, int startY, bool visit[9][9], char temp[9][9]){
    int x, y = 0;
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    stack<pair<int,int>> s;    
    s.push(pair<int,int>(startX,startY));  
    
    visit[startX][startY] = true;

    while(!s.empty()){
        x = s.top().first;
        y = s.top().second;
        s.pop();

        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0 <= nx && nx < m && 0 <= ny && ny < n){
                if(visit[nx][ny] == false && temp[nx][ny] == '0'){
                    visit[nx][ny] = true;
                     s.push(pair<int,int>(x,y));
                     s.push(pair<int,int>(nx,ny));
                     temp[nx][ny] = '2';
                     break;
                }
            }
        }
    }
    
    return;
}
void viruss(){
    char temp[9][9];
    bool visit[9][9];
    fill(visit[0],visit[0]+81, false);
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            temp[i][j] = place[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(temp[i][j] =='2'){
                dfs(n, m, i, j , visit, temp);
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(temp[i][j] =='0'){
                safeNum++;
            }
        }
    }
    if(maxSafeNum < safeNum){
        maxSafeNum = safeNum;
    }
    safeNum=0;
}