#include "data/scripts/dc_terrain/config.h"

#import "data/scripts/dc_terrain/entity.c"
#import "data/scripts/dc_terrain/instance.c"
#import "data/scripts/dc_terrain/offset.c"

// Access and mutators.

int dc_terrain_get_positioning_x()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_X;

	// Get value from local var.
	result = getlocavar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITIONING_X;
	}

	return result;
}

void dc_terrain_set_positioning_x(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_X;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITIONING_X)
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
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_Y;

	// Get value from local var.
	result = getlocavar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITIONING_Y;
	}

	return result;
}

void dc_terrain_set_positioning_y(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_Y;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITIONING_Y)
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
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_Z;

	// Get value from local var.
	result = getlocavar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_POSITIONING_Z;
	}

	return result;
}

void dc_terrain_set_positioning_z(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_POSITIONING_Z;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_POSITIONING_Z)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

// Operations.

