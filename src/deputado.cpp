#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;

deputado::deputado(const string &n,const string &e,const string &p):nome{n},estado{e},partido{p}{}

void deputado::operator+=(const pair<gastoIndividual,string> &in){
	gastos[in.second] += in.first;
	empresas[in.second].clientes.insert(nome);
	empresas[in.second].total += in.first.valor;
	total += in.first.valor;
}

std::ostream& operator<<(std::ostream& os, const deputado& obj){
	return os/* << obj.nome << " " << obj.estado << " " << obj.partido << ": Gasto R$" << obj.total << " em " << obj.gastos << " empresas." << endl*/;
}
