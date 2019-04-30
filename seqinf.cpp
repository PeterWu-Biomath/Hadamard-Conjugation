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
#include "seqinf.h"

using namespace std;

seqinf::seqinf(){}

seqinf::seqinf(const seqinf & m)
{
	taxa_n=m.taxa_n;
	seqlength=m.seqlength;
	taxa_name.insert(m.taxa_name.begin(),m.taxa_name.end());
	taxa_seq.insert(m.taxa_seq.begin(),m.taxa_seq.end());
}

int seqinf::gettaxa_n(){return taxa_n;}

int seqinf::getseqlength(){return seqlength;}

string seqinf::getname(int taxa_num){return taxa_name[taxa_num];}

string seqinf::getseq(int taxa_num){return taxa_seq[taxa_num];}

/*void seqinf::setname(int taxa_num,string name){taxa_name[taxa_num]=name;}

void seqinf::setseq(int taxa_num,int seq_num,int seq){taxa_seq[taxa_num][seq_num]=seq;}

void seqinf::setseq(int taxa_num,vector<int> seq){taxa_seq[taxa_num]=seq;}*/

void seqinf::readfasta(settings globalsettings)
{
	ifstream fin(globalsettings.getinfile().c_str());
	cout<<"Reading sequences from "<<globalsettings.getinfile()<<"..."<<endl;
	taxa_n=0;
	string s,seq="";
	//vector <int> vi_empty;
	//vi_empty.clear();
	
	while(!fin.eof())
	{
		getline(fin,s);
		if(s.find(">")!=string::npos)
		{
			if(taxa_n>0)
			{
				//taxa_seq[taxa_n]=vi_empty;
				taxa_seq[taxa_n]=seq;
				//for(int i=0;i<15;i++){cout<<taxa_seq[taxa_n][i]<<'\t';}cout<<endl;
			}
			//cout<<seq<<"end"<<endl;
			seq="";
			taxa_n++;
			taxa_name[taxa_n]=string(s.begin()+s.find(">")+1,s.end());
		}
		else
		{
			seq.append(s);
		}
	}
	taxa_seq[taxa_n]=seq;
	seqlength=seq.length();
}
