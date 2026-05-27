#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdbool.h>
#include <SDL.h>

#include "graphics/types.h"

typedef struct TextureInternal TextureInternal;

typedef struct {
    TextureInternal * internal;
    Size2D size;
    bool is_locked;
} Texture;

Texture * Texture_CreateFullscreen( SDL_Renderer * renderer, Size2D screen_size );
void Texture_Destroy( Texture * texture );
void Texture_Lock( Texture * texture );
void Texture_Unlock( Texture * texture );

void Texture_WritePixel( Texture * texture, Coord2D pos, ColorRGBA color );

#endif