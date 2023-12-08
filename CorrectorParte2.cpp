void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	/*
	//Sustituya estas lineas por su código
	iNumElementos = 1;
	strcpy(szPalabras[0], "AquiVaElDiccionario");
	iEstadisticas[0] = 1; // la primer palabra aparece solo una vez.*/

	/* Variable de archivo*/
	FILE* fp;
	iNumElementos = 0;

	/*Variable = i*/
	int i;


	/*Variables para que usaremos para guardar los datos */
	char lectura, array[TAMTOKEN];

	/*Aca era el problema*/
	//Para iniciar el arreglo de estadisticas.
	for (i = 0; i < NUMPALABRAS; i++)
		iEstadisticas[i] = 0;

	/*Se abre el archivo en modo lectura*/
	fopen_s(&fp, szNombre, "r");

	/*Variable */
	int contador = 0;

	/*Variable para el puntuacion <<Esto nos servira para conocer las palabras>> */
	char puntuacion[] = " \t\n\r.,;() ";

	//char puntuacion2[] = { ',',';','.','(',')',9,10,13,32 } ;

	/*Comprobamos que de verdad abrio*/
	if (fp == NULL)
		return;

	/*Mientras que la lectura sea igual al fichero (sea diferente a fin del documento */
	while ((lectura = fgetc(fp)) != EOF) {

		/*Declaramos una bandera*/
		/*Nota: bandera = flag*/
		bool bandera = true;

		/*Para pasar las mayusculas a minusculas*/
		lectura = tolower(lectura);

		/*Comprobar que no hay palabras con signo de puntuación */
		for (i = 0; i < strlen(puntuacion); i++)

			/*Compara si el caracter que recibió si esta dentro de la lectura o es un signo de puntuación*/
			if (puntuacion[i] == lectura)
				bandera = false;

		/*Si count es menor que TAMTOKEN Y de la bandera <<Continuar>> */
		if (contador < TAMTOKEN && bandera) {
			/*De lectura guardarlo al array*/
			array[contador++] = lectura;
			continue;
		}
		/* Si no(si es count el igua a cero <<Continuar>> */
		else if (contador == 0)
			continue;

		/*Si no(si es count el igua a 1, asignar 0 a count. <<Continuar>> */
		else if (contador == 1 && bandera) {
			contador = 0;
			continue;
		}
		/*Cuando las encuentre marcar un espacio*/
		array[contador] = '\0';

		/*Despues de comprobar en el abecedario y la puntuacion */
		for (i = 0; i < iNumElementos && !bandera; i++) {

			/*Aqui se hace la comparacion de las palabras*/
			if (strcmp(szPalabras[i], array) == 0) {
				/*Hacerlo hasta formar la palabra*/
				iEstadisticas[i]++;
				bandera = true;
			}
		}
		/*Si es diferente de la bandera*/
		if (!bandera) {
			/*Pasar todos los palabras que estan en el array a szPalabras[]*/
			strcpy_s(szPalabras[iNumElementos], array);
			iEstadisticas[iNumElementos++]++;

		}/*Para retornar*/
		contador = 0;
	}/*Fin del while o el documento*/
	fclose(fp);


	//iEstadisticas[iNumElementos] = 1;

	/*Método burbuja para el ordenamiento*/
	for (int j = 0; j < iNumElementos - 1; j++) {

		for (i = j + 1; i < iNumElementos; i++) {

			if (strcmp(szPalabras[j], szPalabras[i]) > 0) {
				strcpy_s(array, szPalabras[j]);
				strcpy_s(szPalabras[j], szPalabras[i]);
				strcpy_s(szPalabras[i], array);
				contador = iEstadisticas[j];
				iEstadisticas[j] = iEstadisticas[i];
				iEstadisticas[i] = contador;
			}
		}
	}
}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						//Palabra a clonar   palabra
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void	ClonaPalabras(
	char* szPalabraLeida,						// Palabra a clonar
	char  szPalabrasSugeridas[][TAMTOKEN], 	    //Lista de palabras clonadas
	int& iNumSugeridas)						    //Numero de elementos en la lista
{

	/*
	//Sustituya estas lineas por su c digo
	strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
	iNumSugeridas = 1;							//Una sola palabra sugerida*/

	/*Variables para la clonacion*/
	char aux[TAMTOKEN]; iNumSugeridas = 0;

	/*Pasar de szPalabraLeida al la variable aux*/
	strcpy_s(aux, szPalabraLeida);

	//Pasar el abecedario en cada caracter
	for (int i = 0; i < strlen(szPalabraLeida); i++) {

		for (int j = 0; j < LONGITUD; j++) {
			aux[i] = abecedario[j];
			/*Numero de elementos en la lista a la Lista de palabras clonadas*/
			strcpy_s(szPalabrasSugeridas[iNumSugeridas++], aux);
		} aux[i] = szPalabraLeida[i];
	}
	//Pasar el abecedario entre los caracteres
	int k;
	for (k = 1; k < strlen(szPalabraLeida) + 1; k++) {
		aux[k] = szPalabraLeida[k - 1];

		/*Para asignar espacios*/
	} aux[k] = '\0';

	for (int i = 0; i < strlen(szPalabraLeida) + 1; i++) {

		for (int j = 0; j < LONGITUD; j++) {
			aux[i] = abecedario[j];
			/*Numero de elementos en la lista a la Lista de palabras clonadas*/
			strcpy_s(szPalabrasSugeridas[iNumSugeridas++], aux);
		}/*Palabra a clonar es igual auxiliar*/
		aux[i] = szPalabraLeida[i];
	}
	//Para suprimir los caracteres
	int contador = 0;
	for (int i = 0; i < strlen(szPalabraLeida) && strlen(szPalabraLeida) != 1; i++) {

		for (int j = 0; j < strlen(szPalabraLeida); j++) {
			if (j != i)
				aux[contador++] = szPalabraLeida[j];

			/*Para asignar espacios*/
		} aux[contador] = '\0';

		/*Numero de elementos en la lista a la Lista de palabras clonadas*/
		strcpy_s(szPalabrasSugeridas[iNumSugeridas++], aux);

		/*Palabra a clonar palabra al auxiliar*/
		strcpy_s(aux, szPalabraLeida);

		contador = 0;
	}
	//Transposición de los caracteres.
	for (int i = 0; i < strlen(szPalabraLeida) - 1; i++) {
		aux[i] = szPalabraLeida[i + 1];
		aux[i + 1] = szPalabraLeida[i];

		/*Numero de elementos en la lista a la Lista de palabras clonadas*/
		strcpy_s(szPalabrasSugeridas[iNumSugeridas++], aux);
		/*Palabra a clonar palabra al auxiliar*/
		strcpy_s(aux, szPalabraLeida);
	}
	strcpy_s(szPalabrasSugeridas[iNumSugeridas++], szPalabraLeida);


	//Método burbuja, para el ordenamiento.
	for (int j = 0; j < iNumSugeridas - 1; j++) {

		for (int i = j + 1; i < iNumSugeridas; i++) {

			if (strcmp(szPalabrasSugeridas[j], szPalabrasSugeridas[i]) > 0) {
				/*Lista de palabras clonadas al aux*/
				strcpy_s(aux, szPalabrasSugeridas[j]);
				strcpy_s(szPalabrasSugeridas[j], szPalabrasSugeridas[i]);
				strcpy_s(szPalabrasSugeridas[i], aux);
			}
		}
	}


}
