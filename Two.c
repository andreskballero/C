#include <stdio.h>

// estas dos definen constantes para los tamaños de tipos de datos
#include <limits.h>
#include <float.h>

//////////////////////////////////2//////////////////////////////////
// TIPOS, OPERADORES Y EXPRESIONES

// declararlas, indicar el tipo, y valores iniciales.
// operadores especifican que hacer con ellas
// expresiones combinan variables y constantes para generar nuevos valores

// integers pueden ser SIGNED y UNSIGNED
// float operations pueden ser single precision y existe el long double
// se pueden concatenar constantes strings
// enumeraciones
// objetos declarados const significa que no pueden cambiar


/*The byte is a unit of digital information that most commonly consists of eight bits.
Historically, the byte was the number of bits used to encode a single character of text
in a computer and for this reason it is the smallest addressable unit of memory in many
computer architectures.*/



		//////////////////////////////////1//////////////////////////////////
		// VARIABLE NAMES

// variables están formadas por letras y dígitos; primer carácter debe ser letra
// preferiblemente menores a 32 caracteres (Algo de ensambladores)
// _ cuenta como caracter para variable
// variables son CASE SENSITIVE; minúsculas para variables, mayúsculas para constantes


		//////////////////////////////////2//////////////////////////////////
		// DATA TYPES AND SIZES

// data types básicos: char (1 byte), int (integers), float (single-precision fp), double (double-precision fp)
// long y short son modificadores de int(short int sh;); la palabra int puede omitirse en estos casos
// short (2 bytes), long (4 bytes), y el int(2 o 4, depende del compilador)
// float (4 bytes), double(8 bytes) o long double(10 bytes) tienen distintos tamaños

// modificador SIGNED y UNSIGNED es aplicable a char e int (short, long, int)
	// unsigned = 0 ó positivos (2^n) 
	// signed = two's complement of the number (0111 1111 = 127 / 1000 000 = -128)

// fíjate en los prints: para unsigned %u
/*int main() {
	printf("\nBits of type char: %d\n\n", CHAR_BIT);

	printf("Maximum numeric value of type char: %d\n", CHAR_MAX);
	printf("Minimum numeric value of type char: %d\n\n", CHAR_MIN); 

	printf("Maximum value of type signed char: %d\n", SCHAR_MAX); 
	printf("Minimum value of type signed char: %d\n\n", SCHAR_MIN);

	printf("Maximum value of type unsigned char: %u\n\n", UCHAR_MAX);

	printf("Maximum value of type short: %d\n", SHRT_MAX); 
	printf("Minimum value of type short: %d\n\n", SHRT_MIN); 

	printf("Maximum value of type unsigned short: %u\n\n", USHRT_MAX);


	printf("Maximum value of type int: %d\n", INT_MAX); 
	printf("Minimum value of type int: %d\n\n", INT_MIN);

	printf("Maximum value of type unsigned int: %u\n\n", UINT_MAX);

	printf("Maximum value of type long: %ld\n", LONG_MAX);
	printf("Minimum value of type long: %ld\n\n", LONG_MIN);

	printf("Maximum value of type unsigned long: %lu\n\n", ULONG_MAX);

	return 0;
}*/


		//////////////////////////////////3//////////////////////////////////
		// CONSTANTS

// int constant como 1234 es un int
// long constant debe llevar L al final, tipo 123456789L, porque no cabe en un int
// unsigned llevan una U, tipo una unsigned long seria 123456789UL

// constantes float llevan un . (tipo 123.4) y su tipo es DOUBLE a no ser que se ponga F (float) o L (long double)

// el valor de un int se puede expresar en octal y hexadecimal también, aparte de decimal

// character constants son enteros, su valor numérico ASCII: '0' es 48 (y es mejor escribir '0')
// suelen usarse paraa compararse con otros caracteres de manera sencilla

	// '\0' es NULL CHARACTER, se escribe así para enfatizar que NULL es 0 en ASCII

//constant expression: only involves constants. se evalúan en tiempo de compilación (char line[MAXLINE+1])

//string constant/string literal: secuencia de 0 o más caracteres rodeados de ": "Hola"
//las " son solo delimitadores, no forman parte del string=> para poner " es necesario \"
//string constants pueden ser concatenadas en tiempo de compilación (usado para dividir strings muy largos)
//un string constant es un array de caracteres, que siempre lleva al final '\0', por lo que el array será
//del tamaño del contenido+1
//un string no tiene límite de longitud  y los programas deben escanearlos completamente para determinar la 
//longitud, que se puede obtener con strlen(s) de la string.h. La longitud es la longitud EXCLUYENDO '\0'

	//OJO: 'x' != "x". character constant 'x' = int, número ASCII / "x" = char array que contiene x y '\0'


//enumeration constant: número de integer constants enum boolean {NO, YES};
// el primer valor de un enum tiene valor 0, segundo 1,...etc, a no ser que se indique explícitamente
//el valor de progresión o los valores individuales de cada uno.
// enum months {JAN = 1, FEB, MAR, APR} (feb 2, mar 3, ...)



		//////////////////////////////////4//////////////////////////////////
		// DECLARATIONS

// declarar una o varias a la vez tipo char c, cont[1000], ...
// se pueden declarar e inicializar explícitamente a la vez
// external y static variables son inicializadas a 0 por defecto. las automáticas tienen garbage por defecto

//calificador CONST se puede añadir a la declaración de cualquier variable para especificar que su valor
//no puede ser modificado. const char msg[] = "Warning: ";
//se puede usar también en array arguments para indicar que la función no modifica ese array (int strlen(const char[]);)


		//////////////////////////////////5//////////////////////////////////
		// ARITHMETIC OPERATIONS

// +, -, *, /, % (módulo no puede usarse para float ni double, solo enteros)




//relational operators tienen menor precedencia que aritméticos: i < lim-1 es i<(lim-1)
//y lógicos tienen menor que los otros dos

		//////////////////////////////////6//////////////////////////////////
		// RELATIONAL AND LOGICAL OPERATORS

//siempre 1 es true, 0 si es false; ! puede convertir un no-cero operando en 0 y viceversa

// relational: >, <, >=, <= y de menor precedencia: ==, !=
// logical: && y || se evalúan de izq a der y paran tan pronto la condición se cumple (&& mayor precedencia que ||)
	// 1 && 2 && 3 => si 1 es falso, ya no se miran 2 ni 3


		//////////////////////////////////7//////////////////////////////////
		// TYPE CONVERSIONS

// hay conversiones automáticas, las que convierten una variable pequeña en una más grande en expresiones
// aritméticas, por ejemplo
// (como un int a float cuando se hace f + i)
// asignar long a short, float a int,... no está vetado, pero si que genera un WARNING

// como char es int pequeño, se puede usar para opraciones aritméticas (como s[i]-'0') donde s[] es array chars)
// int atoi(char s[]) usa eso, y int lower(int c) 

	//int lower(int c){
	//	if (c >= 'A' && c <= 'Z') {
	//		return c + 'a' - 'A';
	//	}
	//	else {
	//		return c;
	//	}
	//}


//d = c >= 'A' && c <= 'Z'       d = 1 cuando c sea un dígito

// el standard header <ctype.h> proporciona funciones de tests y conversiones independientes del character set
// por ejemplo contiene tolower(c) o isdigit(c)

	//si variables no char van a almacenarse en char, especificar signed o unsigned. Cosa de pag 44

// en expresiones lógicas y relacionales, 1 es true, 0 es false; en realidad 0 es false, el resto true
// las funciones <math.h> usan double.

// en una asignación también hay conversiones. x float e i int, x = i y i = x hay conversión. float a int
// causará truncamiento del valor

// en funciones también hay conversiones para los argumentos. Si no hay function prototype...
	// char y short se convierten a int, float se convierte a double

// por último, casts. Conversiones forzadas. (tipo) expresión
	// por ejemplo, de math, sqrt(double), si n es int, se debe hacer sqrt((double)int)
	
		//FUNCTION PROTOTYPES evitan tener que hacer cast si ya se declaran bien los argumentos en el prototype
		// pe. double sqrt(double) permite sqrt(2);, y el cast se hace automáticamente
// los casts no alteran la variable, simplemente generan el resultado




		//////////////////////////////////8//////////////////////////////////
		// INCREMENT AND DECREMENT OPERATORS

// -- y  ++ pueden ser prefijo (incremento de variable antes de ejecutarse la expresión) y sufijo (después)
// sólo de variables, no de expresiones (i+j)++ es ilegal
// si n es 5, x = ++n (x = 6) ó x = n++ (x = 5); en ambos casos n = 6;

				// EJERCICIO 2.4

// recuerda que pasando arrays se pasa la dirección del primer elemento, por lo que la función
// aunque sea void va a poder modificar el array; no se hace copia local
//void squeeze(char[], char[]);
//
//int main() {
//
//	char a[] = "Soy el Sargento Skinner";
//	char b[] = "on";
//
//	squeeze(a, b);
//
//	printf("%s\n", a);
//
//	return 0;
//}
//
//void squeeze(char s1[], char s2[]) {
//	int i, j, k, si;
//	si = 0;
//
//	for (i = j = 0; s1[i] != '\0'; ++i) {
//		for (k = 0; s2[k] != '\0'; ++k) {
//			if (s1[i] == s2[k]) {
//				si = 1;
//			}
//		}
//		if (!si) {
//			s1[j++] = s1[i];
//			printf("%s\n", s1);
//		}
//		si = 0;
//	}
//
//	 //MUY IMPORTANTE: cuando se añade esto, lo que haya después de la posición en la que
//	 //se añada, ya no cuenta o se borra? pero una de las dos seguro
//	s1[j] = '\0';
//}



		//////////////////////////////////9//////////////////////////////////
		// BITWISE OPERATORS

		// WAT?



		//////////////////////////////////10//////////////////////////////////
		// ASIGNMENT OPERATORS AND EXPRESSIONS
// funcionan de derecha a izquierda, ya que interviene un...
// =

// i = i + 2 puede escribirse como i += 2; += es lo que se llama un asignment operator
// todos los operadores tienen su correspondiente asignment operator ( -=, /=, *=, %=,...)

// preferibles los asignment operators ( i += 2 que i = i + 2 ), y además ayudan a mejorar la eficiencia
// del compilador



		//////////////////////////////////11//////////////////////////////////
		// CONDITIONAL EXPRESSIONS
		// "algo es una cosa u otra"

// un if de asignación puede escribirse de varias maneras...
/*if (a > b) {
	z = a;
} else {
	z = b;
}*/

// ó...
// expr1 ? expr2 : expr3    esto significa...
// se evalúa expr1; si es no-cero (true) el valor de la expresión es expr2, si no, el valor es expr3
// puede expresarse lo mismo con ?:  ==> z = (a > b) ? a : b;  ===>  z = max(a,b);
// será uno u otro valor de :

// paréntesis en la primera condición no son necesarios porque la precedencia de ?: está justito por encima de =
// y = es la más baja (creo)

				// EJERCICIO 2.10
				/*int lower(int);
				int lower(int c) {
					return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
				}

				int main() {
					printf("%c\n", lower('H'));
					return 0;
				}*/



			//////////////////////////////////12//////////////////////////////////
			// PRECEDENCE AND ORDER OF EVALUATION

// esto mejor mirarlo en el libro. Es cortito