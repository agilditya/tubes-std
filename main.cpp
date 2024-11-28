#include "tubes.h"


int main(){
    ListTalent LTalent;
    ListAcara LAcara;
    addressTalent Ptalent,Prec, Stalent;
    addressAcara Pacara, PrecAcara, SAcara;
    addressRelation Srelasi;
    int pilihan,pilihanInsertTalent,PilihanDeleteTalent;
    string cariTalent, cariAcara;
    int pilihanInsertAcara,PilihanDeleteAcara;
    infotypetalent DataTalent;
    infotypeacara DataAcara;
    string namaTalent, namaAcara;

    // DATA DUMMY
    createListTalent(LTalent);
    dataDummyTalent(LTalent);
    createListAcara(LAcara);
    dataDummAcara(LAcara);
    DummyRelasi(LTalent,LAcara);
    dashboard();
    cout << "Select One : ";
    cin >> pilihan;
    while(pilihan != 99){
    //INSERT TALENT
       if (pilihan == 1) {
            cout << "-------------------------" << endl;
            cout << "Pilih Insert :" << endl;
            cout << "1.Insert First" << endl;
            cout << "2.Insert After" << endl;
            cout << "3.Insert Last" << endl;
            cout << "-------------------------" << endl;
            cout << "Select One : ";
            cin >> pilihanInsertTalent;
            //INSERT FIRST
            if (pilihanInsertTalent == 1) {
                cout << "----- Insert First ------" << endl;
                cout<<"Masukkan Nama Talent   : ";
                cin>>DataTalent.nama;
                cout<<"Masukkan Umur          : ";
                cin>>DataTalent.umur;
                cout<<"Masukkan Jenis Kelamin : ";
                cin>>DataTalent.jeniskelamin;
                cout<<"Masukkan Bakat         : ";
                cin>>DataTalent.bakat;
                Ptalent = createElmTalent(DataTalent);
                insertFirstTalent(LTalent,Ptalent);

            //INSERT AFTER
            } else if (pilihanInsertTalent == 2) {
                cout << "----- Insert After ------" << endl;
                cout<<"Masukkan Nama Talent   : ";
                cin>>DataTalent.nama;
                cout<<"Masukkan Umur          : ";
                cin>>DataTalent.umur;
                cout<<"Masukkan Jenis Kelamin : ";
                cin>>DataTalent.jeniskelamin;
                cout<<"Masukkan Bakat         : ";
                cin>>DataTalent.bakat;
                Ptalent = createElmTalent(DataTalent);
                cout << endl;
                cout << "Ingin Masuk Setelah Talent : ";
                cin >> cariTalent;
                Prec = searchTalent(LTalent,cariTalent);
                insertAfterTalent(LTalent,Ptalent,Prec);

            //INSERT LAST
            } else if (pilihanInsertTalent == 3) {
                cout << "----- Insert Last -------" << endl;
                cout<<"Masukkan nama Talent   : ";
                cin>>DataTalent.nama;
                cout<<"Masukkan Umur          : ";
                cin>>DataTalent.umur;
                cout<<"Masukkan Jenis Kelamin : ";
                cin>>DataTalent.jeniskelamin;
                cout<<"Masukkan Bakat         : ";
                cin>>DataTalent.bakat;
                Ptalent = createElmTalent(DataTalent);
                inserLastTalent(LTalent,Ptalent);
            }
            cout << endl;
            cout << "===================================================" << endl;
            cout << "=============== SEMUA TALENT ======================" << endl;
            printTalent(LTalent);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SEARCH TALENT
        } else if (pilihan == 2) {
            cout << "-------------------------" << endl;
            cout << "Masukkan Talent yang akan dicari : ";
            cin >> cariTalent;
            Stalent = searchTalent(LTalent,cariTalent);
            if(Stalent == NULL){
                cout<<"TALENT TIDAK DITEMUKAN"<<endl;
            }else {
                cout << endl;
                cout << "=== Talent Ditemukan ====" << endl;
                cout<<"Nama          : "<<info(Stalent).nama<<endl;
                cout<<"Jenis Kelamin : "<<info(Stalent).jeniskelamin<<endl;
                cout<<"Umur          : "<<info(Stalent).umur<<endl;
                cout<<"Bakat         : "<<info(Stalent).bakat<<endl;
            }
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //DELETE TALENT
        }else if (pilihan == 3 ) {
            cout << "-------------------------" << endl;
            cout << "====== Pilih Talent =====" << endl;
            printTalent(LTalent);
            cout << "-------------------------" << endl;
            cout << "Pilih Delete :" << endl;
            cout << "1.Delete First" << endl;
            cout << "2.Delete After" << endl;
            cout << "3.Delete Last" << endl;
            cout << "-------------------------" << endl;
            cout << "Select One : ";
            cin >> PilihanDeleteTalent;
            cout << "-------------------------" << endl;
            //DELETE FIRST
            if (PilihanDeleteTalent == 1) {
                deleteFirstTalent(LTalent,Ptalent);

            //DELETE AFTER
            }else if(PilihanDeleteTalent == 2){
                cout <<"Ingin Delete Setelah Talent : ";
                cin>>cariTalent;
                Prec = searchTalent(LTalent,cariTalent);
                deleteAfterTalent(LTalent,Ptalent,Prec);

            //DELETE LAST
            } else if (PilihanDeleteTalent == 3) {
                deleteLastTalent(LTalent,Ptalent);
            }
            cout << "-------------------------" << endl;
            cout << "===== Talent Update =====" << endl;
            printTalent(LTalent);
            cout << "-------------------------" << endl;
            dashboard();
            cout << "Select One :";
            cin>> pilihan;

        //SHOW SEMUA TALENT
        } else if (pilihan == 4){
            cout << "-------------------------" << endl;
            printTalent(LTalent);
            cout << "-------------------------" << endl;
            cout << "======== TALENT =========" << endl;
            dashboard();
            cout<<endl;
            cout << "Select One :";
            cin>> pilihan;

        //INSERT ACARA
        } else if (pilihan == 5 ){
            cout << "-------------------------" << endl;
            cout << "Pilih Insert :" << endl;
            cout << "1.Insert First" << endl;
            cout << "2.Insert After" << endl;
            cout << "3.Insert Last" << endl;
            cout << "-------------------------" << endl;
            cout << "Select One : ";
            cin >> pilihanInsertAcara;
            //INSERT FIRST
            if (pilihanInsertAcara == 1) {
                cout << "-------------------------" << endl;
                cout<<"Masukkan nama Acara  : ";
                cin>>DataAcara.namaAcara;
                cout<<"Masukkan Tanggal     : ";
                cin>>DataAcara.tanggal;
                cout<<"Masukkan Tempat      : ";
                cin>>DataAcara.tempat;
                cout << "-------------------------" << endl;
                Pacara = createElmAcara(DataAcara);
                insertFirstAcara(LAcara,Pacara);

            //INSERT AFTER
            } else if (pilihanInsertAcara == 2) {
                cout<<"Masukkan nama Acara  : ";
                cin>>DataAcara.namaAcara;
                cout<<"Masukkan Tanggal     : ";
                cin>>DataAcara.tanggal;
                cout<<"Masukkan Tempat      : ";
                cin>>DataAcara.tempat;
                Pacara = createElmAcara(DataAcara);
                cout << "-------------------------" << endl;
                cout << "masukkan setelah acara : ";
                cin >> cariAcara;
                cout << "-------------------------" << endl;
                PrecAcara = searchAcara(LAcara,cariAcara);
                insertAfterAcara(LAcara,Pacara,PrecAcara);

            //INSERT LAST
            } else if (pilihanInsertAcara == 3) {
                cout<<"Masukkan nama Acara  : ";
                cin>>DataAcara.namaAcara;
                cout<<"Masukkan Tanggal     : ";
                cin>>DataAcara.tanggal;
                cout<<"Masukkan Tempat      : ";
                cin>>DataAcara.tempat;
                Pacara = createElmAcara(DataAcara);
                inserLastAcara(LAcara,Pacara);
            }
            printAcara(LAcara);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SEARCH ACARA
        } else if (pilihan == 6 ){
            cout << "-------------------------" << endl;
            cout << "Masukkan Acara yang akan dicari : ";
            cin >> cariAcara;
            SAcara = searchAcara(LAcara,cariAcara);
            cout << "-------------------------" << endl;
            if(SAcara == NULL){
                cout<<"ACARA TIDAK DITEMUKAN"<<endl;
            }else {
                cout << "-------------------------" << endl;
                cout << "==== Acara Ditemukan ====" << endl;
                cout<<"Nama Acara  : "<<info(SAcara).namaAcara<<endl;
                cout<<"Tanggal     : "<<info(SAcara).tanggal<<endl;
                cout<<"Tempaat     : "<<info(SAcara).tempat<<endl;
            }
            cout << "-------------------------" << endl;
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //DELETE ACARA
        } else if (pilihan == 7 ){
            cout << "-------------------------" << endl;
            printAcara(LAcara);
            cout << "-------------------------" << endl;
            cout << "Pilih Delete :" << endl;
            cout << "1.Delete First" << endl;
            cout << "2.Delete After" << endl;
            cout << "3.Delete Last" << endl;
            cout << "Select One : ";
            cin>>PilihanDeleteAcara;
            cout << "-------------------------" << endl;
            if(PilihanDeleteAcara == 1){
                deleteFirstAcara(LAcara,Pacara,LTalent);
                printAcara(LAcara);
            }else if(PilihanDeleteAcara == 2){
                cout << "-------------------------" << endl;
                cout<<"Ingin delete setelah acara : ";
                cin>>cariAcara;
                PrecAcara = searchAcara(LAcara,cariAcara);
                deleteAfterAcara(LAcara,Pacara,PrecAcara,LTalent);
            }else if (PilihanDeleteAcara == 3){
                deleteLastAcara(LAcara,Pacara,LTalent);
            }
            cout << "-------------------------" << endl;
            cout << "===== Acara Update ======" << endl;
            printAcara(LAcara);
            cout << "-------------------------" << endl;
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SHOW ALL ACARA
        } else if (pilihan == 8){
            cout << "-------------------------" << endl;
            cout << "======= ALL ACARA =======" << endl;
            printAcara(LAcara);
            cout << "-------------------------" << endl;
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //HUBUNGKAN RELASI TALENT DAN ACARA
        }else if (pilihan == 9){
            cout << "-------------------------" << endl;
            cout << "====== Talent Info ======" << endl;
            printTalent(LTalent);
            cout << "-------------------------" << endl;
            cout << "Masukkan Talent yang akan dicari : ";
            cin >> namaTalent;
            cout << "-------------------------" << endl;
            cout << "====== Acara Info =======" << endl;
            printAcara(LAcara);
            cout << "-------------------------" << endl;
            cout << "Masukkan Acara yang akan dicari : ";
            cin >> namaAcara;
            cout << "-------------------------" << endl;
            cout << "===== Pilih Insert ======" << endl;
            Relation(LTalent,namaTalent,LAcara,namaAcara);
            cout << "Acara yang dimiliki oleh " << namaTalent << endl;
            cout << endl;
            showRelation(LTalent,namaTalent);
            cout << "-------------------------" << endl;
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SEARCH ACARA
        }else if (pilihan == 10 ) {
            cout << "-------------------------" << endl;
            cout << "Masukkan nama Talent yang akan dicari : ";
            cin >> namaTalent;
            cout << "-------------------------" << endl;
            cout << "Masukkan nama Acara yang akan dicari : ";
            cin >> namaAcara;
            cout << "-------------------------" << endl;
            showAcara(LTalent,namaTalent,namaAcara);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //DELETE ACARA
        } else if (pilihan == 11 ){
            cout << "-------------------------" << endl;
            cout << "Pilih Delete :" << endl;
            cout << "1.Delete First" << endl;
            cout << "2.Delete After" << endl;
            cout << "3.Delete Last" << endl;
            cout << "-------------------------" << endl;
            cout<<"Select One : ";
            cin >> PilihanDeleteAcara;
            cout << "-------------------------" << endl;
            // DELETE FIRST
            if (PilihanDeleteAcara == 1) {
                cout << "Masukkan nama Talent yang akan dicari : ";
                cin >> namaTalent;
                Stalent = searchTalent(LTalent,namaTalent);
                deleteFirstRelation(Stalent);
            // DELETE AFTER
            }else if(PilihanDeleteAcara == 2){
                cout << "Masukkan nama Talent yang akan dicari : ";
                cin >> namaTalent;
                Stalent = searchTalent(LTalent,namaTalent);
                cout << "-------------------------" << endl;
                cout << "Ingin delete setelah acara : ";
                cin >> cariAcara;
                cout << "-------------------------" << endl;
                Srelasi = searchRelasi(Stalent,cariAcara);
                deleteAfteRelation(Stalent,Srelasi);
            //DELETE LAST
            } else if (PilihanDeleteAcara == 3) {
                cout << "Masukkan nama Talent yang akan dicari : ";
                cin >> namaTalent;
                Stalent = searchTalent(LTalent,namaTalent);
                deleteLastRelation(Stalent);
            }
            cout << "-------------------------" << endl;
            cout << "Acara yang tersedia untuk " << namaTalent << " : " << endl;
            cout << endl;
            showRelation(LTalent,namaTalent);
            dashboard();
            cout<<endl;
            cout << "Select One : ";
            cin>> pilihan;

        //COUNT ACARA
        } else if (pilihan == 12) {
            cout << "-------------------------" << endl;
            cout << "Masukkan Talent : ";
            cin >> namaTalent;
            cout << "-------------------------" << endl;
            cout << "========= Acara =========" << endl;
            countAcara(LTalent,namaTalent);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SHOW SEMUA TALENT DAN ACARA YANG ADA
        }else if (pilihan == 13) {
            cout << "-------------------------" << endl;
            cout << "====== SHOW TALENT ======" <<endl;
            cout << endl;
            printTalent(LTalent);
            cout << "-------------------------" << endl;
            cout << "====== SHOW ACARA =======" <<endl;
            cout << endl;
            printAcara(LAcara);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SHOW ACARA YANG DIMILIKI TALENT
        } else if (pilihan == 14) {
            cout << "-------------------------" << endl;
            cout << "Masukkan Relasi Talent yang akan dicari : ";
            cin >> namaTalent;
            cout << "-------------------------" << endl;
            cout << "====== SHOW ACARA =======" <<endl;
            showRelation(LTalent, namaTalent);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //SHOW SEMUA RELASI
        } else if (pilihan == 15){
            cout << "-------------------------" << endl;
            showAllRelasi(LTalent);
            dashboard();
            cout << "Select One : ";
            cin>> pilihan;

        //KELUAR PROGRAM
        } else if (pilihan == 0) {
            return 0;
        }
    }
}
