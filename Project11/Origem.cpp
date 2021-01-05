#include<stdio.h>
#include<stdlib.h>


// FUNÇOES //


void digQuantMxN();
void digDadosMatriz();
void imprimirMatriz();
void mostraOcorrenciaCaracteres();
void manipulaDado();



// VARIÁVEIS//


int i, j, k, m, n, c, x, indice, cont;
float pri, resultado;
char str[10][10], vetor[100], aux;




// FUNÇÃO PRINCIPAL //


int main() {
	digQuantMxN();
	printf("\n\n");
	digDadosMatriz();
	printf("\n");
	imprimirMatriz();
	printf("\n\n");
	mostraOcorrenciaCaracteres();
	printf("\n\n");
	manipulaDado();
	printf("\n\n");
	system("pause");
	return 0;
}


// DIGITAR LINHAS DE COLUNAS//


void digQuantMxN() {
	do {
		// INSTRUÇÕES USUÁRIO //


		printf(" \n\n Digite a quantidade de linhas de 1 a 10: ");
		scanf_s("%d", &m);  // ARMARZENAR DADOS VARIAVEL//
		while ((c = getchar()) != '\n' && c != EOF) {}
	} while (m < 1 || m > 10); // VALIDAÇÃO 1 A 10 //
	do {
		// IMPRIME INSTRUÇÕES USUÁRIO //
		printf(" \n\n Digite a quantidade de colunas de 1 a 10: ");
		scanf_s("%d", &n);
		while ((c = getchar()) != '\n' && c != EOF) {} // LIMPA BUFFER //
	} while (n < 1 || n > 10);
}
// CARREGAR DADOS MATRIZ //


void digDadosMatriz() {
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// POSIÇÃO MATRIZ //
			printf(" Digite o caracter [%d] [%d]: ", i, j);
			scanf_s("%c", &str[i][j]); // ARMAZENA O DADO DIGITADO PELO USUÁRIO E ARMAZENA NA VARIAVEL //
			while ((c = getchar()) != '\n' && c != EOF) {} // LIMPA BUFFER //
		}
	}
}


// IMPRIME DADOS DA MATRIZ //



void imprimirMatriz() {


	// IMPRIME MENSAGEM PARA USUARIO //


	printf(" Matriz formada MxN.\n");
	for (i = 0; i < m; i++) {
		printf(" \n");

		// IMPRIME VALOR DA MATRIZ //

		for (j = 0; j < n; j++) {
			printf(" %c\t", str[i][j]);
		}
	}
}
// OCORRENCIAS CARACTERES //

void mostraOcorrenciaCaracteres() {

	indice = 0; // INICIA A VARIAVEL EM 0 //

	// TRANSFORMA A MATRIZ EM VETOR //

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			vetor[indice] = str[i][j];
			indice++;
		}
	}
	for (i = 0; i < indice; i++) {
		for (j = i + 1; j < indice; j++) {
			if (vetor[i] > vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	cont = 1; // SE ESTIVER NA LISTA APARECE 1 VEZ //

	for (i = 1; i < indice; i++) {

		if (vetor[i] == vetor[i - 1]) { // SE É IGUAL AO ANTERIOR INCREMENTA O CONTATOR //
			cont++;

		}
		else { // SE MUDOU O NÚMERO //

			if (cont >= 2) {

				printf(" O caracter %c aparece %d vezes!\n", vetor[i - 1], cont);

				cont = 1;
			}
			else {

				printf(" O caracter %c aparece %d vez!\n", vetor[i - 1], cont);

				cont = 1;
			}
		}
	}
	if (cont >= 2) {

		// IMPRIME O ÚLTIMO NÚMERO //
		printf(" O caracter %c aparece %d vezes!\n", vetor[i - 1], cont);
	}
	else {

		printf(" O caracter %c aparece %d vez!\n", vetor[i - 1], cont);
	}
}
// MANIPULA O PRIMEIRO DADO DA MATRIZ //


void manipulaDado() {


	// IMPRIMI INFORMAÇÕES AO USUÁRIO //


	pri = str[0][0];
	printf(" O primeiro caracter da matriz = \"%c\" \n", str[0][0]);
	if ((pri >= 65) && (pri <= 90)) {
		printf(" O caracter \"%c\" eh uma letra maiusculo", str[0][0]);
		resultado = pri / 10;
		printf("\n A funcao pedida para esse tipo de caracter resulta em: %.1f ", resultado);
	}
	else {
		printf(" O caracter \" %c \" eh uma letra minuscula", str[0][0]);
		resultado = pri * 2;
		printf("\n A funcao pedida para esse tipo de caracter resulta em: %.0f ", resultado);
	}
}
