#ifndef PARA_H
#define PARA_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>
#include <iterator>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <time.h>

class para
{private:
	double m_inv;
	double m_gamma;
public:
	para();
	para(double inv,double gamma);
	para(const para & m);
	void set(double inv,double gamma);
	para operator+ (const para & b) const;
	para operator- (const para & b) const;
	para operator* (double n) const;
	double getinv();
	double getgamma();
	void bound(double inv_min);
	void optimize(std::vector<std::vector<double> > allfreq);
	void print();
};

#endif