#ifndef _BASE_H
#define _BASE_H

//--- BASIC INCLUDES ---------

#define CHECKED_DELETE(x) if(x) delete x; x=NULL;
#define CHECKED_DELETE_ARRAY(x) if(x) delete [] x; x=NULL;
#define CHECKED_DELETE_SURFACE(x) SDL_FreeSurface(x); x=NULL;
#define CHECKED_DELETE_WINDOW(x) SDL_DestroyWindow(x); x=NULL;
#define CHECKED_DELETE_TEXTURE(x) SDL_DestroyTexture(x); x=NULL;
#define CHECKED_DELETE_RENDERER(x) SDL_DestroyRenderer(x); x=NULL;
#define CHECKED_DELETE_FONT(x) TTF_CloseFont(x); x=NULL;
#define CHECKED_DELETE_SOUND(x) Mix_FreeChunk(x); x=NULL; 
#define CORE CCore::GetSingleton()

#define DEFAULT_WINDOW_NAME "Game"
#define DEFAULT_HRES 640
#define DEFAULT_VRES 480
#define DEFAULT_BACKGROUND ".\\Images\\BackGround.jpg"
#define DEFAULT_IMAGES_PATH ".\\Images\\"
#define DEFAULT_SPRITE_WIDTH 32
#define DEFAULT_SPRITE_HEIGHT 32
#define DEFAULT_FONT_FILE "ARIAL.TTF"

#endif