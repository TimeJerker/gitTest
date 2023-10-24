#include <iostream>
#include <cmath>

double equation(double x, int n) {
    double An = (pow(-1, n + 1) * pow(x, 2 * n + 1)) / (4 * pow(n, 2) - 1);
    return An;
}

int main(){
    char arrExit[] = {};
    std::string sExit;
    double epsilon;
    do{
    double alpha, x;
    std::cout << "Enter alpha: ";
    while(!(std::cin >> alpha) || std::cin.peek() != '\n' || alpha <= 0){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Incorrect input. Try again: ";
    }
    std::cout << "Enter x: ";
    while(!(std::cin >> x) || std::cin.peek() != '\n' || x > 1 || x < -1){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Incorrect input. Try again: ";
    }
    double sum = 0;
    if ((int)alpha == alpha) {
        for (int i = 1; i <= alpha; i++) {
            sum += equation(x, i);
            epsilon = abs(equation(x, i + 1) / sum);
            std::cout << "n = " << i << " An = " << equation(x, i) << " sum = " << sum << " EPSILONn = " << epsilon << '\n';
        }
        std::cout << " Sn = " << x + 2 * sum << std::endl;

    }
    else {
        int i = 1;
        do{
            sum += equation(x, i);
            epsilon = abs(equation(x, i + 1) / sum);
            std::cout << "\nn = " << i << " An = " << equation(x, i) << " sum = " << sum << " EPSILONn = " << epsilon << '\n';;
            i++;
        }while (epsilon > alpha);
        std::cout << " Sn = " << x + 2 * sum << std::endl;
    }
    std::cout << "Repeat the program?: " << std::endl;
    std::cout << "Yes- enter 'Yes'" << "\n" << "No- enter any key" << std::endl;
    sExit.clear();
    std::cin >> arrExit;
    for (int x = 0; x < strlen(arrExit); x++){
        sExit.push_back(tolower(arrExit[x]));
    }   
    }while(sExit == "yes");
}