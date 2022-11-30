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
            // __vector_iterators& operator=(const __vector_iterators& obj) {  this->it_ptr = obj.it_ptr; return (*this); }
            __vector_iterators& operator+=(std::ptrdiff_t n) { this->it_ptr += n; return (*this); }
            __vector_iterators& operator-=(std::ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            bool operator==(const __vector_iterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(const __vector_iterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(const __vector_iterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(const __vector_iterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(const __vector_iterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(const __vector_iterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        protected:
            typedef T                                                     value_type;
            typedef Allocator                                             allocator_type;
            typedef typename allocator_type::pointer                      pointer;
            typedef class __vector_iterators<pointer>                     iterator;
			iterator													  itv_ptr;
            pointer                                                       v_ptr;
            size_t                                                        __size_;
            size_t                                                        __capacity_;
            allocator_type                                                __alloc;

        public:
            vector():__size_(0), __capacity_(0){ this->itv_ptr.it_ptr = NULL; }
            vector(size_t n):__size_(n),__capacity_(n) { 
                this->v_ptr = __allocate(n);
                for(size_t i = 0; i < n; ++i)
                    this->v_ptr[i] = 0; 
            }
            iterator begin() { return (this->itv_ptr); }
            pointer __allocate(size_t n) {return __alloc.allocate(n); }
            size_t size() { return (this->__size_); }
            size_t capacity() { return (this->__capacity_); }
            void push_back(const value_type &val)
            {
                if(size() < capacity()){}
                else
                {
                    pointer tmp = __alloc.allocate(this->__capacity_ * 2);
                    for(int i = 0; i < __size_; ++i)
                    {
                        tmp[i] = this->v_ptr[i];
                    }
                    if(this->v_ptr)
                        __alloc.deallocate(this->v_ptr, this->__capacity_);
                    this->__capacity_ *= 2;
                    this->v_ptr = tmp;
                }
                this->v_ptr[size()] = val;
                this->__size_++;
                
            }
            value_type operator[](std::ptrdiff_t index)
            {
                return (this->v_ptr[index]);
            }
            vector& operator=(const vector&obj)
            {
                for(int i = 0; i < obj.size(); ++i)
                    this->v_ptr[i] = obj.v_ptr[i];
            }
    };
    
};

#endif