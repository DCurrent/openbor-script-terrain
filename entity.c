#include "data/scripts/dc_terrain/config.h"

#import "data/scripts/dc_terrain/instance.c"

void dc_terrain_get_entity()
{
	char id;
	void result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_ENT;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_ENT;
	}

	return result;
}

void dc_terrain_set_entity(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_ENT;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_ENT)
	{
		value = NULL();
	}
	
	setlocalvar(id, value);
}