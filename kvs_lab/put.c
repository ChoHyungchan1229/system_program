#include "kvs.h"
#include <stdio.h>

int put(kvs_t* kvs, const char* key, const char* value)
{
    
    node_t *new = (node_t*)malloc(sizeof(node_t));
    new->next = NULL;
    strcpy(new->key, key);
    char *buf_val = malloc(sizeof(char)*100);
    strcpy(buf_val, value);
    new->value = buf_val;

    if (kvs->items == 0){
        kvs->db = new;
        kvs->items += 1;
        printf("put: %s, %s\n", kvs->db->key, kvs->db->value);
        return 0;
    }
    
    node_t *cur = kvs->db;
    while(cur->next != NULL){
        cur = cur->next;
    }
    
    kvs->items += 1;
    cur->next = new;
    printf("put: %s, %s\n", new->key, new->value);

	return 0;
}
