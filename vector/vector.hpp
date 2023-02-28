/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */    
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:33 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/11/23 22:25:25 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_vector_HPP
#define FT_vector_HPP
#include <memory>
#include <iostream>
#include  <stdexcept>
#include <type_traits>
#include <algorithm>
#include "../iterators/iterators.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T														value_type;
            typedef Allocator												allocator_type;
            typedef size_t                                                  size_type;
            typedef typename allocator_type::pointer				        pointer;
            typedef typename allocator_type::const_pointer					const_pointer;
            typedef typename allocator_type::reference						reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::difference_type                difference_type;
            typedef ft::iterator<pointer>                                   iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::iterator<const_pointer>                             const_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            explicit vector(const allocator_type& alloc = allocator_type()):__capacity_(0),__size_(0),__alloc(alloc), v_ptr(NULL) {}  
            explicit vector(size_type n, const value_type& val = value_type(),  const Allocator& alloc = Allocator()):__capacity_(n),__size_(n), __alloc(alloc), v_ptr(NULL)
            {
                this->v_ptr = __allocate(n);
                for(size_type i = 0; i < n; ++i)
                    __alloc.construct(this->v_ptr + i, val);
            }
			template<class InputIterator>
			vector(InputIterator first, InputIterator last,  const allocator_type& alloc = allocator_type(), typename std::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0):__capacity_(0),__size_(0),__alloc(alloc), v_ptr(NULL)
			{
                if(!ft::is_same<typename ft::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
                {
                    vector tmp_v;
                    for(;first != last; ++first)
                        tmp_v.push_back(*first);
                    if(tmp_v.size())
                    {
                        size_type tmp_size = tmp_v.size();
                        this->v_ptr = __allocate(tmp_size);
                        this->__capacity_ = tmp_size;
                        for(this->__size_ = 0 ; __size_ < tmp_size; ++__size_)
                        {
                            __alloc.construct(this->v_ptr + __size_, tmp_v[__size_]);
                        }
                    }
                }
                else
                {
                    size_t size = std::distance(first, last);
                    if(size)
                    {
                        this->v_ptr = __allocate(size);
                        int i = 0;
                        for(; first != last; ++first)
                        {
                            __alloc.construct(this->v_ptr + i, *first);
                            i++;
                        }
                        this->__size_  = size;
                        this->__capacity_ = size;
                    }
                }
			}
            vector(const vector &obj)
            {
                this->v_ptr = NULL;
                this->__capacity_ = obj.capacity();
                this->__size_  = obj.size();
                if(__capacity_)
                    this->v_ptr = __alloc.allocate(this->__capacity_);
                for(size_t i =0; i < __size_; ++i)
                    __alloc.construct(this->v_ptr + i, obj[i]);
            }
            iterator begin() const {
                return (iterator(v_ptr));
            }
            iterator end() const { 

                return (this->v_ptr + __size_);
            }
            reverse_iterator rbegin()const
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr + __size_;
                return (tmp);
            }
            reverse_iterator rend()const
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr;
                return (tmp);
            }
            pointer __allocate(size_t n) {return __alloc.allocate(n); }
            //---------------------------memeber_functions------------
            
            reference front()const { return (*this->v_ptr); } 
            reference back()const 
            { 
                return (this->v_ptr[__size_ - 1]); 
            }
			reference at( size_type pos )const
			{
				if(pos >= this->__size_)
					throw(std::out_of_range(""));
				return this->v_ptr[pos];
			}
            void swap(vector& other)
            {
                size_type tmp_size = this->__size_;
                size_type tmp_capacity  = this->__capacity_;
                pointer tmp_ptr = this->v_ptr;
                this->__size_ = other.size();
                this->__capacity_ = other.capacity();
                this->v_ptr = other.v_ptr;
                other.v_ptr = tmp_ptr;
                other.__size_ = tmp_size;
                other.__capacity_ = tmp_capacity;
            }
            void assign(size_t n, const value_type &val)
            {
                this->clear();
                if(n < this->__capacity_)
                {
                    for(this->__size_ = 0; this->__size_ < n; ++__size_)
                        __alloc.construct(v_ptr + __size_, val);
                }
                else
                {
                    vector Svect(n, val);
                    this->swap(Svect);
                }
            }
            template <class InputIterator> 
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
            {
                if(!ft::is_same<typename ft::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
                {
                    this->clear();
                    size_type tmp_size = std::distance(first, last);
                    if(tmp_size > this->__capacity_)
                    {
                        if(this->v_ptr)
                            __alloc.deallocate(this->v_ptr, this->__capacity_);
                        this-> v_ptr = __alloc.allocate(tmp_size);
                        this->__capacity_ = tmp_size;
                    }
                    for(this->__size_ = 0 ;__size_ < tmp_size;)
                    {
                        __alloc.construct(this->v_ptr + __size_, *first);
                        ++first;
                        ++__size_;
                    }
                    return ;

                }
                vector tmp_v;
                for(;first != last; ++first)
                    tmp_v.push_back(*first);
                size_type tmp_size = tmp_v.size();
                this->clear();
                if(tmp_size > this->__capacity_)
                {
                    if(this->v_ptr)
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    this-> v_ptr = __alloc.allocate(tmp_size);
                    this->__capacity_ = tmp_size;
                }
                for(this->__size_ = 0 ;__size_ < tmp_size;)
                {
                    __alloc.construct(this->v_ptr + __size_, tmp_v[__size_]);
					++__size_;
                }
            }
            template <class InputIterator>    
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
            {
                if(!ft::is_same<typename ft::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
                {
                    size_type n = std::distance(first, last);
                    if(this->__size_ + n <= this->__capacity_)
                    {
                        iterator tmp = end();
                        size_t i = size();
                        for(; i > 0; --i)
                        {
                            if(tmp == position)
                                break;
                            if(i <= this->__size_)
                                __alloc.destroy(this->v_ptr + i - 1);
                            __alloc.construct(this->v_ptr + i + n - 1, *(--tmp));
                        }
                        for(size_t j = 0; j < n; ++j, ++first)
                            __alloc.construct(this->v_ptr + i + j, *first);
                        this->__size_ += n;
                    }
                    else
                        goto new_vec;
                }
                else
                {
                    new_vec:
                    vector GetSize(first, last);
                    vector tmp_v;
                    size_type  c = 0;
                    if(this->__size_ + GetSize.size() > this->__capacity_ * 2)
                        c = this->__size_ + GetSize.size();
                    else
                        c = this->__capacity_ * 2;
                    tmp_v.reserve(c);
                    iterator first_it = begin();
                    for(;first_it <= end(); ++first_it)
                    {
                        if(first_it == position)
                        {
                            for(size_type i = 0; i < GetSize.size(); ++i)
                                tmp_v.push_back(GetSize[i]);
                        }
                        if(first_it != end())
                            tmp_v.push_back(*first_it);
                    }
                    this->swap(tmp_v);
                }
            }
            void insert(iterator position, size_type n, const value_type& val)
            {

                if(this->__size_ + n <= this->__capacity_)
                {
                    iterator tmp = end();
                    size_t i = size();
                    for(; i > 0; --i)
                    {
                        if(tmp == position)
                            break;
                        if(i <= this->__size_)
                            __alloc.destroy(this->v_ptr + i - 1);
                        __alloc.construct(this->v_ptr + i + n - 1, *(--tmp));
                    }
                    for(size_t j = 0; j < n; ++j)
                        __alloc.construct(this->v_ptr + i + j, val);
                    this->__size_ += n;
                    return ;
                }
                vector tmp_v;
                iterator first = begin();
                size_type c = 0;
                if(!this->__capacity_ || __capacity_ * 2 < n)
                    c = this->__capacity_ + n;
                else
                    c = this->__capacity_ * 2;
                tmp_v.reserve(c);
                for(;first <= end(); ++first)
                {
                    if(first == position)
                    {
                        for(size_type i = 0; i < n; ++i)
                            tmp_v.push_back(val);
                    }
                    if(first != end())
                        tmp_v.push_back(*first);
                }
                this->swap(tmp_v);
            }
            iterator insert(iterator pos, const T& value )
            {
                if(this->__size_ + 1 <= this->__capacity_)
                {
                    iterator tmp = end();
                    size_t i = size();
                    for(iterator it = end(); tmp != pos; --it, --i)
                    {
                        if(i != size())
                            __alloc.destroy(this->v_ptr + i);
                        __alloc.construct(this->v_ptr + i, *(--tmp));
                    }
                    this->__size_++;
                    *pos = value;
                    return (pos);
                }
                vector tmp_v;
                iterator first = begin();
                iterator tmp;
                size_type c = 0;
                if(!this->__capacity_)
                    c = 1;
                else
                    c = this->__capacity_ * 2;
                tmp_v.reserve(c);
                for(;first <= end();++first)
                {
                    if(first == pos)
                    {
                        tmp_v.push_back(value);
                        tmp = tmp_v.end() - 1;
                    }
                    if(first != end())
                        tmp_v.push_back(*first);
                }
                this->swap(tmp_v);
                return (tmp);
            }
            iterator erase( iterator first, iterator last )
            {
                size_type distance = std::distance(first, last);
                iterator tmp = first;
                this->__size_ -= distance;x
                iterator first_it(last);
                for(; first < end(); ++first)
                {
                    *first = *first_it;
                    ++first_it;
                }
                for(size_type i = __size_; i < __size_ + distance ; ++i)
                    __alloc.destroy(this->v_ptr + i);
                return (tmp);
            }
            iterator erase( iterator pos )
            {
                iterator first_it(pos);
                iterator tmp_one(pos); 
                for(;first_it < this->end() - 1; ++pos)
                {
                    *pos = *(++first_it);
                }
                this->__size_--;
                __alloc.destroy(this->v_ptr + __size_);
                return tmp_one;
            }
            bool empty() const { return (this->__size_ > 0 ? 0 : 1); }
            void clear() 
            {
                for(size_type i = 0; i < this->__size_; ++i)
                {
                    __alloc.destroy(this->v_ptr + i); 
                }
                this->__size_ = 0;
            }
            void reserve(size_t __n)
            {
                if(__n > this->__capacity_)
                {
                    pointer tmp = __allocate(__n);
                    for(size_t i = 0; i < this->__size_; ++i)
                        __alloc.construct(tmp + i, this->v_ptr[i]);
                    if(this->v_ptr)
                    {
                        size_type tmp_size  = this->__size_;
                        this->clear();
                        this->__size_ = tmp_size;
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                    this->__capacity_ = __n;
                    this->v_ptr = tmp;
                }
            }
            void resize(size_type n, T val = T())
            {
                if(n > __size_)
                {
                    if(this->__capacity_ < n)
                    {
                        size_t tmp_capacity = __capacity_;
                        if(this->__capacity_ * 2 < n)
                            __capacity_ = n;
                        else
                            __capacity_ *= 2;
                        pointer tmp = __allocate(this->__capacity_);
                        for(size_t i = 0; i < __size_ ; ++i)
                            __alloc.construct(tmp + i, v_ptr[i]);
                        if(this->v_ptr)
                        {
                            for(size_t i = 0; i < __size_ ; ++i)
                                __alloc.destroy(v_ptr + i);
                            __alloc.deallocate(this->v_ptr, tmp_capacity);
                        }
                        v_ptr = tmp;
                    }
                    for(size_t i = __size_; i < n ; ++i)
                        __alloc.construct(v_ptr + i, val);
                }
                else
                    for(size_t i = n ; i < __size_ ; ++i)
                        __alloc.destroy(v_ptr + i);
                this->__size_ = n; 
                
            }
            size_t size()const { return (this->__size_); }
            size_t capacity()const { return (this->__capacity_); }
            size_type max_size() const { 
                return std::min<size_type>(__alloc.max_size(), std::numeric_limits<difference_type>::max()); 
                }
            void push_back( const T& val)
            {
                if(!this->v_ptr) { 
                    this->v_ptr = __allocate(1); 
                    __alloc.construct(this->v_ptr, val);
                    __size_ = 1;
                    __capacity_= 1;
                    return ;
                }
                if(size() < capacity()){}
                else
                {
                    pointer tmp = __allocate(__capacity_ * 2);
                    for(size_type i = 0; i < __size_; ++i)
                    {
                        __alloc.construct(tmp + i , this->v_ptr[i]);
                    }
                    int tmp_size = this->__size_;
                    if(this->v_ptr)
                    {
                        this->clear();
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                    this->__capacity_ *= 2;
                    this->__size_ = tmp_size;
                    this->v_ptr = tmp;
                }
                __alloc.construct(this->v_ptr + __size_, val);
                this->__size_++;   
            }
            void pop_back()
            {
                this->__size_--;
                __alloc.destroy(this->v_ptr + __size_);
            }
            reference operator[]( size_type pos )const
            {
                return (this->v_ptr[pos]);
            }
            allocator_type get_allocator() const
            {
                return (this->__alloc);
            }
            vector& operator=(const vector &obj)
            {
                this->clear();
                if(__capacity_ < obj.capacity())
                {
                    if(this->v_ptr)
                    {
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                    this->v_ptr = __allocate(obj.capacity());
                    this->__capacity_ = obj.capacity();
                }
                for(size_type i = 0; i < obj.size(); ++i)
                    __alloc.construct(this->v_ptr + i, obj[i]);
                this->__size_ = obj.size();
                return *this;
            }
            ~vector()
            {
                if(this->v_ptr)
                {
                    this->clear();
                    if(this->v_ptr)
                    {
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                }
            }
        protected:
            size_t															__capacity_;
            size_t															__size_;
            allocator_type													__alloc;
            pointer															v_ptr;
    };

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
    template<class T, class _Allocator>
    bool operator==(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs)
    {
        return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template<class T, class _Allocator>
    bool operator!=(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs )
    {
        return !(lhs == rhs);
    }
    template<class T, class _Allocator>
    bool operator<(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template<class T, class _Allocator>
    bool operator>(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs)
    {
        return rhs < lhs;
    }
    template<class T, class _Allocator>
    bool operator<=(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs)
    {
        return !(rhs < lhs);
    }
    template<class T, class _Allocator>
    bool operator>=(const ft::vector<T, _Allocator> &lhs, const ft::vector<T, _Allocator> &rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Allocator>
    void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    {
        x.swap(y);
    }
};
#endif