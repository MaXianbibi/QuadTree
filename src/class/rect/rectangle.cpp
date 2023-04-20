/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:29:49 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 14:57:23 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/QuadTree.hpp"

rectangle::rectangle() : x(0), y(0), w(0), h(0) {}

rectangle::rectangle(int32_t _x, int32_t _y, int32_t _w, int32_t _h) : x(_x), y(_y), w(_w), h(_h) {}

rectangle::~rectangle() {}
