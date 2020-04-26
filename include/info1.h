/*!
 * @file   info1.h
 * @brief  Biblioteca del curso R1042 de Informática I
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Apr 26, 2020
 */
#ifndef INFO1_H_
#define INFO1_H_

enum {
  EXITO = 0,
  ERROR
};

typedef char* string;

// Entradas

/*!
 * @brief Obtiene un char desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
char obtener_char(string mensaje);

/*!
 * @brief Obtiene un int desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int obtener_int(string mensaje);

/*!
 * @brief Obtiene un long desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
long obtener_long(string mensaje);

/*!
 * @brief Obtiene un float desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
float obtener_float(string mensaje);

/*!
 * @brief Obtiene un double desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
double obtener_double(string mensaje);

/*!
 * @brief Obtiene un string desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
string obtener_string(string mensaje);

// Archivos

/*!
 * @brief Abre un archivo en modo lectura/escritura.
 *
 * @param[in] archivo Nombre del archivo.
 * @return	  EXITO en caso de haber podido abrir el archivo correctamente, o ERROR en caso contrario.
 */
int abrir_archivo(char* archivo);

/*!
 * @brief Lee una línea del archivo.
 *
 * @param[out] var1 Puntero al arreglo de calificaciones.
 * @return	   EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int leer_linea(char* linea);

/*!
 * @brief Escribe una línea en el archivo.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int escribir_linea(char* linea);

/*!
 * @brief Ubica el cursor al comienzo del archivo.
 */
void resetear_cursor();

/*!
 * @brief Cierra el archivo.
 */
void cerrar_archivo();

// Sockets

// Servidor

/*!
 * @brief Abre un socket UNIX.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_socket_unix(char* servicio);

/*!
 * @brief Abre un socket INET.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_socket_inet(char* servicio);

/*!
 * @brief Abre un socket UDP.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_socket_udp(char* servicio);

/*!
 * @brief Acepta una conexión entrante desde un cliente.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int aceptar_conexion_cliente(int descriptor);

// Cliente

/*!
 * @brief Abre una conexión UNIX con un servidor.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_conexion_unix(char* servicio);

/*!
 * @brief Abre una conexión INET con un servidor.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_conexion_inet(char* servicio);

/*!
 * @brief Abre una conexión UDP con un servidor.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int abrir_conexion_udp();

// Comunes

/*!
 * @brief Lee datos desde un socket.
 *
 * @param[in]  var1 Puntero al arreglo de calificaciones.
 * @param[out] var1 Puntero al arreglo de calificaciones.
 * @param[in]  var1 Puntero al arreglo de calificaciones.
 * @return	   EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int leer_socket(int socket, char* buffer, int bytes_a_leer);

/*!
 * @brief Escribe datos en un socket.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int escribir_socket(int socket, char* buffer, int bytes_a_escribir);

/*!
 * @brief Lee datos desde un socket UDP.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int leer_socket_udp(int, struct sockaddr*, int*, char*, int);

/*!
 * @brief Escribe datos en un socket UDP.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int escribir_socket_udp(int, struct sockaddr*, int, char*, int);

/*!
 * @brief Obtiene la dirección de un socket UDP.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return	  EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int obtener_direccion_udp(char*, char*, struct sockaddr*, int*);

/*!
 * @brief Cierra un socket.
 */
void cerrar_socket();

#endif // INFO1_H_
