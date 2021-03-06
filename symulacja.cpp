#include "symulacja.h"


#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

void symulacja::fala()
{
    this->zaraza();
    this->hit();
    this->loty();

}

void symulacja::zaraza()
{
    for( int i=0; i<this->size(); i++)
    {
        if (world[i].chorzy!=0 && world[i].ludnosc!=world[i].chorzy)
        {
            world[i].chorzy = world[i].chorzy * 5;   // tu wstawić algo zarazy z alphy potem

            if (world[i].chorzy > world[i].ludnosc)
                world[i].chorzy = world[i].ludnosc;  //limit
            world[i].old_ratio=world[i].ratio;
            world[i].ratio=world[i].chorzy / world[i].ludnosc;

        }
    }

}


void symulacja::hit()
{
    for (int i=0; i<this->size(); i++)
    {
        if(world[i].chorzy)
        {
            lista  temp = world[i].graniczy_z;
            while( !temp.czy_pusta())
            {
                int target = temp.dej();
                if (world[target].chorzy)
                {
                    world[i].graniczy_z.usun_dowolny(target);
                    continue;
                }
                int obrona = world[target].health_care+world[target].GNI;
                int atak = world[i].chorzy/world[i].ludnosc;
                atak = atak + rand()%(100-atak);
                if (atak >= obrona)
                {
                    this->infect(i,10);
                    world[i].graniczy_z.usun_dowolny(target);
                    break;

                }

            }
        }
    }
}
void symulacja::loty()
{
    lista  temp = lotne;
    while( !temp.czy_pusta())
    {
        int target = temp.dej();
        if (world[target].chorzy)
        {
            lotne.usun_dowolny(target);
            continue;
        }
        int obrona = world[target].health_care + world[target].GNI;
        int atak = 50;
        atak = atak + rand()%(100-atak);
        if (atak >= obrona)
        {
            this->infect(target,10);
            lotne.usun_dowolny(target);
            break;

        }

    }

}
void symulacja::infect(int i,int liczba)
{
    world[i].chorzy+=liczba;

}


void symulacja::dodaj_element(string NazwaPliku)
{
    ifstream plik (NazwaPliku.c_str());

    if(!plik.good())
        return;



    while (!plik.eof())
    {
        Kraje kraj;
        kraj.nazwa="";
        plik.ignore(1);
        while (!plik.eof() && !(plik.peek()>='0' && plik.peek()<='9'))   // bierze sobie po literce nazwę państwa
        {                                                                // i zerka czy następna jest cyfrą

            char temp;
            plik.get(temp);
            kraj.nazwa=kraj.nazwa + temp;
            // robi słowow po literce
        }
//jak następna jest cyfrą to czyta normalnie dane do odpowiednich miejsc
        plik  >> kraj.ludnosc>> kraj.powierzchnia >> kraj.dos_morze >> kraj.health_care >> kraj.GNI;
        kraj.gestosc = kraj.ludnosc/kraj.powierzchnia;
        world.push_back(kraj);
    }
    return ;
}


void symulacja::czytaj_macierz (string NazwaPliku)   // bierze po linijce z pliku i dodaje do elementu vectora nowy element jak napotka '1' (np w linijce 24, linijka[100]==1 więc kraj 24 graniczy z krajem 100
{
    ifstream plik (NazwaPliku.c_str());
    if (! plik.good())
        return;
    int n=0; // licznik na którym państwie jest
    while ( ! plik.eof() )
    {

        string x;
        getline ( plik , x ); // wczytuje do x linijkę macierzy i na niej operuje
        for (unsigned int i=0 ; i < x.size() ; i++ )  // tu jest coś nie tak, albo znowu jakieś badbity z excela
                                                      // bo albo czyta że nie ma nic albo że jest wszystko
        {                                             // a lista sama w sobie działa
            if (x[i] == '1')
                world[n].graniczy_z.dodaj_element_po(i); // i można traktować jako indeks państwa mktóre graniczy z państwem nr n
        }
        n++;
    }
}

symulacja::symulacja()
{
    dodaj_element("Afryka.txt");
    dodaj_element("Ameryki.txt");
    dodaj_element("Eurazja.txt");
    dodaj_element("Oceania.txt");
    czytaj_macierz("sasiedztwo.txt");

    for(unsigned int i=0; i<world.size(); i++)
    {
        lotne.dodaj_element_po(i);
        L_ludzi+=world[i].ludnosc;
    }
}

symulacja::~symulacja()
{

}

int symulacja::size()
{
    return world.size();
}


string symulacja::dej_nazwe(int i)
{
    return world[i].nazwa;
}

int symulacja::szukaj_indeks(QString Nazwa)
{
    for (unsigned int i=0; i<world.size();i++)
        if(Nazwa == QString::fromStdString( (world[i].nazwa) ))
            return i;
    return 0;
}

int symulacja::szukaj_indeks(string Nazwa)
{
    for (unsigned int i=0; i<world.size();i++)
        if ( Nazwa == world[i].nazwa)
            return i;
    return -1;
}
void symulacja::set_data(int m, int r)
{
    data.set(m,r);
}
