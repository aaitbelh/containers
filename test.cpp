#include <iostream>
#include <vector>
int main()
{
    std::vector<int> myVector = {1, 2, 3, 4};
    std::vector<int>::iterator it = myVector.begin();
    while (it != myVector.end()) {
        int x = *it;
        std::cout << x << std::endl;
        ++it;
    }

    // this will not work
    it--;
    std::cout << *it << std::endl;
}
