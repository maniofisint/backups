#include <iostream>
#include <map>
using namespace std;

/*
template <typename T1, typename T2>
class MyPair
{
public:
    MyPair(T1 f, T2 s)
    : first(f), second(s){ }
    T1  first;
    T2  second;
};*/

template <typename T1, typename T2>
void printMap(map<T1, T2> m);

int main()
{
    /*
    pair<int, int> intPair(3, 7);
    cout << intPair.first << endl;
    cout << intPair.second << endl;*/
  //map<KeyType, ValueType>;
    map<char, int> asciiMap;

    asciiMap.insert(pair<char, int>('A', 65));
    asciiMap.insert(pair<char, int>('B', 66));
    asciiMap.insert(pair<char, int>('b', 98));
    asciiMap.insert(pair<char, int>('c', 99));
    asciiMap.insert(pair<char, int>('d', 100));
    asciiMap.insert(pair<char, int>('C', 67));
    asciiMap.insert(pair<char, int>('D', 68));
    asciiMap.insert(pair<char, int>('a', 97));

    //cout << asciiMap['E'] << endl;
    //cout << asciiMap.at('E') << endl;
    asciiMap['E'] = 69;
    char ch = 'E';
    if(asciiMap.find(ch) != asciiMap.end())
        cout << "Ascii Code of " << ch << " is " << asciiMap[ch] << endl;
    else
        cout << "There is no record for key: " << ch << endl;

    printMap(asciiMap);

    return 0;
}

template <typename T1, typename T2>
void printMap(map<T1, T2> m)
{
    for(auto it = m.begin(); it != m.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}
