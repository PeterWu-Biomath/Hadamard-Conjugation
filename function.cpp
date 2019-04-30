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

using namespace std;

void calHC(settings globalsettings)
{
	seqinf seqs;
	seqs.readfasta(globalsettings);
	if(globalsettings.getoutformat()==1)
	{hadamardqnet(seqs,globalsettings);}
	if(globalsettings.getoutformat()==2)
	{hadamardclann(seqs,globalsettings);}
}

void hadamard_64(vector<double> & f)
{
	int i;
	double tmp1,tmp2;
	for(i=0;i<64;i+=2)
	{
		tmp1=f[i]+f[i+1];
		tmp2=f[i]-f[i+1];
		f[i]=tmp1;
		f[i+1]=tmp2;
	}
	for(i=0;i<64;i++)
	{
		if(i%4<2)
		{
			tmp1=f[i]+f[i+2];
			tmp2=f[i]-f[i+2];
			f[i]=tmp1;
			f[i+2]=tmp2;
		}
	}
	for(i=0;i<64;i++)
	{
		if(i%8<4)
		{
			tmp1=f[i]+f[i+4];
			tmp2=f[i]-f[i+4];
			f[i]=tmp1;
			f[i+4]=tmp2;
		}
	}
	for(i=0;i<64;i++)
	{
		if(i%16<8)
		{
			tmp1=f[i]+f[i+8];
			tmp2=f[i]-f[i+8];
			f[i]=tmp1;
			f[i+8]=tmp2;
		}
	}
	for(i=0;i<64;i++)
	{
		if(i%32<16)
		{
			tmp1=f[i]+f[i+16];
			tmp2=f[i]-f[i+16];
			f[i]=tmp1;
			f[i+16]=tmp2;
		}
	}
	for(i=0;i<64;i++)
	{
		if(i%64<32)
		{
			tmp1=f[i]+f[i+32];
			tmp2=f[i]-f[i+32];
			f[i]=tmp1;
			f[i+32]=tmp2;
		}
	}
}
