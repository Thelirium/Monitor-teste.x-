#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "handle_sigusr1.h"

void handle_sigusr1(int sig){
	printf("OK\n");
}