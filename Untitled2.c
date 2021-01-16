//nome: Paulo Manoel Gonçalves de Lima – prontuário: gu3003388 – Turma: xx.
//nome: xxxxxxxxxxxxx – prontuário: guxxxxxx – Turma: xx.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct conta{
    int idconta;
    int tipoconta;
    char nomecliente[60];
    float saldoconta;
};

int main(){

    int i, qtd;
    int *n;

    printf("\n================ Onzeneiro Bank ================\n\n\n\n");
    printf("Criacao de conta\n\n");
    printf("Por favor, inserir a quantidade de contas a ser criada:");
    scanf("%d", &qtd);

    //int *n = (struct conta*) malloc(sizeof(struct conta));

    //if(n == NULL){
    //    printf("Erro: Sem memoria! \n");
    //    exit(1);
    //}

    n = &qtd;

    struct conta contas[*n];

    preenche(contas, n);

    exibe(contas, n);
    system("PAUSE");

}


void preenche(struct conta contas[], int *n){
    int i;
        for(i = 0; i < *n; i++){
        printf("\nCadastro da Conta [%d]\n\n", i+1);

        printf("Id Numero da conta [%d]: ", i+1);
        scanf("%d", &contas[i].idconta);

        printf("Nome do Cliente [%d]: ", i+1);
        getchar();
        fgets(contas[i].nomecliente, 60, stdin);
        fflush(stdin);

        printf("Tipo de Conta do cliente [%d]: ", i+1);
        printf("\nPara Conta Corrente digite 1\nPara Conta Poupanca digite 2\n");

        do
        {
            scanf("%d", &contas[i].tipoconta);
            if(contas[i].tipoconta <1 || contas[i].tipoconta >2){
                printf("Por favor inserir o tipo de conta corretamente!\n");
            }
        }while(contas[i].tipoconta < 1 || contas[i].tipoconta > 3);

        printf("Saldo da conta [%d] R$: ", i+1);
        scanf("%f", &contas[i].saldoconta);

        printf("\n=========================================\n");
    }
}

void exibe(struct conta contas[], int *n){
    int i;
        for(i = 0; i < *n; i++){

            printf("\nId Numero da conta     [%d]: %d", i+1, contas[i].idconta);
            printf("\nNome do Cliente        [%d]: %s", i+1, contas[i].nomecliente);
            if(contas[i].tipoconta == 1){
                printf("Tipo de conta cliente  [%d]: Conta Corrente", i+1);
            }else if(contas[i].tipoconta == 2){
                printf("Tipo de conta cliente  [%d]: Conta Poupanca", i+1);
            }
            printf("\nSaldo da conta cliente [%d]: R$%.2f", i+1, contas[i].saldoconta);
            printf("\n\n=========================================\n");
        }
}
