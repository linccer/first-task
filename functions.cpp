#include "headeris.h"
#include "functions.h"

int kiekis=0;
char choice;
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 10);
std::uniform_int_distribution<int> names(0, 9);

//---------------------------------------------------------------------------------------------------------------------------------------------------
void readf (stud &temp, vector<stud> &gr, bool &add){
    
    ifstream file("kursiokai.txt");
    try { if (file.fail()) { throw 1; }
    kiekis=-3;
    string line;
    getline(file, line);                    //get first line
    istringstream ss(line);
    while(ss>>line) {kiekis++;}             //ND kiekis

    temp.balai.reserve(kiekis);
    int balas;
    //read the data
    while (getline (file, line)){
        istringstream ss(line);
        ss>>temp.v;
        ss>>temp.p;
        for (int e=0; e<kiekis; e++){ ss>>balas; temp.balai.push_back(balas);}
        ss>>temp.egz;
        galutinis(temp);

        gr.push_back(temp);
        
    }
    file.close();

    //baigti ivesti
    choice='a';
    cout<<"Failas nuskaitytas. Baigti studentu ivedima? Taip - 'T', Ne - 'N'\n"; cin>>choice;
    while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"\nKlaida. Iveskite T arba N. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin>>choice;}
    if (choice=='t' || choice=='T') add=false;
    else choice='a';
            

    } catch (int) { cout<<"Failas nerastas. ";    choice='n'; }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void enterdata(stud &temporary, vector<stud> &gr, bool &add){
    while (add==true) {
        choice='a';
        cout<<"Generuoti atsitiktinius studentus? Taip - 'T', Ne - 'N'\n"; cin>>choice;
        while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"\nKlaida. Iveskite T arba N. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin>>choice;}

        if (choice=='t' || choice=='T'){    //random data
            int r=0;
            cout<<"Kiek studentu generuoti?\n";
            while ( !(cin>>r) || (r<=0) ) {cout<<"\nKlaida. Iveskite sveika teigiama skaiciu. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            while (r>0){
                rfill(temporary);
                gr.push_back(temporary);
                temporary.balai.clear();
                r--;
            }

        } else {    //manual entry
                    fill(temporary);
                    gr.push_back(temporary);
                    temporary.balai.clear();  
        }
        cout<<"Ivesta studentu - "<< gr.size()<<endl;


        //baigti ivedima
        choice='a';
        cout<<"Baigti studentu ivedima? Taip - 'T', Ne - 'N'\n";
        cin>>choice;
        if (choice=='n' || choice=='N') continue;
        if (choice=='t' || choice=='T') add=false;
        else {  while (choice!='n' && choice!='N' && choice!='t' && choice!='T') {cout<<"\nKlaida. Iveskite T arba N. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin>>choice;}  }
    } 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void print (stud &entry){

    cout<<left<<setw(15)<<entry.v
    <<left<<setw(21)<<entry.p
    <<left<<setw(18)<<std::fixed<<setprecision(2)<<entry.vidurkis
    <<left<<std::fixed<<setprecision(2)<<entry.mediana <<endl;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void galutinis (stud &entry){
    //vidurkis
    entry.vidurkis=accumulate(&entry.balai[0], &entry.balai[kiekis], 0.);    //pazymiu suma
    entry.vidurkis=(entry.vidurkis/(kiekis*1.0))*0.4  + (0.6*entry.egz);

    //mediana
    sort(entry.balai.begin(),entry.balai.end());
    if ((kiekis)%2==0) entry.mediana=(entry.balai[(kiekis/2)-1]*1.0+entry.balai[(kiekis/2)]*1.0)/2;
    else entry.mediana=entry.balai[(kiekis/2)];
    entry.mediana=(entry.mediana*0.4)  + (0.6*entry.egz);

    //for (int p=0; p<kiekis; p++) cout<<entry.balai[p]<<" "; // print grades for test 
    //cout<<"      "<<entry.egz<<endl;
    entry.balai.clear();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void rfill (stud &entry){
    entry.v=gfn();
    entry.p=gln();
    for (int e=0; e<kiekis; e++){  entry.balai.push_back(dist(mt));  }
    entry.egz=dist(mt);
    galutinis(entry);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void fill (stud &entry){
    cout<<"Iveskite studento varda ir pavarde\n";
    cin>>entry.v>>entry.p;

    cout<<"Iveskite studento pazymius\nNorint baigti pazymiu ivedima, iveskite 0\n";
    int ivesta=0;
    int temp;
    for (int e=0; e<kiekis; e++) {

        while(!(cin>>temp)){  cout<<"\nKlaida. Iveskite skaiciu. ";  cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');  }

        if (temp<11 && temp>0) {entry.balai.push_back(temp); ivesta++;}
        else if (temp == 0) {
                            if (ivesta !=0) break;
                            else cout<<"\nKlaida. Iveskite bent 1 pazymi. "; e--;
                            }
        else {cout<<"\nKlaida. Iveskite pazymi nuo 1 iki 10 arba iveskite 0 norint baigti pazymiu ivedima. "; e--;} 
    }

    if (ivesta<kiekis) {   for (int p=ivesta; p<kiekis; p++) entry.balai.push_back(0);   }

    //exam
    cout<<"Iveskite egzamino pazymi. ";
    while(!(cin>>entry.egz) ||entry.egz<0 ||entry.egz>10){  cout<<"\nKlaida. Iveskite skaiciu nuo 0 iki 10. "; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

    galutinis(entry);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
string gfn(){
    string fn[10]={"Garret", "Morgan", "Scott", "Ryan", "Caleb", "Audrey", "Sydney", "Marianne", "Louise", "Margot"};
    return fn[names(mt)];
}
string gln(){
    string ln[10]={"Mayer", "Adkins", "Ellis", "Gallow", "Holt", "Jennings", "Lawrence", "Sinclair", "Wakefield", "Dagley"};
    return ln[names(mt)];
}

bool compareAlphabet(stud& a, stud& b) {
    if (a.p==b.p) {return (a.v < b.v);}
    else return (a.p < b.p);
}