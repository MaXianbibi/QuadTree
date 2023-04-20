/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:48:56 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 18:39:53 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Win.hpp"
#include "../include/QuadTree.hpp"

int doingnothing(Win &win, void *ptr)
{
    data &Qtree = *static_cast<data *>(ptr);;
    std::vector<Point> mousePos;

    mousePos.resize(1);
    SDL_GetMouseState(&mousePos[0].cord.x, &mousePos[0].cord.y);


    win.clear_color_buffer(0);
    for(size_t i = 0; i < Qtree.points.size(); i++)
    {
        Qtree.points[i].update();  
        win.drawRecrangle(Qtree.points[i].cord.x, Qtree.points[i].cord.y, 2 ,2 ,0xff0000);
    }
    
    
    QuadTree Root(Qtree.points, 0, 1, win.getHeight() - 2, win);
    Root.deepLevel = 0;
    Root.algoRec();

    return (1);    
}

int main ( void )
{
    Win win(500, 500, "QuadTree");
    data Qtree;

    Qtree.setUpPoints(5);
    win.updateFunc = doingnothing;
    win.loop(&Qtree);
    
}