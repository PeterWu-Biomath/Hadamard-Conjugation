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
#include "settings.h"


settings::settings(){}

settings::settings(std::string infile,std::string outfile,int outformat)
{
	s_infile=infile;
	s_outfile=outfile;
	s_outformat=outformat;
}

settings::settings(const settings & m)
{
	s_infile=m.s_infile;
	s_outfile=m.s_outfile;
	s_outformat=m.s_outformat;
}

int settings::setparameters(std::string infile,std::string outfile,std::string outformat)
{
	s_outformat=0;
	s_infile=infile;
	s_outfile=outfile;
	if(outformat=="clann"||outformat=="CLANN"||outformat=="Clann"){s_outformat=2;}
	if(outformat=="qnet"||outformat=="QNet"||outformat=="QNET"||outformat=="Qnet"){s_outformat=1;}
	std::cout<<"Running information:"<<std::endl<<"Reading sequence from file: "<<infile<<std::endl;
	if(s_outformat==1)
	{
		std::cout<<"Exporting quartet weights to file: "<<outfile<<" in QNet format."<<std::endl;
	}
	else if(s_outformat==2)
	{
		std::cout<<"Exporting quartet weights to file: "<<outfile<<" in subtree format(Clann)."<<std::endl;
	}
	std::cout<<std::endl;
	return s_outformat;
}

std::string settings::getinfile()
{
	return s_infile;
}

std::string settings::getoutfile()
{
	return s_outfile;
}

int settings::getoutformat()
{
	return s_outformat;
}
