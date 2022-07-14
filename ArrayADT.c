#include <stdio.h>
#include<stdlib.h>
typedef struct ArrayADT
{
    int capacity,lastindex;
    int *ptr;
}arrADT;

arrADT* createArray(int cap)
{
    arrADT *p;
    p=(arrADT*)malloc(sizeof(arrADT));
    p->capacity=cap;
    p->lastindex=-1;
    p->ptr=(int*)malloc(cap*sizeof(int));
    for(int i=0;i<cap;i++)
    {
        p->ptr[i]=-1;
    }
    return p;
}

void append(arrADT* p,int data)
{
    if(p->lastindex==p->capacity-1)
    {
        printf("\n⚠️Overflow⚠️\n");
    }
    else
    {
        p->lastindex++;
        p->ptr[p->lastindex]=data;
    }
    printf("%d\n",p->lastindex);
}

void insert(arrADT* p,int index,int data)
{
    if(index<0||index>p->lastindex+1)
    {
        printf("\n⚠️Invalid index⚠️\n");
    }
    else if(p->lastindex==p->capacity-1)
    {
        printf("\n⚠️Overflow⚠️\n");
    }
    else
    {
        for(int i=p->lastindex;i>=index;--i)
        {
            p->ptr[i+1]=p->ptr[i];
        }
        p->ptr[index]=data;
        p->lastindex++;
        printf("\n%d\n",p->lastindex);
    }
}

void deletion(arrADT* p,int index)
{
    if(p->lastindex==-1)
    {
        printf("\n⚠️Under flow cannot delete⚠️\n");
    }
    else
    {
        for(int i=index+1;i<p->capacity;i++)
        {
            p->ptr[i-1]=p->ptr[i];
        }
        p->lastindex--;
        p->ptr[p->capacity-1]=-1;
        printf("\n%d\n",p->lastindex);
    }

}

void display(arrADT* p)
{

        printf("\nThis is your array\n");
        for(int i=0;i<p->capacity;i++)
            printf("| %d ",p->ptr[i]);
        printf("|");
        printf("\n");
}

int getdata(arrADT* p, int index)
{
    if(index>p->lastindex)
    {
        printf("\n⚠️Invalid Index⚠️");
        return -1;
    }
    else
        return (p->ptr[index]);
}

int count(arrADT* p)
{
    return (p->lastindex+1);
}

void edit(arrADT* p, int index, int newvalue)
{
    if(index>p->lastindex)
    {
        printf("\n⚠️Invalid Index⚠️");\
    }
    else
    {
        p->ptr[index]=newvalue;
    }
}

int main()
{
    int value,ch,flag=1,size;
    arrADT *Array1;
    printf("Enter the size of array you want to create\n");
    scanf("%d",&size);
    Array1=createArray(size);
    while(flag==1)
    {
        int index=0,ans=0;
        printf("\nEnter your choice:\n");
        printf("\n1. Append element\n2. Delete\n3. Display Array\n4. Insert data\n5. Get data\n6. Count\n7. Edit\n8. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nYOU ARE GOING TO APPEND A NEW ELEMENT\n");
                printf("Enter the data: ");
                scanf("%d",&value);
                append(Array1,value);
                break;
            case 2:
                printf("\nYOU ARE GOING TO DELETE AN ELEMENT\n");
                printf("Enter the index: ");
                scanf("%d",&index);
                deletion(Array1,index);
                break;
            case 3:
                display(Array1);
                break;
            case 4:
                printf("\nYOU ARE GOING TO INSET AN ELEMENT AT PARICULAR INDEX\n");
                printf("Enter the index: ");
                scanf("%d",&index);
                printf("\nEnter the value to insert: ");
                scanf("%d",&value);
                insert(Array1, index, value);
                break;
            case 5:
                printf("\nYOU ARE GOING TO FETCH AN ELEMENT AT PARICULAR INDEX\n");
                printf("Enter the index: ");
                scanf("%d",&index);
                ans=getdata(Array1, index);
                printf("\nData: %d",ans);
                break;
            case 6:
                printf("\nYOU ARE GOING TO SEE COUNT OF ELEMENTS\n");
                ans=count(Array1);
                printf("\nCount: %d",ans);
                break;
            case 7:
                printf("\nYOU ARE GOING TO EDIT ARRAY\n");
                printf("Enter the index: ");
                scanf("%d",&index);
                printf("\nEnter the new value to insert: ");
                scanf("%d",&value);
                edit(Array1, index, value);
                break;
            case 8:
                flag=0;
                break;
        }
    }
    return 0;
}
