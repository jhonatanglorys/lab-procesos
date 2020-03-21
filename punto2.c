#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(void){
    int sz;
    printf("Empezando proceso padre: %d\n", getpid());
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) { 
     perror("r1"); 
     exit(1); 
  } 
    
    if(fork()==0){
        printf("Empezando el proceso hijo: %d\n", getpid());
        printf("fd = %d/n", fd);
        sz = write(fd, "Escribiendo desde el hijo\n", strlen("Escribiendo desde el hijo\n")); 

    } else {
        printf("Proceso padre\n");
        printf("fd = %d\n", fd);
        sz = write(fd, "Escribiendo desde el padre\n", strlen("Escribiendo desde el padre\n")); 
    }

    close(fd); 
    return 0;
}