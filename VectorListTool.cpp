#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menu();
void tarkasteleHenkilot();
void lisaaHenkilo();

struct henkilot
{
    string nimi;
    int ika;
    string tyo;
};

vector<henkilot> h;

int main()
{
    menu();
    return 0;
}

void lisaaHenkilo()
{
    string nimi;
    string tyo;
    int ika;

    cout << endl
         << "Aloitetaan henkilon lisays." << endl;

    cin.clear();
    cin.ignore(256, '\n');

    cout << "Nimi?" << endl;
    getline(cin, nimi);

    cout << "Tyo?" << endl;
    getline(cin, tyo);

    cout << "Ika?" << endl;
    cin >> ika;

    struct henkilot a1 = {nimi, ika, tyo};

    h.push_back(a1);

    cout << "henkilo lisatty. Palautetaan valikkoon." << endl;
    menu();
}

void tarkasteleHenkilot()
{
    cout << endl
         << "Lista henkiloista:" << endl;
    for (auto &a : h)
    {
        cout << endl
             << a.nimi << "   " << a.tyo << "   " << a.ika
             << endl;
    }

    cout << endl
         << "Palautetaan valikkoon" << endl;
    menu();
}

void menu()
{
    int kayttajanValinta;

    cout << endl
         << "Valitse toiminto seuraavista vaihtoehdoista (numerovalinta 1-3)" << endl;
    cout << endl
         << "1: Lisaa henkilo";
    cout << endl
         << "2: Tarkastele lisattyja henkiloita";
    cout << endl
         << "3: Poistu" << endl;

    cin >> kayttajanValinta;

    switch (kayttajanValinta)
    {
    case 1:
        lisaaHenkilo();
        break;
    case 2:
        tarkasteleHenkilot();
        break;
    case 3:
        cout << "Ohjelma sammuu";
        return;
        break;
    default:
        cout << "Vaara valinta, palautetaan menun alkuun";
        menu();
    }
}