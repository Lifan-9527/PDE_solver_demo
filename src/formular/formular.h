#ifndef _FORMULAR_H
#define _FORMULAR_H

#include "utility.h"
#include <vector>
#include <complex>

namespace fml {

class Formular {
    private:
        std::string name;
	int id;
    
    public:
        int highest_order; 
        int dim;

        std::vector< std::vector<std::complex<double>> > coef;
	std::vector<int> order;
    public:
        Formular();
	Formular(int dim, int highest_order);
	LoadConfig(std::string path)
	Print();
}


class Equations {
    public:
        int eqNum;
	int varNum;
	int highest_order;
	std::vector<Formular> equations;
	bool solvable;
    public:
        Equations();
	Equations(Formular f, ...);
	Init();
	bool Check();
	Print();
    public:
	std::vector< std::complex<double> > init_t;
	std::vector< std::vector<std::complex<double>> > init_z;
}


}
