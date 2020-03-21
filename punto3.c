#include <stdio.h>
#include <unistd.h>


int main(void){
    printf("Empezando proceso padre: %d\n", getpid());
    if(fork()==0){
        printf("Empezando proceso hijo: %d\n", getpid());
        printf("Hello\n");
    } else {
        sleep(1);
        printf("Goodbye\n");
    }
    return 0;
}