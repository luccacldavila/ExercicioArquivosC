#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Programa para calcular quantos metros de aço são necessarios
//Comprimento C da ponte será em km deve ser de 2 a 4
// A haste tem relação a extensão da ponte, deve ser 1/20 da extensão
// tem quatro cabos cada lado
//precisa saber quantos m de cabo são necessários para construir a ponte


float calcular_haste(float c){

c = c*1000;
float haste;

haste = c*0.05;

return haste;

}

float calculo_para_cada_cabo(float h, float c)
{
    h = h/5;
    int cont;
    float resultado=0, aux;
    c = c/2;
    c = c/5;
    for(cont = 1; cont <=5 ; cont++)
    {
        aux = h*h*cont + c*c*cont;
        aux = sqrt(aux);
        resultado = resultado + aux;
        printf("%.1f\n",resultado);

    }

    return resultado;

}

int main()
{
    float c,h;
    printf("Por favor escolher, em km, o comprimento da extensão da ponte, o valor deve ser de 2 a 4\n\n");

    do{
            scanf("%f",&c);
            fflush(stdin);
            if(c<2 || c>4)
            {
                printf("Valor invalido\n");
            }

    }while(c<2 || c>4);

    printf("O valor do cumprimento da ponte e de %.1f km\n\n",c);

    h = calcular_haste(c);

    printf("Com uma haste de %.2f metros\n\n",h);

    c = calculo_para_cada_cabo(h,c);

    printf("O numero de cabos de aço necessarios para a ponte e: \n\n");
    printf("%.1f metros de aco",c*4);


    return 0;
}
