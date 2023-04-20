/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:50:18 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:45:17 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/QuadTree.hpp"

Rgen *Point::randomPoint = nullptr;

Point::Point()
{
    if (this->randomPoint == nullptr)
        this->initRgen(DEFAULT_HEIGHT);
    this->cord = randomPoint->genPoints();

}

Point::Point(u_int32_t h)
{
    if (randomPoint == nullptr)
        this->initRgen(h);
    this->cord = randomPoint->genPoints();
}


Point::~Point()
{
    if  (randomPoint)
    {
        delete(randomPoint);
            randomPoint = nullptr;
    }
}

void Point::initRgen(u_int32_t h)
{
    if (randomPoint)
        delete(randomPoint);    
    randomPoint = new Rgen(h);
}

void Point::update(void)
{
    Rgen move(-2, 2);
    for (int i = 0; i < 10; i++)
    {  
        this->cord.x += move.genPoints().x;
        if (this->cord.x >= 500)
            this->cord.x -= 10;
        else if (this->cord.x < 0)
            this->cord.x += 10;

        this->cord.y += move.genPoints().y;
        if (this->cord.y >= 500)
            this->cord.y -= 10;
        else if (this->cord.y < 0)
            this->cord.y += 10;
    }
}