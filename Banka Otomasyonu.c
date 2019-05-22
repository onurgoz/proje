#include<stdio.h>
#include<stdlib.h>
#include<time.h>//srand
#include<string.h>
#include<windows.h>
typedef struct 
{
	int tm_day;
	int tm_year;
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mon;
}ZamanStruct;

typedef struct
{
	int islemHesabi;
	int islemmik;
	char islemturu[100];
	ZamanStruct zaman;
}islemler;

typedef struct
{
	int songun;
	int gun;
	int gunlukbakiye;
	int HesapNo;
	int bakiye;
	int islemsayisi;
	islemler islem[100];
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

typedef struct
{
	KullaniciS Ksayisi;
	Kullanici TicariK[100];
	Kullanici BireyselK[100];
	int Bgiden;
	int Bgelen;
	int Btop;
}bnk;
bnk bank;

int secim,secim1,n; 
int rastgelesayi;
void hesapK(int secim,int k ,int j);
void menu();
void wait(int sure);
void OkuBireysel();
void OkuTicari();
void okudekont();
void okurapor();
void YeniMusteriEkleme(int secim,int i,int n);
void HesapAcma(int secim);
void ParaCekme(int secim);
void ParaYatirma(int secim);
void HesabaHavale(int secim);
void BankaGelirGider();
void HesapOzeti(int secim);
void HesapKapatma(int secim);
void Guncelle(int secim);
void zamanicek(int secim,int k,int j);
int No(int j); 
int main()
{	
	menu();
	system("pause"); 
}
void wait(int sure)
{
	clock_t son;
	son=clock()+sure+CLK_TCK;
	while(clock()<son){}
}
void menu()
{
	int n,i;
	OkuBireysel();
	OkuTicari();
	i=bank.Ksayisi.BKullaniciS;
	n=bank.Ksayisi.TKullaniciS;
	printf("Manisa Celal Bayar Universitesi / Yazilim Muhendisligi\nYZM-1106 Algoritma ve Programlama II Dersi (2018-2019)\nDonem Projesi / Banka Yazilim Otomasyonu\n");
	printf("*******************************************************\n");
	okurapor();
	okudekont();
	do{
	printf("Islem Menusu\n---------------\n 1-Yeni Musteri Kaydi Olusturma\n 2-Hesap Acma\n 3-Para Cekme\n 4-Para Yatirma\n 5-Hesaba Havale\n 6-Banka Gelir-Gider Raporu\n 7-Hesap Ozeti\n 8-Hesap Kapatma\n");
	scanf("%d",&secim);
	system("CLS");}while(secim<1 || secim>8);
	switch(secim)
	{
		case 1:
		do{
		printf("Kullanicinizi bireysel acmak icin(1)\nTicari acmak icin(2)\n");
		scanf("%d",&secim1);
		system("CLS");
		}while(secim1<1||secim1>2);
		YeniMusteriEkleme(secim1,i,n);
		Guncelle(secim1);
		menu();
		break;
		case 2:
		do{
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		system("CLS");
		}while(secim1<1||secim1>2);
		HesapAcma(secim1);
		Guncelle(secim1);
		menu();
		break;
		case 3:
		do{
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		system("CLS");
		}while(secim1<1||secim1>2);
		ParaCekme(secim1);
		Guncelle(secim1);
		menu();
		break;
		case 4:
		do{
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		system("CLS");
		}while(secim1<1||secim1>2);
		ParaYatirma(secim1);
		Guncelle(secim1);
		menu();
		break;
		case 5:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		HesabaHavale(secim1);
		Guncelle(secim1);
		menu();
		break;
		case 6:
		BankaGelirGider();
		Guncelle(secim1);
		menu();
		break;
		case 7:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		HesapOzeti(secim1);
		Guncelle(secim1);
		menu();
		break;
		case 8:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		HesapKapatma(secim1);
		Guncelle(secim1);
		menu();
		break;
	}

}
void OkuBireysel()
{
	int i=0,j;
	FILE *fp,*fp1;
	fp=fopen("Bireysel.txt","r");
	if(fp!=NULL)
	{
	while(!feof(fp))
	{
		fscanf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",bank.BireyselK[i].KullaniciAdi,bank.BireyselK[i].SoyAdi,bank.BireyselK[i].TC,&bank.BireyselK[i].KullaniciNo);
		fscanf(fp, " Hesap sayisi : %d", &bank.BireyselK[i].HesapS);
		for (j=0; j<bank.BireyselK[i].HesapS; j++)
		{
			fscanf(fp, " Hesap no : %d bakiye : %d Gunluk bakiye : %d",&bank.BireyselK[i].Hesap[j].HesapNo,&bank.BireyselK[i].Hesap[j].bakiye,&bank.BireyselK[i].Hesap[j].gunlukbakiye);
		}
		i++;
	}
	bank.Ksayisi.BKullaniciS=i-1;
	
	fclose(fp);
	}
	else if(fp==NULL)
	{
		fclose(fp);
		bank.Ksayisi.BKullaniciS=0;
	}
	if(fp1!=NULL)
	{

	}
	
} 
void OkuTicari(){
	int n=0,j;
	FILE *fp1;
	fp1=fopen("Ticari.txt","r");
	if(fp1!=NULL)
	{
	while(!feof(fp1))
	{
		fscanf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",bank.TicariK[n].KullaniciAdi,bank.TicariK[n].SoyAdi,bank.TicariK[n].TC,&bank.TicariK[n].KullaniciNo);
		fscanf(fp1, " Hesap sayisi : %d", &bank.TicariK[n].HesapS);
		for (j=0; j<bank.TicariK[n].HesapS; j++){
			fscanf(fp1, " Hesap no : %d bakiye : %d Gunluk bakiye : %d",&bank.TicariK[n].Hesap[j].HesapNo,&bank.TicariK[n].Hesap[j].bakiye,&bank.TicariK[n].Hesap[j].gunlukbakiye);
		}
		n++;
	}
	bank.Ksayisi.TKullaniciS=n-1;
	fclose(fp1);
	}
	else if(fp1==NULL)
	{
		fclose(fp1);
		bank.Ksayisi.TKullaniciS=0;
	}
	
}
void okudekont()
{
	int n=0,j,k,i=0;
	FILE *fp,*fp1;
	
	fp=fopen("Dekont1.txt","r");
	if(fp!=NULL)
	{
	for(n=0;n<bank.Ksayisi.TKullaniciS;n++)
	{
		fscanf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",bank.TicariK[n].KullaniciAdi,bank.TicariK[n].SoyAdi,bank.TicariK[n].TC,&bank.TicariK[n].KullaniciNo);
		for (j=0; j<bank.TicariK[n].HesapS; j++){
			fscanf(fp, " Hesap no : %d\n Islem sayisi : %d",&bank.TicariK[n].Hesap[j].HesapNo,&bank.TicariK[n].Hesap[j].islemsayisi);
			for(k=0;k<bank.TicariK[n].Hesap[j].islemsayisi;k++)
			{
				fflush(stdin);
				fscanf(fp," %d:%d:%d - %d.%d.%d : %d %d %s",&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_hour,&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_min,&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_sec,&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_day,&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_mon,&bank.TicariK[n].Hesap[j].islem[k].zaman.tm_year,&bank.TicariK[n].Hesap[j].islem[k].islemHesabi,&bank.TicariK[n].Hesap[j].islem[k].islemmik,bank.TicariK[n].Hesap[j].islem[k].islemturu);
			}
		}
	}
	
	fclose(fp);
	}
	else if(fp==NULL)
	{
		fclose(fp);
		
	}
	fp1=fopen("Dekont.txt","r");
	if(fp1!=NULL)
	{
	for(i=0;i<bank.Ksayisi.BKullaniciS;i++)
	{
		fscanf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",bank.BireyselK[i].KullaniciAdi,bank.BireyselK[i].SoyAdi,bank.BireyselK[i].TC,&bank.BireyselK[i].KullaniciNo);
		for (j=0; j<bank.BireyselK[i].HesapS; j++){
			fscanf(fp1, " Hesap no : %d\n Islem sayisi : %d",&bank.BireyselK[i].Hesap[j].HesapNo,&bank.BireyselK[i].Hesap[j].islemsayisi);
			for(k=0;k<bank.BireyselK[i].Hesap[j].islemsayisi;k++)
			{
				fscanf(fp1," %d:%d:%d - %d.%d.%d : %d %d %s",&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_hour,&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_min,&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_sec,&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_day,&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_mon,&bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_year,&bank.BireyselK[i].Hesap[j].islem[k].islemHesabi,&bank.BireyselK[i].Hesap[j].islem[k].islemmik,bank.BireyselK[i].Hesap[j].islem[k].islemturu);
			}
		}
		
	}
	
	fclose(fp1);
	}
	else if(fp==NULL)
	{
		fclose(fp1);
		
	}
}
void okurapor()
{
	FILE *fp;
	fp=fopen("rapor.txt","r");
	fscanf(fp," Bankadan Giden : %d\n Bankaya Gelen : %d\n Bankadaki Toplam Para : %d",&bank.Bgiden,&bank.Bgelen,&bank.Btop);
	fclose(fp);
}
void YeniMusteriEkleme(int secim,int i,int n)
{
	int secim1;
	if(secim==1)
	{
	bank.BireyselK[i].Hesap[0].islemsayisi=0;
	bank.BireyselK[i].HesapS=1;
	srand(time(NULL));
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",bank.BireyselK[i].KullaniciAdi);
	printf("\nSoyadi : ");
	scanf("%s",bank.BireyselK[i].SoyAdi);
	printf("TC : ");
	scanf("%s",bank.BireyselK[i].TC);
	secim1=1;
	rastgelesayi=No(secim1);
	bank.BireyselK[i].Hesap[0].HesapNo=rastgelesayi;
	secim1=2;
	rastgelesayi=No(secim1);
	bank.BireyselK[i].KullaniciNo=rastgelesayi;
	printf("\nYeni Kullanici no:%d(Lutfen not ediniz.)\n",bank.BireyselK[i].KullaniciNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&bank.BireyselK[i].Hesap[0].bakiye);
	bank.Bgelen+=bank.BireyselK[i].Hesap[0].bakiye;
	bank.Btop+=bank.BireyselK[i].Hesap[0].bakiye;
	bank.Ksayisi.BKullaniciS++;
	bank.BireyselK[i].Hesap[0].gunlukbakiye=750;
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	system("CLS");
	}
	else if(secim==2)
	{
	bank.TicariK[i].Hesap[0].islemsayisi=0;
	bank.TicariK[n].HesapS=1;
	srand(time(NULL));
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",bank.TicariK[n].KullaniciAdi);
	printf("\nSoyadi : ");
	scanf("%s",bank.TicariK[n].SoyAdi);
	printf("TC : ");
	scanf("%s",bank.TicariK[n].TC);
	secim1=1;
	rastgelesayi=No(secim1);
	bank.TicariK[n].Hesap[0].HesapNo=rastgelesayi;
	secim1=2;
	rastgelesayi=No(secim1);
	bank.TicariK[n].KullaniciNo=rastgelesayi;
	printf("\nYeni Kullanici no:%d(Lutfen not ediniz.)\n",bank.TicariK[n].KullaniciNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&bank.TicariK[n].Hesap[0].bakiye);
	bank.TicariK[n].Hesap[0].gunlukbakiye=1500;
	bank.Ksayisi.TKullaniciS++;
	bank.Bgelen+=bank.TicariK[n].Hesap[0].bakiye;
	bank.Btop+=bank.TicariK[n].Hesap[0].bakiye;
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	system("CLS");
	}
}
void HesapAcma(int secim)
{	
	int say=0,k,sorgu1,j;
		if(secim==1)
		{
			printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
			scanf("%d",&sorgu1);
			printf("\nARAMA SONUCU\n------------");
			for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
			{
				if(bank.BireyselK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
					for(j=0;j<bank.BireyselK[k].HesapS;j++)
					{
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
					}
					srand(time(NULL));
					rastgelesayi=No(1);
					bank.BireyselK[k].Hesap[bank.BireyselK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&bank.BireyselK[k].Hesap[bank.BireyselK[k].HesapS].bakiye);
					bank.BireyselK[k].HesapS++;
					bank.Bgelen+=bank.BireyselK[k].Hesap[bank.BireyselK[k].HesapS].bakiye;
					bank.Btop+=bank.BireyselK[k].Hesap[bank.BireyselK[k].HesapS].bakiye;
					say++;
					printf("\nAna menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
				}
				else if(k>=bank.Ksayisi.BKullaniciS&&say==0)
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
				}
					
				
			}
			
		}
		else if(secim==2)
		{
			printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
			scanf("%d",&sorgu1);
			printf("\nARAMA SONUCU\n------------");
			for(k=0;k<bank.Ksayisi.TKullaniciS;k++)
			{
				if(bank.TicariK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
					for(j=0;j<bank.TicariK[k].HesapS;j++)
					{
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
					}
					srand(time(NULL));
					rastgelesayi=No(1);
					bank.TicariK[k].Hesap[bank.TicariK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&bank.TicariK[k].Hesap[bank.TicariK[k].HesapS].bakiye);
					bank.TicariK[k].HesapS++;
					bank.Bgelen+=bank.TicariK[k].Hesap[bank.TicariK[k].HesapS].bakiye;
					bank.Btop+=bank.TicariK[k].Hesap[bank.TicariK[k].HesapS].bakiye;
					say++;
					printf("\nAna menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
				}
				else if(k>=bank.Ksayisi.TKullaniciS&&say==0)
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
				}
					
				
			}
	}
}
void Guncelle(int secim)
{	
	int k,j,l,i=0,n=0;
	FILE *fp,*fp1;
	if(secim==1)
	{
	fp=fopen("Bireysel.txt","w");
	for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
	{
		fprintf(fp," Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n Hesap sayisi : %d\n",bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].TC,bank.BireyselK[k].KullaniciNo,bank.BireyselK[k].HesapS);
		for(j=0;j<bank.BireyselK[k].HesapS;j++)
		{
		fprintf(fp," Hesap no : %d bakiye : %d Gunluk bakiye : %d\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].Hesap[j].bakiye,bank.BireyselK[k].Hesap[j].gunlukbakiye);
		}
		
	}
	
	fclose(fp);
	}
	else if(secim==2)
	{
	fp1=fopen("Ticari.txt","w");
	for(k=0;k<bank.Ksayisi.TKullaniciS;k++)
	{
		fprintf(fp1," Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n Hesap sayisi : %d\n",bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].TC,bank.TicariK[k].KullaniciNo,bank.TicariK[k].HesapS);
		for(j=0;j<bank.TicariK[k].HesapS;j++)
		fprintf(fp1," Hesap no : %d bakiye : %d Gunluk bakiye : %d\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].Hesap[j].bakiye,bank.TicariK[k].Hesap[j].gunlukbakiye);
	}
	fclose(fp1);
	}
	fp=fopen("Dekont1.txt","w");
	for(n=0;n<bank.Ksayisi.TKullaniciS;n++)
	{
	fprintf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",bank.TicariK[n].KullaniciAdi,bank.TicariK[n].SoyAdi,bank.TicariK[n].TC,bank.TicariK[n].KullaniciNo);
		for (j=0; j<bank.TicariK[n].HesapS; j++)
		{
			fprintf(fp, " Hesap no : %d\n Islem sayisi : %d\n",bank.TicariK[n].Hesap[j].HesapNo,bank.TicariK[n].Hesap[j].islemsayisi);
			for(k=0;k<bank.TicariK[n].Hesap[j].islemsayisi;k++)
			{
				fprintf(fp," %d:%d:%d - %d.%d.%d : %d %d %s\n",bank.TicariK[n].Hesap[j].islem[k].zaman.tm_hour,bank.TicariK[n].Hesap[j].islem[k].zaman.tm_min,bank.TicariK[n].Hesap[j].islem[k].zaman.tm_sec,bank.TicariK[n].Hesap[j].islem[k].zaman.tm_day,bank.TicariK[n].Hesap[j].islem[k].zaman.tm_mon,bank.TicariK[n].Hesap[j].islem[k].zaman.tm_year,bank.TicariK[n].Hesap[j].islem[k].islemHesabi,bank.TicariK[n].Hesap[j].islem[k].islemmik,bank.TicariK[n].Hesap[j].islem[k].islemturu);
			}
		}
	}	
		fclose(fp);
	fp1=fopen("Dekont.txt","w");
	for(i=0;i<bank.Ksayisi.BKullaniciS;i++)
	{
	fprintf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",bank.BireyselK[i].KullaniciAdi,bank.BireyselK[i].SoyAdi,bank.BireyselK[i].TC,bank.BireyselK[i].KullaniciNo);
	for (j=0; j<bank.BireyselK[i].HesapS; j++)
	{
		fprintf(fp, " Hesap no : %d\n Islem sayisi : %d\n",bank.BireyselK[i].Hesap[j].HesapNo,bank.BireyselK[i].Hesap[j].islemsayisi);
		for(k=0;k<bank.BireyselK[i].Hesap[j].islemsayisi;k++)
		{
			fprintf(fp1," %d:%d:%d - %d.%d.%d : %d %d %s\n",bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_hour,bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_min,bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_sec,bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_day,bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_mon,bank.BireyselK[i].Hesap[j].islem[k].zaman.tm_year,bank.BireyselK[i].Hesap[j].islem[k].islemHesabi,bank.BireyselK[i].Hesap[j].islem[k].islemmik,bank.BireyselK[i].Hesap[j].islem[k].islemturu);
		}
	}
	}
	fclose(fp1);
	fp=fopen("rapor.txt","w");
	fprintf(fp," Bankadan Giden : %d\n Bankaya Gelen : %d\n Bankadaki Toplam Para : %d",bank.Bgiden,bank.Bgelen,bank.Btop);
	fclose(fp);
}
void ParaCekme(int secim)
{
	time_t ti=time(NULL);
	struct tm tm=*localtime(&ti);
	int say=0,k,KullaniciSorgu=0,HesapSorgu=0,BakiyeS=0,j;
	if(secim==1)
	{
	
		printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
		{
			if(bank.BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.BireyselK[k].HesapS;j++)
				{
					if(bank.BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						bank.BireyselK[k].Hesap[j].gun=tm.tm_mday;
						zamanicek(1,k,j);
						if(bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_day>bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi-1].zaman.tm_day)
						{
							bank.BireyselK[k].Hesap[j].gunlukbakiye=750;
						}
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
						printf("Cekilecek para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (bank.BireyselK[k].Hesap[j].bakiye<BakiyeS||750<=BakiyeS||bank.BireyselK[k].Hesap[j].gunlukbakiye==0||bank.BireyselK[k].Hesap[j].gunlukbakiye<=BakiyeS||bank.BireyselK[k].Hesap[j].gun!=bank.BireyselK[k].Hesap[j].songun||BakiyeS<=0);
						bank.BireyselK[k].Hesap[j].bakiye-=BakiyeS;
						printf("%d hasabinizdan %d TL cekilmistir\n",bank.BireyselK[k].Hesap[j].HesapNo,BakiyeS);
						bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemHesabi=bank.BireyselK[k].Hesap[j].HesapNo;
						bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
						strcpy(bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemturu,"cekildi.");
						bank.BireyselK[k].Hesap[j].islemsayisi++;
						bank.Bgiden+=BakiyeS;
						bank.Btop-=BakiyeS;
						bank.BireyselK[k].Hesap[j].gunlukbakiye-=BakiyeS;
						printf("\nAna menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.BKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(1);
				system("CLS");
			}
		}
		
	}
	else if(secim==2)
	{
		
		printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<n+1;k++)
		{
			if(bank.TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.TicariK[k].HesapS;j++)
				{
					if(bank.TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						bank.BireyselK[k].Hesap[j].gun=tm.tm_mday;
						zamanicek(2,k,j);
						if(bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_day>bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi-1].zaman.tm_day)
						{
							bank.TicariK[k].Hesap[j].gunlukbakiye=1500;
						}
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
						printf("Cekilecek para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (BakiyeS<=0||bank.TicariK[k].Hesap[j].bakiye<BakiyeS||1500<=BakiyeS||bank.TicariK[k].Hesap[j].gunlukbakiye==0||bank.TicariK[k].Hesap[j].gunlukbakiye<=BakiyeS||bank.TicariK[k].Hesap[j].gun!=bank.TicariK[k].Hesap[j].songun);
						bank.TicariK[k].Hesap[j].bakiye-=BakiyeS;
						printf("%d hasabinizdan %d TL cekilmistir\n",bank.TicariK[k].Hesap[j].HesapNo,BakiyeS);
						bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemHesabi=bank.TicariK[k].Hesap[j].HesapNo;
						bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
						strcpy(bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemturu,"cekildi.");
						bank.TicariK[k].Hesap[j].islemsayisi++;
						bank.Bgiden+=BakiyeS;
						bank.Btop-=BakiyeS;
						printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
						
						
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.TKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}

}
void ParaYatirma(int secim)
{
	int say=0,k,KullaniciSorgu,HesapSorgu,Bakiye,j;
	if(secim==1)
	{
		printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
		{
			if(bank.BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.BireyselK[k].HesapS;j++)
				{
					if(bank.BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						
						
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
						do{
						printf("Yatirilacak para miktarini giriniz.\n");
						scanf("%d",&Bakiye);
						}while(Bakiye<=0);
						bank.BireyselK[k].Hesap[j].bakiye+=Bakiye;
						zamanicek(1,k,j);
						printf("%d hasabiniza %d TL yatirilmistir\n",bank.BireyselK[k].Hesap[j].HesapNo,Bakiye);
						bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemHesabi=bank.BireyselK[k].Hesap[j].HesapNo;
						bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemmik=Bakiye;
						strcpy(bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemturu,"yatirildi.");
						bank.BireyselK[k].Hesap[j].islemsayisi++;
						bank.Bgelen+=Bakiye;
						bank.Btop+=Bakiye;
						printf("\nAna menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
						
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.BKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}
	else if(secim==2)
	{
			printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.TKullaniciS;k++)
		{
			if(bank.TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.TicariK[k].HesapS;j++)
				{
					if(bank.TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
						do{
						printf("Yatirilacak para miktarini giriniz.\n");
						scanf("%d",&Bakiye);
						}while(Bakiye<=0);
						bank.TicariK[k].Hesap[j].bakiye+=Bakiye;
						zamanicek(2,k,j);
						printf("%d hasabiniza %d TL yatirilmistir\n",bank.TicariK[k].Hesap[j].HesapNo,Bakiye);
						bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemHesabi=bank.TicariK[k].Hesap[j].HesapNo;
						bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemmik=Bakiye;
						strcpy(bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemturu,"yatirildi.");
						bank.TicariK[k].Hesap[j].islemsayisi++;
						bank.Bgelen+=Bakiye;
						bank.Btop+=Bakiye;
						printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
						wait(1);
						system("cls");
						
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.TKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}

}
void HesabaHavale(int secim)
{

	int say=0,k,j,KullaniciSorgu,KullaniciSorgu1,HesapSorgu,HesapSorgu1,BakiyeS,l,m;
	if(secim==1)
	{
		printf("Giris yapmak icin  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
		{
			if(bank.BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.BireyselK[k].HesapS;j++)
				{
					if(bank.BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
						printf("Havale yapmak istediginiz para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (bank.BireyselK[k].Hesap[j].bakiye<(BakiyeS+BakiyeS/50));
						printf("Gondericeginiz kisinin Kullanici Numarasini giriniz :\n");
						scanf("%d",&KullaniciSorgu1);
						printf("\nARAMA SONUCU\n------------");
						for(l=0;l<bank.Ksayisi.BKullaniciS;l++)
						{
							if(bank.BireyselK[l].KullaniciNo==KullaniciSorgu1)
							{
							printf("\nAradiginiz kelime ile eslesen Kullanici bulundu.\n");
							printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
							scanf("%d",&HesapSorgu1);
							for(m=0;m<bank.BireyselK[l].HesapS;m++)
							{
								if(bank.BireyselK[l].Hesap[m].HesapNo==HesapSorgu1)
								{
										printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
										printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
										bank.BireyselK[k].Hesap[j].bakiye-=BakiyeS+BakiyeS/50;
										bank.BireyselK[l].Hesap[m].bakiye+=BakiyeS;
										zamanicek(1,k,j);
										zamanicek(1,l,m);
										printf("%d hasabinizdan %d TL cekilmistir\n",bank.BireyselK[k].Hesap[j].HesapNo,BakiyeS+BakiyeS/50);
										bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemHesabi=bank.BireyselK[l].Hesap[m].HesapNo;
										bank.BireyselK[l].Hesap[m].islem[bank.BireyselK[l].Hesap[m].islemsayisi].islemHesabi=bank.BireyselK[k].Hesap[j].HesapNo;
										bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemmik=BakiyeS+BakiyeS/50;
										bank.BireyselK[l].Hesap[m].islem[bank.BireyselK[l].Hesap[m].islemsayisi].islemmik=BakiyeS;
										strcpy(bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].islemturu,"Havale+kesilen_para.");
										strcpy(bank.BireyselK[l].Hesap[m].islem[bank.BireyselK[l].Hesap[m].islemsayisi].islemturu,"Havale_Gelmistir.");
										bank.BireyselK[k].Hesap[j].islemsayisi++;
										bank.BireyselK[l].Hesap[m].islemsayisi++;
										bank.Bgelen+=BakiyeS/50;
										bank.Btop+=BakiyeS/50;
										printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
										wait(1);
										system("cls");
										
								}
							}
						
						
							say++;
						}
						else if(j>bank.BireyselK[k].HesapS&&say==0)
						{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
						}
						}
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.BKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}
	else if(secim==2)
	{
				printf("Giris yapmak icin  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.TKullaniciS;k++)
		{
			if(bank.TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.TicariK[k].HesapS;j++)
				{
					if(bank.TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
						printf("Havale yapmak istediginiz para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (bank.TicariK[k].Hesap[j].bakiye<BakiyeS);
						printf("Gondericeginiz kisinin Kullanici Numarasini giriniz :\n");
						scanf("%d",&KullaniciSorgu1);
						printf("\nARAMA SONUCU\n------------");
						for(l=0;l<bank.Ksayisi.TKullaniciS;l++)
						{
							if(bank.TicariK[l].KullaniciNo==KullaniciSorgu1)
							{
							printf("\nAradiginiz kelime ile eslesen Kullanici bulundu.\n");
							printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
							scanf("%d",&HesapSorgu1);
							for(m=0;m<bank.TicariK[l].HesapS;m++)
							{
								if(bank.TicariK[l].Hesap[m].HesapNo==HesapSorgu1)
								{
										printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
										printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
										bank.TicariK[l].Hesap[m].bakiye+=BakiyeS;
										bank.TicariK[k].Hesap[j].bakiye-=BakiyeS;
										zamanicek(2,k,j);
										zamanicek(2,l,m);
										printf("%d hasabinizdan %d TL cekilmistir",bank.TicariK[k].Hesap[j].HesapNo,BakiyeS);
										bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemHesabi=bank.TicariK[l].Hesap[m].HesapNo;
										bank.TicariK[l].Hesap[m].islem[bank.TicariK[l].Hesap[m].islemsayisi].islemHesabi=bank.TicariK[k].Hesap[j].HesapNo;
										bank.TicariK[l].Hesap[m].islem[bank.TicariK[l].Hesap[m].islemsayisi].islemmik=BakiyeS;
										bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
										strcpy(bank.TicariK[l].Hesap[m].islem[bank.TicariK[l].Hesap[m].islemsayisi].islemturu,"Havale_Gelmistir.");
										strcpy(bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].islemturu,"Havale_Yapilmistir.");
										bank.TicariK[l].Hesap[m].islemsayisi++;
										bank.TicariK[k].Hesap[j].islemsayisi++;
										printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
										wait(1);
										system("cls");
										
								}
							}
						
						
							say++;
						}
						else if(j>bank.TicariK[k].HesapS&&say==0)
						{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
						}
						}
					}
				}
				
				
				say++;
			}
			else if(k>bank.Ksayisi.TKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}
}
void BankaGelirGider()
{
	printf("---------Banka Gelir Gider Raporu-----------");
	printf(" Bankadan Giden : %d\n Bankaya Gelen : %d\n Bankadaki Toplam Para : %d",bank.Bgiden,bank.Bgelen,bank.Btop);
	wait(1);
	system("cls");
}
void HesapOzeti(int secim)
{
	int say=0,i,KullaniciSorgu,HesapSorgu,j,l,n;
	if(secim==1)
	{
	printf("Hesap ozetini gormek istediginiz kisinin Kullanici Numarasini giriniz :\n");
	scanf("%d",&KullaniciSorgu);
	printf("\nARAMA SONUCU\n------------");
	for(i=0;i<bank.Ksayisi.BKullaniciS;i++)
	{
		if(bank.BireyselK[i].KullaniciNo==KullaniciSorgu)
		{
			printf("\nAradiginiz kelime ile eslesen kullanici bulundu.\n");
			printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
			scanf("%d",&HesapSorgu);
			for(j=0;j<bank.BireyselK[i].HesapS;j++)
			{
				if(bank.BireyselK[i].Hesap[j].HesapNo==HesapSorgu)
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
					for(l=0;l<bank.BireyselK[i].Hesap[j].islemsayisi;l++)
					{
						printf("%d. Islem %d:%d:%d - %d.%d.%d : %d %d %s\n",l+1,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_hour,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_min,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_sec,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_day,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_mon,bank.BireyselK[i].Hesap[j].islem[l].zaman.tm_year,bank.BireyselK[i].Hesap[j].islem[l].islemHesabi,bank.BireyselK[i].Hesap[j].islem[l].islemmik,bank.BireyselK[i].Hesap[j].islem[l].islemturu);
						printf("\nAna menuye dunuluyor.<<<<");
						wait(1);
						system("CLS");
					}
				}
			}
				say++;
		}
		else if(i>bank.Ksayisi.BKullaniciS&&say==0)
		{
			printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
			wait(1);
			system("CLS");
		}
	}
		
	}
	else if(secim==2)
	{
	printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
	scanf("%d",&KullaniciSorgu);
	printf("\nARAMA SONUCU\n------------");
	for(n=0;n<bank.Ksayisi.TKullaniciS;n++)
	{
		if(bank.TicariK[n].KullaniciNo==KullaniciSorgu)
		{
			printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
			printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
			scanf("%d",&HesapSorgu);
			for(j=0;j<bank.TicariK[n].HesapS;j++)
			{
				if(bank.TicariK[n].Hesap[j].HesapNo==HesapSorgu)
				{
					printf("Aradiginiz kelime ile eslesen hesap bulundu.\n");
					for(l=0;l<bank.TicariK[n].Hesap[j].islemsayisi;l++)
					{
					printf("%d. Islem %d:%d:%d - %d.%d.%d : %d %d %s\n",l+1,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_hour,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_min,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_sec,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_day,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_mon,bank.TicariK[n].Hesap[j].islem[l].zaman.tm_year,bank.TicariK[n].Hesap[j].islem[l].islemHesabi,bank.TicariK[n].Hesap[j].islem[l].islemmik,bank.TicariK[n].Hesap[j].islem[l].islemturu);
					printf("\nAna menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
					}
				}
			}
			say++;
		}
		else if(n>bank.Ksayisi.TKullaniciS&&say==0)
		{
			printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
			wait(1);
			system("CLS");
		}
	}
		
	}
}
void HesapKapatma(int secim)
{
	int say=0,k,j,l,KullaniciSorgu,HesapSorgu,sorgula;
	if(secim==1)
	{
		printf("Silmek istediginiz  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.BKullaniciS;k++)
		{
			if(bank.BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz : ");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.BireyselK[k].HesapS;j++)
				{
					if(bank.BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
						label_name:
						if(bank.BireyselK[k].Hesap[j].bakiye==0)
						{
							do
							{
								printf("%d Nolu Hesabi silmek istediginize emin misiniz (1/2)",bank.BireyselK[k].Hesap[j].HesapNo);
								scanf("%d",&sorgula);
							}while(!(sorgula==1||sorgula==2));
							if(sorgula==1)
							{
								for(l=j;l<bank.BireyselK[k].HesapS;l++)
								{
									bank.BireyselK[k].Hesap[l]=bank.BireyselK[k].Hesap[l+1];
								}
								bank.BireyselK[k].HesapS--;
								wait(1);
								system("CLS");
							}
							else if(sorgula==2)
							{
								printf("Islem iptal edildi.\n");
								wait(1);
								system("CLS");
								break;
							}
						}
						else
						{
							hesapK(secim,k,j);
							goto label_name;
							
						}
						
					}
						else if(j>bank.BireyselK[k].HesapS&&say==0)
						{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
						}
				}
				say++;
			}
			else if(k>bank.Ksayisi.BKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}		
	}
	else if(secim==2)
	{
				printf("Giris yapmak icin  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<bank.Ksayisi.TKullaniciS;k++)
		{
			if(bank.TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<bank.TicariK[k].HesapS;j++)
				{
					if(bank.TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
						label_name1:
						if(bank.TicariK[k].Hesap[j].bakiye==0)
						{
							do
							{
								printf("%d Nolu Hesabi silmek istediginize emin misiniz (1/2)",bank.TicariK[k].Hesap[j].HesapNo);
								scanf("%d",&sorgula);
							}while(!(sorgula==1||sorgula==2));
							if(sorgula==1)
							{
								for(l=j;l<bank.TicariK[k].HesapS;l++)
								{
									bank.TicariK[k].Hesap[l]=bank.TicariK[k].Hesap[l+1];
								}
									bank.TicariK[k].HesapS--;
									wait(1);
									system("CLS");
							}
						}
								else if(sorgula==2)
								{
									hesapK(secim,k,j);
									goto label_name1;
								}
						else
						{
							printf("Bakiyenizde para bulunmakta islem iptal ediliyor.\n");
							wait(1);
							system("CLS");
							break;
						}
					
					}
					else if(j>bank.TicariK[k].HesapS&&say==0)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
						wait(1);
						system("CLS");
					}
				}
				say++;
			}
						
			else if(k>bank.Ksayisi.TKullaniciS&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
	
	}
}
void zamanicek(int secim,int k,int j)
{
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);
	if(secim==1)
	{
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_day=tm.tm_mday;
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_year=tm.tm_year+1900;
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_sec=tm.tm_sec;
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_min=tm.tm_min;
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_hour=tm.tm_hour;
	bank.BireyselK[k].Hesap[j].islem[bank.BireyselK[k].Hesap[j].islemsayisi].zaman.tm_mon=tm.tm_mon+1;
	bank.BireyselK[k].Hesap[j].songun=tm.tm_mday;
	}
	else if(secim==2)
	{
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_day=tm.tm_mday;
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_year=tm.tm_year;
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_sec=tm.tm_sec;
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_min=tm.tm_min;
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_hour=tm.tm_hour;
	bank.TicariK[k].Hesap[j].islem[bank.TicariK[k].Hesap[j].islemsayisi].zaman.tm_mon=tm.tm_mon;
	bank.TicariK[k].Hesap[j].songun=tm.tm_mday;
	}
	
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
void hesapK(int secim,int k,int j)
{
	int say=0,KullaniciSorgu=0,HesapSorgu=0,BakiyeS=0;
	if(secim==1)
	{
	do
	{
	printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
	printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.BireyselK[k].Hesap[j].HesapNo,bank.BireyselK[k].KullaniciAdi,bank.BireyselK[k].SoyAdi,bank.BireyselK[k].Hesap[j].bakiye);
	printf("Cekilecek para miktarini giriniz.\n");
	scanf("%d",&BakiyeS);
	}while (bank.BireyselK[k].Hesap[j].bakiye<=BakiyeS&&BakiyeS<0);
	bank.BireyselK[k].Hesap[j].bakiye-=BakiyeS;
	printf("%d hasabinizdan %d TL cekilmistir\n",bank.BireyselK[k].Hesap[j].HesapNo,BakiyeS);
	bank.BireyselK[k].Hesap[j].islemsayisi++;
	bank.Bgiden+=BakiyeS;
	bank.Btop-=BakiyeS;
	
	}

	else if(secim==2)
	{
		
		
		do
		{
		printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
		printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",bank.TicariK[k].Hesap[j].HesapNo,bank.TicariK[k].KullaniciAdi,bank.TicariK[k].SoyAdi,bank.TicariK[k].Hesap[j].bakiye);
		printf("Cekilecek para miktarini giriniz.\n");
		scanf("%d",&BakiyeS);
		}while (BakiyeS<=0||bank.TicariK[k].Hesap[j].bakiye<=BakiyeS);
		bank.TicariK[k].Hesap[j].bakiye-=BakiyeS;
		printf("%d hasabinizdan %d TL cekilmistir\n",bank.TicariK[k].Hesap[j].HesapNo,BakiyeS);
		bank.TicariK[k].Hesap[j].islemsayisi++;
		bank.Bgiden+=BakiyeS;
		bank.Btop-=BakiyeS;
		
	}
			

}