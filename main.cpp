#include <iostream>
#include <set>
#include "set/set.hpp"
#include "map/map.hpp"
#include <map>
#include <ctime>
#define NAMESPACE ft
int main()
{
        std::set<std::string> s;
        ft::set<int> mys;
        mys.insert(1);
        std::cout << *mys.rbegin() << std::endl;
}