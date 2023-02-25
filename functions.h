# ifndef FUNCTIONS_H
# define FUNCTIONS_H


struct stud {
    string v="", p="";
    vector<int> balai;
    int egz = 0;
    double vidurkis=0;
    double mediana=0;
};


void readf (stud &temp, vector<stud> &gr, bool &add);
void enterdata(stud &temporary, vector<stud> &gr, bool &add);
void galutinis (stud &entry);
void rfill (stud &entry);
void fill (stud &entry);
void print (stud &entry);
string gfn();
string gln();
bool compareAlphabet(stud& a, stud& b);


# endif