/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:28:20 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 01:44:41 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>

class rectangle
{
private:
    
public:
    int32_t x, y, w, h;
    rectangle();
    rectangle(int32_t _x, int32_t _y, int32_t _w, int32_t _h);
    ~rectangle();
};




#endif