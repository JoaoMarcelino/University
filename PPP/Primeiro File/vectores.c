
void read123(char v[],int size){
    int i;
    printf("Vetor: ");
    for (i=0;i<size;i++){
        printf("%c",v[i]);
    }
    printf("\n");
}

int Ninteiros(int v[], int N){
    int conta=0,c;
    printf("Introduza ate %d inteiros: ",N);
    while (conta<N && scanf("%d",&c)==1){
        v[conta++]=c;
    }
    return conta;
}


/*

void vetores(int vec1[],int vec2[],int vec3[],int size){
    int i;
    read(vec1,size);
    printf("\n");
    read(vec2,size);
    printf("\n");
    for (i=0;i<size;i++){
        vec3[i]=vec1[i]+vec2[i];
        }
    read(vec3,size);
}

void impar(){
    int i;int size;

    printf("Size: ");
    scanf("%d",&size);

    int v[size];

    for (i=0;i<size;i++){
        printf("Print Numero %d: ",i);
        scanf("%d",&v[i]);
    }
    for (i=0;i<size;i++){
        if (v[i]%2==1){
            v[i]=v[i]*2;
        }
    }
    read(v,size);
}

void scan_vec(int v[],int size){
    int i;
    for (i=0;i<size;i++){
        printf("Print Numero %d: ",i+1);
        scanf("%d",&v[i]);
    }
}

int max(int v[],int size){
    int maior=0;
    int i;
    for (i=0;i<size;i++){
        if (v[i]>=maior){
            maior=v[i];
        }
    }
    return maior;
}
void maximo(){
    int size;int maior;
    printf("Size: ");
    scanf("%d",&size);

    int v[size];
    scan_vec(v,size);
    maior=max(v,size);
    printf("Maior: %d",maior);
}

void valores_distintos(){
    int size, n,i,j,c,novo=0;
    printf("Size: ");
    scanf("%d",&size);

    int v[size];
    for (i=0;i<size;i++){
        printf("Print Numero %d: ",i+1);
        scanf("%d",&n);
        c=0;
        for (j=0;j<i;j++){
            if (n!=v[j])
                c++;

        }
        if (c==i){
            v[novo]=n;
            novo++;
        }
    }
    read(v,novo);
}





int min(int v[],int size){
    int menor;
    int i;
    for (i=0;i<size;i++){
        if (i==0)
            menor=v[i];
        if (v[i]<=menor){
            menor=v[i];
        }
    }
    return menor;
}



void shell(){
    int size;

      1
    printf("Size: ");
    scanf("%d",&size);

     2
    int v[size];
    scan_vec(v,size);

      3
    read(v,size);

      4
    int maior;
    maior=max(v,size);
    printf("Maior: %d\n",maior);

    5
    int menor;
    menor=min(v,size);
    printf("Menor: %d\n",menor);

     6

}


  Funcoes

void division(float x, float y){
    float z;
    z=x/y;
    printf("%f",z);
}


void media(){
    int a,b,c;
    float sum=0;
    printf("Numeros: ");
    scanf("%d%d%d",&a,&b,&c);
    sum=(a+b+c)/3.0;
    printf("%f",sum);
}

void segundo_grau(){
    int a,b,c;
    float raiz;
    float y1,y2;

    printf("Numeros: ");
    scanf("%d%d%d",&a,&b,&c);


    raiz= pow(b,2) - 4*a*c;
    if (raiz<0){
        printf("F-O-D-A---S-E");
    }
    else{
        y1=(-b +sqrt(raiz))/(2*a);
        y2=(-b -sqrt(raiz))/(2*a);
        printf("%f || %f",y1,y2);
    }
}

void pitagoras(){
    float a,b,c;

    printf("Numeros: ");
    scanf("%d%d%d",&a,&b,&c);

    if (pow(a,2)+pow(b,2)==pow(c,2)){
        printf("SIM");
    }
    else
        printf("NAO");
}
*/
/*
void branco(int num,int i){
    int j;
    for (j=0;j<(abs(num-2*i-1)/2);j++){
            printf("  ");
        }
}

void numeros(int num,int i){
    int j;
    for (j=0;j<(num-abs(num-2*i-1));j++){
            if (j%2==0)
                printf(" 0");
            else
                printf(" +");
            }

}

int losango(int num){
    int i,j;
    for (i=0;i<num;i++){
        branco(num,i);

        numeros(num,i);

        branco(num,i);

        printf("\n");

    }
}

*/
