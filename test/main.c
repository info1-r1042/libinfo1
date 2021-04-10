/*!
 * @file   main.c
 * @brief  Biblioteca de info1 para C
 * @author Javier Balloffet <jballoffet@frba.utn.edu.ar>
 * @date   Apr 10, 2021
 */
#include <stdio.h>
#include <info1.h>

int main(void) {
  String s = obtener_string("Ingrese un string: ");
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
