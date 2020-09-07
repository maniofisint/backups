#include <iostream>

using namespace std;

//template <typename T1, typename T2>
//T1 myGreater(T1 v1, T2 v2);

template <typename T, int N = 0>
class MyPair
{
//private:
    T v[2];
public:
    MyPair(T first = N, T second = N)
    {
        setFirst(first);
        setSecond(second);
        //cout << "MyPair constructed, N = " << N << endl;
    }
    T getFirst()
    { return v[0]; }
    T getSecond()
    { return v[1]; }
    T getMax();
    //{ return v[0] > v[1] ? v[0] : v[1]; }
    void setFirst(T n)
    { v[0] = n; }
    void setSecond(T n)
    { v[1] = n; }
};

int main()
{
/*    //To remember:
    cout << myGreater(7, 3) << endl;
    cout << myGreater(7.2, 9.3) << endl;
    cout << myGreater('Q', 'D') << endl;
    cout << myGreater(7.2, 9) << endl;
    cout << myGreater(5, 8.5) << endl;*/

    MyPair<int> p1;
    cout << "My pair is (" << p1.getFirst() << ", " << p1.getSecond() << ")\n";
    cout << "Max of pair is " << p1.getMax() << endl;
    p1.setFirst(15);
    cout << "My pair is (" << p1.getFirst() << ", " << p1.getSecond() << ")\n";
    cout << "Max of pair is " << p1.getMax() << endl;
    return 0;
}

template <typename T, int N>
T MyPair<T, N>::getMax()
{
    return v[0] > v[1] ? v[0] : v[1];
}

//To remember:
template <typename T1, typename T2>
T1 myGreater(T1 v1, T2 v2)
{
    return v1 > v2 ? v1 : v2;
}

