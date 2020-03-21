#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv[]){
    int tubo[2];
    time_t ini, fin;
    pipe(tubo);
    if(fork()==0){
        if(fork()==0){
            dup2(tubo[1],STDOUT_FILENO);
            close(tubo[0]);
            close(tubo[1]);
            execlp("ls","ls",NULL);
        }else{
            dup2(tubo[0],STDIN_FILENO);
            close(tubo[0]);
            close(tubo[1]);
            execlp("wc","wc","-l",NULL);
            }
    } else{
        printf("Tiempo invertido: %ld segundos\n", fin-ini);
    }
        return 0;
}