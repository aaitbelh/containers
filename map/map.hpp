#ifndef MAP_HPP
#define MAP_HPP
#include <utility>
#include <memory>

namespace ft
{

    template<class T1,class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair():first(T1()),second(T2()) {}
        pair(const T1& a, const T2& b):first(a),second(b) {}
        template<class U, class V>
        pair(const pair<U,V>& pr):first(pr.first),second(pr.second) {}
        pair& operator=(const pair& pr)
        { first = pr.first; second = pr.second; return *this; }
    };
    template <class Key, class T, class Compare = std::less<Key>,
                       class Allocator = std::allocator<pair<const Key, T> > >
    class map
    {
        public:

    }
};

#endif