#include <iostream>

using namespace std;
void print(int size, int num);
void printBlank(int size);
void printLeft(int size);
void printRight(int size);
void printLeftRight(int size);
void printLine(int size);

int main(){
    int size, num;
    while(true){
        cin >> size >> num;
        if(size == 0) break;
        print(size, num);
    }
    return 0;
}

void printBlank(int size){
    for(int k = 0; k < size + 2; ++k) cout << " ";
}

void printRight(int size){
    for(int k = 0; k < size + 1; ++k) cout << " ";
    cout << "|";
}

void printLeft(int size){
    cout << "|";
    for(int k = 0; k < size + 1; ++k) cout << " ";
}

void printLeftRight(int size){
     cout << "|";
     for(int k = 0; k < size; ++k) cout << " ";
     cout << "|";
}

void printLine(int size){
    cout << " ";
    for(int k = 0; k < size; ++k) cout <<"-";
    cout << " ";
}

void print(int size, int num){
    int lines = size * 2 + 3;
    string str = to_string(num);
    for(int i = 1; i <= lines; ++i){
        for(int j = 0; j < str.length(); ++j){
            switch(str[j]){
                case '1': if(i == 1 || i == size + 2 || i == 2 * size + 3){
                              printBlank(size);
                          }else{
                              printRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '0': if(i == 1 || i == 2 * size + 3){
                              printLine(size);
                          }else if(i == size + 2){
                              printBlank(size);
                          }else{
                              printLeftRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '2': if(i == 1 || i == size + 2 || i == 2*size + 3){
                            printLine(size);
                          }else if(i > 1 && i < size + 2){
                            printRight(size);
                          }else{
                            printLeft(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '3': if(i == 1 || i == size + 2 || i == 2*size + 3){
                            printLine(size);
                          }else{
                            printRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '4': if(i == 1 || i == 2*size + 3){
                            printBlank(size);
                          }else if(i == size + 2){
                            printLine(size);
                          }else if(1 < i && i < size + 2){
                            printLeftRight(size);
                          }else{
                            printRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '5': if(i == 1 || i == size + 2 || i == 2*size + 3){
                            printLine(size);
                          }else if(i > 1 && i < size + 2){
                            printLeft(size);
                          }else{
                            printRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '6': if(i == 1 || i == size + 2 || i == 2*size +3){
                            printLine(size);
                          }else if(i > 1 && i < size + 2){
                            printLeft(size);
                          }else{
                            printLeftRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '7': if(i == 1){
                            printLine(size);
                          }else if(i == size + 2 || i == 2*size + 3){
                            printBlank(size);
                          }else{
                            printRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '8': if(i == 1 || i == size + 2 || i == 2*size + 3){
                            printLine(size);
                          }else{
                            printLeftRight(size);
                          }
                          if(j != str.length() - 1) cout << " ";
                    break;
                case '9':if(i == 1 ||i == size + 2 || i == 2*size + 3){
                            printLine(size);
                         }else if(i > 1 && i < size + 2){
                            printLeftRight(size);
                         }else{
                            printRight(size);
                         }
                         if(j != str.length() - 1) cout << " ";
                    break;
            }
        }
        cout << endl;
    }
    cout << endl;
}
