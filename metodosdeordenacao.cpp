#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
/*---------------------------------------------------struct--------------------------------------------------------------*/
struct Time {
    char nome[4];
    int jogos, pontos, vitorias, empates, derrotas;
    int golsPro, golsContra, saldo;
    double aproveitamento;

    Time() {
        strcpy(nome, "");
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    Time(char _nome[4]) {
        strcpy(nome, _nome);
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    void computarJogo(int _golsPro, int _golsContra) {
        jogos++;
        if (_golsPro > _golsContra) {
            vitorias++;
            pontos += 3;
        } else if (_golsPro == _golsContra) {
            empates++;
            pontos += 1;
        } else {
            derrotas++;
        }
        golsPro += _golsPro;
        golsContra += _golsContra;
        saldo = golsPro - golsContra;
        aproveitamento = (pontos / (jogos * 3.0)) * 100.0;
    }
/*---------------------------------------------------imprimirVetor--------------------------------------------------------------*/
    void imprimirTime() {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\n",
               nome, jogos, pontos, vitorias, empates,
               derrotas, saldo, golsPro, golsContra,
               aproveitamento);
    }

};

/*------------------------------------------------bubbleSort-----------------------------------------------------------------*/
/*Bubble Sort:
O algoritmo Bubble Sort compara os elementos adjacentes do array e os troca de posição, 
se necessário. Ele percorre o array várias vezes, 
comparando e trocando os elementos até que todo o array esteja ordenado.
 O algoritmo é chamado de Bubble Sort porque, 
 à medida que ele percorre o array, os maiores elementos "flutuam" para o final do array, como bolhas subindo na água.*/

void bubbleSort(Time times[]){
    Time time2;
    
    printf("\n Tabela ordenada com bubbleSort \n");
    printf("\nNome  Jogo  Pontos Vitorias Empates Derrotas  saldo GolsPRO GolsContra Aproveitamentos \n");
     for(int i = 0; i<12; i++){
        for(int j =0; j<12;j++){
                if(times[i].pontos>times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias>times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo>
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro>times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
     }
    
}
/*---------------------------------------------------selectionSort--------------------------------------------------------------*/
/*Selection Sort:
O algoritmo Selection Sort encontra o menor elemento no array e o coloca na primeira posição. Em seguida, 
encontra o próximo menor elemento e o coloca na segunda posição, e assim por diante. 
Ele percorre o array apenas uma vez para cada elemento, 
encontrando o menor elemento restante e colocando-o na posição correta.*/
void selectionSort(Time times[]){
    Time time2;

     printf("\n Tabela ordenada com selectionSort \n");
     printf("\nNome  Jogo  Pontos Vitorias Empates Derrotas  saldo GolsPRO GolsContra Aproveitamentos \n");
    for(int i = 0; i<12;i++){
        for(int j = i+1; j<12;j++){
            if(times[i].pontos<times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias<times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo<
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro<times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
    }

}
/*---------------------------------------------------verifica--------------------------------------------------------------*/
bool troca(Time times, Time time2){
        if(times.pontos<time2.pontos){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias<time2.vitorias){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo<
                time2.saldo){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo==
                time2.saldo&&times.golsPro<time2.golsPro){

        }

        return false;
    }

/*------------------------------------------------insertionsort-----------------------------------------------------------------*/
/*Insertion Sort:
O algoritmo Insertion Sort percorre o array da esquerda para a direita e insere cada elemento na posição correta.
 Ele começa com o segundo elemento do array e compara com o primeiro elemento. 
 Se o segundo elemento for menor que o primeiro, eles são trocados.
  Em seguida, ele compara o terceiro elemento com o segundo elemento e assim por diante, até que todo o array esteja ordenado.*/
void insertionsort(Time times[]){
    Time time2;
    int i , j;

    printf("\nTabela ordenada com insertionsort \n");
    printf("\nNome  Jogo  Pontos Vitorias Empates Derrotas  saldo GolsPRO GolsContra Aproveitamentos \n");
    for(i = 1; i<12;i++){
        time2 = times[i];
        for(j = i-1; j>=0 && troca(times[j], time2) == true; j--){
                 times[j+1] = times[j];

            }

            times[j+1] = time2;
        }
    }


int main() {
/*---------------------------------------------------arquivo--------------------------------------------------------------*/
    Time times[12];
    char t1[4], t2[4];
    int r1, r2, ultimo_id = -1;
    FILE *f = fopen("dados.txt", "r+");
/*---------------------------------------------------Lê o arquivo--------------------------------------------------------------*/
    while(fscanf(f, "%s %dX%d %s", t1, &r1, &r2, t2) != EOF) {
        int i1 = -1, i2 = -1;
        for (int i = 0; i <= ultimo_id; i++) {
            if (strcmp(times[i].nome, t1) == 0) { // Checa se t1 já existe
                i1 = i;
            }
            if (strcmp(times[i].nome, t2) == 0) { // Checa se t2 já existe
                i2 = i;
            }
        }
        if (i1 == -1) { // Se t1 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t1);
            i1 = ultimo_id;
        }
        if (i2 == -1) { // Se t2 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t2);
            i2 = ultimo_id;
        }
        times[i1].computarJogo(r1, r2); // Computa para t1
        times[i2].computarJogo(r2, r1); // Computa para t2
    }
    for (int i = 0; i <= ultimo_id; i++) {
        times[i].imprimirTime();
    }
/*---------------------------------------------------escolha dos metodos--------------------------------------------------------------*/
	int numero;	
	printf("\n Digite uma das opcoes: \n ");
    printf("\n 1 bubbleSort ");
    printf("\n 2 selectionSort ");
    printf("\n 3 insertionSort \n  ");
   		 scanf("%d",&numero);
		
			switch (numero)
					{
   			case 1:
    		/* bubbleSort*/
    		bubbleSort(times);
    		 for (int i = 0; i <12; i++) {
        	 times[i].imprimirTime();
    			}
  				 break;

   			case 2:
    		 /*selectionSort*/
    		 selectionSort(times);
    		 for (int i = 0; i <12; i++) {
        	 times[i].imprimirTime();
    			}
   				break;
   				
			case 3:
    		 /*insertionSort*/
    		 insertionsort(times);
    		 for (int i = 0; i <12; i++) {
        	 times[i].imprimirTime();
    			}
   				break;

  				 default:
  				 printf("Opcao invalida! ");
   				 return 0;
				}
/*-----------------------------------------------------------------------------------------------------------------*/
    return 0;
}
