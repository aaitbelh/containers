/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:03:56 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/28 22:45:07 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <utility>
#include <memory>
#include <functional>
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
    };
    template <class Key, class T, class Compare, class Alloc>
    class value_compare : public std::binary_function<T, T,bool>
    {
        friend class map;
        protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
        public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };
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
            typedef typename ft::map_iterator<pointer>                              iterator;
            typedef typename ft::reverse_iterartor<iterator>                        reverse_iterator;
            typedef typename ft::map_iterator<const_pointer>                         const_iterator;
            typedef typename ft::reverse_iterartor<const_iterator>                  const_reverse_iterator;
            typedef Node<value_type>                                                Node;
            typedef typename ft::value_compare<value_type, value_type, bool>                          value_compare;
            private :
                node_allocator            __allocNode;
                allocator_type            __alloc;
                Compare                   comp;
            public:
                RedBlack_tree<value_type, Key, Compare ,node_allocator> RB;
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
                iterator tmp(RB.NIL, RB.NIL, RB.root);
                return reverse_iterator(tmp);
            }
            reverse_iterator rend()
            {
                reverse_iterator tmp(begin());
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
                Node* RN = RB.insert_newval(new_Node);
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
                erase(position->first);
            }
            void erase (iterator first, iterator last)
            {
                for(; first != last; ++first)
                    erase(first);
            }
            size_type erase (const key_type& k)
            {
                
                Node *RN = RB.find_theNodeval(k);
                if(RN != RB.NIL)
                {
                    RB.Deletion(RN);
                    return 1;
                }
                return 0;
            }
            mapped_type& operator[] (const key_type& k)
            {
                value_type val(k, mapped_type());
                insert(val);
                return (RB.find_theNodeval(k)->value.second);
            }
            T& at( const Key& key )
            {
                Node* RN = RB.find_theNodeval(key);
                if(RN != RB.NIL)
                    return RN->value.second;
                else
                    throw(std::out_of_range(""));
            }
            const T& at( const Key& key ) const
            {
                Node* RN = RB.find_theNodeval(key);
                if(RN != RB.NIL)
                    return RN->value.second;
                else
                    throw(std::out_of_range(""));
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

            //find---------------
            iterator find( const Key& key )
            {
                return (iterator(RB.find_theNodeval(key), RB.root, RB.NIL));
            }
            const_iterator find( const Key& key ) const
            {
                return (iterator(RB.find_theNodeval(key), RB.root, RB.NIL));
            }
            //-------------------upper_bound
            iterator upper_bound( const Key& key )
            {
                iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(it->first > key)
                        return it;
                }
                return (end());
            }
            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(it->first > k)
                        return it;
                }
                return (end());
            }

            //-------lower_bound
            iterator lower_bound (const key_type& k)
            {
                iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(it->first >= k)
                        return it;
                }
                return (end());
            }
            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(it->first >= k)
                        return it;
                }
                return (end());
            }
            //------equal range------
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                return (pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
            }

            //-----------key_compare--------- 
            key_compare key_comp() const
            {
                return (this->comp);
            }

            void swap (map& x)
            {
                map tmp = x;
                x = *this;
                *this = tmp;
            }
            void clear(){ 
                RB.clear();
            }
            
            ~map()
            {
                clear();
            }
    };
    template <class T> 
    void swap (T& a, T& b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

};

#endif