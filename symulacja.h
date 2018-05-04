#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <QString>

#include "lista.h"
#include "czas.h"

using namespace std;

class symulacja
{
private:

    struct Kraje{
        string nazwa;
        short int ratio = 0, old_ratio = 0;
        unsigned int ludnosc,  chorzy=0;
        unsigned int powierzchnia;
        unsigned int  gestosc;
        bool dos_morze;
        int health_care;
        int GNI;
        lista graniczy_z;  // jest lista bo mniejsza będzie o wiele
    };




     vector<Kraje>  world;
     czas data;
     long long int infected=0, L_ludzi=0;
     lista lotne;


public:



     // konstrukcja

     symulacja();     
     ~symulacja();

     //pomocnicze konstruktora
     void dodaj_element(string nazwa_pliku);// tworzy wektor z krajami
     void czytaj_macierz (string NazwaPliku);// dodaje do gotowego wektora listy sąsiadów


     //zaraza
     void fala();
     void zaraza();
     void hit();
     void loty();


     //utility
     int size();
     string dej_nazwe(int);
     void infect(int i,int liczba);
     int szukaj_indeks(string Nazwa);
     int szukaj_indeks(QString Nazwa);
     void set_data(int m, int r);



};
#endif // VECTOR_H
