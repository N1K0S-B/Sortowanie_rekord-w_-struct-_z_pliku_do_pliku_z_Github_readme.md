# Sortowanie uczniów
 
## Opis programu
 
Program służy do wczytywania danych uczniów z pliku tekstowego, zapisania ich w tablicy rekordów, posortowania według nazwiska rosnąco oraz zapisania posortowanych danych do pliku wynikowego.
 
Program obsługuje maksymalnie 30 uczniów.
 
## Struktura Person
 
Dane jednego ucznia są przechowywane w strukturze:
 
```cpp
struct Person
{
    string im;
    string naz;
    int nr;
};
