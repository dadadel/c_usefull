/** 
 *  Author: A. Daouzli - Copyright 2013
 *  Licence: GPL v3
 *
 */
#include <stdlib.h>

#include "basic_list.h"

/** Initialise the list
 *
 * \desc This function will initialise the list.
 *
 */
int init_list(StorageList *l)
{
    l->first_elem = NULL;
    l->size = 0;

    return 0;
}

/** Release the list
 *
 * \desc This function will release the resources allocated to the list.
 * Note that this wont free any allocated user data stored in the list.
 *
 */
int release_list(StorageList *l)
{
    int i;
    StorageElement *p, *q;

    for(i = 0, q = p = l->first_elem ; p != NULL && i <= l->size ; i++)
    {  
        q = p;
        p = p->next;
        free(q);
    }
    l->first_elem = NULL;
    l->size = 0;

    return 0;
}

/** Release the list and user data
 *
 * \desc This function will release the resources allocated to the list and stored by the user.
 *
 */
int release_list_and_user_data(StorageList *l)
{
    int i;
    StorageElement *p, *q;

    for(i = 0, q = p = l->first_elem ; p != NULL && i <= l->size ; i++)
    {  
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }
    l->first_elem = NULL;
    l->size = 0;

    return 0;
}

/** Get an element by its index in the list.
 *
 * \desc This function will get the element corresponding to a particular index.
 *
 * \param[in] idx The index of the wanted element in the list (starts at 0)
 * 
 * \note It is not recommended to use that function in order to retrieve a lot
 * of elements as it will browse from the begining the list each time. 
 *
 * \retval NULL No element was found at that index
 * \retval The found element
 *
 */
void *get_elem_by_index(StorageList *l, int idx)
{
    int i;
    StorageElement *p;

    if (l->first_elem == NULL)
    {
        return NULL;
    }
    for (i = 0, p = l->first_elem ; p != NULL && i < idx ; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        return NULL;
    }
    return p->data;
}

/** Add an element to the list.
 *
 * \desc This function will add at the end of the list a new element.
 *
 * \param[in] data A reference to data to add to the list. 
 * The data to store must be allocated by the user as only a pointer is stored.
 *
 * \retval 0 Element was added
 * \retval < 0 There was an error
 *
 */
int add_to_list(StorageList *l, void *data)
{
    StorageElement *p, *e;
    int i;

    e = (StorageElement *)malloc(sizeof(StorageElement));
    if (e == NULL)
    {
        return -1;
    }

    e->data = data;
    e->next = NULL;

    if (l->first_elem == NULL)
    {
        l->first_elem = e;
    }
    else
    {
        for (i=0, p = l->first_elem ; p->next != NULL && i <= l->size; i++)
        {
            p = p->next;
        }
        p->next = e;
    }

    l->size++;

    return 0;
}
