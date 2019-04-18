#include "data/scripts/dc_terrain/config.h"

#import "data/scripts/dc_terrain/instance.c"
#import "data/scripts/dc_terrain/animation.c"
#import "data/scripts/dc_terrain/entity.c"
#import "data/scripts/dc_terrain/offset.c"
#import "data/scripts/dc_terrain/position.c"

// Access and mutate.

int dc_terrain_get_wall()
{
	char id;
	int result;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_WALL;

	// Get value from local var.
	result = getlocalvar(id);

	// If result is empty or invalid, use default.
	if (typeof(result) != openborconstant("VT_INTEGER"))
	{
		result = DC_TERRAIN_DEFAULT_WALL;
	}

	return result;
}

void dc_terrain_set_wall(int value)
{
	char id;

	// Concatenate instance and key to create an id.
	id = dc_terrain_get_instance() + DC_TERRAIN_MEMBER_WALL;

	// If value is same as default, then make
	// sure the local var is deleted. Otherwise
	// store the value.
	if (value == DC_TERRAIN_DEFAULT_WALL)
	{
		setlocalvar(id, NULL());
	}
	else
	{
		setlocalvar(id, value);
	}
}

// Operations

// Caskey, Damon V.
// 2018-13-03
//
// Returns index of nearest wall in animation range, 
// or DC_TERIAIN_NO_WALL if none found.
int dc_terrain_find_wall()
{
	void ent;			// Acting entity.
	int i;				// Loop cursor.
	int wall_count;		// Number of walls in level.
	int animation;
	float edge_left;
	float edge_right;

	// Get acting entity and animation.
	ent = dc_terrain_get_entity();
	animation = dc_terrain_get_animation();

	// Loop through the level's wall collection.

	wall_count = openborvariant("numwalls");

	for (i = 0; i < wall_count; i++)
	{
		// Verify the wall is within range of animation.
		// If not, then exit this iteration of the loop.
		if (!dc_terrain_check_wall_in_range_all(i))
		{
			continue;
		}

		
	}
}

// Caskey, Damon V.
// 2018-12-07
// 
// Find distance from X position to left horizontal edge 
// of wall along a given Z axis.
float dc_terrain_distance_to_wall_left_edge_x(int wall)
{
	float pos_x;
	float edge;

	// Get X and edge positions.
	edge	= dc_terrain_find_wall_left_edge_x(wall);
	pos_x	= dc_terrain_find_final_position_x();

	// Return difference between edge and X position.
	return dc_math_difference_float(edge, pos_x);
}


// Caskey, Damon V.
// 2018-12-03
//
// Return the absolute horizontal position of a wall's
// left edge at a given Z axis.
//
// wall: Wall index.
float dc_terrain_find_wall_left_edge_x(int wall)
{
	void ent;
	float pos_z;
	float x;
	float z;
	float depth;
	float lower_corner;
	float upper_corner;
	float coefficient;
	float result;

	// If there are no walls, return 0.
	if (!openborvariant("numwalls"))
	{
		return 0.0;
	}

	// Get Z position to search from.
	pos_z = dc_terrain_find_final_position_z();

	// Get wall dimensions.
	x = getlevelproperty("wall", wall, "x");
	z = getlevelproperty("wall", wall, "z");
	lower_corner = getlevelproperty("wall", wall, "lowerleft");
	upper_corner = getlevelproperty("wall", wall, "upperleft");
	depth = getlevelproperty("wall", wall, "depth");

	// Walls are rectangular parallelepipeds (think cube with a parallelogram
	// as its base), so accurately calculating where the wall edge is along
	// a given lateral position can be a little complex. We'll take 
	// some cues from OpenBOR's internal testwall() function.
	//
	// 1. Get distance between the entity's and wall's Z positions. 
	//
	// 2. Multiply distance by the difference of the bottom left 
	// point and the top left point divided by depth of the platform.
	//
	// Assuming the entity's Z position is exactly halfway between the 
	// wall Z position and depth, this will produce a horizontal value
	// exacty halfway between the upper left and lower left offsets.
	// This value is our coefficient.
	//
	// Example:
	// 
	// Entity Z:	120
	// X Position:	500
	// Z Position:	200
	// Depth:		40
	// Lower Left:	0
	// Upper Left:	10
	// Coefficient:	5
	//
	// We then add the coefficient to wall's X position and the
	// lower left offset to get an absolute horizontal position 
	// of the wall's left edge. In our example above, the wall's 
	// edge is at 505.
	//
	// Because we include the entity's Z position when we calculate
	// the coefficient, as the entity moves along Z axis the coefficient 
	// changes accordingly,  This gives us a precise X location 
	// of the wall's edge relative to entity's Z position. In the
	// example above, if our entity moves to Z 170, the coefficient
	// is now 7.5, giving us an absolute wall edge of 507.5.

	// Get our coefficients.
	coefficient = (z - pos_z) * ((upper_corner - lower_corner) / depth);

	// Add position and the lower corner to get an absolute
	// position of the walls edge at Z axis.
	result = x + lower_corner + coefficient;

	return result;
}

// Caskey, Damon V.
// 2018-12-03
//
// Return the absolute horizontal position of a wall's
// right edge at a given Z axis.
//
// wall: Wall index.
// Z: Z posiiton. If omitted, acting entity's current Z position used.
float dc_terrain_find_wall_right_edge_x(int wall)
{
	void ent;
	float pos_z;
	float x;
	float z;
	float depth;
	float lower_corner;
	float upper_corner;
	float coefficient;
	float result;

	// If there are no walls, return 0.
	if (!openborvariant("numwalls"))
	{
		return 0.0;
	}

	// Get Z position to search from.
	pos_z = dc_terrain_find_final_position_z();

	// Get wall dimensions.
	x = getlevelproperty("wall", wall, "x");
	z = getlevelproperty("wall", wall, "z");
	lower_corner = getlevelproperty("wall", wall, "lowerright");
	upper_corner = getlevelproperty("wall", wall, "upperright");
	depth = getlevelproperty("wall", wall, "depth");

	// See dc_terrain_find_wall_left_edge_x() for explanation of 
	// the coefficient.

	// Get our coefficients.
	coefficient = (z - pos_z) * ((upper_corner - lower_corner) / depth);

	// Add position and the lower corner to get an absolute
	// position of the walls edge at Z axis.
	result = x + lower_corner + coefficient;

	return result;
}

// Caskey, Damon V.
// 2018-12-05
//
// Return absolute location of midpoint between wall 
// edges on X axis along a given Z position.
int dc_terrain_find_wall_center_x(int wall)
{
	float edge_left;
	float edge_right;

	edge_left = dc_terrain_find_wall_left_edge_x();
	edge_right = dc_terrain_find_wall_right_edge_x();

	// Return midpoint of edges.
	return dc_math_midpoint_float(edge_left, edge_right);
}

// Caskey, Damon V.
// 2018-12-05
//
// Return thickness of wall (distance between X edges)
// along a given Z axis.
int dc_terrain_find_wall_width(int wall)
{
	float edge_left;
	float edge_right;

	edge_left = dc_terrain_find_wall_left_edge_x();
	edge_right = dc_terrain_find_wall_right_edge_x();

	// Find difference between edges and return.
	return dc_math_difference_float(edge_right, edge_left);
}

// Caskey, Damon V.
// 2018-12-03
//
// Return true if wall index is within range of animation
// range (for active entity).
int dc_terrain_check_wall_in_range_all(int wall)
{
	// Run range check for each axis. If any one returns
	// false, then we return false here.

	if (!dc_terrain_check_wall_in_range_x(wall))
	{
		return 0;
	}

	if (!dc_terrain_check_wall_in_range_y(wall))
	{
		return 0;
	}

	if (!dc_terrain_check_wall_in_range_z(wall))
	{
		return 0;
	}

	// Made it this far, we can return true.
	return 1;
}

// Caskey, Damon V.
// 2018-12-03
//
// Return true if wall index is within horizontal 
// range of animation (for active entity).
int dc_terrain_check_wall_in_range_x(int wall)
{
	float edge_left;
	float edge_right;

	// If there are no walls, return false.
	if (!openborvariant("numwalls"))
	{
		return 0;
	}

	// Get wall edge positions.
	edge_left = dc_terrain_find_wall_left_edge_x(wall);
	edge_right = dc_terrain_find_wall_right_edge_x(wall);

	// Prepare target library.
	dc_target_set_instance(dc_terrain_get_instance());
	dc_target_set_animation(dc_terrain_get_animation());
	dc_target_set_entity(dc_terrain_get_entity());

	// Return result of range check.
	return dc_target_check_range_in_range_x(edge_left, edge_right);
}

// Caskey, Damon V.
// 2018-12-03
//
// Return true if wall index is within vertical 
// range of animation (for active entity).
int dc_terrain_check_wall_in_range_y(int wall)
{
	float height;

	// If there are no walls, return false.
	if (!openborvariant("numwalls"))
	{
		return 0;
	}

	// Get wall height.
	height = getlevelproperty("wall", wall, "height");

	// Prepare target library.
	dc_target_set_instance(dc_terrain_get_instance());
	dc_target_set_animation(dc_terrain_get_animation());
	dc_target_set_entity(dc_terrain_get_entity());

	// Return height vs. range.
	return dc_target_check_position_in_range_y(height);
}

// Caskey, Damon V.
// 2018-12-03
//
// Return true if wall index is within lateral 
// range of animation (for active entity).
int dc_terrain_check_wall_in_range_z(int wall)
{
	// Wall position/dimensions.
	float z;
	float depth;

	// Wall calculations.
	float test_depth;

	// If there are no walls, return false.
	if (!openborvariant("numwalls"))
	{
		return 0;
	}

	// Get wall Z dimensions.
	z = getlevelproperty("wall", wall, "z");
	depth = getlevelproperty("wall", wall, "depth");

	// Get final test depth.
	test_depth = z + depth;

	// Prepare target library.
	dc_target_set_instance(dc_terrain_get_instance());
	dc_target_set_animation(dc_terrain_get_animation());
	dc_target_set_entity(dc_terrain_get_entity());

	// Return height vs. range.
	return dc_target_check_range_in_range_z(z, test_depth);
}