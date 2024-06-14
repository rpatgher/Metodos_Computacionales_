//
//  main.cpp
//  Tarea5
//
//  Created by Remy Patgher on 13/10/23.
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
    
    void deletePairs(){
        Node *tempIndex = index;
        Node *preIndex = NULL;
        Node *temp;
        cout << endl;
        while(tempIndex != NULL) {
            if(tempIndex->data % 2 == 0){
                if(preIndex == NULL){
                    temp = tempIndex;
                    index = tempIndex->next;
                    tempIndex = index;
                }else{
                    temp = tempIndex;
                    preIndex->next = tempIndex->next;
                    tempIndex = preIndex->next;
                }
                cout << endl << "Element deleted: " << temp->data << endl;
                delete temp;
            } else{
                preIndex = tempIndex;
                tempIndex = tempIndex->next;
            }
        }
    }
    
    void average(){
        Node *tempIndex = index;
        float average = 0, counter = 0;
        cout << endl;
        while(tempIndex != NULL) {
            average += tempIndex->data;
            counter++;
            tempIndex = tempIndex->next;
        }
        average /= counter;
        cout <<  endl << "The average of the elements in the list is: " << average << endl;
    }
    
    void search(int num){
        Node *tempIndex = index;
        int position = 1, counter = 0;
        cout << endl;
        while(tempIndex != NULL) {
            if(tempIndex->data == num){
                cout << "The element is on position: " << position << endl;
                counter++;
            }
            position++;
            tempIndex = tempIndex->next;
        }
        cout << "The element is " << counter << " times on the list." << endl << endl;
    }
    
    void deleteAllOccurrences(int num){
        Node *tempIndex = index;
        Node *preIndex = NULL;
        Node *temp;
        while(tempIndex != NULL) {
            if(tempIndex->data == num){
                if(preIndex == NULL){
                    temp = tempIndex;
                    index = tempIndex->next;
                    tempIndex = index;
                }else{
                    temp = tempIndex;
                    preIndex->next = tempIndex->next;
                    tempIndex = preIndex->next;
                }
                cout << endl << "Element deleted: " << temp->data << endl;
                delete temp;
            } else{
                preIndex = tempIndex;
                tempIndex = tempIndex->next;
            }
        }
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
    
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(7);
    list.insertEnd(8);
    list.average();
    list.search(3);
    list.showData();
    list.deletePairs();
    list.showData();
    list.insertEnd(8);
    list.insertEnd(8);
    list.insertEnd(8);
    list.showData();
    list.deleteAllOccurrences(8);
    list.showData();
    
    return 0;
}

