/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:04:07 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/01 19:56:58 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef stack_HPP
#define stack_HPP
#include "../vector/vector.hpp"


namespace ft
{
    template<class T, class Container>
    class stack;
    
    template <class T, class Container>
    bool operator==(const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
        return x.c == y.c;
    }
    template <class T, class Container>
    bool operator< (const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
        return x.c < y.c;
    }
  template <class T, class Container>
    bool operator!=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
                    {
                        return x.c != y.c;
                    }
  template <class T, class Container>
    bool operator> (const stack<T, Container>& x,
                    const stack<T, Container>& y)
                    {
                        return x.c > y.c;
                    }
  template <class T, class Container>
    bool operator>=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
                    {
                        return x.c >= y.c;
                    }
  template <class T, class Container>
    bool operator<=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
                    {
                        return x.c <= y.c;
                    }

    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container                                container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;
        protected:
            container_type c;
        public:
            explicit stack (const container_type& ctnr = container_type()): c(ctnr)
            {}
            stack& operator=( const stack& other )
            { c = other.c; return *this; }
            stack( const stack& other )
            { c = other.c; }
            bool empty() const
                { return c.empty(); }
            size_type size() const
                { return c.size(); }
            void push (const value_type& val)
                { c.push_back(val); }
            void pop()
                { c.pop_back(); }
            value_type& top()
                { return c.back(); }
            const value_type& top() const
                { return c.back(); }
            friend bool operator==<T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            friend bool operator< <T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            friend bool operator!=<T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            friend bool operator><T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            friend bool operator>=<T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            friend bool operator<=<T, Container>(const stack<T, Container>& x,
                    const stack<T, Container>& y);
            ~stack()
            { }
    };
//     template <class T, class Container>
//     bool operator< (const stack<T, Container>& x,
//                     const stack<T, Container>& y)
//                     { return x.c < y.c; }
//   template <class T, class Container>
//     bool operator!=(const stack<T, Container>& x,
//                     const stack<T, Container>& y)
//                     { return x.c != y.c; }
//   template <class T, class Container>
//     bool operator> (const stack<T, Container>& x,
//                     const stack<T, Container>& y)
//                     { return x.c > y.c; }
//   template <class T, class Container>
//     bool operator>=(const stack<T, Container>& x,
//                     const stack<T, Container>& y)
//                     { return x.c >= y.c; }
//   template <class T, class Container>
//     bool operator<=(const stack<T, Container>& x,
//                     const stack<T, Container>& y)
//                     { return x.c <= y.c; }
};

#endif