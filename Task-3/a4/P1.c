/*
Create a union named database that stores the following structures : 
o shops of { name, location } 
o product_info of { id , price ,quantity } 
o category of { id ,products_num } 
Then create an object of this union 
and print the size of the union and each struct
inside it.
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

union database {
    struct shops shop;
    struct product_info product_info;
    struct category category;
};

int main() {
    union database data;
    memset(&data, 0, sizeof(data));
    strcpy(data.shop.name, "My Shop");
    strcpy(data.shop.location, "My Location");
    data.product_info.id = 012345;
    data.product_info.price = 11;
    data.product_info.quantity = 10;
    data.category.id = 6789;
    data.category.products_num = 100;

    printf("-------------------------------------------------------------\n");
    printf("Size of union database      : %zu bytes\n", sizeof(union database));
    printf("Size of struct shops        : %zu bytes\n", sizeof(struct shops));
    printf("Size of struct product_info : %zu bytes\n", sizeof(struct product_info));
    printf("Size of struct category     : %zu bytes\n", sizeof(struct category));
    printf("-------------------------------------------------------------\n");
    return 0;
}
