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
#include "function.h"
#include "help.h"

using namespace std;

int main(int argc, char** argv)
{
	cout<<"Getting command line parameters"<<endl;
	//cout<<argc<<endl;
	settings globalsettings;
	
	if(argc==1){cerr<<"error:not enough parameters!!"<<endl;return 0;}
	if(argc==2)
	{
		if(string(argv[1])=="--help"){help();return 0;}
		else{cerr<<"error:improper parameters!!"<<endl;return 0;}
	}
	if(argc==5)
	{
		if(string(argv[1])=="-in"&&string(argv[3])=="-out")
		{
			globalsettings.setparameters(string(argv[2]),string(argv[4]),"qnet");
		}
		else{cerr<<"error:improper parameters!!"<<endl;}
	}
	if(argc==7)
	{
		if(string(argv[1])=="-in"&&string(argv[3])=="-out"&&string(argv[5])=="-filetype")
		{
			globalsettings.setparameters(string(argv[2]),string(argv[4]),string(argv[6]));
			if(globalsettings.getoutformat()==0) {cerr<<"error:improper file type parameters!!"<<endl;return 0;}
		}
		else{cerr<<"error:improper parameters!!"<<endl;return 0;}
	}
	
	calHC(globalsettings);
	cout<<endl;
	return 0;
	//else if()
}
