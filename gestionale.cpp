#include <iostream>
#include <fstream>
using namespace std;
string getSecondByFirst(string nomeFile, string word)
{
    string first;
    string second;
    string line;
    ifstream fileAperto(nomeFile);
    if (fileAperto.is_open())
    {
        while (getline(fileAperto, line))
        {
            first = "";
            for (int i = 0; i < 5; i++)
            {
                first += line[i];
            }
            if (first == word)
            {
                for (int y = 6; y < line.length(); y++)
                {
                    second += line[y];
                }
                fileAperto.close();
                return second;
            }
        }
        fileAperto.close();
        return "error";
    }
    else
    {
        return "errorAp";
    }
}
string getFirstBySecond(string nomeFile, string word)
{
    string first;
    string second;
    string line;
    ifstream fileAperto(nomeFile);
    if (fileAperto.is_open())
    {
        while (getline(fileAperto, line))
        {
            second = "";
            for (int i = 6; i < line.length(); i++)
            {
                second += line[i];
            }
            if (second == word)
            {
                for (int y = 0; y < 5; y++)
                {
                    first += line[y];
                }
                fileAperto.close();
                return first;
            }
        }
        fileAperto.close();
        return "error";
    }
    else
    {
        return "errorAp";
    }
}
void findNameByCod(string cod) //  scelta 1
{
    string nome = getSecondByFirst("matricola.txt", cod);
    if (nome == "errorAp")
    {
        cout << "Errore durante l'apertura dei file Matricola.txt" << endl;
    }
    else if (nome == "error")
    {
        cout << "Matricola non trovata" << endl;
    }
    else
    {
        cout << "Matricola: " << cod << "   Nome dipendente: " << nome << endl;
    }
}
void findSalaryByCod(string cod) // scelta 2
{
    string stipendio = getSecondByFirst("stipendio.txt", cod);
    if (stipendio == "errorAp")
    {
        cout << "Errore durante l'apertura dei file stipendio.txt" << endl;
    }
    else if (stipendio == "error")
    {
        cout << "Matricola non trovata" << endl;
    }
    else
    {
        cout << "Matricola: " << cod << "     Stipendio: " << stipendio << endl;
    }
}
void findStraordinaryByCod(string cod) // scelta 3
{
    string straordinari = getSecondByFirst("straordinari.txt", cod);
    if (straordinari == "errorAp")
    {
        cout << "Errore durante l'apertura dei file straordinari.txt" << endl;
    }
    else if (straordinari == "error")
    {
        cout << "Matricola non trovata" << endl;
    }
    else
    {
        cout << "Matricola: " << cod << "   ha effettuato " << straordinari << " ore di straordinario." << endl;
    }
}
void findSalaryByName(string name) // scelta 4
{
    string matricola = getFirstBySecond("matricola.txt", name);
    if (matricola == "errorAp")
    {
        cout << "Errore durante l'apertura del file matricola.txt" << endl;
    }
    else if (matricola == "error")
    {
        cout << "Non e' stato possibile trovare una matricola associata a questo nome" << endl;
    }
    else
    {
        string stipendio = getSecondByFirst("stipendio.txt", matricola);
        if (stipendio == "errorAp")
        {
            cout << "Errore durante l'apertura del file stipendio.txt" << endl;
        }
        else
        {
            cout << "Dipendente: " << name << "     Matricola num: " << matricola << "     Stipendio: " << stipendio << endl;
        }
    }
}
void findSalaryAndStraordinaryByCod(string cod) // scelta 5
{
    string stipendio = getSecondByFirst("stipendio.txt", cod);
    if (stipendio == "errorAp")
    {
        cout << "Errore durante l'apertura del file stipendio.txt" << endl;
    }
    else if (stipendio == "error")
    {
        cout << "Matricola non trovata" << endl;
    }
    else
    {
        string ore = getSecondByFirst("straordinari.txt", cod);
        if (ore == "errorAp")
        {
            cout << "Errore durante l'apertura del file straordinari.txt" << endl;
        }
        else if (ore == "error")
        {
            cout << "Matricola: " << cod << "     Stipendio: " << stipendio << "     Ore straordinari: 0"
                 << "     Stipendio totale: " << stipendio << endl;
        }
        else
        {
            cout << "Matricola: " << cod << "     Stipendio: " << stipendio << "     Ore straordinari: " << ore << "     Stipendio totale: " << stoi(stipendio) + 35 * stoi(ore) << endl;
        }
    }
}
int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;
    bool flag = true;
    int scelta;
    string input;
    char conferma = 'y';
    while (flag and conferma == 'y')
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalita' che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Matricola -> Straordinari" << endl;
        cout << "4. Nome -> Stipendio" << endl;
        cout << "5. Matricola -> Stipendio + straordinari (35h)" << endl;
        cout << "0. EXIT\n"
             << endl;
        cout << "Seleziona: ";
        cin >> scelta;
        if (scelta == 0)
        {
            flag = false;
        }
        else
        {
            if (scelta < 1 || scelta > 5) // DA MODIFICARE IN CASO DI AGGIUNTE NEL MENU
            {
                cout << "Scelta non valida" << endl;
            }
            else
            {
                cout << "Inserisci quello che vuoi cercare: ";
                cin >> input;
                cout << endl;
                if (scelta == 1 && input.length() == 5)
                {
                    findNameByCod(input);
                }
                else if (scelta == 2 && input.length() == 5)
                {
                    findSalaryByCod(input);
                }
                else if (scelta == 3 && input.length() == 5)
                {
                    findStraordinaryByCod(input);
                }
                else if (scelta == 4)
                {
                    findSalaryByName(input);
                }
                else if (scelta == 5 && input.length() == 5)
                {
                    findSalaryAndStraordinaryByCod(input);
                }
                else
                {
                    cout << "Scelta non valida" << endl;
                }
            }
            cout << "\nVuoi continuare a consultare? (y per continuare, qualsiasi altro tasto per uscire)  ";
            cin >> conferma;
        }
    }
    cout << "Arrivederci" << endl;
}