#include "headeris.h"

//structures
struct stud {
    string v="", p="";
    vector<int> balai;
    int egz = 0;
    double vidurkis=0;
    double mediana=0;
};

//function declarations
void fill (stud &entry);
void print (stud &entry);

//global vars
int kiekis=0;
char choice;

//main
int main () {

    //vector
    vector<stud> gr;
    gr.reserve(10);

    //pazymiu kiekis
    cout<<"Maksimalus pazymiu kiekis? ";
    cin>>kiekis;
    //check if input is correct
    do {if (kiekis==0 || kiekis<0) {cout<<"\nKlaida. Iveskite sveika teigiama skaiciu. "; cin.clear(); cin.ignore(); cin>>kiekis;} }
    while ( kiekis==0 || kiekis<0);


    //fill group
    bool add=true;
    stud temporary;
    temporary.balai.reserve(kiekis);

    do {
        //new data entry
        fill(temporary);
        gr.push_back(temporary);
        temporary.balai.clear();
        
        cout<<"Ivesta studentu - "<< gr.size()<<endl;


        //baigti ivedima
        choice='a';
        cout<<"Baigti studentu ivedima? Taip - 'T', Ne - 'N'\n";
        cin>>choice;
        if (choice=='n' || choice=='N') continue;
        if (choice=='t' || choice=='T') add=false;
        else {  while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"\nKlaida. Iveskite T arba N. "; cin.clear(); cin.ignore(); cin>>choice;}  }

    } while (add==true);


    //pasirinkimas
    cout<<"Spausdinti vidurki ar mediana? Vidurki - 'V', Mediana - 'M'\n";
    cin>>choice;
    while (choice!='v' && choice!='V' && choice!='m' && choice!='M') {cout<<"\nKlaida. Iveskite V arba M. "; cin.clear(); cin.ignore(); cin>>choice;}

    //print data
    cout<<endl<<left<<setw(15)<<"Vardas "
    <<left<<setw(20)<<"Pavarde "
    <<left<<setw(18);
    if (choice=='v' || choice=='V') cout<<"Galutinis (Vid.) ";
    else cout<<"Galutinis (Med.)";
    cout<<"\n--------------------------------------------------------\n";

    for (int a=0; a<gr.size(); a++) print(gr[a]);   //print entries

    gr.clear();    //clear group vector

}


void print (stud &entry){

    cout<<left<<setw(15)<<entry.v
    <<left<<setw(20)<<entry.p
    <<left<<setw(21)<<std::fixed<<setprecision(2);
    if (choice=='v' || choice=='V') cout<<entry.vidurkis<<endl;
    else cout<<entry.mediana<<endl;
}


void fill (stud &entry){
    cout<<"Iveskite studento varda ir pavarde\n";
    cin>>entry.v>>entry.p;

    //grades
    choice='a';
    cout<<"Generuoti atsitiktinius pazymius? Taip - 'T', Ne - 'N'.\n";
    cin>>choice;
        while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"\nKlaida. Iveskite T arba N. "; cin.clear(); cin.ignore(); cin>>choice;}

if (choice=='n' || choice=='N'){
    cout<<"Iveskite studento pazymius\nNorint baigti pazymiu ivedima, iveskite 0\n";
    int ivesta=0;
    int temp;
    for (int e=0; e<kiekis; e++) {

        while(!(cin>>temp)){
        cout<<"\nKlaida. Iveskite skaiciu. ";
        cin.clear();
        cin.ignore();
        }

        if (temp<11 && temp>0) {entry.balai.push_back(temp); ivesta++;}
        else if (temp == 0) {
                            if (ivesta !=0) break;
                            else cout<<"\nKlaida. Iveskite bent 1 pazymi. "; e--;
                            }
        else {cout<<"\nKlaida. Iveskite pazymi nuo 1 iki 10 arba iveskite 0 norint baigti pazymiu ivedima. "; e--;} 
    }

    if (ivesta<kiekis){ 
        for (int p=ivesta; p<kiekis; p++) entry.balai.push_back(0);
    }


    //exam
    cout<<"Iveskite egzamino pazymi. ";
    while(!(cin>>entry.egz) ||entry.egz<0 ||entry.egz>10){
    cout<<"\nKlaida. Iveskite skaiciu nuo 0 iki 10. ";
    cin.clear();
    cin.ignore();
    }



} else {
    //generate random
    srand(time(0));

    for (int e=0; e<kiekis; e++){
        entry.balai.push_back(rand()%(11));
    }

    entry.egz=rand()%(11);
}

    //for (int p=0; p<kiekis; p++) cout<<entry.balai[p]<<" "; // print grades for test       

    //vidurkis
    double average = 0;
    for (int t=0; t<kiekis; t++) average=average+(entry.balai[t])*1.0;
    average=average/(kiekis*1.0);
    average=average*0.4;
    average=average+(0.6*entry.egz);
    entry.vidurkis=average;

    //mediana
    vector<int> medi;
    medi.reserve(kiekis+1);
    for (int a=0; a<kiekis; a++) medi.push_back(entry.balai[a]);
    medi.push_back(entry.egz);
    sort(medi.begin(),medi.end());
    if ((kiekis+1)%2==0) entry.mediana=(medi[(kiekis/2)+1]+medi[(kiekis/2)])*1.0/2.0;
    else entry.mediana=medi[(kiekis/2)+1];
}