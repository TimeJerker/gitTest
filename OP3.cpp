#include <iostream>

void replace(int *Array);
int verification();
int Exit();

int size;
char arrExit[] = {};
std::string sExit;

int main(){
    std::cout << "=====Insert_array=====" << std::endl;
    size = verification();

    int *Array = new int[size];

    std::cout << "Input the values: " << std::endl;
    for (int l = 0; l < size; l++){
        int temp;
        while(!(std::cin >> temp) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
        }
        Array[l] = temp;
    }
    replace(Array);
    
    for(int i =0; i < size; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n====================" << std::endl;

    delete[] Array;

    Exit();
}

void replace(int *Array){
    for(int j = 1; j < size; j++){
        int current = Array[j];
        int k = j;
        while(k > 0 && Array[k-1] > current){
            Array[k] = Array[k-1];
            k--;
        }
        Array[k] = current;
}
}
int verification(){
    int x;
    std::cout <<"Input the size of array: " << std::endl;
    while(!(std::cin >> x) || std::cin.peek() != '\n' || x < 2){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    return x;
}
int Exit(){
    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    } 
    if(sExit == "yes"){
        main();
    }
    return 0;
}
