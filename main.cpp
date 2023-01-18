/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:00:29 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/01/18 10:22:21 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <stack>
#include <typeinfo>
#include <iterator>
#include <limits>
#include "vector.hpp"
#include <algorithm>
#include <iterator>
#include <cmath>
    int _ratio = 10000;



class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};
std::vector<int> assign_test(ft::vector<int> vector) {
    std::vector<int> v;
    ft::vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main()
{
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::reverse_iterator my_rit2(v.end());
    std::cout <<my_rit2[1] << std::endl;

    
}
    
