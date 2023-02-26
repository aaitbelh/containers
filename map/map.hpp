/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:03:56 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/26 16:15:37 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <utility>
#include <memory>
#include "redblack_tree.hpp"
#include "../iterators/iterators.hpp"
namespace ft
{

    template<class T1,class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair():first(T1()),second(T2()) {}
        pair(const T1& a, const T2& b):first(a), second(b) {}
        template<class U, class V>
        pair(const pair<U,V>& pr):first(pr.first),second(pr.second) {}
        pair& operator=(const pair& pr)
        { first = pr.first; second = pr.second; return *this; }
    };
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
      return ( pair<T1,T2>(x,y) );
    }
    template <class Key, class T, class Compare = std::less<Key>,
                       class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
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
            typedef map_iterator<pointer>                           iterator;
            typedef reverse_it_map<iterator>                        reverse_iterator;
            typedef map_iterator<const_pointer>                     const_iterator;
            typedef reverse_it_map<const_iterator>                  const_reverse_iterator;
            typedef Node<value_type>                                Node;
            private :
                node_allocator            __allocNode;
                allocator_type            __alloc;
                Compare                   comp;
                RedBlack_tree<value_type, Key, Compare ,node_allocator> RB;
            public:
            map():RB(__allocNode, comp){}
            explicit map( const Compare& comps,
              const Allocator& alloc = Allocator() ):__alloc(alloc), comp(comps), RB(__alloc, comps)
              {
                
              }
            template <class InputIterator>  map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()):__alloc(alloc), comp(comp), RB(__alloc, this->comp)
            {
                for(;first != last; ++first)
                {
                    insert(*first);
                }
            }
            map(const map& x):RB(__alloc, this->comp)
            {
                *this = x;
            }
            map& operator=(const map& x)
            {
                this->RB.clear();
                insert(x.begin(), x.end());
                return *this;
            }
            iterator begin() const
            {
                iterator tmp(RB.Minimum(RB.root), RB.NIL, RB.root);
                return (tmp);
            }
            iterator end() const
            {
                iterator tmp(RB.NIL, RB.NIL, RB.root);
                return tmp;
            }
            reverse_iterator rbegin() const
            {
                reverse_iterator tmp(RB.Maximum(RB.root), RB.NIL, RB.root);
                return tmp;
            }
            reverse_iterator rend()
            {
                reverse_iterator tmp(RB.NIL, RB.NIL, RB.root);
                return tmp;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for(;first != last; ++first)
                {
                    insert(*first);
                }
            }
            pair<iterator,bool> insert(const value_type& val)
            {
                Node *new_Node = __allocNode.allocate(1);
                __allocNode.construct(new_Node, val);
                new_Node->left = RB.NIL;
                new_Node->right = RB.NIL;
                new_Node->parent = RB.NIL;
                bool rv = true;
                Node* RN = RB.NIL;
                RN = RB.insert_newval(new_Node);
                if(RN != new_Node)
                    rv = 0;
                if(!rv)
                {
                    __allocNode.destroy(new_Node);
                    __allocNode.deallocate(new_Node, 1);
                }
                iterator it(RN, RB.NIL, RB.root);
                return (ft::pair<iterator, bool>(it, rv));
            }
            iterator insert(iterator position, const value_type& val)
            {
                (void)position;
                return (insert(val).first);
            }


            void erase (iterator position)
            {
                RB.Deletion(RB.find_theNodeval(position->first));
            }            
            size_type erase (const key_type& k)
            {
                RB.Deletion(RB.find_theNodeval(k));
                return 1;
            }
            bool empty()
            {
                if(!RB.size()) return 1;
                return 0;
            }
            size_type count( const Key& key ) const
            {
                if(RB.find_theNodeval(key) != RB.NIL)
                    return 1;
                return 0;
            }
            size_type size()
            {
                return RB.size();
            }
            void clear(){ while(RB.size()) { RB.Deletion(RB.Minimum(RB.root)); } }
            ~map()
            {
                clear();
            }
    };
};

#endif