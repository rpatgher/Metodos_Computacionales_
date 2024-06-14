//
//  main.cpp
//  Tarea2_Ej2
//
//  Created by Remy Patgher on 27/08/23.
//

#include <iostream>

using namespace std;


class Strings{
private:
    string str1;
    string str2;
public:
    Strings(){
        cout << "Enter the first String: "; cin >> str1;
        cout << "Enter the second String: "; cin >> str2;
    }
    
    void compareStrings(){
        if(str1 == str2){
            cout << "They're the same" << endl;
        }else{
            cout << "They're not the same" << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    Strings strings;
    
    strings.compareStrings();
    
    return 0;
}
