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
#include "hadamard.h"
#include "para.h"
#include "output.h"

using namespace std;

int ind[256];

void initind()
{
	for(int i=0;i<256;i++)
	{ind[i]=i^(i/64*85);}
}

int alphabet(char c)
{
	switch(c)
	{case 'A':
		return 0;
	case 'T':
		return 1;
	case 'G':
		return 2;
	case 'C':
		return 3;
	case '-':
		return -1;
	default:
		return -2;}
}



void calprobability(string s1,string s2,string s3,string s4,vector<double>& probability)
{
	int i,u,len=0,m[4];
	probability.clear();
	for(i=0;i<64;i++){probability[i]=0;}
	for(i=0;i<s1.length();i++)
	{
		m[0]=alphabet(s1[i]);
		m[1]=alphabet(s2[i]);
		m[2]=alphabet(s3[i]);
		m[3]=alphabet(s4[i]);
		if(m[0]>=0&&m[1]>=0&&m[2]>=0&&m[3]>=0)
		{
			len++;
			probability[ind[m[0]*64+m[1]*16+m[2]*4+m[3]]]++;
		}
	}
	for(i=0;i<64;i++){probability[i]=probability[i]/len;}
}

void hadamardqnet(seqinf seqs,settings globalsettings)
{
	initind();
	vector<double> probability(64);
	int n=seqs.gettaxa_n(),i,j,k,l,c=0;
	vector<vector<double> > allfreq(n*(n-1)*(n-2)*(n-3)/24, vector<double>(64,1));
	vector<double> v_tmp(64,0);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=1;k<j;k++)
			{
				for(l=1;l<k;l++)
				{
					calprobability(seqs.getseq(l),seqs.getseq(k),seqs.getseq(j),seqs.getseq(i),v_tmp);
					for(int t=0;t<64;t++){allfreq[c][t]=v_tmp[t];}
					c++;
				}
			}
		}
	}
	
	para var_parameter;
	var_parameter.optimize(allfreq);
	qnetoutput(seqs,var_parameter,allfreq,globalsettings);
}

void hadamardclann(seqinf seqs,settings globalsettings)
{
	initind();
	vector<double> probability(64);
	int n=seqs.gettaxa_n(),i,j,k,l,c=0;
	vector<vector<double> > allfreq(n*(n-1)*(n-2)*(n-3)/24, vector<double>(64,1));
	vector<double> v_tmp(64,0);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=1;k<j;k++)
			{
				for(l=1;l<k;l++)
				{
					calprobability(seqs.getseq(l),seqs.getseq(k),seqs.getseq(j),seqs.getseq(i),v_tmp);
					for(int t=0;t<64;t++){allfreq[c][t]=v_tmp[t];}
					c++;
				}
			}
		}
	}
	
	para var_parameter;
	var_parameter.optimize(allfreq);
	clannoutput(seqs,var_parameter,allfreq,globalsettings);
}