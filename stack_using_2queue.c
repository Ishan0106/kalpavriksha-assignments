/*
#include <stdio.h>
#define MAX 5   
// Declare two queues
int queue1[MAX];
int queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;


int isFull(int queueNumber) {
    if (queueNumber == 1) {
        return (rear1 + 1) % MAX == front1;
    } else {
        return (rear2 + 1) % MAX == front2;
    }
}

int isEmpty(int queueNumber) {
    if (queueNumber == 1) {
        return front1 == -1;
    } else {
        return front2 == -1;
    }
}


void peek(int queueNumber) {
    if (isEmpty(queueNumber)) {
        printf("Queue %d is empty. Cannot peek.\n", queueNumber);
    } else {
        if (queueNumber == 1) {
            printf("Queue 1 Peek: %d\n", queue1[front1]);
        } else {
            printf("Queue 2 Peek: %d\n", queue2[front2]);
        }
    }
}


void enqueue(int queueNumber, int value) {
    if (isFull(queueNumber)) {
        printf("Queue %d is full. Cannot enqueue %d\n", queueNumber, value);
        return;
    }

    if (queueNumber == 1) {
        if (front1 == -1) {
            front1 = 0;  
        }
        rear1 = (rear1 + 1) % MAX;  
        queue1[rear1] = value;
        printf("Enqueued %d to Queue 1\n", value);
    } else {
        if (front2 == -1) {
            front2 = 0; 
        }
        rear2 = (rear2 + 1) % MAX;  
        queue2[rear2] = value;
        printf("Enqueued %d to Queue 2\n", value);
    }
}

int dequeue(int queueNumber) {
    if (isEmpty(queueNumber)) {
        printf("Queue %d is empty. Cannot dequeue.\n", queueNumber);
        return -1;
    }

    int dequeuedValue;
    if (queueNumber == 1) {
        dequeuedValue = queue1[front1];
        if (front1 == rear1) { 
            front1 = rear1 = -1;  
        } else {
            front1 = (front1 + 1) % MAX;  
        }
        printf("Dequeued %d from Queue 1\n", dequeuedValue);
    } else {
        dequeuedValue = queue2[front2];
        if (front2 == rear2) { 
            front2 = rear2 = -1; 
        } else {
            front2 = (front2 + 1) % MAX;  
        }
        printf("Dequeued %d from Queue 2\n", dequeuedValue);
    }
    return dequeuedValue;
}


void display() {
    int queueNumber =1;
    if (isEmpty(queueNumber)) {
        printf("Queue %d is empty.\n", queueNumber);
        return;
    }

    printf("Queue %d: ", queueNumber);
    int i;
     i = front1;
        while (i != rear1) {
            printf("%d ", queue1[i]);
            i = (i + 1) % MAX; 
        }
        printf("%d\n", queue1[rear1]); 
}


void push(int ele)
{

     if (isFull(1)) {
        printf("Queue 1 is full. Cannot enqueue %d\n",ele);
        return;
    }
     if (front1 == -1) {
           enqueue(1,ele); 
        }

        else{

while(!isEmpty(1))
{
    int value= dequeue(1);
    enqueue(2,value);
}
enqueue(1,ele);
while(!isEmpty(2))
{
    int value= dequeue(2);
    enqueue(1,value);
}
        }
}

void size()
{
    int count=0;
    for(int i= front1; i<=rear1; i++)
    {
        count++;
    }
    printf("%d\n",count);
}
int main() {
    printf("Queue operations\nEnter operations\n");
    int c, queueChoice;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5.size\n");

    while (1) {
        printf("\nEnter operation (1-4): ");
        scanf("%d", &c);
        queueChoice=1;
        if (c == 1) {

            printf("Enter element to push: ");
            int ele;
            scanf("%d", &ele);
            push(ele);
        }
        else if (c == 2) {

            dequeue(queueChoice);
        }
        else if (c == 3) {

            peek(queueChoice);
        }
        else if (c == 4) {

            display();
        }
        else if(c==5)
{
    size();
}
        else {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }
    return 0;
}

*/

#include <stdio.h>
#define MAX 5   

typedef struct {
    int queue[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}


int isEmpty(Queue* q) {
    return q->front == -1;
}


void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;  
    }
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = q->queue[q->front];
    if (q->front == q->rear) { 
        q->front = q->rear = -1;  
    } else {
        q->front = (q->front + 1) % MAX;  
    }
    return dequeuedValue;
}

void peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
    } else {
        printf("Peek: %d\n", q->queue[q->front]);
    }
}


void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->queue[q->rear]); 
}

void push(Queue* q1, Queue* q2, int ele) {
    enqueue(q1, ele);
    
    // Transfer all elements from queue1 to queue2
    while (!isEmpty(q1)) {
        int value = dequeue(q1);
        enqueue(q2, value);
    }

    // Transfer all elements back from queue2 to queue1
    while (!isEmpty(q2)) {
        int value = dequeue(q2);
        enqueue(q1, value);
    }
}

// Function to get the size of the stack (queue1)
int size(Queue* q1) {
    int count = 0;
    int i = q1->front;
    while (i != q1->rear) {
        count++;
        i = (i + 1) % MAX;
    }
    count++;  // For the last element
    printf("Stack size: %d\n", count);
    return count;
}

int main() {
    Queue q1, q2;
    initQueue(&q1);  // First queue (for stack)
    initQueue(&q2);  // Second queue (temporary)

    printf("Stack operations using two queues\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Size\n");

    int choice;
    while (1) {
        printf("\nEnter operation (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int ele;
            printf("Enter element to push: ");
            scanf("%d", &ele);
            push(&q1, &q2, ele);
        } else if (choice == 2) {
            if (!isEmpty(&q1)) {
                int poppedValue = dequeue(&q1);
                printf("Popped: %d\n", poppedValue);
            } else {
                printf("Stack is empty. Cannot pop.\n");
            }
        } else if (choice == 3) {
            peek(&q1);
        } else if (choice == 4) {
            display(&q1);
        } else if (choice == 5) {
            size(&q1);
        } else {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
