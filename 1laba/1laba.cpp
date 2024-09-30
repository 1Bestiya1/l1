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
            cout << " Input name: ";
            getline(cin >> Name, wrong0);
            if (Name.find(' ') != string::npos || wrong0.length() != 0) {
                cin.clear();
                Name = Name + wrong0;
            }

            cout << " Input length: ";
            getline(cin >> Long, wrong);
            
            if (Long <= 0 || (int(Long) != Long || (to_string(Long)).find(' ') != string::npos || wrong.length() != 0)) {
                cout << "Incorrect data (pls add a new pipe) " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << " Input diametr: ";
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
                << "  Pipe length: " << Long
                << "  Pipe diametr: " << Diametr
                << "  Repairing: " << (Remont ? "Yes" : "No") << endl;   
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

    void LoadingT() {
        if (Long > 0 && Diametr > 0) {
            
            std::ofstream outFile("Truba.txt");

            if (!outFile) {
                std::cerr << "Openning file Error!" << std::endl;
            }

            outFile << Name << std::endl;
            outFile << Long << std::endl;
            outFile << Diametr << std::endl;
            outFile << Remont << std::endl;
            outFile.close();

            std::cout << "Now data in file Truba.txt!" << std::endl;
        }
        else {
            cout << "There is no pipe (pls add a new pipe)" << endl;
        }

    }
    void UnloadingT() {
        const char* filename = "Truba.txt";
        ifstream file(filename);

        if (file) {
            cout << "File " << filename << " is real." << endl;
            ifstream inFile("Truba.txt");

            if (!inFile) {
                cerr << "Openning file Error!" << endl;
            }

            string line1, line2, line3;

            if (getline(inFile, Name)) {
                cout << "Pipe name: " << Name << endl;
            }

            if (getline(inFile, line1)) {
                Long = stoi(line1); // Преобразуем строку в целое число
                cout << "  Pipe length: " << Long << endl;
            }

            if (getline(inFile, line2)) {
                Diametr = stoi(line2); 
                cout << "  Pipe diametr: " << Diametr << endl;
            }

            if (getline(inFile, line3)) {
                Remont = stoi(line3); 
                cout << "  Repairing: " << (Remont ? "Yes" : "No") << endl;
            }

            inFile.close();
        }
        else {
            cout << "File " << filename << " is not real." << endl;
        }
    }
};

// && = and || = or
void DisplayMenu() { // создаем меню для выбора действий
    cout << "__________________(-_-)_/_________________" << endl;
    cout << "                   Menu:          " << endl;
    cout << " 0) Exit the program           " << endl;
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
    string wrong0;
    string wrong;
    string wrong1;
    string wrong2;

    void readC() {
        
        bool B = true;

        while (B) {
            cout << " Input name: ";
            getline(cin >> Name, wrong0);
            if (Name.find(' ') != string::npos || wrong0.length() != 0) {
                cin.clear();
                Name = Name + wrong0;
            }
        

        cout << " Input count of cexov: ";
        getline(cin >> Kolcexov, wrong);

        if (Kolcexov <= 0 || (int(Kolcexov) != Kolcexov || (to_string(Kolcexov)).find(' ') != string::npos || wrong.length() != 0)) {
            cout << "Incorrect data (pls add a new station) " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << " Input count of cexov (working): ";
        getline(cin >> Kolcexorab, wrong1);
        if (Kolcexorab < 0 || (int(Kolcexorab) != Kolcexorab) || (to_string(Kolcexorab)).find(' ') != string::npos || wrong1.length() != 0) {
            cout << "Incorrect data (pls add a new station) " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        

        cout << " Input effective(%): ";
        getline(cin >> Effect, wrong2);
        if (Effect < 0 || (int(Effect) != Effect) || (to_string(Effect)).find(' ') != string::npos || wrong2.length() != 0) {
            cout << "Incorrect data (pls add a new station) " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        B = false;
        }
    }
    void DisplayC() {
        if (Kolcexov <= 0 || Kolcexorab < 0 || Kolcexov < Kolcexorab) {
            cout << "There are no stations (pls add a new station)" << endl;
        }
        else {
            cout << "Station name: " << Name
                << "  Kolcexov: " << Kolcexov
                << "  Kolcexorab: " << Kolcexorab
                << "  Effect: " << Effect << endl;
        }
    }
    void EditionC() { // редактирование станций
        if (Kolcexov <= 0 || Kolcexorab < 0 || Kolcexov < Kolcexorab) {
            cout << "There are no stations (pls add a new station)";
        }
        else {
            bool B = true;

            while (B) {
                cout << "Input count of cexov (working): ";
                getline(cin >> Kolcexorab, wrong1);
                if (Kolcexorab < 0 || (int(Kolcexorab) != Kolcexorab) || (to_string(Kolcexorab)).find(' ') != string::npos || wrong1.length() != 0) {
                    cout << "Incorrect data (pls add a new station) " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
            B = false;
            }
        
        }

    }
    void LoadingC() {
        if (Kolcexov > 0 && Kolcexorab >= 0 && Kolcexov > Kolcexorab) {

            std::ofstream outFile("Compress.txt");

            if (!outFile) {
                std::cerr << "Openning file Error!" << std::endl;
            }

            outFile << Name << std::endl;
            outFile << Kolcexov << std::endl;
            outFile << Kolcexorab << std::endl;
            outFile << Effect << std::endl;
            outFile.close();

            std::cout << "Now data in file Compress.txt!" << std::endl;
        }
        else {
            cout << "There is no station (pls add a new station)" << endl;
        }
    }
    void UnloadingC() {
        const char* filename = "Compress.txt";
        std::ifstream file(filename);

        if (file) {
            std::cout << "File " << filename << " is real." << std::endl;
            std::ifstream inFile("Compress.txt");

            if (!inFile) {
                std::cerr << "Openning file Error!" << std::endl;
            }

            string line1, line2, line3;

            if (getline(inFile, Name)) {
                cout << "Station name: " << Name << endl;
            }

            if (getline(inFile, line1)) {
                Kolcexov = stoi(line1); // Преобразуем строку в целое число
                cout << "  Kolcexov: " << Kolcexov << endl;
            }

            if (getline(inFile, line2)) {
                Kolcexorab = stoi(line2);
                cout << "  Kolcexorab: " << Kolcexorab << endl;
            }

            if (getline(inFile, line3)) {
                Effect = stoi(line3);
                cout << "  Effect: " << Effect << endl;
            }


            inFile.close();
        }
        else {
            std::cout << "File " << filename << " is not real." << std::endl;
        }

    }
};


int main() {
    Truba T;
    Comp C;
    int choice;
    string wrong;
    bool E = true;
    while (E) { // к каждой цифре меню выбираем действие и прописываем условие о верности выбора цифры
        DisplayMenu();
        cout << "Choose the action: ";
        getline(cin >> choice, wrong);

        if (cin.fail() || choice < 0 || choice > 7 ) {
            cout << "Not true number" << endl;
            cin.clear();
            continue;
        }

        switch (choice) {
        case 0:
            E = false;
            break;
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
            T.LoadingT();
            C.LoadingC();
            break;
        case 7:
            T.UnloadingT();
            C.UnloadingC();
            break;
        }
    }
}

