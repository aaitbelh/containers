/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:27:39 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/26 16:34:29 by aaitbelh         ###   ########.fr       */
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
            reference operator[](std::ptrdiff_t index)
            {
                return (this->it_ptr[index]);
            }
            pointer operator->()
            {
                return (this->it_ptr);
            }
            reference operator*()
            {
                return *it_ptr;
            }
            iterator operator+(long n)
            {
                iterator tmp = *this;
                tmp.it_ptr+=n;
                return tmp;
            }
            iterator operator-(long n)
            {
                iterator tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            long operator-(const iterator &obj)const
            {
                return (this->it_ptr - obj.it_ptr);
            }
            iterator_type base() const
            {
                return (it_ptr);
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
    //---------------------------------------reverse_iterator-----
    template <class _TYPE>
    class reverse_iterator
    {
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference         reference;
			iterator_type														    it_ptr;
            reverse_iterator operator++(int){ reverse_iterator tmp(*this); this->it_ptr--; return (tmp); }
            reverse_iterator& operator++() { this->it_ptr--; return (*this); }
            reverse_iterator operator--(int){ reverse_iterator tmp(*this); this->it_ptr++; return (tmp); }
            reverse_iterator& operator--() { this->it_ptr++; return (*this); }
            reverse_iterator& operator+=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            reverse_iterator& operator-=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
			reverse_iterator():it_ptr(NULL){}
            explicit reverse_iterator(iterator_type x) : it_ptr(x)
            {
            }
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other )
            {
                if(this->it_ptr != other.it_ptr)
                    this->it_ptr  = other.base();
            }

            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other )
            {
                this->it_ptr = other.base();
                return *this;
            }

            pointer operator->()
            {
                return &(this->operator*());
            }
            reference operator*() const
            {
                iterator_type tmp = it_ptr;
                return *(--tmp);
            }
            reference operator[](std::ptrdiff_t index)
            {
                return (*(this->it_ptr - index -1));
            }
            reverse_iterator operator+(size_t n)
            {

                return (reverse_iterator(this->it_ptr - n));
            }
            reverse_iterator operator-(size_t n)
            {
                return (reverse_iterator(this->it_ptr + n));
            }
            long operator-(const reverse_iterator &obj)const
            {
                return (obj.it_ptr - this->it_ptr);
            }
            iterator_type base()const
            {
                return (it_ptr);
            }
            template<class p>
            bool operator==(const reverse_iterator<p>& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator!=(const reverse_iterator<p>& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator>(const reverse_iterator<p>& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator<(const reverse_iterator<p>& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator>=(const reverse_iterator<p>& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator<=(const reverse_iterator<p>& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }

    };
    //----------------------------map_iterators
    template <class _TYPE>
    class map_iterator
    {
        public:
            typedef _TYPE 		                                                   iterator_type;
            typedef std::bidirectional_iterator_tag                                iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            // typedef typename ft::iterator_traits<iterator_type>::size_type         size_type;
            // typedef typename ft::iterator_traits<iterator_type>::const_pointer     const_pointer;
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
            map_iterator& operator=(const map_iterator<T> &other)
            {
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
                    while(y != NIL && it_ptr == y->right)
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
                if(it_ptr->left != NIL)
                {
                    it_ptr = it_ptr->left;
                    while(it_ptr->right != NIL)
                        it_ptr = it_ptr->right;
                }
                else
                {
                    NodePtr y = it_ptr->parent;
                    while(it_ptr == y->left)
                    {
                        it_ptr = y;
                        y = y->parent;
                    }
                    it_ptr = y;
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
            pointer operator->()
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
    template <class _TYPE>
    class reverse_it_map
    {
        public:
            typedef _TYPE 		                                                   iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
            // typedef typename ft::iterator_traits<iterator_type>::size_type         size_type;
            // typedef typename ft::iterator_traits<iterator_type>::const_pointer     const_pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference         reference;
            typedef Node<value_type>* NodePtr;
            NodePtr root;
            NodePtr it_ptr;
            NodePtr NIL;
            reverse_it_map(){}
            
            template <class T>
            reverse_it_map(const reverse_it_map<T>& other)
            {
                *this = other;
            }
            reverse_it_map(const NodePtr &other, const NodePtr &NIL, const NodePtr &root)
            {
                this->root = root;
                it_ptr = other;
                this->NIL = NIL;
            }
            template <class T>
            reverse_it_map& operator=(const reverse_it_map<T> &other)
            {
                this->root = other.root;
                it_ptr = other.it_ptr;
                NIL = other.NIL;
                return *this;
            }
            reverse_it_map& operator--()
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
            reverse_it_map& operator++()
            {
                if(it_ptr->left != NIL)
                {
                    it_ptr = it_ptr->left;
                    while(it_ptr->right != NIL)
                        it_ptr = it_ptr->right;
                }
                else
                {
                    NodePtr y = it_ptr->parent;
                    while(y != NIL && it_ptr == y->left)
                    {
                        it_ptr = y;
                        y = y->parent;
                    }
                    it_ptr = y;
                }
                return *this;
            }
            reverse_it_map operator++(int)
            {
                reverse_it_map tmp = *this;
                ++(*this);
                return tmp;
            }
            reverse_it_map operator--(int)
            {
                reverse_it_map tmp = *this;
                --(*this);
                return tmp;
            }
            bool operator==(const reverse_it_map& Other) const
            {
                if(it_ptr == Other.it_ptr)
                    return 1;
                return 0;
            }
            bool operator!=(const reverse_it_map& Other) const
            {
                return (!operator==(Other));
            }
            pointer operator->()
            {
                return &(operator*());
            }
            reference operator*()const
            {
                reverse_it_map tmp(this->it_ptr, this->NIL, this->it_ptr);
                return (tmp.it_ptr->value);
            }
            ~reverse_it_map() {}
       
    };
};
#endif