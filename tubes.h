#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#define info(P) (P)->info
#define next(P) (P)->next
#define next_course(R) (R)->next_course
#define next_acara(Q) (Q)->next_acara
#define firstRelation(H) (H)->firstRelation
#define first(L) ((L).first)
using namespace std;

struct talent{
    //ADT UNTUK LIST TALENT
    string nama;
    string jeniskelamin;
    int umur;
    string bakat;
};

struct acara{
    //ADT UNTUK LIST ACARA
    string namaAcara;
    int tanggal;
    string tempat;
};

typedef talent infotypetalent;
typedef acara infotypeacara;
typedef struct elmListAcara *addressAcara;
typedef struct elmListTalent *addressTalent;
typedef struct elmListRelation *addressRelation;

struct elmListRelation{
    //ADT UNTUK ELEMENT RELATION
    addressRelation next_course;
    addressAcara next_acara;
};

struct elmListAcara {
    //ADT UNTUK ELEMENT LIST ACARA
    infotypeacara info;
    addressAcara next;
};
struct elmListTalent{
    //ADT UNTUK ELEMENT LIST TALENT
    infotypetalent info;
    addressTalent next;
    addressRelation firstRelation;
};
struct ListAcara{
    //ADT UNTUK LIST ACARA
    addressAcara first;
};
struct ListTalent{
    //ADT UNTUK LIST TALENT
    addressTalent first;
};
//DASHBOARD
void dashboard();
// DATA DUMMY
void dataDummyTalent(ListTalent &LTalent);
void dataDummAcara(ListAcara &LAcara);
void DummyRelasi(ListTalent &LTalent, ListAcara &LAcara);

//FUNCTION DAN PROCEDURE UNTUK LIST ACARA
void createListAcara(ListAcara &LAcara);
addressAcara createElmAcara(infotypeacara Xacara);
void insertFirstAcara(ListAcara &LAcara, addressAcara P);//(6)
void inserLastAcara(ListAcara &LAcara, addressAcara P);//(6)
void insertAfterAcara(ListAcara &LAcara,addressAcara P, addressAcara Prec);
void deleteFirstAcara(ListAcara &LAcara, addressAcara &P, ListTalent &LTalent);
void deleteLastAcara(ListAcara &LAcara, addressAcara &P, ListTalent &LTalent);
void deleteAfterAcara(ListAcara &LAcara, addressAcara &P, addressAcara Prec, ListTalent &LTalent);
void printAcara(ListAcara LAcara);
void PrintAcaraTertentu (ListAcara LAcara, string NamaAcara);//(5)
addressAcara searchAcara (ListAcara LAcara,string NamaAcara);

//FUNCTION DAN PROCEDURE UNTUK LIST TALENT
void createListTalent(ListTalent &LTalent);
addressTalent createElmTalent(infotypetalent Xtalent);
void insertFirstTalent(ListTalent &LTalent, addressTalent P);//(1)
void inserLastTalent(ListTalent &LTalent, addressTalent P);//(1)
void insertAfterTalent(ListTalent &LTalent, addressTalent P, addressTalent Prec);
void deleteFirstTalent(ListTalent &LTalent, addressTalent &P);
void deleteLastTalent(ListTalent &LTalent, addressTalent &P);
void deleteAfterTalent(ListTalent &LTalent, addressTalent &p, addressTalent prec);
void printTalent(ListTalent LTalent);//(2)
addressTalent searchTalent(ListTalent LTalent, string NamaTalent);

//FUNCTION DAN PROCEDURE UNTUKL LIST RELATION
addressRelation createElmRelation(addressAcara Pacara);
void insertFirstRelation(addressTalent &PTalent, addressRelation P);
void inserLastRelation(addressTalent &PTalent, addressRelation P);
void insertAfterRelation(addressTalent &PTalent, addressRelation P, addressRelation Prec);
void deleteFirstRelation(addressTalent &PTalent);
void deleteLastRelation(addressTalent &PTalent);
void deleteAfteRelation(addressTalent &PTalent, addressRelation Prec);
void Relation(ListTalent &LTalent,string namaTalent, ListAcara LAcara,string namaAcara);
void showRelation(ListTalent Ltalent, string namaTalent);
void showAcara(ListTalent Ltalent, string namaTalent, string namaAcara);
void countAcara(ListTalent Ltalent, string namaTalent);
addressRelation searchRelasi(addressTalent PTalent, string namaAcara);
void showAllRelasi(ListTalent Ltalent);

#endif // TUBES_H_INCLUDED
