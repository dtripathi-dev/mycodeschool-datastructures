#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* ptrHead) {

    if (ptrHead == NULL) {

        printf("List is empty.\n");
        return;

    }
    
    struct Node* ptrCurrentNode = ptrHead;
    
    do {

        printf("List item => %d\n", ptrCurrentNode->data);
        ptrCurrentNode = ptrCurrentNode->next;

    } while(ptrCurrentNode != NULL);

}

void traverseRecursive(struct Node* ptrCurrNode) {

    if (ptrCurrNode == NULL) {

        printf("List is empty.\n");
        return;

    }

    printf("List item => %d\n", ptrCurrNode->data);
    
    if (ptrCurrNode->next == NULL) {
        return;
    }

    return traverseRecursive(ptrCurrNode->next);
    

}

void traverseReverseRecursive(struct Node* ptrCurrNode) {

    if (ptrCurrNode == NULL) {

        printf("List is empty.\n");
        return;

    }

    traverseReverseRecursive(ptrCurrNode->next);

    printf("List item => %d\n", ptrCurrNode->data);
    

}

void addAtTheEnd(struct Node** ptrHead, int item) {

    struct Node* ptrNodeToAdd = (struct Node*) malloc(sizeof(struct Node));

    ptrNodeToAdd->data = item;
    ptrNodeToAdd->next = NULL;

    if (*ptrHead == NULL) {

        *ptrHead = ptrNodeToAdd;
        
        return;

    }

    struct Node *ptrCurrentNode = *ptrHead;

    //find the last node
    while(ptrCurrentNode->next != NULL) {
        
        ptrCurrentNode = ptrCurrentNode->next;

    }

    ptrCurrentNode->next = ptrNodeToAdd;

}

void addAtTheStart(struct Node** ptrHead, int item) {

    struct Node* ptrNodeToAdd = (struct Node*) malloc(sizeof(struct Node));

    ptrNodeToAdd->data = item;
    ptrNodeToAdd->next = *ptrHead;

    *ptrHead = ptrNodeToAdd;

}

void deleteAtPosition(struct Node** ptrHead, int position) {

    if (*ptrHead == NULL) {

        return;

    }

    struct Node* ptrCurrNode = *ptrHead;

    //would work for both single node and multi node lists
    if (position == 0 || ptrCurrNode->next == NULL) {

        *ptrHead = ptrCurrNode->next;

        //free the head memory
        free(ptrCurrNode);

        return;

    }

    int nodeIndex = 0;
    
    //now reach the node just before the node we want to delete
    while(nodeIndex < position - 1 && ptrCurrNode->next->next != NULL) {

        nodeIndex++;
        ptrCurrNode = ptrCurrNode->next;

    }

    printf("current node index %d\n", nodeIndex);

    //now the node index will either be just before the last node in the list
    //or just before the position we want to delete node at
    struct Node* nodeToDelete = ptrCurrNode->next;

    ptrCurrNode->next = nodeToDelete->next;
    free(nodeToDelete);

}

//0 < position < list size
void addAtPosition(struct Node** ptrHead, int item, int position) {

    struct Node* ptrNodeToAdd = (struct Node*) malloc(sizeof(struct Node));
    ptrNodeToAdd->data = item;
    
    int listIndex = 0;
    struct Node* ptrCurrentNode = *ptrHead;

    //we are already on that position, i.e. 0
    if (ptrCurrentNode == NULL || position == 0) {
        
        //just add at the current position
        ptrNodeToAdd->next = ptrCurrentNode;
        *ptrHead = ptrNodeToAdd;

        return;

    }

    //we have to traverse to given position first
    while(listIndex < position - 1 && ptrCurrentNode->next != NULL) {

        listIndex++;
        ptrCurrentNode = ptrCurrentNode->next;

    }

    ptrNodeToAdd->next = ptrCurrentNode->next;
    ptrCurrentNode->next = ptrNodeToAdd;

    
}

void reverse(struct Node** ptrHead) {

    struct Node* ptrNext = NULL;
    struct Node* ptrPrev = NULL;
    struct Node* ptrCurrentNode = *ptrHead;

    while (ptrCurrentNode != NULL) {

        ptrNext = ptrCurrentNode->next;
        ptrCurrentNode->next = ptrPrev;
        ptrPrev = ptrCurrentNode;
        ptrCurrentNode = ptrNext;

    }

    *ptrHead = ptrPrev;

}

void reverseRecursive(
    struct Node** ptrHead,
    struct Node* ptrPrevNode, 
    struct Node* ptrCurrNode
) {

    if(ptrCurrNode == NULL) {

        *ptrHead = ptrPrevNode;
        return;

    }

    struct Node* ptrNextNode = NULL;

    //save address to the temp pointer
    ptrNextNode = ptrCurrNode->next;
    //update address in current pointer to prev pointer
    ptrCurrNode->next = ptrPrevNode;
    //advance prev point to the current pointer
    ptrPrevNode = ptrCurrNode;
    //advance current pointer to next node in chain via temp pointer
    ptrCurrNode = ptrNextNode;

    return reverseRecursive(ptrHead, ptrPrevNode, ptrCurrNode);

}

//initialize head
struct Node* HEAD = NULL;

int main() {

    int listItem;
    int position;
    int methodId;

    while (1) {

        printf("What operations you want to perform?\n");
        
        printf("1. INSERT AT HEAD\n");
        printf("2. INSERT AT TAIL\n");
        printf("3. INSERT AT POSITION\n");
        printf("4. DELETE AT POSITION\n");
        printf("5. REVERSE ITERATIVELY\n");
        printf("6. REVERSE RECURSIVELY\n");
        printf("7. TRAVERSE RECURSIVELY\n");
        printf("8. TRAVERSE RECURSIVELY IN REVERSE ORDER\n");
        printf("ANY OTHER NUMBER TO TRAVERSE\n");
        
        scanf("%d", &methodId);
        
        switch(methodId) {

            case 1:

                printf("Enter a number\n");
                scanf("%d", &listItem);
                addAtTheStart(&HEAD, listItem);
                
                break;
            
            case 2:

                printf("Enter a number\n");
                scanf("%d", &listItem);
                addAtTheEnd(&HEAD, listItem);

                break;

            case 3:

                printf("Enter a number & position\n");
                scanf("%d%d", &listItem, &position);
                addAtPosition(&HEAD, listItem, position);

                break;

            case 4: 

                printf("Enter a position\n");
                scanf("%d", &position);
                deleteAtPosition(&HEAD, position);

                break;

            case 5: 

                reverse(&HEAD);

                break;
            
            case 6:

                reverseRecursive(&HEAD, NULL, HEAD);
                
                break;
            
            case 7:

                traverseRecursive(HEAD);
                
                break;

            case 8:

                traverseReverseRecursive(HEAD);
                
                break;

            default:

                traverse(HEAD);

        }    

    }


}