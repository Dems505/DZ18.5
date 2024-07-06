// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class playerPoint 
{

public:
    void bubbleSort(int listLength)
    {
        int** list = new int* [listLength];
        for (int i = 0; i < 2; i++)
        {
            list[i] = new int[1];
        }
        for (int i = 0; i < listLength; i++)
        {
            std::cout << "Enter name " << i+1 << " player: ";
            std::cin >> list[i][0];
            std::cout << "Enter ponints " << i+1 << " player: ";
            std::cin >> list[i][1];
            system("cls");
        }
        while (listLength)
        {
            bool swapped = false;

            for (int i = 0; i < listLength - 1; i++)
            {
                if (list[i][1] < list[i + 1][1])
                {
                    std::swap(list[i + 1], list[i]);
                    swapped = true;
                }
            };
            if (swapped == false)
            {
                system("cls");
                for (int i = 0; i < listLength; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        std::cout << list[i][j];
                    }
                    std::cout << '\n';
                }
                for (int i = 0; i < listLength; i++)
                {
                    delete list[0];
                    list[i] = nullptr;
                }

                break;
            }
        }
    }
private:
    int nameCharacter, pointCharacter;
};


int main() 
{
    playerPoint countPlayer;
    int count = 0;
    std::cout << "Enter player count ";    
    std::cin >> count;

    countPlayer.bubbleSort(count);
}

