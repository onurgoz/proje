#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand
#include<locale.h>//setlocale komutu için
#include<windows.h>//sleep komutu için
#include<conio.h>
#include<string.h>//remove,rename
int strcmp(const char *, const char *);
typedef struct{
	char *KullaniciAdi;
	char *SoyAdi;
	char *HesapNo;
	int bakiye;
}kullanici;
int secim,secim1;
int rastgelesayi;
void menu();
void YeniMusteriEkleme(int secim);
void HesapAcma(int secim);
void ParaCekme();
void ParaYatirma();
void HesabaHavale();
void BankaGelirGiderRaporu();
void HesapOzeti();
void HesapKapatma();
int HesapNo();

int main()
{
	menu();
	return 0;
}
void menu()
{
		
	printf("   Banka otomasyonuna hosgeldiniz.   \n");
	printf("*************************************\n");
	
	printf("Lutfen islem seciniz\n 1-Hesap Yeni Musteri Kaydi Olusturma\n 2-Hesap Acma\n 3-Para Cekme\n 4-Para Yatirma\n 5-Hesaba Havale\n 6-Banka Gelir-Gider Raporu\n 7-Hesap Ozeti\n 8-Hesap Kapatma\n");
	scanf("%d",&secim);			//seçim işlermi burada yapılacak
	switch(secim)
	{
		case 1:
		printf("Hesabinizi bireysel acmak icin(1)\nticari acmak icin(2)\n");
		scanf("%d",&secim1);
		YeniMusteriEkleme(secim1);
		menu();
		break;
		case 2:
		printf("Hesabinizi bireysel acmak icin(1)\nticari acmak icin(2)\n");
		scanf("%d",&secim1);
		HesapAcma(secim1);
		menu();
		break;
		


	}

}
void YeniMusteriEkleme(int secim)
{
	
	kullanici oku;
	if(secim==1)
	{
	FILE *fp;
	fp=fopen("Bireysel.txt","a");
	srand(time(NULL));
	oku.KullaniciAdi=(char*)malloc(sizeof(char)*100);//malloc komutu ada göre hafýzada tutulan alaný deðiþtiriyor
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",oku.KullaniciAdi);
	oku.SoyAdi=(char*)malloc(sizeof(char)*100);
	printf("\nSoyadi : ");
	scanf("%s",oku.SoyAdi);
	oku.HesapNo=(char*)malloc(sizeof(char)*100);
	rastgelesayi=HesapNo();
	itoa(rastgelesayi,oku.HesapNo,10);//int deðiþkenini stringe çevirip Hexadesimal16,Binar2 veya 10luk tabanýna göre yazýyor
	printf("\nYeni hesap no:%s(Lutfen not ediniz.)\n",oku.HesapNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&oku.bakiye);
	fprintf(fp,"%s %s %s %d\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,oku.bakiye);
	fclose(fp);
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	
	
	system("CLS");

	}
	else if(secim==2)
	{
	kullanici oku;
	FILE *fp1;
	fp1=fopen("Ticari.txt","a");
	srand(time(NULL));
	oku.KullaniciAdi=(char*)malloc(sizeof(char)*100);//malloc komutu ada göre hafýzada tutulan alaný deðiþtiriyor
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",oku.KullaniciAdi);
	oku.SoyAdi=(char*)malloc(sizeof(char)*100);
	printf("\nSoyadi : ");
	scanf("%s",oku.SoyAdi);
	oku.HesapNo=(char*)malloc(sizeof(char)*100);
	rastgelesayi=HesapNo();
	itoa(rastgelesayi,oku.HesapNo,10);//int deðiþkenini stringe çevirip Hexadesimal16,Binar2 veya 10luk tabanýna göre yazýyor
	printf("\nYeni hesap no:%s(Lutfen not ediniz.)\n",oku.HesapNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&oku.bakiye);
	fprintf(fp1,"%s %s %s %d\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,oku.bakiye);
	fclose(fp1);
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	

	system("CLS");
	}


}
void HesapAcma(int secim)
{
	
	
	if(secim==1)
	{
		kullanici oku;
		FILE *fp;
		fp=fopen("Bireysel.txt","a");
		int say=0;
		char sorgu1[106];
		printf("Hesap acmak istediginiz kisinin adini ve soyadini giriniz:\n");
		fflush(stdin);
		gets( sorgu1 );
		printf("\nARAMA SONUCU\n------------");
		do//feof:end of file fp dosyasýnýn en sonuna git
		{
			fscanf(fp,"%s %s %s %d\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,&oku.bakiye);
			printf("Test\n");
			if(strcmp(oku.HesapNo,sorgu1)==0)//string karþýlaþtýrýcý birbirine eþit(0) ise
			{
				printf("\n<<<<<<<<<<<<\nHesap no : %s\n\nKisinin\n------------\n Adý    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,oku.bakiye);
			++say;//kaç hesap bu kelimeyi içeriyorsa say 
			}
			if(strcmp(oku.HesapNo,sorgu1)==0)
			{
				printf("\n<<<<<<<<<<<<\nHesap no : %s\n\nKisinin\n------------\n Adý    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,oku.bakiye);
			++say;
		}
		if(say==0)
	{
		printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
		
		system("CLS");
	}
	else
	{
		printf("\nAradiginiz kelime ile eslesen %d hesap bulundu.",say);
	}
	}while(!feof(fp));
	}
	else if(secim==2)
	{
		kullanici oku;
		FILE *fp1;
		fp1=fopen("Ticari.txt","a");
		srand(time(NULL));
		oku.KullaniciAdi=(char*)malloc(sizeof(char)*100);//malloc komutu ada göre hafýzada tutulan alaný deðiþtiriyor
		printf("\n\nHesap Acma Ekrani\n------------\nKisinin\n------------\nAdi    : ");
		scanf("%s",oku.KullaniciAdi);
		oku.SoyAdi=(char*)malloc(sizeof(char)*100);
		printf("\nSoyadi : ");
		scanf("%s",oku.SoyAdi);
		oku.HesapNo=(char*)malloc(sizeof(char)*100);
		rastgelesayi=HesapNo();
		itoa(rastgelesayi,oku.HesapNo,10);//int deðiþkenini stringe çevirip Hexadesimal16,Binar2 veya 10luk tabanýna göre yazýyor
		printf("\nYeni hesap no:%s(Lutfen not ediniz.)\n",oku.HesapNo);
		printf("\nLutfen ilk bakiyeyi giriniz : ");
		scanf("%d",&oku.bakiye);
		fprintf(fp1,"%s %s %s %d\n",oku.HesapNo,oku.KullaniciAdi,oku.SoyAdi,oku.bakiye);
		fclose(fp1);
		printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
		
		system("CLS");

	}
	
}
void ParaCekme()
{

}
void ParaYatirma()
{

}
void HesabaHavale()
{

}
void BankaGelirGiderRaporu()
{

}
void HesapOzeti()
{

}
void HesapKapatma()
{
	
}
int HesapNo()
{
	int AltiHane;
	srand(time(NULL));
	AltiHane=rand()%300000+10000;
	return AltiHane;
}
