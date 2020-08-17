//queue 구현
//queue 구현의 문제점 있음.
// 공간을 적극적으로 활용하는 구현이 아니다.
//이를 해결하기 위해 원형 큐를 사용해야한다.
#include <stdio.h>
#include <iostream>

using namespace std;
struct Queue
{
    //data 01234567
    //data 0004567
    //        f  r
    int data[100];
    int front, rear;
    int capacity;

    void create(int y)
    {
        capacity = y;
        front = 0;
        rear = 0;
    }
    void push(int y)
    {
        if (rear - front >= capacity)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            data[rear++] = y;
        }
    }
    void pop()
    {
        if (rear - front <= 0)
        {
            cout << "Queue underflow" << endl;
        }
        else
        {
            data[front++] = 0;
        }
    }
    int front()
    {
        //반환할 것이 없다면 -1 반환
        if (rear - front <= 0)
        {
            return -1;
        }
        else
        {
            return data[front];
        }
    }
    int size(){
        return (rear-front);
    }
}; 
int main()
{

    return 0;
}