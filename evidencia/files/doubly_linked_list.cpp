//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
//
//  main.cpp
//  Lista Doblemente Ligada
//
//  Created by Remy Patgher on 02/10/23.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *beg;
    Node *end;
    
public:
    DoublyLinkedList(){
        beg = NULL;
        end = NULL;
    }
    
    int emptyList(){
        if(beg == NULL && end == NULL)
            return 1;
        return 0;
    }
    
    int listLength(){
        int length = 0;
        if(emptyList() == 0){
            Node *index = beg;
            while(index->next != NULL){
                index = index->next;
                length++;
            }
            length++;
        }
        // cout << endl << "The Length of the list is: " << length << endl;
        return length;
    }
    
    void insertEnd(int num){
        cout << endl << "New Element at End in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = NULL;
            element->prev = end;
            end->next = element;
            end = element;
        }
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
        Node *index = beg;
        Node *element = new Node();
        while(--pos > 1)
            index = index->next;
        element->data = num;
        element->next = index->next;
        element->next->prev = element;
        element->prev = index;
        index->next = element;
    }
    
    void insertBeg(int num){
        cout << endl << "New Element at Beginning in the List: " << num << endl;
        Node *element = new Node();
        if(emptyList() == 1){
            element->data = num;
            element->next = NULL;
            element->prev = NULL;
            beg = element;
            end = element;
        }else{
            element->data = num;
            element->next = beg;
            element->prev = NULL;
            beg->prev = element;
            beg = element;
        }
    }
    
    void deleteEnd(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = end;
        end = end->prev;
        end->next = NULL;
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
        if(pos == listLength()){
            deleteEnd();
            return;
        }
        Node *index = beg;
        while(--pos > 1)
            index = index->next;
        Node *temp = index->next;
        index->next = temp->next;
        temp->prev = index;
        cout << endl << "Element on position " << pos << " deleted: " << temp->data << endl;
        delete temp;
        
    }
    
    void deleteElement(int num){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *index = beg;
        Node *temp;
        while(index->next != NULL) {
            if(index->data == num){
                if(index == beg){
                    deleteBeg();
                    return;
                }else if(index == end){
                    deleteEnd();
                    return;
                }else{
                    temp = index;
                    index->prev->next = index->next;
                    index->next->prev = index->prev;
                    cout << endl << "Element deleted: " << temp->data << endl;
                    delete temp;
                    return;
                }
            }
            index = index->next;
        }
        cout << endl << "Element " << num << " not found" << endl;
    }
    
    void deleteBeg(){
        if(emptyList() == 1){
            cout << endl << "The List is empty" << endl;
            return;
        }
        Node *temp = beg;
        beg = beg->next;
        beg->prev = NULL;
        cout << endl << "Element deleted at Beginning in the List: " << temp->data << endl;
        delete temp;
    }
    
    void showDataBeg(){
        Node *index = beg;
        cout << endl << "Data in List from the Beginning: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->next;
        }
        cout << endl;
    }
    
    void showDataEnd(){
        Node *index = end;
        cout << endl << "Data in List from the End: " << endl;
        cout << "|";
        while(index != NULL){
            cout << "\t" << index->data << "\t|";
            index = index->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    
    list.insertBeg(3);
    list.insertBeg(4);
    list.insertBeg(5);
    list.insertBeg(6);
    list.insertBeg(7);
    list.insertEnd(2);
    list.showDataBeg();
    
    list.deleteBeg();
    list.deleteEnd();
    list.showDataBeg();
    // cout << "Length: " << list.listLength() << endl;
    list.insertPos(10, 4);
    list.showDataBeg();
    list.deletePos(3);
    list.showDataBeg();
    list.deleteElement(5);
    list.showDataBeg();
    
    // list.showDataEnd();
    
    
    return 0;
}
