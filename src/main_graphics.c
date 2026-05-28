#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <SDL.h>
#include <SDL_ttf.h>

#include "graphics/draw.h"
#include "graphics/texture.h"

static Size2D s_screen_size = { .w = 800, .h = 600 };

static void DrawText
    (
    SDL_Renderer * renderer
    )
    {
    TTF_Font* Sans = TTF_OpenFont("resources/fonts/Debrosee-ALPnL.ttf", 24);
    SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = 0;
    Message_rect.y = 0; 
    Message_rect.w = 200;
    Message_rect.h = 100; 
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    SDL_RenderPresent(renderer);
    }

static void DrawSquareUsingTexture
	(
	SDL_Renderer * renderer
	) 
	{
    Texture * texture;
    Coord2D pos;

    /*----------------------- 
    Left
    -----------------------*/

    const Rect layout_left = { .x = 0, .y = 0, .w = s_screen_size.w/2, .h=s_screen_size.h };

    texture = Texture_Create( renderer, layout_left );
    Texture_Lock( texture );
    
    Texture_Fill( texture, COLOR_BLUE );

    Texture_Unlock( texture );

    Texture_CopyToRenderingTarget( renderer, texture );

    Texture_Destroy( texture );

    /*----------------------- 
    Right
    -----------------------*/

    const Rect layout_right = { .x = s_screen_size.w/2, .y = 0, .w = s_screen_size.w/2, .h=s_screen_size.h };

    texture = Texture_Create( renderer, layout_right );
    Texture_Lock( texture );
    
    Texture_Fill( texture, COLOR_GREEN );

    Texture_Unlock( texture );

    Texture_CopyToRenderingTarget( renderer, texture );

    Texture_Destroy( texture );
    
    SDL_RenderPresent(renderer);

	}

int main()
{
    if(TTF_Init() < 0)
        {
        printf("SDL TTL could not be initialized!\n"
               "SDL_ERROR: %s\n", SDL_GetError());
        return 0;
        }

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initialized!\n"
               "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_Window *window = SDL_CreateWindow("GalaxyATC",
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
        SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
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

				// DrawSquareUsingTexture(renderer);
                DrawText(renderer);
            }

            SDL_DestroyRenderer(renderer);
        }

        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    return 0;
}