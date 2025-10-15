//
// Created by 33441 on 2025/10/10.
//
#include "nlist.h"

void nlist_init(nlist_t * list){
    list->first = list->last = (nlist_node_t *)0;
    list->count = 0;
}

void nlist_insert_first(nlist_t * list, nlist_node_t * node){
    node->pre = NULL;
    node->next = list->first;

    if(nlist_is_empty(list)){
        list->first = node;
        list->last = node;
    }else{
        list->first->pre = node;
        list->first = node;
    }
    list->count++;
}

void nlist_insert_last(nlist_t* list, nlist_node_t* node){
    node->next = NULL;
    node->pre = list->last;

    if(nlist_is_empty(list)){
        list->first = node;
        list->last = node;
    }else{
        list->last->next = node;
        list->last = node;
    }
    list->count++;
}

nlist_node_t * nlist_remove(nlist_t *list, nlist_node_t *node) {
    if (!list || !node || list->count == 0)
        return NULL;

    // 更新前驱节点
    if (node->pre){
        node->pre->next = node->next;
    }else{
        list->first = node->next;
    }

    if (node->next) {
        node->next->pre = node->pre;
    }else {
        list->last = node->pre;
    }   // 删除的是最后一个节点
    list->count--;
    node->pre = node->next = NULL;
    return node;
}

void nlist_insert_after(nlist_t* list, nlist_node_t* pre, nlist_node_t* node){
    if(nlist_is_empty(list) || !pre){
        nlist_insert_first(list, node);
    }else if(pre->next == NULL){
        nlist_insert_last(list,node);
    }else{
        pre->next->pre = node;
        node->next = pre->next;
        pre->next = node;
        node->pre = pre;
    }
    list->count++;
    return;
}