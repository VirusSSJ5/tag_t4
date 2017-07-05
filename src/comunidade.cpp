#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;
extern set<comunidade> comunidades;


set<string> comunidade::deputadosUsados;//ja estao em outras comunidades
set<string> comunidade::empresasUsadas;//ja estao em outras comunidades


comunidade::comunidade(string s){
	deps.insert(s);
	while(1){
		double best = calcQ();
		{
			auto bestIT = empresas.end();
			for(auto &it:empresas){
				if(empresasUsadas.count(it->first))continue;
				comunidade c = *this;
				c.insert(it.first,false);
				double q = c.calcQ();
				if(q > best){
					best = q;
					bestIT = it;
				}
			}
			if(bestIT != empresas.end())insert(bestIT->first);
		}
		{
			auto bestIT = deputados.end();
			for(auto &it:deputados){
				if(deputadosUsados.count(it.first));
				comunidade c = *this;
				c.insert(it.first,true);
				double q = c.calcQ();
				if(q > best){
					best = q;
					bestIT = it;
				}
			}
			if(bestIT == deputados.end())insert(bestIT->first);
		}
		if(best = calcQ())break;
	}
}

comunidade comunidade::insert(string s,bool isDep){
	if(isDep){
		for(string &emp:emps){
			if(deputados[s].gastos.count(emp)){
				numArestas++;
				weight += deputados[s].gastos[emp].valorTotal;
			}
		}
		deps.insert(s);
	}
	else{
		emps.insert(s);
		for(string &dep:deps){
			if(deputados[dep].gastos.count(s)){
				numArestas++;
				weight += deputados[dep].gastos[s].valorTotal;
			}
		}
	}
}

void comunidade::criaComunidades(){
	for(auto &it:deputados){
		if(deputadosUsados.count(it.first))continue;
		comunidades.emplace_back(it.first);
	}
}

double comunidade::calcQ(){}
