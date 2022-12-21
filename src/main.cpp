#include "base.h"
#include "menu.h"

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
			case 0:
				input = 0;
				break;
			case 1:

				break;
			case 2:

				modex.addBasket(buffer, amount);
				break;
			case 3:
				modex.showBase();
				break;
			case 4:
				modex.showBasket();
				break;
			case 5:
				modex.addBase(modex.creatArticle(), (1 + rand() % 10));
				break;
			case 6:

				std::cout << "Enter the item number to delete: ";
				std::cin.ignore();
				std::getline(std::cin, buffer);
				std::cout << "Enter the quantity of the item to be removed: ";
				std::cin >> amount;
				modex.removeBase(buffer, amount);
				break;
			case 7:
				break;
			default:
				std::cerr << "*** Invalid input ***" << std::endl;
				break;

			case 8:
				break;
			}


		}
		catch (const std::invalid_argument& ex)
		{
			std::cerr << ex.what() << std::endl;

		}
		catch (const std::runtime_error& ex)
		{
			std::cerr << ex.what() << std::endl;
		}
		menu();
		std::cout << "Your choice: ";
		std::cin >> input;
	}


	return 0;
}
