#ifndef DEPUTADOHPP
#define DEPUTADOHPP

#include "common.hpp"
#include "gasto.hpp"

class deputado{
public:
	//////////////////////////////////////////////////////////////////////////
	///	Variáveis referentes às colunas da planilha:
	///	deputy_name,deputy_state,political_party
	//////////////////////////////////////////////////////////////////////////
	string nome;
	string estado;
	string partido;

<<<<<<< HEAD
	//////////////////////////////////////////////////////////////////////////
	///	Relacionamento (aresta) com as empresas
	///	Nome da empresa,gasto
	//////////////////////////////////////////////////////////////////////////
	map<string,gasto> gastos;

	//////////////////////////////////////////////////////////////////////////
	///		@param &n Nome do deputado
	///		@param &e Nome do estado
	///		@param &p Nome do partido
	///		@brief Construtor
	///		
	///		Construtor da classe. Deve receber os parâmetros referentes ao nome, estado e partido
	//////////////////////////////////////////////////////////////////////////
	deputado(const string &n,const string &e,const string &p);

	//////////////////////////////////////////////////////////////////////////
	///		@param &in Gasto novo a ser adicionado
	///		@brief "Adiciona" um gasto ao deputado
	///		
	///		Insere um gasto novo como a aresta do grafo
	//////////////////////////////////////////////////////////////////////////
	void operator+=(const pair<gasto::gastoIndividual,string> &in);
=======
	double total;

	//nome da empresa,gasto
	map<string,gasto> gastos;

	deputado(){};
	deputado(const string &n,const string &e,const string &p);
	void operator+=(const pair<gastoIndividual,string> &in);
>>>>>>> 1be9f5d79cc39aa40054b769b1f3d1db5dda4326
};

//////////////////////////////////////////////////////////////////////////
///		@param os Local da impressão
///		@param d Deputado
///		@brief Imprime o deputado
///		
///		Imprime os dados do deputado na tela
//////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os,const deputado& d);

#endif//DEPUTADOHPP
