#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand
#include<locale.h>//setlocale komutu için
#include<windows.h>//sleep komutu için
#include<conio.h>
#include<string.h>//remove,rename

typedef struct
{
	int HesapNo;
	int bakiye;
}hesap;

typedef struct{
	int HesapS;
	char TC[100];
	int KullaniciNo;
	char KullaniciAdi[100];
	char SoyAdi[100];
	hesap Hesap[100];
	
}Kullanici;
typedef struct
{
	int BKullaniciS;
	int TKullaniciS;
}KullaniciS;
KullaniciS Ksayisi;


int secim,secim1,n; 
int rastgelesayi;
void OkuBireysel();
void OkuTicari();
void menu();
void YeniMusteriEkleme(int secim,int i,int n);
void HesapAcma(int secim,int i,int n);
void ParaCekme(int i,int n);
void ParaYatirma(int i,int n);
void HesabaHavale(int i,int n);
void BankaGelirGiderRaporu(int i,int n);
void HesapOzeti(int i,int n);
void HesapKapatma(int i,int n);
void Guncelle(int i,int n);
int No(int j); 
Kullanici TicariK[100];
Kullanici BireyselK[100];
int main()
{	
	menu();
	system("pause"); 
}
void OkuBireysel()
{
	int i=0,j;
	FILE *fp;
	fp=fopen("Bireysel.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s - %s - %d",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,&BireyselK[i].KullaniciNo);
		printf("%d",&BireyselK[i].KullaniciNo);
		fscanf(fp, "%d", &BireyselK[i].HesapS);
		for (j=0; j<BireyselK[i].HesapS; j++)
		{
			fscanf(fp, "%d %d",&BireyselK[i].Hesap[j].HesapNo,&BireyselK[i].Hesap[j].bakiye);
		}
		i++;
	}
	Ksayisi.BKullaniciS=i;
	fclose(fp);
	
}
void OkuTicari(){
	int n=0,j;
	FILE *fp1;
	fp1=fopen("Ticari.txt","r");
	while(!feof(fp1))
	{
		fscanf(fp1, "%s %s - %s - %d",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,&TicariK[n].KullaniciNo);
		fscanf(fp1, "%d", &TicariK[n].HesapS);
		for (j=0; j<TicariK[n].HesapS; j++){
			fscanf(fp1, "%d %d",&TicariK[n].Hesap[j].HesapNo,&TicariK[n].Hesap[j].bakiye);
		}
		n++;
	}
	Ksayisi.TKullaniciS=n;
	fclose(fp1);
	
}
void menu()
{
	int n,i;
	i=Ksayisi.BKullaniciS;
	n=Ksayisi.TKullaniciS;
	OkuBireysel();
	OkuTicari();
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
		menu();
		break;
		case 2:
		printf("Hesabinizi bireysel acmak icin(1)\nticari acmak icin(2)\n");
		scanf("%d",&secim1);
		HesapAcma(secim1,i,n);
		menu();
		break;
		


	}

}
void YeniMusteriEkleme(int secim,int i,int n)
{
	int secim1;
	if(secim==1)
	{
	FILE *fp;
	fp=fopen("Bireysel.txt","a");
	srand(time(NULL));
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",BireyselK[i].KullaniciAdi);
	printf("\nSoyadi : ");
	scanf("%s",BireyselK[i].SoyAdi);
	printf("TC : ");
	scanf("%s",BireyselK[i].TC);
	secim1=1;
	rastgelesayi=No(secim1);
	BireyselK[i].Hesap[0].HesapNo=rastgelesayi;
	secim1=2;
	rastgelesayi=No(secim1);
	BireyselK[i].KullaniciNo=rastgelesayi;
	printf("\nYeni Kullanici no:%d(Lutfen not ediniz.)\n",BireyselK[i].KullaniciNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&BireyselK[i].Hesap[0].bakiye);
	fprintf(fp,"\n%s %s - %s - %d\n1\n%d %d\n",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,BireyselK[i].KullaniciNo,BireyselK[i].Hesap[0].HesapNo,BireyselK[i].Hesap[0].bakiye);
	fclose(fp);
	Ksayisi.BKullaniciS++;
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
	printf("TC : ");
	scanf("%s",TicariK[n].TC);
	secim1=1;
	rastgelesayi=No(secim1);
	TicariK[n].Hesap[0].HesapNo=rastgelesayi;
	secim1=2;
	rastgelesayi=No(secim1);
	TicariK[n].KullaniciNo=rastgelesayi;
	printf("\nYeni hesap no:%d(Lutfen not ediniz.)\n",TicariK[n].Hesap[0].HesapNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&TicariK[n].Hesap[0].bakiye);
	fprintf(fp1,"\n%s %s - %s - %d\n1\n%d %d\n",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,TicariK[n].KullaniciNo,TicariK[n].Hesap[0].HesapNo,TicariK[n].Hesap[0].bakiye);
	fclose(fp1);
	Ksayisi.TKullaniciS++;
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	system("CLS");
	}
}
void HesapAcma(int secim,int i,int n)
{	
	int say=0,k,sorgu1,j;
		if(secim==1)
		{
			printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
			scanf("%d",&sorgu1);
			printf("\nARAMA SONUCU\n------------");
			for(k=0;k<i+1;k++)
			{
				if(BireyselK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
					for(j=0;j<Ksayisi.BKullaniciS;j++)
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
					srand(time(NULL));
					rastgelesayi=No(1);
					BireyselK[k].Hesap[BireyselK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&BireyselK[k].Hesap[BireyselK[k].HesapS].bakiye);
					BireyselK[k].HesapS++;
					Guncelle(i,n);
					say++;
				}
				else if(k>i||say==0)
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					sleep(1);
					system("CLS");
				}
					
				
			}
			
		}
		else if(secim==2)
		{
			srand(time(NULL));
			
			printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&sorgu1);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i;k++)
		{
			if(TicariK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
				printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[0].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[0].bakiye);
				srand(time(NULL));
				rastgelesayi=No(1);
				TicariK[k].Hesap[TicariK[k].HesapS].HesapNo=rastgelesayi;
				printf("Yeni Hesabinizin Bakiyesini Giriniz:");
				scanf("%d",&TicariK[k].Hesap[TicariK[k].HesapS].bakiye);
				TicariK[k].HesapS++;
				Guncelle(i,n);
				say++;
			}
			else if(k>i||say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(1);
				system("CLS");
			}
		
		}
	}
}
void Guncelle(int i,int n)
{	
	int k,j;
	FILE *fp,*fp1;
				
	fp=fopen("Bireysel.txt","w");
	for(k=0;k<Ksayisi.BKullaniciS;k++)
	{
		fprintf(fp,"%s %s - %s - %d\n%d",BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].TC,BireyselK[k].KullaniciNo,BireyselK[k].HesapS);
		for(j=0;j<BireyselK[k].HesapS;j++)
		fprintf(fp,"%d %d",BireyselK[k].Hesap[j].HesapNo,&BireyselK[k].Hesap[j].bakiye);
	}
	fp1=fopen("Ticari.txt","w");
	for(k=0;k<Ksayisi.TKullaniciS;k++)
	{
		fprintf(fp1,"%s %s - %s - %d\n%d",TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].TC,TicariK[k].KullaniciNo,TicariK[k].HesapS);
		for(j=0;j<TicariK[k].HesapS;j++)
		fprintf(fp1,"%d %d",TicariK[k].Hesap[j].HesapNo,&TicariK[k].Hesap[j].bakiye);
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
int No(int j)
{
	if(j==1)//hesap no için
	{
	int AltiHane;
	srand(time(NULL));
	AltiHane=((rand()%900)+100)*1000+rand()%1000;
	return AltiHane;
	}
	if(j==2)//kullanıcı no için
	{
	int AltiHane;
	srand(time(NULL));
	AltiHane=((rand()%9000)+100)*1000+rand()%10000;
	return AltiHane;
	}
}
