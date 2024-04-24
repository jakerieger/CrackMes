// Author: Jake Rieger
// Created: 4/24/24.
//

#include <stdio.h>
#include <stdlib.h>

#define __entry int main
#define __args int argc, char *argv[]
#define SHELL_LEN 38
#define CHECK_BIT(x, n) ((x) & (1 << (n)))

static char chunk_one[8]   = {0x60, 0x66, 0x6d, 0x6a, 0x25, 0x27, 0x46, 0x6a};
static char chunk_two[8]   = {0x6b, 0x62, 0x77, 0x64, 0x71, 0x76, 0x24, 0x25};
static char chunk_three[8] = {0x59, 0x6f, 0x75, 0x76, 0x65, 0x20, 0x66, 0x6f};
static char chunk_four[8]  = {0x70, 0x6b, 0x61, 0x25, 0x71, 0x6d, 0x60, 0x25};
static char chunk_five[8]  = {0x66, 0x6c, 0x61, 0x67, 0x2e, 0x22, '\0', '\0'};
static char* chunks[5]     = {chunk_one, chunk_two, chunk_three, chunk_four, chunk_five};

__entry(__args) {
    int bitmask = 0b010100;
    if (argc == 2) {
        bitmask = atoi(argv[1]);
    }

    for (int i = 0; i < 5; i++) {
        if (CHECK_BIT(bitmask, i)) {
            for (int j = 0; j < 8; j++) {
                chunks[i][j] = chunks[i][j] ^ 5;
            }
        }
    }

    char shell[SHELL_LEN + 1] = {'\0'};
    snprintf(shell,
             SHELL_LEN + 1,
             "%s%s%s%s%s",
             chunk_one,
             chunk_two,
             chunk_three,
             chunk_four,
             chunk_five);
    char cmd[80] = {'\0'};
    snprintf(cmd, 80, "sh -c '%s' 2>/dev/null", shell);
    if (system(cmd) != 0) {
        puts("Incorrect.");
    }

    return 0;
}