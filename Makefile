CCC=g++

all: HCquartet

HCquartet: HCquartet.o function.o help.o settings.o seqinf.o hadamard.o para.o output.o optimize.o
	$(CCC) HCquartet.o function.o help.o settings.o seqinf.o hadamard.o para.o output.o optimize.o -o HCquartet

HCquartet.o: HCquartet.cpp settings.h
	$(CCC) -c HCquartet.cpp -o HCquartet.o
function.o: function.cpp function.h settings.h seqinf.h
	$(CCC) -c function.cpp -o function.o
help.o:help.cpp help.h settings.h
	$(CCC) -c help.cpp -o help.o
settings.o:settings.cpp settings.h
	$(CCC) -c settings.cpp -o settings.o
seqinf.o:seqinf.cpp seqinf.h settings.h
	$(CCC) -c seqinf.cpp -o seqinf.o
hadamard.o:hadamard.cpp seqinf.h settings.h optimize.o
	$(CCC) -c hadamard.cpp -o hadamard.o
para.o:para.cpp para.h
	$(CCC) -c para.cpp -o para.o
output.o:output.cpp seqinf.h para.h settings.h
	$(CCC) -c output.cpp -o output.o
optimize.o:optimize.cpp
	$(CCC) -c optimize.cpp -o optimize.o

clean:
	rm -f *.o