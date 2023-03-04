#include <iostream>
#include <vector>
#include "vector/vector.hpp"
#include "map/map.hpp"
#include <map>
int main()
{
    std::map<int, int>m;
    ft::map<int, int>m2;
    m.insert(std::pair<int, int>(1, 1));
    m2.insert(ft::pair<int, int>(1, 1));
	std::cout << m.lower_bound(1)->first << std::endl;;
	std::cout << m2.lower_bound(1)->first << std::endl;;

}