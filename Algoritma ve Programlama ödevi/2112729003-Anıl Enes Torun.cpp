#include<iostream>
#include <stdio.h>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

void kisiKayit(){
	string kisiAd;
	int kisiId;
	string kisisoyad;
	char cinsiyet;
	for(int i=0;i<1;i++){
		ofstream kayit;
		kayit.open("kuafor.txt",ios::app);
		
		cout<<"kiþi adi giriniz"<<endl;
		cin>>kisiAd;
		cout<<"kiþi id giriniz"<<endl;
		cin>>kisiId;
		cout<<"kiþi soyad giriniz"<<endl;
		cin>>kisisoyad;
		cout<<"cinsiyet giriniz"<<endl;
		cin>>cinsiyet;	  
		kayit<<endl<<kisiAd<<kisisoyad<<"-"<<kisiId<<"-"<<cinsiyet;
		kayit.close();
	}
}

int serach(string buffer,string str){
	int i=0,j;
	int m=str.length();
	while(i<=buffer.length()-m){
		j=0;
		while(j<m&&(buffer[i+j]==str[j])){
			j++;
		}if(j==m){
			return 1;
		}else i++;	
	}
	return 0;	
}

void kisiAra(){
	string ad;
	cout<<"kiþinin adini gir"<<endl;
	cin>>kisiad;
	int satirsayisi=0;
	int sayac=0;
	string satir;
	ifstream dosya("kullanici.txt");
	
	while(getline(dosya,satir)){
		satirsayisi++;
		if(serach(satir,kisiad)){
			sayac++;
			cout<<"bulundu";
			cout<<satirsayisi<<" .satir"<<endl;
		}
	}dosya.close();
	if(sayac==0){
		cout<<"bulunamadi"<<endl;
	}
}

void kisiSilme(){
	string kisiAd;
	int kisiId;
	string kisisoyad;
	char cinsiyet;
	
	int id;
	cout<<"id giriniz"<<endl;
	cin>>id;
	
	ifstream Acma("kuafor.txt");
	ofstream Gecici("Gecici.txt");
	
	while(!(Acma.eof())){
		Acma>>kisiAd>>kisiId>>kisisoyad>>cinsiyet;
		if(id==kisiId){
			cout<<"silindi"<<endl;
		}else{
			Gecici<<endl<<kisiId<<" "<<kisiAd<<" "<<kisisoyad<<" "<<cinsiyet;
		}
	}
	Acma.close();
	Gecici.close();
	
	remove("kuafor.txt");
	rename("Gecici.txt","kuafor.txt");
}

void kisiDuzenle(){
	
	string kisiAd;
	int kisiId;
	string kisisoyad;
	char cinsiyet;
	
	int id;
	cout<<"id giriniz"<<endl;
	cin>>id;
	
	ifstream Acma("kuafor.txt");
	ofstream Gecici("Gecici.txt");
	while(!(Acma.eof())){
		
		Acma>>kisiAd>>kisiId>>kisisoyad>>cinsiyet;
		if(id==kisiId){
			cout<<"kiþinin adini giriniz"<<endl;
			cin>>kisiAd;
			cout<<"kiþinin Id giriniz"<<endl;
			cin>>kisiId;
			cout<<"kiþinin soyadýný  giriniz"<<endl;
			cin>>kisisoyad;
			cout<<"kiþinin cinsiyetini giriniz"<<endl;
			cin>>cinsiyet;
			Gecici<<endl<<kisiAd<<" "<<kisiId<<" "<<kisisoyad<<" "<<cinsiyet;
		}else{
			Gecici<<endl<<kisiAd<<" "<<kisiId<<" "<<kisisoyad<<" "<<cinsiyet;
		}
	}
	Acma.close();
	Gecici.close();
		
	remove("kuafor.text");
	rename("Gecici.txt","kuafor.txt");	
}

void listele(){
	const int max=80;
	char buffer[max];
	ifstream oku("kuafor.txt");
	while(!oku.eof()){
		oku.getline(buffer,max);
		cout<<buffer<<endl;
	}
}


int main(){
	ifstream Acma("kuafor.txt");
		
	int secim;
	
	cout<<"****KUAFOR MAGAZAMIZA HOS GELDINIZ YAPMAK ISTEDIGINIZ ISLEMI TUSLAYINIZ*****"<<endl;
	cout<<"1-kiþi kayit islemi"<<endl;
	cout<<"2-kiþi arama"<<endl;
	cout<<"3-kiþi duzeltme"<<endl;
	cout<<"4-kiþi silme"<<endl;
	cout<<"5-kiþileri listele"<<endl;
	cout<<"6-CIKIS"<<endl;
	cin>>secim;
	
	if(secim==1){
		kisiKayit();
		cout<<"kayit basarili"<<endl;
	}else if(secim==2){
		kisiAra();
	}else if(secim==3){
		kisiDuzenle();
	}else if(secim==4){
		kisiSilme();
	}else if(secim==5){
		listele();
	}else if(secim==6){
		return 0;
	}
return 0;
}
