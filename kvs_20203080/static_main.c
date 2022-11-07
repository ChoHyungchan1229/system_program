#include "kvs.h"

int main()
{
	// 1. create KVS
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// 2. put data 
	
	// 1) file read 
	// 2) put data 
	
    char key[100]; 
	char* value = (char*) malloc (sizeof(char)* 300);
	char* rvalue;

	strcpy(key, "Eunji");
	strcpy(value, "Seoul");

	if(put(kvs, key, value) < 0){
		printf("Failed to put data\n");
		exit(-1);
	}

	// 3. get for test 

	// 1) file read 
	// 2) get & compare return value with original vallue 

	if(!(rvalue = get(kvs, key))){
		printf("Failed to get data\n");
		exit(-1);
	}

	printf("\nget: %s, %s\n", key, rvalue);

	// 4. print all items 

	int nitems = seek(kvs);
	printf("%d items are found\n", nitems);

	// 5. close 
	close(kvs);
	
	return 0;
}
