#include <stdio.h>

int binary_search(int *array, int low, int high, int key);

int main()
{
    int array[12] = {4, 5, 12, 24, 56, 78, 90, 91, 92, 93, 94, 99};
    int index = binary_search(array, 0, 11, 24);
    printf("%d", index);
    return 0;
}

int binary_search(int *a, int low, int high, int key)
{
    /*
    // binary search - iterative solution
    int pos = -1;
    int found = 0;
    // if found variable is not created, what is the problem. Think about it?
    while (low <= high && found == 0)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            pos = mid;
            found = 1;
        }
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return pos;
    */
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return binary_search(a, low, mid - 1, key);
        }
        else
        {
            return binary_search(a, mid + 1, high, key);
        }
    }
}