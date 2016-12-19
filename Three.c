#include <stdio.h>
#include <string.h>

// esta es otra manera de recorrer un array, el el while, entiendo que si tiene valor genera un 1 true;

//int main() {
//	char a[] = "a-z";
//	int i = 0;
//
//	for (i = 0; a[i]; ++i);
//	// ó
//	while (a[i]) {
//		++i;
//	}
//
//	printf("%d\n", i);
//
//	return 0;
//}


//////////////////////////////////3//////////////////////////////////
// CONTROL FLOW

// flujo de control, secuencia de ejecución de las instrucciones


		//////////////////////////////////1//////////////////////////////////
		// STATEMENTS AND BLOCKS

// ; marca el fin de una sentencia. {} es un bloque, y un bloque = conjunto de sentencias que actúan como una

		//////////////////////////////////2//////////////////////////////////
		// IF ELSE

// lo normal

		//////////////////////////////////2//////////////////////////////////
		// ELSE IF

//  if, else if, else
// "else" es el caso default. si nunca se va a llegar, omitirlo o usarlo para catch de algo imposible


		//////////////////////////////////4//////////////////////////////////
		// SWITCH

// se necesita break o return para salir de un switch, ya que si no las expresiones se sucederían
// hasta el final si no encuentran un break.

// expr1:
// expr2
// expr3:
// expr4: tal... break;
// esto daría por bueno que se si se cumple 2, se pasa por 3, y en 4 se haría algo respecto a cumplirse las anteriores

		//switch (expresion) {
		//	case const-expr: ... break;
		//	case const-expr2: ... break;
		//	default: ... break;  
		//}

// el break en el default es redundante pero es "programación defensiva"
// ante posibles futuros cambios

// IMPORTANTE: no puedes hacer que s[j] = "\\"; porque la posición de un char en el array no puede ser igual
// a un puto array
//case '\n':
//	s[j] = '\\';
//	s[j + 1] = 'n';
//	j += 2;
//	break;

/*void scape(char s[], char t[]);

int main() {

	char s[100];
	char t[] = "Ojete moreno	y rosica me comen la colica";

	scape(s, t);

	printf("%s\n", s);

	return 0;
}

void scape(char s[], char t[]) {
	int i, j, c;
	j = 0;
	for (i = 0; i < strlen(t); ++i) {
			switch (t[i]) {
			case '\n':
				s[j] = '\\';
				s[j+1] = 'n';
				j += 2;

				//s[j++] = '\\';
				//s[j] = 'n';

				break;
			case '\t':
				s[j] = '\\';
				s[j+1] = 't';
				j += 2;
				break;
			default: 
				s[j++] = t[i];
				break;
			}
	}
	s[j] = '\0';
	return 0;
}*/



		//////////////////////////////////5//////////////////////////////////
		// LOOPS: WHILE AND FOR

// while: mientras la expresión no sea 0, se va haciendo

// for: equivalente a un expr1; while ()... y al final del while expr3.
// expr2 es una expresión relacional siempre (simple o compuesta)
// ya sabes cuando es preferible
// puede dejarse vacío cualquier campo for (;;); es válido, pero será infinito a no ser
// que se le ponga un break

// la variable usada en el for conserva su valor al salir!!!!
/*main() {
	int i;
	for (i = 0; i < 100; ++i);
	printf("%d\n", i);
}*/

// un for ya sabes que su expresión lógica puede ser compuesta ( a && b && c)
// un for puede usar comas para considerar varias expresiones (expr1 y expr3),
// y estas se evalúan de izquierda a derecha. Por ejemplo:
// for (i = 0, j = 0; i < 100; ++i, --j);

// las comas de, por ejemplo, parámetros de una función, o declaraciones de variables
// no se evalúan de izquierda a derecha; no se sabe el orden, simplemente se evalúan


				//EJERCICIO 3.3 (restringido a x-y
				//void expand(char[], char[]);

				//int main() {
				//	char a[] = "a-z";
				//	char b[100];

				//	expand(a, b);

				//	printf("%s\n", b);

				//	return 0;
				//}

				//void expand(char s[], char t[]) {
				//	int i, j, inicio, end;

				//	if ((strlen(s) < 5) && (s[0] >= 'A') && (s[2] <= 'z') && (s[1] == '-') && (s[0] < s[2])) {
		
				//		end = s[2];
				//		for (i = s[0], j = 0; i <= end; ++i, ++j){
				//			t[j] = i;
				//		}
				//		t[j] = '\0';
				//	}
				//}



		//////////////////////////////////6//////////////////////////////////
		// LOOPS: DO-WHILE

// aquí se comprueba la condición AL FINAL del loop. el body se ejecuta siempre al menos una vez.
//do {
//	
//} while (1);


		//////////////////////////////////7//////////////////////////////////
		// BREAK AND CONTINUE

// con un break podemos romper la ejecución de un bucle cuando se quiera.

// quitar cosas del final del array
/*int trim(char s[]) {
	int n;

	for (n = strlen(s) - 1; n >= 0; --n) {
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n'){
			break;
		}
	}
	s[n + 1] = '\0';
	return n;
}*/

// con un continue, se procede a la siguiente iteración: en un while se ejecuta la condición;
// en un for, se pasa al incremento y nuevo test de la condición

//sólo procesar números positivos de un array
/*for (i = 0; i < n; ++i) {
	if (a[i] < 0)
		continue;
	// procesar número positivo
}*/



		//////////////////////////////////8//////////////////////////////////
		// GOTO AND LABELS

// NUNCA NUNCA NUNCA usar GOTO salvo en bucles anidados muy tóxicos. No se puede usar break porque este sólo se
// aplica al loop dentro del que se encuentra, no a todos los bucles anidados

// etiquetas tienen un alcance local en la función a la que pertenecen. Un goto va a una 
// etiqueta que se encuentre en su misma función
