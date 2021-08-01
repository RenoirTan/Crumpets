#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


typedef struct _person_t {
    char *name;
    int32_t age;
} person_t;

person_t *person_new(const char *name, int32_t age) {
    person_t *person = g_new(person_t, 1);
    person->name = name;
    person->age = age;
    return person;
}

int main(int argc, char **argv) {
    GSList *list = NULL;
    person_t *person_1 = person_new("A", 50);
    person_t *person_2 = person_new("B", 50);
    person_t *person_3 = person_new("C", 50);
    list = g_slist_append(list, person_1);
    list = g_slist_append(list, person_2);
    list = g_slist_append(list, person_3);
    person_t *arbitrary = NULL;
    arbitrary = g_slist_nth_data(list, 1);
    printf(
        "person_t { name = %s, age = %d }\n",
        arbitrary->name,
        arbitrary->age
    );
    g_slist_free(list);
    g_free(person_1);
    g_free(person_2);
    g_free(person_3);
    return 0;
}