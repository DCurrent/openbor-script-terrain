#ifndef DC_TERRAIN_CONFIG
#define DC_TERRAIN_CONFIG 1

// Dependencies
#include "data/scripts/dc_target/main.c"

// For positioning switches, each item should be double previous
// items value so we can use bitwise logic.
#define DC_TERRAIN_POSITIONING_ENTITY	1
#define DC_TERRAIN_POSITIONING_OFFSET	2


// Defaults
#define DC_TERRAIN_DEFAULT_INSTANCE			0
#define DC_TERRAIN_DEFAULT_ANIMATION		openborconstant("ANI_IDLE")
#define DC_TERRAIN_DEFAULT_ENT				getlocalvar("self")
#define DC_TERRAIN_DEFAULT_OFFSET_BASE		0
#define DC_TERRAIN_DEFAULT_OFFSET_X			0
#define DC_TERRAIN_DEFAULT_OFFSET_Y			0
#define DC_TERRAIN_DEFAULT_OFFSET_Z			0
#define DC_TERRAIN_DEFAULT_POSITIONING_X	DC_TERRAIN_POSITIONING_ENTITY + DC_TERRAIN_POSITIONING_OFFSET	
#define DC_TERRAIN_DEFAULT_POSITIONING_Y	DC_TERRAIN_POSITIONING_ENTITY + DC_TERRAIN_POSITIONING_OFFSET
#define DC_TERRAIN_DEFAULT_POSITIONING_Z	DC_TERRAIN_POSITIONING_ENTITY + DC_TERRAIN_POSITIONING_OFFSET
#define DC_TERRAIN_DEFAULT_WALL				0

// Variable keys.
#define DC_TERRAIN_VAR_KEY_BASE_ID			"dcterr"	// Base name of every var ID. Must be unique vs. all other libraries.
#define DC_TERRAIN_VAR_KEY_INSTANCE			DC_TERRAIN_VAR_KEY_BASE_ID + 0
#define DC_TERRAIN_VAR_KEY_ANIMATION		DC_TERRAIN_VAR_KEY_BASE_ID + 1
#define DC_TERRAIN_VAR_KEY_ENT				DC_TERRAIN_VAR_KEY_BASE_ID + 2
#define DC_TERRAIN_VAR_KEY_OFFSET_BASE		DC_TERRAIN_VAR_KEY_BASE_ID + 3
#define DC_TERRAIN_VAR_KEY_OFFSET_X			DC_TERRAIN_VAR_KEY_BASE_ID + 4
#define DC_TERRAIN_VAR_KEY_OFFSET_Y			DC_TERRAIN_VAR_KEY_BASE_ID + 5
#define DC_TERRAIN_VAR_KEY_OFFSET_Z			DC_TERRAIN_VAR_KEY_BASE_ID + 6
#define DC_TERRAIN_VAR_KEY_POSITIONING_X	DC_TERRAIN_VAR_KEY_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_POSITIONING_Y	DC_TERRAIN_VAR_KEY_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_POSITIONING_Z	DC_TERRAIN_VAR_KEY_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_WALL				DC_TERRAIN_VAR_KEY_BASE_ID + 8
#define DC_TERRAIN_VAR_KEY_THE_END			9			// Should always last, with a value one higher than previous key ID.

#endif // !DC_TERRAIN_CONFIG
