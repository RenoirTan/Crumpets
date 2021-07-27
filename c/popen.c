#include <stdio.h>

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
#   define popen _popen
#   define pclose _pclose
#endif

#define MAXCOMMANDLEN 2048

int win32find(const char *filename) {
    char command[MAXCOMMANDLEN] = "";
    int len = sprintf(command, "where.exe %s", filename);
    if (len >= MAXCOMMANDLEN) {
        printf("Command length exceeded max.\n");
        return 1;
    } else {
        printf("Command being used: %s\n", command);
    }
    FILE *process = popen(command, "r");
    char chr;
    if (process == NULL) {
        printf("Could not open process.\n");
        return 1;
    }
    while ((chr = fgetc(process)) != EOF) {
        putchar(chr);
        if (chr == '\n') {
            break;
        }
    }
    return pclose(process);
}

int unixfind(const char *filename) {
    char command[MAXCOMMANDLEN] = "";
    int len = sprintf(command, "whereis %s", filename);
    if (len >= MAXCOMMANDLEN) {
        printf("Command length exceeded max.\n");
        return 1;
    } else {
        printf("Command being used: %s\n", command);
    }
    FILE *process = popen(command, "r");
    char chr;
    if (process == NULL) {
        printf("Could not open process.\n");
        return 1;
    }
    while ((chr = fgetc(process)) != EOF) {
        putchar(chr);
        if (chr == '\n') {
            break;
        }
    }
    return pclose(process);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Must provide at least one argument.\n");
        return 1;
    }
#if defined(_WIN32) || defined(_WIN64)
    return win32find(argv[1]);
#elif defined(unix) || defined(__unix__) || defined(__unix)
    return unixfind(argv[1]);
#else
    printf("Not compatible with your OS yet.");
    return 1;
#endif
}
