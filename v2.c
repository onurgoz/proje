#include <stdio.h>
#include <stdlib.h>
#include <time.h>//srand
#include <locale.h>//setlocale komutu için
#include <windows.h>//sleep komutu için
#include <conio.h>
#include <string.h>//remove,rename
#include <sys/time.h>

struct veri{	//Ýstenen veri tip ve bilgileri
char *ad;
char *soyad;
char *hesapno;
int bakiye;
};
void yenile();
int altihane();
int para_islem(int);
void para_transfer();
int alici();
int tarih();
void ekle();
void ara();
void sil();
void menu();
void delay(unsigned int dakika)
{
    clock_t sayi = dakika + clock();
    while (sayi > clock());
}
int main()//------------------------------------------------------MAIN
{
	menu();
	return 0;
}		 //-------------------------------------------------------MAIN

void menu()
{
	int secim,tercih;
	char c;
	setlocale(LC_ALL,"Turkish");//Türkçe karakter için
	printf("Manisa Celal Bayar Üniversitesi / Yazýlým Mühendisliði\n");
 	printf("YZM-1106 Algoritma ve Programlama II Dersi (2018-2019)\n");
	printf("Dönem Projesi / Banka Yazýlým Otomasyonu\n\n");
	printf("------------------------------------------------------------");
	basa:
	basa2:
	
	printf("\n1-Kullanýcý Ýþlemleri\n\n2-Para Yatýrma-Çekme Ýþlemleri\n\n3-Hesaplar Arasý Para Transferi\n\n4-Hesap Özeti\n\nSeçiminiz[1-4] : ");
	scanf("%d",&secim);
//	yenile();
	system("CLS");//Ekraný temizler
	//Bekletip açarak yükleniyor efekti verir
	switch(secim)
	{	
	case 1:
	{
		while(06)
		{
			typedef struct veri oku;
			printf("\n\n1-Kullanýcý Ekle\n\n2-Kullanýcý Ara\n\n3-Kullanýcý Sil\n\nSeçiminiz : \n");
			scanf("%d",&tercih);
			system("CLS");
			switch(tercih)
			{
				case 1:
				{
					ekle();
					goto def;
					break;
				}
				case 2:
				{
					ara();
					goto def;
					break;
				}
				case 3:
				{
					sil();
					goto def;
					break;
				}
			}
		}
	}
	case 2:
	{
			int sorgu, secim;
			int  tut_bakiye, miktar;
			char gsorgu[106];
			printf("\n\n1-Hesaptan para çekme\n\n2-Hesaba para yatýrma\nSeçiminiz : ");
			scanf("%d",&secim);
			hesapnogir:	
			printf("Lütfen kullanýcýnýn hesap numarasýný giriniz : ");
			scanf("%d",&sorgu);
			yenile();
			switch(secim)
			{
				case 1:
					{
					time_t basla,bit;
 					time (&basla);	
					typedef struct veri kayit;
					kayit oku;
					int son_bakiye;
					tut_bakiye=para_islem(sorgu);
					while(tut_bakiye==0)
					{
						system("CLS");
						goto hesapnogir;
						printf("\n");
					}
					printf("\nÇekmek istediðiniz miktarý giriniz : ");
					scanf("%d",&miktar);
					while(miktar>tut_bakiye)
					{
						printf("Bakiyeniz yeterli deðildir.\nMevcut bakiyeniz %d.Lütfen tekrar giriniz : ",tut_bakiye);
						scanf("%d",&miktar);
					}
					while(miktar<=0)
					{
						printf("Yanlýþ tutar girdiniz.\nMevcut bakiyeniz %d.Lütfen tekrar giriniz : ",tut_bakiye);
						scanf("%d",&miktar);
					}
					FILE *yfp=fopen("kayit.txt","r");
					FILE *nfp=fopen("kayit2.txt","w");
					oku.hesapno=(char*)malloc(sizeof(char)*100);
					oku.ad=(char*)malloc(sizeof(char)*100);
					oku.soyad=(char*)malloc(sizeof(char)*100);
					itoa(sorgu,gsorgu,10);
					while(!feof(yfp))
					{
						fscanf(yfp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
						if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							oku.bakiye=tut_bakiye-miktar;
							son_bakiye=oku.bakiye;
							fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
						}
						if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							continue;
						}
						if(feof(yfp))
						{	
							break;
						}
						fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
					}
					printf("\nPara çekme iþlemi baþarýlý!Kalan bakiye : %d ",son_bakiye);
					time (&bit);
					printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
					fclose(yfp);
					fclose(nfp);
					remove("kayit.txt");
					rename("kayit2.txt","kayit.txt");
					goto basa;
					break;
			}
				case 2:
					{
					typedef struct veri kayit;
					kayit oku;
					int son_bakiye;
					time_t basla,bit;
 					time (&basla);					
					tut_bakiye=para_islem(sorgu);
					while(tut_bakiye==-1)
					{
						goto hesapnogir;
						printf("\n");
					}
					printf("\nYatýrmak istediðiniz miktarý giriniz : ");
					scanf("%d",&miktar);
					FILE *yfp=fopen("kayit.txt","r");
					FILE *nfp=fopen("kayit2.txt","w");
					oku.hesapno=(char*)malloc(sizeof(char)*100);
					oku.ad=(char*)malloc(sizeof(char)*100);
					oku.soyad=(char*)malloc(sizeof(char)*100);
					itoa(sorgu,gsorgu,10);
					while(!feof(yfp))
					{
						fscanf(yfp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
						if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							oku.bakiye=tut_bakiye+miktar;
							son_bakiye=oku.bakiye;
							fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
						}
						if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							continue;
						}
						if(feof(yfp))
						{	
							break;
						}
						fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
					}
					printf("\nPara yatýrma iþlemi baþarýlý!Yeni bakiye : %d",son_bakiye);
					time (&bit);
					printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
					fclose(yfp);
					fclose(nfp);
					remove("kayit.txt");
					rename("kayit2.txt","kayit.txt");
					system("CLS");
					goto basa;
					break;
					}
					
		}
	}
	case 3:
		{
			int secim_bos;
			printf("1-Kendi hesaplarým arasý\n\n2-Baþka bir hesaba\nSeçiminiz : ");
			scanf("%d",&secim_bos);
			yenile();
			para_transfer();
			goto basa;
			break;
		}
	case 4:
		{
			int sorgu;
			printf("Lütfen kullanýcý bilgisine ulaþmak\n istediðiniz hesabýn numarasýný giriniz : ");
			time_t basla,bit;
			time (&basla);
			yenile();
			scanf("%d",&sorgu);
			para_islem(sorgu);
			time (&bit);
			printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
			goto basa;
			break;
		}
		default:
		{
				
				typedef struct veri kayit;
				kayit oku;
				char *bos;
				def:
				bos="000000";
				FILE *fp=fopen("kayit.txt","r");
				FILE *sfp=fopen("gecici.txt","w");
				oku.hesapno=(char*)malloc(sizeof(char)*100);
				oku.ad=(char*)malloc(sizeof(char)*100);
				oku.soyad=(char*)malloc(sizeof(char)*100);
				while(!feof(fp))
					{
						fscanf(fp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
						if(strcmp(bos,oku.hesapno)==0)
						{
							continue;
						}
						if(feof(fp))
						{
							fprintf(sfp,"%s %s %s %d\n","000000","dosya","sonu",001);
							break;
						}
						fprintf(sfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
					}
					fclose(fp);
					fclose(sfp);
					remove("kayit.txt");
					rename("gecici.txt","kayit.txt");
					goto basa;
					}
				}
}
void yenile()
{
	typedef struct veri kayit;
	kayit oku;
	char *bos;
	def:
	bos="000000";
	FILE *fp=fopen("kayit.txt","r");
	FILE *sfp=fopen("gecici.txt","w");
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	oku.ad=(char*)malloc(sizeof(char)*100);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
			if(strcmp(bos,oku.hesapno)==0)
				{
					continue;
				}
			if(feof(fp))
				{
					fprintf(sfp,"%s %s %s %d\n","000000","dosya","sonu",001);
					break;
				}
			fprintf(sfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
		}
	fclose(fp);
	fclose(sfp);
	remove("kayit.txt");
	rename("gecici.txt","kayit.txt");
}
int para_islem(int sorgu)
{
	yenile();
	typedef struct veri kayit;
	kayit oku;
	int sakla, say;
	char gsorgu[106];
	FILE *fp=fopen("kayit.txt","r");
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	oku.ad=(char*)malloc(sizeof(char)*100);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	itoa(sorgu,gsorgu,10);
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
		if(strcmp(oku.hesapno,gsorgu)==0)
		{
			printf("Hesap no : %s\n\nKiþinin\n------------\n Adý    : %s\n Soyadý : %s\n Bakiye : %d TL\n------------\n\n\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
			++say;
			sakla=oku.bakiye;
		}
	}
	if(say==0)
	{
		printf("\nHesap bulunamadý.");
		sakla=0;
	}
	fclose(fp);
	return sakla;
}
void para_transfer()
{
	int sorgu;
	int  tut_bakiye, miktar;
	char gsorgu[106];
	typedef struct veri kayit;
	kayit oku;
	int son_bakiye;
	printf("Gönderen Hesap için\n-----------------------\nLütfen kullanýcýnýn hesap numarasýný giriniz : ");
	hesapnogir:
	scanf("%d",&sorgu);
	if((tut_bakiye=para_islem(sorgu))==(0))
		{
			printf("\nBu hesap numarasý yanlýþ.Lütfen tekrar giriniz.\n");
			
			goto hesapnogir;
		}
	else
	{
	printf("\nGöndermek istediðiniz miktarý giriniz : ");
	scanf("%d",&miktar);
	while(miktar>tut_bakiye)
		{
			printf("Bakiyeniz yeterli deðildir.\nMevcut bakiyeniz %d.Lütfen tekrar giriniz : ",tut_bakiye);
			scanf("%d",&miktar);
		}
	while(miktar<=0)
		{
			printf("\nBu hesapta yeterli bakiye yok.\nLütfen tekrar hesap numaranýzý giriniz : ");
			goto hesapnogir;
		}
	if(alici(miktar)!=-1)//eðer iþlemden vazgeçilirse alici fonksiyonundan -1 deðeri gelecek ve bu iþleme devam etmeyecek
		{
			FILE *yfp=fopen("kayit.txt","r");
			FILE *nfp=fopen("kayit2.txt","w");
			oku.hesapno=(char*)malloc(sizeof(char)*100);
			oku.ad=(char*)malloc(sizeof(char)*100);
			oku.soyad=(char*)malloc(sizeof(char)*100);
			itoa(sorgu,gsorgu,10);
			while(!feof(yfp))
				{
					fscanf(yfp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
					if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							oku.bakiye=tut_bakiye-miktar;
							son_bakiye=oku.bakiye;
							fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
						}
					if(strcmp(oku.hesapno,gsorgu)==0)
						{	
							continue;
						}
					if(feof(yfp))
						{	
							break;
						}
					fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
				}
	fclose(yfp);
	fclose(nfp);
	remove("kayit.txt");
	rename("kayit2.txt","kayit.txt");
		}
	}
}
int alici(int miktar)
{
	yenile();
	int sorgu;
	int  tut_bakiye;
	char gsorgu[106], secim_onay;
	typedef struct veri kayit;
	kayit oku;
	int son_bakiye;
	time_t basla,bit;
 	time (&basla);	
	printf("Gönderilecek hesap için\n-----------------------\nLütfen kullanýcýnýn hesap numarasýný giriniz : ");
	hesapnogir:
	scanf("%d",&sorgu);
	tut_bakiye=para_islem(sorgu);
	printf("%d hesap numaralý hesaba, %d TL gönderilecek.Onaylýyor musunuz?[E/H]",sorgu,miktar);
	secimnoktasi:
	scanf("%s",&secim_onay);
	if(secim_onay=='E'||secim_onay=='e')
	{
	FILE *yfp=fopen("kayit.txt","r");
	FILE *nfp=fopen("kayit2.txt","w");
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	oku.ad=(char*)malloc(sizeof(char)*100);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	itoa(sorgu,gsorgu,10);
	while(!feof(yfp))
		{
			fscanf(yfp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
			if(strcmp(oku.hesapno,gsorgu)==0)
				{	
					oku.bakiye=tut_bakiye+miktar;
					son_bakiye=oku.bakiye;
					fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
				}
			if(strcmp(oku.hesapno,gsorgu)==0)
				{	
					continue;
				}
			if(feof(yfp))
				{	
					break;
				}
			fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
		}
	printf("\nHavale iþlemi baþarýlý!Yeni bakiye : %d TL",son_bakiye);
	time (&bit);
	printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));		
	fclose(yfp);
	fclose(nfp);
	remove("kayit.txt");
	rename("kayit2.txt","kayit.txt");
	return son_bakiye;
	}
	else if(secim_onay=='H'||secim_onay=='h')
	{
		printf("\nÝþlemden vazgeçildi.Ana menüye dönülüyor.<<<<\n");
		system("CLS");
		son_bakiye=-1;
		return son_bakiye;
	}
	else
	{
		printf("\nYanlýþ harfe bastýnýz.Lütfen [E/H] harflerinden birine basýnýz.\nSeçiminiz : ");
		goto secimnoktasi;
	}
}
int tarih(int sayi)
{
	int tarih1;
	tarih1=sayi%12;
	return tarih1;
}
void ekle()
{
	typedef struct veri kayit;//kayit adýnda bir int float gibi tip oluþturduk ve veriyle bað kurduk sayýlýr
	double rastgelesayi;
	srand(time(NULL));
	kayit oku;
	time_t basla,bit;
 	time (&basla);
	oku.ad=(char*)malloc(sizeof(char)*100);//malloc komutu ada göre hafýzada tutulan alaný deðiþtiriyor
	printf("\n\nKAYIT EKRANI\n------------\nKiþinin\n------------\nAdý    : ");
	scanf("%s",oku.ad);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	printf("\nSoyadý : ");
	scanf("%s",oku.soyad);
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	rastgelesayi=altihane();
	itoa(rastgelesayi,oku.hesapno,10);//int deðiþkenini stringe çevirip Hexadesimal16,Binar2 veya 10luk tabanýna göre yazýyor
	printf("\nYeni hesap no:%s(Lütfen not ediniz.)\n",oku.hesapno);
	printf("\nLütfen ilk bakiyeyi giriniz : ");
	scanf("%d",&oku.bakiye);
	FILE *fp;
	fp=fopen("kayit.txt","a");//a modunun özelliði: dosya yoksa oluþtur ve yaz,varsa sýradan yaz
	fprintf(fp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
	fclose(fp);
	printf("\n------------\nKayýt Baþarýlý!Ana menüye dönülüyor.<<<<");
	time (&bit);
	printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
	
	system("CLS");
}
void ara()
{	
	typedef struct veri kayit;
	kayit oku;
	int say=0;
	char sorgu[106];
	FILE *fp; 
	fp=fopen("kayit.txt","r");//r modu sadece dosyadan okur
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	oku.ad=(char*)malloc(sizeof(char)*100);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	time_t basla,bit;
 	time (&basla);
	printf("\n\nLütfen aranacak kiþinin adýný veya soyadýný giriniz : ");
	scanf("%s",&sorgu);
	printf("\nARAMA SONUCU\n------------");
	while(!feof(fp))//feof:end of file fp dosyasýnýn en sonuna git
	{
		fscanf(fp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
		if(strcmp(oku.ad,sorgu)==0)//string karþýlaþtýrýcý birbirine eþit(0) ise
		{
			printf("\n<<<<<<<<<<<<\nHesap no : %s\n\nKiþinin\n------------\n Adý    : %s\n Soyadý : %s\n Bakiye : %d TL\n------------\n\n\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
		++say;//kaç hesap bu kelimeyi içeriyorsa say 
		}
		if(strcmp(oku.soyad,sorgu)==0)
		{
			printf("\n<<<<<<<<<<<<\nHesap no : %s\n\nKiþinin\n------------\n Adý    : %s\n Soyadý : %s\n Bakiye : %d TL\n------------\n\n\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
		++say;
		}
	}
	if(say==0)
	{
		printf("\nAradýðýnýz kelime ile eþleþen hesap bulunamadý.Ana menüye dönülüyor.<<<<");
		time (&bit);
		printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
		
		system("CLS");
	}
	else
	{
		printf("\nAradýðýnýz kelime ile eþleþen %d hesap bulundu.",say);
		time (&bit);
		printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
	}
	fclose(fp);
}
void sil()
{
	
	typedef struct veri kayit;
	kayit oku;
	int sorgu,say;
	char gecici_sorgu[106], onay_silme[06];
	FILE *rfp; 
	rfp=fopen("kayit.txt","r");
	oku.hesapno=(char*)malloc(sizeof(char)*100);
	oku.ad=(char*)malloc(sizeof(char)*100);
	oku.soyad=(char*)malloc(sizeof(char)*100);
	printf("\n\nAranacak kiþinin hesap numarasýný giriniz:");
	scanf("%d",&sorgu);
	time_t basla,bit;
 	time (&basla);
	itoa(sorgu,gecici_sorgu,10);
	while(!feof(rfp))
	{
		
		fscanf(rfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
		if(strcmp(oku.hesapno,gecici_sorgu)==0)
		{
			printf("\nSONUÇ\n------------\n\nHesap no : %s\n\nKiþinin\n------------\n Adý    : %s\n Soyadý : %s\n Bakiye : %d TL\n------------\n\n\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
			say++;
		}
	}
		if(say==0)
		{
			printf("Hesap bulunamadý.Ana menüye dönülüyor.<<<<");
			fclose(rfp);
			
			goto sona;
		}
	fclose(rfp);
	
	printf("\nYukarýda bulunan %s nolu hesap silinecek.Onaylýyor musunuz?[E/H] : ",gecici_sorgu);
	secimnoktasi:
	scanf("%s",onay_silme);
	if(strcmp(onay_silme,"e")==0||strcmp(onay_silme,"E")==0)
	{
		FILE *ofp=fopen("kayit.txt","r");
		FILE *nfp=fopen("gecici.txt","w");
		while(!feof(ofp))
		{	
			fscanf(ofp,"%s %s %s %d",oku.hesapno,oku.ad,oku.soyad,&oku.bakiye);
			if(strcmp(oku.hesapno,gecici_sorgu)==0)
			{
				continue;
			}
			if(feof(ofp))
			{
				
				break;
			}
			fprintf(nfp,"%s %s %s %d\n",oku.hesapno,oku.ad,oku.soyad,oku.bakiye);
		}
		printf("\n%s nolu hesap silindi.Ana menüye dönülüyor.<<<<",gecici_sorgu);
		time (&bit);
		printf ("\nÝþleminiz %.2lf saniye sürdü.\n", difftime (bit,basla));
		fclose(nfp);
		fclose(ofp);
		remove("kayit.txt");
		rename("gecici.txt","kayit.txt");

	}
	else if(strcmp(onay_silme,"h")==0||strcmp(onay_silme,"H")==0)
	{
		printf("\nVazgeçtiniz.Ana menüye dönülüyor<<<<");
		goto sona;
	}	
	else
	{
	printf("\nYanlýþ harfe bastýnýz.Lütfen [E/H] harflerinden birine basýnýz.\nSeçiminiz : ");
	goto secimnoktasi;
	}

		sona://goto deðiþkeni
		system("CLS");
}
int altihane()
{
	int alti_h;
	srand(time(NULL));
	alti_h=rand()%300000+10000;
	return alti_h;
}

