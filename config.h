#ifndef DC_TERRAIN_CONFIG
#define DC_TERRAIN_CONFIG 1

// Dependencies
#include "data/scripts/dc_target/main.c"

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_TERRAIN_BASE_ID		"dcter"

// For positioning switches, each item should be double previous
// items value so we can use bitwise logic.
#define DC_TERRAIN_ANCHOR_ENTITY	1
#define DC_TERRAIN_ANCHOR_OFFSET	2


// Defaults
#define DC_TERRAIN_DEFAULT_INSTANCE			0
#define DC_TERRAIN_DEFAULT_ANIMATION		openborconstant("ANI_IDLE")
#define DC_TERRAIN_DEFAULT_ENT				getlocalvar("self")
#define DC_TERRAIN_DEFAULT_OFFSET_BASE		0
#define DC_TERRAIN_DEFAULT_OFFSET_X			0
#define DC_TERRAIN_DEFAULT_OFFSET_Y			0
#define DC_TERRAIN_DEFAULT_OFFSET_Z			0
#define DC_TERRAIN_DEFAULT_ANCHOR_X	DC_TERRAIN_ANCHOR_ENTITY + DC_TERRAIN_ANCHOR_OFFSET	
#define DC_TERRAIN_DEFAULT_ANCHOR_Y	DC_TERRAIN_ANCHOR_ENTITY + DC_TERRAIN_ANCHOR_OFFSET
#define DC_TERRAIN_DEFAULT_ANCHOR_Z	DC_TERRAIN_ANCHOR_ENTITY + DC_TERRAIN_ANCHOR_OFFSET
#define DC_TERRAIN_DEFAULT_WALL				0

// Variable keys.
#define DC_TERRAIN_MEMBER_INSTANCE			DC_TERRAIN_BASE_ID + 0
#define DC_TERRAIN_MEMBER_ANIMATION			DC_TERRAIN_BASE_ID + 1
#define DC_TERRAIN_MEMBER_ENT				DC_TERRAIN_BASE_ID + 2
#define DC_TERRAIN_MEMBER_OFFSET_BASE		DC_TERRAIN_BASE_ID + 3
#define DC_TERRAIN_MEMBER_OFFSET_X			DC_TERRAIN_BASE_ID + 4
#define DC_TERRAIN_MEMBER_OFFSET_Y			DC_TERRAIN_BASE_ID + 5
#define DC_TERRAIN_MEMBER_OFFSET_Z			DC_TERRAIN_BASE_ID + 6
#define DC_TERRAIN_MEMBER_ANCHOR_X	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_MEMBER_ANCHOR_Y	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_MEMBER_ANCHOR_Z	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_MEMBER_WALL				DC_TERRAIN_BASE_ID + 8
#define DC_TERRAIN_MEMBER_THE_END			9			// Should always last, with a value one higher than previous key ID.

#endif // !DC_TERRAIN_CONFIG
