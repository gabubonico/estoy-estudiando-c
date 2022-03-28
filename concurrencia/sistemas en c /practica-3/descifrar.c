#include <stddef.h>
#include <stdio.h>

const unsigned DELTA = 0x9e3779b9; 

void decrypt(unsigned * v, unsigned * k){

	unsigned sum = 0xC6ef3720;

	for(int i = 0; i < 32; i++) {
		v[1] -=	((v[0] << 4) + k[2]) ^ (v[0] + sum) ^ ((v[0] << 5) + k[3]);
		v[0] -=	((v[1] << 4) + k[0]) ^ (v[1] + sum) ^ ((v[1] << 5) + k[1]);
		sum -= DELTA;
	}	
}

int main(int argc, char const *argv[])
{
	FILE *ptr_fichero_entrada, *ptr_fichero_salida;
    unsigned k[4]={128, 129, 130, 131}; 
	unsigned * ptr_memoria_de;
	
	if(argc != 3){
		printf("se esperaban dos parametros de entrada, el fichero encriptado y la salida\n");
		exit(-1);
	}
	
	ptr_fichero_entrada = fopen(argv[1],"rb");
	if (ptr_fichero_entrada == NULL){
		perror("error al abrir el fichero de entrada\n");
		exit(-1);
	}

    ptr_fichero_salida = fopen(argv[2],"rb");
	if (ptr_fichero_salida == NULL){
		perror("error al abrir el fichero de salida\n");
		exit(-1);
	}

	// leemos el fichero binario
	unsigned tam_fichero;
	if(fread(&tam_fichero,sizeof(unsigned),1,ptr_fichero_entrada) != 1){
		perror("error al leer tamaño de fichero");
		exit(-1);
	}

	// tamaño de fichero en tam_fichero
	unsigned tam_fichero_2_des;
	// nos aseguramos de uqe sea multiplo de 8 for the sake of decrypt
	if(tam_fichero % 8 != 0) tam_fichero_2_des = tam_fichero + 8 - tam_fichero % 8;
	else tam_fichero_2_des = tam_fichero;

	ptr_memoria_de = malloc(tam_fichero_2_des);
	if(ptr_memoria_de == NULL){
		perror("no hay memoria suficiente para desencriptar");
		exit(-1);
	}

	//leemos
	fread(ptr_memoria_de,tam_fichero,1,ptr_fichero_entrada);
	for (size_t i = 0; i < tam_fichero/sizeof(unsigned); i += 2) {
		decrypt(&ptr_memoria_de[i],k);
	}

	fclose(ptr_fichero_entrada);
	fclose(ptr_fichero_salida);

    return 0;
}
