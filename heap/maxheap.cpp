#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            int left = 2 * index;
            int right = 2 * index + 1;

            if (arr[parent] < val)
            {
                swap(arr[parent], val);
            }
            else
                return;
        }
    }

    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
        }
        // delete root node
        // replace first with last
        arr[1] = arr[size];
        size--;    // dec the arr size
        int i = 1; // parent

        while (i < size)
        {

            int left = 2 * i;      // left child
            int right = 2 * i + 1; // right child

            if (left < size && arr[left] > arr[i])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            if (right < size && arr[right] > arr[i])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                return;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    // 
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    return 0;
}

// time complexity = O(logn)
