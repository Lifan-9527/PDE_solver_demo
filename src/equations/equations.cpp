#include "utility"
#include "euqations.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

namespace eqt {

Equations::Equations() {
    this.eID = -1;
    this.dim = -1;
    this.eqtNum = -1;
}

Equations::Equations(int eID) {
    this.eID = eID;
    this.dim = 0;
    this.eqtNum = 0;
}

Equations(const int eID, const int dim, const int eqtNum, const vec coef, const tensor orderToVar, const vec order_t, const tensor init_t, const tensor init_x) {
    this.eID = eID;
    this.dim = dim;
    this.eqtNum = eqtNum;
    this.coef = coef;
    this.orderToVar = orderToVar;
    this.order_t = order_t;
    this.init_t = init_t;
    this.init_x = init_x;
}

Equations::LoadConfig(const std::string path) {
    std::ifstream fd;
    std::string line;
    std::string key;
    std::string value;
    fd.open(path);
    if(fd.is_open()) {
        while(!fd.eof()) {

        std::getline(fd, line);
	int is_annot = line.find("%")
	int pos = line.find("=");
	if (pos>0 && pos<line.length()-1 && is_annot<0) {
	    key = line.substr(0, pos);
	    value = line.substr(pos+1, line.length())

	    switch key {

            case "dim":
	        this.dim = atoi(value);
            case "eID":
	        this.dim = atoi(value);
	    case "eqtNum":
	        this.dim = atoi(value);
	    case "coefficient":
                this.coef = StringToVec(value);
	    case "order_t":
                this.order_t = StringToTensor(value);
	    case "order_x":
                this.order_x = StringToTensor(value);
	    case "init_t":
                this.init_t = StringToTensor(value);
	    case "init_x":
	        this.init_x = StringToTensor(value);



	    }
	}
        }

    }

}

}
