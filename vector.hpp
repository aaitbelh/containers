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
namespace ft
{
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
            __vector_iterators(__vector_iterators &obj)
            {
                *this = obj;
            }
            value_type& operator[](std::ptrdiff_t index)
            {
                return (this->it_ptr[index]);
            }
            value_type& operator*()
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

    //-----------------------const-iterator------------------
    template <class _TYPE>
    class const__vector_iterators
    {
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;
			pointer																	it_ptr;
            const const__vector_iterators operator++(int){ const__vector_iterators tmp(*this); this->it_ptr++; return (tmp); }
            const const__vector_iterators& operator++() { this->it_ptr++; return (*this); }
            const const__vector_iterators operator--(int){ const__vector_iterators tmp(*this); this->it_ptr--; return (tmp); }
            const const__vector_iterators& operator--() { this->it_ptr--; return (*this); }
            const const__vector_iterators& operator=(const const__vector_iterators& obj) {  this->it_ptr = obj.it_ptr; return (*this); }
            const const__vector_iterators& operator+=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            const const__vector_iterators& operator-=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            const__vector_iterators(){}
            const__vector_iterators(const__vector_iterators &obj)
            {
                *this = obj;
            }
            const value_type& operator*()
            {
                return *it_ptr;
            }
            const value_type& operator[](std::ptrdiff_t index)
            {
                return (this->it_ptr[index]);
            }
            const const__vector_iterators operator+(long n)
            {
                const__vector_iterators tmp = *this;
                tmp.it_ptr+=n;
                return tmp;
            }
            const const__vector_iterators operator-(long n)
            {
                const__vector_iterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }

            bool operator==(const const__vector_iterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const const__vector_iterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const const__vector_iterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const const__vector_iterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const const__vector_iterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const const__vector_iterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

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
            __vector_riterators& operator=(const __vector_riterators& obj) {  this->it_ptr = obj.it_ptr; return (*this); }
            __vector_riterators& operator+=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            __vector_riterators& operator-=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            value_type& operator*()
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
                tmp.it_ptr-=n;
                return tmp;
            }
            bool operator==(const __vector_riterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const __vector_riterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const __vector_riterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const __vector_riterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const __vector_riterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const __vector_riterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    // --------------const-reverse-iterator
    template <class _TYPE>
    class const__vector_riterators
    {
        public:
            typedef _TYPE 		                                                    iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;
			pointer																	it_ptr;
            const const__vector_riterators operator++(int){ const__vector_riterators tmp(*this); this->it_ptr--; return (tmp); }
            const const__vector_riterators& operator++() { this->it_ptr--; return (*this); }
            const const__vector_riterators operator--(int){ const__vector_riterators tmp(*this); this->it_ptr++; return (tmp); }
            const const__vector_riterators& operator--() { this->it_ptr++; return (*this); }
            const const__vector_riterators& operator=(const const__vector_riterators& obj) {  this->it_ptr = obj.it_ptr; return (*this); }
            const const__vector_riterators& operator+=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            const const__vector_riterators& operator-=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            const value_type& operator[](std::ptrdiff_t index)
            {
                return (it_ptr[index]);
            }
            const value_type& operator*()
            {
                return *it_ptr;
            }
            const__vector_riterators operator+(long n)
            {
                const__vector_riterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            const__vector_riterators operator-(long n)
            {
                const__vector_riterators tmp = *this;
                tmp.it_ptr-=n;
                return tmp;
            }
            bool operator==(const const__vector_riterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const const__vector_riterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const const__vector_riterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const const__vector_riterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const const__vector_riterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const const__vector_riterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        protected:
            typedef T                                                     value_type;
            typedef Allocator                                             allocator_type;
            typedef typename allocator_type::pointer                      pointer;
            size_t                                                        __size_;
            size_t                                                        __capacity_;
            allocator_type                                                __alloc;
            __vector_iterators<pointer>                                   v_ptr;

        public:
            typedef class __vector_iterators<pointer>                     iterator;
            typedef class __vector_riterators<pointer>                    reverse_iterator;
            typedef class const__vector_iterators<pointer>                const_iterator;
            typedef class const__vector_riterators<pointer>               const_reverse_iterator;
            vector():__size_(0), __capacity_(0){ this->v_ptr.it_ptr = NULL; }
            template <typename = std::enable_if<std::is_integral<T>::value>>
            vector(size_t n, value_type val):__size_(n), __capacity_(n)
            {
                this->v_ptr.it_ptr = __allocate(n);
                for(int i = 0; i < n; ++i)
                    v_ptr.it_ptr[i] = val;
            }
            vector(size_t n):__size_(n),__capacity_(n) { 
                this->v_ptr.it_ptr = __allocate(n);
                for(size_t i = 0; i < n; ++i)
                    this->v_ptr.it_ptr[i] = 0; 
            }
            vector(vector &obj)
            {
                this->__size_ = obj.size();
                this->__capacity_ = obj.capacity();
                this->v_ptr = __allocate(this->__capacity_);
                for(int i = 0; i < __size_; ++i)
                    this->v_ptr.it_ptr[i] = obj[i];
            }
            iterator begin() {return (this->v_ptr); }
            const_iterator cbegin()
            {
                const_iterator tmp;
                tmp.it_ptr = v_ptr.it_ptr;
                return (tmp);
            }
            iterator end() { 

                return (this->v_ptr + __size_);
            }
            reverse_iterator rbegin()
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr.it_ptr + (__size_ - 1);
                return (tmp);
            }
            reverse_iterator rend()
            {
                reverse_iterator tmp;
                tmp.it_ptr = v_ptr.it_ptr - 1;
                return (tmp);
            }
            const_reverse_iterator crbegin()
            {
                const_reverse_iterator tmp;
                tmp.it_ptr = v_ptr.it_ptr + (__size_ - 1);
                return (tmp);
            }
            const_reverse_iterator crend()
            {
                const_reverse_iterator tmp;
                tmp.it_ptr = v_ptr.it_ptr - 1;
                return (tmp);
            }
            pointer __allocate(size_t n) {return __alloc.allocate(n); }
            //---------------------------memeber_functions------------
            
            // template< class U, typename = std::enable_if<!std::is_integral<U>::value>>
            // void assign(U first, U second)
            // {
            //     size_t tmp_size = second - first;
            //     if(tmp_size > this->__capacity_)
            //     {
            //         if(this->v_ptr.it_ptr)
            //             __alloc.deallocate(this->v_ptr.it_ptr, this->__capacity_);
            //         this->v_ptr.it_ptr = __allocate(tmp_size);
            //         this->__capacity_  = tmp_size;
            //     }
            //     for(this->__size_ = 0 ;first < second; first++ && ++__size_)
            //     {
            //         this->v_ptr.it_ptr[this->__size_] = *first;
            //     }
            // }
            void assign(size_t n, const value_type &val)
            {
                if(n < this->__capacity_)
                {
                    for(this->__size_ = 0; this->__size_ < n; ++__size_)
                        this->v_ptr.it_ptr[__size_] = val;
                }
                else
                {
                    if(this->v_ptr.it_ptr)
                        __alloc.deallocate(this->v_ptr.it_ptr, this->__capacity_);
                    this->__capacity_ = n;
                    this->v_ptr.it_ptr = __allocate(n);
                    for(this->__size_ = 0; this->__size_ < n; ++__size_)
                        this->v_ptr.it_ptr[__size_] = val;
                }
            }
            bool empty() { return (this->__size_ > 0 ? 1 : 0); }
            void resize(size_t  n) {
                if(n < 0)
                    throw(std::length_error);
                this->__size_ = n;
            }
            size_t size() { return (this->__size_); }
            size_t capacity() { return (this->__capacity_); }
            void push_back(const value_type &val)
            {
                if(!this->v_ptr.it_ptr) { 
                    this->v_ptr.it_ptr = __allocate(1); 
                    this->v_ptr.it_ptr[__size_] = val;
                    __size_++;
                    __capacity_= 1;
                    return ; 
                    }
                if(size() < capacity()){}
                else
                {
                    pointer tmp = __allocate(__capacity_ * 2);
                    for(int i = 0; i < __size_; ++i)
                    {
                        tmp[i] = this->v_ptr.it_ptr[i];
                    }
                    if(this->v_ptr.it_ptr)
                        __alloc.deallocate(this->v_ptr.it_ptr, this->__capacity_);
                    this->__capacity_ *= 2;
                    this->v_ptr.it_ptr = tmp;
                }
                this->v_ptr.it_ptr[__size_] = val;
                this->__size_++;
                
            }
            void pop_back()
            {
                this->__size_--;
            }
            value_type operator[](std::ptrdiff_t index)
            {
                return (this->v_ptr.it_ptr[index]);
            }
            vector& operator=(const vector&obj)
            {
                this->__size_ = obj.size();
                if(__capacity_ < obj.capacity)
                {
                    __alloc.deallocate(this->v_ptr.it_ptr, this->__capacity_);
                    this->v_ptr.it_ptr = allocate(obj.__capacity_);
                    this->__capacity_ = obj.capacity();
                }
                for(int i = 0; i < obj.size(); ++i)
                    this->v_ptr.it_ptr[i] = obj.v_ptr.it_ptr[i];
            }
            ~vector()
            {
                if(this->v_ptr.it_ptr)
                    __alloc.deallocate(this->v_ptr.it_ptr, this->__capacity_);
            }
    };
    
};

#endif