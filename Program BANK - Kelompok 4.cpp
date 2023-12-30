#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Tampilan 

void garis(){
 cout << "==============( BANK UNDIRA )==============" << endl;
}

void setoruang(){
 cout << "==============( SETOR UANG )==============" << endl;
}

void tarikuang(){
 cout << "==============( TARIK UANG )==============" << endl;
}

void kpr(){
 cout << "=================( KPR )=================" << endl;
}

void garis_bawah(){
 cout << "==========================================" << endl;
}

// Fungsi Perulangan Untuk Deposit Atau Setoran Awal

void isiNominal(float& Nominal) {
    do {
    	cout << endl;
        cout << "Masukan Nominal : "; cin >> Nominal;

        if (Nominal < 100000) {
        	cout << endl;
        	cout << "Setoran Tidak Mencukupi." << endl;
            cout << "Nominal harus lebih dari atau sama dengan 100000." << endl;
			cout << "Silakan masukkan kembali." << endl;
        }
    } while (Nominal < 100000);
}

int main(){
	
	// Deklarasi Variabel
	int command, 
		NIK, 
		NPWP, 
		No_Telp, 
		PIN, 
		No_Rek = 2023120001, 
		No_KK,
		Tenor;
	float Nominal, 
		Saldo, 
		Setor, 
		Tarik, 
		slip_gaji,
		Harga_Properti,
		Uang_Muka,
		bunga = 3.7 / 100,
		totalHutang,
		Cicilan_Bulanan;
	string Nama, Alamat;
	char Jenis_Kelamin[0];
	
	// Menu Utama Program
	garis();
	cout << endl << "1. Pembuatan Rekening Baru";
	cout << endl << "2. Deposit";
	cout << endl << "3. Pengajuan KPR";
	cout << endl << "4. Keluar" << endl;
	garis_bawah();
	cout << endl << "Pilih Menu : "; cin >> command;
	
	// Deklarasi Variabel DB
	int db_pin = 202312, 
		db_no_rek = 2023120002;
//		db_no_rek2 = 202312003;
	float db_saldo = 4500000;
	string db_nama = "Rohim";


switch (command){

	// Pembuatan Rekening Baru
	case 1:
	system ("cls");
	garis();
	cout << endl;
	cout << "NIK : "; cin >> NIK;								// Wajib Isi
	cout << "NPWP : "; cin >> NPWP;								// Wajib Isi	
	cout << "Nama : "; cin >> Nama;
	cout << "Jenis Kelamin [L/P] : "; cin >> Jenis_Kelamin;
	cout << "Alamat : "; cin >> Alamat;
	cout << "Nomor Telepon : "; cin >> No_Telp;
	cout << "PIN : "; cin >> PIN;								// Wajib Isi
	
	if (NIK != 0 && NPWP != 0 && PIN != 0){						// Kondisi NIK, NPWP, PIN Tidak Boleh Kosong. Jika Diisi Maka Program Bisa Lanjut
		system ("cls");
		setoruang();											// Setor Uang
		isiNominal(Nominal);
		Saldo = Nominal + Saldo;								// Proses Saldo Dari Nominal Setoran Awal + Saldo Saat Ini
				
		// Tampilkan Hasil
		system ("cls");
		garis();												// Status Berhasil							
		cout << "Nama : " << Nama << endl;
		cout << "Jenis Kelamin : " << Jenis_Kelamin << endl;
		cout << "Alamat : " << Alamat << endl;
		cout << "Nomor Telepon : " << No_Telp << endl;
		cout << "Nomor Rekening : " << No_Rek << endl;
		cout << "PIN : " << PIN << endl;
		garis_bawah();
		cout << "Saldo : Rp." << Nominal;
		
	}
	else{
		system ("cls");
		cout << endl << "NIK, NPWP & PIN Tidak Boleh Kosong";
		cout << endl << "Program Selesai.";
	}
	break;
	
	
	// Deposit
	case 2:
	system ("cls");
	garis();
	cout << endl;
	cout << "Nomor Rekening : "; cin >> No_Rek;
	cout << "PIN : "; cin >> PIN;
	
	if (No_Rek == db_no_rek && PIN == db_pin){								// Kondisi Pengecheckan Nomor Rekening & PIN
		system ("cls");
		garis();
		cout << endl;
		cout << "1. Setor Uang" << endl;
		cout << "2. Tarik Uang" << endl;
		garis_bawah();
		cout << endl << "Pilih Menu : "; cin >> command;
		
				switch(command){
					
						// Setor Uang
						case 1:
						system("cls");
						setoruang();
						isiNominal(Nominal);
						Saldo = Nominal + db_saldo;
						
						// Tampilkan Hasil
						system("cls");
						garis();
						cout << endl;
						cout << "Nama : " << db_nama << endl;
						cout << "Rekening : " << db_no_rek << endl;
						cout << "Nominal Setor : " << Nominal << endl;
						std::cout << std::fixed << std::setprecision(0) << "Total Saldo Saat Ini : Rp." << Saldo << endl;
						garis_bawah();
						break;
						
						// Tarik Uang
						case 2:
						system("cls");
						tarikuang();
						cout << endl;
						cout << "Masukan Nominal : "; cin >> Tarik;
						Saldo = db_saldo - Tarik;
						
						// Tampilkan Hasil						
						system("cls");
						garis();
						cout << endl;
						cout << "Nama : " << db_nama << endl;
						cout << "Rekening : " << db_no_rek << endl;
						cout << "Penarikan : Rp." << Tarik << endl;
						std::cout << std::fixed << std::setprecision(0) << "Total Saldo Saat Ini : Rp. " << Saldo <<endl;
						break;
} 	
	}
	else{
		system ("cls");
		garis();
		cout << endl;
		cout << "NOMOR REKENING ATAU PIN SALAH!" << endl;
	}
	break;
	
	// Pengajuan KPR
	case 3:
	system ("cls");
	garis();
	cout << endl;
	cout << "Nomor Rekening : "; cin >> No_Rek;
	
	if(No_Rek == db_no_rek){										// Kondisi Pengecheckan Nomor Rekening
		system("cls");
		garis();
		cout << "1. KPR" << endl;
		garis_bawah();
		cout << endl << "Pilih Menu : "; cin >> command;		
		
		// KPR
		switch(command){
			case 1:
			system("cls");
			kpr();
			cout << endl;
			cout << "NIK Pemohon : "; cin >> NIK;
			cout << "No. KK : "; cin >> No_KK;
			cout << "NPWP : "; cin >> NPWP;
			cout << "Slip Gaji : "; cin >> slip_gaji;

		if (NIK !=0 && No_KK !=0 && NPWP !=0 && slip_gaji !=0){		// Kondisi Pengecheckan NIK, No. KK, NPWP, Dan Slip Gaji Tidak Boleh Kosong. Jika Diisi Maka Program Bisa Lanjut 
			system("cls");
			kpr();
			cout << endl;
			cout << "Harga Properti : "; cin >> Harga_Properti;
			cout << "Uang Muka : "; cin >> Uang_Muka;
			cout << "Tenor [Tahun] : "; cin >> Tenor;
			cout << "Bunga : 3.7% ";
			totalHutang = Harga_Properti - Uang_Muka;
			Tenor = Tenor * 12;										// Jumlah Tenor 1 Tahun = 12 Bulan
			Cicilan_Bulanan = (totalHutang * bunga) / (12 * (1 - 1 / pow(1 + bunga / 12, Tenor)));		// Rumus Cicilan Bulanan
				
				if(Cicilan_Bulanan <= slip_gaji){					// Kondisi Jika Cicilan Bulanan Lebih Besar Atau Sama Dengan Slip Gaji, Maka Pengajuan KPR Diterima		
					system("cls");
					kpr();
					cout << endl;
					cout << "Nama : " << db_nama << endl;
					std::cout << std::fixed << std::setprecision(0) << "Harga Properti : Rp." << Harga_Properti << endl;
					std::cout << std::fixed << std::setprecision(0) << "Cicilan Perbulan : Rp." << Cicilan_Bulanan << endl;
					cout << "Tenor [Bulan] : " << Tenor << endl;
					cout << "Bunga : 3.7%" << endl;
					cout << "Pengajuan KPR : APPROVED" << endl;
				}
				else{												// Jika Cicilan Bulanan Kurang dari Slip Gaji, Maka Pengajuan KPR Ditolak
					system("cls");
					kpr();
					cout << endl;
					cout << "Nama : " << db_nama << endl;
					std::cout << std::fixed << std::setprecision(0) << "Harga Properti : Rp." << Harga_Properti << endl;
					std::cout << std::fixed << std::setprecision(0) << "Cicilan Perbulan : Rp." << Cicilan_Bulanan << endl;
					cout << "Tenor [Bulan] : " << Tenor << endl;
					cout << "Bunga : 3.7%" << endl;
					cout << "Pengajuan KPR : REJECTED" << endl;
				}
		}
		else{
			cout << endl;
			cout << "NIK, No. KK, NPWP, Slip Gaji Tidak Boleh Kosong.";
		}
		break;


		}
	}
	else{
		system("cls");
		garis();
		cout << endl;
		cout << "Nomor Rekening Tidak Ditemukan." << endl;
		cout << "Silahkan Periksa Kembali / Lakukan Pembuatan Rekening Baru." << endl;
	}
	break;
	
	case 4:
	system ("cls");
	garis();
	system ("exit");
	cout << endl << "Program Selesai";
	cout << endl;
	break;
	
	default:
	cout << endl << "Menu yang Anda pilih tidak ada !";
	
}

}
