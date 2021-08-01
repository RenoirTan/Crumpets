#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <argz.h>

static int parse_opt(int key, char *arg, struct argp_state *state) {
    int *arg_count = (int *) state->input;
    switch (key) {
        case 'd': {
            unsigned int total = atoi(arg);
            unsigned int i = 0;
            for (; i < total; ++i) {
                printf(".");
            }
            printf("\n");
            break;
        }
        case 777:
            return parse_opt((int) 'd', "3", state);
        case 888:
            printf("-");
            break;
        case ARGP_KEY_ARG:
            if (++(*arg_count) > 4) {
                argp_failure(state, 1, 0, "too many arguments");
            } else {
                printf("%s ", arg);
            }
            break;
        case ARGP_KEY_END:
            printf("\n");
            break;
        /*
        default:
            fprintf(stderr, "Unknown flag: %c\n", (char) key);
            break;
        */
    }
    return 0;
}

int main(int argc, char **argv) {
    struct argp_option options[] = {
        {"dot", 'd', "NUM", OPTION_ARG_OPTIONAL, "Show some dots on the screen"},
        {"ellipsis", 777, 0, OPTION_HIDDEN, "Show an ellipsis on the screen"},
        {"dash", 888, 0, 0, "Show a dash on the screen"},
        {0}
    };
    int arg_count = 0;
    struct argp argp = {options, parse_opt, "[WORD [WORD [WORD [WORD]]]]", 0};
    return argp_parse(&argp, argc, argv, 0, 0, &arg_count);
}
