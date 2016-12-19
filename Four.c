#include <stdio.h>
#include <string.h>

// IMPORTANTEEEEEEEEEEEEEEEEEE
// compilar un fichero genera un fichero objeto con el código objeto (ensamblador normalmente; código
// máquina (bit) no es lo que contienen los ficheros objeto) ENSAMBLADOR != CODIGO MÁQUINA

//////////////////////////////////4//////////////////////////////////
// FUNCTIONS AND PROGRAM STRUCTURE

// bloques de código que se ven como una única instrucción.
// permiten usarse para facilitar la programación (propias y ajenas (librerías))

// mejor muchas funciones pequeñas que pocas muy grandes
// un programa se compone de uno o más fucheros fuente



		//////////////////////////////////1//////////////////////////////////
		// BASICS O FUNCTIONS

// manera para mirar que x elementos formen parte de un array teniendo en cuenta
// que no se llegue a un outofindex en el final del array (como podría pasar
// haciendo if (s[i+3] == t[j]), por ejemplo, si estamos en la última posición del array s.

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

//tipo - retorno  nombre - función(parámetros) {
//	declaraciones e instrucciones
//}

// existen las funciones vacías tipo dummy() {}
// si omiten el tipo de return, se asume que es int (int dummy() {})

// los return no exigen una expresión a devolver, por lo que no se devuelve nada
// una función vuelve al caller con un return o, si no hay, cuando se llega a }

// AQUÍ SE EXPLICA CÓMO SE COMPILA EN UNIX UN PROGRAMA QUE TIENE 3 FICHEROS FUENTE!!!!!!

				// EJERCICIO 4.1
				// igual que antes pero el de más a la derecha
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
// si se va a usar una función que no ha sido declarada (como atof(char[])) y se sabe que devuelve
// un valor no int, se debe hacer
// double sum, atof(char[]); =======> sum es una variable de tipo double y la función atof devuelve un double

// si una función sin prototipo se usa sin haberse declarado en el caller, se asume que devuelve un int
// si una función no tiene parámetros (= no recibe argumentos), mejor poner "void" que dejarlo así ()

/*int atoi(char s[]) {
	double atof(char s[]);

	return (int)atof(s);
}*/

// aquí se ha podido ver que la función atof() se declara como double. pero atoi devuelve int porque
// para empezar se hace cast, y si no se hiciera, también se convertiría a int porque atoi devuelve int



		//////////////////////////////////3//////////////////////////////////
		// EXTERNAL VARIABLES

// funciones son externas. variables también pueden serlo.
// c no permite definir funciones dentro de funciones
// variables externas son potencialmente accesibles por muchas funciones

// como son globalmente accesibles, son una alternativa a los argumentos de una función
// facilitan la comunicación de datos entre funciones
// pero usarlas con cuidado, ya que las variables externas pueden desembocar en demasiada relación
// indirecta entre funciones (pero son preferibles a larguísimas listas de argumentos)

// las variables externas existen siempre. las automáticas, cuando se llama a una función se crean,
// y cuando termina la función se destruyen

// si dos fnciones deben compartir datos pero no se llaman mútuamente, es mejor usar variables 
// externas que argumentos


			//Las declaraciones introducen nombres en un programa, por ejemplo, nombres de variables, 
			//espacios de nombres, funciones y clases.Las declaraciones también especifican información 
			//de tipos y otras características del objeto que se declara.Antes de poder usar un nombre,
			//hay que declararlo; en C++, el punto en el que se declara un nombre determina si es visible
			//para el compilador.No se puede hacer referencia a una función o clase que se declara en algún 
			//punto posterior de la unidad de compilación; para superar esta limitación, pueden usarse
			//declaraciones adelantadas.
			//
			//en variables locales, se declara y define a la vez
			//en funciones, se declara en el prototype y se define desarrollando la función
			//en variables externas... siguiente punto
			//
			//Las definiciones especifican qué código o datos describe el nombre.El compilador necesita 
			//la definición a fin de asignar espacio de almacenamiento para el elemento que se declara.
			//El programa sabe que debe reservar un espacio en memoria para almacenar el valor de la variable


			//A declaration introduces an identifier and describes its type, be it a type, object, or function.
			//A declaration is what the compiler needs to accept references to that identifier.
			//A definition actually instantiates / implements this identifier.It's what the linker needs in order
			//to link references to those entities.



			/*int val = 20;

			main() {
			//extern int val; // en este caso el extern podía ser omitido
			printf("%d\n", val);
			return 0;
			}*/

			// una variable externa se define. después, si las funciones quieren acceder a la misma, no es necesario
			// que la declaren (extern int val es redundante si la función está en el mismo fichero).

			// cuando sí es necesario declararla con extern es cuando una función accede a una variable global
			// que se encuentre en otro fichero fuente, o cuando una función vaya a usar una variable global que
			// aún no haya sido definida


		//////////////////////////////////4//////////////////////////////////
		// SCOPE RULES

// el scope es dónde se puede usar un determinado nombre
// el scope de una variable local es la función donde se declara. ya sabes que variables locales
// con mismo nombre en distintas funciones no tienen nada que ver
// lo mismo pasa con los parámetros de una función, que no dejan de ser variables locales

// la diferencia entre declarar y definir una variable local: declarar es caracterizar las propiedades
// de la variable (su tipo), mientras que definir guarda el espacio necesario en memoria para almacenarla.
// se inicializa cuando se define

// int val; ==> esto fuera de cualquier función es una definición de la variable y también una declaración

// sólo puede haber una definición de una variable externa entre todos los ficheros fuente de un programa
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
// variables, constantes,... ; se debe hacer un include del fichero, y después en los demás ficheros que hagan include
// de ese .h se definen las funciones

//A header file is a file with extension.h which contains C function declarations and macro definitions 
//to be shared between several source files.There are two types of header files : the files that the 
//programmer writes and the files that comes with your compiler.
//
//You request to use a header file in your program by including it with the C preprocessing directive #include,
//like you have seen inclusion of stdio.h header file, which comes along with your compiler.



		//////////////////////////////////6//////////////////////////////////
		// STATIC VARIABLES

// declaración static hace que las variables globales de un fichero se limiten únicamente a ese
// fichero y no puedan ser accesibles desde fuera

// static permite ocultar a los usuarios las variables que usan funciones que pueden ser llamadas 
// (puedes llamar a una función de un fichero, esta usa una variable static que no puede ser accedida
// directamente desde fuera con un "extern")

// ocultando las variables se previene de conflictos con otras variables del programa con el mismo nombre

// también se puede usar static para funciones, pero seguirán siendo visibles desde otros ficheros (?)


		//////////////////////////////////7//////////////////////////////////
		// REGISTER VARIABLES

// register declaration avisa de que la variable esta siendo MUY usada
// register declaration hace que esas variables se almacenen en los registros de la cpu para hacer
// los programas mucho más rápidos, pero el compilador puede ignorar esta recomendación

// se declaran así: register int x;

// sólo se pueden usar para variables automáticas y para parámetros de una función



		//////////////////////////////////8//////////////////////////////////
		// BLOCK STRUCTURE

// dentro de una función no se pueden definir más funciones
// dentro de una función, entre {} se pueden definir variables
// las variables definidas dentro de cualquier bloque (por ejemplo un if () { int i; }) hace que el scope
// de la variable sea el bloque, es decir, i se creará al entrar en el if (true) y se destruirá
// al salir de él

// si a la variable de un bloque se le pone static, sólo se inicializa una vez cuando se
// entra por primera vez al bloque

// ya sabes que este scope hace que se puedan tener varias variables con el mismo nombre
// como por ejemplo: las referencias a x fuera de f() son a la x global, mientras que dentro
// de f() son al parámetro, a la copia local de la variable

//int x;
//
//f(double x) {
//	tal
//}

// de todos modos, tratar de evitar variables con los mismos nombres



		//////////////////////////////////9//////////////////////////////////
		// INITIALIZATION

// si variables externas o static no se inicializan, por defecto se inicializan a 0
// variables automáticas o register se inicializan a un valor indefinido (basura)

// variables pueden inicializarse al definirse (tanto externas y static como automáticas y de registro):
		// int s = 0;
		// char quote = '\'';
		// long x = 1000 * 60L * 60L * 24; // milisegundos del día

// para externas y static la inicialización debe ser una expresión constante;
// y la inicialización de estas se hace una única vez, conceptualmente antes de
// iniciarse el programa (a diferencia de las automáticas que es cada vez que se entra
// a su bloque (ya sabes))

// para automáticas y registro la inicialización puede ser una expresión no constante:
		//int culo(int x) {
		//	int ojal = x - 1;
		//}


// se puede inicializar al definir o más tarde, más próximas a donde se vayan a usar; Cuestión de gustos

// un array se puede inicializar con {}, int array[] = {31, 32, 33}; (esto lo inicializa a tamaño 3)
// si el array es más grande que la cantidad de inicializadores, el resto serán 0 en external, static y aut.variables
// (no se puede inicializar un valor intermedio sin proporcionar todos los valores anteriores)

		//string no deja de ser un char array con '\0' al final
// en el caso de los char arrays, los strings que contienen se inicializan:
//char s[] = "culo";
//char s[] = { 'c', 'u', 'l', 'o', '\0' };
// en ambos casos el tamaño del array es 5 (acuérdate del carácter null)



		//////////////////////////////////10//////////////////////////////////
		// RECURSION

// ya sabes como funcionan, necesitan un caso para seguir llamándose y otro para finalizar
// con las llamadas y empezar a devolver los resultados.

// no es más rápida ni salva espacio, pero resulta en código más compacto


//int factorial(int);
//
//int factorial(int i) {
//
//	if (i > 1) {
//		return i * factorial(i-1); // NO factorial(--i) PORQUE ENTONCES SE DECREMENTA i DE ESA ITERACIÓN!!!!!!
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
//que comience la traducción real. Un preprocesador de este tipo puede eliminar los comentarios,
//incluir otros archivos y ejecutar sustituciones de macros.

// proporciona facilidades de lenguaje
// primer paso en la compilación
// las dos características más usadas son #include (incluir fichero) y #define (asociar valor a un token)

		// FILE INCLUSION (#include)
	//#include <> ó "" hace que esta expresión se reemplace por el contenido del fichero incluido
	// para manejar de mejor manera declaraciones y #defines
	// include es la mejor manera de agrupar declaraciones de funciones, por ejemplo, como en los .h
	// tipo stdio.h


		// MACRO SUBSTITUTION
	// macro significa macro definition
	
	//#define CUATRO 4 no es una macro sino una CONSTANTE SIMBÓLICA

	// #define name replaced-text  (si es muy larga, situar \ al final de cada línea
	// su scope es del fichero al que pertenece, desde el principio hasta el final
	// una definición puede usar definiciones previas! y obviamente no va entre " "

	// no simplemente pueden asociarse a texto, sino también a macros, por ejemplo

	// #define forever for (;;)       donde forever representará un bucle infinito
	// #define max(A,B) ((A) > (B) ? (A) : (B))

		// esto puede parecer una función, pero no lo es. lo único que hace es sustituir en una
		// línea de código, el max(A,B) por su replaced-text, pero no funciona como una función
		// lo bueno es que esto servirá para cualquier tipo de datos de A y B

	// #undef sirve para decir que una rutina es realmente una función, no una macro

	// si son STRINGSlos parámetros de una macro se marcan con # en el replaced-text,
	// si no, no llevan ningún operador
	// # en replaced text lo sustituirá por el carácter entre dobles comillas
	// #define dprint(expr) printf(#expr "= %g\n", expr)

	// el operador ## del preprocessor sirve para concatenar argumentos, de manera que
	// #define paste(front, back) front ## back          esto daría name1 si paste(name,1)


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
// con esto, la primera inclusión de hdr.h definirá HDR. las demás pasarán al #endif directamente
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