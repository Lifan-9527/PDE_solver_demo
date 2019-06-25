#include "map.h"
#include "equations.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "utility.h"


int main(int argc, char** argv) {
    vec upBorder(1);
    upBorder[1] = 
    vec downBorder(1);
    realMap fibre(1, 100);
    fibre.Set(upBorder, downBorder);
}
