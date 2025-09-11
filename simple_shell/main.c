#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char prompt[12];
int alphanumeric(int);

int main() {
	// my shell coded here
	
	pid_t k;
	int status; 
	int index = 0;
	int command = 0;
	char buff[100];

	while (1) {
		// prompt
		printf("myshell %% ");
		index = index + 1;
		
		command = 0;
		int startptr;

		char buff2[100];
		char argue[100];

		// get command
		scanf("%s",buff);
		if (*buff == 'e' && *(buff+1) == '\0') {
			// the first build in command
			exit(0);
		} else if (*buff == 'c') {
			// the second built in command
			command = 2;
			scanf(" %99s", buff2);
		} else if (*buff == 'l' && *(buff+1) == '\0') {
		       command = 3;	
		} else if (*buff == 'L' && *(buff + 1) == '\0') {
			command = 4;
		} else if (*buff == 'j' && *(buff + 1) == '\0') {
			command = 5;
		} else if (*buff == '\0') {
			//printf("no command\n");
			continue;
		} else {
			command = 6;
			fgets(argue, 100, stdin);
			int length = strlen(argue);

		}
		//printf("buff and buff2: %s %s\n", buff, buff2);
		
		// forking
		k = fork();
		if (k == 0) {
			if (command == 2) {
				int newline = 0;
				if (strlen(buff2) > 11) {
					printf("string too long \n");
					//char temp[50];
					//fscanf(stdin, " %s", temp);
					exit(1);
				}
                	        for (int i=0; i<strlen(buff2); i++) {
                        	        // check and copy
					int intchar = (int)(*(buff2+i));
                                	if (*(buff2+i) == '\0') {
                                        	if (i == 0) {
                                                	printf("empty string\n");
                                                	exit(1);
                                                	
                                        	} else {
                                                	newline = 1;
                                        	}
                                	} else if (alphanumeric(intchar) == -1) {
                                        	printf("invalid character \n");
                                        	char temp[50];
						fscanf(stdin, " %s", temp);
						exit(1);
                                	} else {
                                        	// business as usual
                                	}
                        	}
				//printf("out of the for loop \n");
				strcpy(prompt, buff2);
				printf("prompt: %s\n", prompt);
				exit(1);
			} else if (command == 3) {
				char *args[] = {"ls",NULL};
				execvp("ls", args);
				exit(1);
			} else if (command == 4) {
				char *args[3];
				args[0] = "ls";
				args[1] = "-l";
				args[2] = NULL;
				execvp("ls", args);
				exit(1);
			} else if (command == 5) {
				char *args[3];
				args[0] = "cat";
				args[1] = "joke.dat";
				args[2] = NULL;
				execvp("cat", args);
				exit(1);
			} else if (command == 6) {
				if (strlen(argue) == 1) {
					// no extra arguments 
					char *args[] = {buff, NULL};
					execvp(args[0], args);
					exit(1);
				} else {
					// count the number of arguments
					int num = 0;
					//printf("here\n");
					for (int i = 0; i<strlen(argue); i++) {
						if (*(argue+i) == ' ') {
							num = num + 1;
						}
					}
					//allocate space for arguments in 2d array
					char **args;
					int bob = 1;
					int arglen, starting;
					args = (char **)malloc((num+2)*sizeof(char *));
					args[0] = (char *)malloc(strlen(buff)*sizeof(char));
					args[0] = buff;
					//printf("num of arguments %d\n", num);
					for (int i=0; i<num; i++) {
						arglen = 0;
						starting = bob;
						while (*(argue+bob) != ' ' && *(argue+bob) != '\0' && *(argue+bob)!= '\n') {
							arglen = arglen+1;
							bob = bob+1;
						}
						bob = bob + 1;
						*(args+i+1) = (char *)malloc(arglen*sizeof(char));
						for (int j=0;j<arglen;j++) {
							*(*(args+i+1)+j) = *(argue+starting+j);
						//	printf("%c\n", *(argue+starting+j));
						}
						//printf("argument and arglen %s %d\n", args[i+1], arglen);

					}
					args[num+1] = NULL;
					execvp(buff, args);
					exit(1);
				}				
				//execvp(buff, args);
				printf("invalid command\n");
				exit(1);
			} else if (command == -1) {
				exit(1);
			} else {
				// shouldn't be here print error and quit
				printf("something's wrong ... try again \n");
				exit(1);
			}
			// kill the children in case something went wrong 
			// go back to the parent
			exit(1);
		} else {
			sleep(2);
		}
		//printf("\n");

	}
}



// check if the characters are valid 
int alphanumeric(int a) {
	if (a>=48 && a<=58) {
		return 1;
	} else if (a>=65 && a<=90) {
		return 1;
	} else if (a>=97 && a<=122) {
		return 1;
	} else if (a == 62 || a == 64 || a == 36 || a == 37) {
		return 1;
	} else {
		return -1;
	}
}
