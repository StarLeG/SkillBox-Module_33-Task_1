#include "base.h"

Object::Object(/* args */)
{
}

Object::~Object()
{
}

void Object::addBase(std::string article, int amount)
{
	if(this->base.find(article) == this->base.end())
	{
		this->base.insert(std::make_pair(article, amount));
	}
	else
	{
		this->base.find(article)->second++;
	}

}
void Object::removeBase(std::string article, int amount)
{

}
void Object::showBase() const
{
    for (auto it = this->base.begin(); it != this->base.end(); it++)
    {
        std::cout << it->first << " ------ " << it->second << std::endl;
    }
}

void Object::addBasket(std::string article, int amount)
{
}
void Object::removeBasket(std::string article, int amount)
{
}
void Object::showBasket() const
{
}

std::string Object::creatArticle()
{
    std::string article;
    std::string buffer;
    srand(std::time(nullptr));
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

