#include <stdio.h>
int countOfDigits(int n)
{
    //пока н не равно 0 отбрасываем последнюю цифру и к count_of_dg прибавляем 1
    if (!n) return 1;
    int count_of_dg = 0;
    while (n)
    {
        count_of_dg++;
        n /= 10;
    }
    return count_of_dg;
}

int rec_countOfDigits(int n)
{
    if (n / 10)
        return 1 + rec_countOfDigits(n / 10);
    else
        return 1;
    //если n не равно нулю вызываем функцию и отбрасываем последнюю цифру n,
    //при этом к возращаемому результату прибавляем 1, иначе завершаем рекурсию
}

int main() {
    int number;
    //считываем  число
    printf("Enter integer number: ");
    scanf("%d", &number);
    //вызываем обычную функцию и рекурсивную в том случае если н не 0
    //иначе просто выводим 1 без вызова функций
    printf("Count of digits:\n");
    printf("Cycle: %d\n", countOfDigits(number));
    printf("Recursion: %d\n", rec_countOfDigits(number));
    return 0;
}
