/* Data de submissao:
 * Nome: Ian Goulart Doretto 
 * RA: 174827
 */

#include <stdio.h>

#define TAM_PILHA 100
const int tam_buffer=100;


typedef struct {
  char dados[TAM_PILHA];
  int n;
} pilha, *Pilha;

void pilha_init(Pilha p) {
  p->n = 0;
}

void push(Pilha p, char c) {
/* Insere caractere c na pilha */
  if (p->n < 10) {
    p->dados[p->n]=c;
    (p->n)++;
  }
}

char pop(Pilha p) {
/* Remove caractere do topo da pilha */
  char c;
  if ((p->n)>0) {
    (p->n)--;
    c = p->dados[p->n];
  }
  return c;
}

int main() {
	
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);

	//cria a pilha
  pilha pilha_aux;

  int i, fim_buffer;
  char c[2];
  
	//a variável fim_buffer determina quando o texto de entrada acaba
	for(i=0; i<tam_buffer; i++) {
		if(buffer[i]=='\n')
			fim_buffer=i;
	}

	//inicializa a pilha
  pilha_init(&pilha_aux);

	//looping de inversão das palavras
  for(i=0; i<fim_buffer; i++) {
    if(buffer[i]==' ') {
      while(pilha_aux.n!=0) {
        c[0]=pop(&pilha_aux);
				c[1]='\0';
        printf("%s", c);
      }
			printf(" ");
    } else {
			c[0]=buffer[i];
      push(&pilha_aux, c[0]);
    }
  }

	//inverte a palavra final
	while(pilha_aux.n!=0) {
		c[0]=pop(&pilha_aux);
		c[1]='\0';
		printf("%s", c);
  }
  
  printf("\n");
 
  return 0;
}

