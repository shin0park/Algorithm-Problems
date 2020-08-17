#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visit[50][50];
int cabbage[50][50];
vector<int> group;

void dfs(int m, int n, int startX, int startY, bool visit[50][50]);
int main (){
    int test_num, n, m, k;
    cin >> test_num;
   
    fill(visit[0],visit[0]+2500, false);
    int x, y;
    int group_num;

    for(int i =0; i < test_num; i++){
        cin >> m >> n >> k;
        group_num = 0;
        vector<pair<int,int>> spot;
        fill(cabbage[0],cabbage[0]+2500, 0);
        fill(visit[0],visit[0]+2500, false);

        for(int i=0; i < k; i++){
            cin >> x >> y;
            cabbage[x][y] = true;
            spot.push_back(pair<int,int>(x,y));
	    }

        for(int i = 0; i < k; i++){
            if(visit[spot[i].first][spot[i].second] == false){
                dfs(m, n, spot[i].first, spot[i].second , visit);
                group_num++;
                
            }
        }
        group.push_back(group_num); 
    }
    for(int i=0; i<group.size(); i++){
        cout << group[i] << endl;
    }
}
void dfs(int m, int n, int startX, int startY, bool visit[50][50]){
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
                if(visit[nx][ny] == false && cabbage[nx][ny] == true){
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