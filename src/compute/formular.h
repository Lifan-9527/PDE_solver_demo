#ifndef _FORMULAR_H
#define _FORMULAR_H

#include "utility.h"
#include "point.h"
#include <vector>

namespace fml {

class Formular {
    private:
        std::string name;
	int id;
    
    public:
        int highest_order; 
        int dim;
	std::vector< std::complex<double> > init_t;
	std::vector< std::vector<std::complex<double>> > init_z;

        std::vector< std::vector<std::complex<double>> > coef;
	std::vector<int> order;
    public:
        Formular();
	Formular(int dim, int highest_order);

	LoadConfig(std::string path)

        propagate();

	Print();

}

}
