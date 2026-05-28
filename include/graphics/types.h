#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/*-------------------------------------
Types
-------------------------------------*/

typedef struct
    {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    } ColorRGBA;


typedef struct
    {
    uint32_t x;
    uint32_t y;
    } Coord2D;

typedef struct
    {
    uint32_t w;
    uint32_t h;
    } Size2D;

typedef union
    {
    struct
        {
        uint32_t x;
        uint32_t y;
        uint32_t w;
        uint32_t h;
        };
    struct 
        {
        Coord2D pos;
        Size2D size;
        };
    } Rect;


/*-------------------------------------
Colors
-------------------------------------*/

static inline uint32_t ColorToUInt32( ColorRGBA color )
    {
    return (((uint32_t)color.r) << 24) + (((uint32_t)color.g) << 16) + (((uint32_t)color.b) << 8) + ((uint32_t)color.a);
    }

static const ColorRGBA COLOR_WHITE = { .r = 0xFF, .g = 0xFF, .b = 0xFF, .a = 0xFF };
static const ColorRGBA COLOR_RED = { .r = 0xFF, .g = 0x00, .b = 0x00, .a = 0xFF };
static const ColorRGBA COLOR_GREEN = { .r = 0x00, .g = 0xFF, .b = 0x00, .a = 0xFF };
static const ColorRGBA COLOR_BLUE = { .r = 0x00, .g = 0x00, .b = 0xFF, .a = 0xFF };

#endif