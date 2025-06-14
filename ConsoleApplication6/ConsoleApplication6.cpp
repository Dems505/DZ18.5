// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


class Player
{
public:
	string GetName()
	{
		return name;
	}
	Player(string newName, int newScore)
	{
		// Прередаем полученную информацию из строки 104 в переменные класса
		this->name = newName;
		this->score = newScore;
	}
	int GetScore()
	{
		return score;
	}
	
	Player();
	/*
	~Player();
	*/

	// Метод при помощи которого происходит сосртировка пользователей
	void shakersort(Player arr[], int end) {


		bool b = true;
		//Player* beg = first-1;
		//Player* end = first+size;
		int beg = -1;
		while (b) {
			b = false;
			beg++;
			// Перебираем массив из пользователей
			for (int i = beg; i < end; i++) {
				// Если кол-во очков i-го игрока больше чем i+1 , то мы меняем их местами
				// 
				// Была ошибка. Цикл выходил за границы масива и выдавал значение из 
				// несуществующей ячейки. Исправил путем добавления доп. условия. 
				if ((arr[i].score < arr[i + 1].score) && (arr[i+1].name != ""))
				{
					swap(*(arr + i), *(arr + i + 1));
					b = true;
				}
			}
			if (!b) break;
			end--;
			// Доп. проверка массива на правильность с конца массива
			for (int i = end; i > beg; i--) {
				if (arr[i].score > arr[i - 1].score)
				{
					swap(*(arr + i), *(arr + i + -1));
					b = true;
				}
			}
		}
	}
private:
	string name;
	int score;
};


// Конструктор по упомлчанию
Player::Player()
{
}

/* Не понял для чего этот конструктор
Player ::~Player()
{
}
*/


int main()
{
	int quant;
	// Получение информации от пользователя о кол-ве игроков
	cout << "Please enter the quantity of players" << endl;
	cin >> quant;

	// Создаем динамический экземпляр класса 
	Player* arr = new Player[quant];
	// Заполняем поочередно массив игроков 
	for (int i = 0; i < quant; i++)
	{
		string newName;
		int newScore;
		//Cпрашиваем информацию о игроках у пользователя
		cout << "Please enter the name of player #" << i + 1 << endl;
		cin >> newName;
		cout << "Please enter the score of player #" << i + 1 << endl;
		cin >> newScore;
		// Присваиваем информация об игроках в массив
		arr[i] = Player(newName, newScore);	
	}

	// Разименовываем указатель arr и передаем информацию в метод shakersort
	arr->shakersort(arr, quant);

	//Вывод элемментов массива в отсортированном порядке
	for (int i = 0; i < quant; i++)
	{

		cout << arr[i].GetName() << '\t' << arr[i].GetScore() << endl;

	}

	// Очистка выделенной памяти под дин. массив
	delete[] arr;
}

