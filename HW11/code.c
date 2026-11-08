#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

struct Device {
    char name[50];
    char brand[50];
    char type[30];
    int year;
    double price;
    int warranty;
};

struct Device input_device(int number) {
    struct Device d;
    printf("\n--- Ввод устройства №%d ---\n", number);

    printf("Название: ");
    scanf("%s", d.name);

    printf("Производитель: ");
    scanf("%s", d.brand);

    printf("Тип устройства: ");
    scanf("%s", d.type);

    printf("Год выпуска: ");
    scanf("%d", &d.year);

    printf("Цена: ");
    scanf("%lf", &d.price);

    printf("Гарантийный срок (в месяцах): ");
    scanf("%d", &d.warranty);

    return d;
}

void check_device(struct Device d, double max_price, struct Device* best, int* found) {
    if (d.price <= max_price && d.warranty >= 24) {
        printf("Подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d.name, d.price, d.warranty);

        if (*found == 0 || d.price > best->price) {
            *best = d;
            *found = 1;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    struct Device d1, d2, d3, d4, d5;
    double max_price_limit;

    struct Device best_device;
    int found_any = 0;

    d1 = input_device(1);
    d2 = input_device(2);
    d3 = input_device(3);
    d4 = input_device(4);
    d5 = input_device(5);

    printf("\nВведите предельную цену для отбора: ");
    scanf("%lf", &max_price_limit);

    printf("\n=== РЕЗУЛЬТАТЫ ОТБОРА ===\n");
    check_device(d1, max_price_limit, &best_device, &found_any);
    check_device(d2, max_price_limit, &best_device, &found_any);
    check_device(d3, max_price_limit, &best_device, &found_any);
    check_device(d4, max_price_limit, &best_device, &found_any);
    check_device(d5, max_price_limit, &best_device, &found_any);

    printf("\n=== САМОЕ ДОРОГОЕ УСТРОЙСТВО ИЗ ПОДХОДЯЩИХ ===\n");
    if (found_any == 1) {
        printf("Название: %s, Производитель: %s, Цена: %.2f, Гарантия: %d мес.\n",
            best_device.name, best_device.brand, best_device.price, best_device.warranty);
    }
    else {
        printf("Нет устройств, удовлетворяющих критериям.\n");
    }

    return 0;
}