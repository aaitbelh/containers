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

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <memory>
#include <iostream>
#include  <stdexcept>
#include <type_traits>
namespace ft
{
template<class vector>
void swap(vector &v1, vector& v2)
{
    v1.swap(v2);
}

template<class Inputiterator>
Inputiterator operator+(const size_t n, Inputiterator &obj) {
    return obj + n;
}
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
    //---------------------------------------iterator-----
    template <class _TYPE>
    class __vector_iterators
    {
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;
			pointer																	it_ptr;
            __vector_iterators operator++(int){ __vector_iterators tmp(*this); this->it_ptr++; return (tmp); }
            __vector_iterators& operator++() { this->it_ptr++; return (*this); }
            __vector_iterators operator--(int){ __vector_iterators tmp(*this); this->it_ptr--; return (tmp); }
            __vector_iterators& operator--() { this->it_ptr--; return (*this); }
            __vector_iterators& operator+=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            __vector_iterators& operator-=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            __vector_iterators(){}
            __vector_iterators(const pointer &obj)
            {
                this->it_ptr = obj;
            }
			template<class P>
            __vector_iterators(const __vector_iterators<P> &obj)
            {
                *this = obj;
            }
            template<class P>
			__vector_iterators& operator=(const __vector_iterators<P> &obj)
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
            __vector_iterators operator+(long n)
            {
                __vector_iterators tmp = *this;
                tmp.it_ptr+=n;
                return tmp;
            }
            __vector_iterators operator-(long n)
            {
                __vector_iterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            long operator-(const __vector_iterators &obj)const
            {
                return (this->it_ptr - obj.it_ptr);
            }
            template<class P>
            bool operator==(const __vector_iterators<P>& obj)const { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator!=(const __vector_iterators<P>& obj)const { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator>(const __vector_iterators<P> &obj)const{ return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator<(const __vector_iterators<P>& obj)const{ return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator>=(const __vector_iterators<P>& obj)const { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            template<class P>
            bool operator<=(const __vector_iterators<P>& obj)const { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }
    };
    //----------------------------reverse_iterator
    template <class _TYPE>
    class __vector_riterators
    {
        protected:
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;
			pointer																	it_ptr;
            __vector_riterators operator++(int){ __vector_riterators tmp(*this); this->it_ptr--; return (tmp); }
            __vector_riterators& operator++() { this->it_ptr--; return (*this); }
            __vector_riterators operator--(int){ __vector_riterators tmp(*this); this->it_ptr++; return (tmp); }
            __vector_riterators& operator--() { this->it_ptr++; return (*this); }
            __vector_riterators& operator+=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            __vector_riterators& operator-=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
			__vector_riterators(){}
			__vector_riterators(const pointer &ptr)
			{
				this->it_ptr = ptr;
			}
            template<class other_type>
			__vector_riterators(const other_type &obj)
			{
				*this = obj;
			}
            template<class p>
			__vector_riterators& operator=(const __vector_riterators<p> &objs)
			{
				if(this->it_ptr != objs.it_ptr)
				    this->it_ptr = objs.it_ptr;
				return *this;
			}
            pointer operator->()
            {
                return (this->it_ptr);
            }
            reference operator*() const
            {
                return *it_ptr;
            }
            reference operator[](std::ptrdiff_t index)
            {
                return (*(this->it_ptr - index));
            }
            __vector_riterators operator+(size_t n)
            {
                __vector_riterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            __vector_riterators operator-(size_t n)
            {
                __vector_riterators tmp = *this;
                tmp.it_ptr += n;
                return tmp;
            }
            long operator-(const __vector_riterators &obj)const
            {
                return (obj.it_ptr - this->it_ptr);
            }
            template<class p>
            bool operator==(const __vector_riterators<p>& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator!=(const __vector_riterators<p>& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator>(const __vector_riterators<p>& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator<(const __vector_riterators<p>& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator>=(const __vector_riterators<p>& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }
            template<class p>
            bool operator<=(const __vector_riterators<p>& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }

    };
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
            typedef class __vector_iterators<pointer>                      iterator;
            typedef class __vector_riterators<pointer>                     reverse_iterator;
            typedef class __vector_iterators<const_pointer>                const_iterator;
            typedef class __vector_riterators<const_pointer>               const_reverse_iterator;
            vector():__capacity_(0),__size_(0), v_ptr(NULL){}  
            vector(size_t n, value_type val = 0):__capacity_(n),__size_(n), v_ptr(NULL)
            {
                this->v_ptr = __allocate(n);
                for(size_type i = 0; i < n; ++i)
                    __alloc.construct(this->v_ptr + i, val);
            }
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
			{
                vector tmp_v;
                for(;first != last; ++first)
                    tmp_v.push_back(*first);
                size_type tmp_size = tmp_v.size();
				this->v_ptr = __allocate(tmp_size);
                this->__capacity_ = tmp_size;
                for(this->__size_ = 0 ; __size_ < tmp_size; ++__size_)
                {
                    __alloc.construct(this->v_ptr + __size_, tmp_v[__size_]);
                }
			}
            vector(vector &obj)
            {
                *this = obj;
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
                tmp.it_ptr = v_ptr + __size_ - 1;
                return (tmp);
            }
            reverse_iterator rend()const
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr - 1;
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
            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last  ,typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
            {
                vector tmp_v;
                for(;first != last; ++first)
                    tmp_v.push_back(*first);
                size_type tmp_size = tmp_v.size();
                // std::cout << "SIZE == " <<  this->__size_ << " && " << tmp_size << std::endl;
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
            iterator insert( const_iterator pos, const T& value )
            {
                vector tmp_v;
                iterator first = begin();
                iterator tmp;
                for(;first <= end();++first)
                {
                    if(first == pos)
                    {
                        tmp = first;
                        tmp_v.push_back(value);
                    }
                    if(first < end())
                        tmp_v.push_back(*first);
                }
                this->swap(tmp_v);
                return (tmp);
            }
            iterator erase( iterator first, iterator last )
            {
                size_type distance = std::distance(first, last);
                this->__size_ -= distance;
                iterator first_it(last);
                for(; first < end(); ++first)
                {
                    *first = *first_it;
                    ++first_it;
                }
                for(size_type i = __size_; i < __size_ + distance ; ++i)
                    __alloc.destroy(this->v_ptr + i);
                return (last);
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
                    if(this->v_ptr)
                    {
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                    this->__capacity_ = n;
                    this->v_ptr = __allocate(n);
                    for(this->__size_ = 0; __size_ < n; ++__size_)
                        __alloc.construct(v_ptr + __size_, val);
                }
            }
            bool empty() { return (this->__size_ > 0 ? 0 : 1); }
            void clear() 
            {
                for(size_type i = 0; i < this->__size_; ++i)
                    __alloc.destroy(this->v_ptr + i); 
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
            size_type max_size() const { return __alloc.max_size(); }
            void push_back( const T& val)
            {
                if(!this->v_ptr) { 
                    this->v_ptr = __allocate(1); 
                    __alloc.construct(this->v_ptr, val);
                    __size_++;
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
                    __alloc.deallocate(this->v_ptr, this->__capacity_);
                }
            }
        protected:
            size_t															__capacity_;
            size_t															__size_;
            allocator_type													__alloc;
            pointer															v_ptr;
    };
    
};
#endif