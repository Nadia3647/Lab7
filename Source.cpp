/*17. Слова в строке разделяются пробелами. Зашифровать текст таким образом, чтобы каждое
слово текста было записано в обратном порядке.*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>

using namespace std;
char* funcs(char str[100])//создаём функцию, которая будет переворачивать каждое отдельное слово, отделённое пробелом, с помощью дополнительного массива типа char
{
    char temp;
    int i, j, k, len;
    len = strlen(str);

    for (i = 0, j = 0; i < len; i++) {

        if (str[i] == ' ' || i == len - 1) {

            if (i < len - 1) {
                k = i - 1;
            }
            else {
                k = i;
            }

            while (k > j) {
                temp = str[j];
                str[j] = str[k];
                str[k] = temp;
                j++;
                k--;
            }

            j = i + 1;
        }
    }
    cout << str << endl;
    
    return str;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int chek = 1;
    while (chek == 1)
    {
        cout << "Выберите действие (1 - расчёт, 0 - остановка)" << endl;
        cin >> chek;
        switch (chek)
        {
        case(0):
        {
            cout << "Программа завершена" << endl;
            break;
        }
        case(1):
        {
            ifstream fin; 
            SetConsoleCP(CP_UTF8);// Устанавливаем кодировку
            SetConsoleOutputCP(CP_UTF8);
            fin.open("test.txt");// Открываем файл с примером
            if (!fin.is_open())// Проверяем правильность открытия файла
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                cout << "Пример строки из файла" << endl;
                char fs[50];
                while (!fin.eof()) // цикл, будет считывать файл до конца и выводить на экран
                {
                    fin.getline(fs, 50);
                    cout << fs << endl;
                }
                cout << "Зашифрованная строка из файла" << endl;
                    funcs(fs); // вызов функции
            }
            char st[100];
            SetConsoleCP(1251); // установление русской кодировки
            SetConsoleOutputCP(1251);
            cout << "Введите собственный пример" << endl;
            cin.ignore(); // игнорирует /n и позволяет ввести строку
            cin.getline(st, 100); 
            
            cout << "Зашифрованная строка" << endl;
            funcs(st); // вызов функции
            break;
        }

        default:
        {
            cout << "Неправильно введеные данные" << endl;
            chek = 1;
            continue;
        }
        }


        
    }
}
   
