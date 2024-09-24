#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Truba { // создем структуру трубы и ее характеристики: имя, длина, диаметр, в ремонте или нет
    string Name;
    int Long;
    int Diametr;
    bool Remont = false;
    string wrong0;
    string wrong;
    string wrong1;

    void readT() { //создаем функцию ввода значений характеристик
        bool B = true;
        
        while (B) {
            cout << "Input name: ";
            getline(cin >> Name, wrong0);
            if (Name.find(' ') != string::npos || wrong0.length() != 0) {
                cin.clear();
                Name = Name + wrong0;
            }

            cout << "Input length: ";
            getline(cin >> Long, wrong);
            
            if (Long <= 0 || (int(Long) != Long || (to_string(Long)).find(' ') != string::npos || wrong.length() != 0)) {
                cout << "Incorrect data (pls add a new pipe) " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Input diametr: ";
            getline(cin >> Diametr, wrong1);
            if (Diametr <= 0 || (int(Diametr) != Diametr) || (to_string(Diametr)).find(' ') != string::npos || wrong1.length() != 0) {
                cout << "Incorrect data (pls add a new pipe) " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            B = false;
        }
    }

    void DisplayT() { //прописываем условие если длина трубы <=0 и диаметр <=0, то трубы не существует 
        if (Long > 0 && Diametr > 0) {
            cout << "Pipe name: " << Name
                << " Pipe length: " << Long
                << " Pipe diametr: " << Diametr
                << " Repairing: " << (Remont ? "Yes" : "No") << endl;   
        }
        else {
            cout << "There is no pipe (pls add a new pipe)" << endl;
        }
    }

    void EditionT() { // редактирование трубы
        if (Long > 0 && Diametr > 0) {
            Remont = not(Remont);
            cout << " Repairing: " << (Remont ? "Yes" : "No") << endl;
            
        }
        else {
            cout << "There is no pipe (pls add a new pipe)";
        }
    }
};

// && = and || = or
void DisplayMenu() { // создаем меню для выбора действий
    cout << "__________________(-_-)_/_________________" << endl;
    cout << "                   Menu:          " << endl;
    cout << " 1) Add a pipe (+ pipe)           " << endl;
    cout << " 2) Add the station (+ station)       " << endl;
    cout << " 3) Check all objects (Pipe and stations)     " << endl;
    cout << " 4) Edit the pipe (redact the pipe)         " << endl;
    cout << " 5) Edit the station (redact the station)       " << endl;
    cout << " 6) Complite (load to the file)              " << endl;
    cout << " 7) Load (load from the file)                  " << endl;
    cout << "__________________(~_~)_/_________________" << endl;
}

struct Comp { // создем структуру компрессорной станции и ее характеристики: имя, кол-во цехов, кол-во цехов в работе, эффективность
    string Name;
    int Kolcexov;
    int Kolcexorab;
    int Effect;

    void readC() {
        
        cout << "Input name: ";
        cin >> Name;
        

        cout << "Input count of cexov: ";
        cin >> Kolcexov;
        

        cout << "Input count of cexov (working): ";
        cin >> Kolcexorab;
        

        cout << "Input effective(%): ";
        cin >> Effect;
        

        if (Kolcexov <= 0 || Kolcexorab <= 0 || Kolcexov <= Kolcexorab) {
            cout << "There are no stations or incorrect data (pls add a new station)" << endl;
        }
    }
    void DisplayC() {
        if (Kolcexov <= 0 || Kolcexorab <= 0 || Kolcexov <= Kolcexorab) {
            cout << "There are no stations (pls add a new station)" << endl;
        }
        else {
            cout << "Station name: " << Name
                << "Kolcexov: " << Kolcexov
                << "Kolcexorab: " << Kolcexorab
                << " Effect: " << Effect << endl;
        }
    }
    void EditionC() { // редактирование станций
        if (Kolcexov <= 0 || Kolcexorab <= 0 || Kolcexov <= Kolcexorab) {
            cout << "There are no stations or incorrect data (pls add a new station)";
        }
        else {
            cout << "Input count of cexov: ";
            cin >> Kolcexov;

            cout << "Input count of cexov (working): ";
            cin >> Kolcexorab;

            cout << "Input effective(%): ";
            cin >> Effect;

            if (Kolcexov <= 0 || Kolcexorab <= 0 || Kolcexov <= Kolcexorab) {
                cout << "Incorrect data (pls add a new station)" << endl;
            }
        }

    }
};


int main() {
    Truba T;
    Comp C;
    int choice;
    string wrong;
    while (true) { // к каждой цифре меню выбираем действие и прописываем условие о верности выбора цифры
        DisplayMenu();
        cout << "Choose the action: ";
        getline(cin >> choice, wrong);

        if (cin.fail() || choice <= 0 || choice > 7 || choice == +0 || choice == -0) {
            cout << "Not true number" << endl;
            cin.clear();
            continue;
        }

        switch (choice) {
        case 1:
            T.readT();
            break;
        case 2:
            C.readC();
            break;
        case 3:
            T.DisplayT();
            C.DisplayC();
            break;
        case 4:
            T.EditionT();
            break;
        case 5:
            C.EditionC();
            break;
        case 6:
            ;
        case 7:
            ;
        }
    }
}

