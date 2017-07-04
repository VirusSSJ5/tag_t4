#ifndef GASTOHPP
#define GASTOHPP

#include "common.hpp"

struct gastoIndividual{
	string descricao;
	string data;
	double valor;
	gastoIndividual(const string &des,const string &date,const double &val);
};

class gasto{
public:
	double valorTotal;
	vector<gastoIndividual> gastos;

	void operator+=(const gastoIndividual &gi);
};

std::ostream& operator<<(std::ostream& os,const gasto& g);

#endif//GASTOHPP
