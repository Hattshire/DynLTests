#include <stdio.h>
#include <stdlib.h>

//Libreria que contiene dlopen y dlsym
//Necesita usar libreria( gcc -ldl)
#include <dlfcn.h>


int main() {
	//Donde se guarda la libreria
	void *handle;
	//Nombre de la libreria
	char strin[100];
	//Funcion que se quiere obtener
	void (*loadThis)(void);
	
	//Obtenemos donde esta la libreria
	scanf("%s", strin);
	
	//Abrimos la libreria TODO: ¿que es RTLD_LAZY?
	handle = dlopen (strin, RTLD_LAZY);
	//Revisamos si la libreria se abrio correctamente
	if (!handle) {
		printf("error D:");
		exit(191191);
	}
	
	//Cargamos la funcion en la libreria a la funcion en este programa
	loadThis = dlsym(handle, "loadThis");
	//Ejecutamos la función
	(*loadThis)();
	
	return 0;
}

