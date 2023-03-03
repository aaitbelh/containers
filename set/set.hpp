/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:47:30 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/03 01:44:41 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef set_HPP
#define set_HPP
#include "../iterators/iterators.hpp"
#include "../utility/utility.hpp"

namespace ft
{

    template< class Key,class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
    class set
    {
        public:
        typedef Key                                     key_type;
        typedef key_type                                 value_type;
        typedef Compare                                 key_compare;
        typedef key_compare                              value_compare;
        typedef Allocator                               allocator_type;
        typedef value_type&                              reference;
        typedef const value_type&                        const_reference;
        typedef typename allocator_type::pointer               pointer;
        typedef typename allocator_type::const_pointer         const_pointer;
        typedef typename allocator_type::size_type             size_type;
        typedef typename allocator_type::difference_type       difference_type;
        typedef  map_iterator<pointer>                          iterator;
        typedef  map_iterator<const_pointer>                    const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        typedef typename Allocator::template rebind<Node<value_type> >::other	node_allocator;
        typedef Node<value_type>                                                Node;
        private:
                node_allocator            __allocNode;
                allocator_type            __alloc;
                Compare                   comp;
                RedBlack_tree<value_type, Key, value_compare, node_allocator, value_type> RB;
        public:
            //--------------------
            // 🄲🄾🄽🅂🅃🅁🅄🄲🄾🅁  |
            //--------------------
            set():RB(__allocNode, comp){}
            explicit set( const Compare& comp,
              const Allocator& alloc = Allocator()):__alloc(alloc), comp(comp), RB(this->__alloc, this->comp)
            { }
            template< class InputIt >
            set( InputIt first, InputIt last,
            const Compare& comp = Compare(),
            const Allocator& alloc = Allocator() ):__alloc(alloc), comp(comp), RB(this->__alloc, this->comp)
            {
                for(;first != last; ++first)
                {
                    insert(*first);
                }
            }
            set( const set& other ):RB(__alloc, this->comp)
            {
                *this = other;
            }

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧

            //--------------------
            // 🄰🅂🅂🄸🄶🄽🄼🄴🄽🅃  |
            //--------------------
            set& operator=(const set& x)
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
            
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧


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
            ft::pair<iterator, bool> insert( const value_type& value )
            {
                Node*new_Node =  RB.allocate_toNode(value);
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
                erase(*position);
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
                
                
                Node *RN = RB.find_theNodeval(k);
                if(RN != RB.NIL)
                {
                    RB.Deletion(RN);
                    return 1;
                }
                return 0;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-----------------
            //   🄵🄸🄽🄳       |
            //-----------------
            
            iterator find( const value_type& key )
            {
                return (iterator(RB.find_theNodeval(key), RB.NIL, RB.root));
            }
            const_iterator find( const value_type& key ) const
            {
                return (iterator(RB.find_theNodeval(key), RB.NIL, RB.root));
            }
            
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            
            //-----------------
            //   🄲🄻🄴🄰🅁     |
            //-----------------
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-----------------
            //   🅂🅆🄰🄿       |
            //-----------------
            void swap (set& x)
            {
                set tmp = x;
                x = *this;
                *this = tmp;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            void clear()
            {
                RB.clear();
            }

            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-----------------
            //   🄲🄾🅄🄽🅃      |
            //-----------------
            size_type count(const Key& key ) const
            {
                if(RB.find_theNodeval(key) != RB.NIL)
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
            //   🄴🄼🄿🅃🅈       |
            //-----------------
            
            bool empty()const
            {
                if(!RB.size()) return 1;
                return 0;
            }
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //------------------------
            //   🄺🄴🅈 🄲🄾🄼🄿🄰🅁🄴   |
            //------------------------

            key_compare key_comp() const
            {
                return key_compare(comp);
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
            //   🅄🄿🄿🄴🅁 🄱🄾🅄🄽🄳      |
            //---------------------------
            iterator upper_bound( const Key& key )
            {
                iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(*it > key)
                        return it;
                }
                return (end());
            }
            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(*it> k)
                        return it;
                }
                return (end());
            }

            
            //✧༝┉┉┉┉┉˚*❋ ❋ ❋ ❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋❋ ❋ ❋*˚┉┉┉┉┉༝✧
            //-------------------------
            //  🄻🄾🅆🄴🅁 🄱🄾🅄🄽🄳     |
            //-------------------------
            
            iterator lower_bound (const key_type& k)
            {
                iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(*it >= k)
                        return it;
                }
                return (end());
            }
            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator it = begin();
                for(;it != end(); ++it)
                {
                    if(*it >= k)
                        return it;
                }
                return (end());
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
            ~set()
            {
                clear();          
            }
    };
    template< class Key, class Compare, class Alloc >
    bool operator==( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
    {
         return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template< class Key, class Compare, class Alloc >
    bool operator!=( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
    {
        return !(lhs == rhs);
    }
    template< class Key, class Compare, class Alloc >
    bool operator<( const ft::set<Key, Compare, Alloc>& lhs,
                const ft::set<Key, Compare, Alloc>& rhs )
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template< class Key, class Compare, class Alloc >
    bool operator<=( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
    {
        return !(rhs < lhs);
    }
    template< class Key, class Compare, class Alloc >
    bool operator>( const ft::set<Key, Compare, Alloc>& lhs,
                const ft::set<Key, Compare, Alloc>& rhs )
    {
        return rhs < lhs;
    }
    template< class Key, class Compare, class Alloc >
    bool operator>=( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
    {
        return !(lhs < rhs);
    }
};
#endif