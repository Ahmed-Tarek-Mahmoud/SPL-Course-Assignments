#include <stdio.h>
int main(int argc, char *argv[]) {
    int cur = 1;
    while(cur < argc){
        printf("%s" , argv[cur]);
        cur++;
        if(cur < argc) printf(" ");
    }
    printf("\n");
    return 0;
}
