#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Error: no matching command\n");
        return -1;
    }

    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0) {
        printf("Error: source file not found\n");
        return -2;
    }

    int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest < 0) {
        printf("Error: could not open/create destination file\n");
        close(fd_src);
        return -3;
    }

    char buf[100];
    int rd = 0;
    while ((rd = read(fd_src, buf, sizeof(buf))) > 0) {
        int ret = write(fd_dest, buf, rd);
        if (ret == -1) {
            printf("Error: write operation failed\n");
            close(fd_src);
            close(fd_dest);
            return -4;
        }
    }

    remove(argv[1]);
    close(fd_dest);
    return 0;
}

