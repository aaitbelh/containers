/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/02/19 10:51:27 by aaitbelh         ###   ########.fr       */
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
    ft::vector<int> v;
    v.push_back(1);
    ft::vector<int>::iterator it = v.begin();
    std::cout << *it << std::endl;
    
}