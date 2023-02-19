#include <iostream>
#include <vector>
#include <map>
#include <string>
int main()
{
    std::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(3, "A"));
    m.insert(std::pair<int, std::string>(1, "B"));
    m.insert(std::pair<int, std::string>(2, "C"));
    std::map<int, std::string>::iterator  it = m.begin();
    std::cout << m.size() << std::endl;
    for(; it != m.end(); ++it)
        std::cout << it->second << std::endl;
}