#include "graphics/draw.h"

ResultStatus Draw_Square
    (
    Texture * texture,
    Coord2D pos,
    ColorRGBA color_rgba,
    uint32_t radius
    )
    {
    #define ADJ_RAD ( radius - 1 )

    if( !texture->is_locked ) return STATUS_FAILURE;

    Coord2D rowStartPos = { .x = pos.x - ADJ_RAD, .y = pos.y - ADJ_RAD };
    for( ; rowStartPos.y < pos.y + ADJ_RAD; ++rowStartPos.y ) 
        Texture_WriteRow( texture, rowStartPos, ADJ_RAD * 2 + 1, color_rgba );

    return STATUS_SUCCESS;

    #undef ADJ_RAD
    }
