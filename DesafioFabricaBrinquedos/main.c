#include <stdio.h>
#include <stdlib.h>

//6 circulos sobre postos com a mesma distância entre eles
//Calcular quantidade de papelao para 5k alvos
//Usuario fornece o diametro

//Resolucao: o raio ira mostrar a quantidade de circulos, portanto a quantidade de papelão utilizado

#define PI  3
#define total 5000
float Areacircuferencia(float r)
{
    float ac;
    ac = 2*PI*r*r;

    return ac;
}

float QtdePapelao(float q){
    float tot;
    q = q/6;
    tot = Areacircuferencia(q);

    return tot;

}
void Areaporcirculo(float a,float c)
{



}

int main()
{
    char escolha;
    float d, q;
    printf("Fabrica de alvos\n\n");

    do{
            d = 0;
            while(d<6){
            printf("Usuario digite o diametro do circulo do alvo, deve ser maior que 6\n\n");


            scanf("%f",&d);
            fflush(stdin);

            q = total*QtdePapelao(d);
            }


            printf("Essa e a sua escolha?\n\n");
              printf("O total de papelão utilizado sera de %.0f\n",q);

            scanf("%c",&escolha);
            fflush(stdin);





    }while(escolha != 's' && escolha != 'S');

    printf("O numero total de papelao sera de %.0f para cada raio %.1f ")



    return 0;
}
