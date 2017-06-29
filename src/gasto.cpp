#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern unsigned double custoTotal;

void gasto::operator+=(const gastoIndividual &gi){
	// auto it = find(gastos.begin(), gastos.end(),gasto);
	// if(it != gastos.end())return;
	gastos.push_back(gi);
	valorTotal += gi.valor;
	if(gi.valor>0)custoTotal += gi.valor;
}

std::ostream& operator<<(std::ostream& os,const gasto& g){
	os = os << "\t(" << g.valorTotal << ":" << endl;
	for(auto &i:g.gastos)os = os << "\t\t(" << i.descricao << ", " << i.data << ", " << i.valor << ")" << endl;
	os = os << "\t)" << endl;
}
