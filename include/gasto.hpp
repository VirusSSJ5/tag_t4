#ifndef GASTOHPP
#define GASTOHPP

#include "common.hpp"

class gasto{
public:
	//refund_description,company_name,company_id,refund_date,refund_value
	string descricao;
	string nomeEmpresa;
	int empresaID;
	date dataGasto;
	double valorGasto;

	gasto(){};
	gasto(string d, string n, int id, date dg, double v);
};

std::ostream& operator<<(std::ostream& os,const gasto& e);

using mapGasto=map<int,gasto>;

#endif//GASTOHPP