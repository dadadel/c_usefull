/** 
 *  Author: A. Daouzli - Copyright 2013
 *  Licence: GPL v3
 *
 */

#ifndef BASIC_LIST_H
#define BASIC_LIST_H

/** An element of the list*/
typedef struct _StorageElement
{
	int size; /**< Size of the stored data */
    void *data; /**< The element data */
    struct _StorageElement *next;
} StorageElement;

/** The list container */
typedef struct _StorageList
{
    int size; /** Number of elements in the list */
    StorageElement *first_elem; /** First element of the chained list */
} StorageList;

int init_list(StorageList *l);
int release_list(StorageList *l);
int release_list_and_user_data(StorageList *l);
void *get_elem_by_index(StorageList *l, int idx);
int add_to_list(StorageList *l, void *data);

#endif /* BASIC_LIST_H */
