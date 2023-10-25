#include <iostream>

int main(){
    char arrExit[] = {};
    std::string sExit;
    do{
    int temp = 0;
    int size = 0;
    std::cout <<"Input the number of integers: " << std::endl;
    while(!(std::cin >> size) || std::cin.peek() != '\n' || size < 2){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    int *Array = new int(size);
    for (int i = 0; i < size; i++){
        std::cout << "Input the integer: " << std::endl;
        while(!(std::cin >> temp) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
        Array[i] = temp;
    }
    for(int j = 0; j < size - 1; j++){
        for(int k = 0; k <size - j - 1; k++){
            if(Array[j] > Array[j+1]){
                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
    std::cout << "Minimum: " << Array[0] << "\nMaximum: " << Array[size-1] << std::endl;
    delete[] Array;
    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    }   
    }while(sExit == "yes");
}