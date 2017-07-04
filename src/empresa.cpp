#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

extern map<string,deputado> deputados;
extern map<string,empresa> empresas;
extern double custoTotal;

empresa::empresa(const string &n,const int id):nomeEmpresa{n},empresaID{id}{}

std::ostream& operator<<(std::ostream& os,const empresa& g){
	return os << "(" << g.nomeEmpresa << " " << g.empresaID << ": Lucro de R$" << g.total << " com " << g.clientes.size() << " clientes." << ")" << endl;
}
