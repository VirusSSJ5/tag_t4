#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

#define SUSPEITO 0.25

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;

double calcEntropia(deputado &dep){
	int N = dep.gastos.size();
	if(N == 1)return 1.0;

	int weight = dep.total;
	double sum = 0;
	for(auto &it:dep.gastos){
		double Pk = it.second.valorTotal/weight;
		sum += Pk * log10(1.0/Pk);
	}
	sum /= log10(N);
	return sum;
}

vector<pair<string,string>> anomalias(){
	vector<pair<string,string>> out;
	for(auto &pD:deputados){
		deputado d = pD.second;
		double er = calcEntropia(d);
		if(er < SUSPEITO){
			char doble[100];
			sprintf(doble,"%lf",er);
			char doble2[100];
			sprintf(doble2,"%.2lf",d.total);
			string s = "Deputado(a) " + d.nome + " gastou R$" + doble2 + " com " + to_string(d.gastos.size()) + " empresas.\n";
			out.push_back(pair<string,string>{d.nome,(string)"Fator de entropia " + doble + " suspeito.\n" + s});
		}
	}
	return out;
}
