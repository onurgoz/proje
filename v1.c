#include <stdio.h>
#include <stdlib.h>
void YeniMusteriEkleme();
void HesapAcma();
void ParaCekme();
void ParaYatirma();
void HesabaHavale();
void BankaGelirGiderRaporu();
void HesapOzeti();
void HesapKapatma();
int main()
{
	int secim,secim1;
	printf("   Banka otomasyonuna hosgeldiniz.   \n");
	printf("*************************************\n");
	printf("Lutfen islem seciniz\n 1-Hesap Yeni Musteri Kaydı Olusturma\n 2-Hesap Acma\n 3-Para Cekme\n 4-Para Yatirma\n 5-Hesaba Havale\n 6-Banka Gelir-Gider Raporu\n 7-Hesap Ozeti\n 8-Hesap Kapatma\n");
	scanf("%d",&secim);			//seçim işlermi burada yapılacak
	switch(secim)
	{
		case 1:
		printf("Hesabınızı bireysel acmak için(1)\nticari acmak icin(2)\n");
		scanf("%d",&secim1);
		

	}
}

void YeniMusteriEkleme()
{
	FILE *fp;
	fp=fopen("MusteriBilgileri.txt","r");
	char KullaniciAdi;
	int sifre;


}
void HesapAcma()
{

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