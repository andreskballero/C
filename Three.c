#include <stdio.h>
#include <string.h>

// esta es otra manera de recorrer un array, el el while, entiendo que si tiene valor genera un 1 true;

//int main() {
//	char a[] = "a-z";
//	int i = 0;
//
//	for (i = 0; a[i]; ++i);
//	// �
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

// flujo de control, secuencia de ejecuci�n de las instrucciones


		//////////////////////////////////1//////////////////////////////////
		// STATEMENTS AND BLOCKS

// ; marca el fin de una sentencia. {} es un bloque, y un bloque = conjunto de sentencias que act�an como una

		//////////////////////////////////2//////////////////////////////////
		// IF ELSE

// lo normal

		//////////////////////////////////2//////////////////////////////////
		// ELSE IF

//  if, else if, else
// "else" es el caso default. si nunca se va a llegar, omitirlo o usarlo para catch de algo imposible


		//////////////////////////////////4//////////////////////////////////
		// SWITCH

// se necesita break o return para salir de un switch, ya que si no las expresiones se suceder�an
// hasta el final si no encuentran un break.

// expr1:
// expr2
// expr3:
// expr4: tal... break;
// esto dar�a por bueno que se si se cumple 2, se pasa por 3, y en 4 se har�a algo respecto a cumplirse las anteriores

		//switch (expresion) {
		//	case const-expr: ... break;
		//	case const-expr2: ... break;
		//	default: ... break;  
		//}

// el break en el default es redundante pero es "programaci�n defensiva"
// ante posibles futuros cambios

// IMPORTANTE: no puedes hacer que s[j] = "\\"; porque la posici�n de un char en el array no puede ser igual
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

// while: mientras la expresi�n no sea 0, se va haciendo

// for: equivalente a un expr1; while ()... y al final del while expr3.
// expr2 es una expresi�n relacional siempre (simple o compuesta)
// ya sabes cuando es preferible
// puede dejarse vac�o cualquier campo for (;;); es v�lido, pero ser� infinito a no ser
// que se le ponga un break

// la variable usada en el for conserva su valor al salir!!!!
/*main() {
	int i;
	for (i = 0; i < 100; ++i);
	printf("%d\n", i);
}*/

// un for ya sabes que su expresi�n l�gica puede ser compuesta ( a && b && c)
// un for puede usar comas para considerar varias expresiones (expr1 y expr3),
// y estas se eval�an de izquierda a derecha. Por ejemplo:
// for (i = 0, j = 0; i < 100; ++i, --j);

// las comas de, por ejemplo, par�metros de una funci�n, o declaraciones de variables
// no se eval�an de izquierda a derecha; no se sabe el orden, simplemente se eval�an


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

// aqu� se comprueba la condici�n AL FINAL del loop. el body se ejecuta siempre al menos una vez.
//do {
//	
//} while (1);


		//////////////////////////////////7//////////////////////////////////
		// BREAK AND CONTINUE

// con un break podemos romper la ejecuci�n de un bucle cuando se quiera.

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

// con un continue, se procede a la siguiente iteraci�n: en un while se ejecuta la condici�n;
// en un for, se pasa al incremento y nuevo test de la condici�n

//s�lo procesar n�meros positivos de un array
/*for (i = 0; i < n; ++i) {
	if (a[i] < 0)
		continue;
	// procesar n�mero positivo
}*/



		//////////////////////////////////8//////////////////////////////////
		// GOTO AND LABELS

// NUNCA NUNCA NUNCA usar GOTO salvo en bucles anidados muy t�xicos. No se puede usar break porque este s�lo se
// aplica al loop dentro del que se encuentra, no a todos los bucles anidados

// etiquetas tienen un alcance local en la funci�n a la que pertenecen. Un goto va a una 
// etiqueta que se encuentre en su misma funci�n
