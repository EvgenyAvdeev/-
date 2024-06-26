#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdio.h>

#define var 1

#if var == 2

//--------------------- Функции с переменным числом аргументов -----------------------

/* У функции обязательно должен быть как минимум один обязательный аргумент.
Переменное число аргументов ставится после последнего обязательного аргумента.
Обратиться к переменному числу аргументов можно двумя способами:

1) Так как в памяти эти аргументы идут подряд после обязательного аргумента, то можно
получить адрес обязательного аргумента, а дальше перемещаться, однако предполагается что
размер у этих аргументов, такой же что и у обязательного.

2) Можно воспользоваться библиотекой stdarg.h. В этой библиотеке определены макрокоманды
для более простого обращения к переменному числу аргументов:

- void va_start(va_list param, последний_явный_параметр);
Первый параметр макроса - param связывает объект va_list с первым необязательным параметром.
Для его определения в качестве второго параметра в макрос передается последний обязательный параметр функции.

- type va_arg(va_list param, type);
Этот макрос позволяет получить значение параметра типа type, а также переместить указатель va_list на следующий необязательный параметр.

- void va_end(va_list param);
Макрос va_end позволяет выйти из функции с переменным списком параметров.

*/



//-------------------------------- ПРИМЕРЫ -------------------------------------------
// с использованием библиотеки
int sum_stdarg(int n, ...)
{
    int result = 0;
    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for (int i = 0; i < n; i++)
    {
        result += va_arg(factor, int);  // получаем значение текущего параметра типа int
    }
    va_end(factor); // завершаем обработку параметров
    return result;
}

// без использования библиотеки
int sum(int count, ...) {
    // указатель на первый аргумент после count
    int* p = &count + 1;
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += *p;  // добавить значение аргумента к сумме и перейти к следующему аргументу
        p++;
    }
    return total;
}



void main() {
    int sum_1, sum_2;
    sum_1 = sum(3, 10, 20, 30);
    sum_2 = sum_stdarg(3, 10, 20, 30);
    printf("sum_1 = %d\nsum_2 = %d", sum_1, sum_2);
}

#elif var==2

/*--------------------------- Хеширование ----------------------------------------------------

Один из лучших способов определить хэш-функцию от строки S:
h(S) = S[0] + S[1] * P + S[2] * P^2 + S[3] * P^3 + ... + S[N] * P^N
где P - некоторое число.
Разумно выбирать для P простое число, примерно равное количеству символов во входном алфавите.

Напомним, что хеш-функция должна иметь следующие свойства:
- всегда возвращает один и тот же адрес для одного и того же ключа
- не обязательно возвращает разные адреса для разных ключей
- использует все адресное пространство с одинаковой вероятностью
- быстро вычисляет адрес



------------------------------------- ПРИМЕР ---------------------------------------------------
*/
void main(){
    char s[100];
    gets(s);
    const int p = 31;
    long long hash = 0, p_pow = 1;
    for (size_t i = 0; i < strlen(s); ++i)
    {
    	// желательно отнимать 'a' от кода буквы
    	// единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
    	hash += (s[i] - 'a' + 1) * p_pow;
    	p_pow *= p;
    }
}
#endif

