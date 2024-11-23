#pragma once

typedef struct node
{
  int value;
  struct node *next;
} node_t;
typedef node_t **list_t;
typedef unsigned long long size_t;

node_t *list_head(list_t list);
node_t *list_tail(list_t list);
node_t *list_item_next(list_t list, int item);
node_t *list_item_index(list_t list, unsigned int index);
int list_contains(list_t list, int value);
size_t list_length(list_t list);
void list_push(list_t list, int item);
void list_append(list_t list, int item);
void list_insert(list_t list, int previtem, int newitem);
void list_insert_sorted(list_t list, int newitem, int (*comp)(const int a, const int b));
void list_insert_index(list_t list, unsigned int index, int newitem);
node_t *list_pop_head(list_t list);
node_t *list_pop_tail(list_t list);
void list_remove(list_t list, int item);
void list_remove_all(list_t list, int item);
node_t *list_remove_index(list_t list, unsigned int index);
void list_reverse(list_t list);
void list_reverse_group(list_t list, unsigned int n);
void list_free(list_t list);