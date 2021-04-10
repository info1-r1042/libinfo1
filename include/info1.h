/*!
 * @file   info1.h
 * @brief  Biblioteca de info1 para C
 * @author Javier Balloffet <jballoffet@frba.utn.edu.ar>
 * @date   Apr 10, 2021
 */
#ifndef INFO1_H_
#define INFO1_H_

// Tipo propio de (puntero a) string.
typedef char* String;

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y devuelve el char equivalente. En caso de que la
 *   validación del dato ingresado falle, solicita al usuario el ingreso de una
 *   nueva línea.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o CHAR_MAX en caso de error.
 */
char obtener_char(const String mensaje);

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y devuelve el int equivalente. En caso de que la
 *   validación del dato ingresado falle, solicita al usuario el ingreso de una
 *   nueva línea.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o INT_MAX en caso de error.
 */
int obtener_int(const String mensaje);

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y devuelve el long equivalente. En caso de que la
 *   validación del dato ingresado falle, solicita al usuario el ingreso de una
 *   nueva línea.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o LONG_MAX en caso de error.
 */
long obtener_long(const String mensaje);

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y devuelve el float equivalente. En caso de que la
 *   validación del dato ingresado falle, solicita al usuario el ingreso de una
 *   nueva línea.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o FLT_MAX en caso de error.
 */
float obtener_float(const String mensaje);

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y devuelve el double equivalente. En caso de que la
 *   validación del dato ingresado falle, solicita al usuario el ingreso de una
 *   nueva línea.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o DBL_MAX en caso de error.
 */
double obtener_double(const String mensaje);

/*!
 * @brief Solicita al usuario el ingreso de una línea de texto desde la entrada
 *   estándar (stdin) y la devuelve como un string (char*). En caso de que el
 *   usuario ingrese sólo un fin de línea, retorna un string vacío (""), no
 *   NULL. El string es almacenado en el heap, pero el destructor de la
 *   biblioteca libera la memoria al finalizar el programa.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    El valor obtenido desde stdin, o NULL en caso de error.
 */
String obtener_string(const String mensaje);

#endif // INFO1_H_
