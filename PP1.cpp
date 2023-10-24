#include <iostream>

int main(){
    char arrExit[] = {};
    std::string sExit;
    do{
    bool flag = true;
    int count = 0;
    int mainSize;
    std::string  temp;
    int secondSize;

    std::cout << "Enter the size of main array: " << '\n';
    while(!(std::cin >> mainSize) || std::cin.peek() != '\n' || mainSize < 3){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    std::cout << "Enter the size of second array: " << '\n';
    while(!(std::cin >> secondSize) || std::cin.peek() != '\n' || secondSize < 2){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    while(secondSize == mainSize){
        std::cout << "Main and second array cant be equivalent: " << '\n';
        main();

    }
    std::string *mainArray = new std::string[mainSize];

    std::cout << "Enter the numbers of main array: " << "\n";
    for(int i = 0; i< mainSize; i++){
        while(!(std::cin >> temp) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
        mainArray[i] = temp;
    }
    
    std::string *secondArray = new std::string[secondSize];

    std::cout << "Enter the numbers of second array: " << "\n";
    for(int j = 0; j < secondSize; j++){
        while(!(std::cin >> temp) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
        secondArray[j] = temp;
    }
    
    for (int i = 0; i < mainSize; i++){
        flag = true;
        int j = 0;
        while (j< secondSize && mainArray[j+i] == secondArray[j]){
            j++;
        }
        if (j == secondSize) {
            count++;
        }
        /*for (int j = 0; j < secondSize; j++){
            if (mainArray[j+i] != secondArray[j]){
                flag = false;
            }
        }*/
    }
    //Обязательная очистка массива, так как без неё может произойти утечка памяти (undefined behaivor)
    delete[] mainArray;
    delete[] secondArray;
    std::cout << "The mainArray includes the secondArray " << count << " times" << std::endl;

    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    }   
    }while(sExit == "yes");
}