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