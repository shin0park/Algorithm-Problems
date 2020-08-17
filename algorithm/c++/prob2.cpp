#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int n = 0;
int group_id = 0;
int group_id_rg = 0;

char **draw = NULL;
bool **visit = NULL;
bool **visitrg = NULL;

void bfs (int startX, int startY);
void bfsrg (int startX, int startY);
int main()
{
	cin >> n;

    draw = (char **) malloc( sizeof(char*)*n );
    visit = (bool **) malloc( sizeof(bool*)*n );
    visitrg = (bool **) malloc( sizeof(bool*)*n );

    for( int i=0; i<n; i++) {
        draw[i] = (char *) malloc( sizeof(char)*n );
        visit[i] = (bool *) malloc( sizeof(bool)*n );
        visitrg[i] = (bool *) malloc( sizeof(bool)*n );
    }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1s", &draw[i][j]);
            visit[i][j] = false;
            visitrg[i][j] = false;
		}
	}
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == false){
                bfs(i,j);
                group_id++;
            }
        }
    } 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visitrg[i][j] == false){
                bfsrg(i,j);
                group_id_rg++;
            }
        }
    } 

    cout << group_id << " " << group_id_rg <<endl;

    free(draw);
    free(visit);
    free(visitrg);
	return 0;
}
void bfsrg (int startX, int startY){
    int x, y = 0;
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    queue<pair<int,int>> q;    
    q.push(pair<int,int>(startX,startY));  
    
    visitrg[startX][startY] = true;
  
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if((draw[nx][ny] == draw[x][y] || ((draw[nx][ny] != 'B') & (draw[x][y] != 'B'))) & visitrg[nx][ny] == false){
                    visitrg[nx][ny] = true;
                    q.push(pair<int,int>(nx,ny));
                }
            }
        }
    }
    return;
}
void bfs (int startX, int startY){
    int x, y = 0;
    int nx,ny = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    queue<pair<int,int>> q;    
    q.push(pair<int,int>(startX,startY));  
    
    visit[startX][startY] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(draw[nx][ny] == draw[x][y] & visit[nx][ny] == false){
                    visit[nx][ny] = true;
                    q.push(pair<int,int>(nx,ny));
                }
            }
        }
    }
    return;
}

