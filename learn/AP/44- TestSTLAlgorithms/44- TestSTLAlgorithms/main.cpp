#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int *, int);
//int binarySearch(int *a, int beg, int end, key);
int main()
{
    int arr[] = {5, 1, 0, 9, 7, 3, 4, 6, 8, 2};

    printArray(arr, sizeof(arr) / sizeof(int));

    sort(arr, arr + sizeof(arr) / sizeof(int));

    cout << binary_search(arr, arr + sizeof(arr) / sizeof(int), 112) << endl;

    printArray(arr, sizeof(arr) / sizeof(int));

    return 0;
}

//DRY

void printArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;
}
