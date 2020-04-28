/*!
 * @file   info1.h
 * @brief  Biblioteca del curso R1042 de Informática I
 * @author Javier Balloffet <javier.balloffet@gmail.com>
 * @date   Apr 26, 2020
 */
#ifndef INFO1_H_
#define INFO1_H_

#include <stdio.h>

enum {
  EXITO = 0,
  ERROR
};

// Funciones para manejo de Entradas.

typedef char* string;

/*!
 * @brief Obtiene un char desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
char obtener_char(string mensaje);

/*!
 * @brief Obtiene un int desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int obtener_int(string mensaje);

/*!
 * @brief Obtiene un long desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
long obtener_long(string mensaje);

/*!
 * @brief Obtiene un float desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
float obtener_float(string mensaje);

/*!
 * @brief Obtiene un double desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
double obtener_double(string mensaje);

/*!
 * @brief Obtiene un string desde stdin.
 *
 * @param[in] mensaje Mensaje de solicitud de ingreso de datos.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
string obtener_string(string mensaje);

// Funciones para manejo de Archivos.

/*!
 * @brief Abre un archivo en modo lectura/escritura.
 *
 * @param[in] archivo Nombre del archivo.
 * @return    EXITO en caso de haber podido abrir el archivo correctamente, o ERROR en caso contrario.
 */
file abrir_archivo(char* archivo);

/*!
 * @brief Lee una línea del archivo.
 *
 * @param[out] var1 Puntero al arreglo de calificaciones.
 * @return     EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int leer_linea(file archivo, char* linea);

/*!
 * @brief Escribe una línea en el archivo.
 *
 * @param[in] var1 Puntero al arreglo de calificaciones.
 * @return    EXITO en caso de haber terminado la carga correctamente, o ERROR en caso contrario.
 */
int escribir_linea(file archivo, char* linea);

/*!
 * @brief Ubica el cursor al comienzo del archivo.
 */
void resetear_cursor(file archivo);

/*!
 * @brief Cierra el archivo.
 */
void cerrar_archivo(file archivo);

// Funciones para manejo de Sockets.

typedef FILE* file;

// 1. TCP - Protocolo orientado a la conexión.

// 1.1. Lado servidor.

/*!
 * @brief Abre un socket INET TCP como servidor.
 *
 * @param[in] int Puerto donde se desea abrir el socket.
 * @return    Descriptor del socket servidor en caso de éxito, o NULL en caso contrario.
 */
int abrir_socket_servidor_tcp(int puerto);

/*!
 * @brief Acepta una conexión INET TCP entrante desde un cliente.
 *
 * @param[in] int Descriptor del socket servidor.
 * @return    Descriptor del socket cliente en caso de éxito, o NULL en caso contrario.
 */
int aceptar_conexion_entrante_tcp(int socket);

// 1.2. Lado cliente.

/*!
 * @brief Abre un socket INET TCP como cliente.
 *
 * @param[in] ip Direccion IP a la que se quiere conectar.
 * @param[in] puerto Puerto al que se quiere conectar.
 * @return    Descriptor del socket en caso de éxito, o NULL en caso contrario.
 */
int abrir_socket_cliente_tcp(char* ip, int puerto);

// 1.3. Ambos lados.

/*!
 * @brief Lee datos desde un socket INET TCP.
 *
 * @param[in]  socket Descriptor del socket.
 * @param[out] buffer Buffer donde almacenar los datos recibidos.
 * @param[in]  largo Largo del buffer en bytes.
 * @return     Cantidad de bytes leídos, o ERROR en caso contrario.
 */
int recibir_datos_tcp(int socket, char* buffer, int largo);

/*!
 * @brief Escribe datos en un socket INET TCP.
 *
 * @param[in]  socket Descriptor del socket.
 * @param[out] buffer Buffer donde están almacenados los datos a enviar.
 * @param[in]  largo Cantidad de bytes a enviar.
 * @return     Cantidad de bytes enviados, o ERROR en caso contrario.
 */
int enviar_datos_tcp(int socket, char* buffer, int largo);

/*!
 * @brief Cierra un socket INET TCP.
 */
void cerrar_socket_tcp(int socket);

// 2. UDP - Protocolo orientado al envío de datos.

// 2.1. Lado servidor.

/*!
 * @brief Abre un socket INET UDP como servidor.
 *
 * @param[in] int Puerto donde se desea abrir el socket.
 * @return    Descriptor del socket servidor en caso de éxito, o NULL en caso contrario.
 */
int abrir_socket_servidor_udp(int puerto);

// 2.2. Lado cliente.

/*!
 * @brief Abre un socket INET UDP como cliente.
 *
 * @param[in] ip Direccion IP a la que se quiere conectar.
 * @param[in] puerto Puerto al que se quiere conectar.
 * @return    Descriptor del socket en caso de éxito, o NULL en caso contrario.
 */
int abrir_socket_cliente_udp(char* ip, int puerto);

// 2.3. Ambos lados.

/*!
 * @brief Lee datos desde un socket INET UDP.
 *
 * @param[in]  socket Descriptor del socket.
 * @param[out] buffer Buffer donde almacenar los datos recibidos.
 * @param[in]  largo Largo del buffer en bytes.
 * @return     Cantidad de bytes leídos, o ERROR en caso contrario.
 */
int recibir_datos_udp(int socket, char* buffer, int largo);

/*!
 * @brief Escribe datos en un socket INET UDP.
 *
 * @param[in]  socket Descriptor del socket.
 * @param[out] buffer Buffer donde están almacenados los datos a enviar.
 * @param[in]  largo Cantidad de bytes a enviar.
 * @return     Cantidad de bytes enviados, o ERROR en caso contrario.
 */
int enviar_datos_udp(int socket, char* buffer, int largo);

/*!
 * @brief Cierra un socket INET UDP.
 */
void cerrar_socket_udp(int socket);

#endif // INFO1_H_
