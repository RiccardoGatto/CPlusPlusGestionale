#include <iostream>
#include <fstream>

using namespace std;

void findNameByCod(string cod)
{
    string nome = "";
    ifstream fileMatricole("matricola.txt");
    string line;
    string matr = "";
    bool trovato = false;
    if (fileMatricole.is_open())
    {
        cout << "File matricole.txt aperto correttamente" << endl;
        while (getline(fileMatricole, line))
        {
            matr = "";
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
        cout << "La matricola " << cod << " corrisponde al nome: " << nome << endl;
    }
    else
    {
        cout << "Matricola non trovata\n";
    }
    fileMatricole.close();
}

void findSalaryByCod(string cod)
{
    string stipendio;
    string line;
    string matr;
    bool trovato = false;
    ifstream fileStipendi("stipendio.txt");
    if (fileStipendi.is_open())
    {
        while (getline(fileStipendi, line))
        {
            matr = "";
            for (int i = 0; i < 5; i++)
            {
                matr += line[i];
            }
            if (matr == cod)
            {
                trovato = true;
                break;
            }
        }
        if (trovato)
        {
            for (int i = 6; i < line.length(); i++)
            {
                stipendio += line[i];
            }
            cout << "Il dipendente con matricola " << cod << " percepisce uno stipendio di " << stipendio << endl;
        }
        else
        {
            cout << "Matricola non trovata" << endl;
        }
    }
    else
    {
        cout << "Impossibile aprire il file stipendio";
    }
    fileStipendi.close();
}

void findSalaryByName(string name)
{
    string stipendio;
    string nome;
    string matr = "";
    string line;
    string matrStipendi;
    bool trovatoNome = false;
    bool trovataMatrStipendio = false;
    ifstream fileStipendi("stipendio.txt");
    ifstream fileMatricole("matricola.txt");
    if (fileStipendi.is_open() and fileMatricole.is_open())
    {
        while (getline(fileMatricole, line)) // mi estrapolo il nome dalla linea del file matricole
        {
            nome = "";
            for (int i = 6; i < line.length(); i++)
            {
                nome += line[i];
            }
            if (nome == name)
            {
                trovatoNome = true;
                break;
            }
        }
        if (trovatoNome) // se ho trovato il nome estrapolo la matricola corrispondente dal file matricole
        {
            for (int y = 0; y < 5; y++) // ciclo per estrapolare la matricola
            {
                matr += line[y];
            }
            while (getline(fileStipendi, line)) // ciclo per cercare la matricola nel file stipendi
            {
                matrStipendi = "";
                for (int i = 0; i < 5; i++)
                {
                    matrStipendi += line[i];
                }
                if (matr == matrStipendi) // se ho trovato la matricola nel file stipendi
                {
                    trovataMatrStipendio = true;
                    break;
                }
            }
            if (trovataMatrStipendio) // se ho trovato la matricola corrispondente al nome nel file stipendi
            {
                for (int i = 6; i < line.length(); i++) // ciclo per estrapolare lo stipendio
                {
                    stipendio += line[i];
                }
                cout << "Il dipendente " << name << " percepisce uno stipendio di " << stipendio << endl; // messaggio finale
            }
            else
            {
                cout << "Il dipendente " << name << " lavora gratis" << endl; // caso in cui esiste il dipendente ma non lo stipendio
            }
        }
        else // il nome che ho cercato non corrisponde a nessuna matricola
        {
            cout << "Matricola corrispondente al nome non trovata" << endl;
        }
    }
    else // Files non aperti correttamente
    {
        cout << "Errore durante l'apertura dei file";
    }
    fileMatricole.close();
    fileStipendi.close();
}

void findSalaryWithStraordinarioByName(string input)
{
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
        cout << "3. Nome -> Stipendio" << endl;
        cout << "4. Matricola -> Stipendio + Straordinari" << endl

             << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare: ";
        string input;
        cin >> input;

        if (scelta < 1 || scelta > 4)
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
            else if (scelta == 4 and input.length() == 5)
            {
                findSalaryWithStraordinarioByName(input);
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