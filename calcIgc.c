
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{

int codigo, nmAlunos,cpcFaixa;
float nota, idd, doutores, mestres, regTrab, orgDidatPed, infra, oaap, cpcConti;

} ENADE;

int menu(void)
{
  int op;

        printf("\n Menu : \n"); 
       printf(" ------------------------------\n");     
       printf(" 1- Criar arquivo : \n"
		          " 2- Carregar o struct \n"
              " 3- Calcular e exibir os Cursos com CPC continuo e faixa \n"
              " 4- Exibir os Cursos com CPC faixa possível \n"
              " 5- Calcular e exibir IGC – Índice Geral de Cursos – \n");
	     printf("\n Qual operação deseja realizar ? : \n");        
       scanf("%d", &op);
  
  return op;
}

int verifCPCFaixa(ENADE curso[], int tam)
{int i;
 for(i=0; i< tam; i++)
 {
   if(curso[i].cpcConti>= 3.945)
   {
     return 1;
   }

 }
return 0;
}

void exibirCpcPossiv(ENADE curso[], int tam)
{int i, n;

 n= verifCPCFaixa(curso,tam);

 if(n !=0)
 {
   printf("\n Cursos com CPC faixa possivel ! \n");
    for(i=0; i<tam; i++)
    {
     if(curso[i].cpcConti >= 3.945)
     {
     printf("\n Curso codigo : %d, CPC contínuo : %.2f, CPC faixa possivel : %d, classificação satisfatório \n", curso[i].codigo, curso[i].cpcConti, curso[i].cpcFaixa);
     }

    }
 
  } 
  else 
  {
    printf("\n Não existe Curso com CPC faixa possivel cadastrado \n");
  }
 

}

void calcCPCFaixa(ENADE curso[], int tam)
{int i;
 float cpc;

 for(i=0; i< tam; i++)
 {
      //1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258  cpc = 2.73
  cpc = ((curso[i].nota*0.2) +(curso[i].idd*0.35)+ (curso[i].doutores*0.15)+(curso[i].mestres*0.075)+
        (curso[i].regTrab*0.075)+ (curso[i].orgDidatPed*0.075)+(curso[i].infra*0.05)+(curso[i].oaap*0.025));

        if(cpc < 0.945)
        {
         curso[i].cpcFaixa =1;
         curso[i].cpcConti = cpc;
        }
        else
        {
          if(cpc < 1.945)
          {
           curso[i].cpcFaixa =2;
           curso[i].cpcConti = cpc;
          }
          else 
          {
            if(cpc < 2.945)
            {
              curso[i].cpcFaixa =3;
              curso[i].cpcConti = cpc;
            }
            else 
            {
              if(cpc < 3.945)
              {
               curso[i].cpcFaixa =4;
               curso[i].cpcConti = cpc;
              }
              else 
              {
                curso[i].cpcFaixa =5;
                curso[i].cpcConti = cpc;
              }

            }

          }

        }

        if(curso[i].cpcFaixa<3)
        {
          printf("\n Curso codigo : %d, CPC contínuo : %.2f, CPC faixa : %d, classificação insatisfatório \n", curso[i].codigo, curso[i].cpcConti, curso[i].cpcFaixa);
        }
        else
        {
          
            printf("\n Curso codigo : %d, CPC contínuo : %.2f, CPC faixa : %d, classificação satisfatório \n", curso[i].codigo, curso[i].cpcConti, curso[i].cpcFaixa);            

        }

 }

}

void calcExibirIGC(ENADE curso[], int tam)
{int i;
 float igc, acumulNumerador=0, acumulDenominador=0;

 for(i=0; i<tam; i++)
 {
    acumulNumerador = acumulNumerador + (curso[i].cpcConti*curso[i].nmAlunos);
    acumulDenominador = acumulDenominador +(curso[i].nmAlunos);
 }

   igc = acumulNumerador/acumulDenominador;

        if(igc < 0.945)
        {
         printf("\n IGC – Índice Geral de Cursos da instituição : %.2f, faixa 1 insatisfatório \n", igc);
        }
        else
        {
          if(igc < 1.945)
          {
            printf("\n IGC – Índice Geral de Cursos da instituição : %.2f, faixa 2 insatisfatório \n", igc);
          }
          else 
          {
            if(igc < 2.945)
            {
              printf("\n IGC – Índice Geral de Cursos da instituição : %.2f, faixa 3 satisfatório \n", igc);
            }
            else 
            {
              if(igc < 3.945)
              {
                printf("\n IGC – Índice Geral de Cursos da instituição : %.2f, faixa 4 satisfatório \n", igc);
              }
              else 
              {
                printf("\n IGC – Índice Geral de Cursos da instituição : %.2f, faixa 5 satisfatório \n", igc);
              }

            }


          }

        }
}

void carregarStruc(ENADE curso[], int tam, char str[], int control, int cL)
{int cod, nmAlun, k;
 //float notaEnad, vidd, vdoutores, vmestres, vregTrab, vorgDidatPed, infra,oaap;
  
  switch(control)
  {
    case 1:
   curso[cL].codigo = atoi(str);
   break;   
   case 2:
    curso[cL].nota = atof(str);
   break;
   case 3:
   curso[cL].idd = atof(str);
   break;
   case 4:
   curso[cL].doutores = atof(str);
   break;     
   case 5:
   curso[cL].mestres = atof(str);
   break;       
     case 6:
   curso[cL].regTrab = atof(str);
   break;   
     case 7:
   curso[cL].orgDidatPed = atof(str);
   break; 
   case 8:
   curso[cL].infra = atof(str);
   break;       
      case 9:
   curso[cL].oaap = atof(str);
   break; 
               
       default:
            curso[cL].nmAlunos = atof(str);
       break;    
  }        
     
}

 int lerArq(ENADE curso[], int tam, char nomeAr[])
 {
	 char linha[100], aux[10];
	  int p, i,j,k, cont, control, contLinha;
    
   FILE *Arquivo = fopen(nomeAr, "r");
    
   if(Arquivo == NULL)
   {
    printf("Erro ao abrir o arquivo");
   }

   else
   {    
     // for(fgets(linha,TAM,Arquivo);!feof(Arquivo);fgets(linha,TAM,Arquivo))  copia a 1° linha do arquivo depois a 2° assim em diante enquanto não for o fim 
     //1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258
     //1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258  cpc = 
     contLinha=0;
     i=0;
     
     //while(fgets(linha,TAM,Arquivo) !=NULL) 
     for(fgets(linha,100,Arquivo);!feof(Arquivo);fgets(linha,100,Arquivo))
      { cont=0, k=0, control=0; 

      
       while(linha[cont] != '\0')
       {
         for(j=0 ; linha[j+cont] != '|' && linha[j+cont] != '\0'; j++)
          {             
           aux[j] = linha[j+cont];
          } 
          aux[j]= '\0';         
          control++;  // conta quando chegou no barra
          
         carregarStruc(curso, tam, aux, control, contLinha);       
        
           
        cont = j+cont;
        cont++;    
        
       }      
      //printf("%s \n", linha);
     contLinha++;
    }         

  }   
   
    fclose(Arquivo);

    return contLinha;
   
} 


int main(void)
{
  ENADE curso[10];
  FILE *Arq;
  int n,k, n2, tamStruc, num;
  char string[100];
  char nomeArq[15] = "enade.txt";
  float valor;     

 do{       
   n = menu();
	   switch(n)
	   {
	      case 1: 

		     Arq = fopen("enade.txt","w");

			 if(Arq == NULL)
			 {
				  printf("\n Erro ao abrir arquivo ");
			 }
			 else
			 {
          printf("\n Deseja escrever no arquivo (1-sim) (2-não) \n");
          scanf("%d", &n2);
          while(n2 != 2)
          {
             printf("\n Escreva os dados \n");
			       scanf("%s", string);

				    fprintf(Arq, "%s \n", string);

           // printf("--------------------- \n");
            //printf("%f \n", string);

            printf("\n Deseja escrever no arquivo (1-sim) (2-não) \n");
            scanf("%d", &n2);		 
			 
	  }

            fclose(Arq);
       }
		    
			   break;

	   case 2:

		    tamStruc = lerArq(curso, 10, nomeArq);
        
        printf(" \n Struct carregado ! \n");
        for(k=0; k<tamStruc; k++)
        {
        printf(" %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %d \n", curso[k].codigo,
          curso[k].nota,curso[k].idd, curso[k].doutores,curso[k].mestres, curso[k].regTrab, curso[k].orgDidatPed, curso[k].infra, curso[k].oaap, curso[k].nmAlunos);

        }
		   break;	

       case 3:      
       calcCPCFaixa(curso, tamStruc);       

       break; 

       case 4:
         exibirCpcPossiv(curso, tamStruc);
       break; 

       case 5:
        calcExibirIGC(curso, tamStruc);
       break;      
	   
	  }

    printf(" Deseja encerrar ? caso sim digite (-1) \n");
    scanf("%d", &num);
    
  } 
  while(num !=-1); 
     

	   system("PAUSE");

    return 0;
}


// 1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258   cpc = 2.73
// 1235|2.45|3.87|0.98|2.05|3.50|4.34|0.76|4.32|259   cpc = 2.88
// 1236|1.47|3.57|0.88|3.08|2.70|2.20|3.40|1.12|247  cpc = 2.47
// 1237|4.47|4.57|3.88|3.08|2.70|4.20|5.00|4.10|277    cpc = 4.17
// 1238|4.50|3.90|4.88|4.95|4.90|3.00|5.00|4.20|267    cpc = 4.31
// 1239|1.50|0.80|0.58|0.95|2.90|1.00|0.20|0.10|237    cpc = 
// 1240|0.30|0.10|0.78|1.95|1.10|2.00|1.10|2.01|217   cpc = 
// 1241|3.47|3.57|3.88|3.08|2.70|3.20|4.07|4.04|271    cpc = 




