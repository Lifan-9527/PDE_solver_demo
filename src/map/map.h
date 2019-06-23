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
	int mapID;
	

};

class realMap : public rawMap {
public:
	realMap();
	tensor grid;
private:
	int gridNum;

public:
	Mesh();
}

}

