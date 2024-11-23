#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 2){
		FILE *file = fopen(argv[1], "rb");
		
		if(file == NULL){
			printf("Erro open archive!\n");
			return -1;
		}

		fseek(file, 0, SEEK_END);

    	int size = ftell(file);
		char buffer[size];
		int work[size];

		fseek(file, 0, SEEK_SET);

		printf("Size %d\n", size);

		int i = 0;
		while(feof(file) == 0) {
        	fread(buffer, sizeof(char), sizeof(buffer), file);
			work[i] = atoi(buffer);
			printf("%s", buffer);
			i++;
    	}


		fclose(file);
	}else{
		printf("Erro in arguments!\n");
		return -1;
	}
	return 0;
}