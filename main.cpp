#include "headeris.h"

//structures
struct stud {
    string v="", p="";
    int * balai = nullptr;
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

    //create group of size 1
    stud *gr;
    gr= new stud[1];


    //pazymiu kiekis
    cout<<"Maksimalus pazymiu kiekis? ";
    cin>>kiekis;
    //check if input is correct
    do {if (kiekis==0 || kiekis<0) {
            cout<<"Klaida. Iveskite sveika skaiciu. "; cin.clear(); cin.ignore(); cin>>kiekis;}
        }
    while ( kiekis==0 || kiekis<0);


    //fill group
    int n=0;    //for student count
    bool add=true;
    char stop;

    do {
        n++;
        //resize array
        if (n!=1){
        stud *tempgr= new stud[n-1];    //create temporary array
        copy(gr, gr+(n-1), tempgr);     //copy to temporary array (pradzios el, pabaigos el, i ka kopijuoti)
        delete[] gr;                    //delete original group array
        gr = new stud[n];               //create a new group array of increased size
        copy(tempgr,tempgr+(n-1), gr);  //copy from temporary array to new group array
        delete[] tempgr;                //delete temporary array
        }
        //new data entry
        fill(gr[n-1]);


        cout<<"Ivesta studentu - "<< n<<endl;


        //baigti ivedima
        cout<<"Baigti studentu ivedima? Taip - 'T', Ne - 'N'\n";
        cin>>stop;
        if (stop=='n' || stop=='N') continue;
        if (stop=='t' || stop=='T') add=false;
        else {
            while (stop!='n' && stop!='N' && stop!='t' && stop!='T') {
                cout<<"Klaida. Iveskite T arba N. ";
                cin.clear(); cin.ignore(); cin>>stop;}
        }
        //
    }
    while (add==true);


    //pasirinkimai
    cout<<"Spausdinti vidurki ar mediana? Vidurki - 'V', Mediana - 'M'\n";
        cin>>choice;
            while (choice!='v' && choice!='V' && choice!='m' && choice!='M') {cout<<"Klaida. Iveskite V arba M. "; cin.clear(); cin.ignore(); cin>>choice;}

    //print data
    cout<<endl<<left<<setw(15)<<"Vardas "
    <<left<<setw(20)<<"Pavarde "
    <<left<<setw(18);
    if (choice=='v' || choice=='V') cout<<"Galutinis (Vid.) ";
    else cout<<"Galutinis (Med.)";
    cout<<"\n--------------------------------------------------------\n";

    for (int a=0; a<n; a++) print(gr[a]);

    //delete group pointer
    delete[] gr;

}


void print (stud &entry){

    cout<<left<<setw(15)<<entry.v
    <<left<<setw(20)<<entry.p
    <<left<<setw(21)<<std::fixed<<setprecision(2);
    if (choice=='v' || choice=='V') cout<<entry.vidurkis<<endl;
    else cout<<entry.mediana<<endl;

    delete[] entry.balai;
}


void fill (stud &entry){
    cout<<"Iveskite studento varda ir pavarde\n";
    cin>>entry.v>>entry.p;

    //grades
    entry.balai=new int[kiekis];
    char uzklausa;
    cout<<"Generuoti atsitiktinius pazymius? Taip - 'T', Ne - 'N'.\n";
    cin>>uzklausa;
        while (uzklausa!='n' && uzklausa!='N' && uzklausa!='t' && uzklausa!='T') {cout<<"Klaida. Iveskite T arba N. "; cin.clear(); cin.ignore(); cin>>uzklausa;}

if (uzklausa=='n' || uzklausa=='N'){
    cout<<"Iveskite studento pazymius\nNorint baigti pazymiu ivedima, iveskite 0\n";
    int ivesta=0;
    int temp;
    for (int e=0; e<kiekis; e++) {

        while(!(cin>>temp)){
        cout<<"Klaida. Iveskite skaiciu. ";
        cin.clear();
        cin.ignore();
        }

        if (temp<11 && temp>0) {entry.balai[e]=temp; ivesta++;}
        else if (temp == 0) {
                            if (ivesta !=0) break;
                            else cout<<"Klaida. Iveskite bent 1 pazymi. "; e--;
                            }
        else {cout<<"Klaida. Iveskite pazymi nuo 1 iki 10 arba iveskite 0 norint baigti pazymiu ivedima. "; e--;}
    }

    if (ivesta<kiekis){
        for (int p=ivesta; p<kiekis; p++) entry.balai[p]=0;
    }


    //exam
    cout<<"Iveskite egzamino pazymi. ";
    while(!(cin>>entry.egz) ||entry.egz<0 ||entry.egz>10){
    cout<<"Klaida. Iveskite skaiciu nuo 0 iki 10. ";
    cin.clear();
    cin.ignore();
    }



} else {
    //generate random
    srand(time(0));

    for (int e=0; e<kiekis; e++){
        entry.balai[e]=rand()%(11);
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
    int *medi= new int [kiekis+1];
    for (int a=0; a<kiekis; a++) medi[a]=entry.balai[a];
    medi[kiekis]=entry.egz;
    sort(medi,medi+kiekis+1);
    if ((kiekis+1)%2==0) entry.mediana=(medi[(kiekis/2)+1]+medi[(kiekis/2)])*1.0/2.0;
    else entry.mediana=medi[(kiekis/2)+1];
    delete[] medi;

}