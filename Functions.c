
#include "FuncHeader.h"

struct  CalisanInfo
{   
    int     ID;
    char    Ad[20];
    char    SoyAd[20];
    int     Yas;
    double  Maas;
};

struct  CalisanInfo Calisanlar[100];

int     CalisanSayisi = 0;

void    CalisanEkle(void)
{
    if (CalisanSayisi <= 100) 
    {
        struct CalisanInfo Calisan;

        printf("\n\t\t\t\t\t\t\t\t----------Calisan Ekleme----------\n");

        printf("\n\t\t\t\t\t\t\t\tID: ");
        scanf("%d",&Calisan.ID);

        printf("\n\t\t\t\t\t\t\t\tAd: ");
        scanf("%s",&Calisan.Ad);

        printf("\n\t\t\t\t\t\t\t\tSoyAd: ");
        scanf("%s",&Calisan.SoyAd);
       
        printf("\n\t\t\t\t\t\t\t\tYas: ");
        scanf("%d",&Calisan.Yas);

        printf("\n\t\t\t\t\t\t\t\tMaas: ");
        scanf("%lf",&Calisan.Maas);

        Calisanlar[CalisanSayisi] = Calisan;
        CalisanSayisi++;

        printf("\n\t\t\t\t\t\t\t\t%s Adinda Bir Calisan Basariyla Eklendi.\n",Calisan.Ad);
    }
    else 
        printf("\n\t\t\t\t\t\t\t\tMaximum Calisan Sayisina Ulasildi.");
}

void    CalisanSil(void)
{
    char    isim[20];
    int     i;

    printf("\n\t\t\t\t\t\t\t\t----------Calisan Silme----------\n");
    printf("\n\t\t\t\t\t\t\t\tsilinecek Calisanin Ismini Girin: ");
    scanf("\n\t\t\t\t\t\t\t\t%s",&isim);

    for (i = 0; i < CalisanSayisi; i++) 
    {
        if (strcmpi(Calisanlar[i].Ad, isim) == 0) 
        {
            for (i; i < CalisanSayisi - 1; i++) 
            Calisanlar[i] = Calisanlar[i + 1];
        CalisanSayisi--;
        printf("\n\t\t\t\t\t\t\t\tCalisan Silindi\n");
        break;
        }
    }  
    if (strcmpi(Calisanlar[i].Ad, isim) != 0)
        printf("\n\t\t\t\t\t\t\t\tBelirtilen Ism'e Sahip Bir Calisan Bulunamadi.\n");
}

void    CalisanListele(void) 
{
    FILE *dosya = fopen("Calisan Yonetimi.txt","w");

    if (dosya == NULL)
        fprintf(stderr, "Dosya Acma Hatasi.\n");

    printf("\n\t\t\t\t\t\t\t\t----------Calisanlari Listeleme----------\n");
    fprintf(dosya,"\n----------Calisanlari Listeleme----------\n");

    if (CalisanSayisi == 0) 
    {
        printf("\n\t\t\t\t\t\t\t\tListelenecek Bir Calisan Yok.\n");
        fprintf(dosya,"Listelenecek Bir Calisan Yok.\n");
    }
    else 
    {
        for (int i=0; i < CalisanSayisi; i++) 
        {
            printf("\n\t\t\t\t\t\t\t\t%d-%s %s\n",i+1,Calisanlar[i].Ad,Calisanlar[i].SoyAd);
            fprintf(dosya,"%d. %s %s\n",i+1,Calisanlar[i].Ad,Calisanlar[i].SoyAd);
        }
    }   
    fclose(dosya);
}

void    CalisanAra(void) 
{
    char    isim[20];
    int     i;

    printf("\n\t\t\t\t\t\t\t\t----------Calisan Arama----------\n");
    printf("\n\t\t\t\t\t\t\t\tHangi Calisanin Bilgilerini Aramak Istiyorsun: ");
    scanf("\n\t\t\t\t\t\t\t\t%s",&isim);

    for (i=0; i < CalisanSayisi; i++) 
    {
        if (strcmpi(Calisanlar[i].Ad, isim) == 0) 
        {
            printf("\n\t\t\t\t\t\t\t\tID: %d || Ad: %s || SoyAd: %s || Yas: %d || Maas: %.2lf $\n",
            Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            break;
        }
    }
    if (strcmpi(Calisanlar[i].Ad, isim) != 0)
        printf("\n\t\t\t\t\t\t\t\tSistemde %s Adinda Bir Calisan Kayitli Degil.\n",isim);
}

void    CalisanGuncelle(void) 
{
    char    isim[20];
    char    sec[10];
    int     i;
    
    printf("\n\t\t\t\t\t\t\t\t----------Calisan Bilgilerini Guncelleme----------\n");
    printf("\n\t\t\t\t\t\t\t\tGuncellenecek Calisanin Adini Girin: ");
    scanf("\n\t\t\t\t\t\t\t\t%s", &isim);

    for (i=0; i < CalisanSayisi; i++) 
    {
        if (strcmpi(Calisanlar[i].Ad,isim) == 0) 
        {
            printf("\n\t\t\t\t\t\t\t\tCalisanin Hangi Bilgilerini Guncellemek Istiyorsunusz\n");
            printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
            Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            printf("\n\t\t\t\t\t\t\t\tGuncelle: ");
            scanf("\n\t\t\t\t\t\t\t\t%s",&sec);

            if (strcmpi(sec,"ID") == 0) 
            {
                printf("\n\t\t\t\t\t\t\t\tID: ");
                scanf("\n\t\t\t\t\t\t\t\t%d",&Calisanlar[i].ID);
                printf("\n\t\t\t\t\t\t\t\tGuncellenmis Bilgiler:\n");
                printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
                Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            }
            else if (strcmpi(sec,"Ad") == 0) 
            {
                printf("\n\t\t\t\t\t\t\t\tAd: ");
                scanf("\n\t\t\t\t\t\t\t\t%s",&Calisanlar[i].Ad);
                printf("\n\t\t\t\t\t\t\t\tGuncellenmis Bilgiler:\n");
                printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
                Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            }
            else if (strcmpi(sec,"SoyAd") == 0) 
            {
                printf("\n\t\t\t\t\t\t\t\tSoyAd: ");
                scanf("\n\t\t\t\t\t\t\t\t%s",&Calisanlar[i].SoyAd);
                printf("\n\t\t\t\t\t\t\t\tGuncellenmis Bilgiler:\n");
                printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
                Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            }
            else if (strcmpi(sec,"Yas") == 0) 
            {
                printf("\n\t\t\t\t\t\t\t\tYas: ");
                scanf("\n\t\t\t\t\t\t\t\t%d",&Calisanlar[i].Yas);
                printf("\n\t\t\t\t\t\t\t\tGuncellenmis Bilgiler:\n");
                printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
                Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            }
            else if (strcmpi(sec,"Maas") == 0) 
            {
                printf("\n\t\t\t\t\t\t\t\tMaas: ");
                scanf("\n\t\t\t\t\t\t\t\t%.2lf",&Calisanlar[i].Maas);
                printf("\n\t\t\t\t\t\t\t\tGuncellenmis Bilgiler:\n");
                printf("\n\t\t\t\t\t\t\t\tID: %d | Ad: %s | SoyAd: %s | Yas: %d | Maas: %.2lf $\n",
                Calisanlar[i].ID,Calisanlar[i].Ad,Calisanlar[i].SoyAd,Calisanlar[i].Yas,Calisanlar[i].Maas);
            }
            else
                printf("\n\t\t\t\t\t\t\t\tYanlis Deger Girdiniz.");
            break;
        }
    }
    if (strcmpi(Calisanlar[i].Ad,isim) != 0) 
        printf("\n\t\t\t\t\t\t\t\tBoyle Bir Calisan Kayitli Degil.\n");
}

void    CalisanSayisiGoster(void) 
{
    printf("\n\t\t\t\t\t\t\t\t----------Calisan Sayisi----------\n");
    if (CalisanSayisi == 0) 
        printf("\n\t\t\t\t\t\t\t\tHic Calisan Kaydedilmedi: %d\n",CalisanSayisi);
    else 
        printf("\n\t\t\t\t\t\t\t\tGuncel Calisan Sayisi: %d\n",CalisanSayisi);
}