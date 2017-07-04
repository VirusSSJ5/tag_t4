#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;

gastoIndividual::gastoIndividual(const string &des,const string &date,const double &val){
	descricao = des;
	data = date;
	valor = val;
}


void gasto::operator+=(const gastoIndividual &gi){
	// auto it = find(gastos.begin(), gastos.end(),gasto);
	// if(it != gastos.end())return;
	gastos.push_back(gi);
	valorTotal += gi.valor;
	custoTotal += gi.valor;
}

std::ostream& operator<<(std::ostream& os,const gasto& g){
	os << "\t(" << g.valorTotal << ":" << endl;
	for(auto &i:g.gastos)os << "\t\t(" << i.descricao << ", " << i.data << ", " << i.valor << ")" << endl;
	os << "\t)" << endl;
	return os;
}
