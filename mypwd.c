#include <unistd.h>
#include <stdio.h>
int main() {
    char curwd[1024];
    getcwd(curwd , 1024);
    if(curwd){
        printf("%s\n" , curwd);
        return 0;
    }
    printf("error occured\n");
    return -1;
}
