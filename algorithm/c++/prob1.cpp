#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int sizeX, sizeY=0;
int group[10] = {0,0,0,0,0,0,0,0,0,0};
int sheep[10] = {0,0,0,0,0,0,0,0,0,0};
int wolf[10] = {0,0,0,0,0,0,0,0,0,0};
int total_sheep = 0;
int total_wolf = 0;
int group_id = 0;

char **yard = new char*[sizeY];
bool **visit = new bool*[sizeY];  
int type = 0;

int bfs (int cx, int cy);
int main()
{

    cin >> sizeX >> sizeY;

    for(int i = 0; i < sizeY; ++i) { 
        yard[i] = new char[sizeX]; 
        visit[i] = new bool[sizeX]; 
        memset(yard[i], 0, sizeof(char)*sizeX);
        memset(visit[i], false, sizeof(bool)*sizeX);
    }

    for(int i=0; i<sizeX; i++){
        for(int j=0; j<sizeY; j++){
            scanf("%1s", &yard[i][j]);
           
        }
    }
  
    for(int i=0; i<sizeX; i++){
        for(int j=0; j<sizeY; j++){
            if(visit[i][j] == false){
                type = bfs(i,j);
                if(type == 3){
                    group_id++;
                }   
            }
            // cout << type << "\n";
        }
    } 

    for(int i=0; i<group_id; i++){
        if(wolf[i] >= sheep[i]){
            total_wolf += wolf[i];
        }else{
            total_sheep += sheep[i];
        }
    }
 
    
    for(int i = 0; i < sizeY; ++i) { 
        delete [] yard[i]; 
    } delete [] yard;
    for(int i = 0; i < sizeY; ++i) { 
        delete [] visit[i]; 
    } delete [] visit;

    for(int i=0; i<group_id; i++){
        cout << wolf[i]<<" "<< sheep[i]<< "\n";
    }
    cout << total_sheep <<" "<< total_wolf;
    return 0;
}

int bfs (int cx, int cy){
    int x,y=0;
    int nx,ny = 0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    queue<pair<int,int>> q;    
    q.push(pair<int,int>(cx,cy));  
    
    visit[cx][cy] = true;

    if(yard[cx][cy] == '#'){
        return 2;
    }else{
        //group[group_id]++;
       
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(yard[x][y] == 'v'){
                wolf[group_id]++;
            }else if(yard[x][y] == 'o'){
                sheep[group_id]++;
            }

            for(int i=0; i<4; i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(0 < nx && nx < sizeX && 0 <= ny && ny < sizeY){
                        if(yard[ny][ny] != '#'&& visit[nx][ny] == false){
                            visit[nx][ny] = true;
                            //group[group_id]++;
                            q.push(pair<int,int>(nx,ny));
                    }
                }
            }


        }
        return 3;
    }
 
}
