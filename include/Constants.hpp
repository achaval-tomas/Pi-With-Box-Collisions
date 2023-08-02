#pragma once

#define BIGBOX_INIT_POSX     500
#define SMALLBOX_INIT_POSX   250
#define SMALLBOX_W           50

#define RENDER_STEP          0.015f
#define LEFTWALL_X           110

#define GOLD       			 {255, 202,  24, 255}
#define ROUND_FONT			 "res/fonts/roundedFont.ttf"

#define COLLISION_PARAMS     renderer, ROUND_FONT, 45, std::to_string(collisionCounter) + "  ", GOLD