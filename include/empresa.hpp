#ifndef EMPRESAHPP
#define EMPRESAHPP

#include "common.hpp"

class empresa{
public:
	//company_name,company_id
	string nomeEmpresa;
	int empresaID;

	//Matriz adjacencia: Nome do Deputado, gasto
	map<string,gasto> gastos

	empresa(){};
	empresa(string n, int id);
};

std::ostream& operator<<(std::ostream& os,const empresa& e);

using mapEmpresa=map<int,empresa>;

#endif//EMPRESAHPP