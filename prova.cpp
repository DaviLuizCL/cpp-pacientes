#include <iostream>
using namespace std;

//Criando o TIPO paciente
struct noPaciente {
    string nome;
    int idade;
    int cpf;
    int prioridade;
    noPaciente *prox;
};
//Inicia a lista encadiada 
void criar_lista(noPaciente *&inicio) {
    inicio = NULL;
}
//Verifica se tem gente na lista
bool vazia(noPaciente *inicio) {
    return inicio == NULL;
}
//coloca o cara respeitando a prioridade, se for maior ele coloca primeiro
void inserir(noPaciente *&inicio, string nome, int idade, int cpf, int prioridade) {
    noPaciente *novo = new noPaciente;
    novo->nome = nome;
    novo->idade = idade;
    novo->cpf = cpf;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if (inicio == NULL || prioridade > inicio->prioridade) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        noPaciente *atual = inicio;
        while (atual->prox != NULL && atual->prox->prioridade >= prioridade) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}
//remove o cara que ta no topo da pilha
void remover(noPaciente *&inicio) {
    if (inicio == NULL) {
        cout << "Erro: lista vazia\n";
    } else {
        noPaciente *aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }
}
//printa a lista
void exibir_lista(noPaciente *inicio) {
    noPaciente *atual = inicio;
    while (atual != NULL) {
        cout << "Nome: " << atual->nome << ", Idade: " << atual->idade << ", CPF: " << atual->cpf 
             << ", Prioridade: " << atual->prioridade << endl;
        atual = atual->prox;
    }
}

int main() {
    noPaciente *inicio;
    criar_lista(inicio);
    inserir(inicio, "João", 30, 123456789, 0);
    inserir(inicio, "Maria", 65, 987654321, 3);
    inserir(inicio, "Rosinei", 57, 192837465, 2);
    inserir(inicio, "Josesclaudo", 20, 192837465, 0);
    inserir(inicio, "Vlaudisvlando", 35, 192837465, 1);
    inserir(inicio, "Osório o legendário", 216, 192837465, 1000);



    cout << "Lista de pacientes:\n";
    exibir_lista(inicio);

    cout << "\nRemovendo o próximo paciente a ser atendido...\n";
    remover(inicio);
    exibir_lista(inicio);

    return 0;
}
