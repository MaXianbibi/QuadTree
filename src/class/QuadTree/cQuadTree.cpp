/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cQuadTree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:40:36 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:30:20 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/QuadTree.hpp"

data::data() {}

data::~data() {}

void data::setUpPoints(u_int32_t n)
{
    if (this->points.size())
        this->points.clear();

    this->points.resize(n);
    for(size_t i = 0; i < points.size(); i++)
        points[i] = Point();
}

void QuadTree::drawRect(void)
{
    this->win.drawLine(rect.x, rect.x + rect.w, rect.y, rect.y); // x
    this->win.drawLine(rect.x, rect.x + rect.w, rect.y + rect.h, rect.y + rect.h); // x + h
    this->win.drawLine(rect.x, rect.x, rect.y, rect.y + rect.h); // y
    this->win.drawLine(rect.x + rect.h, rect.x + rect.h, rect.y, rect.y + rect.h); // y

    
    this->win.drawLine(rect.x, rect.x + rect.w, rect.y + (rect.h / 2), rect.y + (rect.h / 2)); // mid x
    this->win.drawLine(rect.x + rect.h / 2, rect.x + rect.h / 2, rect.y, rect.y + rect.h); // mid y
}

void QuadTree::insert(QuadTree **leaf, rectangle rect)
{
    if (this->deepLevel < 6)
    {
        // pt changer la couleur selon le deep lvl
        *leaf = new QuadTree(this->points, rect.x, rect.y, rect.h, this->win);
        (*leaf)->deepLevel = this->deepLevel + 1;
        (*leaf)->algoRec();
    }
}

void QuadTree::insertA(void)
{
    insert(&this->a, rectA());
}

void QuadTree::insertB(void)
{
    insert(&this->b, rectB());
}

void QuadTree::insertC(void)
{
    insert(&this->c, rectC());
}

void QuadTree::insertD(void)
{
    insert(&this->d, rectD());
}

QuadTree::QuadTree(std::vector<Point> &_points, int32_t x, int32_t y, u_int32_t h, Win &_win) : points(_points), rect(x, y, h, h), win(_win)
{
    a = nullptr;
    b = nullptr;
    c = nullptr;
    d = nullptr;
    (void)points;
    this->drawRect();
}

void QuadTree::destroyTree(QuadTree *&tree)
{   
    if (tree->a)
        destroyTree(tree->a);
    if (tree->b)
        destroyTree(tree->b);
    if (tree->c)
        destroyTree(tree->c);
    if (tree->d)
        destroyTree(tree->d);
    delete tree;
    tree = nullptr;
}

QuadTree::~QuadTree() {
    if (this->a)
        destroyTree(this->a);
    if (this->b)
        destroyTree(this->b);
    if (this->c)
        destroyTree(this->c);
    if (this->d)
        destroyTree(this->d);
}

bool QuadTree::checkList(rectangle rect)
{
    for (size_t i = 0; i < this->points.size(); i++)
    {
        if ((points[i].cord.x > rect.x && points[i].cord.x <= rect.x + rect.h) &&
            (points[i].cord.y > rect.y && points[i].cord.y <= rect.y + rect.h))
                return (true);
    }
    return (false);
}

void QuadTree::algoRec(void)
{
    if (checkList(this->rectA()))
        this->insertA();
    if (checkList(this->rectB()))
        this->insertB();
    if (checkList(this->rectC()))
        this->insertC();
    if (checkList(this->rectD()))
        this->insertD();
}

rectangle   QuadTree::rectA(void)
{
    return (rectangle(this->rect.x, this->rect.y, this->rect.h / 2, this->rect.h / 2));
}

rectangle   QuadTree::rectB(void)
{
    return (rectangle(this->rect.x + this->rect.h / 2, this->rect.y, this->rect.h / 2, this->rect.h / 2));
}

rectangle   QuadTree::rectC(void)
{
    return (rectangle(this->rect.x, this->rect.y + this->rect.h / 2, this->rect.h / 2, this->rect.h / 2));
}

rectangle   QuadTree::rectD(void)
{
    return (rectangle(this->rect.x + this->rect.h / 2, this->rect.y + this->rect.h / 2, this->rect.h / 2, this->rect.h / 2));
}