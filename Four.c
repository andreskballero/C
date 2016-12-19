#include <stdio.h>
#include <string.h>

// IMPORTANTEEEEEEEEEEEEEEEEEE
// compilar un fichero genera un fichero objeto con el c�digo objeto (ensamblador normalmente; c�digo
// m�quina (bit) no es lo que contienen los ficheros objeto) ENSAMBLADOR != CODIGO M�QUINA

//////////////////////////////////4//////////////////////////////////
// FUNCTIONS AND PROGRAM STRUCTURE

// bloques de c�digo que se ven como una �nica instrucci�n.
// permiten usarse para facilitar la programaci�n (propias y ajenas (librer�as))

// mejor muchas funciones peque�as que pocas muy grandes
// un programa se compone de uno o m�s fucheros fuente



		//////////////////////////////////1//////////////////////////////////
		// BASICS O FUNCTIONS

// manera para mirar que x elementos formen parte de un array teniendo en cuenta
// que no se llegue a un outofindex en el final del array (como podr�a pasar
// haciendo if (s[i+3] == t[j]), por ejemplo, si estamos en la �ltima posici�n del array s.

		//int strindex(char s[], char t[]) {
		//	int i, j, k;
		//
		//	for (i = 0; s[i] != '\0'; ++i) {
		//		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++k, ++j);
		//
		//		if (k == strlen(t) && t[k] == '\0') {
		//			return i;
		//		}
		//	}
		//	return -1;
		//}

//tipo - retorno  nombre - funci�n(par�metros) {
//	declaraciones e instrucciones
//}

// existen las funciones vac�as tipo dummy() {}
// si omiten el tipo de return, se asume que es int (int dummy() {})

// los return no exigen una expresi�n a devolver, por lo que no se devuelve nada
// una funci�n vuelve al caller con un return o, si no hay, cuando se llega a }

// AQU� SE EXPLICA C�MO SE COMPILA EN UNIX UN PROGRAMA QUE TIENE 3 FICHEROS FUENTE!!!!!!

				// EJERCICIO 4.1
				// igual que antes pero el de m�s a la derecha
				/*int strindex(char s[], char t[]) {
					int i, j, k, max;
					max = -1;

					for (i = 0; s[i] != '\0'; ++i) {
						for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++k, ++j);

						if (k > 0 && t[k] == '\0') {
							max = i;
						}
					}
					return max;
				}*/



		//////////////////////////////////2//////////////////////////////////
		// FUNCTIONS RETURNING NON INTEGERS

// las funciones deben tener FUNCTION PROTOTYPE para validar lo que devuelven
// si se va a usar una funci�n que no ha sido declarada (como atof(char[])) y se sabe que devuelve
// un valor no int, se debe hacer
// double sum, atof(char[]); =======> sum es una variable de tipo double y la funci�n atof devuelve un double

// si una funci�n sin prototipo se usa sin haberse declarado en el caller, se asume que devuelve un int
// si una funci�n no tiene par�metros (= no recibe argumentos), mejor poner "void" que dejarlo as� ()

/*int atoi(char s[]) {
	double atof(char s[]);

	return (int)atof(s);
}*/

// aqu� se ha podido ver que la funci�n atof() se declara como double. pero atoi devuelve int porque
// para empezar se hace cast, y si no se hiciera, tambi�n se convertir�a a int porque atoi devuelve int



		//////////////////////////////////3//////////////////////////////////
		// EXTERNAL VARIABLES

// funciones son externas. variables tambi�n pueden serlo.
// c no permite definir funciones dentro de funciones
// variables externas son potencialmente accesibles por muchas funciones

// como son globalmente accesibles, son una alternativa a los argumentos de una funci�n
// facilitan la comunicaci�n de datos entre funciones
// pero usarlas con cuidado, ya que las variables externas pueden desembocar en demasiada relaci�n
// indirecta entre funciones (pero son preferibles a largu�simas listas de argumentos)

// las variables externas existen siempre. las autom�ticas, cuando se llama a una funci�n se crean,
// y cuando termina la funci�n se destruyen

// si dos fnciones deben compartir datos pero no se llaman m�tuamente, es mejor usar variables 
// externas que argumentos


			//Las declaraciones introducen nombres en un programa, por ejemplo, nombres de variables, 
			//espacios de nombres, funciones y clases.Las declaraciones tambi�n especifican informaci�n 
			//de tipos y otras caracter�sticas del objeto que se declara.Antes de poder usar un nombre,
			//hay que declararlo; en C++, el punto en el que se declara un nombre determina si es visible
			//para el compilador.No se puede hacer referencia a una funci�n o clase que se declara en alg�n 
			//punto posterior de la unidad de compilaci�n; para superar esta limitaci�n, pueden usarse
			//declaraciones adelantadas.
			//
			//en variables locales, se declara y define a la vez
			//en funciones, se declara en el prototype y se define desarrollando la funci�n
			//en variables externas... siguiente punto
			//
			//Las definiciones especifican qu� c�digo o datos describe el nombre.El compilador necesita 
			//la definici�n a fin de asignar espacio de almacenamiento para el elemento que se declara.
			//El programa sabe que debe reservar un espacio en memoria para almacenar el valor de la variable


			//A declaration introduces an identifier and describes its type, be it a type, object, or function.
			//A declaration is what the compiler needs to accept references to that identifier.
			//A definition actually instantiates / implements this identifier.It's what the linker needs in order
			//to link references to those entities.



			/*int val = 20;

			main() {
			//extern int val; // en este caso el extern pod�a ser omitido
			printf("%d\n", val);
			return 0;
			}*/

			// una variable externa se define. despu�s, si las funciones quieren acceder a la misma, no es necesario
			// que la declaren (extern int val es redundante si la funci�n est� en el mismo fichero).

			// cuando s� es necesario declararla con extern es cuando una funci�n accede a una variable global
			// que se encuentre en otro fichero fuente, o cuando una funci�n vaya a usar una variable global que
			// a�n no haya sido definida


		//////////////////////////////////4//////////////////////////////////
		// SCOPE RULES

// el scope es d�nde se puede usar un determinado nombre
// el scope de una variable local es la funci�n donde se declara. ya sabes que variables locales
// con mismo nombre en distintas funciones no tienen nada que ver
// lo mismo pasa con los par�metros de una funci�n, que no dejan de ser variables locales

// la diferencia entre declarar y definir una variable local: declarar es caracterizar las propiedades
// de la variable (su tipo), mientras que definir guarda el espacio necesario en memoria para almacenarla.
// se inicializa cuando se define

// int val; ==> esto fuera de cualquier funci�n es una definici�n de la variable y tambi�n una declaraci�n

// s�lo puede haber una definici�n de una variable externa entre todos los ficheros fuente de un programa
// los otros pueden contener extern declarations de esa variable para poder acceder a ella

				//file 1: 
				//extern int sp;
				//extern double val[];
				//
				//funciones...
				//
				//file 2:
				//int sp = 0;
				//double val[MAXVAL];


		//////////////////////////////////5//////////////////////////////////
		// HEADER FILES

// header files (.h) sirven para centralizar todas las declaraciones de funciones relacionadas
// variables, constantes,... ; se debe hacer un include del fichero, y despu�s en los dem�s ficheros que hagan include
// de ese .h se definen las funciones

//A header file is a file with extension.h which contains C function declarations and macro definitions 
//to be shared between several source files.There are two types of header files : the files that the 
//programmer writes and the files that comes with your compiler.
//
//You request to use a header file in your program by including it with the C preprocessing directive #include,
//like you have seen inclusion of stdio.h header file, which comes along with your compiler.



		//////////////////////////////////6//////////////////////////////////
		// STATIC VARIABLES

// declaraci�n static hace que las variables globales de un fichero se limiten �nicamente a ese
// fichero y no puedan ser accesibles desde fuera

// static permite ocultar a los usuarios las variables que usan funciones que pueden ser llamadas 
// (puedes llamar a una funci�n de un fichero, esta usa una variable static que no puede ser accedida
// directamente desde fuera con un "extern")

// ocultando las variables se previene de conflictos con otras variables del programa con el mismo nombre

// tambi�n se puede usar static para funciones, pero seguir�n siendo visibles desde otros ficheros (?)


		//////////////////////////////////7//////////////////////////////////
		// REGISTER VARIABLES

// register declaration avisa de que la variable esta siendo MUY usada
// register declaration hace que esas variables se almacenen en los registros de la cpu para hacer
// los programas mucho m�s r�pidos, pero el compilador puede ignorar esta recomendaci�n

// se declaran as�: register int x;

// s�lo se pueden usar para variables autom�ticas y para par�metros de una funci�n



		//////////////////////////////////8//////////////////////////////////
		// BLOCK STRUCTURE

// dentro de una funci�n no se pueden definir m�s funciones
// dentro de una funci�n, entre {} se pueden definir variables
// las variables definidas dentro de cualquier bloque (por ejemplo un if () { int i; }) hace que el scope
// de la variable sea el bloque, es decir, i se crear� al entrar en el if (true) y se destruir�
// al salir de �l

// si a la variable de un bloque se le pone static, s�lo se inicializa una vez cuando se
// entra por primera vez al bloque

// ya sabes que este scope hace que se puedan tener varias variables con el mismo nombre
// como por ejemplo: las referencias a x fuera de f() son a la x global, mientras que dentro
// de f() son al par�metro, a la copia local de la variable

//int x;
//
//f(double x) {
//	tal
//}

// de todos modos, tratar de evitar variables con los mismos nombres



		//////////////////////////////////9//////////////////////////////////
		// INITIALIZATION

// si variables externas o static no se inicializan, por defecto se inicializan a 0
// variables autom�ticas o register se inicializan a un valor indefinido (basura)

// variables pueden inicializarse al definirse (tanto externas y static como autom�ticas y de registro):
		// int s = 0;
		// char quote = '\'';
		// long x = 1000 * 60L * 60L * 24; // milisegundos del d�a

// para externas y static la inicializaci�n debe ser una expresi�n constante;
// y la inicializaci�n de estas se hace una �nica vez, conceptualmente antes de
// iniciarse el programa (a diferencia de las autom�ticas que es cada vez que se entra
// a su bloque (ya sabes))

// para autom�ticas y registro la inicializaci�n puede ser una expresi�n no constante:
		//int culo(int x) {
		//	int ojal = x - 1;
		//}


// se puede inicializar al definir o m�s tarde, m�s pr�ximas a donde se vayan a usar; Cuesti�n de gustos

// un array se puede inicializar con {}, int array[] = {31, 32, 33}; (esto lo inicializa a tama�o 3)
// si el array es m�s grande que la cantidad de inicializadores, el resto ser�n 0 en external, static y aut.variables
// (no se puede inicializar un valor intermedio sin proporcionar todos los valores anteriores)

		//string no deja de ser un char array con '\0' al final
// en el caso de los char arrays, los strings que contienen se inicializan:
//char s[] = "culo";
//char s[] = { 'c', 'u', 'l', 'o', '\0' };
// en ambos casos el tama�o del array es 5 (acu�rdate del car�cter null)



		//////////////////////////////////10//////////////////////////////////
		// RECURSION

// ya sabes como funcionan, necesitan un caso para seguir llam�ndose y otro para finalizar
// con las llamadas y empezar a devolver los resultados.

// no es m�s r�pida ni salva espacio, pero resulta en c�digo m�s compacto


//int factorial(int);
//
//int factorial(int i) {
//
//	if (i > 1) {
//		return i * factorial(i-1); // NO factorial(--i) PORQUE ENTONCES SE DECREMENTA i DE ESA ITERACI�N!!!!!!
//	}
//	else {
//		return 1;
//	}
//}
//
//int main() {
//	printf("%d\n", factorial(5));
//}

		//////////////////////////////////11//////////////////////////////////
		// THE C PREPROCESSOR

//Un preprocesador es un programa separado que es invocado por el compilador antes de 
//que comience la traducci�n real. Un preprocesador de este tipo puede eliminar los comentarios,
//incluir otros archivos y ejecutar sustituciones de macros.

// proporciona facilidades de lenguaje
// primer paso en la compilaci�n
// las dos caracter�sticas m�s usadas son #include (incluir fichero) y #define (asociar valor a un token)

		// FILE INCLUSION (#include)
	//#include <> � "" hace que esta expresi�n se reemplace por el contenido del fichero incluido
	// para manejar de mejor manera declaraciones y #defines
	// include es la mejor manera de agrupar declaraciones de funciones, por ejemplo, como en los .h
	// tipo stdio.h


		// MACRO SUBSTITUTION
	// macro significa macro definition
	
	//#define CUATRO 4 no es una macro sino una CONSTANTE SIMB�LICA

	// #define name replaced-text  (si es muy larga, situar \ al final de cada l�nea
	// su scope es del fichero al que pertenece, desde el principio hasta el final
	// una definici�n puede usar definiciones previas! y obviamente no va entre " "

	// no simplemente pueden asociarse a texto, sino tambi�n a macros, por ejemplo

	// #define forever for (;;)       donde forever representar� un bucle infinito
	// #define max(A,B) ((A) > (B) ? (A) : (B))

		// esto puede parecer una funci�n, pero no lo es. lo �nico que hace es sustituir en una
		// l�nea de c�digo, el max(A,B) por su replaced-text, pero no funciona como una funci�n
		// lo bueno es que esto servir� para cualquier tipo de datos de A y B

	// #undef sirve para decir que una rutina es realmente una funci�n, no una macro

	// si son STRINGSlos par�metros de una macro se marcan con # en el replaced-text,
	// si no, no llevan ning�n operador
	// # en replaced text lo sustituir� por el car�cter entre dobles comillas
	// #define dprint(expr) printf(#expr "= %g\n", expr)

	// el operador ## del preprocessor sirve para concatenar argumentos, de manera que
	// #define paste(front, back) front ## back          esto dar�a name1 si paste(name,1)


				//EJERCICIO 4.14
				//#define swap(t, x, y) {t tmp; tmp = x; x = y;y = tmp;}
				//#define max(A,B) ((A) > (B) ? (A) : (B))
				//
				//int main(void)
				//{
				//	int ia = 20, ib = 35;
				//	printf("before swap: %d, %d\n", ia, ib);
				//	swap(int, ia, ib)
				//	printf(" after swap: %d, %d, %d\n", ia, ib, max(ia, ib));
				//
				//	return 0;
				//}



// CONDITIONAL INCLUSION

// se puede controlar el preprocessor mientras se preprocesa, mediante condiciones!
// #ifdef, #ifndef, #else, #elif y #endif

//#if !defined(HDR)                       esto es igual que #ifndef HDR
//#define HDR "culito.h"
//#endif
// con esto, la primera inclusi�n de hdr.h definir� HDR. las dem�s pasar�n al #endif directamente
// por ejemplo, analizar SYSTEM

// ahora vemos como SYSTEM decide que fichero header se incluye
		//#if SYSTEM == SYSV
		//	#define HDR "sysv.h"
		//#elif SYSTEM == BSD
		//	#define HDR "bsd.h"
		//#else
		//	#define HDR "default.h"
		//#endif
		//#include HDR

// #ifdef y #ifndef son lo mismo que #if defined(tal) y #if !defined(tal) respectivamente