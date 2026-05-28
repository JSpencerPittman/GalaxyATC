#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdbool.h>
#include <SDL.h>

#include "graphics/types.h"
#include "utility.h"

typedef struct TextureInternal TextureInternal;

typedef struct {
    TextureInternal * internal;
    Rect layout;
    bool is_locked;
} Texture;

Texture * Texture_Create( SDL_Renderer * const renderer, Rect layout );
void Texture_Destroy( Texture * const texture );
void Texture_Lock( Texture * const texture );
void Texture_Unlock( Texture * const texture );
void Texture_CopyToRenderingTarget( SDL_Renderer * const renderer, Texture * const texture );

ResultStatus Texture_WriteCell( Texture * const texture, Coord2D pos, ColorRGBA color );
ResultStatus Texture_WriteRow( Texture * const texture, Coord2D start_pos, uint32_t cnt, ColorRGBA color );
ResultStatus Texture_Fill( Texture * const texture, ColorRGBA color );

#endif