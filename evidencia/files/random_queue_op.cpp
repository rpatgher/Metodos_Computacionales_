//
//  main.cpp
//  Tarea4_Ej2
//
//  Created by Remy Patgher on 23/09/23.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

#define maxQueue 5

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

class Queue{
private:
    int values[maxQueue];
    int front;
    int back;
    
public:
    Queue(){
        front = 0;
        back = 0;
    }
    
    int emptyQueue(){
        if(front == back){
            cout << "The Queue is empty" << endl;
            return 1;
        }else
            return 0;
    }
    
    int fullQueue(){
        if(back == maxQueue){
            cout << "The Queue is full" << endl;
            return 1;
        }else
            return 0;
    }
    
    void enqueue(int num){
        cout << endl << "New element on Queue: " << num << endl;
        if(fullQueue() == 1)
            return;
        values[back] = num;
        back++;
    }
    
    void dequeue(){
        cout << endl << "Deleting elemento from Queue: " << values[front] << endl;
        if(emptyQueue() == 1)
            return;
        values[front] = 0;
        for(int i = 0; i < (back - 1); i++)
            values[i] = values[i+1];
        back--;
    }
    
    void showQueueQueueElements(){
        cout << "Elements on Queue: " << endl;
        cout << "|";
        for(int i = front; i < back; i++)
            cout << "\t" << values[i] << "\t|";
        cout << endl;
    }
    
    void fillQueue(){
        Dice number(1, 5);
        for(int i = 0; i < maxQueue; i++)
            enqueue(number.random());
    }
    
    void toSquare(){
        for(int i = front; i < back; i++)
            values[i]*= values[i];
    }
    
};

int main() {
    
    Queue queue;
    queue.fillQueue();
    cout << endl;
    queue.showQueueQueueElements();
    
    queue.toSquare();
    cout << endl;
    queue.showQueueQueueElements();
    
    
    return 0;
}
