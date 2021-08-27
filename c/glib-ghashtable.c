#include <stdio.h>
#include <glib.h>


void iterator(const char *key, const char *value, int *count) {
    printf("[%d] %s: %s\n", ++(*count), key, value);
}


int main(int argc, char **argv) {
    GHashTable *squares = g_hash_table_new(g_str_hash, g_str_equal);

    g_hash_table_insert(squares, "1", "1");
    g_hash_table_insert(squares, "2", "4");
    g_hash_table_insert(squares, "3", "9");
    g_hash_table_insert(squares, "-2", "-4");

    printf("Number of key-value pairs: %d\n", g_hash_table_size(squares));

    printf("-- Squares --\n");
    int count = 0;
    g_hash_table_foreach(squares, (GHFunc) iterator, &count);

    printf("2^2 = %s\n", (char *) g_hash_table_lookup(squares, "2"));
    printf("4^2 = %s\n", (char *) g_hash_table_lookup(squares, "4"));

    printf("Removing erroneous values...\n");
    gboolean found = g_hash_table_remove(squares, "-2");
    if (found) {
        printf("Found one wrong value!\n");
    } else {
        printf("All good\n");
    }

    printf("Cleaning up...\n");
    g_hash_table_destroy(squares);
    return 0;
}
