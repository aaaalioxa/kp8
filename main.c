#include <stdio.h>
#include "list.h"

int main() {
    list *l = Create();
    printf("1. Add element\n2. Add first element\n3. Delete element\n4. Check size\n5. Print list\n6. Swap elements\n7. Exit\n");
    while (true) {
        int op;
        iterator p;
        char op1[] = "";
        printf("Enter option: ");
        do {
            scanf("%s", op1);
            op = RInput(op1, 0);
        } while (op == -1);
        char inputIns[100];
        bool insInput = true;
        switch (op) {
            case 1:
                if (l->size != 0) {
                    while (insInput) {
                        printf("Enter previous element:\n");
                        scanf("%s", inputIns);
                        p = Find(l, inputIns);
                        if (p.node == NULL) {
                            printf("No such element\n");
                        } else {
                            insInput = false;
                        }
                    }
                    char inputString[100];
                    printf("Enter new element:\n");
                    scanf("%s", inputString);
                    Insert(l, &p, inputString);
                }
                else {
                    printf("The list is empty, add first element\n");
                }
                break;
            case 5:
                if (l->size != 0) {
                    PrintList(l);
                }
                else {
                    printf("The list is empty\n");
                }
                break;
            case 3:
                if (l->head != NULL) {
                    while (insInput) {
                        printf("Enter deleting element:\n");
                        scanf("%s", inputIns);
                        p = Find(l, inputIns);
                        if (p.node == NULL) {
                            printf("No such element\n");
                        }
                        else {
                            insInput = false;
                        }
                    }
                    Delete(l, &p);
                }
                else {
                    printf("The list is empty\n");
                }
                break;
            case 4:
                printf("Size = %d\n", l->size);
                break;
            case 2:
                printf("Enter new element:\n");
                scanf("%s", inputIns);
                AddFirstElement(l, inputIns);
                break;
            case 6:
                if (l->size >= 3) {
                    printf("Input index k:\n");
                    do {
                        scanf("%s", op1);
                        op = RInput(op1, 0);
                    } while (op == -1);
                    if (op > l->size - 2 || op < 1) {
                        printf("Wrong input, try again\n");
                        do {
                            scanf("%s", op1);
                            op = RInput(op1, 0);
                        } while (op == -1);
                    }
                    Swap(l, op);
                }
                else {
                    printf("Not enough items in the list\n");
                }
                break;
            case 7:
                return 0;
            default:
                printf("No such option\n");
                break;
        }
    }
    return 0;
}