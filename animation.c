#include "data/scripts/dc_terrain/config.h"

#import "data/scripts/dc_terrain/instance.c"

int dc_terrain_get_animation()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_OFFSET_X;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_OFFSET_X;
	}

	return result;
}

void dc_terrain_set_animation(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_VAR_KEY_OFFSET_X;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_OFFSET_X)
	{
		setlocalvar(id, NULL());
	}
	else
	{
		setlocalvar(id, value);
	}
}