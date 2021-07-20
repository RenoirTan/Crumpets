#include <stdio.h>

int main(int argc, char **argv) {
    fclose(stdout);
    fclose(stdin);
    fclose(stderr);
    return 0;
}
