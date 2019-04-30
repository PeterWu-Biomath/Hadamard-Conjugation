#ifndef SEQINF_H
#define SEQINF_H

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

class seqinf
{
	private:
		int taxa_n;
		int seqlength;
		std::map <int,std::string> taxa_name;
		std::map <int,std::string> taxa_seq;
	public:
		seqinf();
		seqinf(const seqinf & m);
		std::string getname(int taxa_num);
		int gettaxa_n();
		int getseqlength();
		std::string getseq(int taxa_num);
		/*void setname(int taxa_num,std::string name);
		void setseq(int taxa_num,int seq_num,int seq);
		void setseq(int taxa_num,std::vector<int> seq);*/
		void readfasta(settings globalsettings);
};

#endif
