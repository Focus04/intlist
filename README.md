
# Linked List Library

This C library provides a set of functions to work with singly linked lists of integers. It includes basic operations like insertion, deletion, and traversal, as well as advanced utilities such as reversing the list or removing items by index or value.

## Features

- Add or remove elements at the head, tail, or specific positions.
- Check for element existence and retrieve list properties.
- Reverse the list or reverse subgroups of the list.
- Memory management with proper freeing of resources.

## Installation

To use this library, include `intlist.h` in your project and link with `intlist.c`. For example:

```c
#include "intlist.h"
```

## Usage

### Data Structure

The library defines the following types:

- `node_t`: Represents a single node in the linked list.
- `list_t`: A double pointer to the head node, used to represent the list.

### Creating and Initializing a List

```c
#include "list.h"

int comparator(const int a, const int b) // Advanced usage for insertion sort
{
  return a - b; // Sorts elements in ascending order
}

int main() 
{
  node_t *head = NULL;
  list_t list = &head;

  // Add elements
  list_push(my_list, 10);
  list_append(my_list, 20);
  list_insert_sorted(my_list, 15, comparator);

  // Free resources
  list_free(my_list);
  return 0;
}
```

### Traversing and Checking the List

- **Get Head:**

  ```c
  node_t *head_node = list_head(my_list); // Returns the first element
  ```

- **Get Tail:**

  ```c
  node_t *tail_node = list_tail(my_list); // Returns the last element
  ```

- **Get Next Element:**

  ```c
  node_t *next_node = list_item_next(my_list, 10); // Returns the element that follows 10
  ```

- **Access by Index:**

  ```c
  node_t *node = list_item_index(my_list, 1);
  if (node) 
    printf("Value at index 1: %d\n", node->value);
  ```

- **Check for Existence:**

  ```c
  int exists = list_contains(my_list, 20); // Returns 1 if 20 exists, otherwise 0
  ```

- **Get Length:**

  ```c
  size_t len = list_length(my_list); // Returns the number of elements
  ```

### Adding Elements

- **Push to Head:**

  ```c
  list_push(my_list, 10); // Adds 10 to the start of the list
  ```

- **Append to Tail:**

  ```c
  list_append(my_list, 20); // Adds 20 to the end of the list
  ```

- **Insert After a Value:**

  ```c
  list_insert(my_list, 10, 15); // Inserts 15 after the first occurrence of 10
  ```

- **Insert at Index:**

  ```c
  list_insert_index(my_list, 1, 25); // Inserts 25 at index 1
  ```

### Removing Elements

- **Pop Head:**

  ```c
  node_t *removed = list_pop_head(my_list);
  ```

- **Pop Tail:**

  ```c
  node_t *removed = list_pop_tail(my_list);
  ```

- **Remove by Value:**

  ```c
  list_remove(my_list, 15); // Removes the first occurrence of 15
  ```

- **Remove All Instances of a Value:**

  ```c
  list_remove_all(my_list, 10);
  ```

- **Remove by Index:**

  ```c
  node_t *removed = list_remove_index(my_list, 2);
  ```

### Reversing the List

- **Reverse Entire List:**

  ```c
  list_reverse(my_list);
  ```

- **Reverse Groups of Elements:**

  ```c
  list_reverse_group(my_list, 3); // Reverses the list in groups of 3
  ```

### Sorted Insertion

You can insert items in a sorted manner using a custom comparator function, as described in the first example:

```c
list_insert_sorted(my_list, 30, comparator);
```

### Memory Management

Always call `list_free` to free the memory of the list when it's no longer needed:

```c
list_free(my_list);
```
