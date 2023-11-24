#include <iostream>
#include <queue>
#include "Methods.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");

    double ans;
    int num = 0;

    while (true)
    {
        cout << "\t     Выбранный нтеграл \n\n" << "\t(x^3-1)^(-1/2) \n" << "\tНа интревале [1.3 ; 2.621] \n\n";
        cout << "Выберите способ решения: \n" << "1. Метод Трапеций \n" << "2. Метод Симсона \n\n";

        cin >> num;
        if (num == 1)
        {
            cout << "\tМетод Трапеций:\n";
            ans = calculate_trapezium_method(function, 1.3, 2.621, 1e-5);
            cout << ans << "\n";
        }
        if (num == 2)
        {
            cout << "\tMeтод Симсона:\n";
            ans = calculate_simson_method(function, 1.3, 2.621, 1e-5);
            cout << ans << "\n";
        }
        if (num != 1 && num != 2) {
            cout << "Выйти из программы" << endl;
            break;
        }
    }


}