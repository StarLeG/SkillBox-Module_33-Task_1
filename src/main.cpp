#include "base.h"
#include "menu.h"
#include <regex>
#include <string>

bool is_valid_article(std::string &str)
{
	const std::regex txt_regex("[A-Z]{2}-[A-Z]{2}-[A-Z]{2}-[A-Z]{3}-[A-Z]{1}");

	return std::regex_match(str, txt_regex);
}

int main()
{

	Object modex;
	int input = -1;
	int cnt = 0;
	int amount = 0;
	std::string buffer;
	std::cout << "Welcome to MODEX online store." << std::endl;
	menu();
	std::cout << "Your choice: ";
	std::cin >> input;
	while (input != 0)
	{
		try
		{
			switch (input)
			{
			case 0: // EXIT
				input = 0;
				break;
			case 1: // Add a product to the store database
				std::cout << "Enter the article in the format <XX>-<XX>-<XX>-<XXX>-<X> :";
				std::cin.ignore();
				std::getline(std::cin, buffer);
				if (!(is_valid_article(buffer)))
				{
					throw std::invalid_argument("Not correct article");
					break;
				}
				std::cout << "Enter Quantity: ";
				std::cin >> amount;

				if (amount < 0)
				{
					throw std::invalid_argument("Amount < 0");
					break;
				}

				modex.addBase(buffer, amount);
				break;
			case 2: // Add item to cart
				std::cout << "Enter the article in the format <XX>-<XX>-<XX>-<XXX>-<X> :";
				std::cin.ignore();
				std::getline(std::cin, buffer);
				if (!(is_valid_article(buffer)))
				{
					throw std::invalid_argument("Not correct article");
					break;
				}

				std::cout << "Enter Quantity: ";
				std::cin >> amount;

				if (amount < 0)
				{
					throw std::invalid_argument("Amount < 0");
					break;
				}

				modex.addBasket(buffer, amount);
				modex.removeBase(buffer, amount);
				break;
			case 3: // Display products from the store database
				modex.showBase();
				break;
			case 4: // Display an item from the shopping cart
				modex.showBasket();
				break;
			case 5: // Automatic addition of goods to the store database
				modex.addBase(modex.creatArticle(), (1 + rand() % 10));
				break;
			case 6: // Delete a product from the store database

				std::cout << "Enter the item number to delete: ";
				std::cin.ignore();
				std::getline(std::cin, buffer);
				if (!(is_valid_article(buffer)))
				{
					throw std::invalid_argument("Not correct article");
					break;
				}
				std::cout << "Enter the quantity of the item to be removed: ";
				std::cin >> amount;
				if (amount < 0)
				{
					throw std::invalid_argument("Amount < 0");
					break;
				}
				modex.removeBase(buffer, amount);
				break;
			case 7: // Remove item from cart
				std::cout << "Enter the item number to delete: ";
				std::cin.ignore();
				std::getline(std::cin, buffer);
				if (!(is_valid_article(buffer)))
				{
					throw std::invalid_argument("Not correct article");
					break;
				}
				std::cout << "Enter the quantity of the item to be removed: ";
				std::cin >> amount;
				if (amount < 0)
				{
					throw std::invalid_argument("Amount < 0");
					break;
				}
				modex.removeBasket(buffer, amount);
				modex.addBase(buffer, amount);
				break;
			case 8: // Paying for items in the cart
				modex.pay();
				break;
			default:
				throw std::runtime_error("*** Invalid input command ***");
				break;
			}
		}
		catch (const std::invalid_argument &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
		catch (const std::runtime_error &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
		menu();
		std::cout << "Your choice: ";
		std::cin >> input;
	}

	return 0;
}
