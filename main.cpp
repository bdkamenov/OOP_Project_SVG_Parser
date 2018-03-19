#include <iostream>
#include <fstream>
#include <cstring>
#include "Circle.h"
#include "Input.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "Output.h"

int getChoice()
{
	int choice;
	std::cin >> choice;
	return choice;
}


void displayMenu()
{
	std::cout << "************************************************************\n\n"
		<< "What would you like to do:\n"
		<< "1. Create figures from standart input\n"
		<< "2. Create figures from SVG file\n"
		<< "3. Erase figure\n"
		<< "4. Print figures\n"
		<< "5. Check if figures are within\n"
		<< "6. Transate figures\n"
		<< "7. Save\n"
		<< "8. Save as\n"
		<< "9. Print the menu\n"
		<< "10. Exit the program\n\n"
		<< "************************************************************\n";
}

void menu()
{
	Input& input = Input::getInstance();
	ShapeFactory& factory = ShapeFactory::getInstance();
	static ShapeArray figures;
	Output& output = Output::getInstance();
	int choice = 0;

	displayMenu();
	do
	{
		choice = getChoice();
		std::cin.get();

		switch (choice)
		{
		case 1:
			if (input.inputFromKeybord(std::cin))
				figures.addShape(factory.whatToCreate(input.getDataForFig()), std::cout);
			break;

		case 2:
			if (input.inputFromFile(std::cout))
			{
				input.readFile(factory, figures);
			}
			break;

		case 3:
			std::cout << "Enter index of figure: ";
			int index;
			std::cin >> index;
			figures.removeShape(index, std::cout);
			break;

		case 4:
			figures.printShapes(std::cout);
			break;

		case 5:
			if (input.inputFromKeybord(std::cin))
			{
				switch (input.getDataForFig().figType)
				{
				case 'r':
				case 'R':
					figures.printWithinRectangle(dynamic_cast<Rectangle*>(factory.whatToCreate(input.getDataForFig())), std::cout);
					break;
				case 'c':
				case 'C':
					figures.printWithinCircle(dynamic_cast<Circle*>(factory.whatToCreate(input.getDataForFig())), std::cout);
					break;
				}
			}
			break;
			
		case 6:
			double horizont;
			double vertical;

			if (std::cin >> index)
			{
				std::cin.ignore(32, '=');
				std::cin >> horizont;

				std::cin.ignore(32, '=');
				std::cin >> vertical;
				figures.translateOne(index, horizont, vertical);
				
			}
			else
			{
				std::cin.clear();

				std::cin.ignore(32, '=');
				std::cin >> horizont;

				std::cin.ignore(32, '=');
				std::cin >> vertical;
				figures.translateAll(horizont, vertical);
			
			}
			break;
			
		case 7:
			output.save(input, figures);
			break;

		case 8:
			output.saveAs(input, figures);
			break;

		case 9:
			displayMenu();
			break;

		case 10:
			std::cout << "Exiting the program ...\n";
			break;

		default:
			std::cout << "Bad command!\n";
			std::cin.clear();
			std::cin.ignore(100000);

			break;
		}
	} while (choice != 10);
}

//C:\Users\Darry\Desktop\ex.svg

int main()
{
	menu();
}