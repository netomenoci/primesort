#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 200010


int entrada[MAX];
int nprimos[MAX];

int main() {
  int aux,i,tam_nprimos;
  int counter = 0;
 
  for(i=0; i<MAX; i++){
    entrada[i] = -1;
    nprimos[i] = -1;
  }
  for(counter=0; counter<MAX; counter++){
    scanf("%d", &aux);
    if(aux == -1){
      break;
    }
    entrada[counter] = aux;
  }
  for(i=0; i<10; i++){
    //printf("A entrada %d é: %d \n",i, entrada[i]);
  }  
  tam_nprimos = encontra_primos(counter);
  ordena_numeros(tam_nprimos);
}

int encontra_primos(int tam_vetor){
  int i,j,aux; // aux eh o numero de divisores de um numero
  int k = 0; // k sera o tamanho do vetor nprimos
  for(i=0; i<tam_vetor; i++){ //faz um loop entre os numeros do input
    if(entrada[i] == 2){  // supoe que todo numero eh divisivel por 1 e por ele mesmo
      aux = 1;
    }else aux = 2;
    if(entrada[i] == 1){
      aux = 3;
    }  
    //printf("A entrada atual é: %d \n", entrada[i]);
    for(j=2;( (j <= ceil(sqrt(entrada[i]))) && (aux < 4) ); j++){
      //printf("O j, div atual, é: %d \n", j);
      if( (entrada[i] % j) == 0 ){
	aux++ ; //o numero nao e primo
	//printf("aux aumentou para %d \n", aux);
      }
    }
    if(aux > 2){
      nprimos[k] = entrada[i];
      //printf("%d nao eh primo \n", nprimos[k]);
      k++;
    }  
  }
  return k;
}
int compara(const void *argumento1, const void *argumento2){
 return (* (int*) argumento2-*(int*) (argumento1));
}

void ordena_numeros(int tam_vetor){
    qsort(nprimos, tam_vetor, sizeof(int), compara);
    int i;
//  int i,j,aux;
//  for(i=0; i<(tam_vetor-1); i++){
//    for(j=0; j<(tam_vetor-1); j++){
//      if(nprimos[j] < nprimos[j+1]){
//	aux = nprimos[j];
//	nprimos[j] = nprimos[j+1];
//	nprimos[j+1] = aux;
//     }
//  }  
//  }  
  
  for(i=0; i<tam_vetor; i++)
    printf("%d\n", nprimos[i]);
  
}
