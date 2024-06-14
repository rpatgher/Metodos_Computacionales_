//
//  main.cpp
//  Tarea2_Ej1
//
//  Created by Remy Patgher on 27/08/23.
//

#include <iostream>

using namespace std;

class Numbers{
private:
    int numsInit[5];
    int length;
    
public:
    Numbers(){
        length = sizeof(numsInit)/sizeof(numsInit[0]);
        for(int i = 0; i < length; i++){
            cout << "Enter the number " <<i+1<< ": "; cin>>numsInit[i];
        }
    }
    
    void multiplyNums(){
        int newNums[length];
        cout << endl;
        for(int i = 0; i < length; i++){
            newNums[i] = numsInit[i] * 2;
            cout << newNums[i] << "\t";
        }
        cout << endl;
    }
};


int main(int argc, const char * argv[]) {
    Numbers nums;
    
    nums.multiplyNums();
    
    return 0;
}
