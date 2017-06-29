#ifndef GASTOHPP
#define GASTOHPP

#include "common.hpp"

class gasto{
public:
	struct gastoIndividual{
		string descricao;
		string data;
		double valor;
	}
	double valorTotal;
	vector<gastoIndividual> gastos;

	void operator+=(const gastoIndividual &gi);
};

std::ostream& operator<<(std::ostream& os,const gasto& g);

using mapGasto=map<int,gasto>;

#endif//GASTOHPP
