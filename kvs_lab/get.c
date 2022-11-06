#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */

	char* value = (char*)malloc(sizeof(char)*100);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}
    node_t *cur = kvs->db;
    int cnt = kvs->items;
    for (int i = 0;i < cnt;i++)
    {
        if (strcmp(cur->key, key)==0){
            strcpy(value, cur->value);
            return value;
        }
        cur = cur->next;
    } 

	strcpy(value, "deadbeaf");
	return value;

}
