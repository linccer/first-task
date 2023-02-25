#include "headeris.h"
#include "functions.h"

//external
extern int kiekis;
extern char choice;

//main
int main () {

    //vector
    vector<stud> gr;
    gr.reserve(10);
    stud temporary;
    bool add=true;

    //file
    choice='a';
    cout<<"Skaityti duomenis is failo \"Kursiokai.txt\"? Taip - 'T', Ne - 'N'\n"; cin>>choice;
    while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"Klaida. Iveskite T arba N. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin>>choice;}

    if (choice=='t' || choice=='T'){
        readf(temporary,gr, add);

    } if (choice=='n' || choice=='N') {
        //max pazymiu kiekis
        cout<<"Maksimalus pazymiu kiekis? ";
        while ( !(cin>>kiekis) || (kiekis<=0) ) {cout<<"\nKlaida. Iveskite sveika teigiama skaiciu. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        temporary.balai.reserve(kiekis);
    }

    //data entry
    enterdata(temporary, gr, add);

    //sort
    sort(gr.begin(),gr.end(),compareAlphabet);

    //print data
    cout<<endl<<left<<setw(15)<<"Vardas "
    <<left<<setw(20)<<"Pavarde "
    <<left<<setw(18)<<"Galutinis (Vid.) "
    <<left<<setw(18)<<"Galutinis (Med.) "
    <<"\n----------------------------------------------------------------\n";

    for (auto &i:gr) print(i);      //print entries

    gr.clear();    //clear group vector
}
