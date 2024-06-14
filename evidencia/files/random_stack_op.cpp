//
//  main.cpp
//  Tarea4_Ej1
//
//  Created by Remy Patgher on 23/09/23.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

#define maxStack 5

class Dice{
private:
    int maxNum, minNum;
    
public:
    Dice(int min, int max){
        maxNum = max;
        minNum = min;
    }
    
    int random(){
        return rand() % maxNum + minNum;
    }
};

class Stack{
private:
    int values[maxStack];
    int top;
public:
    // Init Stack
    Stack(){
        top = -1;
    }
    
    int fullStack(){
        if(top == maxStack - 1){
            cout << "The Stack is full" << endl;
            return 1;
        }else
            return 0;
    }
    
    int emptyStack(){
        if(top == -1){
            cout << "The Stack is empty" << endl;
            return 1;
        }else
            return 0;
    }
    
    void push(int newNum){
        cout << endl << "New element on Stack: " << newNum << endl;
        if(fullStack() == 1)
            return;
        top++;
        values[top] = newNum;
    }
    
    void pop(){
        cout << endl << "Deleting element from Stack: " << values[top] << endl;
        if (emptyStack() == 1)
            return;
        values[top] = 0;
        top--;
     }
    
    void showStackElements(){
        int i;
        cout << "Elements on Stack: " << endl;
        cout << "---------" << endl;
        for(i = top; i >= 0; i--)
            cout << "|\t" << values[i] << "\t|" << endl << "---------" << endl;
    }
    
    void chooseOperation(){
        Dice decision(1, 2);
        Dice number(0, 9);
        if(decision.random() == 1){
            push(number.random());
        }else{
            pop();
        }
    }
};

int main() {
    srand(time(0));
    Stack stack;
    int op;
    cout << "Enter the number of operations you want to do: "; cin >> op;
    
    for(int i = 0; i < op; i++){
        stack.chooseOperation();
        stack.showStackElements();
    }
    
    return 0;
}
