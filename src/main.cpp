#include "common.hpp"
#include "deputado.hpp"
#include "empresa.hpp"
#include "gasto.hpp"

map<string,deputado> deputados;
map<string,empresa> empresas;
// map<string,set<string>> grupoDep;
// map<string,set<string>> grupoEmp;
// set<string> deputadosUsados;
// set<string> empresasUsadas;
double custoTotal;


//OBS: Tratar 'aa' como uma letra 'a' craseada. Tratar 'eh' como uma letra 'e' com acento agudo.

int main(){
	
	//Cadeia de caracteres que armazena cada linha do arquivo csv lido
	string line;

	//Leitura do arquivo de planilha "dirty_deputies_v2.csv", com tratamento de erro
	ifstream file("dirty_deputies_v3.csv");
	if(!file.is_open()){
		cout << "Erro ao abrir arquivo \"dirty_deputies_v3.csv\", o programa ira encerrar agora" << endl;
		return EXIT_FAILURE;
	}

	getline(file,line);//ignora a primeira linha de colunas da planilha

	//Variaveis temporarias para armazenar os seguintes valores das colunas, respectivamente:
	//deputy_name,deputy_state,political_party,refund_description,company_name,company_id,refund_date,refund_value
	string nome;
	string estado;
	string partido;
	string descricao;
	string nomeEmpresa;
	int empresaID;
	string dataGasto;
	double valorGasto;
	string temp;

	while(getline(file,line)){
		nome = estado = partido = descricao = nomeEmpresa = dataGasto = "[]";
		empresaID = -1;
		valorGasto = 0.0;

		std::stringstream ss(line);
		getline(ss,nome,';');
		getline(ss,estado,';');
		getline(ss,partido,';');
		getline(ss,descricao,';');
		getline(ss,nomeEmpresa,';');
		getline(ss,temp,';');empresaID=atoi(temp.c_str());
		getline(ss,dataGasto,'T');getline(ss,temp,';');
		getline(ss,temp,';');valorGasto=atof(temp.c_str());

		if(
			(nome=="[]") ||
			(estado=="[]") ||
			(partido=="[]") ||
			(descricao=="[]") ||
			(nomeEmpresa=="[]") ||
			(dataGasto=="[]") ||
			(empresaID==-1) ||
			(valorGasto==0.0)
		){
			cerr << "Linha '" << line << "' fora do padrão esperado." << endl;
			continue;
		}


		//
		valorGasto = abs(valorGasto);

		//Atribui os valores lidos em nodos do grafo
		deputados[nome].nome = nome;
		deputados[nome].estado = estado;
		deputados[nome].partido = partido;

		empresas[nomeEmpresa].nomeEmpresa = nomeEmpresa;
		empresas[nomeEmpresa].empresaID = empresaID;

		gastoIndividual gi{descricao, dataGasto, valorGasto};
		deputados[nome]+=pair<gastoIndividual,string>{gi,nomeEmpresa};

		// if(!deputadosUsados.count(nome)){
		// 	grupoDep[estado].insert(nome);
		// 	deputadosUsados.insert(nome);
		// }
		// if(!empresasUsadas.count(nomeEmpresa)){
		// 	grupoEmp[descricao].insert(nomeEmpresa);
		// 	empresasUsadas.insert(nomeEmpresa);
		// }
	}

	file.close();


	cout << "numero de grupos de deputado: " << grupoDep.size() << endl;
	for(auto &i:grupoDep){
		cout << i.first << endl;
	}
	cout << endl;
	cout << "numero de grupos de empresa: " << grupoEmp.size() << endl;

	// //printa de novo so para ver que leu direito
	// FOR2(i,1,101)cout << professores[i] << endl;cout << endl;
	// FOR2(i,1,51)cout << escolas[i] << endl;cout << endl;

	//Metodo principal do programa: o que encontra anomalias no grafo
	

	
	//Impressao do resultado do pareamento
	// for(auto p:pareamentoPE)cout << "Professor " << p.first << " pareado com escola " << p.second << endl;
	// for(auto p:pareamentoEP)cout << "Escola " << p.first << " pareado com professores " << p.second.first << " e " << p.second.second << endl;

	return 0;
}
