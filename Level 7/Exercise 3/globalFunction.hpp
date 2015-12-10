#ifndef globalFunc_HPP
#define globalFunc_HPP

struct less_x { //functor
	less_x(double x) : x(x) {}
	bool operator()(double y) { return y < x;  }

	private:
		double x;
};
#endif