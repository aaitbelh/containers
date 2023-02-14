#ifndef REDBLACK_TREE_HPP
#define REDBLACK_TREE_HPP
#define BLACK 1
#define RED 0

#include <iostream>
#include <memory>
#include <utility>
#define REDC "\033[1;31m"
#define RESET "\033[0m"
template<class T>
struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    T value;
    bool color; //zero for red, one for black
};
template <class T, class Allocator = std::allocator<Node<T> > >
class RedBlack_tree
{
    private:
        size_t size;
        Allocator alloc;
    public:
        Node<T> *NIL;
        Node<T> *root;
        RedBlack_tree() {
            NIL = alloc.allocate(1);
            NIL->value = 0;
            NIL->color = BLACK;
            NIL->right = nullptr;
            NIL->left = nullptr;
            root = NIL;
            size = 0;
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
            while (new_node->parent->color == RED)
            {
                if (new_node->parent == new_node->parent->parent->left)
                {
                    Node<T> *y = new_node->parent->parent->right;
                    if (y->color == RED)
                    {
                        new_node->parent->color = BLACK;
                        y->color = BLACK;
                        new_node->parent->parent->color = RED;
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
                        new_node->parent->parent->color = RED;
                        right_rotation(new_node->parent->parent);
                    }
                }
                else
                {
                    Node<T> *y = new_node->parent->parent->left;
                    if (y->color == RED)
                    {
                        new_node->parent->color = BLACK;
                        y->color = BLACK;
                        new_node->parent->parent->color = RED;
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
                        new_node->parent->parent->color = RED;
                        left_rotation(new_node->parent->parent);
                    }
                }
            }
            root->color = BLACK;
        }
        void insert_newval(const T& value)
        {
            Node<T> *new_node;
            new_node = alloc.allocate(1);
            new_node->value = value;
            new_node->left = NIL;
            new_node->right = NIL;
            new_node->color = RED;
            if(root == NIL)
            {
                root = new_node;
                root->color = 1;
                root->parent = NIL;
                return;
            }
            Node<T> *temp = root;
            while(temp != NIL)
            {
                if(temp->value == value)
                {
                    alloc.destroy(new_node);
                    alloc.deallocate(new_node, 1);
                    return ;
                }
                if(temp->value > value)
                {
                    if(temp->left == NIL)
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                        break;
                    }
                    temp = temp->left;
                }
                else
                {
                    if(temp->right == NIL)
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                        break;
                    }
                    temp = temp->right;
                }
            }
            insert_fixup(new_node);
            this->size++;
        }
        Node<T> *Minimum()
        {
            Node<T> *tmp = root;
            while(tmp->left != NIL);
                tmp = tmp->left;
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
        Node<T> *find_theNodeval(const T& value)
        {
            Node<T>* tmp = root;
            while(tmp != NIL)
            {
                if(tmp->value == value)
                    return tmp;
                if(val > tmp->value)
                    tmp = tmp->right;
                else
                    tmp = tmp->left;
            }
            return NIL;
        }
        void delete_fixup(Node<T> * x)
        void Deletion(const T& value)
        {
            Node<T> *y = find_theNodeval();
            if(y == NIL)
                return ;
            int color, y_original_color = y->color;
            if(y->left == NIL)
            {
                transplant(z, z->right)
            }
            else if(y->right == NIL)
            {
                transplant(z, z->left);
            }
            else
            {
                y = Minimum(y->right);
                y_original_color = y->color;
                x = y->right;
                if(y->parent == z)
                    x->parent = y;
                else
                {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            if(y_original_color == BLACK)
                delete_fixup(x);
        }
        ~RedBlack_tree()
        {
            if(root != NIL)
                alloc.deallocate(root, size);
        }
};
#endif
