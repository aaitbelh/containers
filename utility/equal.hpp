/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:55:47 by aaitbelh          #+#    #+#             */
/*   Updated: 2023/03/03 01:14:54 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1,
                InputIt2 first2 )
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!(*first1 == *first2))
                return false;
        return true;
    }
    template< class InputIt1,
          class InputIt2,
          class BinaryPredicate >
    bool equal( InputIt1 first1,
            InputIt1 last1,
            InputIt2 first2,
            BinaryPredicate p )
    {
        for (; first1 != last1; ++first1, ++first2)
            if (!p(*first1, *first2))
                return false; 
            return true;
    }
}
#endif