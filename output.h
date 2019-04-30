#ifndef OUTPUT_H
#define OUTPUT_H

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
#include "seqinf.h"
#include "para.h"
#include "settings.h"

void qnetoutput(seqinf seqs,para var_parameter,std::vector<std::vector<double> > allfreq,settings globalsettings);
void clannoutput(seqinf seqs,para var_parameter,std::vector<std::vector<double> > allfreq,settings globalsettings);


#endif
