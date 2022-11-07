#include "kvs.h"

int close(kvs_t* kvs)
{
	node_t *clear = kvs->db;
    while (clear){
        free(clear);
        clear = clear->next;
    }
    free(kvs);
	return 0;
}
