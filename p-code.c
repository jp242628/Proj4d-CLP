#include <stdio.h>
#include <string.h>

int main() {
    char caractereLido;
    FILE *entrada, *saida;
    char operacaoLida[10];

    entrada = fopen("Entrada.txt", "r");
    saida = fopen("Saida.txt", "w");

    if (entrada == NULL) {
        printf("Erro ao abrir arquivo de entrada\n");
        return 1;
    }

    while (!feof(entrada)) {
        caractereLido = 'i';
        fscanf(entrada, "PUSH(%c)\n", &caractereLido);

        switch (caractereLido) {
            case 'a':
                fprintf(saida, "LOD 0 3\n");
                break;
            case 'b':
                fprintf(saida, "LOD 0 4\n");
                break;
            case 'c':
                fprintf(saida, "LOD 0 5\n");
                break;
            case 'd':
                fprintf(saida, "LOD 0 6\n");
                break;
            case 'e':
                fprintf(saida, "LOD 0 7\n");
                break;
        }

        strcpy(operacaoLida, "inf");
        fscanf(entrada, "y=POP(); x=POP(); PUSH(x %s y)\n", operacaoLida);

        if (strcmp(operacaoLida, "ADD") == 0) {
            fprintf(saida, "OPR 0 2\n");
        } else if (strcmp(operacaoLida, "SUB") == 0) {
            fprintf(saida, "OPR 0 3\n");
        } else if (strcmp(operacaoLida, "MUL") == 0) {
            fprintf(saida, "OPR 0 4\n");
        } else if (strcmp(operacaoLida, "DIV") == 0) {
            fprintf(saida, "OPR 0 5\n");
        }

        fscanf(entrada, "X = []\n");
    }

    fclose(entrada);
    fclose(saida);

    // Verifica se o arquivo de saída foi gerado corretamente
    saida = fopen("Saida.txt", "r");
        if (saida != NULL) {
            printf("Arquivo de saída gerado com sucesso\n");
            fclose(saida);
        } else {
            printf("Erro ao gerar o arquivo de saída\n");
        }

    return 0;
}
