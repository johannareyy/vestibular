CXXARGS = -Wall -Wextra -std=c++17
NOMEPROG = exproposto1.bin

#make compilar
compilar: exproposto1.cpp
	g++ exproposto1.cpp -o $(NOMEPROG) $(CXXARGS)

#make debug
debug: exproposto1.cpp
	g++ exproposto1.cpp -o $(NOMEPROG) $(CXXARGS) -g

apagar:
	rm $(NOMEPROG)

executar: compilar
	./$(NOMEPROG)
	
