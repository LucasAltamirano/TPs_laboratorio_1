#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"

int menu()
{
	int opcionMenu;
	float operandoUno;
	float operandoDos;
	int banderaOperandoUno=0;
	int banderaOperandoDos=0;
	int banderaCalcularResultados=0;
	//RESULTADOS
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicar;
	long resultadoFactorialOperandoUno=0;
	long resultadoFactorialOperandoDos=0;

	do
	{
		printf("Bienvenido al Menu de CALCULADORA\n Ingrese\n1:introduce primer operando\n2:introduce segundo operando\n3:Calcula suma,resta,division,multiplicacion y factorial\n4:informa resultados\n5:salir\n");
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
				printf("EL OPERANDO UNO ES %.2f\n",operandoUno);
			break;
			case 2:
				printf("Ingrese segundo operando\n");
				scanf("%f",&operandoDos);
				banderaOperandoDos=1;
				printf("EL OPERANDO DOS ES %.2f\n",operandoDos);
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
					if(division(operandoUno,operandoDos,&resultadoDivision))
					{
						printf("La division se realizo con exito\n");
					}
					else
					{
						printf("Algo fallo en DIVISION");
					}
					if(multiplicar(operandoUno,operandoDos,&resultadoMultiplicar))
					{
						printf("La multiplicacion se realizo con exito\n");
					}
					else
					{
						printf("Algo fallo en MULTIPLICAR\n");
					}
					if(factorial(operandoUno,&resultadoFactorialOperandoUno))
					{
						printf("El factorial de OPERANDO 1 se realizo con exito , recuerde no se factoriza numeros decimales +info en resultados\n");
					}
					else
					{
						printf("Algo fallo en FACTORIAL OPERANDO 1");
					}
					if(factorial(operandoDos,&resultadoFactorialOperandoDos))
					{
						printf("El factorial de OPERANDO 2 se realizo con exito, recuerde no se factoriza numeros decimales +info en resultados\n");
					}
					else
					{
						printf("Algo fallo en FACTORIAL OPERANDO 2");
					}
					banderaCalcularResultados=1;
				}
				else
				{
					if(banderaOperandoUno==0)
					{
						printf("Aun no ha ingresado el operando uno\n");
					}
					else
					{
						printf("Aun no ha ingresado el operando dos\n");
					}
				}
			break;
			case 4:
				if(banderaCalcularResultados)
				{
					printf("SUS RESULTADOS\n\nSUMA DE %.2f+%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoSuma);
					printf("RESTA DE %.2f-%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoResta);
					printf("MULTIPLICACION DE %.2f*%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoMultiplicar);
					if(operandoDos!=0)
					{
						printf("DIVISION DE %.2f/%.2f=%.2f\n\n",operandoUno,operandoDos,resultadoDivision);
					}
					else
					{
						printf("NO ES POSIBLE DIVIDIR POR 0\n\n");
					}
					if(resultadoFactorialOperandoUno!=0)
					{
						printf("FACTORIAL DE %.2f=%ld\n\n",operandoUno,resultadoFactorialOperandoUno);
					}
					else
					{
						if(operandoUno>33)
						{
							printf("CALCULADORA NO POSEE SUFICIENTE MEMORIA PARA FACTORIALES MAYORES AL N�33\n\n");
						}
						else
						{
							if(operandoUno<1)
							{
								printf("CALCULADORA NO REALIZA FACTORIAL DE NEGATIVOS\n\n");
							}
							else
							{
								printf("CALCULADORA NO REALIZA FACTORIAL DE DECIMALES\n\n");
							}
						}
					}
					if(resultadoFactorialOperandoDos!=0)
					{
						printf("FACTORIAL DE %.2f=%ld\n\n",operandoDos,resultadoFactorialOperandoDos);
					}
					else
					{
						if(operandoDos>33)
						{
							printf("CALCULADORA NO POSEE SUFICIENTE MEMORIA PARA FACTORIALES MAYORES AL N�33\n\n");
						}
						else
						{
							if(operandoDos<1)
							{
								printf("CALCULADORA NO REALIZA FACTORIAL DE NEGATIVOS\n\n");
							}
							else
							{
								printf("CALCULADORA NO REALIZA FACTORIAL DE DECIMALES\n\n");
							}
						}
					}
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
