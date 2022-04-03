#include<bits/stdc++.h>
 
/* Estrutura da arvore binaria com valor,
ponteiro para raiz esquerda e
ponteiro para raiz direita */
class raiz
{
    public:
    int valor;
    raiz* esq;
    raiz* dir;
     
    /* Construtor que aloca
    uma nova raiz com o valor informado
    e NULL para raiz esquerda e direita. */
	raiz(int valor) {
        this->valor = valor;
        this->esq = NULL;
        this->dir = NULL;
    }
};
 
int ehBinariaBusca(raiz* raiz, int min, int max);
 
/* Retorna true se a raiz informada
eh uma arvore binaria de busca */
int ehBinaria(raiz* raiz)
{
    return(ehBinariaBusca(raiz, INT_MIN, INT_MAX));
}
 
/* Retorna true se a raiz informada
eh uma arvore binaria de busca e seus valores
sao >= min e <= max. */
int ehBinariaBusca(raiz* raiz, int min, int max) {
    /* raiz vazia eh arvore binaria de busca */
    if (raiz==NULL){
    	return 1;
	}        
             
    /* falso se a raiz viola
    a validacao min/max */
    if (raiz->valor < min || raiz->valor > max) {
    	return 0;
	}        
     
    /* checa as subraizes recursivamente */
    return
        ehBinariaBusca(raiz->esq, min, raiz->valor-1) && // Permite apenas valores distintos
        ehBinariaBusca(raiz->dir, raiz->valor+1, max); // Permite apenas valores distintos
}
 
int main() {
    raiz *raiz1 = new raiz(4);
    raiz1->esq = new raiz(2);
    raiz1->dir = new raiz(5);
    raiz1->esq->esq = new raiz(1);
    raiz1->esq->dir = new raiz(3);
    raiz1->dir = new raiz(6); 
     
    if(ehBinaria(raiz1)) {
    	printf("Arvore eh Binaria de Busca.");
	}             
    else {
    	printf("Arvore nao eh Binaria de Busca.");
	}        
    return 0;
}
 
