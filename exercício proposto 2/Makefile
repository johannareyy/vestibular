CXXARGS = -Wall -Wextra -std=c++17
NOMEPROG = exproposto2.bin

#make compilar
compilar: exproposto2.cpp
	g++ exproposto2.cpp -o $(NOMEPROG) $(CXXARGS)

#make debug
debug: exproposto2.cpp
	g++ exproposto2.cpp -o $(NOMEPROG) $(CXXARGS) -g

apagar:
	rm $(NOMEPROG)

executar: compilar
	./$(NOMEPROG)

