//
// Created by stas_malikov on 20.08.2020.
//

#include "Product.h"


string Product::toString() {
    return to_string(id) + " " + title + " " +
        to_string(quantity) + " " +
        Product::productTypeToStr(productType);
}

string Product::productTypeToStr(ProductType _productType) {
    switch (_productType) {
        case ProductType::meat: {
            return "meat";
        }

        case ProductType::dairy: {
            return "dairy";
        }

        case ProductType::bakery: {
            return "bakery";
        }
    }

    return string();
}