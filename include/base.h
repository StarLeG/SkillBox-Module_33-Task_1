#pragma once

#include <map>
#include <string>
#include <ctime>
#include <iostream>
#include <stdlib.h>



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
    Object() = default;
    ~Object() = default;

    void addBase(const std::string& article,const  int amount);

    void removeBase(const std::string& article,const  int amount);

    void showBase() const;

    void addBasket(const std::string &article, const int amount);

    void removeBasket(const std::string& article,const  int amount);
    
    void showBasket() const;

	void pay();

    std::string creatArticle();

private:
    std::map<std::string, int> base;
    std::map<std::string, int> basket;

    
};
