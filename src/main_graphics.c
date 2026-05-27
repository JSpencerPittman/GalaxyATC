#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <SDL.h>

#include "graphics/draw.h"
#include "graphics/texture.h"

static Size2D s_screen_size = { .w = 800, .h = 600 };

static void DrawSquareUsingTexture
	(
	SDL_Renderer * renderer
	) 
	{
    const ColorRGBA white = { 0xFF, 0xFF, 0xFF, 0xFF };
    const ColorRGBA red = { 0xFF, 0x00, 0x00, 0xFF };
    Texture * texture;
    Coord2D pos;

    texture = Texture_CreateFullscreen( renderer, s_screen_size );
    Texture_Lock( texture );
    
    pos.x = 0;
    for( uint32_t r = 0; r < s_screen_size.h/2; ++r )
        {
        pos.y = r;
        Texture_WriteRow( texture, pos, s_screen_size.w, white );
        }

    Coord2D sqPos = { .x = 20, .y = 20 };
    Draw_Square( texture, sqPos, red, 5 );

    Texture_Unlock( texture );
    Texture_Destroy( texture );
	}

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initialized!\n"
               "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Window *window = SDL_CreateWindow("Basic C SDL project",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          s_screen_size.w, s_screen_size.h,
                                          SDL_WINDOW_SHOWN);
    if(!window)
    {
        printf("Window could not be created!\n"
               "SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(!renderer)
        {
            printf("Renderer could not be created!\n"
                   "SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            bool quit = false;
            while(!quit)
            {
                SDL_Event e;

                SDL_WaitEvent(&e);

                if(e.type == SDL_QUIT)
                {
                    quit = true;
                }

                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
                SDL_RenderClear(renderer);

				DrawSquareUsingTexture(renderer);

                SDL_RenderPresent(renderer);
            }

            SDL_DestroyRenderer(renderer);
        }

        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    return 0;
}