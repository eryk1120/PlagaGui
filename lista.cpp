#include "lista.h"

using namespace std;


void lista::dodaj_element_po(int inde)
{
    node * aktualny= new node(inde);
    if (head == nullptr)
        head = aktualny;
    else if (ogon == nullptr)
    {
    ogon = aktualny;
    head -> nast = ogon;
    }
    else
    {
     ogon -> nast = aktualny;
     ogon = aktualny;
    }
}

void lista::wypisz_liste ()
{
    node*temp;
    temp=head;
    while (temp != NULL)
    {
        //cout << temp->indeks << '\t';
        temp = temp->nast;
    }
}


void lista::usun_pierwszy()
{
    node *tmp; /*
    tmp=head->nast;
    delete head;
    head=tmp;
    */
    tmp = head;
    head = head->nast;
    delete tmp;
}


void lista::usun_dowolny(int numer)
{
    while(head->nast->indeks!=numer)
        head=head->nast;
    node *tmp=head->nast;
    head->nast=tmp->nast;
    delete tmp;
    return;

}

bool lista::czy_pusta()
{
    if (head == nullptr)
        return true;
    return false;
}
int lista::dej()
{
    if (head==NULL)
        return -1;           // sygnał, że koniec listy
    node * temp = head;
    int x = head->indeks;
    head=head->nast;
    delete temp;

    return x;
}
