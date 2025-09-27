#include <iostream>
using namespace std;

class Person {
	string name;
	string surname;
	int age;
public:
	void SetName(string name) {
		this->name = name;
	}

	void SetSurname(string surname) {
		this->surname = surname;
	}

	void SetAge(int age) {
		if (age < 0 || age > 126) this->age = 18;
		else this->age = age;
	}

	string GetName() const {
		return name;
	}

	string GetSurname() const {
		return surname;
	}

	int GetAge() const {
		return age;
	}

	Person() {
		name = "Oleksandr";
		surname = "Zahoruiko";
		age = 36;
	}

	Person(string name, string surname, int age) {
		SetName(name);
		SetSurname(surname);
		SetAge(age);
	}

	void Print() const {
		cout << "Name: " << name << "\n";
		cout << "Surname: " << surname << "\n";
		cout << "Age: " << age << "\n";
	}
};

class Student : public Person {
	string avg_rate;
	int rates[50];
	string zalik_book;
public:
	Student() {
		rates[0] = 12;
		zalik_book = "AA00001";
	}

	Student(string name, string surname, int age) : Person(name, surname, age)
	{
		rates[0] = 12;
		zalik_book = "AA00001";
	}

	Student(string name, string surname, int age, int* rates, string zalik_book) : Person(name, surname, age) {
		// SetName(name);
		// SetSurname(surname);
		// SetAge(age);
		SetRates(rates);
		SetZalikBook(zalik_book);
	}

	void SetAvgRate(string avg_rate)
	{
		this->avg_rate = avg_rate;
	}

	void SetRates(int rates[])
	{
		for (int i = 0; i < 50; i++)
		{
			this->rates[i] = rates[i];
		}
	}

	void SetZalikBook(string zalik_book)
	{
		this->zalik_book = zalik_book;
	}

	string GetAvgRate()
	{
		return avg_rate;
	}

	int GetRate(int index)
	{
		if (index >= 0 && index < 50)
			return rates[index];
	}

	string GetZalikBook()
	{
		return zalik_book;
	}

	void Print() const {
		Person::Print();
		cout << "Rate: " << rates[0] << "\n";
		cout << "ZB: " << zalik_book << "\n\n";
	}
};

class Aspirant : public Student
{
	string candidate_theme;

public:
	
	Aspirant()
	{
		candidate_theme = "C++";
	}

	Aspirant(string name, string surname, int age, int* rates, string zalik_book, string theme) 
		: Student(name, surname, age, rates, zalik_book)
	{
		SetCandTheme(theme);
	}

	void SetCandTheme(string candidate_theme)
	{
		this->candidate_theme = candidate_theme;
	}

	string GetCandTheme()
	{
		return candidate_theme;
	}

	void Print() const
	{
		Student::Print();
		cout << "candidate theme: " << candidate_theme << "\n\n";
	}
};

int main()
{
	int rates[50]{ 10, 11, 12 };

	Student n1;
	n1.Print();
	Student n2("Karina", "Zinovieva", 16, rates, "ABCDE");
	n2.Print();

	Aspirant first;
	first.Print();
}