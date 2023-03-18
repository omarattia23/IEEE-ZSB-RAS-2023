/*
For the previous problem make the union a struct instead then print the size of the parent struct and compare with the size of the previous union…Explain why the two
sizes are different
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shops {
    char name[50];
    char location[50];
};

struct product_info {
    int id;
    float price;
    int quantity;
};

struct category {
    int id;
    int products_num;
};

struct database {
    struct shops shop;
    struct product_info product_info;
    struct category category;
};

int main() {
    struct database data;
    memset(&data, 0, sizeof(data));
    strcpy(data.shop.name, "My Shop");
    strcpy(data.shop.location, "My Location");
    data.product_info.id = 012345;
    data.product_info.price = 11;
    data.product_info.quantity = 10;
    data.category.id = 6789;
    data.category.products_num = 100;
    printf("-------------------------------------------------------------\n");
    printf("Size of struct database     : %zu bytes\n", sizeof(struct database));
    printf("Size of struct shops        : %zu bytes\n", sizeof(struct shops));
    printf("Size of struct product_info : %zu bytes\n", sizeof(struct product_info));
    printf("Size of struct category     : %zu bytes\n", sizeof(struct category));
    printf("-------------------------------------------------------------\n");
    printf("Explantion of the difference: is the size beacause a union only stores one member at a time,\nwhereas a struct stores all members at the same time.\nTherefore, the size of a union is equal to the size of its largest member,\nwhereas the size of a struct is equal to the sum of the sizes of all its members.\n");
    printf("-------------------------------------------------------------\n");
    return 0;
}
