#ifndef MAIN_H
#define MAIN_H

#include "pch.h"

#undef main

SDL_Window*		window = NULL;
SDL_Renderer*	renderer = NULL;
SDL_Texture*	solidTexture;
SDL_Texture*	text;
SDL_Rect			solidRect;
TTF_Font*		gFont = NULL;

SDL_Event e;

const int SCREEN_WIDTH	= 480*2;
const int SCREEN_HEIGHT	= 300*2;

bool running = false;

#endif // MAIN_H
//720 450 - 480 300
