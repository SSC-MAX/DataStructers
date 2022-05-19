#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    char data;
    StackNode *next;
}StackNode,*LStack;

void initStack(LStack &S)
{
    S = (StackNode*)malloc(sizeof(StackNode));
    S->next = NULL;
}

bool isEmpty(LStack S)
{
    return S->next==NULL;
}

void push(LStack &S, char c)
{
    StackNode *s = (StackNode*)malloc(sizeof(StackNode));
    s->data = c;
    s->next = S->next;
    S->next = s;
}

bool pop(LStack &S, char &c)
{
    if (isEmpty(S))
    {
        return false;
    }
    StackNode *p = S->next;
    c = p->data;
    S->next = p->next;
    free(p);
    return true;
}

bool matchBracket(char str[])
{
    int i;
    char c;
    LStack S;
    initStack(S);
    for (i = 0; str[i]!='\0'; i++)
    {
        if (str[i]=='{' || str[i]=='[' || str[i]=='(')
        {
            push(S,str[i]);
            continue;
        }else{
            pop(S,c);
            if (c=='{' && str[i]=='}')
            {
                continue;
            }
            if (c=='[' && str[i]==']')
            {
                continue;
            }
            if (c=='(' && str[i]==')')
            {
                continue;
            }
        }
        return false;
    }
    return isEmpty(S);
    
}