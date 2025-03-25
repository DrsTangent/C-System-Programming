#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t child;
    int status;

    std::cout << "I am the parent, my PID is " << getpid() << std::endl;
    std::cout << "My parent's PID is " << getppid() << std::endl;
    std::cout << "I am going to create a new process..." <<std::endl;

    //creating child processes until it throws error;
    child = fork();
    std::cout << "place of fork"<<std::endl;
    if(child == -1){
        std::cout << "error occurred creating the child process" << std::endl;
    }
    else if (child == 0){
        std::cout << "child process created" << std::endl;
        sleep(2);
        //If excel executes successfully, program will be replaced.. so this won't run further
        if(execl("/usr/bin/ls", "ls", "-l", NULL)<0){
            std::cout << "execl() failed" << std::endl;
        }
        std::cout << "child process id: " << getpid() << " with parent process of " << getppid() << std::endl;
    }
    else{
        //wait for child to finish, else it will become a zombie process//        
        wait(&status);
        std:: cout << "value of status: " << status << std::endl;
        std::cout << "child variable value: " << child<<std::endl;
        std::cout <<"finishing parent process"<<std::endl;
    }

    std::cout << "process is ending here"<<std::endl;
    return 0;
}