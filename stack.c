#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char stack[] = {'a','b','c','d'};
char poppedStack[] = {};
const int MaxSize = 5;


char *top = &stack[sizeof(stack) - 1] ;
char *top2 = &poppedStack[sizeof(poppedStack) - 1] ;

bool IsEmpty(){
    if (top == &stack[0]-1){
        return 1;
    }else{
        return 0;
    }
}

bool IsFull(){
    if (sizeof(stack) == MaxSize)
    {
        return 1;
    }else{
        return 0;
    }
    
} 

char peek(char* ptr){
    return *ptr;
}

void push(char Letter){
    if(IsFull()){
        printf("\nThe stack is full.");
        exit(EXIT_SUCCESS);
    }else{
        stack[sizeof(stack) -1] = Letter;
    }
}

bool IsOnTop(char Item){
    if (peek(top) == Item)
    {
        return 1;
    }else{
        return 0;
    };
}

void pop(char Letter){
    if(IsEmpty()){
        printf("\nCould not retrieve data item, Stack is empty!");
        exit(EXIT_SUCCESS);
    }else{
        if(IsOnTop(Letter)){
            for(int i = 0 ; i < sizeof(stack)-2 ; i++){
                poppedStack[i] = stack[i];
            }
        }else{
            printf("\nCould not delete the item you specified, It may not be on top.");
            exit(EXIT_SUCCESS);
        }
    }
}

int main(){
    
    printf( "\n\nTop => %c" , peek(top));

    printf("\n\nIs empty? => %d", IsEmpty());

    printf("\n\nIs full? =>%d", IsFull());

    pop('d');

    printf( "\n\nTop => %c" , peek(top2));

    
}


