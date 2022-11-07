#include "kvs.h"
#include <dlfcn.h>


int main()
{   //handle init
    void* handle = dlopen("./libkvs.so", RTLD_LAZY);
    if(!handle){
        printf("error : %s\n", dlerror());
        return -1;
    }
    kvs_t*(*open)();
    int (*put)(kvs_t*, const char*, const char*);
    char*(*get)(kvs_t*, const char*);
    int (*seek)(kvs_t*);
    int (*close)(kvs_t*);


    open = (void(*))dlsym(handle, "open");
	// 1. create KVS
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}
    put = (int(*)(kvs_t*, char*, char*))dlsym(handle, "put");
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

    get = (char*(*)(kvs_t*, char*))dlsym(handle, "get");
	// 3. get for test 

	// 1) file read 
	// 2) get & compare return value with original vallue 

	if(!(rvalue = get(kvs, key))){
		printf("Failed to get data\n");
		exit(-1);
	}

	printf("\nget: %s, %s\n", key, rvalue);
    
    seek = (int(*)(kvs_t*))dlsym(handle,"seek");
	// 4. print all items 

	int nitems = seek(kvs);
	printf("%d items are found\n", nitems);

    close = (int(*)(kvs_t*))dlsym(handle, "close");
	// 5. close 
	close(kvs);

	dlclose(handle);


	return 0;
}
