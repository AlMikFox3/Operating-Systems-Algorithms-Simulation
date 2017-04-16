#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 1024

int main(){
    char command[BUF_LEN];  
    char* argv[100];        
    char* path= "/bin/";    
    char ppath[20];                
while(1){

    printf("ush> ");                    
	if(!fgets(command, BUF_LEN, stdin)){  
        break;                               
    }
	size_t length = strlen(command);
	if (command[length - 1] == '\n')
    	command[length - 1] = '\0';
        if(strcmp(command, "exit\0")==0){           
        break;
    }
    char *token;                 
    token = strtok(command," ");
    int i=0;
    while(token!=NULL){
        argv[i]=token;      
        token = strtok(NULL," ");
        i++;
    }
    argv[i]=NULL;                     
    strcpy(ppath, path);           
    strcat(ppath, argv[0]);            
    for(i=0; i<strlen(ppath); i++){    
        if(ppath[i]=='\n'){      
            ppath[i]='\0';
        }
    }
    int pid= fork();              
    if(pid==0){               
        execvp(ppath,argv);
        fprintf(stderr, "Child process could not do execvp\n");
    }else{                   
        wait(NULL);
        //printf("Child exited\n");
    }
}
} 
