#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
    int i, j;
    const int k = 65534;
    const int s = 32768;
    int *arr = new int[s];
    srand(time(0)+100);
    for(i = 0; i < s; i++)
        arr[i] = rand() % s;


    bool isFound = false;

    for(i = 0; i < s; i++)
    {
        for(j = 0; j < s; j++)
            if(arr[i] + arr[j] == k)
            {
                isFound = true;
                break;
            }
        if(isFound)
            break;
    }
	if(isFound)
        cout << arr[i] << " + " << k - arr[i] << " = " << k << "i:" << i<<endl;
    else
        cout << "There is no pair of input with sum " << k<< endl;

    return 0;

    sort(arr, arr + s);
    for(i = 0; i < s; i++)
        if(binary_search(arr, arr + s, k - arr[i]))
        {
            isFound = true;
            break;
        }
    if(isFound)
        cout << arr[i] << " + " << k - arr[i] << " = " << k;
    else
        cout << "There is no pair of input with sum " << k;

    return 0;
}
