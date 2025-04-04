#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;
	
	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */
	
	logger = iniciar_logger();
	log_info (logger, "Prueba al inicio del codigo");

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */
	//config_create ("cliente.config");
	config = iniciar_config();
	

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = config_get_string_value (config, "IP");
	puerto = config_get_string_value (config, "PUERTO");
	valor = config_get_string_value (config, "CLAVE");
	log_info (logger, "IP: %s", ip);
	log_info (logger, "Clave: %s", valor);
	log_info (logger, "Puerto: %s", puerto);

	// Loggeamos el valor de config

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje("valor de prueba", conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);


	/* ---------------- LEER DE CONSOLA ---------------- */

	//leer_consola(logger);

	terminar_programa(conexion, logger, config);
	printf("FIN USUARIO \n");

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;
	nuevo_logger = log_create ("TP0.log", "test", 1, LOG_LEVEL_INFO);
	if(!nuevo_logger){
		perror("ALgo malio sal en LOG \n");
		exit(EXIT_FAILURE);
	}
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	nuevo_config = config_create("cliente.config");
	if(!nuevo_config){
		perror("ALgo malio sal en config \n");
		exit(EXIT_FAILURE);
	}
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	while(!string_is_empty(leido)){
		log_info (logger, "NO puedo creer que hayas dicho: %s", leido);
		free(leido);
		leido = readline("> ");
	}
	
	printf("Termine de leer lo que me diste \n");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */

	log_destroy (logger);
	config_destroy(config);
}
