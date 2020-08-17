/*#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int collective (int index, int* arr[], int s[], int k);
int main()
{
    int k = 0;
    int s[49] ={0};
    int arr[2][1] ={0};
    while(1){
        cin >> k;
        if(k==0){
            break;
        }
        for(int i=0; i<k; i++){
            cin >> s[i];
        }
        arr[0][0] = {s[0]};
        arr[1][0] = {0};
        collective(0,arr,s,k);
        

    }

    return 0;
}
int collective (int n, int* arr[], int s[],int k){
    int len = sizeof(arr)/sizeof(arr[0]);
    int temp[len*2][49] ={0};
    for(int i = 0; i <sizeof(arr)/sizeof(arr[0]); i++){
        for(int j=0; j<sizeof(arr[i])/sizeof(int); j++){
            temp[i][j] = arr[i][j];
        }
    }
    //int len = sizeof(temp)/sizeof(temp[0]);
    for(int i = 0; i <sizeof(arr)/sizeof(arr[0]); i++){
        for(int j=0; j<sizeof(arr[i])/sizeof(int); j++){
            if(arr[i][j] == 0){
                temp[i+len][j] = s[n];
            }else{
                temp[i+len][j] = arr[i][j];
            }
        }
    }
    if(n == k-1){
        return 1;
    }
    collective (n+1, temp, s);

}*/