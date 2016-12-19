#include <stdio.h>


//trabaja con una copia de la direcci�n
//en ambos casos es una copia de la direcci�n
//lo que pasa
//es que en el caso del string, t� est�s diciendo, variable con la copia, te cambio la direcci�n
//y en el caso de los arrays de strings
//est�s diciendo
//variable con la copia, vamos a la direcci�n de memoria de ese primer elemento y lo cambiamos
//es una cosa diferente
//por eso funciona
//si no lo acabas de pillar no te frustres xD casi casi lo tienes
//si consigo que lo pilles me pondr� contento xD no es molestia
//Andr�s
//si si, lo tengo!
//lo tengo de verdad
//Uab Manu
//es ultra f�cil pero la primera vez es un l�o
//una vez lo pillas es que no hay manera de equivocarse
//Andr�s
//te haria un dibujo para clarificarlo
//Uab Manu
//y es super l�gico
//Andr�s
//si, vale!!!uff vale ahora lo veo
//a ver si me sale bien la explicacion
//Uab Manu
//mientras me lo dices subo un momento a encender el horno
//Andr�s
//en el caso del string solo, original = a, copia = a, entonces cuando hago copia = b, original = a y copia = b, y claro la copia es un 
//puntero distinto al original
//en cambio en el caso del array de strings
//Uab Manu
//Andr�s ico
//en el caso del string solo, original = a, copia = a, entonces cu
//100 % correcto
//Andr�s
//original contiene direcciones de memoria, copia contiene las mismas direcciones de memoria, entonces original y copia son dos punteros 
//distintos que apuntan a lo mismo, por lo que si cambio el contenido de esas direcciones de memoria, da igual que este trabajando con 
//una copia porque su contenido apunta al mismo sitio
//(no se si se entiende bien esto ultimo jejeje)
//Uab Manu
//original contiene la direcci�n a la lista de direcciones de memoria, copia contiene esa misma direcci�n
//entonces coges una u otra y dices, leo tu valor, y vamos a esa direcci�n de memoria
//y haces lo que sea
//y da igual si usas la copia o la original
//(subo) xD
//Andr�s
//exacto!en el caso del string no da igual trabar con la copia y el original, pero en el caso del array de strings "si da igual" porque 
//lo que importa es que voy a modificar el contenido de las direcciones a las que puede apuntar dicho puntero, que son las mismas
//Uab Manu
//eso es

// AQU� COMO LA COPIA DE MODIFICAR APUNTA A LAS MISMAS DIRECCIONES DE MEMORIA DEL ARRAY QUE EL ORIGINALY NO ESTOY CAMBIANDO LA DIRECCI�N A LA QUE APUNTA LA COPIA
// SINO EL CONTENIDO DE LAS DIRECCIONES A LAS QUE APUNTA, NO HAY PROBLEMA.
// EL PROBLEMA VIENE CUANDO CAMBIO LA DIRECCI�N A LA QUE APUNTA LA COPIA, PORQUE LA COPIA ES DISTINTA AL PUNTERO ORIGINAL
//void modificar(char*[]);
//
//int main() {
//	char *a[] = { "ho", "la" };
//
//	modificar(a);
//
//	printf("%s, %s\n", a[0], a[1]);
//
//	return 0;
//}
//
//void modificar(char *a[]) {
//	a[0] = "cuag";
//	a[1] = "lohk";
//}


// no funca? NO PORQUE EN MODIFICAR, a ES UNA COPIA LOCAL DEL PUNTERO QUE EN UN PRINCIPIO APUNTA A LO MISMO PERO LUEGO LE CAMBIO EL CONTENIDO
// ES DECIR, NO ESTOY MODIFICANDO EL CONTENIDO DEL ORIGINAL SINO QUE ESTOY MODIFICANDO LA DIRECCI�N A LA QUE APUNTA LA COPIA!!!!!!!
//void modificar(char*);
//
//int main() {
//	char *a = "ho";
//
//	modificar(a);
//
//	printf("%s\n", a);
//
//	return 0;
//}
//
//void modificar(char *a) {
//	a = "cu";
//	a[0] = 'y';
//	printf("%c\n", a[0]);
//}

// y no me deja hacer a[0] = 'u'; por ejemplo

// EN ESTE CASO SI VUELVE A DEJAR PORQUE ESTOY MODIFICANDO, A TRAV�S DE LA COPIA, EL CONTENIDO DE LA DIRECCI�N A LA QUE APUNTA EL PUNTERO ORIGINAL
//void modificar(int*);
//
//int main() {
//	int b = 2,  *a = &b;
//
//	modificar(a);
//
//	printf("%d, %d\n", *a, b);
//
//	return 0;
//}
//
//void modificar(int *a) {
//	*a = 7;
//}

// ������������recuerda que para declarar variables en una misma l�nea haciendo uso de un mismo id de datatype, se puede
// hacer como en este ejemplo: se puede usar la direcci�n de memoria de la variable declarada justo a la izquierda!!!!!!!

//int main(){
//	char a = 'j';
//	struct {
//		int len;
//		char *str;
//	} pt = {10, &a}, *p = &pt;



		//////////////////////////////////6//////////////////////////////////
		// STRUCTURES

// Simple y llano: una struct es un conjunto de una o m�s variables de distinto tipo agrupadas bajo un mismo nombre
// permite tratar un conjunto de valores como una unidad en vez de como entidades individuales

// las structs se pueden copiar y asignar a, pasar a funciones y ser devueltas por funciones.



		//////////////////////////////////1//////////////////////////////////
		// BASICS OF STRUCTURES

// imaginemos que tenemos una coordenada en el eje

		//struct point {
		//	int x;
		//	int y;
		//};

// struct es la palabra clave en la declaraci�n de la struct. La declaraci�n puede ir seguida de un tag, que en este caso
// es point y sirve para representar ese conjunto de variables.

// A las variables declaradas en una struct se les llama "members"
	// una variable normal puede tener el mismo nombre que una struct o un miembro, ya que se distinguen por contexto
	// ( operador de asignaci�n, tipo el this en los getters )
	// incluso miembros de distintas structs pueden llamarse de la misma forma, aunque es conveniente evitar esto


// DECLARAR UNA STRUCT DEFINE UN TIPO!!!!!!!!!!!! por ello, el brazo derecho del bloque puede ir seguido por
// una lista de variables de este tipo. de este modo se reserva el espacio en memoria para estas variables

		//struct {
		//	...
		//} x, y, z;

		// es lo mismo que: int x, y, z;


// por otro lado, si la declaraci�n de la struct no va seguido de ninguna variable, se la considera una plantilla
// por lo que no se reserva nada de espacio en memoria, simplemente se toma constancia de que una unidad as� puede existir.
// Esta podr� ser utilizada m�s adelante para declarar/definir variables, pero no justo cuando se declara la struct

// tomando el caso de point:   struct point pt; define la variable pt de tipo point y reserva su espacio en memoria

// adem�s, se puede inicializar las variables que contiene la struct de igual modo que inicializas un array: entre {}
		// struct point pt = { 320, 300 };
// tambi�n se pueden inicializar por asignaci�n o llamando a una funci�n que devuelva una struct del tipo necesario


		// para acceder a los miembros de una struct, se hace con el operador de acceso .
		// por lo que para acceder a las variables internas de pt se har�a: printf("%d, %d\n", pt.x, pt.y);


// las structures pueden anidarse, de manera que una struct puede contener structs

	//struct rectangulo {
	//	struct point p1;
	//	struct point p2;
	//};

	//struct rectangulo screen;

// para acceder a sus contenidos se hace con los operadores de asignaci�n necesarios para ir accediendo a los distintos
// niveles: screen.p1.x



		//////////////////////////////////2//////////////////////////////////
		// STRUCTURES AND FUNCTIONS

// las �nicas operaciones que se pueden realizar con una struct son: copiar o asignarlas como una unidad, obtener su
// direcci�n con el operador de direcci�n &, y acceder a sus miembros.
// pasar structs como argumentos a funciones o que las funciones devuelvan una struct (un elemento de tipo struct)
// las structs no pueden compararse
// una struct se puede inicializar con una lista de constantes de miembros; una automatic struct puede inicializarse por asignaci�n

// a una funci�n podemos: pasarle una struct entera, pasarle sus miembros, o pasar un puntero a ella

	// devolver point structure e inicializar struct
			
			// struct point makepoint(int, int);
				
			//struct point makepoint(int x, int y) {     // para inicializar este tipo de structs
			//	struct point temp;
			//
			//	temp.x = x; // las x se distinguen por contexto!
			//	temp.y = y;
			//
			//	return temp;
			//}

			// ahora se puede hacer: struct point middle; y screen.p1 = makepoint(0, 0);


	// pasar structs a funciones

			//struct point addpoint(struct point p1, struct point p2) {
			//	p1.x += p2.x;
			//	p1.y += p2.y;
			//	return p1;
			//}

			// recuerda que en este caso se hacen copias locales (pass by value), por lo que p1 no cambia realmente


	// pasar miembros de structs a funciones

			//int ptinrect(struct point pt, struct rectangulo r) { //devuelve 1 si est� dentro de r el punto pt
			//	return /*expresi�n l�gica con varios &&*/
			//}

			//� se puede hacer otra cosa, tipo
			//
			//#define min(a, b) ((a) < (b)) ? a : b
			//#define max(a, b) ((a) > (b)) ? a : b
			//
			//struct rectangulo canonrect(struct point pt, struct rect r){
			//	struct rectangulo temp;
			//
			//	blablabla...
			//}


///////////////////

// si una struct es muy grande, es m�s conveniente pasar a las funciones un puntero a la struct. los punteros a 
// structs funcionan igual que los punteros a variables, ya que las structs son definiciones de tipo de datos

//struct point origin, *pp;
//
//pp = &origin;
//printf("%d, %d\n", (*pp).x, (*pp).y);

// los par�ntesis son necesarios porque la precedencia de . es mayor que la de *, y *(pp.x) ser�a ilegal porque x no es
// un puntero
	// el contenido del puntero es la struct!
// con el puntero manejamos la struct igual que si fuera una variable struct normal (teniendo en cuenta los operadores
// de punteros), pero con la diferencia de si se la pasamos a una funci�n, estaremos modificando la struct original, no una copia!


// de hecho, PUNTEROS A STRUCT SON TAN USADOS QUE HAY UN OPERADOR PARA ACCEDER A LOS MIEMBROS DE UN PUNTERO A STRUCT
				// p->miembro de la struct

// por lo que se podr�a escribir printf("%d, %d\n", pp->x, pp->y);
// la causa de este operador es evitar el intrincado uso del operador de indirecci�n de punteros *

// OJO: si la struct es una variable normal, no se puede usar ->; -> solo se usa cuando se aplica sobre un puntero
// a struct o si uno de sus miembros es un puntero, claro

// . y -> se eval�an de izquierda a derecha, por lo que si tenemos struct rectangulo r, *rp = &r; ...
// todo esto es equivalente:
		// r.pt1.x		rp->pt1.x		(r.pt1).x		(rp->pt1).x	



// en el TOP jerarqu�a tenemos los operadores de struct (. y ->), tenemos los par�ntesis de funciones () y los 
// corchetes de subscripts []

		//int main(){
		//	char a = 'j';
		//	struct {
		//		int len;
		//		char *str;
		//	} pt = {10, &a}, *p = &pt;
		//
		//	/*p->len = 10;
		//	p->str = &a;*/
		//
		//	printf("%d, %c\n", p->len, ++*p->str);
		//}


//++p->len; incrementa len, no p(es como tener++(pp->len))
//
//*p->str; obtiene lo que sea que apunta str(es como tener *(p->str))



		//////////////////////////////////3//////////////////////////////////
		// ARRAYS OF STRUCTURES

// supongamos que queremos contar las veces que aparecen las keywords de C en un programa. Se podr�a hacer con dos arrays
// paralelos que guarden, uno un array de strings de la palabra, y el segundo el n�mero de veces, pero esto es dif�cil de gestionar.

// mejor se puede hacer con un array de structs!

		//struct key {
		//	char *word;
		//	int count;
		//} kaytab[NKEYS];
		//
		//�
		//
		//struct key {
		//	char *word;
		//	int count;
		//};
		//
		//struct key keytab[NKEYS];


		// como se trata de un array que va a guardar unas mismas palabras todo el rato, un set de nombres constante, es mejor
		// hacerla una variable externa

		//struct key {
		//	char *word;
		//	int count;
		//} kaytab[] = {
		//	{"auto", 0},
		//	{"break", 0},
		//	{"case", 0},
		//	//...  tambi�n podr�a hacerse sin brazos, tipo "auto", 0, "break", 0, ...
		//};
		

// se puede contar el tama�o de un array a mano, pero es mucho mejor hacerlo en tiempo de compilaci�n con un operador
// ya proporcionado por C: sizeof
// con sizeof, si cambia el tama�o en bytes de, por ejemplo, un array, se puede calcular en tiempo de ejecuci�n

		// sizeof object � sizeof(data type)

// sizeof devuelve un unsigned int de tipo size_t (definido en <stddef.h> con el tama�o en bytes del elemento (objeto o tipo de dato))
// un objeto puede ser una variable, una struct o un array / data type ya sabes, int, char, double, structure, puntero,...

// para el caso de n�mero de keywords, el array es de tama�o NKEYS...
		// #define NKEYS (sizeof keytab / sizeof (struct key))

// sizeof no se puede usar en, por ejemplo, #if, porque el preprocesador no procesa tipos de datos
// pero s� puede usarse en #define porque la expresi�n input/output no la eval�a el preprocesador



		//////////////////////////////////4//////////////////////////////////
		// POINTERS TO STRUCTURES

// aqu� lo �nico a remarcar es que cambia el uso de array por punteros, y que usando punteros para
// recorrer el array se debe ir con mucho cuidado de no intentar acceder a algo que est� fuera de los l�mites del array
// y por tanto, en este caso, de que una funci�n devuelva un puntero ilegal

// aclara, de todos modos que C soporta sin fallos en la aritm�tica de punteros que se acceda a la �ltima posici�n 
// de un array &array[n] sin problemas

// adem�s, no asumir que el tama�o de una struct es la suma de los tama�os de sus miembros!!!!!!!!!!!! para alinear y que la
// aritm�tica de punteros funcione bien, puede haber agujeros en la struct, de manera que si por ejemplo una struct tiene un 
// char y un int, su tama�o no ser� 5 bytes sino 8, y sizeof devuelve el valor correcto

// sabiendo esto, si p es puntero a struct, for (p = keytab; p < keytab + NKEYS; ++p), el ++p computar� bien el tama�o del
// struct haciendo el salto de posici�n a la que apunta p



		//////////////////////////////////5//////////////////////////////////
		// SELF REFERENTIAL STRUCTURES

// si queremos contar las palabras de un input, podr�amos guardarlas ordenadas en un array, pero ser�a muy costoso ir a�adiendo
//nuevas, podr�amos guardarlas en binary search, pero tardar�a demasiado al ir a�adiendo nuevas (cuadr�tico)

// la soluci�n es un binary tree, donde cada nodo desde la ra�z contenga:
	// un puntero a su contenido, n�mero de veces aparecido, puntero al nodo hijo izquierdo, puntero al nodo hijo derecho

			//struct tnode {
			//	char *word;
			//	int count;
			//	struct tnode *left;
			//	struct tnode *right;
			//};

// una struct no puede contener una instancia de s� misma, pero es correcto que contenga un puntero a tnode, ya que lo est� declarando
// ser un puntero, no ser una instancia de s� misma.

// el �rbol funciona as�: llega una palabra y se compara con el nodo root, en funci�n del orden alfab�tico, se compara con
// el nodo left o el nodo right. llega un momento en el que se encuentra un nodo que haga match (incrementar valor de la palabra),
// o no se encuentra ninguno por lo que la palabra no est� registrada y se debe crear el nuevo nodo en el lugar adecuado y devolver
// un puntero al nuevo nodo. 

// para crear un nuevo nodo se debe reservar espacio en memoria y asociar este espacio a un punterico

				// problema relacionado con STORAGE ALLOCATORS: MIRAR EN LIBRO
				// malloc devuelve un puntero a un espacio de memoria (de n bytes) que se reserva para ese tipo de datos! pero sin inicializar!!!!
				// se debe hacer un cast (?) -----> ver chapter 7 malloc!

// a veces es necesario sacrificar espacio en memoria para obtener una correcta alineaci�n!

// �qu� es alineaci�n exactamente?



		//////////////////////////////////6//////////////////////////////////
		// TABLE LOOKUP

// interior de una table-lookup! esto es lo que se encontrar�a en el preprocesador al procesar las macros!!! #define

// cuando #define IN 1 aparece, IN y 1 se almacenan en una tabla y cuando aparecen tipo number = IN; se busca en la tabla
// para realizar la reemplazo

// hay dos rutinas para manipular nombres y textos de reemplazo: install(s, t) guarda en la tabla el nombre s y su reemplazo t
// donde s y t son s�lo strings
// lookup(s) busca el nombre s en la tabla y devuelve un puntero a la posici�n donde fue encontrada; NULL si no existe
// funciona en formato hash! el nombre recibido se convierte mediante una funci�n hash a un entero no negativo y se usa de
// �ndice en un array de punteros. La posici�n del array apunta al principio de una linked list de todos los valores
// que generan el mismo valor hash, de manera que se recorren secuencialmente (ya que guardan referencias al siguiente) 
// hasta que se encuentra/no se encuentra el deseado
// NULL tiene la posici�n del array si a�n no hay ning�n valor asignado a ese hash (lo mismo con la siguiente posici�n
// a la que apuntan los contenidos)

// el bloque de cada cadena de hash son structures del siguiente tipo
//
//#define HASHSIZE 101
//
//struct nList {
//	struct nList *next;
//	char *name;
//	char *defn;
//};
//
//static struct nList *hashtab[HASHSIZE];
//
//unsigned int hash(char *s) {
//
//	unsigned hashval;  // unsigned para asegurarnos de que el valor nunca pueda ser negativo!!!!
//
//	for (;;); //bucle for con body cosicas dentro
//
//	return hashval % HASHSIZE;
//}


// si el string deseado se va a encontrar en alg�n sitio, es empezando por el valor que devuelva ese hash, en la cadena
// de bloques almacenados a partir de ese valor

// la b�squeda de un posible valor la lleva a cabo lookup. si lookup encuentra el bloque deseado, devuelve un puntero al mismo
// si no, devuelve NULL

//struct nList *lookup(char *s) {
//	struct nList *np;
//	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {  // ESTA ES LA MANERA CONVENCIONAL DE RECORRER UNA LINKED LIST!!!!
//		// blablabla
//	}
//	return np;
//}

// install usa lookup para mirar si ya existe el nombre y replacement text a guardar. Si ya existe, sobreescribe el valor 
// output (nueva definici�n sobreescribe a la antigua); si no existe, se crea. Devuelve NULL si por cualquier raz�n no se
// puede almacenar una nueva




		//////////////////////////////////7//////////////////////////////////
		// TYPEDEF

// C provee un mecanismo para "crear" nuevos tipos de datos, que pueden ser usados en declaraciones, casts, etc. al igual que
// el nombre del tipo al que representan. 
// NO SE EST�N CREANDO NUEVOS TIPOS DE DATOS! SE EST�N REGISTRANDO SIN�NIMOS PARA LOS YA EXISTENTES.
// de momento, el �nico tipo de datos que se que se puede definir son las structs

// su primera letra en may�scula, por CONVENCI�N!!!!

//typedef int Length; // hace que Length sea un sin�nimo de int
//
//Length c, i;
//Length *a[];
//
//// similarmente... 
//typedef char *String; // hace que String sea sin�nimo de un puntero a char
//String h;
//
//// �
//typedef struct node *Treenode;
//
//typedef struct node {
//	int a;
//} a;


// typedef es una especie de define pero no est� limitado por las capacidades del preprocesador, por lo que puede consistir
// en expresiones m�s complejas! (ver libro)

// size_t es un ejemplo de typedef

// sirven para facilitar la portabilidad de programas con variables machine-dependent
		//bueno, no es nada raro
		//un typedef es decir
		//llamar POLLO a un int
		//y ya puedes usar variables POLLO
		//pensar�s que no tiene mucha utilidad pero hay un motivo
		//y es poder cambiar el tipo de datos
		//por ejemplo un programa que usa floats o doubles
		//te haces un typedef de float a "real"
		//y usas variables real
		//si necesitas m�s precisi�n a costa de velocidad cambias el typedef y el programa entero se adapta

// y para facilitar la lectura del c�digo



		//////////////////////////////////8//////////////////////////////////
		// UNIONS

// unions son variables que pueden contener, en tiempos distintos, datos de distinto tipo y tama�o, es decir, se le pueden asignar
// diferentes tipos de datos y el compilador se encarga de darle el tama�o adecuado para almacenar cualquiera de los posibles
// y gesionar la alineaci�n en memoria. Unions permiten manejar distintos tipos de datos en una misma �rea de almacenamiento

// si puede asign�rsele tres tipos de datos, es conveniente que la variable sea lo suficientemente grande como para almacenar
// el m�s grande de los tres tipos de datos y que se almacene en el mismo sitio, independientemente del tipo

//union u_tag {
//	int val;
//	float fval;
//	char *cval;
//} u;

// u ser� lo suficientemente grande como para guardar cualquiera de los tres tipos. Su asignaci�n es implementation-dependent.
// se asigna el tipo y se utiliza consecuentemente, con l�gica y coherencia, y el tipo devuelto ser� el �ltimo tipo asignado, obvio

// so, it's the programmer's resposibility to keep track of the last value assigned to the variable, that is, keep track
// of which type is currently assigned to the union


// para acceder a los miembros de las unions: unionname.member // en caso de puntero  unionpointer->member

// puede haber unions dentro de structures, of course
// se acceder�a al valor "val" 
	//normal tipo structarray[i].nombreunion.val
	//si es un puntero a char *structarray[i].nombreunion.cval  �  structarray[i].nombreunion.val[0]

// una union, a t�rminos de efecto, es una struct que tiene offset 0 para todos sus miembros y que es lo bastante
// grande para almacenar cualquiera de ellos en un momento determinado y alinearse bien en memoria independientemente
// del tipo que contenga en el momento

// la union s�lo puede inicializarse con un dato del tipo de su primer miembro!!!!!!!!!!!!!



		//////////////////////////////////9//////////////////////////////////
		// BIT FIELDS

//un bitfield s�lo es una cosa
//poderle poner "nombre"  a bits individuales de un int
//es como que a partir de un int, haces muchas variables de pocos bits


