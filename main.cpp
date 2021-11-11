#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
int z;

int kod(int z)
{
    fstream out,in;                                 //tworzenie zmiennych dla plików
    in.open("in.txt",ios::in);
    out.open("out.txt",ios::out);

    int jeden=0;                                    //zmienne to zlicznia ciągów
    int zero=0,r;



    while(!in.eof())                            // pętla kiedy plik nie jest skończony
{
        int a;
        in>>a;                                    // przypisanie danych z pliku do zmiennej

        if(a==1)
        {
            if(zero<2 )
                {
                if(r==1)
                    {

                        zero=0;
                        jeden++;
                        r=a;
                    }
                    else
                    {
                        zero=0;
                        jeden=1;
                        r=a;
                    }
                }
            else
                {
                if(jeden>1)
                    {

                    if(zero<jeden)
                        {
                           jeden=zero;
                        }
                    else
                        {
                           zero=jeden;
                        }


                    string do_out="[";
                    for(int i=0; i<jeden; i++){                 // <---jeśli znalało podciąg to wpisuje go do pliku
                        do_out=do_out+"1, ";
                    }
                    for(int i=0; i<zero; i++){
                        do_out=do_out+"0, ";
                    }
                    do_out=do_out+"]";
                    out<<do_out<<endl;





                    jeden=0;
                    zero=0;
                    jeden=1;
                     r=a;
                    }
                else
                    {
                    jeden++;
                    zero=0;
                    r=a;

                    }
                }

        }
        else
        {
        if(jeden<2)
            {
                jeden=0;
                zero++;
                 r=a;
            }
        else
            {
                zero++;
                r=a;
            }
        }
}

    if(zero-1>1 && jeden>1)                         //  <--- sprawdzenie jeśli cuiąg z pliku kończy się na 0
        {
            if(zero<jeden)
                    {
                    jeden=zero;
                    }
                    else
                    {
                    zero=jeden;
                    }

        string output="[";
        for(int i=0; i<jeden; i++){                     // <--- jeśli na koncu jest podciąg t oteż go wpisuje do pliku
            output=output+"1,_, ";
        }
        for(int i=0; i<zero-1; i++){
            output=output+"0,_, ";
        }
        output=output+"0]";
        out<<output<<endl;

        }

return 0;
}


int wpisywanie()                    // <-- funkcja wpisywania do pliku losowych liczb z przedziału 0-1
{

    fstream in;
    in.open("in.txt",ios::out);                 //  <--- umożliwianie wpisywanie danych do pliku


    string u;
    cout<<"ile znakow w tablicy"<<endl;             // <--- podanie ile ma liczyć ciag
    cin>>z;
    for(int r=0;r<z;r++)
    {
    u=rand()%2+48;
    in<<u+" ";                          // <----wpisanie do pliku licz z zakrsu 0-1
    }
    return z;
}


int main()              // < ---główny main
{
    srand(time(NULL ) );            // <--- umożliwianie zawsze losowych liczb

    auto startA = chrono::steady_clock::now();      //<-- zaczęcia liczenia czasu

    wpisywanie();               // <-- wywołanie funkcji do wpisywania losowych liczb

    kod(z);                 // <-- wywołanie funcki sprawdzającej liczby z pliku i wpisywanie poprawnych wyników do innego pliku


    auto stopA = chrono::steady_clock::now();     //< -- stop zegara
    auto durationA = stopA - startA;                //<-- roznica czasów miedzy start i stop
    auto duration_microseconds = chrono::duration_cast<std::chrono::microseconds> (durationA).count();      //< --konwersja różnicy czasu na mikro sekundy
    cout << endl <<"__________________"<<endl<< "Czas wykonania algorytmu w mikrosekundach: " << endl << duration_microseconds << endl;  // <-- wypisanie czasu w mikro sakundach

    return 0;
}
