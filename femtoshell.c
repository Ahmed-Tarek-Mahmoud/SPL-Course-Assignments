#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 100024

int main(int argc, char *argv[]) {
    char input[MAX_INPUT];
    while(1){
        printf("FemtoShell > ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit if error
        }
        
        input[strcspn(input, "\n")] = 0;
        
        // empty command
        if (strlen(input) == 0) {
            continue;
        }
        // compare first n bytes
        if (strncmp(input, "echo ", 5) == 0) {
            printf("%s\n", input + 5);
        }
        
        else if (strncmp(input, "exit" , 4) == 0) {
            printf("Good Bye\n");
            break;
        }
        // Invalid command
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
