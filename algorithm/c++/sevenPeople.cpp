#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main (){
    int height[9] ={0};
    vector<pair<int,int>> exPeople;
    int sum=0;
    int fsum = 0;
    bool flag = false;

    for(int i=0; i<9; i++){   
        cin >> height[i];
        sum += height[i];
    }
    fsum = sum;
    sort(height, height + 9);

    for(int i=0; i<9; i++){
        if(flag == true){
            flag = false;
            break;
        }
        sum -= height[i];

        for(int j=0; j<9; j++){
            if(j != i){
                sum -= height[j];
                if(sum == 100){
                    exPeople.push_back(pair<int,int>(i,j));
                    flag = true;
                    break;
                }
                sum += height[j];
            }
        }
        sum = fsum;
    }

    for(int i=0; i<9; i++){
        if(i == exPeople[0].first || i == exPeople[0].second){
            continue;
        }
        cout << height[i]<<endl;
    }

}
