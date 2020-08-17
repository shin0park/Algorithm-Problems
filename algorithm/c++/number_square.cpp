#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
char square[52][52];
int result = 1;

void brute (int x,int y); 
int main (){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> square[i][j];
        }
    }

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m-1; j++){
            brute(i,j);
        }
    }
    cout << result;
}

void brute (int x, int y){
    int nx,ny = 0;
    int plus = 0;
    if( n-x-1 < m-y-1){
        plus = n-x-1;
    }else{
        plus = m-y-1;
    }
    for(int i=1; i <= plus; i++){
        nx = x + i;
        ny = y + i;
        if(square[x][y] == square[nx][y] &&
             square[nx][y] == square[x][ny] &&
              square[x][ny] == square[nx][ny] &&
              square[x][y] == square[nx][ny]){
            if(result < ((i+1)*(i+1))){
                result = (i+1)*(i+1);
            }
        }
    }
    return;
}