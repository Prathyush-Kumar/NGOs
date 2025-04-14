#include <stdio.h>
#include <stdlib.h>
#define N 5

int wait(int s){
    return --s;
}

int signal(int s){
    return ++s;
}

int state[N];
int semaphore[N];
int mutex = 1;

void test(int i){
    if (state[i] == 1 && state[(i+1)%5] != 2 && state[(i+4)%5] != 2){
        state[i] = 2;
        semaphore[i] = 0;
        printf("philosopher starts eating!\n");
    }    
}

void take_fork(int i){
    mutex = wait(mutex);
    
    state[i] = 1;
    test(i);
    
    if (state[i] == 2){
    printf("philosopher is ready to take forks\n");
}
    mutex = signal(mutex);
}


void put_forks(int i){
    state[i] = 0;
    printf("philosopher is thinking\n");
    
    test((i+4)%5);
    test((i+1)%5);
    
    mutex = signal(mutex);
}


int main(){
    int ch,phil;
    
    for(int i=0;i<N;i++){
        state[i] = 0;
        semaphore[i] = 1;

    }
    
    
    
    while(1){
        printf("enter choice 1. take fork  2. put firk  3. exit\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("enter a philosoher 1-5: ");
                scanf("%d",&phil);
                
                take_fork(phil-1);
                break;
                
            case 2:
                printf("enter a philosoher 1-5: ");
                scanf("%d",&phil);
                
                put_forks(phil-1);
                break;
                
            case 3:
                exit(0);
        }
        
        
    }
    return 0;
}
