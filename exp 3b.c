#include <stdio.h>
#include <stdlib.h>

int mutex = 1,rw_mutex = 1,readcount=0;

int wait(int s){
    return --s;
}

int signal(int s){
    return ++s;}

int reader(){
    mutex = wait(mutex);
    rw_mutex++;
    if(readcount==1){
        rw_mutex = wait(rw_mutex);
    }
    printf("reader is reading\n");
    mutex = wait(mutex);
    rw_mutex--;
    if(readcount==0){
        rw_mutex = signal(rw_mutex);
    }
    
}

int writer(){
    mutex = wait(mutex);
    printf("writer is writting\n");
    mutex = signal(mutex);
}

int main(){
    int ch;
    printf(" 1.Reader\n 2.Writer\n 3.Exit\n");
    
    while(1){
        printf("enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                reader();
                break;
            case 2:
                writer();
                break;
            case 3:
                exit(0);
                
                
        }
    }
    
    return 0;
}
