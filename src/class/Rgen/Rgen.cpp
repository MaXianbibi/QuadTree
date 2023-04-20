/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rgen.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:56:25 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:38:56 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/QuadTree.hpp"

vector2d    Rgen::genPoints(void)
{
    vector2d tmp;
    
    tmp.x = dis(gen);
    tmp.y = dis(gen);

    return (tmp);
}

Rgen::Rgen(u_int32_t h) : gen(rd()), max(h), dis(0, max) {}

Rgen::Rgen(int32_t _min, int32_t _max) : gen(rd()), max(_max), dis(_min, max) {}


Rgen::~Rgen()
{
}