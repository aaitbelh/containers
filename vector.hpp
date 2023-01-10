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
            __vector_iterators& operator=(const __vector_iterators& obj) {  this->it_ptr = obj.it_ptr; return (*this); }
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
            bool operator==(const __vector_iterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const __vector_iterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const __vector_iterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const __vector_iterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const __vector_iterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const __vector_iterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    //----------------------------reverse_iterator
    template <class _TYPE>
    class __vector_riterators
    {
        protected:
            size_t operator-(const __vector_riterators & obj)
            {
                return (this->it_ptr - obj.it_ptr);
            }
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
			__vector_riterators(__vector_riterators &obj)
			{
				*this = obj;
			}
			__vector_riterators& operator=(const __vector_riterators &objs)
			{
				this->it_ptr = objs.it_ptr;
				return *this;
			}

            reference operator*() const
            {
                return *it_ptr;
            }
            value_type& operator[](std::ptrdiff_t index)
            {
                return (this->it_ptr[index]);
            }
            __vector_riterators operator+(long n)
            {
                __vector_riterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            __vector_riterators operator-(long n)
            {
                __vector_riterators tmp = *this;
                tmp.it_ptr -= n;
                return tmp;
            }
            bool operator==(const __vector_riterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const __vector_riterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const __vector_riterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const __vector_riterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const __vector_riterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const __vector_riterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        protected:
            typedef T														value_type;
            typedef Allocator												allocator_type;
            typedef size_t                                                  size_type;
            typedef typename allocator_type::pointer				        pointer;
            typedef typename allocator_type::const_pointer					const_pointer;
            typedef typename allocator_type::reference						reference;
            size_t															__capacity_;
            size_t															__size_;
            allocator_type													__alloc;
            pointer															v_ptr;

        public:
            typedef class __vector_iterators<pointer>                      iterator;
            typedef class __vector_riterators<pointer>                     reverse_iterator;
            typedef class __vector_iterators<const_pointer>                const_iterator;
            typedef class __vector_riterators<const_pointer>               const_reverse_iterator;
            vector():__capacity_(0),__size_(0), v_ptr(NULL){}  
            vector(size_t n, value_type val = 0):__capacity_(n),__size_(n), v_ptr(NULL)
            {
                this->v_ptr = __allocate(n);
                for(size_type i = 0; i < n; ++i)
                    v_ptr[i] = val;
            }
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
			{
				size_t tmp_size = last - first;
				this->v_ptr = __allocate(tmp_size);
                this->__capacity_ = tmp_size;
                for(this->__size_ = 0 ;first < last; first++)
                {
                    this->v_ptr[this->__size_] = *first;
					++__size_;
                }
			}
            vector(vector &obj)
            {
                this->__size_ = obj.size();
                this->__capacity_ = obj.capacity();
                this->v_ptr = __allocate(this->__capacity_);
                for(int i = 0; i < __size_; ++i)
                    this->v_ptr[i] = obj[i];
            }
            iterator begin() {
                return (iterator(v_ptr));
            }
            iterator end() { 

                return (this->v_ptr + __size_);
            }
            reverse_iterator rbegin()
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr + (__size_ - 1);
                return (tmp);
            }
            reverse_iterator rend()
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr - 1;
                return (tmp);
            }
            pointer __allocate(size_t n) {return __alloc.allocate(n); }
            //---------------------------memeber_functions------------
            
            reference front() { return (this->v_ptr[0]); } 
            reference back() { return (this->v_ptr[__size_ - 1]); }
			reference at(size_t n)
			{
				if(n >= this->__size_)
					throw(std::out_of_range(""));
				return this->v_ptr[n];
			}
            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
            {
                size_t tmp_size = last - first;
                if(tmp_size > this->__capacity_)
                {
                    __alloc.destroy(this->v_ptr);
                    this->reserve(tmp_size);
                }
                for(this->__size_ = 0 ;first < last; first++)
                {
                    this->v_ptr[this->__size_] = *first;
					++__size_;
                }
            }
			// template<class iterator>
			// void insert (iterator position, size_type n, const value_type& val)
			// {
			// }
            void assign(size_t n, const value_type &val)
            {
                if(n < this->__capacity_)
                {
                    __alloc.destroy(this->v_ptr);
                    for(this->__size_ = 0; this->__size_ < n; ++__size_)
                        __alloc.construct(v_ptr + __size_, val);
                }
                else
                {
                    if(this->v_ptr)
                    {
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                        __alloc.destroy(this->v_ptr);
                    }
                    this->__capacity_ = n;
                    this->v_ptr = __allocate(n);
                    for(this->__size_ = 0; __size_ < n; ++__size_)
                        __alloc.construct(v_ptr + __size_, val);
                }
            }
            bool empty() { return (this->__size_ > 0 ? 0 : 1); }
            void reserve(size_t __n)
            {
                if(__n > this->__capacity_)
                {
                    pointer tmp = __allocate(__n);
                    for(size_t i = 0; i < this->__size_; ++i)
                        tmp[i] = this->v_ptr[i];
                    if(this->v_ptr)
                    {
                        __alloc.destroy(this->v_ptr);
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    }
                    this->__capacity_ = __n;
                    this->v_ptr = tmp;
                }
            }
            void resize(size_type n, T val = T())
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
                    {
                        __alloc.construct(tmp + i, v_ptr[i]);
                    }
                    for(size_t i = __size_; i < n ; ++i)
                    {
                        __alloc.construct(tmp + i, val);
                    }
                    if(this->v_ptr)
                    {
                        __alloc.destroy(this->v_ptr);
                        __alloc.deallocate(this->v_ptr, tmp_capacity);
                    }
                    v_ptr = tmp;
                }
                else
                {
                    __alloc.destroy(this->v_ptr + n);
                }
                this->__size_ = n;
                
            }
            size_t size() { return (this->__size_); }
            size_t capacity() { return (this->__capacity_); }
            size_type max_size() const { return __alloc.max_size(); }
            void push_back( const T& val)
            {
                if(!this->v_ptr) { 
                    this->v_ptr = __allocate(1); 
                    this->v_ptr[__size_] = val;
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
                        tmp[i] = this->v_ptr[i];
                    }
                    if(this->v_ptr)
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    this->__capacity_ *= 2;
                    this->v_ptr = tmp;
                }
                this->v_ptr[__size_] = val;
                this->__size_++;
                
            }
            void pop_back()
            {
                this->__size_--;
            }
            reference operator[]( size_type pos )
            {
                return (this->v_ptr[pos]);
            }
            vector& operator=(const vector&obj)
            {
                this->__size_ = obj.size();
                if(__capacity_ < obj.capacity)
                {
                    __alloc.deallocate(this->v_ptr, this->__capacity_);
                    this->v_ptr = allocate(obj.__capacity_);
                    this->__capacity_ = obj.capacity();
                }
                for(int i = 0; i < obj.size(); ++i)
                    this->v_ptr[i] = obj.v_ptr[i];
            }
            ~vector()
            {
                if(this->v_ptr)
                {
                    __alloc.destroy(this->v_ptr);
                    __alloc.deallocate(this->v_ptr, this->__capacity_);
                }
            }
    };
    
};
#endif