/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/01/10 21:03:06 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <memory>
#include <stack>
#include <typeinfo>
#include <iterator>
#include <limits>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <cmath>


template <class T>
class X
{
    public:
    X():a(NULL){}
    T a;
};

int main()
{
    ft::vector<std::string> v(1, "DG");
    v.assign(64, "vector-string");
    std::cout << v.size() << std::endl;
    for(size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl;
}