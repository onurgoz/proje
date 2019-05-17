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
KullaniciS Ksayisi;
Kullanici TicariK[100];
Kullanici BireyselK[100];
int secim,secim1,n; 
int rastgelesayi;
void menu();
void wait(int sure);
void OkuBireysel();
void OkuTicari();
void okudekont();
void okurapor();
void YeniMusteriEkleme(int secim,int i,int n);
void HesapAcma(int secim,int i,int n);
void ParaCekme(int secim,int n,int i);
void ParaYatirma(int secim,int i,int n);
void HesabaHavale(int secim,int i,int n);
void BankaGelirGiderRaporu(int i,int n);
void HesapOzeti(int i,int n);
void HesapKapatma(int secim,int i,int n);
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
	printf("   Banka otomasyonuna hosgeldiniz.   \n");
	printf("*************************************\n");
	
	printf("Lutfen islem seciniz\n 1-Hesap Yeni Musteri Kaydi Olusturma\n 2-Hesap Acma\n 3-Para Cekme\n 4-Para Yatirma\n 5-Hesaba Havale\n 6-Banka Gelir-Gider Raporu\n 7-Hesap Ozeti\n 8-Hesap Kapatma\n");
	scanf("%d",&secim);			//seçim işlermi burada yapılacak
	switch(secim)
	{
		case 1:
		printf("Kullanicinizi bireysel acmak icin(1)\nTicari acmak icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		YeniMusteriEkleme(secim1,i,n);
		Guncelle(secim1);
		menu();
		break;
		case 2:
		printf("Hesabinizi bireysel acmak icin(1)\nTicari acmak icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		HesapAcma(secim1,i,n);
		
		Guncelle(secim1);
		menu();
		break;
		case 3:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		ParaCekme(secim1,i,n);
		Guncelle(secim1);
		menu();
		break;
		case 4:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		ParaYatirma(secim1,i,n);
		Guncelle(secim1);
		menu();
		break;
		case 5:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		HesabaHavale(secim1,i,n);
		Guncelle(secim1);
		menu();
		break;
		case 8:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		HesapKapatma(secim1,i,n);
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
		fscanf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,&BireyselK[i].KullaniciNo);
		fscanf(fp, " Hesap sayisi : %d", &BireyselK[i].HesapS);
		for (j=0; j<BireyselK[i].HesapS; j++)
		{
			fscanf(fp, " Hesap no : %d bakiye : %d",&BireyselK[i].Hesap[j].HesapNo,&BireyselK[i].Hesap[j].bakiye);
		}
		i++;
	}
	Ksayisi.BKullaniciS=i-1;
	
	fclose(fp);
	}
	else if(fp==NULL)
	{
		fclose(fp);
		Ksayisi.BKullaniciS=0;
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
		fscanf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,&TicariK[n].KullaniciNo);
		fscanf(fp1, " Hesap sayisi : %d", &TicariK[n].HesapS);
		for (j=0; j<TicariK[n].HesapS; j++){
			fscanf(fp1, " Hesap no : %d bakiye : %d",&TicariK[n].Hesap[j].HesapNo,&TicariK[n].Hesap[j].bakiye);
		}
		n++;
	}
	Ksayisi.TKullaniciS=n-1;
	fclose(fp1);
	}
	else if(fp1==NULL)
	{
		fclose(fp1);
		Ksayisi.TKullaniciS=0;
	}
	
}
void okudekont()
{
	int n=0,j,k,i;
	FILE *fp,*fp1;
	
	fp=fopen("Dekont1.txt","r");
	if(fp!=NULL)
	{
	while(!feof(fp))
	{
		fscanf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,&TicariK[n].KullaniciNo);
		for (j=0; j<TicariK[n].HesapS; j++){
			fscanf(fp, " Hesap no : %d\nIslem sayisi : %d",&TicariK[n].Hesap[j].HesapNo,&TicariK[n].Hesap[j].islemsayisi);
			for(k=0;k<TicariK[n].Hesap[j].islemsayisi;k++)
			{
				fscanf(fp,"%d:%d:%d - %d.%d.%d : %d %d %s",&TicariK[n].Hesap[j].islem[k].zaman.tm_hour,&TicariK[n].Hesap[j].islem[k].zaman.tm_min,&TicariK[n].Hesap[j].islem[k].zaman.tm_sec,&TicariK[n].Hesap[j].islem[k].zaman.tm_day,&TicariK[n].Hesap[j].islem[k].zaman.tm_mon,&TicariK[n].Hesap[j].islem[k].zaman.tm_year,&TicariK[n].Hesap[j].islem[k].islemHesabi,&TicariK[n].Hesap[j].islem[k].islemmik,TicariK[n].Hesap[j].islem[k].islemturu);
			}
		}
		n++;
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
	while(!feof(fp1))
	{
		fscanf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,&TicariK[i].KullaniciNo);
		for (j=0; j<BireyselK[i].HesapS; j++){
			fscanf(fp, " Hesap no : %d\nIslem sayisi : %d",&BireyselK[i].Hesap[j].HesapNo,&BireyselK[i].Hesap[j].islemsayisi);
			for(k=0;k<BireyselK[i].Hesap[j].islemsayisi;k++)
			{
				fscanf(fp1,"%d:%d:%d - %d.%d.%d : %d %d %s",&BireyselK[i].Hesap[j].islem[k].zaman.tm_hour,&BireyselK[i].Hesap[j].islem[k].zaman.tm_min,&BireyselK[i].Hesap[j].islem[k].zaman.tm_sec,&BireyselK[i].Hesap[j].islem[k].zaman.tm_day,&BireyselK[i].Hesap[j].islem[k].zaman.tm_mon,&BireyselK[i].Hesap[j].islem[k].zaman.tm_year,&BireyselK[i].Hesap[j].islem[k].islemHesabi,&BireyselK[i].Hesap[j].islem[k].islemmik,BireyselK[i].Hesap[j].islem[k].islemturu);
			}
		}
		i++;
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

}
void YeniMusteriEkleme(int secim,int i,int n)
{
	int secim1;
	if(secim==1)
	{
	FILE *fp;
	BireyselK[i].Hesap[0].islemsayisi=0;
	BireyselK[i].HesapS=1;
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
	fprintf(fp,"Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,BireyselK[i].KullaniciNo);
	fprintf(fp,"Hesap sayisi : %d\nHesap no : %d bakiye : %d",BireyselK[i].HesapS,BireyselK[i].Hesap[0].HesapNo,BireyselK[i].Hesap[0].bakiye);
	fclose(fp);
	Ksayisi.BKullaniciS++;
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	system("CLS");
	}
	else if(secim==2)
	{
	FILE *fp1;
	TicariK[i].Hesap[0].islemsayisi=0;
	TicariK[n].HesapS=1;
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
	printf("\nYeni Kullanici no:%d(Lutfen not ediniz.)\n",TicariK[n].KullaniciNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&TicariK[n].Hesap[0].bakiye);
	fprintf(fp1,"Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,TicariK[n].KullaniciNo);
	fprintf(fp1,"Hesap sayisi : %d\nHesap no : %d bakiye : %d",TicariK[n].HesapS,TicariK[n].Hesap[0].HesapNo,TicariK[n].Hesap[0].bakiye);
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
					for(j=0;j<BireyselK[k].HesapS;j++)
					{
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
					}
					srand(time(NULL));
					rastgelesayi=No(1);
					BireyselK[k].Hesap[BireyselK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&BireyselK[k].Hesap[BireyselK[k].HesapS].bakiye);
					BireyselK[k].HesapS++;
					say++;
				}
				else if(k>=i&&say==0)
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
			for(k=0;k<i+1;k++)
			{
				if(TicariK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
					for(j=0;j<TicariK[k].HesapS;j++)
					{
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
					}
					srand(time(NULL));
					rastgelesayi=No(1);
					TicariK[k].Hesap[TicariK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&TicariK[k].Hesap[TicariK[k].HesapS].bakiye);
					TicariK[k].HesapS++;
					

					say++;
				}
				else if(k>=i&&say==0)
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
	for(k=0;k<Ksayisi.BKullaniciS;k++)
	{
		fprintf(fp," Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\nHesap sayisi : %d\n",BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].TC,BireyselK[k].KullaniciNo,BireyselK[k].HesapS);
		for(j=0;j<BireyselK[k].HesapS;j++)
		{
		fprintf(fp," Hesap no : %d bakiye : %d\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].Hesap[j].bakiye);
		}
		
	}
	
	fclose(fp);
	}
	else if(secim==2)
	{
	fp1=fopen("Ticari.txt","w");
	for(k=0;k<Ksayisi.TKullaniciS;k++)
	{
		fprintf(fp1," Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\nHesap sayisi : %d\n",TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].TC,TicariK[k].KullaniciNo,TicariK[k].HesapS);
		for(j=0;j<TicariK[k].HesapS;j++)
		fprintf(fp1," Hesap no : %d bakiye : %d\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].Hesap[j].bakiye);
	}
	fclose(fp1);
	}
	fp=fopen("Dekont1.txt","w");
	for(n=0;n<Ksayisi.TKullaniciS;n++)
	{
	fprintf(fp, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",TicariK[n].KullaniciAdi,TicariK[n].SoyAdi,TicariK[n].TC,TicariK[n].KullaniciNo);
		for (j=0; j<TicariK[n].HesapS; j++)
		{
			fprintf(fp, " Hesap no : %d\nIslem sayisi : %d\n",TicariK[n].Hesap[j].HesapNo,TicariK[n].Hesap[j].islemsayisi);
			for(k=0;k<TicariK[n].Hesap[j].islemsayisi;k++)
			{
				fprintf(fp,"%d:%d:%d - %d.%d.%d : %d %d %s\n",TicariK[n].Hesap[j].islem[k].zaman.tm_hour,TicariK[n].Hesap[j].islem[k].zaman.tm_min,TicariK[n].Hesap[j].islem[k].zaman.tm_sec,TicariK[n].Hesap[j].islem[k].zaman.tm_day,TicariK[n].Hesap[j].islem[k].zaman.tm_mon,TicariK[n].Hesap[j].islem[k].zaman.tm_year,TicariK[n].Hesap[j].islem[k].islemHesabi,TicariK[n].Hesap[j].islem[k].islemmik,TicariK[n].Hesap[j].islem[k].islemturu);
			}
		}
	}	
		fclose(fp);
	fp1=fopen("Dekont.txt","w");
	for(i=0;i<Ksayisi.BKullaniciS;i++)
	{
	fprintf(fp1, " Adi : %s Soyadi : %s - TC : %s Kullanici numarasi : %d\n",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,BireyselK[i].KullaniciNo);
	for (j=0; j<BireyselK[i].HesapS; j++)
	{
		fprintf(fp, " Hesap no : %d\nIslem sayisi : %d\n",BireyselK[i].Hesap[j].HesapNo,BireyselK[i].Hesap[j].islemsayisi);
		for(k=0;k<BireyselK[i].Hesap[j].islemsayisi;k++)
		{
			fprintf(fp1,"%d:%d:%d - %d.%d.%d : %d %d %s\n",BireyselK[i].Hesap[j].islem[k].zaman.tm_hour,BireyselK[i].Hesap[j].islem[k].zaman.tm_min,BireyselK[i].Hesap[j].islem[k].zaman.tm_sec,BireyselK[i].Hesap[j].islem[k].zaman.tm_day,BireyselK[i].Hesap[j].islem[k].zaman.tm_mon,BireyselK[i].Hesap[j].islem[k].zaman.tm_year,BireyselK[i].Hesap[j].islem[k].islemHesabi,BireyselK[i].Hesap[j].islem[k].islemmik,BireyselK[i].Hesap[j].islem[k].islemturu);
		}
	}
	}
	fclose(fp1);
}
void ParaCekme(int secim,int n,int i)
{
	int say=0,k,KullaniciSorgu=0,HesapSorgu=0,BakiyeS=0,j;
	if(secim==1)
	{
		printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i+1;k++)
		{
			if(BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<BireyselK[k].HesapS;j++)
				{
					if(BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						printf("Cekilecek para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (BireyselK[k].Hesap[j].bakiye<BakiyeS||750<BakiyeS);
						BireyselK[k].Hesap[j].bakiye-=BakiyeS;
						zamanicek(1,k,j);
						printf("%d hasabinizdan %d TL cekilmistir",BireyselK[k].Hesap[j].HesapNo,BakiyeS);
						BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemHesabi=BireyselK[k].Hesap[j].HesapNo;
						BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
						strcpy(BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemturu,"cekildi.");
						BireyselK[k].Hesap[j].islemsayisi++;
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
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
			if(TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<TicariK[k].HesapS;j++)
				{
					if(TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
						printf("Cekilecek para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (TicariK[k].Hesap[j].bakiye<BakiyeS||1500>=BakiyeS);
						TicariK[k].Hesap[j].bakiye-=BakiyeS;
						zamanicek(2,k,j);
						printf("%d hasabinizdan %d TL cekilmistir",TicariK[k].Hesap[j].HesapNo,BakiyeS);
						TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemHesabi=TicariK[k].Hesap[j].HesapNo;
						TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
						strcpy(TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemturu,"cekildi.");
						TicariK[k].Hesap[j].islemsayisi++;
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}

}
void ParaYatirma(int secim,int i,int n)
{
	int say=0,k,KullaniciSorgu,HesapSorgu,Bakiye,j;
	if(secim==1)
	{
		printf("Hesap acmak istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i+1;k++)
		{
			if(BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<BireyselK[k].HesapS;j++)
				{
					if(BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						
						
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						printf("Yatirilacak para miktarini giriniz.\n");
						scanf("%d",&Bakiye);
						BireyselK[k].Hesap[j].bakiye+=Bakiye;
						zamanicek(1,k,j);
						printf("%d hasabinizdan %d TL yatirilmistir",BireyselK[k].Hesap[j].HesapNo,Bakiye);
						BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemHesabi=BireyselK[k].Hesap[j].HesapNo;
						BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemmik=Bakiye;
						strcpy(BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemturu,"yatirildi.");
						BireyselK[k].Hesap[j].islemsayisi++;
						
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
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
		for(k=0;k<i+1;k++)
		{
			if(TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<TicariK[k].HesapS;j++)
				{
					if(TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						
						
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
						printf("Yatirilacak para miktarini giriniz.\n");
						scanf("%d",&Bakiye);
						TicariK[k].Hesap[j].bakiye+=Bakiye;
						zamanicek(2,k,j);
						printf("%d hasabinizdan %d TL yatirilmistir",TicariK[k].Hesap[j].HesapNo,Bakiye);
						TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemHesabi=TicariK[k].Hesap[j].HesapNo;
						TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemmik=Bakiye;
						strcpy(TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemturu,"yatirildi.");
						TicariK[k].Hesap[j].islemsayisi++;
						
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}

}
void HesabaHavale(int secim,int i,int n)
{

	int say=0,k,j,KullaniciSorgu,KullaniciSorgu1,HesapSorgu,HesapSorgu1,BakiyeS,l,m;
	if(secim==1)
	{
		printf("Giris yapmak icin  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i+1;k++)
		{
			if(BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<BireyselK[k].HesapS;j++)
				{
					if(BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						printf("Havale yapmak istediginiz para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (BireyselK[k].Hesap[j].bakiye<(BakiyeS+BakiyeS/50));
						printf("Gondericeginiz kisinin Kullanici Numarasini giriniz :\n");
						scanf("%d",&KullaniciSorgu1);
						printf("\nARAMA SONUCU\n------------");
						for(l=0;l<i+1;l++)
						{
							if(BireyselK[l].KullaniciNo==KullaniciSorgu1)
							{
							printf("\nAradiginiz kelime ile eslesen Kullanici bulundu.\n");
							printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
							scanf("%d",&HesapSorgu1);
							for(m=0;m<BireyselK[l].HesapS;m++)
							{
								if(BireyselK[l].Hesap[m].HesapNo==HesapSorgu1)
								{
										printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
										printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
										BireyselK[k].Hesap[j].bakiye-=BakiyeS+BakiyeS/50;
										BireyselK[l].Hesap[m].bakiye+=BakiyeS;
										zamanicek(1,k,j);
										zamanicek(1,l,m);
										printf("%d hasabinizdan %d TL cekilmistir",BireyselK[k].Hesap[j].HesapNo,BakiyeS+BakiyeS/50);
										BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemHesabi=BireyselK[l].Hesap[m].HesapNo;
										BireyselK[l].Hesap[m].islem[BireyselK[l].Hesap[m].islemsayisi].islemHesabi=BireyselK[k].Hesap[j].HesapNo;
										BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
										BireyselK[l].Hesap[m].islem[BireyselK[l].Hesap[m].islemsayisi].islemmik=BakiyeS;
										strcpy(BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].islemturu,"havale yapilmistir.");
										strcpy(BireyselK[l].Hesap[m].islem[BireyselK[l].Hesap[m].islemsayisi].islemturu,"havale gelmistir.");
										BireyselK[k].Hesap[j].islemsayisi++;
										BireyselK[l].Hesap[m].islemsayisi++;
										
								}
							}
						
						
							say++;
						}
						else if(k>i&&say==0)
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
			else if(k>i&&say==0)
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
		for(k=0;k<i+1;k++)
		{
			if(TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<TicariK[k].HesapS;j++)
				{
					if(TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
						printf("Havale yapmak istediginiz para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (TicariK[k].Hesap[j].bakiye<BakiyeS);
						printf("Gondericeginiz kisinin Kullanici Numarasini giriniz :\n");
						scanf("%d",&KullaniciSorgu1);
						printf("\nARAMA SONUCU\n------------");
						for(l=0;l<i+1;l++)
						{
							if(TicariK[l].KullaniciNo==KullaniciSorgu1)
							{
							printf("\nAradiginiz kelime ile eslesen Kullanici bulundu.\n");
							printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
							scanf("%d",&HesapSorgu1);
							for(m=0;m<TicariK[l].HesapS;m++)
							{
								if(TicariK[l].Hesap[m].HesapNo==HesapSorgu1)
								{
										printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
										printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
										TicariK[l].Hesap[m].bakiye+=BakiyeS;
										TicariK[k].Hesap[j].bakiye-=BakiyeS;
										zamanicek(2,k,j);
										zamanicek(2,l,m);
										printf("%d hasabinizdan %d TL cekilmistir",TicariK[k].Hesap[j].HesapNo,BakiyeS);
										TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemHesabi=TicariK[l].Hesap[m].HesapNo;
										TicariK[l].Hesap[m].islem[TicariK[l].Hesap[m].islemsayisi].islemHesabi=TicariK[k].Hesap[j].HesapNo;
										TicariK[l].Hesap[m].islem[TicariK[l].Hesap[m].islemsayisi].islemmik=BakiyeS;
										TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemmik=BakiyeS;
										strcpy(TicariK[l].Hesap[m].islem[TicariK[l].Hesap[m].islemsayisi].islemturu,"Havale gelmistir.");
										strcpy(TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].islemturu,"Havale yapilmistir.");
										TicariK[l].Hesap[m].islemsayisi++;
										TicariK[k].Hesap[j].islemsayisi++;
										
								}
							}
						
						
							say++;
						}
						else if(k>i&&say==0)
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
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}
}
void BankaGelirGiderRaporu(int i,int n)
{

}
void HesapOzeti(int i,int n)//iyice incele
{
int say=0,k,KullaniciSorgu,HesapSorgu,Bakiye,j,ilktarih,sontarih;
	if(secim==1)
	{
		printf("Hesap ozetini gormek istediginiz kisinin Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i+1;k++)
		{
			if(BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<BireyselK[k].HesapS;j++)
				{
					if(BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						
						
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("Tarih araligini giriniz : ");
						scanf("%d",&ilktarih);
						printf("Tarih araligini giriniz : ");
						scanf("%d",&sontarih);
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
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
		for(k=0;k<i+1;k++)
		{
			if(TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<TicariK[k].HesapS;j++)
				{
					if(TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						
						
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
						printf("Yatirilacak para miktarini giriniz.\n");
						scanf("%d",&Bakiye);
						TicariK[k].Hesap[j].bakiye+=Bakiye;
						printf("%d hasabinizdan %d TL yatirilmistir",TicariK[k].Hesap[j].HesapNo,Bakiye);
						
					}
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
				wait(1);
				system("CLS");
			}
		}
		
	}
}
void HesapKapatma(int secim,int i,int n)
{
	int say=0,k,j,l,KullaniciSorgu,HesapSorgu,sorgula;
	if(secim==1)
	{
		printf("Silmek istediginiz  Kullanici Numarasini giriniz :\n");
		scanf("%d",&KullaniciSorgu);
		printf("\nARAMA SONUCU\n------------");
		for(k=0;k<i+1;k++)
		{
			if(BireyselK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz : ");
				scanf("%d",&HesapSorgu);
				for(j=0;j<BireyselK[k].HesapS;j++)
				{
					if(BireyselK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						if(BireyselK[k].Hesap[j].bakiye==0)
						{
							do
							{
								printf("%d Nolu Hesabi silmek istediginize emin misiniz (1/2)");
								scanf("%d",&sorgula);
							}while(!(sorgula==1||sorgula==2));
							if(sorgula==1)
							{
								for(l=j;l<BireyselK[k].HesapS;l++)
								{
									BireyselK[k].Hesap[l]=BireyselK[k].Hesap[l+1];
								}
								BireyselK[k].HesapS--;
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
							printf("Bakiyenizde para bulunmakta islem iptal ediliyor.\n");
							wait(1);
							system("CLS");
							break;
						}
						
					}
						else if(k>i&&say==0)
						{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					wait(1);
					system("CLS");
						}
				}
				say++;
			}
			else if(k>i&&say==0)
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
		for(k=0;k<i+1;k++)
		{
			if(TicariK[k].KullaniciNo==KullaniciSorgu)
			{
				printf("\nAradiginiz numara ile eslesen kullanici bulundu.\n");
				printf("Islem yapmak istediginiz hesabin numarasini giriniz\n");
				scanf("%d",&HesapSorgu);
				for(j=0;j<TicariK[k].HesapS;j++)
				{
					if(TicariK[k].Hesap[j].HesapNo==HesapSorgu)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",TicariK[k].Hesap[j].HesapNo,TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].Hesap[j].bakiye);
						if(TicariK[k].Hesap[j].bakiye==0)
						{
							do
							{
								printf("%d Nolu Hesabi silmek istediginize emin misiniz (1/2)");
								scanf("%d",&sorgula);
							}while(!(sorgula==1||sorgula==2));
							if(sorgula==1)
							{
								for(l=j;l<TicariK[k].HesapS;l++)
								{
									TicariK[k].Hesap[l]=TicariK[k].Hesap[l+1];
								}
									TicariK[k].HesapS--;
							}
						}
								else if(sorgula==2)
								{
									printf("Islem iptal edildi.\n");
									system("CLS");
								}
						else
						{
							printf("Bakiyenizde para bulunmakta islem iptal ediliyor.\n");
							wait(1);
							system("CLS");
							break;
						}
					
					}
					else if(k>i&&say==0)
					{
						printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
						wait(1);
						system("CLS");
					}
				}
				say++;
			}
						
			else if(k>i&&say==0)
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
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_day=tm.tm_mday;
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_year=tm.tm_year;
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_sec=tm.tm_sec;
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_min=tm.tm_min;
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_hour=tm.tm_hour;
	BireyselK[k].Hesap[j].islem[BireyselK[k].Hesap[j].islemsayisi].zaman.tm_mon=tm.tm_mon;
	}
	else if(secim==2)
	{
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_day=tm.tm_mday;
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_year=tm.tm_year;
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_sec=tm.tm_sec;
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_min=tm.tm_min;
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_hour=tm.tm_hour;
	TicariK[k].Hesap[j].islem[TicariK[k].Hesap[j].islemsayisi].zaman.tm_mon=tm.tm_mon;
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
