#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct {
    char name[50];
    char brand[50];
    char type[30];
    int year;
    double price;
    int warranty;
} Device_t;

int check_device(Device_t d, double max_price);
Device_t input_device(int number);
Device_t most_expensive(Device_t current, Device_t best);

int main() {
    setlocale(LC_CTYPE, "RUS");
    Device_t d1, d2, d3, d4, d5;
    double max_price_limit;
    Device_t best_device;
    int found_any = 0;
    best_device.price = 0.0;
    d1 = input_device(1);
    d2 = input_device(2);
    d3 = input_device(3);
    d4 = input_device(4);
    d5 = input_device(5);
    printf("\nВведите предельную цену для отбора: ");
    scanf("%lf", &max_price_limit);
    printf("\n=== РЕЗУЛЬТАТЫ ОТБОРА ===\n");
    best_device = d1;
    if (check_device(d1, max_price_limit) == 1 && (best_device = most_expensive(d1, best_device)).price) {
        printf("Устройство 1 подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d1.name, d1.price, d1.warranty);
        found_any = 1;
    }
    if (check_device(d2, max_price_limit) == 1 && (best_device = most_expensive(d2, best_device)).price) {
        printf("Устройство 2 подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d2.name, d2.price, d2.warranty);
        found_any = 1;
    }
    if (check_device(d3, max_price_limit) == 1 && (best_device = most_expensive(d3, best_device)).price) {
        printf("Устройство 3 подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d3.name, d3.price, d3.warranty);
        found_any = 1;
    }
    if (check_device(d4, max_price_limit) == 1 && (best_device = most_expensive(d4, best_device)).price) {
        printf("Устройство 4 подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d4.name, d4.price, d4.warranty);
        found_any = 1;
    }
    if (check_device(d5, max_price_limit) == 1 && (best_device = most_expensive(d5, best_device)).price) {
        printf("Устройство 5 подходит: %s, Цена: %.2f, Гарантия: %d мес.\n", d5.name, d5.price, d5.warranty);
        found_any = 1;
    }
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

Device_t input_device(int number) {
    Device_t d;
    printf("\n--- Ввод устройства №%d ---\n", number);
    printf("Название: "); scanf("%s", d.name);
    printf("Производитель: "); scanf("%s", d.brand);
    printf("Тип устройства: "); scanf("%s", d.type);
    printf("Год выпуска: "); scanf("%d", &d.year);
    printf("Цена: "); scanf("%lf", &d.price);
    printf("Гарантийный срок (в месяцах): "); scanf("%d", &d.warranty);
    return d;
}
int check_device(Device_t d, double max_price) {
    if (d.price <= max_price && d.warranty >= 24) {
        return 1;
    }
    else return 0;
}
Device_t most_expensive(Device_t current, Device_t best) {
    if (current.price > best.price) {
        return current;
    }
    return best;
}