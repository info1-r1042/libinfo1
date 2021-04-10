/*!
 * @file   main.c
 * @brief  Biblioteca del curso R1042 de Informática I
 * @author Javier Balloffet <jballoffet@frba.utn.edu.ar>
 * @date   Apr 26, 2020
 */
#include <stdio.h>

#include <info1.h>

int main(void) {
  string s = obtener_string("Ingrese un string: ");
  printf("hola, %s\n", s);
  char c = obtener_char("Ingrese un char: ");
  printf("char ingresado: %c\n", c);
  int i = obtener_int("Ingrese un int: ");
  printf("int ingresado: %d\n", i);
  long l = obtener_long("Ingrese un long: ");
  printf("long ingresado: %ld\n", l);
  float f = obtener_float("Ingrese un float: ");
  printf("float ingresado: %f\n", f);
  double d = obtener_double("Ingrese un double: ");
  printf("double ingresado: %lf\n", d);

  return 0;
}
