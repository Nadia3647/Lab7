/*17. ����� � ������ ����������� ���������. ����������� ����� ����� �������, ����� ������
����� ������ ���� �������� � �������� �������.*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>

using namespace std;
char* funcs(char str[100])//������ �������, ������� ����� �������������� ������ ��������� �����, ��������� ��������, � ������� ��������������� ������� ���� char
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
        cout << "�������� �������� (1 - ������, 0 - ���������)" << endl;
        cin >> chek;
        switch (chek)
        {
        case(0):
        {
            cout << "��������� ���������" << endl;
            break;
        }
        case(1):
        {
            ifstream fin; 
            SetConsoleCP(CP_UTF8);// ������������� ���������
            SetConsoleOutputCP(CP_UTF8);
            fin.open("test.txt");// ��������� ���� � ��������
            if (!fin.is_open())// ��������� ������������ �������� �����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                cout << "������ ������ �� �����" << endl;
                char fs[50];
                while (!fin.eof()) // ����, ����� ��������� ���� �� ����� � �������� �� �����
                {
                    fin.getline(fs, 50);
                    cout << fs << endl;
                }
                cout << "������������� ������ �� �����" << endl;
                    funcs(fs); // ����� �������
            }
            char st[100];
            SetConsoleCP(1251); // ������������ ������� ���������
            SetConsoleOutputCP(1251);
            cout << "������� ����������� ������" << endl;
            cin.ignore(); // ���������� /n � ��������� ������ ������
            cin.getline(st, 100); 
            
            cout << "������������� ������" << endl;
            funcs(st); // ����� �������
            break;
        }

        default:
        {
            cout << "����������� �������� ������" << endl;
            chek = 1;
            continue;
        }
        }


        
    }
}
   
