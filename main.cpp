/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casper <casper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/12/04 06:13:12 by casper           ###   ########.fr       */
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


int main()
{
    std::vector<int> a(4, 8);
    std::vector<int>::iterator it = a.end();
    --it;
    *it = 9;
    std::cout << *it << std::endl;
}


