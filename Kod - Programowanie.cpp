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

void Twórz()
{
    system("cls");
    for (int i = 0; i < szerokość + 2; i++)
        cout << "#";
    cout << endl;
    for (int i = 0; i < wysokość; i++)
    {
        for (int j = 0; j < szerokość; j++)
        {
            if (j == 0)
                cout << "#"; //granice
            if (i == y && j == x)
                cout << "X"; //wąż
            else if (i == owocY && j == owocX)
                cout << "O"; //owoc
            else
            {
                bool print = false;
                for (int k = 0; k < długość_ogona; k++)
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
            if (j == szerokość - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < szerokość + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Wynik:" << Wynik << endl;
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

void Algorytm()
{
    int prevX = ogonX[0];
    int prevY = ogonY[0];
    int prev2X, prev2Y;
    ogonX[0] = x;
    ogonY[0] = y;
    for (int i = 1; i < długość_ogona; i++)
    {
        prev2X = ogonX[i];
        prev2Y = ogonY[i];
        ogonX[i] = prevX;
        ogonY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    if (x >= szerokość) 
        x = 0; 
    else if (x < 0)
        x = szerokość - 1;
    if (y >= wysokość) 
        y = 0; 
    else if (y < 0)
        y = wysokość - 1;
    for (int i = 0; i < długość_ogona; i++)
        if (ogonX[i] == x && ogonY[i] == y) 
            koniec = true;

    if (x == owocX && y == owocY)
    {
        Wynik += 10;
        owocX = rand() % szerokość;
        owocY = rand() % wysokość;
        długość_ogona++;
    }
}

int main()
{
    Ustawienia();
    while (!koniec)
    {
        Twórz();
        Wejście();
        Algorytm();
    }
    return 0;
}
