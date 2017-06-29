#ifndef DEPUTADOHPP
#define DEPUTADOHPP

#include "common.hpp"
#include "gasto.hpp"

class deputado{
public:
	//deputy_name,deputy_state,political_party
	string nome;
	string estado;
	string partido;

	double total;

	//nome da empresa,gasto
	map<string,gasto> gastos;

	deputado(){};
	deputado(const string &n,const string &e,const string &p);
	void operator+=(const pair<gastoIndividual,string> &in);
};

std::ostream& operator<<(std::ostream& os,const deputado& d);

#endif//DEPUTADOHPP
