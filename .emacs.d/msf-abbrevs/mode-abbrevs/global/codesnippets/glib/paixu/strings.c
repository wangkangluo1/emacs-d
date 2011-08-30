#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct { 
    char* name; 
    int shoe_size; 
} Person; 

gint my_comparator(gconstpointer item1, gconstpointer item2) {
    if(((Person*)item1)->shoe_size > ((Person*)item2)->shoe_size)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
   //  return g_ascii_strcasecmp(((Person*)item1)->name, ((Person*)item2)->name); 
}

int main(int argc, char** argv) { 
    GSList* list = NULL;
 
    Person* tom = (Person*)malloc(sizeof(Person)); 
    tom->name = "Tom"; 
    tom->shoe_size = 10; 
    list = g_slist_append(list, tom); 

    Person* fred = g_new(Person, 1); // allocate memory for one Person struct 
    fred->name = "yred"; 
    fred->shoe_size = 11; 
    list = g_slist_append(list, fred);

    Person* god = g_new(Person, 1); // allocate memory for one Person struct 
    god->name = "zod"; 
    god->shoe_size = 15; 
    list = g_slist_append(list, god);


    list = g_slist_sort(list, (GCompareFunc)my_comparator);

    printf("Tom's shoe size is '%d'\n", ((Person*)list->data)->shoe_size); 
    printf("The last Person's name is '%s'\n", ((Person*)g_slist_last(list)->data)->name); 
    g_slist_free(list); 
    free(tom); 
    g_free(fred);
    g_free(god); 
    return 0; 
} 
