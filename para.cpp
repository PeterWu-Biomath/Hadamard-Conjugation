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
#include "para.h"

using namespace std;


para::para(){}

para::para(double inv,double gamma)
{
	m_inv=inv;
	m_gamma=gamma;
}

para::para(const para& m)
{
	m_inv=m.m_inv;
	m_gamma=m.m_gamma;
}

void para::set(double inv,double gamma)
{
	m_inv=inv;
	m_gamma=gamma;
}

para para::operator+(const para& b) const
{return para(m_inv+b.m_inv,m_gamma+b.m_gamma);}

para para::operator-(const para& b) const
{return para(m_inv-b.m_inv,m_gamma-b.m_gamma);}

para para::operator*(double n) const
{return para(m_inv*n,m_gamma*n);}

double para::getinv()
{return m_inv;}

double para::getgamma()
{return m_gamma;}

void para::bound(double inv_min)
{
	if(m_inv<0){m_inv=0;}
	if(m_inv>inv_min){m_inv=inv_min;}
	if(m_gamma<0){m_gamma=0;}
	if(m_gamma>10){m_gamma=10;}
}

void para::print(){cout<<m_inv<<'\t'<<m_gamma<<endl;}
