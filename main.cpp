/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casper <casper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/12/11 10:39:51 by casper           ###   ########.fr       */
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
template< class U, typename = std::enable_if<!std::is_integral<U>::value>>
void f(U val1, U val2)
{
    for(; val1 < val2; val1++)
    {
        std::cout << *val1 << std::endl;
    }
}

int main()
{
    int tab[10] = {1, 2, 3,4, 5,6,7,8,9,10};
    std::vector<int> vec;
    vec.assign(&tab[0], &tab[10]);
    vec.resize(-1);
    std::cout << vec.capacity() << std::endl;
    std::cout << vec.size() << std::endl;
}
