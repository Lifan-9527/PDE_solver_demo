#include <iostream>
#include <vector>
#include "map.h"
namespace map {

rawMap::rawMap() {
	this.dim = -1;
	mapID = -1;
}
rawMap::rawMap(int dim) {
	if(dim<=0) {
		::std::cout << "invalid dimension in rawMap initializing." << ::std::endl;
		exit(-1);
	}else {
		this.upBorder = vec(dim);
		this.downBorder = vec(dim);
	}
}

rawMap::Set(const vec upBorder, const vec downBorder){
	if upBorder.size()!=downBorder.size(){
		::std::cout << "unmatched inputs" << ::std::endl;
		exit(-1);
	}
	if this.dim != upBorder.size() {
		::std::cout << "input vector length is unmatched with rawMap dimension." << ::std::endl;
		this.upBorder(upBorder);
		this.downBorder(downBorder);
	}
}



realMap::realMap(int dim, vec gridNum) {
	if(dim!=gridNum.size()){
		::std::cout << "the dimension setting is not matched with the gridNum." << ::std::endl;
	exit(-1);
	}
	this.dim = dim;
	this.gridNum = gridNum;
}


realMap::MeshGrid() {
	for (int i=0; i<gridNum.size(); i++) {
		map_value[i] = vec(gridNum[i]);
		for (int j=0; j<gridNum[i]; j++) {
			map_value[i][j] = this.upBorder;	
		}
	}
}

realMap::Padding(rawMap region, double value) {

}

realMap::Padding() {
}






}
