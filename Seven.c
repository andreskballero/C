#include <stdio.h>
#include <ctype.h>    // contiene funciones como tolower(c)
#include <stdlib.h>

// macros o funciones? depende, las macros son menos potentes pero si se puede generar con una lo mismo que con una funci�n,
// evitan el overhead de llamada a funci�n


//////////////////////////////////7//////////////////////////////////
// INPUT AND OUTPUT

// input/output facultades no son propias de C.
// a pesar de ello, los programas interact�an con su entorno de maneras much�simo m�s complejas de las mostradas hasta
// el momento

// en este cap�tulo se va a describir la Biblioteca standard: un set de funciones para tratar con I/O, manejo de strings, 
// almacenamiento, rutinas matem�ticas, etc. (entendiendo por Biblioteca el conjunto de todas las librer�as propias de C)
// que sean "standard" permite que sean v�lidas en cualquier sistema donde se use C, y poder mover programas de un sistema 
// a otro sin cambios. esto es porque las funciones se han implementado de manera que se ejecuten de un modo u otro dependiendo
// del sistema, pero que la funcionalidad sea uniforme

// las propiedades de las Bibliotecas se especifican en los headers (.h). la Biblioteca standard de C: compuesta de librer�as (.h)







		//////////////////////////////////1//////////////////////////////////
		// STANDARD INPUT AND OUTPUT

// un text stream consiste en un conjunto de l�neas donde cada l�nea finaliza con un newline character \n
// si el sistema no funciona de dicho modo, la librer�a hace lo necesario para que parezca que funciona as�

// por ejemplo, la manera m�s sencilla de leer un char uno a uno a trav�s standard input (normalmente teclado) es con

		// int getchar(void);  // devuelve el ASCII del siguiente car�cter o de EOF, valor -1 definido en stdio.h

// Input switching: en muchos entornos, se puede sustituir el standard input teclado por un fichero. esto se hace 
// con el operador (DE L�NEA DE COMANDOS!) de redirecci�n < 
		//por ejemplo: prog <infile    // hace que el programa prog que usa getchar() lea del fichero y no de teclado

// de este <infile el programa no se dar� cuenta, se hace de tal manera para que as� sea, y tampoco estar� en argv

// tambi�n se puede hacer que la salida de un programa sea la entrada de otro con el operador de pipes (pipeline) ( | )
		//por ejemplo: otherprogram | prog   // el standard output generado por otherprogram es el standard input de prog


//la funci�n
		// int putchar(int); pone el argumento en el standard output, que por defecto es la pantalla
// putchar(c) devuelve el caracter escrito o EOF si ocurre alg�n error
// el standard output puede ser redirigido a un archivo en vez de a la pantalla, con el operador >
		// si prog usa putchar(): prog >outfile
		// si pipes se soportan: prog | anotherprog   pone el standard output de prog en el standard input de otherprog

// printf tambi�n se las apa�a para llegar al standard output pantalla; llamadas a putchar y printf son intercalables; cada
// una mostrar� lo que deba seg�n el orden de las llamadas


// cada llamada que se haga a una funci�n standard, de la biblioteca standard, cualquiera de sus librer�as,  debe hacerse despu�s
// de haberse hecho el include del archivo de cabecera que contenga la funci�n #include <stdio.h> pe

// los brackets <> inician una b�squeda del archivo en un lugar est�ndar de b�squeda








		//////////////////////////////////2//////////////////////////////////
		// FORMATTED OUTPUT - PRINTF

// printf convierte, formata y printa los argumentos en el standard output bajo el control de "format"

	// int printf(char *format, arg1, arg2, ...)
	// DEVUELVE EL N�MERO DE CARACTERES PRINTADOS!
			//int main(){
			//	char a[] = "oja";
			//	printf("%s", a); //printf(a);  //ver el porqu� de esto NO un poquito m�s abajo
			//	return 0;
			//}

// printf par�metro "format" maneja dos tipos de objetos: caracteres normales que simplemente printa y especificaciones
// de conversi�n, que causan la conversi�n de un argumento y avance al siguiente
// los objetos de especificaci�n de conversi�n empiezan con % seguidos de el car�cter de conversi�n
// si lo que sigue a % no est� especificado, el comportamiento es indefinido

	// (aqu� se habla del ancho y precisi�n)

// vigilar con que las especificaciones de conversi�n coincidan con los argumentos y sus tipos y que haya la cantdad necesaria,
// si no, el comportamiento ser� confuso

// entonces, �? por qu� printf(s) no es recomendable si s es un string y s� lo es as� printf("%s", s)
	// pues porque si s contiene %, fallar�, porque necesita contar con sus argumentos espec�ficos, es decir, m�nimo el
	// format y un argumento para la conversi�n


// una variaci�n de printf es               int sprintf(char *string, char *format, arg1, arg2, ...)
// que lo que hace es que el output generado lo almacena en string de acuerdo con format en vez de enviarlo
// al standard output. string debe, obviamente, ser lo suficientemente grande como para almacenar el output generado




		//////////////////////////////////3//////////////////////////////////
		// VARIABLE-LENGTH ARGUMENT LISTS

// la declaraci�n de printf es int printf(char *fmt, ...);

// donde ... significa que el n�mero de argumentos y sus tipos es variable. siempre debe ir al final de la lista de par�metros

// ahora si quisi�ramos implementar una copia de printf pero sin devolver el int (n�mero de caracteres), podr�a hacerse
	// void minprintf(char *fmt, ...);

// la parte interesante es ver c�mo recorrer la lista de argumentos cuando no se sabe ni su longitud ni sus tipos.
// para ello tenemos la librer�a <stdarg.h> que contiene un set de macros que definen c�mo recorrer una lista de argumentos.
// su implementaci�n var�a entre m�quinas pero su interfaz es uniforme y su funcionalidad tambi�n


// el tipo va_list: para declarar una variable que se referir� a cada argumento
	// por ejemplo: va_list ap;    // ap  = argument pointer

// la macro va_start inicializa ap para apuntar al primer argumento sin nombre. obviamente se la debe llamar antes de usar
// el primer argumento

// la macro va_arg devuelve un argumento y hace ap avanzar al siguiente (por ejemplo ival = va_arg(ap, int);
// la macro va_end limpia todo lo necesario








		//////////////////////////////////4//////////////////////////////////
		// FORMATTED INPUT - SCANF

// an�logo, pero en input, del printf	
		// int scanf(char *format, ...)

// scanf lee caracteres del standard input (teclado), los intepreta seg�n la especificaci�n de format y almacena los
// resultados en los argumentos siguientes sin especificar (que deben ser PUNTEROS! TODOS!!!!)

// scanf se detiene cuando se acaba el format string o cuando hay alg�n tipo de error en el input.
// devuelve el n�mero de inputs correctamente le�dos y asignados a los argumentos

// cuando acabe el input, se devuelve EOF, que no es lo mismo que devolver 0, que significa que el siguiente input character
// no encaja con la especficaci�n de format

		// (tambi�n existe la funci�n int sscanf(char *string, char *format, ...) que lee de un input string en vez del standard input)
		// sscanf(line, "%d/%d/%d", &day, &month, &year);

// la conversi�n del input se asigna a su input field (argumento) respectivo, en orden. un input field se define como un string sin
// white characters (blank, tab, newline, carriage return, vertical tab and formfeed)

		//int main() {
		//	// por ejemplo, para leer 25 feb 1993 ...
		//	//int day, year;
		//	//char monthname[20];
		//	//	// day y year no son punteros, pero como scanf debe recibir punteros, se le pasa sus direcciones con el operador de
		//	//	// direcci�n de memoria &. monthname no, ya sabes por qu�
		//	//scanf("%d, %s, %d", &day, monthname, &year);
		//
		//	// por ejemplo, para leer 25/02/1993 ...
		//	int day, month, year;
		//	// el string format puede contener chars que aparezcan literalmente (/) siempre que en el input tambi�n se encuentren
		//	scanf("%d/%d/%d", &day, &month, &year);
		//
		//	return 0;
		//}

//scanf ignora blanks y tabs, es m�s, se salta los white spaces mientras busca input values.

// para leer un input cuyo formato de input fields no est� definido, es mejor hacerlo l�nea a l�nea (ver en libro)








		//////////////////////////////////5//////////////////////////////////
		// FILE ACCESS

// el sistema operativo define como standard input el teclado y como standard output la pantalla. esto lo define para cualquier programa
 
// pero c�mo se puede hacer que un programa acceda a un archivo que no est� conectado al programa?

// por ejemplo, el programa cat (pe.  cat x.c y.c  concatena y printa x.c e y.c en el standard output) concatena archivos de texto
// y los env�a al standard output

// la cuesti�n es c�mo conseguir leer los archivos, es decir, c�mo conectar los nombres externos a los elementos para leerlos

// SIMPLE: antes de leer o escribir un archivo, debe ser "abierto" por la library function fopen. fopen coge una referencia externa
// tipo x.c y negocia con el sistema operativo, devolviendo un puntero para usarse en las subsiguientes lecturas o escrituras del
// fichero

// a este puntero se le llama file pointer. apunta a una struct que contiene informaci�n sobre el archivo, tipo la localizaci�n del
// buffer, si se est� leyendo o escribiendo el archivo, ...
// pero nosotros no necesitamos saber nada porque la declaraci�n de la struct y definici�n de su consecuente tipo viene 
// en <stdio.h> y se declara...

		//FILE *fp;
		//FILE *fopen(char *name, char *mode);

// fp es un puntero a FILE, y fopen devuelve un puntero a FILE

// la llamada a fopen es...       fp = fopen(name, mode);

// name es un string que contiene el nombre del archivo externo a conectar al puntero, mode es tambi�n un string pero indica
// para qu� se va a usar el archivo ("r" para leer, "w" para escribir, "a" para append)



// si se abre, para escritura o append, un fichero que no existe, lo que se hace es crearlo, si no hay ning�n problema
// abrir un archivo ya existente para escritura descarta todo el contenido que ten�a para a�adir el nuevo
// append abre el archivo para escribir pero conserva su contenido ya existente

// si se abre, para lectura, un fichero que no existe, entonces s� da error
// hay m�s causas de error, como puede ser acceder a un fichero para el que no se tenga permiso de acceso

// ante error, fopen devuelve NULL

// ahora, necesitamos poder manejarlo una vez ya lo tenemos asociado a un puntero para poder actuar con �l
// hay funciones, como getc o putc
		// int getc(FILE *fp) devuelve el siguiente char referido por fp del fichero; EOF si hay error o EOF
		// int putc(int c, FILE *fp) escribe el char c en el archivo fp y devuelve el char escrito o EOF si hay alg�n error



// cuando un programa en C se arranca, el entorno del sistema operativo es el encargado de abrir tres archivos y proporcionar
// punteros a ellos. estos archivos son standard input, standard output y el standard error
// sus punteros son stdin, stdout, stderr  ---> declarados en <stdio.h>

// stdin, stdout y stderr son output streams

// estos punteros son constantes, por lo que no pueden reasignarse

// stdin est� por defecto conectado al teclado; stdout y stderr a la pantalla; se puede cambiar, como se ha visto en el punto 7

// entonces getchar y putchar pueden redefinirse en t�rminos de getc y putc mediante macros, y ya sabes que en las macros
// se sobreescribe el valor output de un valor input que se pretenda redefinir y ya exista
		// #define getchar() getc(stdin)
		// #define putchar(c) putc((c), stdout)


// las funciones fprintf() y fscanf() pueden usarse de igual modo que las normales pero en este caso para input y output archivos
// son id�nticas a las otras pero en este caso, de manera an�loga a sscanf o sprintf, el primer argumento cambia. 
// se trata del puntero que representa el archivo abierto para ser le�do o escrito
		//int fprintf(FILE *fp, char *format, ...)
		//int fscanf(FILE *fp, char *format, ...)




// cuando se acaba de tratar con el archivo, la manera de cerrarlo es un fclose, la inversa a fopen
		// int fclose(FILE *fp)
// rompe la conexi�n entre el puntero y el archivo, liberando el puntero para que se pueda usar para otro archivo
// es recomendable hacerlo siempre. aunque al terminar la ejecuc�n de un programa normalmente se llama autom�ticamente,
// el sistema operativo suele imponer l�mites en cuanto al n�mero de archivos que puede tener abierto un programa de manera
// simult�nea, por lo que se recomienda liberar los punteros que apuntan a ellos una vez se finalice con su uso










		//////////////////////////////////6//////////////////////////////////
		// ERROR HANDLING

// los errores hay que tratarlos bien. por ejemplo en cat, si alg�n archivo no se puede acceder por lo que sea, el error
// se printa al final del output, lo cual puede aceptarse si es para enviarlo al standard output, pero no si es para enviarlo
// a otro output (como un archivo u otro programa v�a pipeline)

// para manejar esto bien usaremos uno de los tres archivos que nos proporciona el SO, stderr
// normalmente el stderr se printa en pantalla independientemente de que el standard output haya sido redirigido a otro lugar que 
// no sea la pantalla

		// c�digo de programejo

// se guarda el nombre del programa as� char *prog = argv[0];

// en el caso del c�digo se manejan los errores de dos maneras: 
	// 1) se env�a el contenido de fprintf a stderr --> fprintf(stderr, "%s: no se puede abrir %s\n", prog, *argv)

	// 2) y el programa usa la funci�n de librer�a standard exit() que termina con la ejecuci�n del programa cuando se le llama
	// el argumento de exit est� disponible para cualquier programa que haya llamado a este, para que pueda comprobar la ejecuci�n
	// del sub-programa ejecutado y usar su estado exit

	// de exit(), el argumento 0 es que todo ha ido normal, y != 0 es que ha habido alg�n error (situaciones anormales)
	// exit() llama a fclose para cada archivo que haya sido abierto durante la ejecuci�n del programa (y de esta manera libera
	// cualquier stream output que hubiera sido almacenado)

// en int main(), "return expr" es equivalente a "exit (expr)", pero exit() tiene la ventaja de que puede llamarse desde cualquier
// subrutina y terminar con la ejecuci�n del programa

// la funci�n ferror(FILE *fp) devuelve no-cero si ha ocurrido un error en el stream fp
// la funci�n feof(FILE *fp) devuelve no-cero si EOF ha ocurrido en un fichero concreto

// todos los programas deben controlar esto, porque los errores pueden ocurrir (por ejemplo cuando un disco est� lleno), y debe
// ser una pr�ctica manejada debidamente (el control de errores)










		//////////////////////////////////7//////////////////////////////////
		// LINE INPUT AND OUTPUT

// la biblioteca standard provee una funci�n/rutina que sirve para leer l�neas en vez de chars solos, como hace getchar()
	// char *fgets(char *line, int maxline, FILE *fp)
	// la funci�n lee la siguiente l�nea (incluido \n), de m�ximo maxline-1 chars y la almacena en line (line termina con '\0')
	// en EOF o error, fgets devuelve NULL

// tambi�n una funci�n para escribir l�neas en un archivo
	// int fputs(char *line, FILE *fp)
	// devuelve EOF si ocurre un error; 0 si todo va bien

// las funciones gets() y puts() son an�logas a fgets y fputs, pero interact�an con stdin y stdout respectivamente en vez de con
// un fichero normal

		// gets elimina '\n' y puts lo a�ade, a diferencia de las fgets














		//////////////////////////////////8//////////////////////////////////
		// MISCELLANEOUS FUNCTIONS

// funciones m�s �tiles de la biblioteca standard de C

	// STRING OPERATIONS <string.h>
	// CHARACTER CLASS TESTING AND CONVERSION <ctype.h>
	// ungetc
	// COMMAND EXECUTION
			// la funci�n system(char *s) ejecuta el comando contenido en s y contin�a con la ejecuci�n del programa
			// los comandos var�an entre sistemas operativos
			// por ejemplo system("date") ejecuta el programa date de UNIX que devuelve por standard output la fecha
			// system devuelve un valor int system-dependent status, que en UNIX es el valor devuelto por exit()

	// STORAGE MANAGEMENT
			// malloc and calloc obtienen bloques de memoria din�micamente
				//void *malloc(size_t n)   devuelve un puntero de n bytes de almacenamiento no inicializado; NULL si no es posible
				//void *calloc(size_t n, size_t size) devuelve un puntero a suficiente espacio para un array de n objetos de un tipo
				// espec�fico; NULL si no se puede satisfacer. el almacenamiento se inicializa a 0

			// el puntero devuelto por malloc y calloc tiene el alineamiento en memoria requerido, pero debe ser casteado al tipo
			// deseado 

				//int *ip;
				//
				//ip = (int *) calloc(n, sizeof(int));

			// free(p) libera el espacio apuntado por p, donde o se obtuvo originalmente con malloc o calloc
			// no hay restricciones de liberaci�n de espacio, pero lo que no se puede hacer es liberar un puntero a un espacio
			// de memoria que no ha sido reservado

			// y cuidado con usar un puntero que ya haya sido liberado!
				

	// MATHEMATICAL FUNCTIONS <math.h>
			// todas reciben tipos double para todos los argumentos
			

	// RANDOM NUMBER GENERATION
			// rand() genera un pseudorand n�mero desde 0 hasta RAND_MAX definido en <stdlib.h>
			// srand(unsigned) pone la semilla rand