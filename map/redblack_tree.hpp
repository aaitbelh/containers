/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblack_tree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:03:45 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/03 01:44:41 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_TREE_HPP
#define REDBLACK_TREE_HPP
#define BLACK 1
#define REDCOLOR 0
#include <iostream>
#include <memory>
#include <utility>
#include "../utility/pair.hpp"
template <class T>
class Node
{
    public:
    Node *left;
    Node *right;
    Node *parent;
    T value;
    bool color; //zero for red, one for black
    Node(const T& value) : value(value)
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        this->color = REDCOLOR;
    }
    Node(): value()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        this->color = REDCOLOR;
    }
    Node(const Node& Other):value(Other.value)
    {
        *this = Other;
    }
    Node& operator=(const Node &Other)
    {
        this->left = Other.left;
        this->right =  Other.right;
        this->parent  = Other.parent;
        this->color = Other.color;
        return *this;
    }
    ~Node(){}
};
template <class T, class Key , class Compare, class Allocator, class value_type>
class RedBlack_tree
{
    private:
        size_t __size;
        Allocator alloc;
        Compare comp;
    public:
        Node<T> *NIL;
        Node<T> *root;
        RedBlack_tree(const Allocator& alloc, const Compare& comp = std::less<T>()): alloc(alloc), comp(comp), NIL(this->alloc.allocate(1)) {
            this->alloc.construct(NIL, Node<T>());
            NIL->color = BLACK;
            NIL->right = NULL;
            NIL->left = NULL;
            root = NIL;
            __size = 0;
        }

        size_t size() const
        {
            return this->__size;
        }
        void left_rotation(Node<T>* x)
        {
            Node<T> *y = x->right;
            x->right = y->left;
            if(y->left != NIL)
                y->left->parent = x;
            y->parent = x->parent;
            if(x->parent == NIL)
                root = y;
            else if(x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
        void right_rotation(Node<T>* x)
        {
            Node<T> *y = x->left;
            x->left = y->right;
            if(y->right != NIL)
                y->right->parent = x;
            y->parent = x->parent;
            if(x->parent == NIL)
                root = y;
            else if(x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        }
        void insert_fixup(Node<T> *new_node)
        {
            while (new_node->parent->color == REDCOLOR)
            {
                if (new_node->parent == new_node->parent->parent->left)
                {
                    Node<T> *y = new_node->parent->parent->right;
                    if (y->color == REDCOLOR)
                    {
                        new_node->parent->color = BLACK;
                        y->color = BLACK;
                        new_node->parent->parent->color = REDCOLOR;
                        new_node = new_node->parent->parent;
                    }
                    else
                    {
                        if (new_node == new_node->parent->right)
                        {
                            new_node = new_node->parent;
                            left_rotation(new_node);
                        }
                        new_node->parent->color = BLACK;
                        new_node->parent->parent->color = REDCOLOR;
                        right_rotation(new_node->parent->parent);
                    }
                }
                else
                {
                    Node<T> *y = new_node->parent->parent->left;
                    if (y->color == REDCOLOR)
                    {
                        new_node->parent->color = BLACK;
                        y->color = BLACK;
                        new_node->parent->parent->color = REDCOLOR;
                        new_node = new_node->parent->parent;
                    }
                    else
                    {
                        if (new_node == new_node->parent->left)
                        {
                            new_node = new_node->parent;
                            right_rotation(new_node);
                        }
                        new_node->parent->color = BLACK;
                        new_node->parent->parent->color = REDCOLOR;
                        left_rotation(new_node->parent->parent);
                    }
                }
            }
            root->color = BLACK;
        }
        Node<T>* insert_newval(Node<T>* new_node)
        {
            if(!__size)
            {
                root = new_node;
                root->color = 1;
                __size++;
                NIL->parent = this->Maximum(root);
                return new_node;
            }
            Node<T> *temp = root;
            while(temp != NIL)
            {

                if(comp(new_node->value, temp->value))
                {
                    if(temp->left == NIL)
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        break;
                    }
                    temp = temp->left;
                }
                else if(comp(temp->value, new_node->value))
                {
                    if(temp->right == NIL)
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        break;
                    }
                    temp = temp->right;
                }
                else
                    return temp;
            }
            insert_fixup(new_node);
            this->__size++;
            NIL->parent = this->Maximum(root);
            return new_node;
        }
        Node<T> *Minimum(Node<T> *x) const 
        {
            while(x != NIL && x->left != NIL)
            {
                x = x->left;
            }
            return x;
        }
        Node<T> *Maximum(Node<T> *x) const 
        {
            while(x != NIL && x->right != NIL)
            {
                x = x->right;
            }
            return x;
        }
        void transplant(Node<T> *u, Node<T> *v)
        {
            if(u->parent == NIL)
                root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        Node<T> *find_theNodeval(const value_type& k)const
        {
            Node<T>* tmp = root;
            while(tmp != NIL)
            {
                if(comp(k, tmp->value))
                    tmp = tmp->left;
                else if(comp(tmp->value, k))
                    tmp = tmp->right;
                else
                    return tmp;
            }
            return NIL;
        }
        
        void delete_fixup(Node<T> *x)
        {
            while(x != root && x->color == BLACK) {
                if(x == x->parent->left) {
                    Node<T> *w = x->parent->right;
                    if(w->color == REDCOLOR) {
                        w->color = BLACK;
                        x->parent->color = REDCOLOR;
                        left_rotation(x->parent);
                        w = x->parent->right;
                    }
                    if(w->left->color == BLACK && w->right->color == BLACK) {
                        w->color = REDCOLOR;
                        x = x->parent;
                    }
                    else {
                        if(w->right->color == BLACK) {
                            w->left->color = BLACK;
                            w->color = REDCOLOR;
                            right_rotation(w);
                            w = x->parent->right;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        left_rotation(x->parent);
                        x = root;
                    }
                }
                else {
                    Node<T> *w = x->parent->left;
                    if(w->color == REDCOLOR) {
                        w->color = BLACK;
                        x->parent->color = REDCOLOR;
                        right_rotation(x->parent);
                        w = x->parent->left;
                    }
                    if(w->right->color == BLACK && w->left->color == BLACK) {
                        w->color = REDCOLOR;
                        x = x->parent;
                    }
                    else {
                        if(w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = REDCOLOR;
                            left_rotation(w);
                            w = x->parent->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        right_rotation(x->parent);
                        x = root;
                    }
                }
                }
                x->color = BLACK;
        }
        void Deletion(Node<T> *nodeToDelete)
        {
            Node<T> *y = nodeToDelete;
            Node<T> *x = y;
            if(y == NIL)
                return ;
            int y_original_color = y->color;
            if(y->left == NIL)
            {
                x = y->right;
                transplant(y, y->right);
            }
            else if(y->right == NIL)
            {
                x = y->left;
                transplant(y, y->left);
            }
            else
            {
                y = Minimum(y->right);
                y_original_color = y->color;
                x = y->right;
                if(y->parent == nodeToDelete)
                    x->parent = y;
                else
                {
                    transplant(y, y->right);
                    y->right = nodeToDelete->right;
                    y->right->parent = y;
                }
                transplant(nodeToDelete, y);
                y->left = nodeToDelete->left;
                y->left->parent = y;
                y->color = nodeToDelete->color;
            }
            if(y_original_color == BLACK)
                delete_fixup(x);
            alloc.destroy(nodeToDelete);
            alloc.deallocate(nodeToDelete,1);
            NIL->parent = this->Maximum(root);
            this->__size--;
            
        }
        void free_tree(Node<T> * node){
            if (node != NIL) {
                free_tree(node->right);
                free_tree(node->left);
                alloc.destroy(node);
                alloc.deallocate(node, 1);
            }
        }
        Node<T>* upper_bound(const Key& key) const
        {
            Node<T>* tmp = root;
            while(tmp != NIL)
            {
                if(comp(key, tmp->value))
                    return tmp;
                else
                    tmp = tmp->right;
            }
            return NIL;
        }
        void clear()
        {
            free_tree(this->root);
            root = NIL;
            this->__size = 0;
        }
        void setSize(size_t n)
        {
            this->__size = n;
        }
        Node<T>*  allocate_toNode(const value_type& val)
        {
            Node<T> *new_Node = alloc.allocate(1);
            alloc.construct(new_Node, val);
            new_Node->left = NIL;
            new_Node->right = NIL;
            new_Node->parent = NIL;
            return new_Node;
        }
        ~RedBlack_tree()
        {
            alloc.destroy(NIL);
            alloc.deallocate(NIL, 1);
        }
};
#endif
