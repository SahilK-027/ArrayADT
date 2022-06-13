#include <stdio.h>
#include<stdlib.h>
typedef struct ArrayADT
{
    int capacity,lastindex;
    int *A;
} Arr;

Arr* createArray(int cap)
{
    Arr *ptr;
    ptr=(Arr*)malloc(cap * sizeof(Arr));
    ptr->capacity=cap;
    ptr->lastindex=-1;
    ptr->A=(int*)malloc(cap*sizeof(int));
    for(int i=0;i<cap;i++)
    {
        ptr->A[i]=-1;
    }
    return(ptr);
}
int isFull(Arr* ptr)
{
    if(ptr->lastindex==ptr->capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Arr* ptr)
{
    if(ptr->lastindex==-1)
    {
        return 1;
    }
    else
        return 0;
}

void append(Arr* ptr, int value)
{
    if(!isFull(ptr))
    {
        ptr->lastindex++;
        ptr->A[ptr->lastindex]=value;
    }
    else
    {
        int flag=0;
        for(int i=ptr->capacity-1;i>0;--i)
        {
            if(ptr->A[i]==-1)
            {
                ptr->A[i]=value;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n⚠️ARRAY IS FULL CANNOT APPEND⚠️\n");
        }
    }
}
void delete(Arr* ptr,int index)
{
        for(int i=index+1;i<ptr->capacity;i++)
        {
            ptr->A[i-1]=ptr->A[i];
        }
        ptr->A[ptr->capacity-1]=-1;
    
}
void insertatIndex(Arr* ptr,int index,int data)
{
    
    if(ptr->A[index]==-1)
    {
        ptr->A[index]=data;
        ptr->lastindex=index;
    }
    else{
    for(int i=ptr->capacity-1;i>index;--i)
    {
        ptr->A[i]=ptr->A[i-1];
    }
    ptr->A[index]=data;
    }
}

void showArray(Arr *ptr)
{
    printf("This is your array\n");
    for(int i=0;i<ptr->capacity;i++)
        printf("| %d ",ptr->A[i]);
    printf("|");
    printf("\n");
}


int main()
{
    int value,ch,flag=1,size;
    Arr *Array1;
    printf("Enter the size of array you want to create\n");
    scanf("%d",&size);
    Array1=createArray(size);
    while(flag==1)
    {
        int index=0;
        printf("Enter your choice:\n");
        printf("\n1. Append element\n2. Delete a particular element\n3. Display Array\n4. Insert data in between \n5. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nYOU ARE GOING TO APPEND A NEW ELEMENT\n");
                printf("Enter new number: ");
                scanf("%d",&value);
                append(Array1,value);
                break;
            case 2:
                printf("\nYOU ARE GOING TO DELETE AN ELEMENT\n");
                printf("Enter new index: ");
                scanf("%d",&index);
                delete(Array1,index);
                break;
            case 3:
                showArray(Array1);
                break;
            case 4:
                printf("\nYOU ARE GOING TO INSER AN ELEMENT AT PARICULAR INDEX\n");
                printf("Enter the index: ");
                scanf("%d",&index);
                printf("\nEnter the value to insert: ");
                scanf("%d",&value);
                insertatIndex(Array1, index, value);
                break;
            case 5:
                flag=0;
                break;
        }
    }
    return 0;
}
