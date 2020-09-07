#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>
int main()
{
    std::vector<int> v = { 1 , 2 , 3, 4, 5};

    for ( int i = 0 ; i < v.size() ; i++)
        std::cout << v[i] << std::endl;

    for ( int i : v )
        std::cout << i << std::endl;

    for(std::vector<int>::iterator it = v.begin();
        it != v.end() ; ++it)
        std::cout << *it << std::endl;

    std::unordered_map< std::string , int > map;
    map["a"] = 12;
    map["b"] = 234;
    map["c"] = 1;

    for ( std::unordered_map<std::string , int > :: const_iterator it = map.begin() ; it != map.end() ; it++)
    {
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << std::endl;

    }

    using shorter = std::unordered_map< std::string , int >;
    shorter secondMap;
    secondMap["a"] = 1552;
    secondMap["b"] = 2534;
    secondMap["c"] = 1555;
    for ( shorter::const_iterator it = secondMap.begin() ; it != secondMap.end(); it++)
        std::cout << it->first << " = " << it->second << std::endl;


    for ( auto it : secondMap )
        std::cout << it.first << " = " << it.second << std::endl;

    //next one is only supported by c++17
    //for ( auto [ key , value ] : secondMap)
    //    std::cout << key << " = " << value << std::endl;

    std::cin.get();
}