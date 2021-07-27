#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(MS_WINDOWS) || defined(__CYGWIN__)
#   define DLL_PATH "./libinjected-module.dll"
#else
#   define DLL_PATH "./libinjected-module.so"
#endif
#define HYPOTHENUSE "hypothenuse"

typedef void* shared_lib_t;
typedef double (*fd_dd_t)(double, double);

int run(int argc, char **argv) {
    shared_lib_t module = dlopen(DLL_PATH, RTLD_LAZY);
    if (module == NULL) {
        printf("Could not load module.\n");
        goto cleanup;
    } else {
        printf("Module loaded successfully at %p\n", module);
    }

    fd_dd_t hypothenuse = dlsym(module, HYPOTHENUSE);
    if (module == NULL) {
        printf("Could not load hypothenuse.\n");
        goto cleanup;
    } else {
        printf("hypothenuse retrieved at %p\n", hypothenuse);
    }

    double a = 6.0, b = 8.0;
    double c = hypothenuse(a, b);
    printf("Hypothenuse of %lf and %lf is %lf\n", a, b, c);

    goto cleanup;

cleanup:
    if (module != NULL)
        return dlclose(module);
    else
        return 1;
}

int main(int argc, char **argv) {
    if (run(argc, argv)) {
        char *error = dlerror();
        if (error == NULL) {
            printf("An error occurred.\n");
        } else {
            printf("An error occurred: %s\n", error);
        }
        return 1;
    } else {
        printf("Success!\n");
        return 0;
    }
}
