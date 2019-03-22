#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    /*
    inicio();
    troco();
    odd_even();
    age();
    hours();
    estacao();
    estacao_switch();
    dados();
    */
    /*mes();*/
    /*soma();*/
    /*minimo();*/
    /*mmc();*/
    /*mdc();*/
    /*soma_digitos();*/
    /*bissextos();*/
    /*calendario();*/
    /*jogo_do_ze();*/
    /*bitz();*/

    /*-----VETORES----------*/
    int v1[]={1,2,3};
    int v2[]={4,5,6};
    int v3[3];
    int size=3;
    /*vetores(v1,v2,v3,size);*/
    /*impar();*/
    /*maximo();*/
    /*valores_distintos();*/
    /*division(10.0,4.0);*/
    /*media();*/
    /*segundo_grau();*/
    /*pitagoras();*/
    /*losango(21);*/


    /* FUNCOES  */
    /*cargos();*/
    /*ascii();*/
    /*eof();*/
    /*linhas();*/
    min2mas();
    return 0;
    }


/*
void inicio(){
    int idade,peso;
    printf("Idade e Peso: ");
    scanf("%d %d", &idade,&peso);
    printf("Ola o meu nome é Joao, tenho %d anos e peso %d",idade,peso);

    }

void troco(){
    int number,n50,r50,n20,r20,n10,r10,n5,r5,n2,r2;
    printf("Preço da Compra: ");
    scanf("%d",&number);

    n50=number/ 50;
    r50= number% 50;

    n20= r50 /20;
    r20= r50%20;

    n10=r20/10;
    r10=r20%10;

    n5 = r10/5;
    r5 = r10%5;

    n2 = r5/2;
    r2= r5%2;


    printf("%d %d %d %d %d %d ",n50,n20,n10,n5,n2,r2);

}

void odd_even(){

    int number1,number2,number3,final;
    printf("Gimme 3 numbers: ");
    scanf("%d %d %d",&number1, &number2,&number3);

    if (number1>=number2 && number1>=number3){
        printf("Number1 is bigger %d",number1);
    }
    else if (number2>=number1 && number2>=number3){
        printf("Number2 is bigger %d",number2);
    }
    else
        printf("Number3 is bigger %d",number3);


    if (number1%2 == 0 && number2%2 == 0){

        printf("Both even!");
        final= number1 + number2;
        printf("Final: %d",final);
        }
    else{
        printf("At least 1 of those is odd!");
        final = number1*number2 ;
        printf("Final: %d",final);
        }

 }


void age(){

    int age;
    printf("What's your age? ");
    scanf("%d",&age);
    if (age<=12)
        printf("Isento de pagamento");
    else if (age<=24)
        printf("Bilhete Raical");
    else if (age<=36)
        printf("Bilhete Light");
    else if (age<=48)
        printf("Bilhete Normal");
    else if (age<=60)
        printf("BIlhete Light");
    else
        printf("Isento de pagamento");

}


void hours(){

    int hours,minutes;
    printf("What time is it? ");
    scanf("%d:%d",&hours,&minutes);
    if (hours>12){
    hours = hours%12;
    printf("%d:%d PM",hours,minutes);
    }
    else
        printf("%d:%d AM",hours,minutes);

}

void estacao(){

    int day,month;
    printf("Day and Month: ");
    scanf("%d:%d",&day,&month);

    if (3<=month && 6>month)
        printf("Primavera");
    else if (6<=month && 9>month)
        printf("Verao");
    else if (9<=month && 12>month)
        printf("Outono");
    else
        printf("Inverno");

}


void dados(){

    int dado,i,soma;
    time_t seconds;
    seconds =time(NULL);
    srand(seconds);

    for (i=0;i<2;i++){
        dado=((rand() % 5)+1);
        soma =(dado*pow(-1,i));

    }

    printf("%d\n",(-soma));
    if (abs(soma)<2){
        printf("Inferior a 2");
    }
    else if (abs(soma)<4){
        printf("Inferior a 4");
    }
    else if (abs(soma)>=3){
        printf("Superior a 3");
    }

}


void mes(){
    int dia,mes;
    printf("Data ");
    scanf("%d:%d",&dia,&mes);

    switch (mes){
    case 1:
        printf("Janeiro");break;
    case 2:
        printf("Fevereiro");break;
    case 3:
        printf("Março");break;
    case 4:
        printf("Abril");break;
    case 5:
        printf("Maio");break;
    case 6:
        printf("Junho");break;
    case 7:
        printf("Julho");break;
    case 8:
        printf("Agosto");break;
    case 9:
        printf("Setembro");break;
    case 10:
        printf("Outubro");break;
    case 11:
        printf("Novembro");break;
    case 12:
        printf("Dezembro");break;

    default:
        printf("Mas és estupido ou que?");break;
    }
}

void acrescenta(){
    int n1,n2,n3,n4;
    int extra;
    printf("Numero de cartao: ");
    scanf("%c%c%c%c",&n1,&n2,&n3,&n4);
    if ((n1+n2+n3+n4)%2 ==1)
        extra=1;

    else
        extra=0;

    printf("%c%c%c%c%d",n1,n2,n3,n4,extra);
}

void cores(){
    int c1,c2,c3;
    printf("Bits: ");
    scanf("%c%c%c", &c1,&c2,&c3);
    if (c1==1){
        printf("Vermelho ");
    }
    if (c2==1){
        printf("Verde ");
    }
    if (c3==1){
        printf("Azul ");
    }
}

void dia_ano_mes(){
    int dia,mes,ano;
    printf("Dia/Mes/Ano: ");
    scanf("%d/%d/%d",&dia,&mes,&ano);

    if (dia==28 && mes==2){
        dia=1;
        mes=3;
    }
    else if (dia >=30){
        if (mes== 4 || mes == 6 || mes == 9 || mes == 11){
            dia=1;
            mes++;
        }
        else
            dia++;
    }
    else if (dia==31){
        if (mes==12){
            ano++;
        }
        else{
            dia=1;
            mes++;
        }
    }
    else{
        dia++;
    }
    printf("Dia Seguinte: %d/%d/%d",dia,mes,ano);
}


void soma_ate(){
    int number;int counter=0;
    printf("Queres uma cena estupida ate que numero? ");
    scanf("%d",&number);

    while (counter<number){
        counter++;
        printf("Puto... %d\n",counter);

    }
}


void soma(){
    int input;int number=1;int counter=0;
    printf("Que Numero Deseja? ",input);
    scanf("%d",&input);

    while (counter<input){
        counter+= number;
        number++;
    }
    printf("%d",counter);
}

void minimo(){
    int input,min,num; int counter=0;
    printf("Nº de Numeros: ");
    scanf("%d",&input);
    while (counter<input){
        printf("Numero: ");
        scanf("%d",&num);
        if (counter==0)
            min=num;
        else if (num<min)
            min=num;
        counter++;
    }
    printf("%d",min);

}

void mmc(){
    int num,other;int counter=0;
    printf("Numero: ");
    scanf("%d",&num);
    printf("Results: ");
    while (counter<4){
        other=num*counter;
        printf("%d ",other);
        counter++;
    }
}

void mmc2(){
    int maior,a,b;
    printf("Numeros: ");
    scanf("%d %d",&a,&b);

    if (a>=b)
        maior=a;
    else
        maior=b;

    while (!(maior%a==0 && maior%b==0)){
        printf("passing here\n");
        maior++;
    }
    printf("MMC: %d\n",maior);
}

void mdc(){
    int n1,n2,r;
    printf("Mdc(a,b): ");
    scanf("%d%d",&n1,&n2);
    while (n1%n2!=0){
        r=n1%n2;
        n1=n2;
        n2=r;
    }
    printf("Mdc: %d",n2);
}

void soma_digitos(){
    int input,num;int counter=0;int sum=0;
    printf("Nº de Numeros: ");
    scanf("%d",&input);
    while (counter<input){
        printf("Numero: ");
        scanf("%d",&num);
        counter++;
        sum=sum + num;
        }
    printf("Sum: %d",sum);
}

void bissextos(){
    int ano1,ano2,dif;int counter=0;

    printf("Anos: ");
    scanf("%d%d,",&ano1,&ano2);
    dif=ano1-ano2;

    while (counter<=dif){
        if ((ano2+counter)%4==0){
            printf("Ano Bissexto: %d\n",ano2+counter);
            }
        counter++;
    }
}

void calendario(){
    int ndias,dsem,i,j;
    printf("ndias: ");
    scanf("%d",&ndias);
    printf("1ºdia semana: ");
    scanf("%d",&dsem);
    printf(" D  S  T  Q  Q  S  S\n");
    for (i=1;i<dsem;i++){
        printf("   ");
    }

    for(j=1; j<=ndias; j++){
        if (j<10)
            printf("0%d ",j);
        else
            printf("%d ",j);
        if ((j+dsem-1)%7==0){
            printf("\n");
        }
    }
}

void jogo_do_ze(){
    int random,num;
    int tries=0;
    time_t seconds = time(NULL);
    srand(seconds);

    random=rand()%100;

    do{
    printf("Numero entre 0 e 99: ");
    scanf("%d",&num);
    tries++;
    if (num<random)
        printf("Maior!   Numero de tries: %d",tries);
    else if (num>random)
        printf("Mais Pequeno!   Numero de tries: %d",tries);
    else
        printf("Ganhou!   Numero de tries: %d",tries);
    printf("\n\n");
    }while(random!=num);
}

void bitz(){
    int number;
    int bit1=0;int bit0=0;
    int soma=0;int count=0;
    printf("Numero binario: ");
    scanf("%d",&number);

    while (number>0 ){
        if (number%2==1){
            bit1++;
            soma=soma+ pow(2,count);
        }
        else{
            bit0++;
        }
        number=number/10;
        count++;

    }
    printf("%d bits 1\n %d bits 0\nequivalente decimal:%d ",bit1,bit0,soma);

}

*/
