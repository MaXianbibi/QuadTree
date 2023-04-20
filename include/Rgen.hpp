/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rgen.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:55:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:35:03 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGEN_HPP
#define RGEN_HPP

#include "QuadTree.hpp"

#include <random>

class Rgen
{
private:
    std::random_device rd;
    std::mt19937 gen;
    u_int32_t max; 
    std::uniform_int_distribution<> dis;
public:
    Rgen(u_int32_t h);
    Rgen(int32_t min, int32_t max);
    ~Rgen();
    vector2d    genPoints(void);
};


#endif