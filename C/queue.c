#include<stdio.h>
#include<stdlib.h>
#define Max 3

struct queue
{
    int item[Max];
    int f;
    int r;
};

typedef struct queue Q;

void create(Q*s) {
    s->f = -1;
    s->r = -1;
}

void printQ(Q*s) {
    if (s->f == -1)
    {
        printf("Queue is empty !\n");
        return;
    }
    printf("front is : %d\n",s->f);
    printf("end is : %d\n",s->r);
    for (int i = s->f; i <= s->r; i++)
    {
        printf("%dth element : %d\n",i,s->item[i]);
    }
}

void insert(Q*s,int data) {
    if(s->r==Max-1)
    {
        printf("full\n");
    }
    else {
        if (s->f == -1)
        {
            s->f = 0;
        }
        s->r++;
        s->item[s->r] = data;
    }
}

void delete(Q*s) {
    if(s->f==-1)
    {
        printf("empty\n");
    }
    else
    {
        printf("%d\n",s->item[s->f]);
        s->f++;
        
        if(s->f>s->r)
        {
            s->f=-1;
            s->r=-1;
        }
    }
}

void main() {
    int data;
    Q *s=malloc(sizeof(Q));
    create(s);
    printf("Enter the elements : \n");
    for(int i=0;i<Max;i++)
    {
        scanf("%d",&data);
        insert(s,data);
    }
    
    printf("Delete the element : \n");
    delete(s);
    printf("Elements inside queue is : ");
    printQ(s);
}
