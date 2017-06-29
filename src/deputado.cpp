#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern unsigned double custoTotal;

deputado::deputado(const string &n,const string &e,const string &p):nome{n},estado{e},partido{p}{}

void deputado::operator+=(const pair<gasto::gastoIndividual,string> &in){
	gastos[in.second].insert(in.first);
	empresas[in.second].gastos[nome].insert(in.first);
}

std::ostream& operator<<(std::ostream& os,const deputado& g){
	os = os << "\t(" << g.valorTotal << ":" << endl;
	for(auto &i:g.deputados)os = os << "\t\t(" << i.descricao << ", " << i.data << ", " << i.valor << ")" << endl;
	os = os << "\t)" << endl;
}
