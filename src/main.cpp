#include "common.hpp"

//OBS: Tratar 'aa' como uma letra 'a' craseada. Tratar 'eh' como uma letra 'e' com acento agudo.

int main(){
	
	//Cadeia de caracteres que armazena cada linha do arquivo csv lido
	string line;

	//Leitura do arquivo de planilha "dirty_deputies_v2.csv", com tratamento de erro
	ifstream file("dirty_deputies_v2.csv");
	if(!file.is_open()){
		cout << "Erro ao abrir arquivo \"dirty_deputies_v2.csv\", o programa ira encerrar agora" << endl;
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

	FOR2(i,1,338198){//ler 338198 linhas do csv
		getline(file,line);
		sscanf(line.c_str(),"%s,%s,%s,%s,%d,%s,%f",
			&deputados[i].nome,
			&deputados[i].estado,
			&deputados[i].partido,
			&deputados[i].descricao,
			&deputados[i].nomeEmpresa,
			&deputados[i].empresaID,
			&deputados[i].dataGasto,
			&deputados[i].valorGasto,
		);
	}

	getline(file,line);getline(file,line);getline(file,line);//ignora tres linhas de comentario + linha vazia

	FOR2(i,1,51){//ler 50 escolas
		getline(file,line);
		sscanf(line.c_str(),"(E%d):(%d)",&escolas[i].id,&escolas[i].preferencia);
	}

	file.close();

	// //printa de novo so para ver que leu direito
	// FOR2(i,1,101)cout << professores[i] << endl;cout << endl;
	// FOR2(i,1,51)cout << escolas[i] << endl;cout << endl;

	//Metodo principal do programa: o que encontra o pareamento perfeito entre professores e escolas
	achaPareamento(professores,escolas,pareamentoPE,pareamentoEP);

	
	//Impressao do resultado do pareamento
	for(auto p:pareamentoPE)cout << "Professor " << p.first << " pareado com escola " << p.second << endl;
	for(auto p:pareamentoEP)cout << "Escola " << p.first << " pareado com professores " << p.second.first << " e " << p.second.second << endl;

	return 0;
}