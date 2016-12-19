#include <stdio.h>
#include <limits.h>
#include <string.h>


										// EJEMPLACO DE PUNTEROS

										//int main() {
										//	int x = 5;
										//	int *a = &x;
										//
										//	char *cul = "Culo";
										//
										//	char *arr[2];
										//	arr[0] = "Hola";
										//	arr[1] = "Adios";
										//
										//	printf("%d\n%d\n%s\n%s\n%c\n%c\n", cul, &cul[0], cul, &cul[0], *cul, cul[0]); //con &cul[1] el resultado es "ulo"
										//	printf("Dir Contenido a: %d\nDir Puntero a: %d\nContenido a: %d\nDir Contenido arr0: %d\nDir Contenido arr1: %d\n\
										//		   Contenido arr0 : %s\nContenido arr1 : %s\nPrimera letra arr1 : %c\n", a, &a, *a, arr[0], arr[1], &arr[0][0], arr[1], *arr[1]);
										//	// &arr[0][0] direcci�n del primer elemento de la l�nea = arr[0]
										//	// ya que arr[0] aloja la direcci�n del primer elemento de la l�nea

										//	//printf("%c\n", *(arr[0]+2)); //*(arr+1) salta de arr0 a arr1, no entre las letras; *arr+1 entre letras!
										//	printf("%c\n", *(cul+1));
										//	printf("%s\n", cul + 1);
										//
										//	return 0;
										//}

// IMPORTANTE!!!!!!!!!!!

		// SE PUEDEN HACER ASIGNACIONES EN LAS CONDICIONES DE CONTROL FLOW! (IFS, BUCLES, ...)
		// TIPO:

			//	while ((*s++ = *t++) != '\0'); //inc s y t se hace al final de la expresi�n, despu�s de comp != '\0'

					// �

			//while ((i = proveLine(linea, MAXPERLINEA)) > 0) {
			//	if (i > MIN) {
			//		printf("%s\n", linea);
			//	}
			//}

					// �
					// y como las partes se eval�an de izquierda a derecha, puede usarse la asignaci�n para realizarse otras comprobaciones!

			//for (i = 0; (c = getchar()) != EOF && c != '\n' && i < maxperlinea - 1; ++i) {
			//	linea[i] = c;
			//}

		



//test!
/*main() {
int g[] = { 123123, 5666 };

for (int i = 0; i < (sizeof(g)/sizeof(int)); ++i) {
printf("%d\n", g[i]);
}

}*/



		//////////////////////////////////5//////////////////////////////////
		// POINTERS AND ARRAYS

// un puntero es una variable que contiene una direcci�n de memoria de una variable
// se usan para implementar c�digo de mejor manera y porque, a veces, son la �nica forma de
// expresar una computaci�n

// pero deben usarse con cuidado. Son delicados, pueden apuntar f�cilmente a lugares inesperados
// y llevar a programas imposibles de entender



		//////////////////////////////////1//////////////////////////////////
		// POINTERS AND ADDRESSES

// puntero es un grupo de celdas/direcciones de memoria (2 o 4 suelen ser) que almacenan una direcci�n
// de memoria. los punteros tambi�n tienen tipo, ya que se les debe decir qu� tipo de dato hay
// en la direcci�n a la que van a apuntar

//se declara/define como puntero con *, luego se usa sin el *

			// & es el operador devuelve la direcci�n de un objeto en memoria (S�LO variables y arrays;
			// ni register, constantes ni expresiones) == > p = &c;

			// p = &c; almacena la direcci�n de memoria de c en p, por lo que "p apunta a c" = puntero a c


			// * es el operador de indirecci�n o de derreferencia. cuando se aplica a un puntero, accede al objeto de 
			// memoria al que apunta el puntero

//main() {
//int x = 1, y = 2, z[10];
//int *ip;
//
//ip = &x;
//y = *ip;
//*ip = 0;  /* x = 0!!!!!!!!!!!!! */
//ip = &z[0];
//printf("%d, %d, %d\n", x, y, *ip);
//}

// esto sirve tambi�n para argumentos ( atof(char *) ) significa que atof recibe un puntero de tipo char

// todos los punteros apuntan a un tipo espec�fico de datos que se debe especificar, salvo los punteros a 
// void de los que se hablar� en 5.11

// entonces si ip apunta a x, se puede usar ip en cualquier contexto en el que se puede usar x
// *ip = *ip + 10;

// * y & tienen mayor precedencia que los operadores aritm�ticos

// *ip += 1; = ++*ip = (*ip)++  ==> en el �ltimo caso es necesario () para evitar ip++ en vez de a lo que apunta

// por �ltimo, como los punteros son variables, esto es v�lido iq = ip; esto har�a que iq apuntase a lo
// mismo que ip




		//////////////////////////////////2//////////////////////////////////
		// POINTERS AND FUNCTION ARGUMENTS

// C pasa argumentos por valor, por lo que no hay manera de que una funci�n modifique el valor
// de una variable de la funcion caller. �O si?

// SI, con punteros!

//swap(a, b);               ESTO NO HACE SWAP DE VARIABLES, HACE SWAP DE LAS COPIAS LOCALES!!!!
//
//void swap(int a, int b) {
//	int tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}

// la manera correcta de hacer swap de las dos variables reales ser�a 

//swap(&a, &b);              AS� SE ESPECIFICA QUE RECIBE LA DIRECCI�N DE UNA VARIABLE NORMAL! recibe una direcci�n de memoria!
//
//void swap(int *pa, int *pb) {
//	int tmp;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}

//As� permite a una funci�n acceder a los objetos de la funci�n caller y modificarlos




		//////////////////////////////////3//////////////////////////////////
		// POINTERS AND ARRAYS

// un array no es m�s que un puntero a la primera posici�n del primer elemento del contenido (por ejemplo, 
// un puntero a la primera letra de un string; de este modo se puede desplazar por todo el contenido
// mediante aritm�tica de direcciones

// en C hay una estrecha relaci�n entre estos dos. Cualquier operaci�n hecha con arrays
// subscript (a[1 � 2...]) puede ser realizada con punteros. Con punteros es m�s eficiente
// pero m�s dif�cil

// esa declaraci�n: int a[10]; define, ya sabes, un array de 10, de 0 a 9
// declaraci�n int *pa es un puntero a integer, entonces pa = &a[0]; hace que pa apunte al elemento 0 del array,
// es decir, el primer elemento
// entonces x = *pa; copiar� el contenido de la primera posici�n del array en x

// si pa apunta a un determinado elemento del array, entonces pa+1 apuntar� al siguiente elemento 
// si pa apunta a a[0], *(pa+1) apunta al contenido de a[1]

// entonces la correspondencia entre indexar y "puntear" punteros y arrays es muy cercana. pa = &a[0]; convierte
// a "pa" en lo mismo que "a"
// como el nombre de un array es una referencia a la localizaci�n del primer elemento, pa = a; es tambi�n v�lido


		// al evaluar a[i], C lo convierte a *(a+i), por lo que se puede expresar de ese modo!!!! son equivalentes
		// al aplicar &, la equivalencia es &a[i] es lo mismo que a+i
		// asimismo, si pa es un puntero, *(pa+i) puede expresarse como pa[i], es decir, un array subscript es lo mismo
		// que puntero y offset

		// un puntero es una variable, por tanto se acepta pa = a � pa++;
		// el nombre de un array no es una variable, es una referencia a la direcci�n de la
		// primera variable de un un conjunto de variables del mismo tipo consecutivas en memoria,
		// por lo que no se acepta a = pa � a++;

// de aqu� que cuando una funci�n recibe como argumento un array, lo que se le pasa es la posici�n de memoria
// del elemento inicial. Esto hace que efectivamente se haga una copia local de la referencia del array, por lo
// que se podr�a considerar que se le est� pasando un puntero y la copia local es un puntero


			// esto funciona con strlen("Hello"); con strlen(array) donde array[100] y con strlen(ptr) donde *ptr
	//int strlen(char *s) {         
	//	int i;
	//
	//	for (i = 0; *s != '\0'; s++) {
	//		++i;
	//	}
	//
	//	return i;
	//}

			// lo que significa que en par�metros de una funci�n: *s y s[] son equivalentes!!!!!!!
			// y sea cual sea, se puede tratar como puntero a conveniencia de la funci�n

// se le puede pasar parte de un array a una funci�n haci�ndole creer que es el principio ==> f(&a[2]) � f(a+2)
// su declaraci�n puede ser f(int arr[]) � f(int *arr), ES LO MISMO!!!!!!!!

// si se est� seguro de que el array contiene elementos por detr�s de [0], se les puede indexar con [-1], etc.





			//////////////////////////////////4//////////////////////////////////
			// ADDRESS ARITHMETIC

// allocate = asignar

// como ya se ha dicho, si p es puntero, p++ incrementa la posici�n a la que apunta, y p+=i a la pos i desde donde est�

// la integraci�n de punteros y arrays, y la direcci�n aritm�tica son puntos fuertes de C!!!!

// alloc(n) ==> devuelve un puntero p a n posiciones consecutivas de caracteres y afree(p) libera el almacenamiento
// para usarse primero se debe usar alloc() y luego afree(), por lo tanto se comportan como una pila (LIFO)

// la librer�a stdio.h proporciona las funciones malloc() y free()

// alloc usa piezas de un char array llamado allocbuf; este array es privado para alloc y afree
// alloc y afree tratan con punteros, no array �ndices, as� que allocbuf puede declararse en la source file
// static para que ninguna otra rutina pueda acceder a �l y sea invisible para el resto

// tambi�n se necesita saber el espacio de allocbuf que ya ha sido usado. Se usa un puntero llamado allocp
// que apunta al siguiente elemento libre. Cuando se le pregunta a alloc por "n" caracteres, comprueba
// que haya suficiente espacio disponible en allocbuf

// entonces, alloc devuelve el valor de allocp(el inicio del siguiente bloque libre), lo incrementa por "n"
// para apuntar al siguiente bloque libre. 
// si no hay espacio, alloc devuelve 0;

// afree(p) lo �nico que hace es hacer que allocp sea p si p est� en allocbuf (porque funciona como una pila)


			//#define ALLOCSIZE 10000 //tama�o del espacio disponible
			//
			//static char allocbuf[ALLOCSIZE]; //almacenamiento para alloc
			//static char *allocp = allocbuf; //siguiente posici�n libre
			// //� static char *allocp = &allocbuf[0]; ya que el nombre es la referencia a la primera posici�n del array
			//
			//char *alloc(int n) { //devuelve puntero a char, a n caracteres
			//	if (allocbuf + ALLOCSIZE - allocp >= n) { //// ahora se mira si hay suficiente espacio para n caracteres
			//		allocp += n;
			//		return allocp - n; //la antigua p
			//	}
			//	else {
			//		return 0; //C asegura que 0 nunca es una direcci�n v�lida de memoria: se usa para indicar eventos anormales
								// de hecho, punteros e integers no son intercambiables, esta es la �nica excepci�n:
								// la constante 0 puede asignarse a un puntero, y se puede comparar un puntero con la constante 0
								// NULL es la constante simb�lica de 0, definida en stdio.h; NULL es un puntero void a 0
			//	}
			//}
			//
			//void afree(char *p) { // liberar el espacio al que apunta p
			//	if (p > allocbuf && p < allocbuf + ALLOCSIZE) {
			//		allocp = p;
			//	}
			//}

// en general un puntero se puede inicializar como cualquier otra variable, a pesar de que los valores adecuados
// son cero o una expresi�n que suponga la direcci�n de datos previamente definidos del tipo adecuado

// principales facetas de aritm�tica de punteros:
	// 1: si p y q apuntan a miembros del mismo array, expresiones l�gicas y relacionales son aceptadas (tipo p < q)
	// tambi�n se acepta para p y q que no sean del mismo array, pero entonces el resultado es incierto
	// EXCEPCI�N: primera direcci�n despu�s del array puede usarse para comparaciones


	// 2: como ya se dijo antes, se puede sumar/restar a un puntero para cambiar su direcci�n. si p + n
	// p apuntar� a la direcci�n +n a partir de p. si p es un puntero a int(4 bytes = 4 direcciones de memoria)
	// y n es 1, �l compilador escalar� 1 a 4 para que se mueva a la siguiente posici�n del int
	
	// del mismo modo, si p < q, q-p+1 es el n�mero de elementos entre p y q inclusives

				//int strlen(char*);
				//
				//int main() {
				//	char *s = "hola";
				//
				//	printf("%d\n", strlen(s /*&s[2] har�a que su primera posici�n en la funci�n fuera 'l'*/));
				//
				//	return 0;
				//}
				//
				//int strlen(char *s) {
				//	char *p = s;
				//
				//	while (*p != '\0'){
				//		++p;
				//	}
				//
				//	return p - s; //desplazamiento de direcciones = tama�o!
				//}

// p�gina 103, media p�gina pabajo (algo de stddef.h)
// ya se sabe que si en vez de usar int hubieramos usado float, float *p, p + n tambi�n ser�a v�lido
// y el escalado ser�a autom�tico

// operaciones con punteros v�lidas: asignar punteros del mismo tipo, a�adir o restar integer a puntero,
// restar un puntero a otro o compararlos (siempre que formen parte del mismo array), y asignar o comparar un puntero con 0

// el resto de operaciones aritm�ticas con punteros son ilegales, tipo sumar dos punteros, multiplicarlos, 
// sumarles float o double, asignar un puntero de un tipo a otro de otro tipo sin cast (excepto para void *)



		//////////////////////////////////5//////////////////////////////////
		// CHARACTER POINTERS AND FUNCTIONS

// string constants tipo "I am a string" es un char array!, acaban con '\0' para que los programas
// puedan encontrar donde est� su final, por lo que su length es su numero de chars entre las comillas
// +1, el del s�mbolo '\0'. TO ESTO YA LO SABIAS

		//IMPORTANTE
// este tipo de strings se les pasa a funciones como argumento. Normalmente estos strings se acceden
// a trav�s de un puntero char al principio del array de chars. Esto es, las funciones acceden al array de chars
// mediante un puntero char que apunta a su primer elemento. LA FUNCI�N RECIBE UN PUNTERO AL PRINCIPIO DEL CHAR ARRAY

// string constants no necesitan ser function arguments. si declaramos pmessage como
	// char *pmessage
	// es posible hacer pmessage = "hola que tal";
// esto asigna a pmessage un puntero al inicio del char array. NO COPIA NADA; SE USA UN PUNTERO

			// C no proporciona ning�n mecanismo para acceder y procesar un char array entero!

// hay una diferencia importante entre estas definiciones:
		// char amessage[] = "hola";  //array
		// char *pmessage = "hola";   //puntero

// amessage es un array de tama�o justo para guardar un string constant hola + \0; los chars del array
// se pueden cambiar pero siempre apuntar�n a las mismas direcciones de memoria

// por otro lado, pmessage es unpuntero inicializado para apuntar a un string constant; el puntero podr�
// modificarse para apuntar a cualquier otro sitio, pero el resultado es indefinido si tratas de modificar
// el contenido del string


// caso de estudio 1: strcpy(s,t) que copia t en s. Hacer s = t no es v�lido, ya que se estar�a copiando s�lo el
// puntero, no el contenido (puede haber asignaciones entre punteros). veamos dos variantes

		// esto va copiando hasta que el '\0' que termina t ha sido copiado en s

		//void strcpy(char *s, char *t) {
		//	int i = 0;
		//
		//	while ((s[i] = t[i]) != '\0')
		//		++i;
		//
		//}
		//
		//void strcpy(char *s, char *t) {
		//	while ((*s = *t) != '\0') {
		//		++s;
		//		++t;
		//	}
		//}

// como los argumentos se pasan BY VALUE!!!!!!!!!(copias locales de los punteros), los puede usar como quiera
// por eso puede cambiar la posici�n a la que apunta la variable sin preocuparse por que el puntero original
// deje de apuntar a la misma posici�n

			// una mejor manera de escribir esto ser�a: los incrementos en la secci�n de test del loop

			//void strcpy(char *s, char *t) {
			//	int i = 0;

			//	while ((*s++ = *t++) != '\0'); //inc s y t se hace al final de la expresi�n, despu�s de comp != '\0'
			//}

			// la comparaci�n con '\0' es redundante porque simplemente queremos saber cuando la
			// expresi�n es cero, y para esto basta con (*s++ = *t++)

			// t no se incrementa hasta que el valor sin incrementar de t haya sido recuperado! entonces se incr

//strcpy existe en stdio.h


// caso de estudio 2: strcmp(s, t) que compara s y t, y devuelve <0, 0 � >0 si s es menor que,
// igual que, o mayor que t

//int strcmp(char *s, char *t) {
//	int i;
//	for (i = 0; s[i] == t[i]; ++i)
//		if (s[i] == '\0')
//			return 0;
//	return s[i] - t[i];
//}

// mira el orden de las letras, por eso resta EL CONTENIDO de las direcciones de memoria
//int strcmp(char*, char*);
//
//int main() {
//
//	char *s = "Hola";
//	char *t = "Hona"; // n est� dos posiciones por delante de l
//
//	printf("%d\n", strcmp(s, t));
//
//	//int x = 0;
//	//int *ip = &x;
//	//printf("%d\n%d\n%d\n", (*ip)++, *ip, x); //cojo el valor y enconces incremento ip; resultado 1, 1, 0;
//	//x = 0;
//	//printf("%d\n%d\n%d\n\n", *ip, x, (*ip)++); //resultado 0, 1, 1? precedencia? no hay = resultado incierto?
//	//return 0;
//}
//
//int strcmp(char *s, char *t) {
//	int i;
//
//	for (; *s == *t; ++s, ++t)
//		if (*s == '\0')
//			return 0;
//	return *s - *t;
//}

// ++ y -- son prefijos y sufijos aplicables a punteros:
// *p++ = val; hace push de val a un stack; val = *--p; pop en val el top del stack
// *p++ = val ====> primero se val se copia en el contenido de p, y se incrementa donde apunta p


			// EJERCICIO 5.3 Y 5.4

			//void strcata(char*, char*);
			//int strend(char*, char*);

			//int main() {

			//	char *s = malloc(sizeof(char)* 100);
			//	char *t = "holita, vecinito";

			//	char *w = "holati";
			//	char *j = "ati";

			//	strcpy_s(s, 100, "Hola "); //el numero 100 es el tama�o del array destino!

			//	strcata(s, t);
			//	printf("%s\n", s);

			//	printf("%d\n", strend(w, j)); //funciona

			//	free(s);

			//	return 0;
			//}

			//void strcata(char *s, char *t) {

			//	for (; *s != '\0'; ++s) {
			//		printf("a\n");
			//	}

			//	//strlen(s);
			//	for (; (*s = *t) != NULL; ++s, ++t);
			//	//while ((*s++ = *t++) != NULL); //esta no es v�lida porque en la �ltima iteraci�n no nos quedar�amos
			//	// con s y t apuntando a '\0' sino a la siguiente posici�n. en el for se para cuando se es igual a '\0'
			//	// mientras que en el while s y t a�n incrementan una posici�n m�s
			//}

			//int strend(char *s, char *t) {
			//	//int i = 0;
			//	//while (*s++ != '\0');

			//	for (; *s != '\0'; ++s);

			//	//printf("%c\n", *(s-2));
			//	//s = s - strlen(t) - 1;

			//	s = s - strlen(t);

			//	/*while ((*s == *t) && *s != '\0') {
			//		s++;
			//		t++;
			//	}*/

			//	for (; *s == *t && *s != '\0'; ++s, ++t);

			//	if (*s == '\0' && *t == '\0') {
			//		return 1;
			//	}

			//	return 0;
			//}



					//si la constraint es que debes usar la declaraci�n char *algo
					//entonces haz un malloc y libera luego la memoria
					//algo = malloc(sizeof(char)* 100);
					//strcpy(algo, "Hola");
					//strcat(algo, loquesea);
					//usarlo
					//y luego
					//free(algo);


					//para guardar cosas en memoria tienes que pedir memoria
					//s�lo es eso
					//y lo que pides tienes que devolverlo


					//hacerlo con memoria din�mica s�lo es 1 instrucci�n m�s
					//y es mucho m�s correcto


					//cambia las dos primeras l�neas por
					//bueno, hay que copiar el Hola xD
					//pero
					//cambia esas dos l�neas por estas dos
					//char *s = malloc(100);


					//si se enfada, char *s = (char *)malloc(100);
					//y luego
					//strcpy(s, "Hola ");
					//y pruebas y ver�s que funciona
					//y para terminar
					//para que sea correcto 100 %
					//antes del return 0
					//pones
					//free(s);
					//eso es todo el terrible mundo de la memoria din�mica xD no hay m�s
					//y tiene una gran ventaja
					//y es que si haces el array de 100, lo est�s alojando en la pila
					//y con esto otro, es memoria normal
					//ya te explicar� qu� significa eso, y por qu� es mejor una u otra cosa seg�n la ocasi�n





		//////////////////////////////////6//////////////////////////////////
		// POINTER ARRAYS; POINTERS TO POINTERS


						//nombres pomposos para decir
						//arrays de dos o m�s dimensiones
						//un array de strings es eso
						//char *arrays[10];
						//eso son 10 punteros a char
						//si haces un bucle
						//array[var1] = malloc(tam maximo string);
						//ya puedes hacer cosas con cada uno de tus 10 strings


												//IMPORTANTE
										// los punteros son variables, por lo que est�n en una direcci�n de memoria y contienen otra, que es a la que apuntan
										// y esa otra es la que tiene un contenido!!!!!

										//int main() {
										//
										//	int x = 2;
										//	int *a = &x;
										//	int *b = a;
										//
										//	printf("Dir a: %d, %d, Apuntan a:%d, Apuntan a:%d\n", &a, &b, a, b);
										//
										//	return 0;
										//}


										// A VER: int *arr[2] = {6, 7}; ES UN ARRAY DE PUNTEROS, Y UN PUNTERO SIEMPRE APUNTA A UNA VARIABLE, SI NO, NO SER�A 
										// UN PUNTERO POR ESO PARA ACCEDER AL N�MERO S�LO HACEMOS *ARR � ARR[0], PORQUE HAY QUE ACCEDER AL CONTENIDO QUE APUNTA

										// EN EL CASO DE QUE SEA UN ARRAY DE PUNTEROS A CHAR PARA STRINGS, 
										// char *daytab[2] = { "Ojete", "moreno" }; daytab es un puntero a un array de punteros!!!!!!!!!!!!
										// EL ** ACCEDE A LA LETRA, PERO EL * ACCEDE AL STRING, al puntero a su primera direcci�n
										// de memoria!!!!!!!!!!!!!!!!!!!!!!!, no directamente a la variable,
										// como ser�a el caso de int, sino a otro puntero, porque un string "es un puntero"

										// por tanto en un array de strings (array de punteros a char) hay dos punteros: el que se mueve por el
										// array y el que se mueve en cada string!! (ver cap�tulo command-line args (cap�tulo10), �ltimas l�neas)


										/*int main() {
										
											int *arr[2] = {6, 7};
											printf("%d, %d\n", arr, *arr);
										
											static char *daytab[2] = { "Ojete", "moreno" };
											printf("%d, %s\n", daytab, *daytab);

											char *pmessage = "hola";
											printf("%c\n", *pmessage);
										
											return 0;
										}*/


// como los punteros son variables, pueden ser almacenadas en arrays de igual modo que otras variables pueden

// un ejemplo de comparar l�neas y ordenarlas. integers si se pueden comparar y mover en un array porque son del mismo
// tama�o. sin embargo, con l�neas esto no se puede hacer, ya que son de diferentes tama�os y no se pueden mover.

// esto se puede hacer con otro tipo de representaci�n de datos que haga esto eficientemente respecto a la diferencia
// de tama�o posible entre l�neas: ARRAY DE PUNTEROS

// en el array de punteros se almacenan, de manera ordenada, los punteros que apuntan al primer char de cada l�nea
	// de este modo podemos comparar dos l�neas pasando sus punteros a strcmp, por ejemplo. � si se debe cambiar
	// el orden en que se almacenan las l�neas en el array, basta con cambiar de posici�n los punteros al primer
	// char de cada l�nea, no la l�nea entera! ESTO ELIMINA MUCH�SIMA CARGA DE TRABAJO

// un programa que haga eso debe hacer principalmente 3 cosas (que se pueden traducir en 3 funciones controladas por
// la main() ), ACU�RDATE DE HACERTE UNA REPRESENTACI�N B�SICA DE LO QUE HACE EL PROGRAMA PARA SABER DE LA MEJOR MANERA
// EL ORDEN DE COSAS A HACER

			// leo todas las l�neas de input: esto debe guardar los chars de cada l�nea, construir array de punteros
					// a para guardar referencias a cada l�nea, contar el n�mero de l�neas para ordenar y printar, y
					// comprobar que no haya demasiadas l�neas de input
			// las ordeno
			// las printo


// la cosa est� en declarar esto como char *lineptr[MAXLINES]
// esto dice que lineptr es un array de tama�o MAXLINES donde cada uno de sus elementos es un puntero a char
// esto significa que lineptr[i] es un puntero a char, y *lineptr[i] es el char al que apunta, el primer caracter
// de la l�nea

// lineptr es el nombre del array y puede ser tratado como un puntero, como se ha ido haciendo (*lineptr++, por ejemplo)

		// (*lineptr++ se puede quedar apuntando a algo que est� m�s all� del propio array, pero no pasa nada porque solo
		// puntar� a otra direcci�n de memoria. da igual si esta tiene un int y lineptr es char, un apuntador apunta a datos,
		// no a un tipo. el tipo lo interpreta el compilador para interpretar bien los datos de cierto tipo, pero a nivel
		//de memoria, solo se est�n almacenando datos. el tipo es algo que usa el compilador para interpretar bien
		//como procesar los datos almacenados en la posici�n de memoria. solo petar�a con cosas chungas tipo te 
		//sales del asignado (?) o de memoria, u otro tipo de errores que a�n ni idea)


					//*Lineptr++
					//En la ultima iteracion no acabaria apuntando a algo que esta una posicion mas alla de lo que lineptr es en si ? 
					//No se si me explico : joy::joy :
					//No se vuelve a usar lineptr, porque el incremento es a posteriori, pero puede apuntar mas alla de su propio
					//tama�o ?
					//Uab Manu
					//al final el puntero es inv�lido, s�
					//puede apuntar a donde quieras
					//porque el puntero s�lo es un n�mero que es la direcci�n de memoria donde apunta
					//as� que tiene el rango completo de n�meros a su disposici�n xD
					//imagina que haces puntero = malloc(2);
					//s�lo tienes 2 bytes para usar
					//pero tu puedes hacer un bucle y aumentar ese puntero 1000000000 posiciones
					//eso s�, si intentas usarlo se hostiar� xD
					//Andr�s
					//Y si esa posicion a la que pasa a apuntar guarda algo de un tipo distinto al del tipo de puntero, no pasa 
					//nada ?
					//O petaria ?
					//Tipo si el lineptr es de tipo char y el *lineptr++ se acaba quedando apuntando a una dir de memoria que 
					//tiene un int guardado
					//Uab Manu
					//es que no existen los tipos
					//existen direcciones de memoria
					//que contienen datos
					//leer�s un dato
					//y tendr� sentido o no tendr� sentido

		// al copiar puntero a un puntero del array de punteros, si luego se modifica p no var�a en el array?
//int main() {
//	//char *p = malloc(sizeof(char)* 10);
//	char *p = "Hey";
//	char *arr[2];
//
//	//strcpy_s(p, 10, "Hey");
//	//p = "Hey";
//	arr[0] = p;
//	printf("%d\n", p);
//
//	//strcpy_s(p, 10, "Uao");
//	p = "Uao";
//	arr[1] = p;
//	printf("%d\n", p); //la direcci�n de p cambia! pero con strcpy_s no?!
//
//	printf("%s, %s, %s\n", arr[0], arr[1], p);
//
//	return 0;
//}



		//////////////////////////////////7//////////////////////////////////
		// MULTI-DIMENSIONAL ARRAYS

//arr[][] ===> ya sabes, array de arrays

// C proporciona arrays multidimensionales, pero son mucho menos usados que los arrays de punteros (*arr[])

// ejemplo de conversi�nd de fechas, donde marzo 1 es el d�a 60 de a�os no bisiestos, 61 de bisiestos

// day_of_year() convierte mes y d�a a d�a del a�o
// month_day() convierte d�a del a�o en mes y d�a, donde m�s y d�a son argumentos y ambos ser�n punteros
		// month_day(1982, 60, &m, &d) asigna a m un 2 y a d un 29 (29 de febrero)

// ambas funciones lo que necesitan es una tabla con los n�meros de d�as de cada mes si es a�o normal o bisiesto
		//static char daytab[2][13] = { { 0, 31, 28, ... }, { 0, 31, 29, ... } };
			//se empieza por 0 para recorrer los meses de manera natural=mes 1, 31 d�as, etc
		// lo han hecho char para demostrar que char puede almacenar n�meros peque�os; yo lo har�a int		
		//este array debe estar static y debe ser variable global porque debe ser accesible por ambas funciones

		//main(){
		//	static char daytab[2][13] = { { 0, 31, 28}, { 0, 31, 45} };
		//	printf("%d\n", daytab[1][2]); //en este caso puede hacer print de -128 a 127 (signed chars en el array!)
		//} //para hacer print del char, %c, ya sabes. guardar 77 en un char son bits igualmente. el compilador
		//	//interpreta los bits del modo que le digas!

// la funci�n day_of_year(int year, int month, int day) contiene dentro una instrucci�n
	// leap = year%4 && year%100 != 0 || year%400 ==0;
	// esto da a leap el valor 1 � 0 para acceder a la daytab adecuada seg�n si el a�o es bisiesto o no
		// moraleja: espresiones l�gicas generan 1 � 0, que tambi�n son v�lidos para asignaci�n!!!!!!

// en un array multidimensional arr[][]
// el orden de almacenamiento es fila, columnas de la fila, siguiente fila, columnas de esa fila, etc
// es decir, las filas (los arrays) se almacenan de manera contigua
// relaci�n con los fallos de cach�, acu�rdate de AC!


// si un array multidimensional se le pasa a una funci�n, la declaraci�n del par�metro debe incluir las columnas
// obligatoriamente, pero puede no incluir las rows (filas), ya que no deja de ser un puntero a un array de l�neas
// donde cada l�nea tiene 13 ints

// la declaraci�n pu� ser (f(int daytab[2][13], ...) {} � (f(int daytab[][13], ...) {}
// o podr�a ser (f(int (*daytab)[13], ...) {} que dice que daytab es un puntero a un array de 13 ints
// los par�ntesis son necesarios porque (f(int *daytab[13], ...) {} es un puntero a un array de 13 punteros int;
// [] tiene mayor precedencia que *



		//////////////////////////////////8//////////////////////////////////
		// INITIALIZATION OF POINTER ARRAYS

// arr[] guarda UN STRING PORQUE ES UN PUNTERO A UN STRING (= *arr),
// *arr[] guarda VARIOS STRINGS PORQUE SON PUNTEROS A LOS STRINGS

// imagina una funci�n month_name que recibe un entero y devuelve un puntero al nombre del mes deseado

//internamente puede tener un static array de punteros char a cada uno de los meses, s�lo gestionado por esta funci�n
	// (siendo static se crea y se mantiene)

//char *month_name(int i) {
//	static char *name[] = { "No existe", "Enero", "Febrero" };
//
//	return ((i < 1 || i > 12) ? name[0] : name[i]); // name[0] == *(name), y esto es el apuntador del primer char del primer string
//}

// la funci�n habla por s� misma



		//////////////////////////////////9//////////////////////////////////
		// POINTERS VS MULTIDIMENSIONAL ARRAYS

// diferencia entre int a[10][20]; e int *b[20]; ===> a[3][4] y b[3][4], ambos son referencias a un int

				// ESTO ES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
				//int main(){
				//	static char *daytab[2] = { "Ojete", "moreno" };
				//	daytab[1] = "Wololo";
				//	//char *p = "Walak";
				//	//daytab[1] = p;
				//	printf("%d, %d\n", daytab, *daytab);
				//	printf("%s\n", *daytab);
				//	printf("%c\n", *((daytab + 1)[0]));// *((daytab + 1)[0]) ES LO MISMO QUE daytab[1][0]
				//	printf("%s\n", *(daytab + 1));
				//	printf("%c\n", **daytab); //contenido (primer puntero)
				//	// del contenido (ese puntero apunta a dir de primera letra de 0) de &daytab[0]
				//	// daytab es un ARRAY!!! que guarda PUNTEROS!!! de ah� el doble acceso para llegar
				//	// a la letra (primero acceso a la posici�n del array, despu�s acceso al puntero!
				//}


// la diferencia est� a m�s bajo nivel: un array multidimensional reserva el espacio necesario en memoria para
// almacenar todos los datos que puedan caber en el array (200 huecos int)

// por otro lado, la definici�n de *b[10] simplemente asigna en memoria 10 punteros a int, pero no se sabe de qu�
// tama�o va a ser cada elemento contenido en el int (guardar� los punteros y el espacio que almacene el contenido)

// la principal ventaja es que el array de punteros no ha definido cu�nto ocupar� cada uno de sus elementos
// mientras que el array multidimensional s� que lo ha hecho. De este modo, los punteros del array de punteros
// pueden apuntar a contenido de diverso tama�o, mientras que los del array multidimensional siempre tendr�n como
// m�ximo el mismo tama�o (20 en este caso)

//char *name[] = { "No existe", "Enero", "Febrero" };
// es bastante distinto de 
//char aname[][20] = {"No existe", "Enero", "Febrero"};


			// IMPORTANTE!!!!!!!!!
// en este ejemplo se han usado integers, pero el objetivo m�s b�sico de los arrays de punteros es el de
// almacenar varios strings de tama�o indefinido!




		//////////////////////////////////10//////////////////////////////////
		// COMMAND-LINE ARGUMENTS

// MAIN

		//Cada programa de C tiene una funci�n principal que se debe llamar main.
		//La funci�n main sirve como punto de partida para la ejecuci�n del programa.
		//Normalmente, controla la ejecuci�n del programa dirigiendo las llamadas a otras 
		//funciones del programa.Un programa deja de ejecutarse normalmente al final 
		//de main, aunque puede finalizar en otros puntos del programa por distintos 
		//motivos. A veces, quiz�s cuando se detecta un error, puede resultar conveniente
		//forzar la finalizaci�n de un programa.Para ello, utilice la funci�n exit.

		//el control de ejecuci�n del programa est� en la funci�n que se ejecuta actualmente, se va pasando
		//en la pila de funci�nes invocadas

		//You need either a definition or a prototype in order to properly call a function, but main must never be called from any other function, so it must not be declared.
		//Because the C standard says so.Operating systems pass the return value to the calling program(usually the shell).Some compilers will accept void main, but this is a non - standard extension(it usually means "always return zero to the OS").
		//By convention, a non - zero return value signals that an error occurred.Shell scripts and other programs can use this to find out if your program terminated successfully.



// hay maneras de pasarle argumentos o par�metros a un programa escrito en C cuando se est� ejecutando

// cuando se llama al main(), el main() RECIBE DOS ARGUMENTOS!!!!!!!!

// por convenci�n, el primero se llama argc ("argument count" nro de argumentos de l�nea de comandos con que se invoca al programa(
// el segundo se llama argv ("argument vector" es un puntero a un array de punteros a char (array de strings), donde
// cada argumento es un string distinto

// un ejemplo sencillito es el programa echo, que hace un print de los argumentos que recibe
// echo hola, adios				genera como output hola, adios


// por convenci�n, el nombre con el que el programa se invoca es argv[0], por lo que argc es siempre al menos 1
// si argc es 1, no hay argumentos en la l�nea de comandos despu�s del nombre del programa

		// en el ejemplo echo, argc = 3, argv[0] es "echo", argv[1] es "hola", argv[2] = "adios"

// el primer argumento opcional es argv[1], y es obligatorio que argv[argc] sea un puntero a NULL

// EJEMPLO DEL ECHO IMPLEMENTADO

//int main(int argc, char *argv[]) {
//	int i;
//
//	for (i = 1; i < argc; ++i)
//		printf("%s%s\n", argv[i], ((i < argc - 1) ? " " : ""));
//	return 0;
//}
//
//// como argv es un puntero a un array de punteros, podemos jugar con la aritm�tica de direcciones
//
//int main(int argc, char *argv[]) {
//	int i;
//
//	while (--argc > 0)
//		printf("%s%s\n", *(++argv), ((argc > 1) ? " " : ""));
//	return 0;
//}

// cada incremento/decremento de argv hace que apunte al siguiente/anterior argumento; y entonces *argv es el
// puntero al principio del string

// strstr(s, t) devuelve un puntero a la primera posici�n en s del string t, si existe, si no NULL

// la convenci�n de programas C en UNIX y por tanto, convenci�n, es que los argumentos que empiezan con un
// signo - introducen un "optional flag" o "parametrer". 
// Supongamos dos argumentos opcionales: print de todas las l�neas excepto las que cumplan el patr�n y
// preceder las l�neas por su n�mero de l�nea- Si se elige -x para el primer argumento opcional y -n para el segundo
			
				// la llamada al programa ser�:        find -x -n pattern

// y printar� todas las l�neas que no cumplan el patr�n, precedidas de su n�mero de l�nea

// tambi�n podr�as ser, y es conveniente, combinar opciones tipo		find -xn pattern

// los argumentos opcionales se permiten tantos como sea, en el orden que sea, y el programa debe estar preparado
// para procesarlos

		// EJEMPLACO: OJO A LA DIFERENCIA ENTRE (*++argv)[0] y *++argv[0]
		// uno es el contenido de la primera posici�n del string, el otro es la siguiente posici�n del
		// contenido de un mismo array ya que no se va avanzando argv sino el puntero a/en su contenido

		// mejor acceder as�, con el subscript, a los valores de un string. ((*++argv)[0] podr�a ser **++argv)
		// [] tiene mayor precedencia que * y que ++, por lo que se esas expresiones son exactamente lo explicado
		// sin necesidad de m�s par�ntesis, aunque podr�an usarse

		//while (c = *++argv[0]) { //mientras c no sea NULL... 0, '\0' y NULL son lo mismo, POR LO QUE SALE DEL WHILE
		//	switch (c) {
		//	case 'x': //tal
		//	case 'n'://tal
		//	default: //tal
		//	}
		//}





		//////////////////////////////////11//////////////////////////////////
		// POINTERS TO FUNCTIONS

// pueden definirse punteros a funciones, que pueden ser asignados, guardados en arrays, pasados a funciones, etc.

// es decir, si declaramos las funciones

	// void qsort(char*[], int left, int right, int(*comp)(void *, void *));
	// numcmp(char *, char *);

// qsort y numcmp son las direcciones de estas funciones!!!!
// no se les pone & delante de igual modo que a los arrays tampoco, ya que el mismo nombre es la referencia
// a la primera direcci�n del array (&arr[0])


// el �ltimo parametro de qsort (int(*comp)(void *, void *)) significa una funci�n con dos punteros de argumento

	// vemos que se est� usando el typo gen�rico void * para los punteros. cualquier puntero puede ser casteado
	// a void y descasteado sin p�rdida de informaci�n, por lo que sirve cuando no se sabe con qu� tipo de puntero
	// se va a trabajar (puntero que apunta a int, a char,...)

			// CON CUIDAO! el cuarto par�metro de qsort es int(*comp)(void *, void *)
			// esto significa que comp es un puntero a una funci�n que recibe dos punteros void como argumentos, y devuelve un int

			// esto int(*comp)(void *, void *) no es lo mismo que esto otro int *comp(void *, void *)
			// se debe asociar correctamente con par�ntesis: en el primer caso una funci�n comp que recibe dos punteros a void de
			// argumentos y devuelve un int, en el segundo caso una funci�n comp que devuelve un puntero a int




		//////////////////////////////////11//////////////////////////////////
		// COMPLICATED DECLARATIONS

// PRIMERA: cuidado con los par�ntesis en las funciones que devuelven punteros: int *f() no es lo mismo, por asociatividad,
// que int (*f)()   /*esto �ltimo es punteroa a funci�n que devuelve int*/
	// () tiene mayor precedencia que *


// dcl()