/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:03:56 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/03 18:43:41 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_HPP
#define map_HPP
#include <memory>
#include <functional>
#include "redblack_tree.hpp"
#include "../iterators/iterators.hpp"
#include "../utility/utility.hpp"
namespace ft
{
    
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
            typedef typename ft::reverse_iterator<iterator>                        reverse_iterator;
            typedef typename ft::map_iterator<const_pointer>                         const_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                  const_reverse_iterator;
            typedef Node<value_type>                                                Node;
            class value_compare
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
            private :
                node_allocator            __allocNode;
                allocator_type            __alloc;
                Compare                   comp;
                RedBlack_tree<value_type, Key, value_compare, node_allocator, value_type> RB;
            public:
            //--------------------
            // 🄲🄾🄽🅂🅃🅁🅄🄲🄾🅁  |
            //--------------------
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
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //--------------------
            // 🄰🅂🅂🄸🄶🄽🄼🄴🄽🅃  |
            //--------------------
            
            map& operator=(const map& x)
            {
                this->RB.clear();
                insert(x.begin(), x.end());
                return *this;
            }
            

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //--------------------
            // 🄸🅃🄴🅁🄰🅃🄾🅁🅂    |
            //--------------------
            
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
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧

            
            //---------------------------------
            // 🅁🄴🅅🄴🅁🅂🄴 🄸🅃🄴🅁🄰🅃🄾🅁🅂    |
            //---------------------------------
            reverse_iterator rbegin() const
            {
                iterator tmp(RB.NIL, RB.NIL, RB.root);
                return reverse_iterator(tmp);
            }
            reverse_iterator rend()const
            {
                reverse_iterator tmp(begin());
                return tmp;
            }

            
  //        ✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧


            //-----------------
            //   🄸🄽🅂🄴🅁🅃    |
            //-----------------
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for(;first != last; ++first)
                {
                    insert(*first);
                }
            }
            ft::pair<iterator, bool> insert(const value_type& val)
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
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-----------------
            //   🄴🅁🄰🅂🄴     |
            //-----------------

            
            void erase (iterator position)
            {
                erase(position->first);
            }
            void erase (iterator first, iterator last)
            {
                iterator tmp;
                while(first != last)
                {
                    tmp = first;
                    ++first;
                    erase(tmp);
                }
            }
            size_type erase (const key_type& k)
            {
                
                value_type val(k, mapped_type());
                Node *RN = RB.find_theNodeval(val);
                if(RN != RB.NIL)
                {
                    RB.Deletion(RN);
                    return 1;
                }
                return 0;
            }
            
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //------------------------------
            //   🄸🄽🄳🄴🅇 🄾🄿🄴🅁🄰🅃🄾🅁     |
            //------------------------------

            mapped_type& operator[] (const key_type& k)
            {
                value_type val(k, mapped_type());
                insert(val);
                return (RB.find_theNodeval(val)->value.second);
            }

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            
            //----------
            //   🄰🅃   |
            //----------
            T& at( const Key& key )
            {
                value_type val(key, mapped_type());
                Node* RN = RB.find_theNodeval(val);
                if(RN != RB.NIL)
                    return RN->value.second;
                else
                    throw(std::out_of_range(""));
            }
            const T& at( const Key& key ) const
            {
                value_type val(key, mapped_type());
                Node* RN = RB.find_theNodeval(val);
                if(RN != RB.NIL)
                    return RN->value.second;
                else
                    throw(std::out_of_range(""));
            }
            
                        
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            
            //-----------------
            //   🄴🄼🄿🅃🅈       |
            //-----------------
            bool empty()
            {
                if(!RB.size()) return 1;
                return 0;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-----------------
            //   🄲🄾🅄🄽🅃      |
            //-----------------
            size_type count( const Key& key ) const
            {
                value_type val(key, mapped_type());
                if(RB.find_theNodeval(val) != RB.NIL)
                    return 1;
                return 0;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-----------------
            //   🅂🄸🅉🄴       |
            //-----------------
       
            size_type size()const
            {
                return RB.size();
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-----------------
            //   🄵🄸🄽🄳       |
            //-----------------
            iterator find( const Key& key )
            {
                value_type val(key, mapped_type());
                return (iterator(RB.find_theNodeval(val), RB.NIL, RB.root));
            }
            const_iterator find( const Key& key ) const
            {
                value_type val(key, mapped_type());
                return (iterator(RB.find_theNodeval(val), RB.NIL, RB.root));
            }

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧

            //---------------------------
            //   🅄🄿🄿🄴🅁 🄱🄾🅄🄽🄳      |
            //---------------------------
            
            iterator upper_bound( const Key& key )
            {
                Node *tmp = RB.root;
                iterator result = end();
                while(tmp != RB.NIL)
                {
                    if(comp(key, tmp->value.first))
                    {
                        result = iterator(tmp, RB.NIL, RB.root);
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return result;
            }
            const_iterator upper_bound (const key_type& k) const
            {
                Node *tmp = RB.root;
                const_iterator result = end();
                while(tmp != RB.NIL)
                {
                    if(comp(k, tmp->value.first))
                    {
                        result = const_iterator(tmp, RB.NIL, RB.root);
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return result;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-------------------------
            //  🄻🄾🅆🄴🅁 🄱🄾🅄🄽🄳     |
            //-------------------------
            
            iterator lower_bound (const key_type& k)
            {
                Node *tmp = RB.root;
                iterator result = end();
                value_type val(k, mapped_type());
                while(tmp != RB.NIL)
                {
                    if(!value_compare(comp)(tmp->value, val))
                    {
                        result = iterator(tmp, RB.NIL, RB.root);
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return result;
            }
            const_iterator lower_bound (const key_type& k) const
            {
                Node *tmp = RB.root;
                const_iterator result = end();
                value_type val(k, mapped_type());
                while(tmp != RB.NIL)
                {
                    if(!value_compare(comp)(tmp->value, val))
                    {
                        result = const_iterator(tmp, RB.NIL, RB.root);
                        tmp = tmp->left;
                    }
                    else
                        tmp = tmp->right;
                }
                return result;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //------------------------
            //   🄴🅀🅄🄰🄻 🅁🄰🄽🄶🄴   |
            //------------------------
            
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                return (pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //------------------------
            //   🄺🄴🅈 🄲🄾🄼🄿🄰🅁🄴   |
            //------------------------

            key_compare key_comp() const
            {
                return (this->comp);
            }

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-----------------
            //   🅂🅆🄰🄿       |
            //-----------------
            void swap (map& x)
            {
                Compare tmp_comp = x.key_comp();
                x.comp = this->comp;
                this->comp = tmp_comp;
                RB.swap(x.RB);
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-----------------
            //   🄲🄻🄴🄰🅁     |
            //-----------------
            void clear(){ 
                RB.clear();
            }
            
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            
            //---------------------------
            //   🅅🄰🄻🅄🄴 🄲🄾🄼🄿🄰🅁🄴   |
            //---------------------------
            value_compare value_comp() const
            {
                return value_compare(comp);
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //---------------------------
            //   🄶🄴🅃 🄰🄻🄻🄾🄲🄰🅃🄾🅁   |
            //---------------------------
            
            allocator_type get_allocator() const
            {
                return (this->__alloc);
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //--------------------
            //   🄼🄰🅇 🅂🄸🅉🄴    |
            //--------------------
            
            size_type max_size() const { 
                return std::min<size_type>(__alloc.max_size(), std::numeric_limits<difference_type>::max()); 
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-------------------------
            //   🄳🄴🅂🅃🅁🅄🄲🅃🄾🅁     |
            //-------------------------
            ~map()
            {
                clear();
            }
            
    };
    template< class Key, class T, class Compare, class Alloc >
    bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
    {
         return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
    {
        return !(lhs == rhs);
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs )
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
    {
        return !(rhs < lhs);
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs,
                const ft::map<Key, T, Compare, Alloc>& rhs )
    {
        return rhs < lhs;
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
    {
        return !(lhs < rhs);
    }
    template< class Key, class T, class Compare, class Alloc >
    void swap( ft::map<Key, T, Compare, Alloc>& lhs,
           ft::map<Key, T, Compare, Alloc>& rhs )
    {
        lhs.swap(rhs);
    }
};

#endif