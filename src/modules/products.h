#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <list.h>

typedef struct PRODUCT
{
    char name[25];
    float price;
    int stock;
} PRODUCT;

void loadProducts(List* productList);
List* getProductList();

#endif
