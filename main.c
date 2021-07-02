/* Ruler 1         2         3         4         5         6         7        */
/* Tarea 2*********************************************************************/
/*                                                                            */
/*   ┌────┐ ┌────┐                     ECUACION CUADRATICA                    */
/*   └┐  ┌┘ └┐╔══╧═╗                                                          */
/*    │  │   │╚╗  ╔╝      DEVELOPED BY: Ing. Edward Duarte                    */
/*    │  │   │ ║  ║                     edwardduarte@javeriana.edu.co         */
/*    │  │   │ ║  ║                                                           */
/*    │╔═╧══╗│ ║  ║       Bucaramanga,  March 08th, 2021.                     */
/*    │╚╗  ╔╝┘ ║  ║                                                           */
/*    └┐║  ╚╗ ╔╝  ║       Copyright (C) Electronics Engineering Program       */
/*     └╚╗  ╚═╝  ╔╝                     School of Engineering                 */
/*      └╚╗     ╔╝                      Pontificia Universidad Javeriana      */
/*        ╚═════╝                       Bogota - Colombia - South America     */
/*                                                                            */
/*********************************  bench.h  **********************************/
/*                                                                            */
/*   Purpose: Hallar las raices de una función cuadratica                     */
/*                                                                            */
/*   Origin:  Ingeniero Juan Carlos Giraldo                                   */
/*                                                                            */
/*   Notes:   Este codigo está diseñado para ser corrido en cmd               */
/*                                                                            */
/******************************************************************************/

/********************************** HEADERS ***********************************/
#include <stdio.h>
#include <math.h>
#include <aclapi.h>
/****************************** Estructuras ***********************************/

typedef struct {
    double real;
    double imag;
} COMPLEX_T;

/*FN****************************************************************************
*
*   prototype: int solve_Quadratic_Ecuation(COMPLEX_T *root_1,COMPLEX_T *root_2,
*              double  a,double  b,double  c)
*
*   Return: 1
*
*   Purpose: Hallar las raices de una ecuación cuadratica con entrada por param.
*
*   Plan:
*   1) Definir los parametros de entrada de la función, con 3 datos de
*   tipo double y dos apuntadores a estructuras de tipo COMPLEX_T
*   2) Crear una variable con el discriminante, el cual permitira la selección
*   entre los distintos casos posibles
*   3) Condicionales que establecen el tipo de respuesta de las raíces
*       3.1) Caso de dos raices diistintas con valores reales.
*       3.2) Caso de 1 raiz  con valor real.
*       3.3) Caso de dos raices diistintas con valores imaginarios.
*
*   Register of Revisions:
*
*   DATE       RESPONSIBLE  COMMENT
*   -----------------------------------------------------------------------
*   marzo 08/21  J.C.Giraldo    Initial implementation
*   marzo 08/21  Edward Duarte  Function developer
*******************************************************************************/


/***************************FUNCION_EC.CUADRATICA ****************************/

/*----------------------------------1)---------------------------------------*/
int Solve_Quadratic_Equation(
        double a,
        double b,
        double c,
        COMPLEX_T *root_1,
        COMPLEX_T *root_2 )
{
/*----------------------------------2)---------------------------------------*/
    double discriminante;
    discriminante = b * b - 4 * a * c;
/*----------------------------------3)---------------------------------------*/

/*----------------------------------3.1)-------------------------------------*/
    if(discriminante > 0) {
        root_1->real = (-b + sqrt(discriminante)) / (2 * a);
        root_1->imag = 0;
        root_2->real = (-b - sqrt(discriminante)) / (2 * a);
        root_2->imag = 0;
    }
/*----------------------------------3.2)-------------------------------------*/
    else if (discriminante == 0) {
        root_1->real = -b / (2 * a);
        root_1->imag = 0;
        root_2->real = -b / (2 * a);
        root_2->imag = 0;
    }
/*----------------------------------3.3)-------------------------------------*/
    else {
        root_1->real = -b / (2 * a);
        root_1->imag = sqrt(-discriminante) / (2 * a);
        root_2->real = -b / (2 * a);
        root_2->imag = -sqrt(-discriminante) / (2 * a);
    }
} /*solve_Quadratic_Ecuation*/

/*****************************FUNCION_PRINCIPAL ******************************/
int main( int argc, char *argv[])
{
    double a = atof( argv[1] );
    double b = atof( argv[2] );
    double c = atof( argv[3] );

    COMPLEX_T root_1, root_2;
    Solve_Quadratic_Equation( a, b, c, &root_1, &root_2 );
    fprintf( stdout, "Solucion 1: %.2f %.2f i\n", root_1.real, root_1.imag );
    fprintf( stdout, "Solucion 2: %.2f %.2f i\n", root_2.real, root_2.imag );

    return 0;

}/*main*/