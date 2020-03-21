#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(void){
    pid_t pid;
    int fin = 2;
    printf("Iniciando proceso padre: %d\n", getpid());
    if((pid = fork())){
        printf("Iniciando el proceso hijo: %d\n", getpid());
        fin = fin + 3;
        for (int i=0; i<fin; i++){
            printf("i = %d\n", i);
            sleep(1);
        }
        
    } else {
        for(int i=0; i<fin; i++){
            printf("i = %d\n", i);
            sleep(1);
        }
        int stat_val;
        waitpid(pid, &stat_val, 0);
        if(WIFEXITED(stat_val)){
            printf("Proceso hijo terminado con código %d\n",WEXITSTATUS(stat_val));
        } else {
            printf("Proceso hijo terminado anormalmente, signal %d\n", WTERMSIG(stat_val));

        }
    }
    printf("Finalizando proceso :%d\n", getpid());
    return 0;
}