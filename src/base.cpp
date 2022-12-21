#include "base.h"

void Object::addBase(const std::string &article, const int amount)
{
    if (this->base.find(article) == this->base.end())
    {
        this->base.insert(std::make_pair(article, amount));
    }
    else
    {
        this->base.find(article)->second++;
    }
}

void Object::removeBase(const std::string &article, const int amount)
{
    if (this->base.find(article) == this->base.end())
    {
        throw std::runtime_error("Item not found.");
        return;
    }

    if ((this->base.find(article)->second - amount) < 0)
    {
        throw std::invalid_argument("amount < 0");
        return;
    }

    if ((this->base.find(article)->second - amount) >= 0)
    {
        (this->base.find(article)->second) -= amount;
        
    }

    if (this->base.find(article)->second == 0)
    {
        this->base.erase(this->base.find(article));
        
    }
}

void Object::showBase() const
{
    if (this->base.empty())
    {
        throw std::runtime_error("There are no goods in the store base.");
    }
    else
    {
        for (auto it = this->base.begin(); it != this->base.end(); it++)
        {
            std::cout << it->first << " ------ " << it->second << std::endl;
        }
    }
}

void Object::addBasket(const std::string &article, const int amount)
{
    if (this->base.empty())
    {
        throw std::runtime_error("The base of the store is empty");
        return;
    }

    if (this->base.find(article) == this->base.end())
    {
        throw std::runtime_error("Products are not in the store database.\n");
        return;
    }

    if (this->base.find(article) != this->base.end())
    {
        this->basket.insert(std::make_pair(article, amount));
    }
    else
    {
        this->basket.find(article)->second++;
    }
    
}

void Object::removeBasket(const std::string &article, const int amount)
{
    if (this->basket.find(article) == this->basket.end())
    {
        throw std::runtime_error("Item not found.");
        return;
    }

    if (this->basket.find(article)->second - amount < 0)
    {
        throw std::invalid_argument("amount < 0");
        return;
    }

    if ((this->basket.find(article)->second - amount) >= 0)
    {
        (this->basket.find(article)->second) -= amount;

    }

    if ((this->basket.find(article)->second) == 0)
    {
        this->basket.erase(this->basket.find(article));

    }
}

void Object::showBasket() const
{
    if (this->basket.empty())
    {
        throw std::runtime_error("There are no goods in the basket.");
    }
    else
    {
        for (auto it = this->basket.begin(); it != this->basket.end(); it++)
        {
            std::cout << it->first << " ------ " << it->second << std::endl;
        }
    }
}

void Object::pay()
{
    if(this->basket.empty())
    {
        throw std::runtime_error("The basket is empty");
        return;
    }
        this->basket.clear();

}

std::string Object::creatArticle()
{
    srand(std::time(nullptr));

    std::string article;
    std::string buffer;

    // генерируем бренд
    int brend = rand() % 7;

    // генерируем категорию
    int category = rand() % 4;

    // генерируем пол
    int sex = rand() % 1;

    // генерируем цвет
    int color = rand() % 6;

    // генерируем размер
    int size = rand() % 6;

    switch (brend)
    {
    case Brand::BL:
        buffer = "BL";
        break;
    case Brand::DR:
        buffer = "DR";
        break;
    case Brand::FD:
        buffer = "FD";
        break;
    case Brand::GC:
        buffer = "GC";
        break;
    case Brand::LV:
        buffer = "LV";
        break;
    case Brand::MN:
        buffer = "MN";
        break;
    case Brand::PD:
        buffer = "PD";
        break;
    case Brand::VR:
        buffer = "VR";
        break;
    default:
        break;
    }

    article = buffer;
    buffer.clear();

    switch (category)
    {
    case Category::JN:
        buffer = "JN";
        break;
    case Category::PN:
        buffer = "PN";
        break;
    case Category::SR:
        buffer = "SR";
        break;
    case Category::ST:
        buffer = "ST";
        break;
    case Category::TS:
        buffer = "TS";
        break;

    default:
        break;
    }

    article += ("-" + buffer);
    buffer.clear();

    switch (sex)
    {
    case Sex::ML:
        buffer = "ML";
        break;
    case Sex::FM:
        buffer = "FM";
        break;

    default:
        break;
    }

    article += ("-" + buffer);
    buffer.clear();

    switch (color)
    {
    case Color::BLK:
        buffer = "BLK";
        break;
    case Color::BLU:
        buffer = "BLU";
        break;
    case Color::GRE:
        buffer = "GRE";
        break;
    case Color::GRY:
        buffer = "GRY";
        break;
    case Color::ORG:
        buffer = "ORG";
        break;
    case Color::PNK:
        buffer = "PNK";
        break;
    case Color::WTE:
        buffer = "WTE";
        break;

    default:
        break;
    }

    article += ("-" + buffer);
    buffer.clear();

    switch (size)
    {
    case SizeType::L:
        buffer = "L";
        break;
    case SizeType::M:
        buffer = "M";
        break;
    case SizeType::S:
        buffer = "S";
        break;
    case SizeType::XL:
        buffer = "XL";
        break;
    case SizeType::XS:
        buffer = "XS";
        break;
    case SizeType::XXL:
        buffer = "XXL";
        break;
    case SizeType::XXXL:
        buffer = "XXXL";
        break;

    default:
        break;
    }

    article += ("-" + buffer);
    buffer.clear();

    return article;
}
