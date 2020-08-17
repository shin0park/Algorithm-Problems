//원형 큐 구현.
#include <stdio.h>
#include <iostream>

using namespace std;
const int MAX = 100;
struct Queue
{
    int data[MAX];
    int front, rear;
    int capacity;
    int numElement;
    void create(int y)
    {
        capacity = y;
        front = 0;
        rear = 0;
        numElement = 0;
    }
    void push(int y)
    {
        if (numElement >= capacity)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {

            data[rear] = y;
            rear = (rear + 1) % MAX;
            numElement++;
        }
    }
    void pop()
    {
        if (numElement <= 0)
        {
            cout << "Queue underflow" << endl;
        }
        else
        {
            data[front] = 0;
            front = (front + 1) % MAX;

            numElement--;
        }
    }
    int front()
    {
        //반환할 것이 없다면 -1 반환
        if (numElement <= 0)
        {
            return -1;
        }
        else
        {
            return data[front];
        }
    }
    int size()
    {
        return numElement;
    }
};
int main()
{

    return 0;
}