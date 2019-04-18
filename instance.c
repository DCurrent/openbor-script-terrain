#include "data/scripts/dc_terrain/config.h"

// Caskey, Damon V.
// 2018-11-29
//
// Return set instance, or default instance if
// set value is non-existing or invalid.
int dc_terrain_get_instance()
{
	int result;

	// Get instance value.
	result = getlocalvar(DC_TERRAIN_MEMBER_INSTANCE);

	// Value must be a valid integer, or
	// we will use the default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_INSTANCE;
	}

	return result;
}

// Caskey, Damon V.
//
// 2018-11-29
// Set instance value. 
void dc_terrain_set_instance(int value)
{
	// Only set instance value if new value
	// is different from default. No reason to waste
	// the memory on a default value.
	if (value != DC_TERRAIN_DEFAULT_INSTANCE)
	{
		setlocalvar(DC_TERRAIN_MEMBER_INSTANCE, value);
	}
	else
	{
		setlocalvar(DC_TERRAIN_MEMBER_INSTANCE, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Clears the current instance, effectively resetting
// all values to their defaults.
void dc_terrain_reset_instance()
{
	int instance;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Destroy all instance variables.
	dc_terrain_free_instance();

	// If the instance ID isn't default, then restore 
	// it to memory. Either way we now have a clean
	// copy of the current instance.
	if (instance != DC_TERRAIN_DEFAULT_INSTANCE)
	{
		dc_terrain_set_instance(instance);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance by deleting all
// library variables.
void dc_terrain_free_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_TERRAIN_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_TERRAIN_BASE_ID + i;

		// Delete variable.
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Send all library variables to log for debugging.
void dc_terrain_dump_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Log base name and instance.
	log("\n\n " + DC_TERRAIN_BASE_ID + " dump:");
	log("\n\t " + "Instance: " + instance);

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_TERRAIN_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_TERRAIN_BASE_ID + i;

		// Log ID.
		log("\n\t " + id + ": ");

		// Log value.
		log(getlocalvar(id));
	}

	// Log end point.
	log("\n End Dump.\n");
}

// Caskey, Damon V.
// 2018-11-28
//
// Export instance to global vars for other event
// to import.
void dc_terrain_export_instance()
{
	int instance;
	int i;
	char id;

	void value;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_TERRAIN_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_TERRAIN_BASE_ID + i;

		// Get local (library) value.
		value = getlocalvar(id);

		// Export value to global var.
		setglobalvar(id, value);
	}
}

// Caskey, Damon V.
// 2018-11-28
//
// Import an exported instance.
void dc_terrain_import_instance()
{
	int instance;
	int i;
	char id;

	void value;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_TERRAIN_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_TERRAIN_BASE_ID + i;

		// Get value
		value = getglobalvar(id);

		// Import value to local (library) var.
		setlocalvar(id, value);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance export.
void dc_terrain_free_export_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_terrain_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_TERRAIN_MEMBER_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_TERRAIN_BASE_ID + i;

		// Delete the global variable.
		setglobalvar(id, NULL());
	}
}