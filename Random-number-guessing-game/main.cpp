
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 10

// تابع توليد عدد تصادفي با تعداد رقم n
int generate_random_number(int n, int digits[]) {
    int i, random_number = 0;
    int count[MAX_DIGITS] = {0};

    // براي اطمينان از عدم تکرار رقم‌ها، يک آرايه با مقدار اوليه صفر تعريف مي‌کنيم و در هر بار توليد رقم، مقدار متناظر با آن رقم در آرايه را يکي افزايش مي‌دهيم
    for (i = 0; i < n; i++) {
        int digit = rand() % 10;
        while (count[digit] > 0) {
            digit = rand() % 10;
        }
        digits[i] = digit;
        count[digit]++;
        random_number = random_number * 10 + digit;
    }
    return random_number;
}

// تابع مقايسه دو عدد و بررسي تعداد رقم‌هايي که درست حدس زده شده‌اند و تعداد رقم‌هايي که درست حدس زده شده‌اند و در مکان درست قرار دارند
void compare_numbers(int random_number, int guess_number[], int n, int *num_correct, int *num_correct_position) {
    int i, j;
    *num_correct = 0;
    *num_correct_position = 0;

    // تعداد رقم‌هايي که درست حدس زده شده‌اند را محاسبه مي‌کنيم
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (guess_number[i] == random_number % 10) {
                (*num_correct)++;
                break;
            }
            random_number /= 10;
        }
    }

    // تعداد رقم‌هايي که درست حدس زده شده‌اند و در مکان درست قرار دارند را محاسبه مي‌کنيم
    random_number = random_number * pow(10, n - 1);
    for (i = 0; i < n; i++) {
        if (guess_number[i] == random_number / (int)pow(10, n - 1 - i)) {
            (*num_correct_position)++;
        }
    }
}

int main() {
    int n, random_number, guess_number[MAX_DIGITS];
    int num_guesses = 0, num_correct = 0, num_correct_position = 0;
    char guess_string[MAX_DIGITS + 1];

    srand(time(NULL));

    // توليد عدد تصادفي با تعداد رقم n
    printf("Enter the number of digits (4-9): ");
    scanf("%d", &n);
    while (n < 4 || n > 9) {
        printf("Invalid input. Enter the number of digits (4-9): ");
        scanf("%d", &n);
    }
    random_number = generate_random_number(n, guess_number);

    // شروع بازي
    printf("I'm thinking of a %d-digit number. Can you guess what it is?\n", n);
    do {
        num_guesses++;

        // خواندن حدس کاربر
        printf("Guess #%d: ", num_guesses);
        scanf("%s", guess_string);
        while (strlen(guess_string) != n) {
            printf("Invalid input. Guess again: ");
            scanf("%s", guess_string);
        }

        // تبديل حدس کاربر به آرايه از اعداد
        for (int i = 0; i < n; i++) {
            guess_number[i] = guess_string[i] - '0';
        }

        // مقايسه حدس کاربر با عدد تصادفي
        compare_numbers(random_number, guess_number, n, &num_correct, &num_correct_position);

        // نمايش نتايج مقايسه
        printf("%d digits correct, %d digits in the correct position\n", num_correct, num_correct_position);
    } while (num_correct_position < n);

    // پايان بازي
    printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);

    return 0;
}
