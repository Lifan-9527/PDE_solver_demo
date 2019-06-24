const double c = 3e8;

double W2F(double wavelength) {
	return c/wavelength;
}
double F2W(double freq) {
	return c/freq;
}

using vec = ::std::vector<double>;
using tensor = ::std::vector<vec>;

// The argument str is a string object, in
// form: "v1, v2, v3, v4, ..., vn".
// The seperator can be comma or blankspace.
vec StringToVec(const std::string str) {
    int len = str.length();
    if (len < 1) {
        std::cout << "Invalid config file format." << std::endl;
	exit(-1);
    }
    vec
}
