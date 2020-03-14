#include <stdio.h>
#include <unistd.h>

int main(void){
    int x= 100;
    printf("Empezando proceso padre: %d\n", getpid());
    
    if(fork()==0){
        printf("Empezando proceso hijo: %d\n", getpid());
        printf("El valor de X en el proceso hijo es: %d\n", x);
    } else {
        printf("El valor de X en el proceso padre es: %d\n", x);
    }
    printf("Finalizando proceso %d\n", getpid());
    return 0;
}