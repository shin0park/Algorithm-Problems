#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

void dfs(int i, int j, vector<int> farm[], vector<bool> check[]) 
{
   check[i][j] = true; // 처음 시작 노드의 check를 true로 변경

   if (farm[i - 1][j] == 1 && check[i - 1][j] == false && i != 0)
   {
      dfs(i - 1, j, farm, check);
   } // 기준노드의 상 노드 체크
   if (farm[i + 1][j] == 1 && check[i + 1][j] == false && i != 49)
   {
      dfs(i + 1, j, farm, check);
   } // 기준노드의 하 노드 체크
   if (farm[i][j-1] == 1 && check[i][j-1] == false && j != 0)
   {
      dfs(i, j-1, farm, check);
   } // 기준노드의 좌 노드 체크
   if (farm[i][j+1] == 1 && check[i][j+1] == false && j != 49)
   {
      dfs(i, j+1, farm, check);
   } // 기준노드의 우 노드 체크


   /*for (int i = 0; i < graph[start].size(); i++) {
      int next = graph[start][i];
      // 방문하지 않았다면
      if (check[next] == false) {
         // 재귀함수를 호출한다.
         dfs(next, graph, check);
      }
   }*/
}

int main()
{
   int k, row, col, cab;
   int count;
   cin >> k >> row >> col >> cab;

   vector<int> farm[50];
   vector<bool> check[50];
   fill(farm, farm + 51, 0);
   fill(check, check + 51, false);
   for (int i = 0; i < k; i++)
   {
      count = 0;
      for (int i = 0; i < cab; i++)
      {
         int r, c;
         cin >> r >> c;

         farm[r][c] = 1;
      }

      for (int i = 0; i < 50; i++)
      {
         for (int j = 0; j < 50; j++)
         {
            if (farm[i][j] == 1 && check[i][j] == 0)
            {
               dfs(i, j, farm, check);
               count++;
            }
         }
      }

      cout << count;
   }

   return 0;
}