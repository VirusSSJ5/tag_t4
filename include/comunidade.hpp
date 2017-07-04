#ifndef COMUNIDADEHPP
#define COMUNIDADEHPP

#include "common.hpp"

class comunidade{
public:
	static set<string> deputadosUsados;//ja estao em outras comunidades
	static set<string> empresasUsados;//ja estao em outras comunidades

	set<string> deps;//deputados
	set<string> emps;//empresas
	comunidade();

	double calcQ();
	comunidade operator+(deputado d);
	comunidade operator+(empresa e);
};

std::ostream& operator<<(std::ostream& os,const comunidade& c);

using mapComunidade=map<int,comunidade>;

#endif//COMUNIDADEHPP
