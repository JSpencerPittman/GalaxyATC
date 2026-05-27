#include "graphics/texture.h"

struct TextureInternal
    {
    SDL_Texture * texture;
    void * pixels;
    int pitch;
    };

Texture * Texture_CreateFullscreen( SDL_Renderer * renderer, Size2D screen_size )
{
    TextureInternal * internal = (TextureInternal*)malloc(sizeof(TextureInternal));
    internal->texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, screen_size.w, screen_size.h );
    internal->pixels = NULL;
    internal->pitch = 0;

    Texture * texture = (Texture*)malloc(sizeof(Texture));
    texture->internal = internal;
    texture->size = screen_size;
    texture->is_locked = false;
    return texture;
}

void Texture_Destroy( Texture * texture )
    {
    SDL_DestroyTexture( texture->internal->texture );
    free( texture->internal );
    free( texture );
    }

void Texture_Lock( Texture * texture )
    {
    SDL_LockTexture( texture->internal->texture, NULL, &texture->internal->pixels, &texture->internal->pitch );
    texture->is_locked = true;
    }

void Texture_Unlock( Texture * texture )
    {
	SDL_UnlockTexture( texture->internal->texture );
    texture->is_locked = false;
    }

void Texture_WritePixel( Texture * texture, Coord2D pos, ColorRGBA color )
    {
    // TODO: Verify is locked
    uint32_t pixelIdx = texture->size.w * pos.y + pos.x;
    memcpy(&(((uint32_t*)texture->internal->pixels)[pixelIdx]), &color, sizeof(uint32_t));
    }
