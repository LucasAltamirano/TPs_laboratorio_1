#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"

int menu()
{
	int opcionMenu;
	float operandoUno=0;
	float operandoDos=0;
	int banderaOperandoUno=0;
	int banderaOperandoDos=0;
	int banderaCalcularResultados=0;
	int controlDivision;
	int controlFactorialUno;
	int controlFactorialDos;
	//RESULTADOS
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicar;
	unsigned long resultadoFactorialOperandoUno;
	unsigned long resultadoFactorialOperandoDos;

	do
	{
		printf("Bienvenido al Menu de CALCULADORA\n Ingrese\n1:introduce primer operando (OP1=%.2f)\n2:introduce segundo operando (OP2=%.2f)\n3:Calcula suma,resta,division,multiplicacion y factorial\n4:informa resultados\n5:salir\n",operandoUno,operandoDos);
		scanf("%d",&opcionMenu);
		while(opcionMenu>5||opcionMenu<1)
		{
			printf("Error, ingrese una opcion de menu valida\n");
			scanf("%d",&opcionMenu);
		}
		switch(opcionMenu)
		{
			case 1:
				printf("Ingrese primer operando\n");
				scanf("%f",&operandoUno);
				banderaOperandoUno=1;
			break;
			case 2:
				printf("Ingrese segundo operando\n");
				scanf("%f",&operandoDos);
				banderaOperandoDos=1;
			break;
			case 3:
				if(banderaOperandoUno&&banderaOperandoDos)
				{
					if(sumar(operandoUno,operandoDos,&resultadoSuma))
					{
						printf("La suma se realizo con exito\n");
					}
					else
					{
						printf("Alfo fallo en SUMAR\n");
					}
					if(restar(operandoUno,operandoDos,&resultadoResta))
					{
						printf("La resta se realizo con exito\n");
					}
					else
					{
						 printf("Algo fallo en RESTAR\n");
					}
					controlDivision=division(operandoUno,operandoDos,&resultadoDivision);
					if(controlDivision)
					{
						printf("La division se realizo con exito\n");
					}
					else
					{
						printf("Algo fallo en DIVISION\n");
					}
					if(multiplicar(operandoUno,operandoDos,&resultadoMultiplicar))
					{
						printf("La multiplicacion se realizo con exito\n");
					}
					else
					{
						printf("Algo fallo en MULTIPLICAR\n");
					}
					controlFactorialUno=factorial(operandoUno,&resultadoFactorialOperandoUno);
					if(controlFactorialUno)
					{
						printf("El factorial de OPERANDO 1 se realizo con exito , recuerde calculadora no factoriza numeros decimales,� mayores a 12 � negativos +info en resultados\n");
					}
					else
					{
						printf("Algo fallo en FACTORIAL OPERANDO 1\n");
					}
					controlFactorialDos=factorial(operandoDos,&resultadoFactorialOperandoDos);
					if(controlFactorialDos)
					{
						printf("El factorial de OPERANDO 2 se realizo con exito, recuerde calculadora no factoriza numeros decimales,� mayores a 12 � negativos +info en resultados\n\n");
					}
					else
					{
						printf("Algo fallo en FACTORIAL OPERANDO 2\n");
					}
					banderaCalcularResultados=1;
					banderaOperandoUno=0;
					banderaOperandoDos=0;
				}
				else
				{
					if(banderaOperandoUno==0)
					{
						printf("AUN NO HA INGRESADO EL OPERANDO UNO\n\n");
					}
					else
					{
						printf("AUN NO HA INGRESADO EL OPERANDO DOS\n\n");
					}
				}
			break;
			case 4:
				if(banderaCalcularResultados)
				{
					printf("SUS RESULTADOS\n\nSUMA DE %.2f+%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoSuma);
					printf("RESTA DE %.2f-%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoResta);
					printf("MULTIPLICACION DE %.2f*%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoMultiplicar);
					if(controlDivision!=2)
					{
						printf("DIVISION DE %.2f/%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoDivision);
					}
					else
					{
						printf("NO ES POSIBLE DIVIDIR POR 0\n\n");
					}
					if(controlFactorialUno!=2)
					{
						printf("FACTORIAL DE %.2f=%lu\n\n",operandoUno,resultadoFactorialOperandoUno);
					}
					else
					{
						printf("CALCULADORA NO FACTORIZA NUM + A 12, NO FACTORIZA NEGATIVOS , NO FACTORIZA DECIMALES\n\n");
					}
					if(controlFactorialDos!=2)
					{
						printf("FACTORIAL DE %.2f=%lu\n\n",operandoDos,resultadoFactorialOperandoDos);
					}
					else
					{
						printf("CALCULADORA NO FACTORIZA NUM + A 12, NO FACTORIZA NEGATIVOS , NO FACTORIZA DECIMALES\n\n");
					}
					banderaCalcularResultados=0;
				}
				else
				{
					printf("PARA OBTENER RESULTADOS DEBE PRIMERO CALCULAR LAS OPERACIONES OPCION 3\n\n");
				}
			break;
		}

	}while(opcionMenu!=5);

	 return 0;
}

