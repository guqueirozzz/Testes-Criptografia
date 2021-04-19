#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string>

using namespace std;

int chave[21][20100];
char vetor[21][5500];
char aux[2];
int pokerTestV[21][16];
int reMonoBit[21];
int mRunTest0[21][2];
int mRunTest1[21][2];
int mRunTest2[21][2];
int mRunTest3[21][2];
int mRunTest4[21][2];
int mRunTest5[21][2];
int mRunTest6[21][2];
int mRunTest34[21][2];

// LEITURA DO VETOR
void input_stream()
{
	FILE * sc = fopen("ChavesCrip.txt","r");
	for(int i = 0 ; i < 20; i++)
    {
		fgets(vetor[i],5003,sc);
		fgets(aux,2,sc);
		//printf("\n chave %d = %s",i,vetor[i]);
	}
		fclose(sc);
}

// PRINT HEXADECIMAL
void printHEXADECIMAL()
{
	for(int i = 1; i <= 5000; i++)
    {
		printf("%c",vetor[0][i]);
	}
}

//PRINT BINARIO
void print_binario()
{

	for(int i = 0; i < 20; i++)
    {
        printf("\nChave %d = \n",i);
		for(int j = 0; j < 20000; j++)
        {
			printf("%d",chave[i][j]);
		}
	}
}

// Conversão de Hexadecimal para binário
void converte_binario()
{
	for(int i = 0 ; i < 20 ; i++)
    {
		int cont_vetor = 0;

		for(int j = 1; j <= 5000 ; j++)
	 	{
		    if(vetor[i][j] == '0')
		    {
		        chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 0;
		    	cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '1')
		    {
		        chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '2')
		    {
		        chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '3')
		    {
		       	chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '4')
		    {
		       	chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '5')
		    {
		    	chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '6')
		    {
		    	chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '7')
		    {
		    	chave[i][cont_vetor] = 0;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '8')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == '9')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'A')
		    {
		        chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'B')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 0;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'C')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'D')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 0;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'E')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 0;
		        cont_vetor = cont_vetor + 4;
		    }
		    else if(vetor[i][j] == 'F')
		    {
		    	chave[i][cont_vetor] = 1;
		        chave[i][cont_vetor+1] = 1;
		        chave[i][cont_vetor+2] = 1;
		        chave[i][cont_vetor+3] = 1;
		        cont_vetor = cont_vetor + 4;
		    }
	  	}
	  	//printf("contador %d", cont_vetor);
	}
}


void pokerTest()
{
  for(int i=0;i<20;i++)
  {
    	for(int j=1; j<=5000; j++)
        {
	    	if(vetor[i][j] == '0')
	        	pokerTestV[i][0] = pokerTestV[i][0]+1;

	      	if(vetor[i][j] == '1')
	        	pokerTestV[i][1] = pokerTestV[i][1]+1;

	      	if(vetor[i][j] == '2')
	        	pokerTestV[i][2] = pokerTestV[i][2]+1;

	      	if(vetor[i][j] == '3')
	       		pokerTestV[i][3] = pokerTestV[i][3]+1;

	      	if(vetor[i][j] == '4')
	        	pokerTestV[i][4] = pokerTestV[i][4]+1;

	      	if(vetor[i][j] == '5')
	        	pokerTestV[i][5] = pokerTestV[i][5]+1;

	      	if(vetor[i][j] == '6')
	        	pokerTestV[i][6] = pokerTestV[i][6]+1;

	      	if(vetor[i][j] == '7')
	        	pokerTestV[i][7] = pokerTestV[i][7]+1;

	      	if(vetor[i][j] == '8')
	        	pokerTestV[i][8] = pokerTestV[i][8]+1;

	      	if(vetor[i][j] == '9')
	        	pokerTestV[i][9] = pokerTestV[i][9]+1;

	      	if(vetor[i][j] == 'A')
	        	pokerTestV[i][10] = pokerTestV[i][10]+1;

	      	if(vetor[i][j] == 'B')
	        	pokerTestV[i][11] = pokerTestV[i][11]+1;

	      	if(vetor[i][j] == 'C')
	        	pokerTestV[i][12] = pokerTestV[i][12]+1;

	      	if(vetor[i][j] == 'D')
	        	pokerTestV[i][13] = pokerTestV[i][13]+1;

	      	if(vetor[i][j] == 'E')
	        	pokerTestV[i][14] = pokerTestV[i][14]+1;

	      	if(vetor[i][j] == 'F')
	        	pokerTestV[i][15] = pokerTestV[i][15]+1;

    	}
	}

    float t [21];
    for(int i = 0; i < 20; i++)
    {
           float soma = 0;
        for(int j = 0; j <= 15; j++)
        {
           soma = soma + pow(pokerTestV[i][j],2);
        }
     t[i] = 16.0/5000.0 * soma;
     t[i] = t[i] - 5000;
    }

  	for(int i = 0 ; i<20; i++){
   		printf("\n Chave %d", i+1);
   		printf("\n Quantidade de ocorrências de 0 = %d", pokerTestV[i][0]);
		printf("\n Quantidade de ocorrências de 1 = %d", pokerTestV[i][1]);
		printf("\n Quantidade de ocorrências de 2 = %d", pokerTestV[i][2]);
		printf("\n Quantidade de ocorrências de 3 = %d", pokerTestV[i][3]);
		printf("\n Quantidade de ocorrências de 4 = %d", pokerTestV[i][4]);
		printf("\n Quantidade de ocorrências de 5 = %d", pokerTestV[i][5]);
		printf("\n Quantidade de ocorrências de 6 = %d", pokerTestV[i][6]);
		printf("\n Quantidade de ocorrências de 7 = %d", pokerTestV[i][7]);
		printf("\n Quantidade de ocorrências de 8 = %d", pokerTestV[i][8]);
		printf("\n Quantidade de ocorrências de 9 = %d", pokerTestV[i][9]);
		printf("\n Quantidade de ocorrências de A = %d", pokerTestV[i][10]);
		printf("\n Quantidade de ocorrências de B = %d", pokerTestV[i][11]);
		printf("\n Quantidade de ocorrências de C = %d", pokerTestV[i][12]);
		printf("\n Quantidade de ocorrências de D = %d", pokerTestV[i][13]);
		printf("\n Quantidade de ocorrências de E = %d", pokerTestV[i][14]);
		printf("\n Quantidade de ocorrências de F = %d", pokerTestV[i][15]);
	    printf("\n");
	}
}

int contador34 = 1;

void monobit()
{
    for(int  i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20000; j++)
        {
            if(chave[i][j] == 1)
                reMonoBit[i] = reMonoBit[i] + 1;

        }
        printf("\n Na chave %d existem %d numeros 1 \n", i + 1,reMonoBit[i]);
    }
}

void run_test()
{
    for (int i = 0; i < 20; i++)
    {

        int iterator = 0;
        while(iterator < 20000){

            int contador_1=0;
            while(chave[i][iterator] == 1 && iterator < 20000 ){
                contador_1++;
                iterator++;
            }

            int contador_0=0;
              while(chave[i][iterator] == 0 && iterator < 20000  ){
                contador_0++;
                iterator++;
            }

            if (contador_1 == 1 )
                mRunTest1[i][1] = mRunTest1[i][1] + 1;

            if(contador_1 == 2)
                mRunTest2[i][1] = mRunTest2[i][1] +1;

            if(contador_1 == 3)
                mRunTest3[i][1] = mRunTest3[i][1] +1;

            if(contador_1 == 4)
                mRunTest4[i][1] = mRunTest4[i][1] +1;

            if(contador_1 == 5)
                mRunTest5[i][1] = mRunTest5[i][1] +1;

            if(contador_1 >= 6 )
                mRunTest6[i][1] = mRunTest6[i][1] +1;

            if(contador_1 >= 34)
                mRunTest34[i][1] = mRunTest34[i][1] + 1;




            if(contador_0 == 1)
                mRunTest1[i][0] = mRunTest1[i][0] +1;

            if(contador_0 == 2)
                mRunTest2[i][0] = mRunTest2[i][0] +1;

            if(contador_0 == 3)
                mRunTest3[i][0] = mRunTest3[i][0] +1;

            if(contador_0 == 4)
                mRunTest4[i][0] = mRunTest4[i][0] +1;

            if(contador_0 == 5)
                mRunTest5[i][0] = mRunTest5[i][0] +1;

            if(contador_0 >= 6 )
                mRunTest6[i][0] = mRunTest6[i][0] +1;

            if(contador_0 >= 34)
            {
                printf("\nEntrou no if do 34. Valor do contador:  %d \n", contador34);
                mRunTest34[i][0] = mRunTest34[i][0] + 1;
                contador34++;

            }

        }
    }
    for (int i = 0; i < 20; i++)
    {
        printf("\n\n Chave %d",i+1);
        printf("\n Numero de sequencias de tamanho 1:");
        printf("\n 0 = %d",mRunTest1[i][0]);
        printf("\n 1 = %d",mRunTest1[i][1]);
        printf("\n Numero de sequencias de tamanho 2:");
        printf("\n 0 = %d",mRunTest2[i][0]);
        printf("\n 1 = %d",mRunTest2[i][1]);
        printf("\n Numero de sequencias de tamanho 3:");
        printf("\n 0 = %d",mRunTest3[i][0]);
        printf("\n 1 = %d",mRunTest3[i][1]);
        printf("\n Numero de sequencias de tamanho 4:");
        printf("\n 0 = %d",mRunTest4[i][0]);
        printf("\n 1 = %d",mRunTest4[i][1]);
        printf("\n Numero de sequencias de tamanho 5:");
        printf("\n 0 = %d",mRunTest5[i][0]);
        printf("\n 1 = %d",mRunTest5[i][1]);
        printf("\n Numero de sequencias de tamanho 6+:");
        printf("\n 0 = %d",mRunTest6[i][0]);
        printf("\n 1 = %d",mRunTest6[i][1]);



    }

}

void long_run_test()
{
    int iterator = 0;
    for(int i = 0; i < 20; i++)
    {
        while(iterator < 20000)
        {
            int contador_1=0;
            while(chave[i][iterator] == 1 && iterator < 20000 )
            {
                contador_1++;
                iterator++;
            }

            int contador_0=0;
              while(chave[i][iterator] == 0 && iterator < 20000  )
            {
                contador_0++;
                iterator++;
            }

            if(contador_1 >= 34)
                mRunTest34[i][1] = mRunTest34[i][1] + 1;

            if(contador_0 >= 34)
            {
                printf("\nEntrou no if do 34. Valor do contador:  %d \n", contador34);
                mRunTest34[i][0] = mRunTest34[i][0] + 1;
                contador34++;

            }
        }

    }

    for(int i = 0; i < 20; i++)
    {
            printf("\n Sequencias de tamanho 34 + ");
            printf("\n CHAVE: %d ", i+1);
            printf("\n 0 = %d",mRunTest34[i][0]);
            printf("\n 1 = %d",mRunTest34[i][1]);
    }

}

int main()
{
	input_stream();
	converte_binario();
	//printHEXADECIMAL();
	//monobit();
	//print_binario();
	//run_test();
	pokerTest();
	//printf("\n ========================== LONG RUN TEST =========================== :");
	//long_run_test();
}
