#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person
{
    string im;
    string naz;
    int nr;
};

int readData(Person students[])
{
    ifstream file("uczniowie.txt");

    if (!file)
    {
        cout << "Nie mozna otworzyc pliku uczniowie.txt!" << endl;
        return 0;
    }

    int count = 0;

    while (count < 30)
    {
        if (file >> students[count].im >> students[count].naz >> students[count].nr)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    file.close();

    return count;
}

void sortData(Person students[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].naz > students[j + 1].naz)
            {
                Person temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayData(Person students[], int count)
{
    cout << "Posortowani uczniowie:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << students[i].im << " "
<< students[i].naz << " "
<< students[i].nr << endl;
    }
}

void saveData(Person students[], int count)
{
    ofstream file("wynik.txt");

    if (!file)
    {
        cout << "Nie mozna utworzyc pliku wynik.txt!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << students[i].im << " "
<< students[i].naz << " "
<< students[i].nr << endl;
    }

    file.close();
}

int main()
{
    Person students[30];

    int count = readData(students);

    if (count == 0)
    {
        cout << "Brak danych." << endl;
        return 0;
    }

    sortData(students, count);

    displayData(students, count);

    saveData(students, count);

    cout << endl;
    cout << "Wynik zostal zapisany do pliku wynik.txt." << endl;

    return 0;
}
