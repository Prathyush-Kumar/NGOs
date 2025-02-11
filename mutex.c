#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;
int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
int choice;
printf("\n1. Producer \n2. Consumer \n3. Exit");

while (1) {
printf("\nENTER A CHOICE: ");
scanf("%d", &choice);

switch (choice) {
case 1:
if ((mutex == 1) && (empty != 0)) {
producer();
} else {
printf("Buffer is full!\n");
}
break;
case 2:
if ((mutex == 1) && (full != 0)) {
consumer();
} else {
printf("Buffer is empty\n");
}
break;
case 3:
exit(0);
break;
default:
printf("Invalid choice! Please enter 1, 2 or 3.\n");
}
}
return 0;
}

int wait(int s) {
return (--s);
}

int signal(int s) {
return (++s);
}

void producer() {
mutex = wait(mutex);
full = signal(full);
empty = wait(empty);
x++;
printf("\nProducer produces the item %d\n", x);
mutex = signal(mutex);
}

void consumer() {
mutex = wait(mutex);
full = wait(full);
empty = signal(empty);
printf("\nConsumer consumes the item %d\n", x);
x--;
mutex = signal(mutex);
}

