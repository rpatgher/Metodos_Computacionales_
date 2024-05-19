//
//  main.cpp
//  Linear Search
//
//  Created by Remy Patgher on 25/10/23.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

class LinearSearch{
private:
    int n; // Size of the list
    int *list;
    
public:
    LinearSearch(){
        srand((unsigned int)time(NULL));
        cout << "Enter the size of the List: "; cin >> n;
        list = new int[n];
    }
    
    void random_list(int minNum, int maxNum){
        for(int i = 0; i < n; i++){
            list[i] = rand() % maxNum + minNum;
        }
    }
    
    void set_list(){
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << "Enter the number " << i+1 << " of the list: "; cin >> list[i];
        }
    }
    
    void print_list(){
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << list[i] << "\t";
        }
        cout << endl << endl;
    }
    
    void search_num(int num){
        cout << endl;
        for(int i = 0; i < n; i++){
            if(list[i] == num){
                cout << "The number is at position " << i << " of the list" << endl;
            }
        }
    }
};

int main() {
    LinearSearch search;
    search.random_list(1, 10);
    search.print_list();
    
    return 0;
}
