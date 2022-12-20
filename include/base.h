#pragma once

#include <map>
#include <string>
#include <ctime>
#include <iostream>

enum Color
{
    BLK, // Черный
    WTE, // Белый
    PNK, // Розовый
    GRE, // Зеленый
    BLU, // Синий
    GRY, // Серый
    ORG // Оранжевый
};

enum SizeType
{
    XS,
    S,
    M,
    L,
    XL,
    XXL,
    XXXL
};

enum Brand
{
    BL, // Balenciaga
    GC, // Gucci
    PD, // Prada
    LV, // Louis Vuitton
    MN, // Moncler
    DR, // Dior
    FD, // Fendi
    VR, // Versace 
};

enum Sex
{
    ML,
    FM
}; 

enum Category
{
    JN, //Jeans
    PN, // Pants
    ST, //Shirt
    TS, // T-shirt
    SR, // Shorts
}; 

class Object
{

public:
    Object();
    Object(bool autoArticle, int amount);
    ~Object();

    void addBase(std::string article, int amount);
    void removeBase(std::string article, int amount);
    void showBase() const;

    void addBasket(std::string article, int amount);
    void removeBasket(std::string article, int amount);
    void showBasket() const;

    std::string creatArticle();

private:
    std::map<std::string, int> base;
    std::map<std::string, int> basket;

    
};
