/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Win.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:51:35 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 16:06:37 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_HPP
# define WIN_HPP

# include   <SDL2/SDL.h>
# include    <iostream>

#include     <cstdint>
#include        <cmath>




# define DEFAULT_HEIGHT  500  
# define DEFAULT_WIDTH   500 
# define DEFAULT_NAME    "Window"

void fatal(std::string msg);
void fatal_SDL(std::string msg);

class Win
{
private:
    SDL_Window      *win;
    SDL_Renderer    *renderer;
    SDL_Texture     *texture;
    u_int32_t       n_pixel;
    u_int32_t       *colorBuffer;
    u_int16_t       w;
    u_int16_t       h;
    u_int8_t        FRAME_RATE;
    bool            is_running;
    void            (Win::*defaultEventFunction)(void);
    void            render(void);
    void            defaultEvent(void);
public:
    Win();
    Win(u_int16_t _w, u_int16_t _h, std::string name);
    ~Win();
    int            (*eventsFunc)(Win &win);
    int            (*updateFunc)(Win &win, void *ptr);
    void           loop(void *ptr);
    void           change_frame_rate(u_int8_t v);
    void           stop_running(void); 
    void           drawPixel(u_int32_t y, u_int32_t x, u_int32_t color);
    void           clear_color_buffer(u_int32_t color);
    void           draw_grid(void);
    void           drawRecrangle(u_int32_t posX, u_int32_t posY, u_int32_t w, u_int32_t h, u_int32_t color);
    u_int16_t      getHeight(void);
    u_int16_t      getWidth(void);
void               drawLine(int32_t start_x, int32_t finish_x, int32_t start_y, int32_t finish_y);
};
#endif