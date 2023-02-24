#include <iostream>
#include <fstream>

using namespace std;

void findNameByCod(string cod)
{
    string nome = "";
    ifstream fileMatricole("matricola.txt");
    string line;
    string matr="";
    bool trovato = false;
    if (fileMatricole.is_open())
    {
        cout << "File matricole.txt aperto correttamente" << endl;
        while (getline(fileMatricole, line))
        {
            matr="";
            for (int i = 0; i < 5; i++)
            {
                matr = matr + line[i];
            }
            if (matr == cod)
            {
                trovato = true;
                break;
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file matricole.txt" << endl;
    }
    if (trovato)
    {
        for (int i = 6; i < line.length(); i++)
        {
            nome = nome + line[i];
        }
        cout << "La matricola: " << cod << " corrisponde al nome: " << nome << endl;
    }
    else{
        cout << "Matricola non trovata\n";
    }
}

void findSalaryByCod(string cod)
{
    cout << "sono findSalaryByCod" << endl;
}

void findSalaryByName(string name)
{
    cout << "sono findSalaryByName" << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalita' che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Nome -> Stipendio\n"
             << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare: ";
        string input;
        cin >> input;

        if (scelta < 1 || scelta > 3)
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
                flag = false;
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
                flag = false;
            }
            else if (scelta == 3)
            {
                findSalaryByName(input);
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }

    cout << "Fine" << endl;
}