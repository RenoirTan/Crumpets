#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * @brief Last 400 digits of Graham's number. From
 * https://brilliant.org/wiki/grahams-number/
 */
const char GRAHAM_400[] =
    "3881448314065252616878509555264605107117200099709291249544378887496062882911725063001303622934916080254594614945788714278323508292421020918258967535604308699380168924988926809951016905591995119502788717830837018340236474548882222161573228010132974509273445945043433009010969280253527518332898844615089404248265018193851562535796399618993967905496638003222348723967018485186439059104575627262464195387";

int main(int argc, char **argv) {

    mpz_t a;
    mpz_init_set_str(a, GRAHAM_400, 10);

    // 1 extra for minus sign and 1 for null terminator
    size_t a_size_b2 = mpz_sizeinbase(a, 2) + 2;
    char *a_b2 = malloc(a_size_b2);
    if (a_b2 == NULL) {
        fprintf(
            stderr,
            "Could not allocate memory to represent a string for the last 400 base-10 digits of graham's number as a base 2 number.\n"
        );
        mpz_clear(a);
        return 1;
    }
    a_b2[a_size_b2 - 1] = '\0'; // Pre-emptive null terminator
    char *a_rep_b2 = mpz_get_str(a_b2, 2, a);
    printf("%s\n", a_rep_b2);
    printf("Required bytes: %d\n", (int) a_size_b2 / 8);
    free(a_b2);

    // Current largest Mersenne prime (over 10MB) on 7/12/2018
    mpz_t b;
    mpz_init(b);
    mpz_ui_pow_ui(b, (long) 2, (long) 82589933);
    mpz_sub_ui(b, b, (long) -1);

    size_t b_size_b10 = mpz_sizeinbase(b, 10) + 2;
    char *b_b10 = malloc(b_size_b10);
    if (b_b10 == NULL) {
        fprintf(
            stderr,
            "Could not allocate memory to represent the current largest Mersenne prime.\n"
        );
        mpz_clear(a);
        mpz_clear(b);
        return 1;
    }
    b_b10[b_size_b10 - 1] = '\0';
    char *b_rep_b10 = mpz_get_str(b_b10, 10, b);
    printf("%s\n", b_rep_b10);
    printf(
        "Digits in current largest Mersenne prime: %d\n",
        (int) b_size_b10 - 2
    );
    free(b_b10);

    mpz_clear(a);
    mpz_clear(b);
    return 0;

}
