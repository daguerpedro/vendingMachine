#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "products.h"

List* _products;

//TODO: Carregar do estoque
//TODO: Salvar no estoque
void loadProducts(List* productList)
{
    PRODUCT* product = malloc(sizeof(PRODUCT));
    strcpy(product->name, "Produto 1");
    product->price = 7.50f;
    product->stock = 5;

    pushList(productList, (void*)product);
    
    _products = productList;
}

// Para uso no stateMachine.
List* getProductList()
{
    return _products;
}
