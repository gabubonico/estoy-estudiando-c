Shell: Shell_project.o job_control.o
	gcc Shell_project.o job_control.o -o Shell

Shell_project.o: Shell_project.c
	gcc -c Shell_project.c

job_control.o: job_control.c job_control.h
	gcc -c job_control.c

clean:
	rm *.o 
