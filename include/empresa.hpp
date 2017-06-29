#ifndef EMPRESAHPP
#define EMPRESAHPP

#include "common.hpp"

class empresa{
public:
	//company_name,company_id
	string nomeEmpresa;
	int empresaID;
	double total=0.0;

	//Matriz adjacencia: Nome do Deputado
	set<string> clientes;

	empresa(){};
	empresa(const string &n,const int id);
};

std::ostream& operator<<(std::ostream& os,const empresa& e);

#endif//EMPRESAHPP
