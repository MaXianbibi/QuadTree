/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:17:18 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 12:38:33 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/QuadTree.hpp"

vector2d::vector2d() : x(0), y(0)
{}

vector2d::vector2d(int32_t &&_x, int32_t &&_y) : x(_x), y(_y)
{}

vector2d::~vector2d()
{}

vector2d::vector2d(int32_t &_x, int32_t &_y) : x(_x), y(_y)
{
    
}
