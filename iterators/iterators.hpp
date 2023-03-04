/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:27:39 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/03 17:41:55 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#include <cstddef>
#include "../map/redblack_tree.hpp"
namespace ft
{

template <class T>
struct is_integral
{
    const static bool value = false;
};
template <>
struct is_integral<bool>
{
    const static bool value = true;
};
template <>
struct is_integral<char>
{
    const static bool value = true;
};
template <>
struct is_integral<signed char>
{
    const static bool value = true;
};
template <>
struct is_integral<unsigned char>
{
    const static bool value = true;
};
template <>
struct is_integral<wchar_t>
{
    const static bool value = true;
};
template <>
struct is_integral<char16_t>
{
    const static bool value = true;
};
template <>
struct is_integral<char32_t>
{
    const static bool value = true;
};
template <>
struct is_integral<short int>
{
    const static bool value = true;
};

template <>
struct is_integral<int>
{
    const static bool value = true;
};
template <>
struct is_integral<long int>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned short int>
{
    const static bool value = true;
};
template <>
struct is_integral<unsigned int>
{
    const static bool value = true;
};
template <>
struct is_integral<unsigned long int>
{
    const static bool value = true;
};

template<class T>
struct is_integral<const T>
{
    static const bool value = is_integral<T>::value;
};
template<class T>
struct is_integral<volatile T>
{
    static const bool value = is_integral<T>::value;
};
template<class T>
struct is_integral<const volatile T>
{
    static const bool value = is_integral<T>::value;
};




template<class Inputiterator>
Inputiterator operator+(const size_t n, Inputiterator &obj) {
    return obj + n;
}
template <class T, class U>
struct is_same
{
    const static bool value = false;
};
template <class T>
struct is_same<T, T>{
    const static bool value = true;
};
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };


template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template< class T >
struct iterator_traits<const T*>
{
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};
    //---------------------------------------iterator-----
    template <class _TYPE>
    class iterator
    {
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference         reference;
			pointer																	it_ptr;
            iterator operator++(int){ iterator tmp(*this); this->it_ptr++; return (tmp); }
            iterator& operator++() { this->it_ptr++; return (*this); }
            iterator operator--(int){ iterator tmp(*this); this->it_ptr--; return (tmp); }
            iterator& operator--() { this->it_ptr--; return (*this); }
            iterator& operator+=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            iterator& operator-=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            iterator(){}
            iterator(const pointer &obj)
            {
                this->it_ptr = obj;
            }
			template<class P>
            iterator(const iterator<P> &obj)
            {
                *this = obj;
            }
            template<class P>
			iterator& operator=(const iterator<P> &obj)
			{
				if(this->it_ptr != obj.it_ptr)
					this->it_ptr = obj.it_ptr;
				return *this;
			}
            reference operator[](std::ptrdiff_t index)const
            {
                return (this->it_ptr[index]);
            }
            pointer operator->()const
            {
                return (this->it_ptr);
            }
            reference operator*()
            {
                return *it_ptr;
            }
            iterator operator+(long n)const 
            {
                iterator tmp = *this;
                tmp.it_ptr += n;
                return tmp;
            }
            iterator operator-(long n)const
            {
                iterator tmp = *this;
                tmp.it_ptr -= n;
                return tmp;
            }
            difference_type operator-(const iterator &obj)const
            {
                return (this->it_ptr - obj.it_ptr);
            }
            template<class P>
            bool operator==(const iterator<P>& obj)const { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator!=(const iterator<P>& obj)const { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator>(const iterator<P> &obj)const{ return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator<(const iterator<P>& obj)const{ return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator>=(const iterator<P>& obj)const { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator<=(const iterator<P>& obj)const { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }
    };
    //----------------------------map_iterators
    template <class _TYPE>
    class map_iterator
    {
        public:
            typedef _TYPE	                                                       iterator_type;
            typedef std::bidirectional_iterator_tag                                iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference         reference;
            typedef Node<value_type>* NodePtr;
            NodePtr root;
            NodePtr it_ptr;
            NodePtr NIL;
        public:
            map_iterator() { }
            template <class T>
            map_iterator(const map_iterator<T>& other)
            {
                *this = other;
            }
            map_iterator(const NodePtr &other, const NodePtr &NIL, const NodePtr &root)
            {
                this->root = root;
                it_ptr = other;
                this->NIL = NIL;
            }
            template <class T>
            map_iterator& operator=(const map_iterator<T> &other){
                this->root = other.root;
                it_ptr = other.it_ptr;
                NIL = other.NIL;
                return *this;
            }
            map_iterator& operator++()
            {
                if(it_ptr->right != NIL)
                {
                    it_ptr = it_ptr->right;
                    while(it_ptr->left != NIL)
                        it_ptr = it_ptr->left;
                }
                else
                {
                    NodePtr y = it_ptr->parent;
                    while(it_ptr == y->right)
                    {
                        it_ptr = y;
                        y = y->parent;
                    }
                    it_ptr = y;
                }
                return *this;
            }
            map_iterator operator++(int)
            {
                map_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            map_iterator& operator--()
            {
                if(it_ptr == NIL)
                    it_ptr = it_ptr->parent;
                else
                {
    
                    if(it_ptr->left !=  NIL)
                    {
                        it_ptr = it_ptr->left;
                        while(it_ptr->right != NIL)
                            it_ptr = it_ptr->right;
                    }
                    else
                    {
                        NodePtr y = it_ptr->parent;
                        while(it_ptr == y->left && it_ptr != NIL)
                        {
                            it_ptr = y;
                            y = y->parent;
                        }
                        it_ptr = y;
                    }
                }
                return *this;
            }
            map_iterator operator--(int)
            {
                map_iterator tmp = *this;
                --(*this);
                return tmp;
            }
       
            bool operator==(const map_iterator& Other) const
            {
                if(it_ptr == Other.it_ptr)
                    return 1;
                return 0;
            }
            bool operator!=(const map_iterator& Other) const
            {
                return (!operator==(Other));
            }
            pointer operator->()const
            {
                return &(operator*());
            }
            reference operator*()const
            {
                return it_ptr->value;
            }
            ~map_iterator() {}
    };
    //map_reverse_iterator------------------------------------
    template <class Iter>
    class reverse_iterator: public Iter
    {
        public:
            typedef Iter 		                                                   iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference         reference;
            protected:
                Iter iterator;
            public:
            reverse_iterator(){}
            explicit reverse_iterator( iterator_type x ){
                iterator = x;
            }
            template <class T>
            reverse_iterator(const reverse_iterator<T>& other){
                *this = other;
            }
            template <class T>
            reverse_iterator& operator=(const reverse_iterator<T> &other)
            {
                iterator = other.base();
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++iterator;
                return *this;
            }
            reverse_iterator& operator++()
            {
                --iterator;
                return *this;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return tmp;
            }
            bool operator==(const reverse_iterator& Other) const
            {
                return (iterator == Other.base());
            }
            bool operator!=(const reverse_iterator& Other) const
            {
                return (!operator==(Other));
            }
            reverse_iterator  operator+ (difference_type __n) const {
                reverse_iterator tmp(iterator - __n);
                return tmp;
            }
            reverse_iterator  operator- (difference_type __n) const {
                reverse_iterator tmp(iterator + __n);
                return tmp;
            }
            reverse_iterator  operator-= (difference_type __n) {
                return reverse_iterator(iterator += __n);
            }
            reverse_iterator  operator+= (difference_type __n) {
                return reverse_iterator(iterator -= __n);
            }
            difference_type operator-(const reverse_iterator &obj)const
            {
                return (obj.base() - iterator);
            }
            pointer operator->()
            {
                return &(operator*());
            }
            reference operator[](std::ptrdiff_t index)
            {
                return (iterator[((index + 1) * -1)]);
            }
            reference operator*() const {
                Iter __tmp = iterator;
                --__tmp;
                return *__tmp;
            }
            iterator_type base() const
            {
                iterator_type tmp(this->iterator);
                return tmp;
            }
            ~reverse_iterator() {}
       
    };
    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() == rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() != rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() > rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() >= rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
    {
         return (lhs.base() < rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() <= rhs.base());
    }
    //lexicographical_compare-------------------------------------------
    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
    
        return (first1 == last1) && (first2 != last2);
    }
};
#endif