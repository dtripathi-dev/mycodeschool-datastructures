#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* HEAD = NULL;

void traverse();
void addAtTheStart(int item);
void addAtTheEnd(int item);
void addAtPosition(int item, int position);

int main () {

    int data;
    
    int stop = 0;
    int methodId;
    int item = NULL;
    int pos = NULL;
    
    while (!stop) {

        printf("\n0. EXIT\n");
        printf("1. INSERT AT HEAD\n");
        printf("2. INSERT AT TAIL\n");
        printf("3. INSERT AT LOCATION\n");
        printf("ANY OTHER NUMBER TO TRAVERSE ITERATIVE\n");
        printf("What operations you want to perform?\n");
        
        scanf("%d", &methodId);
        
        switch (methodId) {
            
            case 0:

                stop = 1;
                break;

            case 1:
                
                printf("Enter a number\n");
                scanf("%d", &item);
                addAtTheStart(item);
                
                break;
            
            case 2:
                
                printf("Enter a number\n");
                scanf("%d", &item);
                addAtTheEnd(item);
                
                break;
            
            case 3:
                
                printf("Enter a number & position\n");
                scanf("%d%d", &item, &pos);
                addAtPosition(item, pos);
                
                break;

            default:
                
                traverse(); 
        }

    }
    
}

void addAtPosition(int item, int position) {

    printf("\nAdding item %d at position %d\n", item, position);

    //allocate memory
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    
    node->data = item;

    //empty list, ignore index
    if (HEAD == NULL) {

        node->prev = NULL;
        node->next = NULL;

        HEAD = node;

        return;

    }

    //enter at the start
    if (position == 0) {

        node->prev = NULL;
        node->next = HEAD;
        
        HEAD->prev = node;
        
        HEAD = node;

        return;

    }

    struct Node* nodeAtPos = HEAD;
    int nodePos = 0;

    while (nodeAtPos->next != NULL && nodePos < position) {

        nodeAtPos = nodeAtPos->next;
        nodePos++;

    }

    //enter at the end
    if (nodePos < position) {

        node->next = NULL;
        node->prev = nodeAtPos;

        nodeAtPos->next = node;

        return;
    }

    //in middle of the list
    nodeAtPos->prev->next = node;
    node->prev = nodeAtPos->prev;
    node->next = nodeAtPos;
    nodeAtPos->prev = node;

}

void addAtTheEnd(int item) {

    printf("\nAdding at the end %d\n", item);

    //allocate memory
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    
    node->data = item;
    node->next = NULL;
    
    struct Node* lastNode = HEAD;

    while (lastNode != NULL && lastNode->next != NULL) {

        lastNode = lastNode->next;

    }

    node->prev = lastNode;
    
    //lastNode will only be NULL in case of empty list
    if (lastNode == NULL) {

        HEAD = node;

    } else {

        lastNode->next = node;
    }

}

void addAtTheStart(int item) {

    printf("Adding at the start %d\n", item);

    //allocate memory
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    
    node->data = item;
    
    //always going to be the 1st node
    node->prev = NULL;
    
    //current node will come after the new one 
    node->next = HEAD;
    
    if (HEAD != NULL) {

        HEAD->prev = node;

    }

    HEAD = node;

}

void traverse() {

    printf("\n\nStarting traversal\n\n");
    
    if (HEAD == NULL) {

        printf("List is empty.\n");

    }
    
    struct Node* node = HEAD;

    while (node != NULL) {

        //print item
        printf("%d\n", node->data);
        //jump to next node
        node = node->next;

    }
    
    printf("\n\nEnd traversal\n\n");



}