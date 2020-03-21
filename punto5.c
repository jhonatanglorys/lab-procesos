#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void){
    int estado;
    int fin = 2;
    printf("Iniciando proceso padre: %d\n", getpid());
    if(fork()){
        printf("Iniciando el proceso hijo: %d\n", getpid());
        fin = fin + 3;
        for (int i=0; i<fin; i++){
            printf("i = %d\n", i);
            sleep(1);
        }
        int pid_h_espera = wait(&estado);
        if(pid_h_espera==0){
            printf("Proceso hijo ha terminado\n");
        } else {
            printf("Esperando terminación proceso hijo\n");
        }
    } else {
        for(int i=0; i<fin; i++){
            printf("i = %d\n", i);
            sleep(1);
        }
        
        
    }
    printf("Finalizando proceso :%d\n", getpid());
    return 0;
}