#include <iostream>

//Создание приложения, которое будет переволить градусы в разные степени измерения
// объявление функций выше, чтобы чтобы главная функция не потерялась
char choiseMeasurement();
double choiseValue();
char choiseConversation(char choise1);
double compilator(char choise1, char  choise2, double gradius);
//choise1, choise2- выбор первой и второй системы градусов
//gradius- число первоначальных градусов, result- переменная, для вывода ответа
//arrExit, sExit - массив и строка для распознавания, хочет ли польхователь выйти из приложения
char choise1;
double gradius;
char choise2;
double result;

int main(){
    char arrExit[] = {};
    std::string sExit;
    do{
    std::cout << "***** Tempreture converstation *****" << std::endl;
    
    choise1 = choiseMeasurement();
    gradius = choiseValue();
    choise2 = choiseConversation(choise1);
    result = compilator(choise1, choise2, gradius);
    std::cout << "The result of compilation is: " << result << std::endl;
    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    //цикл for который будет переводить результат ввода в строку в нижнем регистре
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    }   
    //проверка, на то, хочет ли пользователь выйти из приложения, в случае отрицательного ответа приложения будет повторяться заново
    }while(sExit == "yes");

    std::cout << "**********************************";
}
//функция, которая записывает выбор первых градусов и проверяет ввод на корректность
char choiseMeasurement(){
    char equivalently[] = "CFK";
    std::cout << "Choose one of them: " << std::endl;
    std::cout << "C - Celsius\n";
    std::cout << "F - Farenheit\n";
    std::cout << "K - Kelvin\n";
    //проверка правильности ввода
    while(!(std::cin >> choise1) || std::cin.peek() != '\n'  || !(strchr(equivalently,choise1))){
        //очистка ввода и флагов
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    return toupper(choise1);
}
// функция для ввода числа градусов и проверка на корректность ввода
double choiseValue(){
    std::cout << "Enter the value(any number): " << std::endl;
    while(!(std::cin >> gradius) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    return gradius;
}
//функция для определения градуса, в которую будут переводить данные
char choiseConversation(char choise1){
    char equivalently[] = "CFK";
    std::cout << "What unit of measurement you want to convert to?: " << std::endl;
    switch(choise1){
        case 'C':
        std::cout << "F - Farenheit\n";
        std::cout << "K - Kelvin\n";
        break;
        case 'F':
        std::cout << "C - Celsius\n";
        std::cout << "K - Kelvin\n";
        break;
        case 'K':
        std::cout << "C - Celsius\n";
        std::cout << "F - Farenheit\n";
        break;
    }
    while(!(std::cin >> choise2) || std::cin.peek() != '\n'  || !(strchr(equivalently,choise2))){
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "Wrong input! Try again: ";
    }
    return toupper(choise2);
}
//функция, которая будет выдавать результат, соответсвуя всем введеным данным
double compilator(char choise1, char  choise2, double gradius){
    double result;
    if (choise1 == 'C'){
        if (choise2 == 'F'){
            result = gradius * 1.8 + 32;
        }
        else if(choise2 == 'K'){
            result = gradius + 273.15;
        }
    }
    else if(choise1 == 'K'){
        if (choise2 == 'C'){
            result = gradius - 273.15;
        }
        else if (choise2 == 'F'){
            result = gradius * 1.8 - 459.67;
        }
    }
    else if(choise1 == 'F'){
        if (choise2 == 'C'){
            result = (gradius - 32) / 1.8;
        }
        else if(choise2 == 'K'){
            result = (gradius + 459.67) / 1.8;
        }
    }
    return result;
}