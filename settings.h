#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>


class settings
{
	private:
		std::string s_infile;
		std::string s_outfile;
		int s_outformat;			//1 for qnet, 2 for clann subtrees
	public:
		settings();
		settings(std::string infile,std::string outfile,int outformat);
		settings(const settings & m);
		int setparameters(std::string infile,std::string outfile,std::string outformat);
		std::string getinfile();
		std::string getoutfile();
		int getoutformat();
};

#endif
