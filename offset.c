#include "data/scripts/dc_terrain/config.h"

int dc_terrain_get_offset_x()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_X;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_OFFSET_X;
	}

	return result;
}

void dc_terrain_set_offset_x(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_X;

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

int dc_terrain_get_offset_y()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_Y;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_OFFSET_Y;
	}

	return result;
}

void dc_terrain_set_offset_y(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_Y;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_OFFSET_Y)
	{
		setlocalvar(id, NULL());
	}
	else
	{
		setlocalvar(id, value);
	}
}

int dc_terrain_get_offset_z()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_Z;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_OFFSET_Z;
	}

	return result;
}

void dc_terrain_set_offset_z(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_OFFSET_Z;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_OFFSET_Z)
	{
		setlocalvar(id, NULL());
	}
	else
	{
		setlocalvar(id, value);
	}
}