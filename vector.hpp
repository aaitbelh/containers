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
            __vector_iterators& operator=(__vector_iterators& obj) { this->it_ptr = obj.it_ptr; return (*this); }
            __vector_iterators& operator+=(ptrdiff_t n) { this->it_ptr += n; return (*this); }
            __vector_iterators& operator-=(ptrdiff_t n) { this->it_ptr -= n; return (*this); }
            bool operator==(__vector_iterators& obj) { return (this->it_ptr == obj.it_ptr ? 1 : 0); }
            bool operator!=(__vector_iterators& obj) { return (this->it_ptr != obj.it_ptr ? 1 : 0); }
            bool operator>(__vector_iterators& obj) { return (this->it_ptr > obj.it_ptr ? 1 : 0); }
            bool operator<(__vector_iterators& obj) { return (this->it_ptr < obj.it_ptr ? 1 : 0); }
            bool operator>=(__vector_iterators& obj) { return (this->it_ptr >= obj.it_ptr ? 1 : 0); }
            bool operator<=(__vector_iterators& obj) { return (this->it_ptr <= obj.it_ptr ? 1 : 0); }

    };
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                     value_type;
            typedef Allocator                                             allocator_type;
            typedef typename allocator_type::pointer                      pointer;
            typedef class __vector_iterators<pointer>                     iterator;
			iterator													  v_ptr;
            vector(){ this->v_ptr.it_ptr = NULL; }
            iterator& begin() { return (this->v_ptr); }

    };
    
};

#endif