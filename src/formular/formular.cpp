#include "formular.h"
#include <cstdarg>

namespace fml {

Formular::Formular() {
    this.name = "anonymous";
    this.id = -1;
    this.highest_order = 0;
    this.dim = 0;
}
Formular::Formular(int dim, int highest_order) {
    this.name = "anonymous";
    this.id = -1;
    this.highest_order = highest_order;
    this.dim = dim;
}

Formular::LoadConfig (const std::string path) {
    std::ifstream fd;
    std::string line;
    std::string key;
    std::string value;

    fd.open(path);
    if(!fd.is_open()) {
	std::cout << "Failed to load file:" << path << std::endl;
        exit(-1);
    }else {
        while(!fd.eof()) {
            std::getline(fd, line);
	    int is_annot = line.find("%")<0;
	    int pos = line.find("=");
	    if (pos>0 && pos<line.length()-1 && is_annot<0) {
	        key = line.substr(0, pos);
	        value = line.substr(pos+1, line.length())

	        switch key {
		case "name":
                    this.name = value;
		case "id":
                    this.id = atoi(value);
		case "highest_order":
                    this.highest_order = atoi(value);
		case "dim":
                    this.highest_order = atoi(value);
		case "init_t":
                    if ( value.front()=='{' ) {
		        while() {
                            getline(fd, line);
			    deleteALLBlankspace(line);
			    parseVector(line);
                        }
		    }
		case "init_z":

		case "coef":
		
		
		}
	    }
	}
    }
}


Equations::Equations(){
    this.eqNum = 0;
    this.varNum = 0;
    this.highest_order = -1;
    this.solvable = false;
}
Equations::Equations(Formular f, ...){

}


Equations::Init(){
}

Equations::Check(){
}

Equations::Print(){
}

}
