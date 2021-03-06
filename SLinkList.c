#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*fnode;

void create_List(){
    struct node *prev,*temp;
    int n,num;
    printf("Enter no. of nodes you want to  insert : ");
    scanf("%d",&n);
    while(n!=0){
        prev = temp;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter element : ");
        scanf("%d",&num);

        temp->data = num;
        temp->next = NULL;

        if(fnode == NULL){
            fnode = temp;
        }
        else{
            prev->next = temp;
        }
        n--;
    }
}
void beg_insert(){
    struct node *temp;
    int num;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("\nOverflow...");
    }
    else{
        printf("\nEnter element : ");
        scanf("%d",&num);

        temp->data = num;
        temp->next = fnode;
        fnode = temp;

        printf("\nNode inserted at beginning...");
    }
    return fnode;
}
void loc_insert(){
    struct node *prev,*temp;
    int num,loc;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("\nOverflow...");
    }
    else{
        printf("Enter element : ");
        scanf("%d",&num);
        printf("\nEnter location after which u want to insert : ");
        scanf("%d",&loc);
        temp->data = num;

        prev = fnode;
        
        for(int i=1;i<loc;i++){
            
            prev = prev->next;

            if(prev == NULL){
            printf("\nCan't insert...");
            }
        }
        
            temp->next = prev->next;
            prev->next = temp; 
            printf("\nNode inserted...");
    }
}
void end_insert(){
    struct node *temp,*prev;
    int num;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("\nOverflow...");
    }
    else{
        printf("\nEnter element : ");
        scanf("%d",&num);

        temp->data = num;
        
        if(fnode == NULL){
            temp->next = NULL;
            fnode = temp;
        }
        else{
            prev = fnode;
            while(prev->next != NULL){
                prev = prev->next;
            }
            prev->next = temp;
            temp->next = NULL;
        }

        printf("\nNode inserted at end...");
    }

}

void beg_delete(){
    struct node *temp;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else{
        temp = fnode;
        fnode = temp->next;
        free(temp);
        printf("\nFirst Node Deleted...");
    }
}
void loc_delete(){
    int loc;
    struct node *temp,*prev;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else{
        printf("\nEnter location after which you want to delete node :-");
        scanf("%d",&loc);
        temp = fnode;
        for(int i=0;i<loc;i++){
            prev = temp;
            temp = temp->next;
            if(temp == NULL){
                printf("\nThere are less than %d elements in list...",loc);
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
        printf("\nDeleted node%d.",loc+1);
    }
    
}
void num_delete(){
     struct node *temp,*prev;
     int num;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else{
        printf("Enter num you want to delete : ");
        scanf("%d",&num);
            temp = fnode;
        if(fnode->data == num){
            temp = fnode;
            fnode = temp->next;
            free(temp);
            printf("\nNode Deleted...");
        }
        else{
            
            while(temp->next != NULL && temp->data != num) {
                prev = temp;
                temp = temp->next;
            }        

            if(temp->data == num) {
                 prev->next = prev->next->next;
                free(temp);  
             }
             printf("\nNode Deleted...");
         }
    }
}
void end_delete(){
    struct node *temp,*prev;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else if(fnode->next == NULL){
        fnode = NULL;
        free(fnode);
        printf("\nOnly one element was present which is deleted...");
    }
    else{
        temp = fnode;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);

        printf("\nLast node deleted...");
    }
}
void display(){
    struct node *temp;
    if(fnode == NULL){
        printf("\nList is empty...");
    }
    else{
        temp = fnode;
        while(temp != NULL){
            printf("\n%d",temp->data);
            temp = temp->next;
        }
    }
}

void reverse(){
    struct node *next = NULL,*prev = NULL,*current = fnode;
    if(fnode == NULL){
        printf("\nUnderflow...");
    }
    else{
       while(current != NULL){
           next = current->next;
           current->next = prev;

           prev = current;
           current = next;
       }
        fnode = prev;
    }
}
int main(){
    int choice;
    int ch1,ch2;
    do{
    printf("\nEnter your choice :-\n");
    printf("\n1 : CREATE LIST\n2 : INSERT\n3 : DELETE\n4 : SEARCH\n5 : REVERSE\n6 : DISPLAY\n0 : EXIT\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : 
                create_List();
                break;
        case 2 : 
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
        case 3 : 
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
        case 4 : 
                break;
        case 5 : reverse();
                break;
        case 6 : display();
                break;
        case 0 : exit(0);

        default : printf("Invalid input...");

    }
    }while(choice != 0);
    return 0;
}