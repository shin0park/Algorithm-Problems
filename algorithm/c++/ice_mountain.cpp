#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[300][300];
int sea[300][300];
int temp[300][300];
int groupNum = 0;
int iceNum =0,countYear =0;

void year(int n , int m, vector<pair<int,int>> map);
void dfs(int n, int m, int startX, int startY, bool visit[300][300]);

int main(){
    int n,m;
    fill(visit[0],visit[0]+90000, false);
    cin >> n >> m;
    vector<pair<int,int>> ice;

    for(int i = 0; i<n; i++){
        for(int j = 0; j <m; j++){
            cin >> sea[i][j];
            if(sea[i][j] != 0){
                ice.push_back(pair<int,int>(i,j));
                iceNum++;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j <m; j++){
            temp[i][j] = sea[i][j];
        }
    }
   
    while(1){
        year(n,m,ice);
        for(int i = 0; i<n; i++){
            for(int j = 0; j <m; j++){
                sea[i][j] = temp[i][j];
            }
        }
        countYear++;
        
        for(int i = 0; i < iceNum; i++){
            if(visit[ice[i].first][ice[i].second] == false && sea[ice[i].first][ice[i].second] != 0){
                dfs(n, m, ice[i].first, ice[i].second , visit);
                groupNum++;              
            }
        }
        if(groupNum == 0){
            cout << 0;
            break;
        }
        if(groupNum > 1){
            cout << countYear;
            break;
        }
        groupNum = 0;
        fill(visit[0],visit[0]+90000, false);
    }
    return 0;
}
void year(int n , int m, vector<pair<int,int>> ice){
    int x, y = 0;
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    for(int i = 0; i < iceNum; i++){
        x = ice[i].first;
        y = ice[i].second;
        if(sea[x][y] <= 0){
            sea[x][y] = 0;
            continue;
        }
        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(sea[nx][ny] == 0){
                    if(temp[x][y] > 0){
                        temp[x][y]--;
                    }
                }

            }
        }
    }
}
void dfs(int n, int m, int startX, int startY, bool visit[300][300]){
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
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(visit[nx][ny] == false && sea[nx][ny] != 0){
                    visit[nx][ny] = true;
                    s.push(pair<int,int>(x,y));
                    s.push(pair<int,int>(nx,ny));
                    break;
                }
            }
        }
    }
    
    return;
}