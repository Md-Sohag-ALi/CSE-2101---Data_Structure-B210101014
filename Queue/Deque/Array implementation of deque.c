#include <stdio.h>
#include <stdlib.h>
#define size 100

int front = -1;
int rear = -1;
int deque[size];

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}

void enqueueFront(int data) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        exit(1);
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }

    deque[front] = data;
    printf("OK\n");
}

void enqueueRear(int data) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        exit(1);
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = data;
    printf("OK\n");
}

int dequeFront() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        exit(1);
    }

    int data = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }

    return data;
}

int dequeRear() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        exit(1);
    }

    int data = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }

    return data;
}

void printFirstElement() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
    } else {
        printf("First element: %d\n", deque[front]);
    }
}

void printAllElements() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i++;
        if (i == size) i = 0;
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.Print the first element\n");
        printf("6.Print all the elements\n");
        printf("7.Quit\n");
        int choice, data;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter an element to be insert in the front end of deque\n");
            scanf("%d", &data);
            enqueueFront(data);
            break;
        case 2:
            printf("Enter an element to be insert in the rear end of deque\n");
            scanf("%d", &data);
            enqueueRear(data);
            break;
        case 3:
            data = dequeFront();
            printf("The deleted element from front end is %d\n", data);
            break;
        case 4:
            data = dequeRear();
            printf("The deleted element from rear end is %d\n", data);
            break;
        case 5:
            printFirstElement();
            break;
        case 6:
            printAllElements();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
