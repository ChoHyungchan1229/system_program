#include "kvs.h"
#include <stdio.h>

kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));
	if(kvs)
		kvs->items = 0;
    FILE* fp = fopen("./student.dat", "r");
    char str[300];

    while (fgets(str, sizeof(str), fp))
    {   
        //printf("%s\n",str);

        node_t *tmp = (node_t*)malloc(sizeof(node_t));
        tmp->next = NULL;

        char *ptr = strtok(str, " ");
        strcpy(tmp->key, ptr);
        ptr = strtok(NULL, "\n");
        char *buf_val = malloc(sizeof(char)*100);
        strcpy(buf_val, ptr);
        tmp->value = buf_val;
        
        put(kvs, tmp->key, tmp->value);
    }
    

	return kvs;
}
