API program 1(a)

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();
    
    if (pid ==0){
        printf("child process %d and parent process %d\n",getpid(),getppid());
        execlp("ls","ls","-1",NULL);
        perror("error in execlp");
        return 1;
    }
    else if (pid > 0){
        printf("parent process %d and child process %d\n",getpid(),pid);
        int status;
        wait(&status);
        printf("child process finished");
        
    }
    else{
        perror("fork failed");
        return 1;
    }
    return 0;
}

--------------------------------------------------------------------------------------------------------------

  System calls program 1(b)

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    char buffer[50];
    fd= open("test.txt",O_RDWR | O_CREAT , 0644);
    if (fd<0){
    perror("error opening file");
    return 1;
    }
    write(fd,"Hello World!\n",14);
    
    lseek(fd,0,SEEK_SET);
    read(fd,buffer,14);
    buffer[14] = '\0';
    printf("Data read : %s",buffer);
    close(fd);
    return 0;
    
}
