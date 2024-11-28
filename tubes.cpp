#include "tubes.h"

void dashboard(){
    cout <<"==================== DASHBOARD ====================" << endl;
    cout << "    = TALENT =   " << endl;
    cout << "1.  Insert Talent" << endl;
    cout << "2.  Search Talent" << endl;
    cout << "3.  Delete Talent (Dan Relasinya)" << endl;
    cout << "4.  Show Semua Talent" << endl;
    cout << "    = ACARA =   " << endl;
    cout << "5.  Insert  Acara" << endl;
    cout << "6.  Search Acara" << endl;
    cout << "7.  Delete Acara" << endl;
    cout << "8.  Show Semua Acara" << endl;
    cout << "    = RELASI =   " << endl;
    cout << "9.  Hubungkan Relasi Talent dan Acara" << endl;
    cout << "10. Search Acara pada Talent" << endl;
    cout << "11. Delete Acara pada Talent" << endl;
    cout << "12. Count Acara pada Talent" << endl;
    cout << "13. Show semua Talent dan acara yang ada" << endl;
    cout << "14. Show Acara yang dimiliki Talent" << endl;
    cout << "15. Show Semua Relasi" << endl;
    cout << endl;
    cout << "0. Keluar Program" << endl;
    cout <<"---------------------------------------------------" << endl;
}

void createListAcara(ListAcara &LAcara){
    //CREATE LIST UNTUK LIST ACARA
    first(LAcara) = NULL;
};
addressAcara createElmAcara(infotypeacara Xacara){
    //MEMBUAT ELEMENT LIT ACARA
    addressAcara P;
    P = new elmListAcara;
    info(P) = Xacara;
    next(P) = NULL;

};
void insertFirstAcara(ListAcara &LAcara, addressAcara P){
    //INSERT FIRST UNTUK LIST ACARA
    if (first(LAcara) == NULL){
        first(LAcara) = P;
    }else{
        next(P) = first(LAcara);
        first(LAcara) = P;
    }
};
void inserLastAcara(ListAcara &LAcara, addressAcara P){
    //INSERT LAST UNTUK LIST ACARA
    addressAcara Q;
    Q = first(LAcara);
    if (first(LAcara)== NULL){
        first(LAcara) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
};
void insertAfterAcara(ListAcara &LAcara,addressAcara P, addressAcara Prec){
    //INSERT AFTER UNTUK LIST ACARA
    if(first(LAcara) == NULL){
        first(LAcara) = P;
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
};
void deleteFirstAcara(ListAcara &LAcara, addressAcara &P, ListTalent &LTalent){
    //DELETE FIRST UNTUK LIST ACARA
    addressTalent QTalent;
    addressRelation QRelation, DRelation;
    if (first(LAcara)== NULL){
        cout<<"List ACARA KOSONG"<<endl;
    }else{
        P = first(LAcara);
        QTalent = first(LTalent);
                 while(QTalent != NULL){
            if(firstRelation(QTalent) != NULL){
                QRelation= firstRelation(QTalent);
                while (QRelation != NULL){
                    if(next_acara(QRelation) == P ){
                        if(QRelation == firstRelation(QTalent)){
                            deleteFirstRelation(QTalent);
                        }else if(next_course(QRelation) == NULL){
                            deleteLastRelation(QTalent);
                        }else {
                            DRelation = firstRelation(QTalent);
                            while(next_course(DRelation) != QRelation){
                                DRelation = next_course(DRelation);
                            }
                            deleteAfteRelation(QTalent,DRelation);
                        }
                    }
                QRelation = next_course(QRelation);
                }
            }
            QTalent = next(QTalent);
        }
        first(LAcara) = next(P);
        next(P) = NULL;
    }
};
void deleteLastAcara(ListAcara &LAcara, addressAcara &P, ListTalent &LTalent){
    //DEELTE LAST UNTUK LIST ACARA
    addressTalent QTalent;
    addressRelation QRelation, DRelation;
    addressAcara Q;
    Q = first(LAcara);
    if(first(LAcara)== NULL){
        cout<<"List ACARA KOSONG"<<endl;
    }else{
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        QTalent = first(LTalent);
         while(QTalent != NULL){
            if(firstRelation(QTalent) != NULL){
                QRelation= firstRelation(QTalent);
                while (QRelation != NULL){
                    if(next_acara(QRelation) == P ){
                        if(QRelation == firstRelation(QTalent)){
                            deleteFirstRelation(QTalent);
                        }else if(next_course(QRelation) == NULL){
                            deleteLastRelation(QTalent);
                        }else {
                            DRelation = firstRelation(QTalent);
                            while(next_course(DRelation) != QRelation){
                                DRelation = next_course(DRelation);
                            }
                            deleteAfteRelation(QTalent,DRelation);
                        }
                    }
                QRelation = next_course(QRelation);
                }
            }
            QTalent = next(QTalent);
        }
        next(Q) = NULL;
    }
};
void deleteAfterAcara(ListAcara &LAcara, addressAcara &P, addressAcara Prec, ListTalent &LTalent){
    //DELETE AFTER UNTUK LIST ACARA
    addressTalent QTalent;
    addressRelation QRelation, DRelation;
    if(first(LAcara) == NULL){
        cout<<"List ACARA KOSONG"<<endl;
    }else{
        P = next(Prec);
        QTalent = first(LTalent);
          while(QTalent != NULL){
            if(firstRelation(QTalent) != NULL){
                QRelation= firstRelation(QTalent);
                while (QRelation != NULL){
                    if(next_acara(QRelation) == P ){
                        if(QRelation == firstRelation(QTalent)){
                            deleteFirstRelation(QTalent);
                        }else if(next_course(QRelation) == NULL){
                            deleteLastRelation(QTalent);
                        }else {
                            DRelation = firstRelation(QTalent);
                            while(next_course(DRelation) != QRelation){
                                DRelation = next_course(DRelation);
                            }
                            deleteAfteRelation(QTalent,DRelation);
                        }
                    }
                QRelation = next_course(QRelation);
                }
            }
            QTalent = next(QTalent);
        }
        next(Prec) = next(P);
        next(P) = NULL;
    }
};
void printAcara(ListAcara LAcara){
    //MENGELUARKAN SEMUA INFO UNTUK LIST ACARA
    addressAcara Q;
    Q = first(LAcara);
    if(first(LAcara) == NULL){
        cout<<"LIST ACARA KOSONG"<<endl;
    }else{
        while(Q != NULL){
            cout<<"- Nama Acara :"<<info(Q).namaAcara<<endl;
            cout<<"  Tanggal    :"<<info(Q).tanggal<<endl;
            cout<<"  Tempat     :"<<info(Q).tempat<<endl;
            cout<<endl;
            Q = next(Q);
        }
    }
};
void PrintAcaraTertentu (ListAcara LAcara, string NamaAcara){
    //PRINT ACARA TERTENTU
    addressAcara Q;
    Q = first(LAcara);
    if (first(LAcara) == NULL){
        cout<<"TIDAK ADA ACARA"<<endl;
    }else {
        while(Q != NULL){
            if (info(Q).namaAcara == NamaAcara){
                cout<< "- Nama Acara : "<<info(Q).namaAcara<<endl;
                cout<< "  Tanggal    : "<<info(Q).tanggal<<endl;
                cout<< "  Tanggal    : "<<info(Q).tempat<<endl;
            }else{
                Q = next(Q);
            }
        }
    }
};
addressAcara searchAcara (ListAcara LAcara,string NamaAcara){
    //SEARCHING ACARA
    addressAcara PAcara;
    addressAcara Q;
    Q = first(LAcara);
    PAcara = NULL;
    while(Q!= NULL){
        if(info(Q).namaAcara == NamaAcara){
            PAcara = Q;
            return PAcara;
        }else{
            Q = next(Q);
        }
    }
    return PAcara;

};

////////////////////////////////////////////////////////////////////////////////////

void createListTalent(ListTalent &LTalent){
    //CREATE LIST UNTUK LIST TALENT
    first(LTalent) = NULL;
};

addressTalent createElmTalent(infotypetalent Xtalent){
    //MEMBUAT ELEMENT TALNET UNTUK LIST TALENT
    addressTalent P;
    P = new elmListTalent;
    info(P) = Xtalent;
    next(P) = NULL;
    firstRelation(P) = NULL;
};
void insertFirstTalent(ListTalent &LTalent, addressTalent P){
    //INSERT FIRST UNTUK LIST TALENT
    if (first(LTalent) == NULL){
        first(LTalent) = P;
    }else{
        next(P) = first(LTalent);
        first(LTalent) = P;
    }
};
void inserLastTalent(ListTalent &LTalent, addressTalent P){
    //INSERT LAST UNTUK LIST TALENT
    addressTalent Q;
    Q = first(LTalent);
    if(first(LTalent) == NULL){
        first(LTalent) = P;
    }else{
        while(next(Q)!= NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
};
void insertAfterTalent(ListTalent &LTalent, addressTalent P, addressTalent Prec) {
    // INSERT AFTER UNTUK LIST TALENT
    if(Prec == NULL){
        cout<<"TIDAK ADA TALENT"<<endl;
    }else{
        if (first(LTalent) == NULL) {
            first(LTalent) = P;
        } else {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void deleteFirstTalent(ListTalent &LTalent, addressTalent &P){
    //DELETE FIRST LIST TALENT
   if(first(LTalent) == NULL){
        cout<<"LIST TALENT KOSONG"<<endl;
    }else{
        while(firstRelation(first(LTalent))!= NULL){
            deleteFirstRelation(first(LTalent));
        }
        P = first(LTalent);
        first(LTalent) = next(P);
        next(P) = NULL;
        firstRelation(P) = NULL;
    }
};

void deleteLastTalent(ListTalent &LTalent, addressTalent &P){
    //DELETE LAST LIST TALENT
    addressTalent Q;
    Q= first(LTalent);
    if(first(LTalent) == NULL){
        cout<<"LIST TALENT KOSONG"<<endl;
    }else{
        while(next(next(Q)) != NULL){
            Q= next(Q);
        }
        while(firstRelation(next(Q)) != NULL){
            deleteFirstRelation(next(Q));
        }
        P = next(Q);
        next(Q) = NULL;
        next(P) = NULL;
        firstRelation(P) = NULL;
    }
};
void deleteAfterTalent(ListTalent &LTalent, addressTalent &p, addressTalent prec){
    //DELETE AFTER TALENT
    if(first(LTalent) == NULL){
        cout<<"LIST TALENT KOSONG"<<endl;
    }else{
        p = next(prec);
        while(firstRelation(p) != NULL){
            deleteFirstRelation(p);
        }
        next(prec) = next(p);
        next(p) = NULL;
        firstRelation(p) = NULL;
    }
};
void printTalent(ListTalent LTalent){
    //PRINT SEMUA INFO LIST TALENT
    addressTalent Q;
    Q = first(LTalent);
    while(Q != NULL){
        cout<< "- Nama          : " <<info(Q).nama<<endl;
        cout<< "  Jenis Kelamin : " <<info(Q).jeniskelamin<<endl;
        cout<< "  Umur          : " <<info(Q).umur<<endl;
        cout<< "  Bakat         : " <<info(Q).bakat<<endl;
        cout<<endl;
        Q = next(Q);
    }
};
addressTalent searchTalent(ListTalent LTalent, string NamaTalent){
    //SEARCHING TALENT
    addressTalent PTalent;
    addressTalent Q;
    Q = first(LTalent);
    PTalent= NULL;
    while(Q != NULL){
        if(info(Q).nama == NamaTalent){
            PTalent = Q;
            return PTalent;
        }else{
            Q = next(Q);
        }
    }
    return PTalent;
};


/////////////////////////////////////////////////////////////////////////////////////
addressRelation createElmRelation(addressAcara Pacara){
    //MEMBUAT ELEMENT RELATION UNTUK LIST RELATION
    addressRelation P;
    P = new elmListRelation;
    next_course(P) = NULL;
    next_acara(P) = Pacara;

    return P;
};
void insertFirstRelation(addressTalent &PTalent, addressRelation P){
    //INSERT FIRST UNTUK RELATION
    if(firstRelation(PTalent) == NULL){
        firstRelation(PTalent) = P;
    }else{
        next_course(P)= firstRelation(PTalent);
        firstRelation(PTalent) = P;
    }
};
void inserLastRelation(addressTalent &PTalent, addressRelation P){
    //INSERT LAST UNTUK RELATION
    addressRelation Q;
    if (firstRelation(PTalent) == NULL){
        firstRelation(PTalent) = P;
    }else{
        Q = firstRelation(PTalent);
        while(next_course(Q)!= NULL){
            Q = next_course(Q);
        }
        next_course(Q) = P;
    }
};
void insertAfterRelation(addressTalent &PTalent, addressRelation P, addressRelation Prec){
    //INSERT AFTER RELASI
    if(firstRelation(PTalent) == NULL){
        firstRelation(PTalent) = P;
    }else{
        next_course(P) = next_course(Prec);
        next_course(Prec) = P;
    }
};
void  deleteFirstRelation(addressTalent &PTalent){
    //DELETE FIRST UNTUK LIST RELATION
    addressRelation P;
    if(firstRelation(PTalent) == NULL){
        cout<<"TIDAK ADA ACARA"<<endl;
    }else{
        P = firstRelation(PTalent);
        firstRelation(PTalent) = next_course(P);
        next_acara(P) = NULL;
        next_course(P) = NULL;
    }
};
void deleteAfteRelation(addressTalent &PTalent, addressRelation Prec){
    //DELETE AFTER RELASI
    addressRelation P;
    if(firstRelation(PTalent) == NULL){
        cout<<"TIDAK ADA ACARA"<<endl;
    }else{
        P = next_course(Prec);
        next_course(Prec) = next_course(P);
        next_acara(P) = NULL;
        next_course(P) = NULL;
    }
};
void deleteLastRelation(addressTalent &PTalent) {
    // DELETE LAST UNTUK LIST RELATION
    addressRelation P;
    addressRelation Q;
    Q = firstRelation(PTalent);

    if (Q == NULL) {
        cout << "TIDAK ADA ACARA" << endl;
    }else{
        while(next_course(next_course(Q)) != NULL){
            Q = next_course(Q);
        }
        P = next_course(Q);
        next_course(P) = NULL;
        next_course(Q) = NULL;
    }
}
void Relation(ListTalent &LTalent,string namaTalent, ListAcara LAcara,string namaAcara){
    //Relasi acara dan talent
    int kondisi;
    string namaA;
    addressRelation PR;
    addressTalent Q;
    addressAcara H;
    addressRelation PRelation;
    Q = searchTalent(LTalent,namaTalent);
    H = searchAcara(LAcara,namaAcara);
    PRelation = createElmRelation(H);
    cout << "-------------------------" << endl;
    cout<<"1. Insert First"<<endl;
    cout<<"2. Insert After"<<endl;
    cout<<"3. Insert Last"<<endl;
    cout<<"Select One : ";
    cin>>kondisi;
    cout << "-------------------------" << endl;
    if(kondisi == 1){
        insertFirstRelation(Q,PRelation);
    }else if(kondisi == 2){
        cout<<"Ingin masuk setelah :";
        cin>>namaA;
        PR = searchRelasi(Q,namaA);
        insertAfterRelation(Q,PRelation,PR);
    }else if(kondisi == 3){
        inserLastRelation(Q,PRelation);
    }
};

void showRelation(ListTalent Ltalent, string namaTalent){
    //SHOW TALENT DAN ACARA
    addressTalent T;
    addressRelation R;
    T = first(Ltalent);
    while(T != NULL){
        if(info(T).nama == namaTalent){
            R = firstRelation(T);
            while( R != NULL){
                cout<< "- Nama Acara : "<<info(next_acara(R)).namaAcara<<endl;
                cout<< "  Tanggal    : "<<info(next_acara(R)).tanggal<<endl;
                cout<< "  Tempat     : "<<info(next_acara(R)).tempat<<endl;
                cout<< endl;
                R=next_course(R);
            }
            T= next(T);
        }else{
            T = next(T);
        }
    }
};
void showAcara(ListTalent Ltalent, string namaTalent, string namaAcara) {
    // Search Acara Talent
    addressTalent T;
    addressAcara PA = NULL;
    addressRelation R;
    T = first(Ltalent);
    while (T != NULL) {
        if (info(T).nama == namaTalent) {
            R = firstRelation(T);
            while (R != NULL) {
                if (info(next_acara(R)).namaAcara == namaAcara) {
                    PA = next_acara(R);
                }
                R = next_course(R);
            }
            T = next(T);
        } else {
            T = next(T);
        }
    }
    if (PA == NULL) {
        cout << namaTalent << " tidak menghadiri acara " << namaAcara << endl;
    } else {
         cout << "==== Acara Ditemukan ====" << endl;
        cout << "- Nama Acara : " << info(PA).namaAcara << endl;
        cout << "  Tanggal    : " << info(PA).tanggal << endl;
        cout << "  Tempat     : " << info(PA).tempat << endl;
    }
}
void countAcara(ListTalent Ltalent, string namaTalent){
    //COUT Acara yang dimiliki talent
    addressTalent Q;
    addressRelation H;
    int jumlahAcara;
    jumlahAcara = 0;
    Q = first(Ltalent);
    while(Q != NULL and info(Q).nama != namaTalent){
        Q = next(Q);
    }
    H = firstRelation(Q);
    if(H == NULL){
        cout<< namaTalent <<" tidak menghadiri acara apapun"<<endl;
    }else{
        while(H != NULL){
            jumlahAcara++;
            cout<< "- Nama Acara :  "<<info(next_acara(H)).namaAcara<<endl;
            cout<< "  Tanggal    :  "<<info(next_acara(H)).tanggal<<endl;
            cout<< "  Tempat     :  "<<info(next_acara(H)).tempat<<endl;
            cout<<endl;
            H = next_course(H);
        }
        cout<<"Menghadiri Sebanyak : "<<jumlahAcara<< " Acara"<<endl;
    }
};
addressRelation searchRelasi(addressTalent PTalent, string namaAcara){
    //Searhing Relasi
    addressRelation Q;
    addressRelation PRelasi = NULL;
    Q = firstRelation(PTalent);
    while(Q!= NULL){
        if(info(next_acara(Q)).namaAcara == namaAcara){
            PRelasi = Q;
            return PRelasi;
        }else{
            Q = next_course(Q);
        }
    }
    return PRelasi;
};
void showAllRelasi(ListTalent Ltalent){
    addressTalent Ptalent;
    addressRelation Prelasi;
    Ptalent = first(Ltalent);
    while(Ptalent != NULL){
        cout<<"Acara "<<info(Ptalent).nama << " : "<<endl;
        if(firstRelation(Ptalent) == NULL){
            cout<<"TIDAK MENGHADIRI ACARA APUN"<<endl;
            cout<<endl;
        }else {
            Prelasi = firstRelation(Ptalent);
            while(Prelasi != NULL){
                cout<< "- Nama Acara : " <<info(next_acara(Prelasi)).namaAcara<<endl;
                cout<< "  Tanggal    : " <<info(next_acara(Prelasi)).tanggal<<endl;
                cout<< "  Tempat     : " <<info(next_acara(Prelasi)).tempat<<endl;
                cout << endl;
                Prelasi = next_course(Prelasi);
            }
            cout<<endl;
        }
        Ptalent = next(Ptalent);
    }
};

void dataDummyTalent(ListTalent &LTalent){
    addressTalent P;
    infotypetalent DataTalent;

    DataTalent.nama         = "Rafianto";
    DataTalent.jeniskelamin = "Laki-Laki";
    DataTalent.umur         = 19;
    DataTalent.bakat        = "bernyanyi";
    P = createElmTalent(DataTalent);
    inserLastTalent(LTalent,P);

    DataTalent.nama         = "Udin_Garing";
    DataTalent.jeniskelamin = "Laki-Laki";
    DataTalent.umur         = 21;
    DataTalent.bakat        = "Pelawak";
    P = createElmTalent(DataTalent);
    inserLastTalent(LTalent,P);

    DataTalent.nama         = "Ujang_Ronda";
    DataTalent.jeniskelamin = "Laki-Laki";
    DataTalent.umur         = 28;
    DataTalent.bakat        = "Aktor";
    P = createElmTalent(DataTalent);
    inserLastTalent(LTalent,P);

    DataTalent.nama         = "Kobo";
    DataTalent.jeniskelamin = "Perempuan";
    DataTalent.umur         = 22;
    DataTalent.bakat        = "bernyanyi";
    P = createElmTalent(DataTalent);
    inserLastTalent(LTalent,P);
};
void dataDummAcara(ListAcara &LAcara){
    addressAcara P;
    infotypeacara DataAcara;

    DataAcara.namaAcara     = "Gathering_Anto_Dunia";
    DataAcara.tanggal       =  11224;
    DataAcara.tempat        = "Gedung Anto";
    P = createElmAcara(DataAcara);
    inserLastAcara(LAcara,P);

    DataAcara.namaAcara     = "Anime_Festival_Asia";
    DataAcara.tanggal       = 21223;
    DataAcara.tempat        = "TUCH";
    P = createElmAcara(DataAcara);
    inserLastAcara(LAcara,P);

    DataAcara.namaAcara     = "Indonesia_Award";
    DataAcara.tanggal       = 91223;
    DataAcara.tempat        = "JIS";
    P = createElmAcara(DataAcara);
    inserLastAcara(LAcara,P);
};
void DummyRelasi(ListTalent &LTalent, ListAcara &LAcara){
    addressAcara H;
    addressTalent Q;
    addressRelation R;
    Q = searchTalent(LTalent,"Rafianto");
    H = searchAcara(LAcara,"Gathering_Anto_Dunia" );
    R = createElmRelation(H);
   insertFirstRelation(Q,R);
    Q = searchTalent(LTalent,"Rafianto");
    H = searchAcara(LAcara, "Anime_Festival_Asia");
    R= createElmRelation(H);
    inserLastRelation(Q,R);
    Q = searchTalent(LTalent,"Ujang_Ronda");
    H = searchAcara(LAcara,"Indonesia_Award");
    R= createElmRelation(H);
    inserLastRelation(Q,R);
    Q = searchTalent(LTalent,"Kobo");
    H = searchAcara(LAcara, "Anime_Festival_Asia");
    R= createElmRelation(H);
    insertFirstRelation(Q,R);
    Q = searchTalent(LTalent, "Kobo");
    H = searchAcara(LAcara, "Indonesia_Award");
    R = createElmRelation(H);
    inserLastRelation(Q,R);
}
