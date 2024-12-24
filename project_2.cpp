#include <iostream>
using namespace std;

template <class T, int MAX>
class PriorityQueue_5
{
private:
    T items[MAX];
    int rear;

public:
    PriorityQueue_1()
    {
        rear=-1;
    }

    bool empty()
    {
        if(rear == -1)
        {
            return true;
        }
        return false;
    }

    bool insert(T x)
    {
        if(rear == MAx)
        {
            return false;
        }
        items[++rear]=x;
        return true;
    }

    T maxDelete()
    {
        if(empty())
        {
            cout << "Priority Queue 5 is Empty!" << endl;
            exit(1);
        }
        int imx = 0;
        for(int i=0; i<=rear; i++)
        {
            if(items[i] > items[imx])
                imx=i;
        }
        T mx=items[imx];
        items[imx] = items[rear];
        rear--;
        return mx;
    }
};

int main()
{

}