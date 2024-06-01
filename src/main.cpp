#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>
#include <getopt.h>
using namespace std;




uint32_t my_callbackfunc(uint32_t interval, void *param)
{
    SDL_Event event;
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
    return(interval);
}


int main( int argc, char* argv[] )
{
    uint32_t delay = 2000;
    char img_path [256] = "";
    int window_width=1600, window_height=900;

    const char* optstring = "t:p:w:h:";
    int opt;
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 't': {
            uint32_t millseconds;
            sscanf(optarg, "%u", &millseconds);
            delay = millseconds;
            } break;
        case 'p':
            strcpy(img_path, optarg);
            break; 
        case 'w':
            sscanf(optarg, "%d", &window_width);
            break;
        case 'h':
            sscanf(optarg, "%d", &window_height);
            break;
        default:
            break;
        }
    }



    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }
    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )  {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return 2;
    }

    SDL_Window* window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS  | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI );
    SDL_Surface* screenSurface = SDL_GetWindowSurface( window );


    SDL_Surface* imgSurface = SDL_ConvertSurface(IMG_Load( img_path ), screenSurface->format, 0 );
    //SDL_Surface* imgSurface = IMG_Load( "C:\\Users\\guest_blmsaex\\Desktop\\splash-start\\asset\\splash.png" );
    assert(imgSurface!=NULL);

    SDL_Rect screenRect {0, 0, window_width, window_height};

    SDL_BlitScaled( imgSurface, NULL, screenSurface, &screenRect );

    SDL_UpdateWindowSurface( window );
    
    SDL_TimerID my_timer_id = SDL_AddTimer(delay, my_callbackfunc, NULL);


    bool shouldQuit = false; 
    while(!shouldQuit){ 
        SDL_Event e; 
        while( SDL_PollEvent( &e ) ){ 
            switch (e.type)
            {
            case SDL_QUIT:
                shouldQuit = true; 
                break;
            default:
                break;
            }
        }
    }


    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}