#include <stdio.h>
#include <stdlib.h>

// protótipos
int Fat(int N);
int combinacao(int N, int K);
int arranjo(int N, int K);

// ESCOPO: GLOBAL
int main(void) {
  int N, K, C, A;
  int opcao = 1;
  while(opcao == 1){
    printf("MENU\n");
    printf("[1]: Usar a Calculadora\n");
    printf("[]: Sair: Qualquer Tecla\n");
    printf("Sua opcao: ");scanf("%i", &opcao);
    if(opcao == 1){
      printf("N (N >= 0): ");scanf("%i", &N);
      printf("K (K >= 0): ");scanf("%i", &K);
      if(N < 0 || K < 0 || N < K){
        printf("ERRO: Escolha de novo.\n");}
      else{
        printf("DADOS DOS CÁLCULOS:\n");
        printf("Fatorial (N = %i): %i\n", N, Fat(N));
        printf("Fatorial (K = %i): %i\n", K, Fat(K));
        printf("COMBINAÇÃO (%i, %i): %i\n", 
          N, K, combinacao(N, K));
        printf("ARRANJO (%i, %i): %i\n", 
          N, K, arranjo(N, K));
      }
    }
    else break;
  }
  return 0;
}

// funções:
// ESCOPO: LOCAL
int Fat(int N){
  int F = 1, C;
  if (N <= 1)
    return 1;
  for(C = 2; C <= N; C++)
    F *= C;
  return F;    
}

int combinacao(int N, int K){
  int C;
  C = arranjo(N, K) / Fat(K);
  return C;
}

int arranjo(int N, int K){
  int A;
  A = Fat(N) / Fat(N - K);
  return A;
}