#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *initVet (int *size, int *maxSize);
void printVet (int *v, int size, int maxSize);
int *addVet(int *v, int *size, int *maxSize, int e);
int find (int *v, int size, int e);
int *removeVet (int *v, int *size, int *maxSize, int e);

int main()
{
	setlocale(LC_ALL, "portuguese");

    int tamanho_alocado = 4, elementos = 0,
        *v, find_res, opcao, valor;

    v = initVet(&elementos, &tamanho_alocado);

    do {
        system("cls");
        printf("Programa criador de vetor\n");
        printf("Digite 1 para inserir dado no vetor\n");
        printf("Digite 2 para procurar dado do vetor\n");
        printf("Digite 3 para remover dado do vetor\n");
        printf("Digite 4 para imprimir o vetor\n");
        printf("Sua escolha é: \n\n");
        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1: printf("Digite o valor para inserir no vetor: ");
                    scanf("%d", &valor);
                    v = addVet(v, &elementos, &tamanho_alocado, valor);
                    getchar();
                    break;

            case 2: printf("Digite o valor para procurar no vetor: ");
                    scanf("%d%*c", &valor);
                    find_res = find(v, elementos, valor);
                    getchar();
                    break;

            case 3: printf("Digite o valor para remover do vetor: ");
                    scanf("%d%*c", &valor);
                    v = removeVet(v, &elementos, &tamanho_alocado, valor);
                    getchar();
                    break;

            case 4: printVet(v, elementos, tamanho_alocado);
                    getchar();
                    break;
        }
    } while (opcao != 0);

    free(v);

    return 0;
}

int *initVet (int *size, int *maxSize) {
    int *v;
    v = calloc(*maxSize, sizeof(int *));

    printf("Vetor criado!\n");

    return v;
}

void printVet (int *v, int size, int maxSize) {
    printf("\nImprimindo vetor: \n");
	int i;

	if (size > 0) {
		for (i = 0; i <= maxSize; i++) {
       		printf("%d", v[i]);
		    if (i <= maxSize - 1) {
		        printf(", ");
			}
    	}
	} else {
        printf("O Vetor não possui elementos.");
	}

    printf("\n\n");
}

int *addVet(int *v, int *size, int *maxSize, int e) {
    printf("Adicionando elemento %d ao vetor.\n", e);
	int i;

	if (*size > *maxSize) {
        printf("\nVetor cheio, precisa expandir.\n");

        *maxSize = 2*(*maxSize);

        v = realloc(v, *maxSize);

        for (i = 0; i <= *maxSize; i++) {
            if (v[i] == 0) {
                v[i] = e;
                (*size)++;

                break;
            }
        }
    } else {
        for (i = 0; i <= *maxSize; i++) {
            if (v[i] == 0) {
                v[i] = e;
                (*size)++;

                break;
            }
        }
    }

    return v;
}

int find (int *v, int size, int e) {
	//printf("Buscando elemento %d ao vetor.\n", e);
	int contagem, encontrado = 0;

	for (contagem = 0; contagem <= size; contagem++) {
		if (v[contagem] == e) {
            printf("Elemento %d ao encontrado na posição %d.\n", e, contagem);
			return contagem;
		}
	}

	printf("O elemento não existe.\n");
	return -1;
}

int *removeVet (int *v, int *size, int *maxSize, int e) {
	int pos, tam, contagem, antigoMax;

	pos = find(v, *size, e);

	if (*size < (*maxSize)/4) {
        int i, j, *v2, i2;
        printf("\nVetor possui poucos elementos, precisa diminuir.\n");

        antigoMax = *maxSize;
        *maxSize = (*maxSize)/2;

        v2 = realloc(v, *maxSize);
        if (pos == -1) {
            printf("Elemento não existe no vetor, impossível remover.\n");

            return v;
        } else {
            v[pos] = NULL;
            printf("Elemento %d removido no vetor.\n", e);

            (*size)--;
        }

        return v2;
    } else {
        if (pos == -1) {
            printf("Elemento não existe no vetor.\n");

            return v;
        } else {
            v[pos] = NULL;
            printf("Elemento %d removido no vetor.\n", e);

            (*size)--;
        }

        return v;
    }
}
