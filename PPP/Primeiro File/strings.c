#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void read(char v[],int size){
    int i;
    printf("Vetor: ");
    for (i=0;i<size;i++){
        printf("%c",v[i]);
    }
    printf("\n");
}

void min2mas(){
char linha[20];
printf("Linha para conversao: ");
fgets(linha,20,stdin);
read(strupr(linha),strlen(linha));
}
