#ifndef _MAP_H
#define _MAP_H

#include <vector>

namespace map {

class rawMap {
public:
	int dim;
	vec upBorder;
	vec downBorder;
public:
	rawMap();
	rawMap(int dim, gridNum);

	void Set(vec upBorder, vec downBorder);
private:
	int raw_map_id;

};

class realMap : public rawMap {
public:
	realMap();
	tensor map_value;
private:
	vec gridNum;
	int real_map_id;

public:
	// Mesh generates map in a a 0-multi dimension space.
	MeshGrid();
	Padding();
}

}

