#include <iostream>
#include <cstdlib>
using namespace std;

// Algorithm 1: Insert at rear, delete the maximum, shift elements, reduce rear
template <class T, int MAX>
class PriorityQueue_1
{
private:
    T items[MAX];
    int rear;

public:
    PriorityQueue_1() 
    { 
        rear = -1; 
    }

    bool empty() 
    { 
        return rear == -1; 
    }

    bool insert(T x)
    {
        if (rear == MAX - 1) // Check if the queue is full
            return false;
        items[++rear] = x;
        return true;
    }

    T maxDelete()
    {
        if (empty())
        {
            cout << "Priority Queue 1 is Empty!" << endl;
            exit(1);
        }
        int imx = 0;
        for (int i = 1; i <= rear; i++)
        {
            if (items[i] > items[imx]) // Find the index of the max element
                imx = i;
        }
        T mx = items[imx];
        for (int i = imx; i < rear; i++) // Shift elements to fill the gap
        {
            items[i] = items[i + 1];
        }
        rear--;
        return mx;
    }
};

// Algorithm 2: Insert at the first empty slot, delete the maximum with a deletion marker (-1)
template <class T, int MAX>
class PriorityQueue_2
{
private:
    T items[MAX];
    int rear;

public:
    PriorityQueue_2()
    {
        rear = -1;
        for (int i = 0; i < MAX; i++)
            items[i] = -1; // Initialize all slots with a marker
    }

    bool empty()
    {
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] != -1) // Check for non-deleted elements
                return false;
        }
        return true;
    }

    bool insert(T x)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (items[i] == -1) // Find the first available slot
            {
                items[i] = x;
                if (i > rear) // Update rear to track the last position
                    rear = i;
                return true;
            }
        }
        return false; // No available slots
    }

    T maxDelete()
    {
        if (empty())
        {
            cout << "Priority Queue 2 is Empty!" << endl;
            exit(1);
        }
        int imx = -1;
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] != -1)
            {
                if (imx == -1 || items[i] > items[imx])
                {
                    imx = i;
                }
            }
        }
        T mx = items[imx];
        items[imx] = -1; // Mark as deleted
        return mx;
    }
};

// Algorithm 3: Insert at rear, delete the maximum with a deletion marker (-1), compress when rear == MAX - 1
template <class T, int MAX>
class PriorityQueue_3
{
private:
    T items[MAX];
    int rear;

    void compress()
    {
        int j = 0;
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] != -1) // Skip deleted elements
                items[j++] = items[i];
        }
        rear = j - 1; // Update rear after compression
    }

public:
    PriorityQueue_3()
    {
        rear = -1;
        for (int i = 0; i < MAX; i++)
            items[i] = -1; // Initialize all slots with a marker
    }

    bool empty()
    {
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] != -1)
                return false;
        }
        return true;
    }

    bool insert(T x)
    {
        if (rear == MAX - 1)
        {
            compress();          // Reorganize to free space
            if (rear == MAX - 1) // Check if still full
                return false;
        }
        items[++rear] = x;
        return true;
    }

    T maxDelete()
    {
        if (empty())
        {
            cout << "Priority Queue 3 is Empty!" << endl;
            exit(1);
        }
        int imx = -1;
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] != -1)
            {
                if (imx == -1 || items[i] > items[imx])
                {
                    imx = i;
                }
            }
        }
        T mx = items[imx];
        items[imx] = -1;
        return mx;
    }
};

// Algorithm 4: Insert in sorted order, delete from rear(increasing sort)
template <class T, int MAX>
class PriorityQueue_4
{
private:
    T items[MAX];
    int rear;

public:
    PriorityQueue_4() 
    { 
        rear = -1; 
    }

    bool empty() 
    { 
        return rear == -1; 
    }

    bool insert(T x)
    {
        if (rear == MAX - 1) // Check if the queue is full
            return false;

        int i;
        for (i = rear; i >= 0 && items[i] > x; i--)
        {
            items[i + 1] = items[i]; // Shift elements to maintain order
        }
        items[i + 1] = x;
        rear++;
        return true;
    }

    T maxDelete()
    {
        if (empty())
        {
            cout << "Priority Queue 4 is Empty!" << endl;
            exit(1);
        }
        return items[rear--]; // Remove the last (largest) element
    }
};

// Algorithm 5: Insert at rear, delete the maximum by replacing it with the rear element
template <class T, int MAX>
class PriorityQueue_5
{
private:
    T items[MAX];
    int rear;

public:
    PriorityQueue_5() 
    { 
        rear = -1;
    }

    bool empty() 
    { 
        return rear == -1; 
    }

    bool insert(T x)
    {
        if (rear == MAX - 1) // Check for overflow
            return false;
        items[++rear] = x;
        return true;
    }

    T maxDelete()
    {
        if (empty())
        {
            cout << "Priority Queue 5 is Empty!" << endl;
            exit(1);
        }
        int imx = 0;
        for (int i = 0; i <= rear; i++)
        {
            if (items[i] > items[imx]) // Find the index of the max element
                imx = i;
        }
        T mx = items[imx];
        items[imx] = items[rear--]; // Replace max with the last element
        return mx;
    }
};

int main()
{
    
}
