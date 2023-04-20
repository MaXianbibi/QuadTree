/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cQuadTree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:36:17 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:33:35 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CQUADTREE_HPP
#define CQUADTREE_HPP

#include "QuadTree.hpp"
#include "rectangle.hpp"
#include <vector>

class Point;
class Win;

class data
{
private:
    
public:
    std::vector<Point> points;
    data();
    ~data();
    void setUpPoints(u_int32_t n);
};


class QuadTree
{
private:
    std::vector<Point> &points;
    QuadTree    *a;
    QuadTree    *b;
    QuadTree    *c;
    QuadTree    *d;
    rectangle   rect;
    Win         &win;
    void        drawRect(void);
public:
    QuadTree(std::vector<Point> &_points, int32_t x, int32_t y, u_int32_t h, Win &_win);
    ~QuadTree();
    void insert(QuadTree **leaf, rectangle rect);
    u_int16_t   deepLevel;

    void insertA(void);
    void insertB(void);
    void insertC(void);
    void insertD(void);


    rectangle   rectA(void);
    rectangle   rectB(void);
    rectangle   rectC(void);
    rectangle   rectD(void);

    

    void destroyTree(QuadTree *&tree);

    bool checkList(rectangle rect);

    void algoRec(void);

};



    


#endif