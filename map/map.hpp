/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:03:56 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/19 10:45:22 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        first_type first;
        second_type second;
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
        protected:
            size_t size;
        public:
            typedef Key												key_type;
			typedef T												mapped_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::value_type				value_type;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			
			typedef typename Allocator::template rebind<Node<value_type> >::other	node_allocator;
    }
};

#endif