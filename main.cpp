#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

void pokaz_dochody(double *dochody, int d)
{
    int i=1;
    cout << "Twoje dochody:" << endl;
    for(i=1; i<d; i++)
        {
        cout << i << ") " << dochody[i]<< " zl" << endl;
        }
}

void pokaz_wydatki(double *wydatki, int w)
{
    int i=1;
    cout << "Twoje wydatki:" << endl;
    for(i=1; i<w; i++)
        {
        cout << i << ") " << wydatki[i] << " zl" << endl;
        }
}

void sortuj_dochody(double *dochody, int d)
{
    int i =0;
    for(i=0; i<d-1; i++)
        {
          if (dochody[i]>dochody[i+1])
            {
             swap(dochody[i], dochody[i+1]);
            }
        }
}

void sortuj_wydatki(double *wydatki, int w)
{
    int i =0;
    for(i=0; i<w-1; i++)
        {
          if (wydatki[i]>wydatki[i+1])
            {
             swap(wydatki[i], wydatki[i+1]);
            }
        }
}

void zakreskuj()
{
 for(int i=0; i<=24; i++)
    {
        printf("=");
    }
}


int main()
{
    int d = 1;
    int w = 1;
    int o = 1;
    double dochody[5] = {0};
    double wydatki[5] = {0};
    double lacznie_dochody = 0;
    double lacznie_wydatki = 0;
    char menu=0;

    do
    {
        cout << "   APLIKACJA FINANSOWA   " << endl;
        zakreskuj();
        printf("\n");
        printf("|         Menu          |\n");
        printf("|   1. Dodaj dochody    |\n");
        printf("| 2. Analiza dochodow   |\n");
        printf("|   3. Dodaj wydatki    |\n");
        printf("| 4. Analiza wydatkow   |\n");
        printf("|   5. Oszczednosci     |\n");
        printf("|     6. Wyjscie.       |\n");
        zakreskuj();
        printf("\n");
        cout << "  @copyright by Rafcio    " << endl;

        menu=getch(); system("CLS");

        switch(menu)
        {
        case '1':
            {
                system("CLS");
                        float f = 0;
                        printf("Dodaj:\n");
                        printf("%d.",d);
                        scanf("%f", &f);
                        dochody[d] = f;
                        d++;
                system("CLS");
            }
            break;

        case '2':
            {
                system("CLS");
                        pokaz_dochody(dochody,d);
                        cout << endl;
                        cout << "-Posortowane- ";
                        sortuj_dochody(dochody,d);
                        pokaz_dochody(dochody,d);
                        double razem = 0;
                        for (int i = 0; i < d; i++)
                        razem += dochody[i];
                        cout << endl;
                        cout << "Suma dochodow wynosi: " << razem << "zl" << endl;
                        lacznie_dochody = razem;
                        cout << endl;

            }
        break;

        case '3':
            {
                system("CLS");
                        float e= 0;
                        printf("Dodaj:\n");
                        printf("%d.",w);
                        scanf("%f", &e);
                        wydatki[w] = e;
                        w++;
                system("CLS");
            }
        break;

        case '4':
            {
                system("CLS");
                        pokaz_wydatki(wydatki,w);
                        cout << endl;
                        cout << "-Posortowane- ";
                        sortuj_wydatki(wydatki,w);
                        pokaz_wydatki(wydatki,w);
                        double wynik = 0;
                        for (int i = 0; i < d; i++)
                        wynik += wydatki[i];
                        cout << endl;
                        cout << "Suma wydatkow wynosi: " << wynik << "zl" << endl;
                        lacznie_wydatki = wynik;
                        cout << endl;
            }
        break;

        case '5':

            {
                system("CLS");
                cout << endl;
                cout << "Posiadasz dok³adnie: " << lacznie_dochody - lacznie_wydatki << "zl oszczednosci." << endl;
                cout << endl;
            }
        break;


        case '6':
            system("CLS");
            printf("Dziekujemy za korzystanie z naszych uslug! \n");
            break;
        default:
            printf("Sprobuj jeszcze raz \n");
        }
    }
    while(menu !='6');

    ofstream plikCPP("Twoja Analiza.txt");
    plikCPP<<"Dochody łącznie:"<< sortuj_dochody <<  lacznie_dochody << endl <<"Wydatki łacznie:"<<sortuj_wydatki << lacznie_wydatki << endl << "Posiadasz dok³adnie: " << lacznie_dochody - lacznie_wydatki << "zl oszczednosci." << endl;
    plikCPP.close();

    fstream plik;
    plik.open("Twoja Analiza.txt", ios::out | ios::app);
    cout<<endl;
    plik.close();

    return 0;
}
