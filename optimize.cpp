#include "para.h"
#include "function.h"
#include <vector>
#include <math.h>

using namespace std;

double rel_ent(vector<double> f,double inv,double gamma)
{
	int i;
	double tmp;
	int index[]={7,8,10,12,14,15,19,20,23,24,25,26,27,28,29,30,31,32,34,36,37,38,39,40,42,44,45,46,47,48,50,51,53,54,55,56,57,58,59,60,62,63};
	vector<double> u=f;
	hadamard_64(u);
	for(i=0;i<64;i++)
	{
		tmp=(u[i]-inv)/(1-inv);
		tmp=pow(tmp,-1/gamma)-1;
		u[i]=tmp;
	}
	hadamard_64(u);
	
	for(i=0;i<64;i++){u[i]=u[i]/64;if(u[i]>0){u[i]=0;}}
	for(i=0;i<42;i++){u[index[i]-1]=0;}
	u[0]=0;
	for(i=0;i<64;i++){u[0]-=u[i];}
	
	hadamard_64(u);
	for(i=0;i<64;i++)
	{
		tmp=u[i];
		u[i]=(pow(1+tmp,-gamma))*(1-inv)+inv;
	}
	hadamard_64(u);
	for(i=0;i<64;i++){u[i]=u[i]/64;}
	tmp=0;
	for(i=0;i<64;i++){if(f[i]>0){tmp+=f[i]*(log(u[i])-log(f[i]));}}
	return tmp;
}

double score(vector<vector<double> > allfreq,double inv,double gamma)
{
	double i=0;
	for(int count=0;count<allfreq.size();count++)
	{i-=rel_ent(allfreq[i],inv,gamma);}
	return i;
}

double score(vector<vector<double> > allfreq,para parameter){return score(allfreq,parameter.getinv(),parameter.getgamma());}

void para::optimize(vector<vector<double> > allfreq)
{
	double inv_min=1;
	vector<double> v_tmp;
	for(int count=0;count<allfreq.size();count++)
	{
		v_tmp=allfreq[count];
		hadamard_64(v_tmp);
		for(int i=1;i<64;i++)
		{if(inv_min>v_tmp[i]){inv_min=v_tmp[i];}}
	}
	
	double error=1;
	para worst,good,best,reflect,ext,mid,shr,con;
	worst.set(inv_min*0.3,3);
	good.set(inv_min*0.3,5);
	best.set(inv_min*0.6,5);
	cout<<"optimizing"<<endl;
	int round=0;
	
	while(error>0.0001)
	{
		double worst_value=score(allfreq,worst);
		double good_value=score(allfreq,good);
		double best_value=score(allfreq,best);
		//cout<<best_value<<'\t'<<good_value<<'\t'<<worst_value<<endl;
		//best.print();
		//worst.print();
		//good.print();
		double tmp;
		
		if(best_value>good_value){shr=best;best=good;good=shr;tmp=best_value;best_value=good_value;good_value=tmp;}
		if(best_value>worst_value){shr=best;best=worst;worst=shr;tmp=best_value;best_value=worst_value;worst_value=tmp;}
		if(worst_value<good_value){shr=worst;worst=good;good=shr;tmp=good_value;good_value=worst_value;worst_value=tmp;}
		error=-(best_value-worst_value)/(worst_value);
		round++;
		cout<<"optimizing round "<<round<<".\n";
		cout<<"error:"<<error<<endl;
		
		reflect=best+good-worst;
		reflect.bound(inv_min);
		double reflect_value=score(allfreq,reflect);
		
		if(reflect_value<good_value)
		{
			if(reflect_value<best_value)
			{worst=reflect;}
			else
			{
				ext=reflect*2-best*0.5-good*0.5;
				ext.bound(inv_min);
				double ext_value=score(allfreq,ext);
				if(ext_value<best_value)
				{worst=ext;}
				else{worst=reflect;}
			}
		}
		else
		{
			if(reflect_value<worst_value)
			{worst=reflect;}
			con=worst*0.5+best*0.25+good*0.25;
			con.bound(inv_min);
			double con_value=score(allfreq,con);
			if(con_value<worst_value)
			{worst=con;}
			else
			{worst=worst*0.5+best*0.5;good=good*0.5+best*0.5;}
		}
		best.bound(inv_min);
		good.bound(inv_min);
		worst.bound(inv_min);
	}
	cout<<"optimizing done."<<endl;
	
	m_inv=best.getinv();
	m_gamma=best.getgamma();
	
}