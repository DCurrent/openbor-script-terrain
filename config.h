#ifndef DC_TERRAIN_CONFIG
#define DC_TERRAIN_CONFIG 1

// Dependencies
#include "data/scripts/dc_instance/main.c"
#include "data/scripts/dc_target/main.c"

// Name of library. Used mainly as a base for variable IDs. Must
// be unique vs all other libraries. Try to keep it short.
#define DC_TERRAIN_BASE_ID			"dcterr"

// For positioning switches, each item should be double previous
// items value so we can use bitwise logic.
#define DC_TERRAIN_POSITION_STATE_ENTITY	1
#define DC_TERRAIN_POSITION_STATE_OFFSET	2


// Defaults
#define DC_TERRAIN_DEFAULT_ANIMATION		openborconstant("ANI_IDLE")
#define DC_TERRAIN_DEFAULT_ENT				getlocalvar("self")
#define DC_TERRAIN_DEFAULT_OFFSET_BASE		0
#define DC_TERRAIN_DEFAULT_OFFSET_X			0
#define DC_TERRAIN_DEFAULT_OFFSET_Y			0
#define DC_TERRAIN_DEFAULT_OFFSET_Z			0
#define DC_TERRAIN_DEFAULT_POSITION_STATE_X	DC_TERRAIN_POSITION_STATE_ENTITY + DC_TERRAIN_POSITION_STATE_OFFSET	
#define DC_TERRAIN_DEFAULT_POSITION_STATE_Y	DC_TERRAIN_POSITION_STATE_ENTITY + DC_TERRAIN_POSITION_STATE_OFFSET
#define DC_TERRAIN_DEFAULT_POSITION_STATE_Z	DC_TERRAIN_POSITION_STATE_ENTITY + DC_TERRAIN_POSITION_STATE_OFFSET
#define DC_TERRAIN_DEFAULT_WALL				0

// Variable keys.
#define DC_TERRAIN_VAR_KEY_INSTANCE			DC_TERRAIN_BASE_ID + 0
#define DC_TERRAIN_VAR_KEY_ANIMATION		DC_TERRAIN_BASE_ID + 1
#define DC_TERRAIN_VAR_KEY_ENT				DC_TERRAIN_BASE_ID + 2
#define DC_TERRAIN_VAR_KEY_OFFSET_BASE		DC_TERRAIN_BASE_ID + 3
#define DC_TERRAIN_VAR_KEY_OFFSET_X			DC_TERRAIN_BASE_ID + 4
#define DC_TERRAIN_VAR_KEY_OFFSET_Y			DC_TERRAIN_BASE_ID + 5
#define DC_TERRAIN_VAR_KEY_OFFSET_Z			DC_TERRAIN_BASE_ID + 6
#define DC_TERRAIN_VAR_KEY_POSITION_STATE_X	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_POSITION_STATE_Y	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_POSITION_STATE_Z	DC_TERRAIN_BASE_ID + 7
#define DC_TERRAIN_VAR_KEY_WALL				DC_TERRAIN_BASE_ID + 8
#define DC_TERRAIN_VAR_KEY_THE_END			9			// Should always last, with a value one higher than previous key ID.

// Instance control. 
#define dc_terrain_get_instance()		dc_instance_get(DC_TERRAIN_VAR_KEY_INSTANCE)
#define dc_terrain_set_instance(value)	dc_instance_set(DC_TERRAIN_VAR_KEY_INSTANCE, value)
#define dc_terrain_reset_instance()		dc_instance_reset(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)
#define dc_terrain_free_instance()		dc_instance_free(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)
#define dc_terrain_dump_instance()		dc_instance_dump(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)
#define dc_terrain_export_instance()	dc_instance_export(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)
#define dc_terrain_import_instance()	dc_instance_import(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)
#define dc_terrain_free_export()		dc_instance_free_export(DC_TERRAIN_BASE_ID, DC_TERRAIN_VAR_KEY_INSTANCE, DC_TERRAIN_VAR_KEY_THE_END)

#endif // !DC_TERRAIN_CONFIG
