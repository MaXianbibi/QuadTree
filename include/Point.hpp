/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:49:35 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:39:11 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "QuadTree.hpp"

class Rgen;

class Point
{
private:
    
public:
    static Rgen *randomPoint;
    vector2d cord;
    Point();
    Point(u_int32_t h);
    ~Point();
    void initRgen(u_int32_t h);

    void update(void);

};


#endif