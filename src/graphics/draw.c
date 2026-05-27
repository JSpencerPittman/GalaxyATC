#include "graphics/draw.h"

void Draw_Square
    (
    Texture * texture,
    Coord2D pos,
    ColorRGBA color_rgba,
    uint32_t radius
    )
    {
    #define ADJ_RAD ( radius - 1 )

    Coord2D rowStartPos = { .x = pos.x - ADJ_RAD, .y = pos.y - ADJ_RAD };
    for( ; rowStartPos.y < pos.y + ADJ_RAD; ++rowStartPos.y ) 
        Texture_WriteRow( texture, rowStartPos, ADJ_RAD * 2 + 1, color_rgba );

    #undef ADJ_RAD
    }
