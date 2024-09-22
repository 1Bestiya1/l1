#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Truba { // создем структуру трубы и ее характеристики: имя, длина, диаметр, в ремонте или нет
    string Name;
    int Long;
    int Diametr;
    bool Remont = false;


    void readT() { //создаем функцию ввода значений характеристик

        cout << "Input name: ";
        cin >> Name;

        cout << "Input length: ";
        cin >> Long;

        cout << "Input diametr: ";
        cin >> Diametr;

    }

    void Display() { //прописываем условие если длина трубы <=0 и диаметр <=0, то трубы не существует 
        if (Long <= 0 && Diametr <= 0) {
            cout << "There is no pipe " << endl;
        }
        else {
            cout << "Pipe name: " << Name
                << " Pipe length: " << Long
                << " Pipe diametr: " << Diametr
                << " Repairing: " << (Remont ? "Yes" : "No") << endl;
        }
    }

    void Edition() {
        if (Long <= 0 && Diametr <= 0) {
            cout << "There is no pipe";
        }
        else {
            Remont = not(Remont);
            cout << " Repairing: " << (Remont ? "Yes" : "No") << endl;
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

        cout << "Input effective: ";
        cin >> Effect;
    }
    void Display() {
        if (Kolcexov <= 0 && Kolcexorab <= 0) {
            cout << "There is no station" << endl;
        }
        else {
            cout << "Station name: " << Name
                << " Station kolcexov: " << Kolcexov
                << " Station kolcexorab: " << Kolcexorab
                << "Effect: " << Effect << endl;
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
            T.Display();
            C.Display();
            break;
        case 4:
            T.Edition();
            break;
        case 5:
            ;
        case 6:
            ;
        case 7:
            ;
        }
    }
}

