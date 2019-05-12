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
void ParaCekme(int secim,int i,int n);
void ParaYatirma(int secim,int i,int n);
void HesabaHavale(int secim,int i,int n);
void BankaGelirGiderRaporu(int i,int n);
void HesapOzeti(int i,int n);
void HesapKapatma(int i,int n);
void Guncelle();
int No(int j); 
Kullanici TicariK[100];
Kullanici BireyselK[100];
int main()
{	
	menu();
	system("pause"); 
}

void menu()
{
	int n,i;
	OkuBireysel();
	OkuTicari();
	i=Ksayisi.BKullaniciS;
	n=Ksayisi.TKullaniciS;
	
	printf("   Banka otomasyonuna hosgeldiniz.   \n");
	printf("*************************************\n");
	
	printf("Lutfen islem seciniz\n 1-Hesap Yeni Musteri Kaydi Olusturma\n 2-Hesap Acma\n 3-Para Cekme\n 4-Para Yatirma\n 5-Hesaba Havale\n 6-Banka Gelir-Gider Raporu\n 7-Hesap Ozeti\n 8-Hesap Kapatma\n");
	scanf("%d",&secim);			//seçim işlermi burada yapılacak
	switch(secim)
	{
		case 1:
		printf("Kullanicinizi bireysel acmak icin(1)\nTicari acmak icin(2)\n");
		scanf("%d",&secim1);
		YeniMusteriEkleme(secim1,i,n);
		Guncelle();
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		menu();
		break;
		case 2:
		printf("Hesabinizi bireysel acmak icin(1)\nTicari acmak icin(2)\n");
		scanf("%d",&secim1);
		HesapAcma(secim1,i,n);
		Guncelle();
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		menu();
		break;
		case 3:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		ParaCekme(secim1,i,n);
		Guncelle();
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		menu();
		break;
		case 4:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		ParaYatirma(secim1,i,n);
		Guncelle();
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		menu();
		break;
		case 5:
		printf("Bireysel hesap islemi icin(1)\nTicari hesap islemi icin(2)\n");
		scanf("%d",&secim1);
		HesabaHavale(secim1,i,n);
		Guncelle();
		OkuBireysel();
		OkuTicari();
		i=Ksayisi.BKullaniciS;
		n=Ksayisi.TKullaniciS;
		menu();
		break;
	}

}
void OkuBireysel()
{
	int i=0,j;
	FILE *fp;
	fp=fopen("Bireysel.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s - %s - %d",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,&BireyselK[i].KullaniciNo);
		fscanf(fp, "%d", &BireyselK[i].HesapS);
		for (j=0; j<BireyselK[i].HesapS; j++)
		{
			fscanf(fp, "%d %d",&BireyselK[i].Hesap[j].HesapNo,&BireyselK[i].Hesap[j].bakiye);
		}
		i++;
	}
	Ksayisi.BKullaniciS=i-1;
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
	Ksayisi.TKullaniciS=n-1;
	fclose(fp1);
	
}
void YeniMusteriEkleme(int secim,int i,int n)
{
	int secim1;
	if(secim==1)
	{
	FILE *fp;
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
	fprintf(fp,"%s %s - %s - %d\n",BireyselK[i].KullaniciAdi,BireyselK[i].SoyAdi,BireyselK[i].TC,BireyselK[i].KullaniciNo);
	fprintf(fp,"%d\n%d %d",BireyselK[i].HesapS,BireyselK[i].Hesap[0].HesapNo,BireyselK[i].Hesap[0].bakiye);
	fclose(fp);
	Ksayisi.BKullaniciS++;
	printf("\n------------\nKayit Basarili!Ana menuye donuluyor.<<<<");
	system("CLS");
	}
	else if(secim==2)
	{
	FILE *fp1;
	TicariK[i].HesapS=1;
	fp1=fopen("Ticari.txt","a");
	srand(time(NULL));
	printf("\n\nKAYIT EKRANI\n------------\nKisinin\n------------\nAdi    : ");
	scanf("%s",TicariK[i].KullaniciAdi);
	printf("\nSoyadi : ");
	scanf("%s",TicariK[i].SoyAdi);
	printf("TC : ");
	scanf("%s",TicariK[i].TC);
	secim1=1;
	rastgelesayi=No(secim1);
	TicariK[i].Hesap[0].HesapNo=rastgelesayi;
	secim1=2;
	rastgelesayi=No(secim1);
	TicariK[i].KullaniciNo=rastgelesayi;
	printf("\nYeni Kullanici no:%d(Lutfen not ediniz.)\n",TicariK[i].KullaniciNo);
	printf("\nLutfen ilk bakiyeyi giriniz : ");
	scanf("%d",&TicariK[i].Hesap[0].bakiye);
	fprintf(fp1,"%s %s - %s - %d\n",TicariK[i].KullaniciAdi,TicariK[i].SoyAdi,TicariK[i].TC,TicariK[i].KullaniciNo);
	fprintf(fp1,"%d\n%d %d",TicariK[i].HesapS,TicariK[i].Hesap[0].HesapNo,TicariK[i].Hesap[0].bakiye);
	fclose(fp1);
	Ksayisi.BKullaniciS++;
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
					printf("%d",BireyselK[k].Hesap[BireyselK[k].HesapS].bakiye);
					say++;
				}
				else if(k>=i||say==0)
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
			scanf("%d",&sorgu1);
			printf("\nARAMA SONUCU\n------------");
			for(k=0;k<i+1;k++)
			{
				if(TicariK[k].KullaniciNo==sorgu1)//string karþýlaþtýrýcý birbirine eþit(0) ise
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulundu.");
					for(j=0;j<TicariK[k].HesapS;j++)
					{
					printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
					}
					srand(time(NULL));
					rastgelesayi=No(1);
					TicariK[k].Hesap[TicariK[k].HesapS].HesapNo=rastgelesayi;
					printf("Yeni Hesabinizin Bakiyesini Giriniz:");
					scanf("%d",&TicariK[k].Hesap[TicariK[k].HesapS].bakiye);
					TicariK[k].HesapS++;
					printf("%d",TicariK[k].Hesap[TicariK[k].HesapS].bakiye);
					say++;
				}
				else if(k>=i||say==0)
				{
					printf("\nAradiginiz kelime ile eslesen hesap bulunamadi.Ana menuye dunuluyor.<<<<");
					sleep(1);
					system("CLS");
				}
					
				
			}
	}
}
void Guncelle()
{	
	int k,j;
	FILE *fp,*fp1;
	fp=fopen("Bireysel.txt","w");
	for(k=0;k<Ksayisi.BKullaniciS;k++)
	{
		fprintf(fp,"%s %s - %s - %d\n%d\n",BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].TC,BireyselK[k].KullaniciNo,BireyselK[k].HesapS);
		for(j=0;j<BireyselK[k].HesapS;j++)
		{
		fprintf(fp,"%d %d\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].Hesap[j].bakiye);
		}
	}
	fclose(fp);
	fp1=fopen("Ticari.txt","w");
	for(k=0;k<Ksayisi.TKullaniciS;k++)
	{
		fprintf(fp1,"%s %s - %s - %d\n%d\n",TicariK[k].KullaniciAdi,TicariK[k].SoyAdi,TicariK[k].TC,TicariK[k].KullaniciNo,TicariK[k].HesapS);
		for(j=0;j<TicariK[k].HesapS;j++)
		fprintf(fp1,"%d %d\n",TicariK[k].Hesap[j].HesapNo,&TicariK[k].Hesap[j].bakiye);
	}
	fclose(fp1);
}
void ParaCekme(int secim,int i,int n)
{
	int say=0,k,KullaniciSorgu,HesapSorgu,BakiyeS,j;
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
						printf("%d hasabinizdan %d TL cekilmistir",BireyselK[k].Hesap[j].HesapNo,BakiyeS);
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
						do
						{
						printf("\nAradiginiz kelime ile eslesen hesap bulundu.\n");
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						printf("Cekilecek para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (TicariK[k].Hesap[j].bakiye<BakiyeS||750<BakiyeS);
						TicariK[k].Hesap[j].bakiye-=BakiyeS;
						printf("%d hasabinizdan %d TL cekilmistir",TicariK[k].Hesap[j].HesapNo,BakiyeS);
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
						printf("%d hasabinizdan %d TL yatirilmistir",BireyselK[k].Hesap[j].HesapNo,Bakiye);
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
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
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
				sleep(1);
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
						}while (BireyselK[k].Hesap[j].bakiye<BakiyeS||750<BakiyeS);
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
										printf("%d hasabinizdan %d TL cekilmistir",BireyselK[k].Hesap[j].HesapNo,BakiyeS+BakiyeS/50);
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
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(1);
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
						printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
						printf("Havale yapmak istediginiz para miktarini giriniz.\n");
						scanf("%d",&BakiyeS);
						}while (TicariK[k].Hesap[j].bakiye<BakiyeS||750<BakiyeS);
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
										printf("\n<<<<<<<<<<<<\nHesap no : %d\n\nKisinin\n------------\n Adi    : %s\n Soyadi : %s\n Bakiye : %d TL\n------------\n\n\n",BireyselK[k].Hesap[j].HesapNo,BireyselK[k].KullaniciAdi,BireyselK[k].SoyAdi,BireyselK[k].Hesap[j].bakiye);
										TicariK[l].Hesap[m].bakiye+=BakiyeS;
										TicariK[k].Hesap[j].bakiye-=BakiyeS;
										printf("%d hasabinizdan %d TL cekilmistir",TicariK[k].Hesap[j].HesapNo,BakiyeS);
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
				}
				
				
				say++;
			}
			else if(k>i&&say==0)
			{
				printf("\nAradiginiz kelime ile eslesen kullanici bulunamadi.Ana menuye dunuluyor.<<<<");
				sleep(1);
				system("CLS");
			}
		}
		
	}
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
