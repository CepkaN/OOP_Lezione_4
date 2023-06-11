#include<iostream>
#include<string>
#include<vector>

//class Client {
//private:
//	std::string _name;
//	int _id;
//	//static std::vector<Client*>_clients;           // Создание глобальной переменной внутри класса.
//
//	void ShowClient() {
//		std::cout << "Name : " << _name << '\n';
//		std::cout << "Id : " << _id << '\n';
//	}
//public:	
//	//Client(std::string name, int id) :_name(name), _id(id) {
//	//	_clients.push_back(this);
//	//}
//	Client(std::string name, int id, std::vector<Client*>& client) :_name(name), _id(id) {
//		client.push_back(this);
//	}
//	//static void ShowClients() {               // не требуется объект для вызова метода. (static)
//	//	for (const auto& it : _clients)
//	//		it->ShowClient();
//	//}
//	static void ShowClients(std::vector<Client*>& clients) {
//		for (const auto& it : clients)
//			it->ShowClient();
//	}
//};
//
////std::vector<Client*>Client::_clients;   // объявление наличия статическиго поля в классе Client.
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//
//
//	// Статические переменные.
//
//	std::vector<Client*>clients;
//
//	/*Client* client = new Client("Jhon", 34);
//	Client* client2 = new Client("Alex", 345);
//	Client* client3 = new Client("Olga", 3777);
//	Client::ShowClients(); */ // в классе Client вызываем метод вот этот.
//	//client->ShowClients(); 
//
//	//Ещё один способ.
//	Client* client = new Client("Jhon", 34, clients);
//	Client* client2 = new Client("Alex", 345, clients);
//	Client* client3 = new Client("Olga", 3777, clients);
//	Client::ShowClients(clients);
//
//
//
//
//
//
//	return 0;
//}

// SOLID

//S - принцип единой ответственности
//   один класс - одна функция.

//class ClientServer {
//public:
//	void ShowClients(std::vector<Client*>clients) {
//		for (const auto& it : clients)
//			it->Pay();
//	}
//};

// O - функция должна быть открыта для расширения и закрыта для модификации
//
//class Animal {
//private:
//	std::string _type;
//public:
//	Animal(std::string type):_type(type){ }
//
//	//std::string GetType()const {
//	//	return _type;
//	//}
//
//	virtual std::string GetSound() = 0; 
//
//
//};
//class Cow : public Animal {
//public:
//	Cow() :Animal("Cow"){}
//	std::string GetSound()override {
//		return "Mooo";
//	}
//};
//class Cat : public Animal {
//public:
//	Cat() :Animal("Cat") {}
//	std::string GetSound() override {
//		return "MRRR";
//	}
//};
//class Dog : public Animal {
//public:
//	Dog() :Animal("Dog") {}
//	std::string GetSound()override {
//		return "Gav";
//	}
//};
//
//// открыт для расширения, но закрыт для модификации.
//
//void AnimalSound(Animal& animal) {
//	/*if (animal.GetType() == "Lion")
//		std::cout << "RRRR";
//	else if (animal.GetType() == "Cat")
//		std::cout << "MRRR";
//	else if (animal.GetType() == "Dog")
//		std::cout << "Gav";
//	else if (animal.GetType() == "Cow")
//		std::cout << "Mooo";*/
//
//	// Так гораздо лучше и правильнее, чем сверху.
//	std::cout<<animal.GetSound() << "\n\n";
//}

class Vector {
private:
	int _size;
	int* _massivPtr;
public:
	Vector() {
		_size = 0;
		_massivPtr = nullptr;
	}
	void Push_back(int element) {
		_size++;
		int* newMassiv = new int[_size];
		if (_massivPtr == nullptr) {
			newMassiv[0] = element;
			_massivPtr = newMassiv;
			return;
		}
		for (int i = 0; i < _size - 1; i++)
			newMassiv[i] = _massivPtr[i];
		newMassiv[_size - 1] = element;

		int* temp = _massivPtr;

		_massivPtr = newMassiv;

		delete[]temp;

	}

	void ShowElements() {
		for (int i = 0; i < _size; i++)
			std::cout << i << " element : " << _massivPtr[i] << '\n';
	}
};
int main() {
	///*Cat* cat = new Cat();
	//Dog* dog = new Dog();
	//Cow* cow = new Cow();
	//AnimalSound(*dog);
	//AnimalSound(*cat);
	//AnimalSound(*cow);*/

	Vector* vector = new Vector();
	vector->Push_back(23);
	vector->Push_back(77);
	vector->Push_back(87);
	vector->Push_back(876);
	vector->Push_back(233);
	vector->ShowElements();


	return 0;
}