#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {5, 1, 0, 9, 7, 3, 4, 6, 8, 2};
    vector<int> intVec;

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        intVec.push_back(arr[i]);
        cout << "Push #" << i + 1 << ": "
             << "Cap = " << intVec.capacity()
             << ", Size = " << intVec.size()  << endl;
    }


    for(vector<int>::iterator it = intVec.begin(); it != intVec.end(); ++it)
        cout << *it << ", ";
    cout << endl;

    sort(intVec.begin(), intVec.end());

    for(auto it = intVec.begin(); it != intVec.end(); ++it)
        cout << *it << ", ";
    cout << endl;

    for(auto it = intVec.rbegin(); it != intVec.rend(); ++it)
        cout << *it << ", ";
    cout << endl;

    return 0;
}
