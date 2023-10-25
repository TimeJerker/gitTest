#include <iostream>
#include <math.h>
const double PI = acos(-1.0);

long double GetPolarAngle(double x, double y);
long double x = 0;
long double y = 0;

int main(){

    char arrExit[] = {};
    std::string sExit;
    do{

    std::cout << "Enter x: ";
    while(!(std::cin >> x) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Incorrect input. Try again: ";
    }
    
    std::cout << "Enter y: ";
    while(!(std::cin >> y) || std::cin.peek() != '\n'){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Incorrect input. Try again: ";
    }

    long double angle = GetPolarAngle(x,y);
    long double p = sqrt(pow(x,2) + pow(y,2));

    std::cout.precision(16);

    std::cout << "Distance: "<< p << "\nAngle: " << angle << std::endl;

    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    }   
    }while(sExit == "yes");
}
long double GetPolarAngle(double x, double y){
    long double res = atan2(y,x);
    if (res < 0) res += 2*PI;
    return res;
}
