//
//  main.cpp
//  Linked List
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *index;
    
public:
    LinkedList(){
        index = NULL;
    }
    
    int emptyList(){
        if(index == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *tempIndex = index;
            while(tempIndex->next != NULL){
                tempIndex = tempIndex->next;
                length++;
            }
            length++;
        }
        cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = index;
            index = element;
            return;
        }
        Node *tempIndex = index;
        while(tempIndex->next != NULL)
            tempIndex = tempIndex->next;
        element->data = num;
        element->next = NULL;
        
        tempIndex->next = element;
    }
    
    void insertPos(int num, int pos){
        if(pos < 1 || pos > listLength()){
            cout << endl << "Cannot Insert. Invalid Position" << endl;
            return;
        }
        if(pos == 1){
            insertBeg(num);
            return;
        }
        cout << endl << "New Element on position " << pos << ": " << num << endl;
        Node *element = new Node();
        Node *tempIndex = index;
        while(--pos > 1)
            tempIndex = tempIndex->next;
        element->data = num;
        element->next = tempIndex->next;
        tempIndex->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = index;
            index = element;
            return;
        }
        element->data = num;
        element->next = index;
        index = element;
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        if(index->next == NULL){
            delete index;
            index = NULL;
            return;
        }
        Node *tempIndex = index;
        while (tempIndex->next->next != NULL)
            tempIndex = tempIndex->next;
        Node *temp = tempIndex->next;
        tempIndex->next = NULL;
        cout << endl << "Element deleted at End in the List: " << temp->data << endl;
        delete temp;
    }
    
    void deletePos(int pos){
        if(pos < 1 || pos > listLength()){
            cout << endl << "Cannot Insert. Invalid Position" << endl;
            return;
        }
        if(pos == 1){
            deleteBeg();
            return;
        }
        Node *tempIndex = index;
        while(--pos > 1)
            tempIndex = tempIndex->next;
        Node *temp = tempIndex->next;
        tempIndex->next = tempIndex->next->next;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *tempIndex = index;
        Node *preIndex = NULL;
        Node *temp;
        while(tempIndex->next != NULL) {
            if(tempIndex->data == num){
                if(preIndex == NULL){
                    deleteBeg();
                    return;
                }else{
                    temp = tempIndex;
                    preIndex->next = tempIndex->next;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            preIndex = tempIndex;
            tempIndex = tempIndex->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = index;
        index = index->next;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showData(){
        Node *temp = index;
        cout << endl << "Data in List: " << endl;
        cout << "|";
        while(temp != NULL){
            cout << "\t" << temp->data << "\t|";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    //list.showData();
    list.insertEnd(2);
    list.insertEnd(1);
    //list.showData();
    
    //list.deleteEnd();
    //list.deleteBeg();
    //list.showData();
    //list.listLength();
    
    list.insertPos(5, 2);
    //list.showData();
    //list.deletePos(2);
    list.showData();
    
    list.deleteElement(5);
    list.deleteElement(8);
    list.deleteElement(6);
    list.showData();
    
    return 0;
}
