#include <iostream>
#include <vector>
int main()
{
    std::vector<int> myvector = {1, 2, 3, 4};
    std::vector<int>::iterator it = myvector.begin();
    while (it != myvector.end()) {
        int x = *it;
        std::cout << x << std::endl;
        ++it;
    }

    // this will not work
    it--;
    std::cout << *it << std::endl;
}
