#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=3,item=0;

int wait(int s){
    return --s;
}

int signal(int s){
    return ++s;
}

int producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    item++;
    printf("produced item: %d\n",item);
    mutex=signal(mutex);
}

int consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    item--;
    printf("consumed item: %d\n",item);
    mutex=signal(mutex);
}

int main(){
    int ch;
    printf(" 1.Producer\n 2.Consumer\n 3.Exit\n");
    
    while(1){
        printf("enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                if(mutex==1 && empty>0){
                    producer();
                }
                else{
                    printf("buffer is full!\n");
                }
                break;
            case 2:
                if(mutex==1 && full>0){
                    consumer();
                }
                else{
                    printf("buffer is empty!\n");
                }
                break;
            case 3:
                exit(0);
                
                
        }
    }
    
    return 0;
}
