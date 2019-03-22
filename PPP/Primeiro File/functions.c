#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargos(){
    char letra;
    printf("Letra: ");
    scanf("%c",&letra);

    if (letra=='C')
    printf("Chefe");
    else if (letra=='o')
    printf("operario");
    else if (letra=='i')
    printf("inspetor");
    else if (letra=='o')
    printf("mecanico");
    else
    printf("...");
}

void ascii(){
    int i=32;
    for(i;i<129;i++){
        printf("%c  ", i);
    }
}

void eof(){
    int sum=0;
    printf("Frase: ");
    while (getchar()!=EOF){
        sum++;
    }
    printf("%d",sum);
}

void linhas(){
    int sum=0;
    while (getchar()!=EOF) {
        if (getchar()=='\n'){
            sum++;
        }
    }
    printf("%d",sum);
}

void min2mas(){
char linha[20];
printf("Linha para conversao: ");
fgets(linha,20,stdin);
read(strupr(linha),strlen(linha));
}
