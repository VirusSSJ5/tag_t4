#ifndef COMUNIDADEHPP
#define COMUNIDADEHPP

#include "common.hpp"

class comunidade{
public:
	static set<string> deputadosUsados;//ja estao em outras comunidades
	static set<string> empresasUsadas;//ja estao em outras comunidades

	int numArestas=0;
	double weight=0.0;

	set<string> deps;//deputados
	set<string> emps;//empresas
	comunidade(){};
	comunidade(string s);

	void insert(string s,bool isDep);

	static double calcQ();
	static void criaComunidades();
};

std::ostream& operator<<(std::ostream& os,const comunidade& c);

using mapComunidade=map<int,comunidade>;

#endif//COMUNIDADEHPP
