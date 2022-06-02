/**
UNIX Shell Project

Sistemas Operativos
Grados I. Informatica, Computadores & Software
Dept. Arquitectura de Computadores - UMA

Some code adapted from "Fundamentos de Sistemas Operativos", Silberschatz et al.

To compile and run the program:
   $ gcc Shell_project.c job_control.c -o Shell
   $ ./Shell          
	(then type ^D to exit program)

**/

#include "job_control.h"   // remember to compile with module job_control.c 
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 256 /* 256 chars per line, per command, should be enough. */

job * tareas;

void manejador (int senal) {
	job * item;
	int status;
	int info;
	int pid_wait = 0;
	enum status status_res;

	for (int i = 1; i <= list_size(tareas); i++) {
		item = get_item_bypos(tareas, i);			
		pid_wait = waitpid(item->pgid, &status, WUNTRACED | WNOHANG | WCONTINUED);
		if (pid_wait == item->pgid) {
			status_res = analyze_status(status, &info);
			if (status_res == EXITED) {
				printf("\ncommand %s executed background. Pid %d finished", item->command, item->pgid);		
				delete_job(tareas, item);
			} else if (status_res == SUSPENDED) {
				printf("\ncommand %s executed background. Pid %d suspended", item->command, item->pgid);		
				item->state = STOPPED;	
			}	
		}
	}
}

// -----------------------------------------------------------------------
//                            MAIN          
// -----------------------------------------------------------------------

int main(void)
{
	char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */
	int background;             /* equals 1 if a command is followed by '&' */
	char *args[MAX_LINE/2];     /* command line (of 256) has max of 128 arguments */
	// probably useful variables:
	int pid_fork, pid_wait; /* pid for created and waited process */
	int status;             /* status returned by wait */
	enum status status_res; /* status processed by analyze_status() */
	int info;				/* info processed by analyze_status() */

	job * item;

	ignore_terminal_signals();
	signal(SIGCHLD, manejador);
	tareas = new_list("tareas");

	while (1)   /* Program terminates normally inside get_command() after ^D is typed*/
	{   		
		printf("[gash]$ ");
		fflush(stdout);
		get_command(inputBuffer, MAX_LINE, args, &background);  /* get next command */
		
		if(args[0]==NULL) continue;   // if empty command

		/* the steps are:
			 (1) fork a child process using fork()
			 (2) the child process will invoke execvp()
			 (3) if background == 0, the parent will wait, otherwise continue 
			 (4) Shell shows a status message for processed command 
			 (5) loop returns to get_commnad() function
		*/

		if(!strcmp(args[0], "cd")) {
			chdir(args [1]);
			continue;
		}
		if(!strcmp(args[0], "JOBS")) {
			print_job_list(tareas);
			continue;
		}

		pid_fork = fork();
		if (pid_fork > 0) { //padre
			if (background == 0) {
				waitpid(pid_fork, &status, WUNTRACED);
				set_terminal(getpid());
				status_res = analyze_status(status, &info);
				if (status_res == SUSPENDED) {
					item = new_job(pid_fork, args[0], STOPPED);
					add_job(tareas, item);
					printf("\nForeground pid: %i, command: %s, %s, info: %i\n", pid_fork, args[0], status_strings[status_res], info);
				} else {
					printf("\nForeground pid: %i, command: %s, %s, info: %i\n", pid_fork, args[0], status_strings[status_res], info);
				}
			} else {
				item = new_job(pid_fork, args[0], STOPPED);
				add_job(tareas, item);
				printf("\nBackground pid: %i, command: %s\n", pid_fork, args[0]);
				continue;
			}	
		} else { //hijo
			new_process_group(getpid()); 
			if (background == 0) set_terminal(getpid());
			restore_terminal_signals();
			execvp(inputBuffer, args);
			printf("Error, command %s not found", args[0]);
			exit(-1);
		}

	} // end while
}
