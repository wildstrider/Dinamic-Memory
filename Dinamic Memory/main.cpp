#include <iostream>

using namespace std;
#define tab "\t"
int buf = 0;


void Fill_arr(int arr[], int size);
void Print_arr(int arr[], int size);

void  push_front(int arr[], int buffer[], int buf, int size, int elem, int quant);
void push_back(int arr[], int buffer[], int buf, int size, int elem, int quant);
void  insert(int arr[], int buffer[], int buf, int elem, const int q, int quant, int index, int in);
int* Add_element(int arr[], int size);

void  pop_back(int arr[], int buffer[], int buf);
void pop_front(int arr[], int buffer[], int buf, int quant);
void erase(int arr[], int buffer[], int size, int index, int quant);
int* Delete_element(int arr[], int size);

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "Введите размер массива: "; cin >> size;
	int* arr = new int[size] {};

	Fill_arr(arr, size);
	Print_arr(arr, size);

	cout << "Выберите действие."
		"\n1 - Добавление в массив элементов."
		"\n2 - Удаление из массива элементов" << endl;

	int choice; cin >> choice;

	switch (choice)
	{
	case 1:
		arr = Add_element(arr, size);
		break;
	case 2:
		arr = Delete_element(arr, size);
	}
	size = buf;
	Print_arr(arr, size);
	delete[] arr;

	return 0;
}


void Fill_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {

		arr[i] = rand() % 100;
	}
}
void Print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++) {

		std::cout << arr[i] << tab;
	}
	cout << endl;
}

void  push_front(int arr[], int buffer[], int buf, int size, int elem, int quant)
{
	for (int i = buf - 1; i >= 0; i--) {

		size--;
		if (i >= i - size) {
			buffer[i] = arr[size];
		}
		if (i < quant)
			buffer[i] = elem;
	}
}
void push_back(int arr[], int buffer[], int buf, int size, int elem, int quant)
{
	for (int i = 0; i < buf; i++) {

		if (i < size) {
			buffer[i] = arr[i];
		}
		if (i == buf - quant) {
			buffer[i] = elem;
		}
	}
}
void  insert(int arr[], int buffer[], int buf, int elem, const int q, int quant, int index, int in)
{
	for (int i = 0; i < buf; i++) {

		if (i < index && q == quant) {
			buffer[i] = arr[i];
		}
		if (i == index) {
			buffer[i] = elem;
		}
		if (i > index) {
			buffer[i] = arr[in++];
		}
	}
}
int* Add_element(int arr[], int size)
{
	int quant;
	cout << "Введите количество добавляемых элементов: "; cin >> quant;
	buf = size + quant;
	const int q = quant;
	int* buffer = new int[buf] {};
	cout << "Выберите в какую часть массива добавить элемент."
		"\n1 - В начало массива"
		"\n2 - В конец массива"
		"\n3 - По указанному индексу" << endl;
	int choice; cin >> choice;
	int elem = 0;
	switch (choice)
	{
	case 1:
		cout << "Введите добавляемый элемент" << endl;
		while (quant > 0)
		{
			cin >> elem;
			push_front(arr, buffer, buf, size, elem, quant--);
		}
		break;
	case 2:
		cout << "Введите добавляемый элемент" << endl;
		while (quant > 0)
		{
			cin >> elem;
			push_back(arr, buffer, buf, size, elem, quant--);
		}
		break;
	case 3:
		int index;
		if (quant > 1) {
			cout << "Введите с какого индекса добавлять элементы: ";
		}
		else
			cout << "Введите по какому идексу добавить элемент." << endl;
		cin >> index;
		while (index > size)
		{
			cout << "Превышен размер массива!! Попробуйте еще раз: "; cin >> index;
		}
		int in = index;
		cout << "Введите добавляемый элемент" << endl;
		while (quant > 0)
		{
			cin >> elem;
			insert(arr, buffer, buf, elem, q, quant--, index++, in);
		}
	}

	delete[] arr;
	arr = buffer;
	return arr;
}

void  pop_back(int arr[], int buffer[], int buf)
{
	for (int i = 0; i < buf; i++) {

		buffer[i] = arr[i];
	}
}
void pop_front(int arr[], int buffer[], int buf, int quant)
{
	for (int i = 0; i < buf; i++) {

		buffer[i] = arr[quant++];
	}
}
void erase(int arr[], int buffer[], int size, int index, int quant)
{
	int temp = index + quant;
	for (int i = 0; i < size; i++) {

		if (i < index) {
			buffer[i] = arr[i];
		}
		if (i >= temp) {
			buffer[index++] = arr[i];
		}
	}
}
int* Delete_element(int arr[], int size)
{
	int quant;
	cout << "Введите количество удаляемых элементов: "; cin >> quant;
	while (quant >= size)
	{
		cout << "Превышен размер массива!!!! Попробуйте ещ раз: "; cin >> quant;
	}
    buf = size - quant;
	int* buffer = new int[buf] {};
	if (quant > 1) {
		cout << "Выберите из какой части массива удалить элементы." << endl;
	}
	else
		cout << "Выберите из какой части массива удалить элемент." << endl;

	cout << "1 - начало массива"
		"\n2 - конец массива"
		"\n3 - По указанному индексу" << endl;
	int choice; cin >> choice;
	switch (choice)
	{
	case 1:
		pop_front(arr, buffer, buf, quant);
		break;
	case 2:
		pop_back(arr, buffer, buf);
		break;
	case 3:
		if (quant > 1) {
			cout << "Введите с какого индекса начать удалять элементы: ";
		}
		else
			cout << "Введите по какому идексу удалить элемент." << endl;
		 int index; cin >> index;

		while (index > size - quant)
		{
			cout << "Невозможно удалить такое количство элементов!!!! Попробуйте выбрать другую ячейку: "; cin >> index;

		}
		erase(arr, buffer, size, index, quant);
		
	}

	delete[] arr;
	arr = buffer;
	return arr;
}
