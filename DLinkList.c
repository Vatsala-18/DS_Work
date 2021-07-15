#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*fnode;
void beg_insert(){
    struct node *temp;
    int num;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter element :- ");
        scanf("%d",&num);

        if(fnode == NULL){
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = num;

            fnode = temp;
        }
        else{
            temp->data = num;
            temp->prev = NULL;
            temp->next = fnode;
            fnode->prev = temp;

            fnode = temp;
        }
        printf("\nNode inserted...");
      
}
}
void end_insert(){
    int num;
    struct node *temp1,*temp2;
    temp1 = (struct node*)malloc(sizeof(struct node));
    if(temp1 == NULL){
        printf("\nOverflow...");
    }
    else{
        printf("\nEnter element := ");
        scanf("%d",&num);
        temp1->data = num;
        if(fnode == NULL){
            temp1->next = NULL;
            temp1->prev = NULL;
            
            fnode = temp1;
        }
        else{
            temp2 = fnode;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp1;
            temp1->next = NULL;
            temp1->prev = temp2;
        }
        printf("\nNode inserted...");
    }
}
void loc_insert(){
    int i;
}
void beg_delete(){
    struct node *temp;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else if(fnode->next == NULL){
        fnode = NULL;
        free(fnode);
        printf("\nOnly node present is deleted...");
    }
    else{
        temp = fnode;
        fnode = fnode->next;
        fnode->prev = NULL;
        free(temp);
        printf("\nFirst node deleted...\n");
    }
} 
void loc_delete(){
    int i;
}
void end_delete(){
    struct node *temp;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else if(fnode->next == NULL){
        fnode = NULL;
        free(fnode);
        printf("\nOnly node present is deleted...");
    }
    else{
        temp = fnode;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("Last node deleted...");
    }
}
void num_delete(){
    int i;
}
void reverse(){
    int i;
}
void display(){
    struct node *temp = fnode;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else{
        while(temp != NULL){
            printf(" %d",temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int choice;
    int ch1,ch2;
    do{
    printf("\nEnter your choice :- ");
    printf("\n1 : INSERT\n2 : DELETE\n3 : REVERSE\n4 : DISPLAY\n0 : EXIT\n");
    scanf("%d",&choice);
    switch(choice){
        
        case 1 : 
                printf("\nSelect one : \n");
                printf("1 : AT BEGINNING\n2 : AT ANY LOCATION\n3 : AT END\n");
                scanf("%d",&ch1);
                switch(ch1){
                    case 1 : beg_insert();
                             break;          
                    case 2 : loc_insert();
                             break;
                    case 3 : end_insert();
                             break;
                }
                break;
        case 2 : 
                printf("\nSelect one : ");
                printf("\n1 : FROM BEGINNING\n2 : FROM ANY LOCATION\n3 : FROM END\n4 : ANY ELEMENT\n");
                scanf("%d",&ch2);
                switch(ch2){
                    case 1 : beg_delete();
                             break;
                    case 2 : loc_delete();
                             break;
                    case 3 : end_delete();
                             break;
                    case 4 : num_delete();
                             break;
                }
                break;
        case 3 : reverse();
                break;
        case 4 : display();
                break;
        case 0 : exit(0);

        default : printf("Invalid input...");

    }
    }while(choice != 0);
    return 0;
}