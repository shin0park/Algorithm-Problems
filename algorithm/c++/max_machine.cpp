//최대값 기계
//캡슐화란? 기존에 없는 새로운 자료구조를 정의 하고자 할때 사용되며 자료구조를 사용하는 사람은 자료구조가 어떤 구조로 이루어져 있는지 알 필요가 없다.
//캡슐화의 예시로 구조체가 있다.
//구조체는 캡슐화를 구현하기 위한 자료구조
//구조체는 타입을 정의하는 것이다.
//struct를 이용하여 maxmachine 이라는 자료구조를 "정의"한 것.
//maxmachine이라는 자료구조 M을 "선언"
//M <- 변수, 인스턴스(instance) 개체. 실체가 있는 뭔가.
//maxmachine이라는 struct의 인스턴스 M.
#include <stdio.h>
#include <iostream>
const int MAX = 50;
using namespace std;
struct maxMachine
{
    int machine[MAX] = {
        0,
    };
    int len = 0;

    void insertNumber(int x)
    {
        machine[len++] = x;
    }
    void removeNumber(int x)
    {
        for (int i = 0; i < len; i++)
        {
            if (machine[i] == x)
            {
                for (int j = i; j < len; j++)
                {
                    machine[i] = machine[i + 1];
                }
                len--;
            }
        }
    }
    int getMax()
    {
        int max = machine[0];
        for (int i = 0; i < len; i++)
        {
            if (max < machine[i])
            {
                max = machine[i];
            }
        }
        return max;
    }
};

int main()
{
    maxMachine M;
    M.insertNumber(1);
    M.insertNumber(3);
    M.insertNumber(2);

    cout << M.getMax() << endl;
    M.removeNumber(3);
    cout << M.getMax() << endl;
}