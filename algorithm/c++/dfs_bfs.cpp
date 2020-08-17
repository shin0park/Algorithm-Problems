#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void dfs(int start, vector<int> graph[], bool visit[]);
void bfs(int start, vector<int> graph[], bool visit[]);

int main (){
	int n, m, start;
	cin >> n >> m >> start;
    //vector<int> *graph = new vector<int>(n+1);
	vector<int> graph[1001];
	bool visit [1001];
	fill(visit, visit+1001, false);
	int u,v;
	for(int i=0; i<m; i++){
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start, graph, visit);
    cout << endl;
    fill(visit, visit+1001, false);
    bfs(start, graph, visit);
	

	return 0;
}

void bfs(int start, vector<int> graph[], bool visit[]){
	queue<int> q;
	q.push(start);
	visit[start] = true;
    int temp = 0;
	
	while(!q.empty()){
		temp = q.front();
		q.pop();
        cout << temp << " ";
		
		for(int i=0; i<graph[temp].size(); i++){
			if(visit[graph[temp][i]] == false){
				q.push(graph[temp][i]);
				visit[graph[temp][i]] = true;
			}
		}
	}
}

/*
void dfs(int y, int x){
	visited[y][x]=1;
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(isRange(ny,nx) && !visited[ny][nx] && map[ny][nx]!=0){
			dfs(ny,nx);
		}
	}
}
*/


void dfs(int start, vector<int> graph[], bool visit[]){

	stack<int> s;
	int current_node, next_node;
	s.push(start);
	visit[start] = true;
    cout << start << " ";
	
	while(!s.empty()){
		current_node = s.top();
		s.pop();
		for(int i=0; i<graph[current_node].size(); i++){
			next_node = graph[current_node][i];
			if(visit[next_node]==false){
                cout << next_node << " ";
				visit[next_node] = true;
				
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}

}