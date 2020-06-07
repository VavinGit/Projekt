#include <iostream>
#include <conio.h>
using namespace std;
bool koniec;
const int szerokość = 20;
const int wysokość = 17;
int x, y, owocX, owocY, Wynik;
int ogonX[100], ogonY[100]; //pozycja węża
int długość_ogona;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; // kontrola
eDirecton dir;
void Ustawienia()
{
    koniec = false;
    dir = STOP;
    x = szerokość / 2;
    y = wysokość / 2;
    owocX = rand() % szerokość; //losowa pozycja owocu
    owocY = rand() % wysokość;
    Wynik = 0;
}
void Wejście()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            koniec = true;
            break;
        }
    }
}
void Twórz()
{
system("cls");
for (int i = 0; i < szerokoœæ + 2; i++)
    cout << "#";
cout << endl;
for (int i = 0; i < wysokoœæ; i++)
{
    for (int j = 0; j < szerokoœæ; j++)
    {
        if (j == 0)
            cout << "#"; //granice
        if (i == y && j == x)
            cout << "X"; //w¹¿
        else if (i == owocY && j == owocX)
            cout << "O"; //owoc
        else
        {
            bool print = false;
            for (int k = 0; k < d³ugoœæ_ogona; k++)
            {
                if (ogonX[k] == j && ogonY[k] == i)
                {
                    cout << "X";
                    print = true;
                }
            }
            if (!print)
                cout << " ";
        }
        if (j == szerokoœæ - 1)
            cout << "#";
    }
    cout << endl;
}
for (int i = 0; i < szerokoœæ + 2; i++)
    cout << "#";
cout << endl;
cout << "Wynik:" << Wynik << endl;
}
