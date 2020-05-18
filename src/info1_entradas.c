/*!
 * @file   info1_entradas.h
 * @brief  Biblioteca del curso R1042 de Informática I
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Apr 26, 2020
 */
// #include "info1.h"

#include <stdio.h>
#include <stdlib.h>

static void setup() __attribute__((constructor));

static void teardown();

static void setup() {
  printf("Setup\n");
  atexit(teardown);
}

static void teardown() {
  printf("Teardown\n");
}

int main(void) {
  return 0;
}
