void Tw�rz()
{
system("cls");
for (int i = 0; i < szeroko�� + 2; i++)
    cout << "#";
cout << endl;
for (int i = 0; i < wysoko��; i++)
{
    for (int j = 0; j < szeroko��; j++)
    {
        if (j == 0)
            cout << "#"; //granice
        if (i == y && j == x)
            cout << "X"; //w��
        else if (i == owocY && j == owocX)
            cout << "O"; //owoc
        else
        {
            bool print = false;
            for (int k = 0; k < d�ugo��_ogona; k++)
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
        if (j == szeroko�� - 1)
            cout << "#";
    }
    cout << endl;
}
for (int i = 0; i < szeroko�� + 2; i++)
    cout << "#";
cout << endl;
cout << "Wynik:" << Wynik << endl;
}