#include <iostream>
int length(int n);
int result(int a);
int main(){
    std::cout << "Digital root" << '\n';
    char chExit;
    do{
    int value;
    std::cout << "Input a nonnegative integer>";
    while(!(std::cin >> value) || abs(value) != value){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Incorrect input! Try again: " << '\n';
    }   
    while (length(value) != 1){
        value = result(value);
    }
    std::cout << "Result: " << value << '\n';
    std::cout << "Continue? (Y/N) >";
    std::cin >> chExit;
    }while(chExit == 'Y' || chExit == 'y');
}
int length(int n) {
    int l = 0;
    do {
        l++;
        n /= 10;
    } while(n);
    return l;
}
int result(int a){
    int b = 0;
    while(a != 0){
        b += a % 10;
        a = a / 10;
    }
    return b;
}