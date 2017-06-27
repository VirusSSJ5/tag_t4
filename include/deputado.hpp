#ifndef DEPUTADOHPP
#define DEPUTADOHPP

#include "common.hpp"

class deputado{
public:
	//deputy_name,deputy_state,political_party
	string nome;
	string estado;
	string partido;

	deputado(){};
	deputado(string n, string e, string p);

};

std::ostream& operator<<(std::ostream& os,const deputado& e);


using mapDep=map<int,deputado>;

#endif//DEPUTADOHPP