#ifndef COMUNIDADEHPP
#define COMUNIDADEHPP

#include "common.hpp"

class comunidade{
public:
	int grau;
	comunidade();

	comunidades();
};

std::ostream& operator<<(std::ostream& os,const comunidade& c);

using mapComunidade=map<int,comunidade>;

#endif//COMUNIDADEHPP