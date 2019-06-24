#ifndef _EQUATIONS_H
#define _EQUATIONS_H


#include "utility"
#include <cstring>

namespace eqt {

class Equations {
    private:
        int eID;

    public:
        Equations();
        Equations(int eID);
	Equations(int eID, int dim, int eqtNum, vec coef, tensor orderToVar, vec order_t, tensor init_t, tensor init_x)

    public:
        int dim;
	int eqtNum;
        vec coef;
        tensor order_x;    // each element is the i term's derivative to j variable;
	vec order_t;
        tensor init_t;    // time initial descriptor tensor   ~ E(t=t0, x)
        tensor init_x;    // space initial descrptor tensor.  ~ E(t, x=x0)
        
	vec propagate();
	vec propagate(int n);

	int loadConfig(std::string path);

	int SetManually(int eID, int dim, int eqtNum, vec coef, tensor orderToVar, vec order_t, tensor init_t, tensor init_x);
}


}
