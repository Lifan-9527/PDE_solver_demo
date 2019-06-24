#ifndef _UTILITY_H
#define _UTILITY_H

#define number double

using comp = std::complex<number>;
using vec = std::vector<number>;
using tensor = std::vector<vec>;
using vecString = std::vector<std::string>;

const double c = 3e8;

double W2F(double wavelength) {
	return c/wavelength;
}
double F2W(double freq) {
	return c/freq;
}

// The argument str is a string object, in
// form: "v1, v2, v3, v4, ..., vn".
// The seperator can be comma or blankspace.
vec StringToVec(const std::string str) {
    int len = str.length();
    if (len < 1) {
        std::cout << "Invalid config file format." << std::endl;
	exit(-1);
    }
    vec res(0);

    
}

// 由于这里仅仅用于读配置文件,
// 暂时传引用以减少内存使用
// 如果需要保护数据则应该传值.
comp StringToComplex (std::string & input) {
    double real=0, imag=0;
    delAllBlankspace(input);

    int pos = input.find("+");
    if (pos<0) pos = input.find("-");
    if (pos<0) {
        std::cout << "Invalid complex number format." << std::endl;
	exit(-1);
    }

    real = atof( input.substr(0, pos). c_str() );
    imag = atof( input.substr(pos+1, input.size()). c_str() );
    comp x(real, imag);
    return x;
}

// 由于这里仅仅用于读配置文件,
// 暂时传引用以减少内存使用.
// 如果需要保护数据则应该传值.
vec StringToVec (std::string & line) {
    int pos = 0;
    vecString tmp;
    vec res;
    while (pos>=0) {
        pos = line.find(",");
	tmp.push_back(line.substr(0, pos));
	line.erase(0, pos+1);
    }
    for (int i=0; i<tmp.size(); i++) {
        delAllBlankspace (tmp[i]);
        res.push_back( StringToComplex( tmp[i] );	
    }

}

//
/*
tensor StringToTensor (std::string & line) {


}
*/










// Delete all blankspace.
// Changes happen on data.
void delAllBlankspace(std::string & input) {   
    int k=0;
    while(k>=0) {
        k = input.find(' ');
	if (k>=0) input.erase(k, 1);
    }
}
