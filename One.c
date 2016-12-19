#include <stdio.h>

// Se siguen las p�ginas en orden

// ANSI C

/////////////////////////////////1/////////////////////////////////


// EJERCICIOS 1.1 y 1.2
/*main() {
	printf("Hello World!\c");

	// \n, \t, \b, \", \\, \c

	printf("Audible or visual alert. \a\n");
	printf("Form feed. \f\n");
	printf("This escape, \r, moves the active position to the initial position of the current line.\n");
	printf("Vertical tab \v is tricky, as its behaviour is unspecified under certain conditions.\n");
	printf("Hola\bDw");
}*/

/////////////////////////////////2/////////////////////////////////
// VARIABLES Y EXPRESIONES ARITM�TICAS

/*main() {
	
	float fahr, celsius;
	//int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	// asingaciones donde intervienen int y float, int se convierte a float antes de
	// realizar la operaci�n
	fahr = lower;

	while (fahr <= upper) {
		//celsius = 5 * (fahr - 32) / 9; // division int elimina la parte decimal; (5/9) = 0
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		//printf("%3d son %6d celsius\n", fahr, celsius);
		printf("%3.0f son %6.2f celsius\n", fahr, celsius);
		fahr = fahr + step;
	}
	// %d, %f, %c, %s, %%
}*/

		// EJERCICIOS 1.3 y 1.4
		/*main() {
			float fahr, celsius;
			int lower, upper, step;

			lower = 0;
			upper = 300;
			step = 20;

			celsius = lower;

			printf("%f", lower);

			printf("Conversi�n Celsius-Fahrenheit:\n");
			while (celsius <= upper) {
				fahr = celsius / (5.0 / 9.0) + 32.0;
				printf("%3.0f celsius son %6.2f fahr\n", celsius, fahr);
				celsius = celsius + step;
			}
		}*/


//////////////////////////////////3//////////////////////////////////
// FOR

// ALL� DONDE VAYA UNA VARIABLE DE ALG�N TIPO, PUEDE IR TAMBI�N UNA EXPRESI�N QUE
// GENERE UN RESULTADO DEL MISMO TIPO

// primero los dos elementos, y al final se realiza el incremento y reevaluaci�n
// de la condici�n

		// EJERCICIO 1.5
		/*main() {
			int fahr;
			// ahora fahr puede ser int porque solo se trabaja con valores enteros
			for (fahr = 300; fahr >= 0; fahr = fahr - 20)
				printf("%3d, %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
		}*/


//////////////////////////////////4//////////////////////////////////
// CONSTANTES SIMB�LICAS #define

// NO USAR MAGIC NUMBERS!!! USAR CONSTANTES SIMB�LICAS, NO VARIABLES
// CS no se declaran y siempre EN MAY�SCULAS y sin semicolon

/*#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d, %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}*/


//////////////////////////////////5//////////////////////////////////
// INPUT/OUTPUT CHARACTER

// input/output trabaja con text streams
// c = getchar() lee el siguiente input character del text stream y devuelve el valor
// putchar(c) hace un print del character cada vez que se le llama, pudiendo ser char, int,...

// putchar y printf son intercalables

// "\n" es un STRING de UN �NICO CAR�CTER (la terminaci�n)
// "a" es un STRING de dos caracteres a y la terminaci�n (CREO)
// '\n' es UN �NICO CAR�CTER, caracter constant (valor ASCII de lo que hay entre comillas simples)

		/*In the simple setup you are likely using, getchar works with buffered input, 
		so you have to press enter before getchar gets anything to read.
		Standard C input functions only start processing what you type in when you press 
		the Enter key; IOW, input is line - oriented. Every key you press adds a character
		to the keyboard buffer.Then when the line is complete(ie, you press Enter), 
		getchar() reads the first character in the buffer, which also removes it from the buffer.
		Because your terminal is line - buffered.getchar() and putchar() still only work on single 
		characters but the terminal waits with submitting the characters to the program until 
		you've entered a whole line. Then getchar() gets the character from that buffer one-by-one
		and putchar() displays them one-by-one.*/


	//////////////////////////////////5.1//////////////////////////////////
	// FILE COPYING

	/*main() {
		int c;
		// se usa int en vez de char porque... EOF es un elemento que devuelve getchar() cuando
		// se llega al final, y la variable debe ser suficientemente grande como para poder
		// almacenarlo (am�n de todo tipo de caracteres)
		// EOF es un integer definido en la librer�a stdio.h, y no importa que valor tenga siempre
		// que no sea el mismo que un character v�lido

		//c = getchar(); // esto es una expresi�n y tiene un valor, por lo que puede ir en el while
		while ((c = getchar()) != EOF) {
			putchar(c);
			//c = getchar();
		}

		// MUCHO M�S COMPACTO!
		// los par�ntesis en (c = getchar()) son necesarios porque la precedencia de != es mayor que de =
	}*/

			// EJERCICIO 1.5 y 1.6
			/*main() {
				printf("%d\n", getchar() != EOF); // (!= es 1; == es 0)
				printf("%d\n", EOF); //(= -1)
			}*/



	//////////////////////////////////5.2//////////////////////////////////
	// CHARACTER COUNTING

	// EOF EN WINDOWS ES CTRL+Z!!!!!!

	/*main() {
		long nc; // long integers = 32 bits = 4 bytes; usar %d o %ld en printf

		nc = 0;
		while (getchar() != EOF)
			++nc; //(= nc = nc + 1;)
		printf("%ld\n", nc);
	}*/

	/*main() {
		double nc; // usar %f para float y double en los printf

		for (nc = 0; getchar() != EOF; ++nc)
			; // null statement porque el trabajo se hace en for y for debe tener body
		printf("%.0f\n", nc);
	}*/


	//////////////////////////////////5.3//////////////////////////////////
	// LINE COUNTING

	// como el stdio input recibe L�NEAS (TEXT STREAM) se asegura de que el text stream
	// sea una secuencia de l�neas con terminaci�n final de nueva l�nea \n

	/*main() {
		int c, nl;

		nl = 0;
		while ((c = getchar()) != EOF)
			if (c == '\n') //CUIDADO, NO USAR " SINO ' PORQUE ' ' significa el valor de lo que hay en medio
				// pero en c�digo ASCII, por lo que en este caso se haria (A(65) == '\n'(10))
				++nl;
		printf("%d\n", nl);
	}*/

			// EJERCICIO 1.8, 1.9, 1.10
			/*main() {
				int c, b, t, nl;

				nl = 0;
				b = 0;
				t = 0;

				// ++nl;? en principio si, pero por consola para poner EOF es necesario CTRL+Z otra l�nea
				// por lo que siempre habr� que contar otro \n, pero EOF no lleva \n impl�cito
				while ((c = getchar()) != EOF){
					if (c == ' '){
						++b;
					}
					if (c == '\t'){
						++t;
					}
					if (c == '\n'){
						++nl;
					}
				}
				printf("%d, %d, %d\n", b, t, nl);	
			}*/

			/*main() {
				int c, b;

				b = 0;

				while ((c = getchar()) != EOF)
					if (c == ' '){
						if (!b){
							b = 1;
							putchar(c);
						}
					} else {
						b = 0;
						putchar(c);
					}
			}*/

			/*main() {
				int c;

				while ((c = getchar()) != EOF)
					if (c == '\t')
						printf("\\t");
						// por qu� no (c = "\\t";)?PUES PORQUE "\t" ES UN STRING DE 1 CAR�CTER, PERO STRING
					else if (c == '\b')
						printf("\\b");
					else if (c == '\\')
						printf("\\\\");
					else
						printf("%c", c);
						//putchar(c);
			}*/


	//////////////////////////////////5.3//////////////////////////////////
	// WORD COUNTING

	// palabra no contiene tab, blanco ni newline

	/*#define OUT 0 //en una palabr
	#define IN 1 // fuera de una palabra 

	main() {
		int c, nl, nw, nc, state;

		state = OUT;
		nl = nw = nc = 0; // de izquierda a derecha, ya sabes!
		while ((c = getchar()) != EOF) {
			++nc;
			if (c == '\n')
				++nl;
			if (c == ' ' || c == '\n' || c == '\t') // && precedence is higher than || precedence
				state = OUT;
			else if (state == OUT){
				state = IN;
				++nw;
			}
		}
		printf("%d %d %d\n", nl, nw, nc);
	}*/

			// EJERCICIO 1.11, 1.12
			/*main() {
				int c;

				while ((c = getchar()) != EOF)
					if (c == ' ' || c == '\n' || c == '\t')
						putchar('\n');
					else
						putchar(c);
			}*/


//////////////////////////////////6//////////////////////////////////
// ARRAYS

// chars son integers peque�itos! por eso (c - '0') es una expresi�n integer

//main() {
//	int c, i, nwhite, nother;
//	int ndigit[10]; // de 0 a 9, ya sabes
//
//	nwhite = nother = 0;
//	for (i = 0; i < 10; ++i) // inicializar array!
//		ndigit[i] = 0;
//
//	while ((c = getchar()) != EOF)
//		if (c >= '0' && c <= '9')
//			++ndigit[c - '0']; // corresponder al �ndice de array seg�n el char que sea
//		else if (c == ' ' || c == '\n' || c == '\t')
//			++nwhite;
//		else
//			++nother;
//	
//	printf("digits =");
//	for (i = 0; i < 10; ++i)
//		printf(" %d", ndigit[i]);
//	printf(", white space = %d, otrher = %d\n", nwhite, nother);
//
//}

				// EJERCICIO 1.11, 1.12
				// m�ximo 10 palabras
				/*main() {
					int c, i, j, contador;
					int longitudes[10];

					for (i = 0; i < 10; ++i)
						longitudes[i] = 0;

					i = contador = 0;

					while ((c = getchar()) != EOF)
						if (c == ' ' || c == '\t' || c == '\n'){
							longitudes[i] = contador;
							++i;
							contador = 0;
						} else {
							++contador;
						}
					//falta ver cuantas palabras tienen los mismos caracteres y hacer el histograma
					// cuantas tienen 1, cuantas tienen 2, ...
				}*/

				/*#define MAXCHAR 256
				main() {
					int c, i, j, contador;
					int longitudes[MAXCHAR];

					for (i = 0; i < MAXCHAR; ++i)
						longitudes[i] = 0;

					i = contador = 0;

					while ((c = getchar()) != EOF)
						++longitudes[c];

					for (i = 0; i < MAXCHAR; ++i){
						printf("%c: ", i);
					for (j = 0; j < longitudes[i]; ++j)
						printf("-");
					printf("\n");
					}
				}*/



//////////////////////////////////7//////////////////////////////////
// FUNCTIONS

// tratar de fragmentar en funciones los programas para que cada cosa a hacer se haga
// en una funci�n distinta y sean aplicables a diferentes contextos
// (ver CHARACTER ARRAYS)

// subrutina; encapsulaci�n de c�digo. QU� se hace, no c�mo se hace.
// funci�n pow(x,y) ya existe, pero se va a hacer una para ver el funcionamiento.

/*int power(int m, int n); // <====== FUNCTION PROTOTYPE / DECLARACI�N! debe coincidir con la definici�n!!!!!!
// el compilador comprueba que se llama bien a la funci�n
// no tienen por qu� llevar nombre las variables: int power(int, int); tambi�n sirve
// van fuera del main, al igual que las funciones

int main(){
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d, %d, %d\n", i, power(2, i), power(-3, i));

	return 0;
}

// el CALLER de main() es el entorno desde el que es llamada; valor = 0 significa terminaci�n
// normal; != a 0 significan terminaci�n anormal/err�nea
// Funciones deben devolver un estado a sus entornor callers

// las variables de una funci�n son siempre locales
// primero declarar variables, luego statements de la funci�n

// par�metros = variables en la declaraci�n
// argumentos = valores de las variables usados en las llamadas/call a la funci�n

int power(int base, int n) { // <========= DEFINICI�N!
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p*base;
	return p;
}*/


				//EJERCICIO 1.15
				/*float conversor(float fahr);

				int main(){
					int lower, upper, step;

					lower = 0.0;
					upper = 300.0;
					step = 20.0;

					for (float i = 0.0; i <= upper; i = i + step) {
						printf("Fahr: %3.0f, Celsius: %6.2f\n", i, conversor(i));
					}

					return 0;
				}

				float conversor(float f) {
					return (5.0 / 9.0) * (f - 32.0);
				}*/


//////////////////////////////////8//////////////////////////////////
// ARGUMENTS: CALL BY VALUE

// en C siempre es "PASS BY VALUE" = los valores de los argumentos se dan en variables
// temporales DISTINTAS a las originales, es decir, son COPIAS LOCALES

// una funci�n s�lo puede alterar su propia copia temporal, no la variable original

/*int power(int base, int n) {
	int p;

	// los que se haga aqu� con "n" no afecta al argumento que se di� a power(base, n);

	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}*/

	// pero S� HAY FORMA DE CAMBIAR EL VALOR DE LA VARIABLE ORIGINAL DESDE UNA FUNCI�N: PUNTEROS!!!!!!
	// proporcionar la direcci�n de memoria de la variable y declarar que el par�metro es un puntero
	// para poder acceder a la direcci�n de memoria indirectamente a trav�s del mismo en la subrutina

// con ARRAYS ES DISTINTO: cuando una variable array se usa de argumento, el valor que se pasa es la
// direcci�n de la primera posici�n del array, es decir, no se copian elementos.
// a trav�s de esto, la funci�n puede acceder y modificar cualquier elemento del array



//////////////////////////////////9//////////////////////////////////
// CHARACTER ARRAY

// todas las l�neas de un texto, incluso las vac�as, tienen AL MENOS 1 CAR�CTER

// cuando una string constant como "hello\n" aparece en C, se almacena como un array
// de caracteres que contiene el string + '\0' ("hello\n\0") ===> CONVENCI�N DE C

/*
Aqu� debemos... ALGORITMO
	mientras haya lineas
		mirar si es la mas grande respecto a la anterior m�s grande
			si lo es la copio
			copio su tama�o
	print de la l�nea
*/

/*#define MAXLINE 1000

int getLine(char line[], int maxperline);
void copy(char to[], char from[]);

main() {
	int len;
	int maxLength;
	char line[MAXLINE];
	char longest[MAXLINE];

	maxLength = 0;
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > maxLength) {
			copy(longest, line);
			maxLength = len;
		}
	}
	if(maxLength > 0)
		printf("Linea: %s\n Longitud: %d\n", longest, maxLength);
	return 0;
}

// no se necesita el tama�o de line porque ya se le ha dado en el main
int getLine(char line[], int maxperline) {
	int c, i;

	for (i = 0; ((c = getchar()) != EOF && c != '\n' && i < maxperline-1); ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	
	//for (int i = 0; i < MAXLINE; ++i) {
	//	to[i] = from[i];
	//}
	//// MAL PORQUE SE PUEDE HACER EN UN WHILE DIRECTAMENTE LA COPIA Y COMPROBACI�N!!!!
	
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') //mientra from sea distinto a '\0', copio from a to
		++i;
}*/


				//EJERCICIO 1.17, 1.18, 1.19
				
				//mientras haya m�s l�neas
				//	miro si la linea es superior a 80
				//		si lo es me la guardo
				//		si no, nada
				//print de las l�neas

				/*#define MAXPERLINEA 800 // no dejan de ser int que se pueden pasar como argumento
				#define MIN 3

				int proveLine(char linea[], int maxperlinea);

				main() {
					int i;
					char linea[MAXPERLINEA];

					while ((i = proveLine(linea, MAXPERLINEA)) > 0) {
						if (i > MIN) {
							printf("%s\n", linea);
						}
					}

					return 0;
				}

				int proveLine(char linea[], int maxperlinea) {
					int c, i;

					for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxperlinea - 1; ++i) {
						linea[i] = c;
					}
					if (c == '\n') {
						linea[i] = c;
						++i;
					}
					linea[i] = '\0';
					return i;
				}*/

				//1.18

				// cuidado con las || y &&
				/*main() {
					int c;

					while ((c = getchar()) != EOF) {
						if (c != ' ' && c != '\t' && c != '\n') {
							printf("%c", c);
						}
					}

					return 0;
				}*/

				//1.19
				/*#define MAXLINEA 10

				int getlinea(char s[], int maxline);
				void reverse(char s[], int tamlin);

				main() {
					int c, i;
					char linea[MAXLINEA];

					while ((i = getlinea(linea, MAXLINEA)) > 0) {
						reverse(linea, i);
					}
				}

				int getlinea(char s[], int maxline) {
					int c, i;

					for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxline - 1; ++i) {
						s[i] = c;
					}
					if (c == '\n') {
						s[i] = c;
						++i;
					}
					s[i] = '\0';
					return i;
				}

				void reverse(char s[], int tamlin) {
					int i, j, c;
					char aux[MAXLINEA];

					for (i = tamlin, j = 0; i >= 0; --i) {
						if (s[i] != '\n' && s[i] != '\0') {
							aux[j] = s[i];
							++j;
						}
					}
					aux[j] = '\0';

					//printf("%s\n", aux);
					for (i = 0; aux[i] != '\0'; ++i)
						printf("%c", aux[i]);
				}*/





//////////////////////////////////10//////////////////////////////////
// EXTERNAL VARIABLES AND SCOPE

// cada variable local es �nica para la funci�n a la que pertenece e inaccesible para el resto de funciones,
// por lo que puede haber dos variables i en dos funciones distintas

// la variable existe cuando se hace call a la funci�n y desaparece cuando finaliza la subrutina

// VARIABLES LOCALES = VARIABLES AUTOM�TICAS

// variables GLOBALES pueden usarse para acceder a variables sin necesidad de par�metros
// se conservan durante toda la ejecuci�n, incluso cuando funciones que terminan han accedido a ellas

// VARIABLES GLOBALES deben definirse una vez fuera de las funciones para guardarlas seg�n su tipo (asignarles espacio)
// y deben declarase en cada funci�n que vaya a acceder a ellas (puede declararse expl�citamente"extern" o dejarlo
// impl�citamente. Lo de "extern" se hace cuando una funci�n va a usar una variable global que no ha
// sido declarada, pero como la convenci�n es declarar variables al principio, siempre se habr� declarado
// una variable global cuando cualquier funci�n del fichero FUENTE  la vaya a usar

// pero si las variables est�n en otro fichero, entonces s� es necesario el "extern"
// normalmente las variables globales se recopilan en un fichero .h

// se debe usar "void" para las listas de par�metros vac�as!!!! (compatibilidad con C no ANSI)
//Means different things in C and C++!In C it means "could take any number of parameters of unknown 
//types", and in C++ it means the same as foo(void).

// NO USAR SIEMPRE VARIABLES EXTERNAS PARA TENER MENOS ARGUMENTOS, YA QUE LAS VARIABLES EXTERNAS SIEMPRE
// EST�N AH�, INCLUSO CUANDO NO LAS QUEREMOS



