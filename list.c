#include <stdlib.h>
#include <stdio.h>
#include "list.h"

node_t *list_head(list_t list)
{
  if (!*list)
    return NULL;
  return *list;
}

node_t *list_tail(list_t list)
{
  if (!*list)
    return NULL;
  node_t *curr = *list;
  while (curr->next)
    curr = curr->next;
  return curr;
}

node_t *list_item_next(list_t list, int item)
{
  for (node_t *curr = *list; curr; curr = curr->next)
    if (curr->value == item && curr->next)
      return curr->next;
    else if (curr->value == item && !curr->next)
      return NULL;
  return NULL;
}

node_t *list_item_index(list_t list, unsigned int index)
{
  if (index == 0)
    return *list;
  node_t *curr = *list;
  for (int i = 0; i < index && curr; i++)
    curr = curr->next;
  if (!curr)
    return NULL;
  return curr;
}

void list_push(list_t list, int item)
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = item;
  new_node->next = *list;
  *list = new_node;
}

void list_append(list_t list, int item)
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = item;
  new_node->next = NULL;
  if (!*list)
  {
    *list = new_node;
    return;
  }
  node_t *curr = *list;
  while (curr->next)
    curr = curr->next;
  curr->next = new_node;
}

void list_insert(list_t list, int previtem, int newitem)
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = newitem;
  for (node_t *curr = *list; curr; curr = curr->next)
    if (curr->value == previtem)
    {
      new_node->next = curr->next;
      curr->next = new_node;
      return;
    }
}

void list_insert_sorted(list_t list, int newitem, int (*comp)(const int a, const int b))
{
  if (!*list)
  {
    list_push(list, newitem);
    return;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = newitem;
  node_t *curr = *list;
  node_t *prev = NULL;
  while (curr)
  {
    if (comp(curr->value, newitem) >= 0)
    {
      if (!prev)
        list_push(list, newitem);
      else
      {
        new_node->next = curr;
        prev->next = new_node;
      }
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  new_node->next = curr;
  prev->next = new_node;
}

void list_insert_index(list_t list, unsigned int index, int newitem)
{
  if (index == 0)
  {
    list_push(list, newitem);
    return;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = newitem;
  node_t *curr = *list;
  for (int i = 0; i < index - 1 && curr; i++)
    curr = curr->next;
  if (!curr)
    return;
  new_node->next = curr->next;
  curr->next = new_node;
}

node_t *list_pop_head(list_t list)
{
  if (!*list)
    return NULL;
  node_t *tmp = *list;
  node_t *tmp2 = *list;
  *list = (*list)->next;
  free(tmp);
  return tmp2;
}

node_t *list_pop_tail(list_t list)
{
  node_t *tmp;
  if (!*list)
    return NULL;
  if (!(*list)->next)
    return list_pop_head(list);
  node_t *curr = *list;
  node_t *prev = NULL;
  while (curr->next)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  tmp = curr;
  free(curr);
  return tmp;
}

void list_remove(list_t list, int item)
{
  node_t *curr = *list;
  node_t *prev = NULL;
  while (curr)
  {
    if (curr->value == item)
    {
      node_t *tmp = curr;
      if (!prev)
        *list = curr->next;
      else
        prev->next = curr->next;
      free(tmp);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void list_remove_all(list_t list, int item)
{
  node_t *curr = *list;
  node_t *prev = NULL;
  while (curr)
  {
    if (curr->value == item)
    {
      node_t *tmp = curr;
      if (!prev)
        *list = curr->next;
      else
        prev->next = curr->next;
      curr = curr->next;
      free(tmp);
    }
    else
    {
      prev = curr;
      curr = curr->next;
    }
  }
}

node_t *list_remove_index(list_t list, unsigned int index)
{
  if (index == 0)
    return list_pop_head(list);
  node_t *curr = *list;
  node_t *prev = NULL;
  node_t *tmp;
  node_t *tmp2;
  for (int i = 0; i < index && curr; i++, curr = curr->next)
    prev = curr;
  if (!curr)
    return NULL;
  tmp = curr;
  tmp2 = curr;
  prev->next = curr->next;
  free(tmp);
  return tmp2;
}

void list_reverse(list_t list)
{
  node_t *curr = *list;
  node_t *prev = NULL;
  while (curr)
  {
    node_t *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *list = prev;
}

void list_reverse_group(list_t list, unsigned int n)
{
  if (n < 2)
    return;
  int len = list_length(list);
  node_t *ptr = *list;
  node_t *ptr_start = *list;
  for (int i = n; i <= len; i += n)
  {
    node_t *aux = NULL;
    ptr_start = ptr;
    for (int j = 0; j < n && ptr; j++)
    {
      list_append(&aux, ptr->value);
      ptr = ptr->next;
    }
    list_reverse(&aux);
    node_t *curr1 = aux;
    node_t *curr2 = ptr_start;
    for (int j = 0; j < n && curr1; j++)
    {
      curr2->value = curr1->value;
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    list_free(&aux);
  }
  node_t *aux = NULL;
  ptr_start = ptr;
  while (ptr)
  {
    list_append(&aux, ptr->value);
    ptr = ptr->next;
  }
  list_reverse(&aux);
  node_t *curr1 = aux;
  node_t *curr2 = ptr_start;
  while (curr1)
  {
    curr2->value = curr1->value;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  list_free(&aux);
}

size_t list_length(list_t list)
{
  size_t i = 0;
  for (node_t *curr = *list; curr; curr = curr->next)
    ++i;
  return i;
}

int list_contains(list_t list, int value)
{
  for (node_t *curr = *list; curr; curr = curr->next)
    if (curr->value == value)
      return 1;
  return 0;
}

void list_free(list_t list)
{
  node_t *curr = *list;
  while (curr)
  {
    node_t *tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  *list = NULL;
}