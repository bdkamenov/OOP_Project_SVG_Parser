#define _CRT_SECURE_NO_WARNINGS
#include "Input.h"


Input & Input::getInstance()
{
	static Input obj;
	return obj;
}

bool Input::inputFromFile(std::ostream& out)
{
	out << "Enter file path: ";
	char pth[1024];
	std::cin.getline(pth, 1024);

	if (strlen(pth) <= _MAX_PATH)
	{
		strcpy(path, pth);
		input.open(path);
		out << path << " was successfully opened!\n";
		return true;
	}
	else
		out << "The path is too long!\n";
	return false;
}

bool Input::inputFromKeybord(std::istream& input)
{
	std::cout << "Enter figure data: ";

	input >> data.figType;
	input.ignore(32, ' ');

	switch (data.figType)
	{
	case 'l':
	case 'L':
		input >> data.data[0] >> data.data[1] >> data.data[2] >> data.data[3];
		return true;
		break;
	case 'r':
	case 'R':
		input >> data.data[0] >> data.data[1] >> data.data[2] >> data.data[3];
		input.get();
		input.getline(data.colour, 20);
		return true;
		break;
	case 'c':
	case 'C':
		input >> data.data[0] >> data.data[1] >> data.data[2];
		input.get();
		input.getline(data.colour, 20);
		return true;
		break;
	default:
		std::cerr << "Bad input!\n";
		return false;
		break;
	}
}

const char* Input::getHead() const
{
	return headData;
}

const DataForFigure& Input::getDataForFig() const
{
	return data;
}

const char * Input::getPath() const
{
	return path;
}

Input::Input()
	: headData(nullptr)
{
}

Input::~Input()
{
	delete[] headData;
	headData = nullptr;
}

bool Input::readFile(ShapeFactory& factory, ShapeArray& arr)
{
	if (input.good())
	{
		readHead();
		while (isContentRead())
		{
			arr.addShape(factory.whatToCreate(data), std::cout);
		}
		return true;
	}
	else
		return false;
}

void Input::readHead()
{
	char buff[1024];
	input.getline(buff, 1024);

	if (strstr(buff, "<svg>"))
	{
		return;
	}
	else
	{
		headData = new char[4096];
		headData[0] = '\0';
		strcat(headData, buff);

		while (true)
		{
			input.getline(buff, 1024);

			if (strstr(buff, "<svg>"))
				break;
			else if (!input)
			{
				inputError();
				break;
			}
			else
			{
				strcat(headData, "\n");
				strcat(headData, buff);
			}
		}
	}
}

void Input::inputError()
{
	std::cerr << "Bad input file!\nYou may continue with partial data!\n";
	input.close();
}

bool Input::isContentRead()
{
	DataForFigure newFigData;
	char lineBuff[512];
	char* token = nullptr;

	while (input.good())
	{
		memset(lineBuff, '\0', 512);
		input.getline(lineBuff, 512);
		token = strtok(lineBuff, "\"");

		if (strstr(lineBuff, "</svg>"))
		{
			input.close();
			return false;
		}
		else
		{
			if (strstr(token, "<line x1="))							// Line
			{
				newFigData.figType = 'l';

				token = strtok(nullptr, "\"");
				newFigData.data[0] = atof(token);					// base point
				token = strtok(nullptr, "\"");

				if (strstr(token, "y1="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[1] = atof(token);				// base point
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "x2="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[2] = atof(token);					// newFigData.data[2] = second point coord
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "y2="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[3] = atof(token);					// newFigData.data[3] = second point coord
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				data = newFigData;
				return true;

			}
			else if (strstr(token, "<rect x="))						// Rectangle
			{
				newFigData.figType = 'r';

				token = strtok(nullptr, "\"");
				newFigData.data[0] = atof(token);					// base point
				token = strtok(nullptr, "\"");

				if (strstr(token, "y="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[1] = atof(token);				// base point
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "width="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[2] = atof(token);				// newFigData.data[2] = width for Rect
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "height="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[3] = atof(token);				// newFigData.data[3] = height for Rect
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "fill="))
				{
					token = strtok(nullptr, "\"");
					strncpy(newFigData.colour, token, 19);
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				data = newFigData;
				return true;

			}
			else if (strstr(token, "<circle cx="))			// circle
			{
				newFigData.figType = 'c';

				token = strtok(nullptr, "\"");
				newFigData.data[0] = atof(token);
				token = strtok(nullptr, "\"");

				if (strstr(token, "cy="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[1] = atof(token);
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "r="))
				{
					token = strtok(nullptr, "\"");
					newFigData.data[2] = atof(token);
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				if (strstr(token, "fill="))
				{
					token = strtok(nullptr, "\"");
					strncpy(newFigData.colour, token, 19);
					token = strtok(nullptr, "\"");
				}
				else
				{
					inputError();
					return false;
				}

				data = newFigData;
				return true;

			}
			else
			{
				inputError();
				return false;
			}
		}
	}
	return false;
}