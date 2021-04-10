/*!
 * @file   info1.c
 * @brief  Biblioteca de info1 para C
 * @author Javier Balloffet <jballoffet@frba.utn.edu.ar>
 * @date   Apr 10, 2021
 */
#include "info1.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define LARGO_MAX 100

// Arreglo de string allocados por obtener_string.
static String* strings = NULL;

// Cantidad de strings allocados por obtener_string.
static size_t strings_cant = 0;

// Función llamada automáticamente antes de comenzar la ejecución de main.
static void setup() __attribute__((constructor));

// Función llamada automáticamente luego de terminar la ejecución de main.
static void teardown();

static void setup()
{
    // Seteo la función teardown para ser llamada al terminar la ejecución.
    atexit(teardown);
}

static void teardown()
{
    // Libero strings almacenados.
    if (strings != NULL)
    {
        for (size_t i = 0; i < strings_cant; i++)
        {
            free(strings[i]);
        }
        free(strings);
    }
}

String obtener_string(const String mensaje)
{
    String str = NULL;
    String tmp = NULL;
    String* str_tmp = NULL;
    char ch = 0;
    int largo = 0;

    // Muestro mensaje de solicitud de ingreso de datos al usuario.
    if (mensaje != NULL)
    {
        printf("%s", mensaje);
    }

    while ((ch = getchar()) != '\n')
    {
        // Chequeo largo del buffer.
        if (largo >= LARGO_MAX)
        {
            free(str);
            return NULL;
        }

        // Redimensiono buffer.
        tmp = realloc(str, sizeof(char) * largo++);
        if (tmp == NULL)
        {
            free(str);
            return NULL;
        }
        str = tmp;

        // Agrego el caracter obtenido al buffer.
        str[largo - 1] = ch;
    }

    // Agrego el caracter de finalizacion.
    tmp = realloc(str, sizeof(char) * largo++);
    if (tmp == NULL)
    {
        free(str);
        return NULL;
    }
    str = tmp;
    str[largo - 1] = '\0';

    // Redimensiono el arreglo de almacenamiento de strings.
    str_tmp = realloc(strings, sizeof(String) * (strings_cant + 1));
    if (str_tmp == NULL)
    {
        free(strings);
        return NULL;
    }
    strings = str_tmp;

    // Agrego el string obtenido al arreglo.
    strings[strings_cant] = str;
    strings_cant++;

    // Retorno el string obtenido.
    return str;
}

char obtener_char(const String mensaje)
{
    String linea;

    // Solicito datos al usuario hasta que el valor ingresado sea válido.
    while (1)
    {
        // Obtengo línea ingresada, retornando CHAR_MAX en caso de error.
        linea = obtener_string(mensaje);
        if (linea == NULL)
        {
            return CHAR_MAX;
        }
    
        // Retorno un char si solo un char fue ingresado.
        if (strlen(linea) == 1)
        {
            return linea[0];
        }
    }
}

int obtener_int(const String mensaje)
{
    String linea;
    char* fin;
    long numero;

    // Solicito datos al usuario hasta que el valor ingresado sea válido.
    while (1)
    {
        // Obtengo línea ingresada, retornando INT_MAX en caso de error.
        linea = obtener_string(mensaje);
        if (linea == NULL)
        {
            return INT_MAX;
        }
    
        // Retorno un int si solo un int (con rango válido) fue ingresado.
        if (strlen(linea) > 0)
        {
            errno = 0;
            numero = strtol(linea, &fin, 10);
            if (errno == 0 && *fin == '\0' && numero >= INT_MIN && numero < INT_MAX)
            {
                return numero;
            }
        }
    }
}

long obtener_long(const String mensaje)
{
    String linea;
    char* fin;
    long numero;

    // Solicito datos al usuario hasta que el valor ingresado sea válido.
    while (1)
    {
        // Obtengo línea ingresada, retornando LONG_MAX en caso de error.
        linea = obtener_string(mensaje);
        if (linea == NULL)
        {
            return LONG_MAX;
        }
      
        // Retorno un long si solo un long (con rango válido) fue ingresado.
        if (strlen(linea) > 0)
        {
            errno = 0;
            numero = strtol(linea, &fin, 10);
            if (errno == 0 && *fin == '\0' && numero >= LONG_MIN && numero < LONG_MAX)
            {
                return numero;
            }
        }
    }
}

float obtener_float(const String mensaje)
{
    String linea;
    char* fin;
    float numero;

    // Solicito datos al usuario hasta que el valor ingresado sea válido.
    while (1)
    {
        // Obtengo línea ingresada, retornando FLT_MAX en caso de error.
        linea = obtener_string(mensaje);
        if (linea == NULL)
        {
            return FLT_MAX;
        }
    
        // Retorno un float si solo un float (con rango válido) fue ingresado.
        if (strlen(linea) > 0)
        {
            errno = 0;
            numero = strtof(linea, &fin);
            if (errno == 0 && *fin == '\0' && isfinite(numero) && numero < FLT_MAX)
            {
                return numero;
            }
        }
    }
}

double obtener_double(const String mensaje)
{
    String linea;
    char* fin;
    double numero;

    // Solicito datos al usuario hasta que el valor ingresado sea válido.
    while (1)
    {
        // Obtengo línea ingresada, retornando DBL_MAX en caso de error.
        linea = obtener_string(mensaje);
        if (linea == NULL)
        {
            return DBL_MAX;
        }
    
        // Retorno un double si solo un double (con rango válido) fue ingresado.
        if (strlen(linea) > 0)
        {
            errno = 0;
            numero = strtod(linea, &fin);
            if (errno == 0 && *fin == '\0' && isfinite(numero) && numero < DBL_MAX)
            {
                return numero;
            }
        }
    }
}
