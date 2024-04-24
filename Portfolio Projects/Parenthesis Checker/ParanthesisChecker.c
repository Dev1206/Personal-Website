#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char stack[30];
int top = -1; //-1 indicates that array is empty.

bool isEmpty() // check if stack is empty
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int value) // push the value into stack
{
    if (top == 30 - 1)
    {
        printf("Stack is full");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
    }
    return;
}

int pop() // pop pops the top element out and return rest of the stack
{
    if (isEmpty())
    {
        printf("stack is empty\n");
        exit(1);
    }
    else
    {
        top = top - 1;
        return stack[top + 1];
    }
}

int currentTop() // it returns the topmost element in the stack
{
    return stack[top];
}

void size() // it prints the size of the stack using top.
{
    printf("%d", top + 1);
}

void print() // it prints the stack.
{
    int len = strlen(stack);
    if (isEmpty())
    {
        printf("stack is empty\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
}

void bracketmatch(char arr[], char x) //this function matches the paranthesis
{
    

    x = strlen(arr);
    for (int i = 0; i < x; i++) // for loop is used to iterate through whole string.
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')//push if open paranthesis
        {
            push(arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') // checks if closed paranthesis.
        {
            if (isEmpty()) // if stack is empty and close paranthesis it prints no.
            {
                printf("No");
            }
            else if (arr[i] == ')' && currentTop() == '(')// if there is match for the paranthesis it pops that out.
            {
                pop();
            }
            else if (arr[i] == '}' && currentTop() == '{')
            {
                pop();
            }
            else if (arr[i] == ']' && currentTop() == '[')
            {
                pop();
            }
        }
    }
    if (isEmpty()) // after completing itteration through whole string if the stack is empty prints yes else no.
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

int main()
{
    // if we want to take user input.

    printf("Enter a string of paranthesis\n");
    scanf("%s",stack);

    int len = strlen(stack);
    bracketmatch(stack,len);
    

}

/*
time complexity:-
best case is O(1) - when 1st element is envalid element or closed bracket.
worst case is O(n) - when all the paranthesis are correct and iterate through whole string.
*/ 
    
























    // for (int i = 0; i < len; i++)
    // {
    //     if (stack[i] =='('||stack[i] =='['||stack[i] =='{' || stack[i] ==')'||stack[i] ==']'||
    //      stack[i] =='}'||stack[i] =='0'||stack[i] =='1'||stack[i] =='2'||stack[i] =='3'||stack[i] =='4'||
    //      stack[i] =='5'||stack[i] =='6'||stack[i] =='7'||stack[i] =='8'||stack[i] =='9'||stack[i] =='/'||
    //      stack[i] =='*'||stack[i] =='-'||stack[i] =='+')
    //     {
    //         continue;
    //     } 
    //     else
    //     {
    //          printf("INVALID ELEMENT");
    //          exit(0);
    //     }
    // }

    // if (go != x)
    // {
    //     printf("Wrong paranthesis");
    //     exit(0);
    // }
