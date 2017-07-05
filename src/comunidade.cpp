#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"
#include "comunidade.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;
extern vector<comunidade> comunidades;


set<string> comunidade::deputadosUsados;//ja estao em outras comunidades
set<string> comunidade::empresasUsadas;//ja estao em outras comunidades


comunidade::comunidade(string s){
	deps.insert(s);
	while(1){
		double best = calcQ();
		{
			string bestSTR = "";
			for(auto &it:empresas){
				if(empresasUsadas.count(it.first))continue;
				comunidade c = *this;
				insert(it.first,false,false);
				double q = calcQ();
				if(q > best){
					best = q;
					bestSTR = it.first;
				}
				*this = c;
			}
			if(!bestSTR.empty())insert(bestSTR,false);
		}
		{
			string bestSTR;
			for(auto &it:deputados){
				if(deputadosUsados.count(it.first));
				comunidade c = *this;
				c.insert(it.first,true,false);
				double q = c.calcQ();
				if(q > best){
					best = q;
					bestSTR = it.first;
				}
			}
			if(!bestSTR.empty())insert(bestSTR,true);
		}
		if(best == calcQ())break;
	}
}

void comunidade::insert(string s,bool isDep,bool mark){
	if(isDep){
		for(const string &emp:emps){
			if(deputados[s].gastos.count(emp)){
				numArestas++;
				weight += deputados[s].gastos[emp].valorTotal;
			}
		}
		deps.insert(s);
		if(mark)deputadosUsados.insert(s);
	}
	else{
		emps.insert(s);
		for(const string &dep:deps){
			if(deputados[dep].gastos.count(s)){
				numArestas++;
				weight += deputados[dep].gastos[s].valorTotal;
			}
		}
		if(mark)empresasUsadas.insert(s);
	}
}

void comunidade::criaComunidades(){
	for(auto &it:deputados){
		if(deputadosUsados.count(it.first))continue;
		comunidade c(it.first);
		if(c.deps.size() + c.emps.size() > 1)comunidades.push_back(c);
	}
}

double comunidade::calcQ(){
	double soma=0;
	for(comunidade &com:comunidades){
		for(const string &dep1:com.deps){
			for(const string &dep2:com.deps){
				if (dep1 != dep2) soma += ((deputados[dep1].total * deputados[dep2].total)/ (2 * custoTotal)) * (-1); //* mesmaComunidade(deputados[dep],empresas[emp]);
			}
			
			for(const string &emp2:com.emps){
				soma += deputados[dep1].gastos[emp2].valorTotal - ((deputados[dep1].total * empresas[emp2].total)/ (2 * custoTotal)); //* mesmaComunidade(deputados[dep],empresas[emp]);
			}
		}
		
		for(const string &emp1:com.emps){
			for(const string &dep2:com.deps){
				soma += deputados[dep2].gastos[emp1].valorTotal - ((empresas[emp1].total * deputados[dep2].total)/ (2 * custoTotal)); //* mesmaComunidade(deputados[dep],empresas[emp]);
			}
			
			for(const string &emp2:com.emps){
				if (emp1 != emp2) soma +=  (empresas[emp1].total * empresas[emp2].total)/ (2 * custoTotal) * (-1); //* mesmaComunidade(deputados[dep],empresas[emp]);
			}
		}
	}
	
	soma /= 2 * custoTotal;
	return soma;	
}
