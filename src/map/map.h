#ifndef _MAP_H
#define _MAP_H

#include <vector>

namespace map {
using vec = ::std::vector<double>;
using tensor = ::std::vector<vec>;

class rawMap {
public:
	int dim;
	vec upBorder;
	vec downBorder;
public:
	rawMap();
	rawMap(int dim);

	void Set(vec upBorder, vec downBorder);
private:
	int raw_map_id;

};

class realMap : public rawMap {
public:
	realMap();
	tensor map_value;
private:
	vec map_valueNum;
	int real_map_id;

public:
	// Mesh generates map in a a 0-multi dimension space.
	MeshGrid();
	Padding();
}

}

