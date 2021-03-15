﻿// S002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";


    
    char s[256]; //1 строка
    int to = 3; // от куда
    int lengt = 2; // сколько элементов
    char f[] = "%s";

    char m[514];
    __asm
    {
        //заполнение 1 строки
        lea esi, s
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi

        push edx
        mov edx, to

        lea ebx, s
        push ebx
        dec ebx

        //находим длину строки
        b1 :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz b1
            push ecx

            //проверяем, что длина была больше 0, чтобы начало удаление было больше 1, проверяем чтобы начало удаление было меньше длины строки, проверям, чтобы участок удаление входил в нашу строку.
            //если условия нарушаются, то переходим в b9 и выводим строку без изменений
        b2:
        cmp to, 1
            jl b9
            b3 :
        cmp lengt, 1
            jl b9

            b4 :
        cmp to, ecx
            jg b9

            add edx, lengt
            b5 :
        add ecx, 1
            cmp edx, ecx
            jg b9

            //удаляем элементы из строки
            add esp, 8
            mov ecx, 1
            dec esi

            lea esi, [s]
            lea edi, [m]
            push edi

            mov edx, to

            cmp edx, 2
            jl b12

            b6 :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne b6

            b12 :
        add edx, lengt


            b7 :
        inc esi
            inc ecx
            cmp ecx, edx
            jne b7

            b8 :
        lodsb
            stosb
            cmp al, 0
            jnz b8

            jmp b11

            //выводим не изменённую строку
            b9 :
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [s]
            lea edi, [m]
            push edi
            b10 :
        lodsb
            stosb
            cmp al, 0
            jnz b10


            b11 :
        pop edi
            pop esi

    }
    std::cout << m;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
