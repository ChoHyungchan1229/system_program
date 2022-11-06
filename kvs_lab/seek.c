#include "kvs.h"

int seek(kvs_t* kvs)
{
	printf("\nSeek operation...\n");
    node_t *sort = (node_t*)malloc(sizeof(node_t));
    int cnt = kvs->items;
    char **key_list = (char**)malloc(sizeof(char*)*cnt);
    if (key_list==NULL) printf("Fail to key_list\n");
    for (int i = 0;i<cnt;i++){
        key_list[i] = (char*)malloc(sizeof(char)*100);
    }
    sort = kvs->db;
    for (int i = 0;i<cnt;i++){
        strcpy(key_list[i], sort->key);
        sort = sort->next;
    }
    char tmp_str[100];
    for (int i = 0;i < cnt-1;i++){
        for (int j = 0;j<cnt-1-i;j++){
           if (strcmp(key_list[j], key_list[j+1]) > 0){
                strcpy(tmp_str, key_list[j]);
                strcpy(key_list[j], key_list[j+1]);
                strcpy(key_list[j+1], tmp_str);
           }
        }
    }
    for (int i = 0;i<cnt;i++){
        char *val = get(kvs, key_list[i]);
        printf("(%s, %s)\n", key_list[i], val);
    }
	return kvs->items;
}
