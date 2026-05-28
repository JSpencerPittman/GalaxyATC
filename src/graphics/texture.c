#include "graphics/texture.h"

struct TextureInternal
    {
    SDL_Texture * texture;
    uint32_t * pixels;
    int pitch;
    };

Texture * Texture_Create( SDL_Renderer * const renderer, Rect layout )
{
    TextureInternal * internal = (TextureInternal*)malloc(sizeof(TextureInternal));
    internal->texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, layout.w, layout.h );
    internal->pixels = NULL;
    internal->pitch = 0;

    Texture * texture = (Texture*)malloc(sizeof(Texture));
    texture->internal = internal;
    texture->layout = layout;
    texture->is_locked = false;
    return texture;
}

void Texture_Destroy( Texture * const texture )
    {
    SDL_DestroyTexture( texture->internal->texture );
    free( texture->internal );
    free( texture );
    }

void Texture_Lock( Texture * const texture )
    {
    SDL_LockTexture( texture->internal->texture, NULL, (void**)&(texture->internal->pixels), &texture->internal->pitch );
    texture->is_locked = true;
    }

void Texture_Unlock( Texture * texture )
    {
	SDL_UnlockTexture( texture->internal->texture );
    texture->is_locked = false;
    }

void Texture_CopyToRenderingTarget( SDL_Renderer * const renderer, Texture * const texture )
    {
    SDL_Rect tgt = 
        { 
        .x = (int)texture->layout.x,
        .y = (int)texture->layout.y,
        .w = (int)texture->layout.w,
        .h = (int)texture->layout.h
        };

    SDL_RenderCopy(renderer, texture->internal->texture, NULL, &tgt);
    }

ResultStatus Texture_WriteCell( Texture * const texture, Coord2D pos, ColorRGBA color )
    {
    if( !texture->is_locked ) return STATUS_FAILURE;

    uint32_t pixelIdx = texture->layout.w * pos.y + pos.x;
    texture->internal->pixels[pixelIdx] = ColorToUInt32( color );

    return STATUS_SUCCESS;
    }

ResultStatus Texture_WriteRow( Texture * const texture, Coord2D start_pos, uint32_t cnt, ColorRGBA color )
    {
    if( !texture->is_locked ) return STATUS_FAILURE;

    uint32_t startPixelIdx = texture->layout.w * start_pos.y + start_pos.x;
    UTL_FillUInt32( texture->internal->pixels + startPixelIdx, cnt, ColorToUInt32( color ) );

    return STATUS_SUCCESS;
    }

ResultStatus Texture_Fill( Texture * const texture, ColorRGBA color )
    {
    if( !texture->is_locked ) return STATUS_FAILURE;

    UTL_FillUInt32( texture->internal->pixels, texture->layout.w * texture->layout.h, ColorToUInt32( color ) );

    return STATUS_SUCCESS;
    }