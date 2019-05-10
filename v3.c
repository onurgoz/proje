#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand
#include<locale.h>//setlocale komutu için
#include<windows.h>//sleep komutu için
#include<conio.h>
#include<string.h>//remove,rename

typedef struct{
	char KullaniciAdi[100];
	char SoyAdi[100];
	int HesapNo[100];
	int bakiye;
}Kullanici;


int secim,secim1,n; 
int rastgelesayi;
int OkuBireysel();
int OkuTicari();
void menu(int i,int n);
void YeniMusteriEkleme(int secim,int i,int n);
void HesapAcma(int secim,int i,int n);
void ParaCekme(int i,int n);
void ParaYatirma(int i,int n);
void HesabaHavale(int i,int n);
void BankaGelirGiderRaporu(int i,int n);
void HesapOzeti(int i,int n);
void HesapKapatma(int i,int n);
int HesapNo(); 
Kullanici TicariK[100];
Kullanici BireyselK[100];
int main()
{	int i,n;
	i=OkuBireysel();
	n=OkuTicari();
	menu(i,n);
	system("pause");
}
int OkuBireysel()
{
	int i=0;
	FILE *fp;
	fp=fopen("Bireysel.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %s %d\n",&BireyselK[i].HesapNo,BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,&BireyselK[i].bakiye);
		i++;
	}
	fclose(fp);
	return i;
}
int OkuTicari(){
	int n=0;
	FILE *fp1;
	fp1=fopen("Ticari.txt","r");
	while(!feof(fp1))
	{
		fscanf(fp1,"%d %s %s %d\n",&TicariK[n].HesapNo,TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,&TicariK[n].bakiye);
		n++;
	}
	fclose(fp1);
	return n;
}
void menu(int i,int n)
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
		YeniMusteriEkleme(secim1,i,n);
		menu(i,n);
		break;
		case 2:
		printf("Hesabinizi bireysel acmak icin(1)\nticari acmak icin(2)\n");
		scanf("%d",&secim1);
		HesapAcma(secim1,i,n);
		menu(i,n);
		break;
		


	}

}
void YeniMusteriEkleme(int secim,int i,int n)
{
	if(secim==1)
	{
	FILE *fp;
	fp=fopen("Bireysel.txt","a");
	srand(time(NULL));
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",BireyselK[i].KullaniciAdi);
	printf("\nSoyadi : ");
	scanf("%s",BireyselK[i].SoyAdi);
	rastgelesayi=HesapNo();
	rastgelesayi,BireyselK[i].HesapNo;
	printf("\nYeni hesap no:%d(Lutfen not ediniz.)\n",BireyselK[i].HesapNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&BireyselK[i].bakiye);
	fprintf(fp,"%d %s %s %d\n",BireyselK[i].HesapNo,BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].bakiye);
	fclose(fp);
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	
	
	system("CLS");

	}
	else if(secim==2)
	{
	FILE *fp1;
	fp1=fopen("Ticari.txt","a");
	srand(time(NULL));

	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",TicariK[n].KullaniciAdi);
	
	printf("\nSoyadi : ");
	scanf("%s",TicariK[n].SoyAdi);
	
	rastgelesayi=HesapNo();
	rastgelesayi,TicariK[n].HesapNo;
	printf("\nYeni hesap no:%d(Lutfen not ediniz.)\n",TicariK[n].HesapNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&TicariK[n].bakiye);
	fprintf(fp1,"%d %s %s %d\n",TicariK[n].HesapNo,TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].bakiye);
	fclose(fp1);
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	

	system("CLS");
	}


}
void HesapAcma(int secim,int i,int n)
{	
	if(secim==1)
	{
		
		FILE *fp;
		fp=fopen("Bireysel.txt","r");
		int say=0,k,HesapEklenecek,sorgu1;
		printf("Hesap acmak istediginiz kisinin Hesap Numarasini giriniz:\n");
		scanf("%d",&sorgu1);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i;k++)
		{
			if(*BireyselK[k].HesapNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
			{
				printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",*BireyselK[k].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].bakiye);
				++say;//kaç hesap bu kelimeyi içeriyorsa say 
				HesapEklenecek=k;

			}
			else if(k>i && say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(2);
				system("CLS");
			}
				
			
		}
		printf("\nAradiginiz kelime ile eslesen %d hesap bulundu.",say);
	}
	else if(secim==2)
	{
			
		FILE *fp1;
		fp1=fopen("Ticari.txt","a");
		srand(time(NULL));
		int say=0,k,HesapEklenecek,sorgu1;
		printf("Hesap acmak istediginiz kisinin Hesap Numarasini giriniz:\n");
		scanf("%d",&sorgu1);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<n;k++)
		{
			
			if(TicariK[k].HesapNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
			{
				printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].bakiye);
				++say;//kaç hesap bu kelimeyi içeriyorsa say 
				HesapEklenecek=k;

			}
			else if(k>i && say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(2);
				system("CLS");
			}
				
			
		}
		printf("\nAradiginiz kelime ile eslesen %d hesap bulundu.",say);
		}
	
}
void ParaCekme(int i,int n)
{

}
void ParaYatirma(int i,int n)
{

}
void HesabaHavale(int i,int n)
{

}
void BankaGelirGiderRaporu(int i,int n)
{

}
void HesapOzeti(int i,int n)
{

}
void HesapKapatma(int i,int n)
{
	
}
int HesapNo()
{
	int AltiHane;
	srand(time(NULL));
	AltiHane=rand()%300000+10000;
	return AltiHane;
}
