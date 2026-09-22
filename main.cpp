#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
class Person
{
    string firstName;
    string lastName;
    int age;
 
public:
 
    // Wczytywanie z klawiatury
    void read()
    {
        cin >> firstName >> lastName >> age;
    }
 
    // Wczytywanie z pliku
    void readFromFile(ifstream &file)
    {
        file >> firstName >> lastName >> age;
    }
 
    // Wypisywanie na ekran
    void display()
    {
        cout << firstName << " "
<< lastName << " "
<< age << endl;
    }
 
    // Zapisywanie do pliku
    void saveToFile(ofstream &file)
    {
        file << firstName << " "
<< lastName << " "
<< age << endl;
    }
 
    // Pobieranie nazwiska do sortowania
    string getLastName()
    {
        return lastName;
    }
};
 
int main()
{
    Person students[30];
 
    ifstream file("uczniowie.txt");
 
    if (!file)
    {
        cout << "Nie mozna otworzyc pliku uczniowie.txt!" << endl;
        return 0;
    }
 
    int count = 0;
 
    // Wczytywanie maksymalnie 30 osob
    while (count < 30 && file)
    {
        students[count].readFromFile(file);
 
        if (file)
            count++;
    }
 
    file.close();
 
    // Sortowanie wedlug nazwiska
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].getLastName() >
                students[j + 1].getLastName())
            {
                Person temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
 
    // Wyświetlanie wyniku w konsoli
    cout << "=================================" << endl;
    cout << "       POSORTOWANI UCZNIOWIE" << endl;
    cout << "=================================" << endl;
 
    for (int i = 0; i < count; i++)
    {
        students[i].display();
    }
 
    // Zapisywanie do pliku
    ofstream outputFile("wynik.txt");
 
    if (!outputFile)
    {
        cout << "Nie mozna utworzyc pliku wynik.txt!" << endl;
        return 0;
    }
 
    for (int i = 0; i < count; i++)
    {
        students[i].saveToFile(outputFile);
    }
 
    outputFile.close();
 
    // Informacja w konsoli
    cout << "=================================" << endl;
    cout << "Wynik zostal zapisany do pliku wynik.txt." << endl;
 
    return 0;
}
