#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Test{
    public:
    int x,y;
    Test(int x, int y):x(x),y(y){}
};

float distance(Test t1,  Test t2)
{
    // Calculating distance
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2) * 1.0);
}
bool f(Test t1, Test t2)
{
    
    Test org = Test(1, 1);
    return ( > distance(t1, org));
}
int main()
{
    std::vector<Test> vecOfclassTest;
    vecOfclassTest.emplace_back(Test(1, 2));
    vecOfclassTest.emplace_back(Test(3, 10));
    vecOfclassTest.emplace_back(Test(4, 6));
    sort(vecOfclassTest.begin(), vecOfclassTest.end(), f);
}