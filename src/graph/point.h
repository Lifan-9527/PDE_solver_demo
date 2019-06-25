#ifndef _POINT_H
#define _POINT_H

#include <vector>
#include "utility.h"

namespace graph {

class Point {
    public:
        int pID;
    public:
        Point();
    public:
        vec position;
	std:: param;
	vec channel;
}



class Line {
    public:
        Line();
	Line(int n);
	Line(std::vector<Point> dots);
	Line(const Line & origin);
	~Line();
    public:
        std::vector<Point> line;
	
}

Line propagate ( const Line & fibre, const Equation & eq ) {




}


}
