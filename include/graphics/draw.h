#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

#include "graphics/texture.h"
#include "utility.h"

ResultStatus Draw_Square
    (
    Texture * texture,
    Coord2D pos,
    ColorRGBA color_rgba,
    uint32_t radius
    );

#endif