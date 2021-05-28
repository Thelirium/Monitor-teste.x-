#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "handle_sigusr1.h"

int main(){
	int id = fork();
	int fd = -1;

	/*Processo A*/
	if(id == 0){
		while(fd == -1){
			fd = access("/home/clailton/TP_Cod/dir_teste/teste.x", F_OK);
			if(fd != -1){
				kill(getppid(), SIGUSR1);
			}
		}
	}
	/*Processo B*/
	else{
		/*Definição do SIGUSR1*/
		struct sigaction sa = {0};
		/*Após realizar a tarefa, reinicia o que estava sendo
		executado*/
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		/*Aguardar filho encerrar*/
		wait(NULL);
	}
	return 0;
}