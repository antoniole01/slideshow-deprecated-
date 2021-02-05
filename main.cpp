
#include "main.h"

void Close();

struct Region
{
	int x, y, w, h;
};

LTexture gimage1;
LTexture gimage2;
LTexture gimage3;
LTexture gimage4;
LTexture gimage5;
LTexture gimage6;
LTexture gimage7;

bool loadMedia()
{
	bool success = true;
	
	if( !gimage1.loadFromFile("../data/images/image1.png")){printf("Failed!\n");success = false;}
	if( !gimage2.loadFromFile("../data/images/image2.png")){printf("Failed!\n");success = false;}
	if( !gimage3.loadFromFile("../data/images/image3.png")){printf("Failed!\n");success = false;}
	if( !gimage4.loadFromFile("../data/images/image4.png")){printf("Failed!\n");success = false;}
	if( !gimage5.loadFromFile("../data/images/image5.png")){printf("Failed!\n");success = false;}
	if( !gimage6.loadFromFile("../data/images/image6.png")){printf("Failed!\n");success = false;}
	if( !gimage7.loadFromFile("../data/images/image7.png")){printf("Failed!\n");success = false;}
	
	return success;
}

int main(int argc, char* args[])
{
	init_Window(300,200,SCREEN_WIDTH,SCREEN_HEIGHT);
	//init_window();
	loadMedia();
	
 	int x = 0;
 	int y = 0;

	int rx = 20;
	int ry = 100;
	Region r = {rx,ry, rx+250,ry+250};
	Region r2 = {0,0,20,20};

	enum {one,two,three};
	static int slideshow = 0;
	
	int clicks = 0;
	while(!running)
	{
		while(POLLEVENT)
		{
			if(QUIT){ exit(0); }
			if(DOWNPRESS){}
			if(UPPRESS)
			{
				if(ESCAPE){ exit(0); }
				if(LEFT)  { slideshow--; }
				if(RIGHT) { slideshow++; }
			}
			if(MOUSEBUTTONUP)
			{
				if(MX(r.x,r.y, r.w,r.h))
				{
					slideshow++;
				}
			}
			if(MOUSEMOTION)
			{
				if(MX(r.x,r.y, r.w,r.h))
				{
					printf("%i %i %i %i\n",r.x,r.y,r.w,r.h);
				}
			}
		}
		
		if(slideshow <= 0){slideshow = 0;}
		if(slideshow >= 7){slideshow = 7;}
		
		SDL_SetRenderDrawColor(renderer,GRAY);
		SDL_RenderClear(renderer);

		drawOutlineRect(renderer, r.x,r.y,r.w,r.h, MAGENTA);
		
		//SLIDESHOW IMAGES
		if(slideshow == 1){gimage1.render(0,0,4,4);}
		if(slideshow == 2){gimage2.render(0,0,4,4);}
		if(slideshow == 3){gimage3.render(0,0,4,4);}
		if(slideshow == 4){gimage4.render(0,0,4,4);}
		if(slideshow == 5){gimage5.render(0,0,4,4);}
		if(slideshow == 6){gimage6.render(0,0,4,4);}
		if(slideshow == 7){gimage7.render(0,0,4,4);}
		printf("%i\n",slideshow);
		
		/**/
		//CONVERSION FROM INT TO CONST CHAR*
		std::stringstream strs;
		strs<<(slideshow);
		std::string str = strs.str();
		const char* cstr = str.c_str();

		//DRAW TEXT "CLICKS : 0" - DRAW TEXT "SLIDES"
		drawFontSolid(gFont,text,solidTexture,solidRect,renderer,2,0,5,890,0,cstr,255,255,255,255,"../data/font/arial.ttf",32);
	   drawFontSolid(gFont,text,solidTexture,solidRect,renderer,2,0,5,960,0,"slide",255,255,255,255,"../data/font/arial.ttf",32);

		Sleep(1000/33);
		SDL_RenderPresent(renderer);
	}
	
	Close();
	return(0);
}

void Close()
{
	gimage1.free();
	gimage2.free();
	gimage3.free();

	IMG_Quit();
	
	destroy_Window();
}
