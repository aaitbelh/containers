/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/07 20:01:52 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "vector/vector.hpp"
#include <vector>
#include <sstream>
#include <istream>
#include <map>
#include "map/redblack_tree.hpp"
#include "fancy_tree/src/fancy_tree.hpp"
int main()
{
    RedBlack_tree<int> RBtree;
    RBtree.insert_newval(1);   
    RBtree.insert_newval(2);   
    RBtree.insert_newval(3);
    RBtree.insert_newval(3);
    // std::cout << RBtree.root->value << std::endl;
    fancy_tree<int> tree;
    tree.print_tree(RBtree.root, V_VIEW);
}