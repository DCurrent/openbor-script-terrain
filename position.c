#include "data/scripts/dc_terrain/config.h"

#import "data/scripts/dc_terrain/entity.c"
#import "data/scripts/dc_terrain/offset.c"

// Access and mutators.

int dc_terrain_get_positioning_x()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_X;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITION_STATE_X;
	}

	return result;
}

void dc_terrain_set_positioning_x(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_X;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITION_STATE_X)
	{
		value = NULL();
	}
	
	setlocalvar(id, value);	
}

int dc_terrain_get_positioning_y()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_Y;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITION_STATE_Y;
	}

	return result;
}

void dc_terrain_set_positioning_y(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_Y;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITION_STATE_Y)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

int dc_terrain_get_positioning_z()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_Z;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITION_STATE_Z;
	}

	return result;
}

void dc_terrain_set_positioning_z(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_POSITION_STATE_Z;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITION_STATE_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Operations.

// Caskey, Damon V.
// 2018-12-05
//
// Get X position based on user settings and
// acting entity location.
float dc_terrain_find_final_position_x()
{
	float result;
	void ent;
	int positioning;

	// get positioning setting.
	positioning = dc_terrain_get_positioning_x();

	// Start with 0 value.
	result = 0.0;

	// Use entity position?
	if (positioning & DC_TERRAIN_POSITION_STATE_ENTITY)
	{
		ent = dc_terrain_get_entity();

		result += getentityproperty(ent, "x");
	}

	// Use offset?
	if (positioning & DC_TERRAIN_POSITION_STATE_OFFSET)
	{
		result += dc_terrain_get_offset_x();
	}

	// Return final result.
	return result;
}

// Caskey, Damon V.
// 2018-12-05
//
// Get Y position based on user settings and
// acting entity location.
float dc_terrain_find_final_position_y()
{
	float result;
	void ent;
	int positioning;

	// get positioning setting.
	positioning = dc_terrain_get_positioning_y();

	// Start with 0 value.
	result = 0.0;

	// Use entity position?
	if (positioning & DC_TERRAIN_POSITION_STATE_ENTITY)
	{
		ent = dc_terrain_get_entity();

		result += getentityproperty(ent, "y");
	}

	// Use offset?
	if (positioning & DC_TERRAIN_POSITION_STATE_OFFSET)
	{
		result += dc_terrain_get_offset_y();
	}

	// Return final result.
	return result;
}

// Caskey, Damon V.
// 2018-12-05
//
// Get Z position based on user settings and
// acting entity location.
float dc_terrain_find_final_position_z()
{
	float result;
	void ent;
	int positioning;

	// get positioning setting.
	positioning = dc_terrain_get_positioning_z();

	// Start with 0 value.
	result = 0.0;

	// Use entity position?
	if (positioning & DC_TERRAIN_POSITION_STATE_ENTITY)
	{
		ent = dc_terrain_get_entity();

		result += getentityproperty(ent, "z");
	}

	// Use offset?
	if (positioning & DC_TERRAIN_POSITION_STATE_OFFSET)
	{
		result += dc_terrain_get_offset_z();
	}

	// Return final result.
	return result;
}