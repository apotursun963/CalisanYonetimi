
#include "FuncHeader.h"

int		main(void) 
{
    int     Secim;

    printf("\n\t\t\t\t\t\t\t-------------------Calisan Yonetimi Programi-------------------\n\n");
    do 
    {
        printf("\n\t\t\t\t\t\t\t\t----------------------------------");
        printf("\n\t\t\t\t\t\t\t\t1. Calisan Ekle\n");
        printf("\n\t\t\t\t\t\t\t\t2. Calisan Sil\n");
        printf("\n\t\t\t\t\t\t\t\t3. Calisanlari Listele\n");
        printf("\n\t\t\t\t\t\t\t\t4. Calisan Ara\n");
        printf("\n\t\t\t\t\t\t\t\t5. Calisan Bilgilerini Guncelle\n");
        printf("\n\t\t\t\t\t\t\t\t6. Calisan Sayisi Goster\n");
        printf("\n\t\t\t\t\t\t\t\t7. Cikis\n");
        printf("\t\t\t\t\t\t\t\t----------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\tSecimini Yap: ");
        scanf("\n\t\t\t\t\t\t\t\t%d",&Secim);

        switch (Secim)
        {
            case 1:
                CalisanEkle();
                break;
            case 2:
                CalisanSil();
                break;
            case 3:
                CalisanListele();
                break;
            case 4:
                CalisanAra();
                break;
            case 5:
                CalisanGuncelle();
                break;
            case 6:
                CalisanSayisiGoster();
                break;
            case 7:
                printf("\n\t\t\t\t\t\t\t\tProgramdan Cikildi.");
                break;
            default:
                printf("\n\t\t\t\t\t\t\t\tGecerli Bir Islem Giriniz.\n");
        }
    } while (Secim != 7);
    
    return (0);
}



