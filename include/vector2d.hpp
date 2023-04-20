/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:16:13 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 12:37:18 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_HPP
# define VECTOR2D_HPP

#include "QuadTree.hpp"

#include <cstdint>

class vector2d
{
private:
  
public:
    int32_t x, y;
    vector2d();
    vector2d(int32_t &&_x, int32_t &&_y);
    vector2d(int32_t &_x, int32_t &_y);
    ~vector2d();
};

#endif