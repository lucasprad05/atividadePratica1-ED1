/*
 * @file: ED1-2022-1-AT01-ConversorD2B-LucasPrado.c
 * @date: 21 mar 2022
 * @author: Lucas Prado
 * @brief: Atividade Prática 01
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 50

typedef struct{
    int decimal[TAMANHO];
    int topo;
}PilhaDecimal;

void iniciaPilhaDecimal(PilhaDecimal *pilha);
void empilharPilhaDecimal(PilhaDecimal *pilha, char *argv[]);
void imprimePilhaDecimal(PilhaDecimal *pilha);
void converteBinario(PilhaDecimal *pilha, char *argv[]);

int main(int argc, char *argv[]){
    PilhaDecimal p;

    //iniciar Pilha
    iniciaPilhaDecimal(&p);

    //empilhar
    empilharPilhaDecimal(&p, &argv);

    //imprimir Pilha
    imprimePilhaDecimal(&p);

    //converteBinario
    converteBinario(&p, &argv);


    return 0;
}//main


void iniciaPilhaDecimal(PilhaDecimal *pilha){
    pilha->topo = -1;
    return;
}//iniciaPilhaDecimal

void empilharPilhaDecimal(PilhaDecimal *pilha, char *argv[]){
    FILE *arq1;
    arq1 = fopen(argv[1], "r");
    if(arq1 == NULL){
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    while(!feof(arq1)){
        pilha->topo++;
        fscanf(arq1,"%d",&pilha->decimal[pilha->topo]);
    }//while

    fclose(arq1);
    return;
}//empilharPilhaEstatica

void imprimePilhaDecimal(PilhaDecimal *pilha){
    printf("Pilha = [");
    for(int i = 0; i <= pilha->topo; i++){
        printf("%d ", pilha->decimal[i]);
    }//for
    printf("]\n");
    return;
}//imprimePilhaEstatica

void converteBinario(PilhaDecimal *pilha, char *argv[]){
    FILE *arq2;
    arq2 = fopen(argv[2], "w");
    if(arq2 == NULL){
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }//if

    int bin[8];
    int aux;
    int num;
    for(int i = 0; i<= pilha->topo; i++){
        num = pilha->decimal[i];
        for (aux = 8; aux >= 0; aux--){
            if(num % 2 == 0){
                bin[aux] = 0;
                num = num / 2;
            }else{
                bin[aux] = 1;
                num = num / 2;
            }//else
        }//for

        //exibir na tela e salvar no arquivo
        for (aux = 0; aux <= 8; aux++) {
            printf("%d", bin[aux]);
            fprintf(arq2, "%d", bin[aux]); //Comentar essa linha
        }//for
        printf("\n");
        fprintf(arq2, "\n"); //Comentar essa linha
    }//for

    fclose(arq2);
    return;
}//converteBinario
