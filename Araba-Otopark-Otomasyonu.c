#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arabalar {
    int numara ;
    char marka[20] , model [20], renk[20];
    int ucret, durum;
} araba  ;



void arabaEkle( )
{
    system("cls");
    printf("--ARABA EKLEME--\n\n") ;
    araba a1;
    int numara=0;
    
    FILE * numPtr = fopen("arabaNumaralari.dat", "a+b") ;
    while( fread ( &numara, sizeof(int), 1, numPtr  ) != NULL  )
    {
    }
    numara++;
    fwrite ( &numara, sizeof(int), 1, numPtr  ) ;
    fclose(numPtr)  ;
    
    a1.numara= numara;
    printf("Marka        : ") ; scanf(" %[^\n]s", a1.marka ) ;
    printf("Model (Yil)  : ") ; scanf(" %[^\n]s", a1.model ) ;
    printf("Renk         : ") ; scanf(" %[^\n]s", a1.renk ) ;
    printf("Ucret        : ") ; scanf(" %d", &a1.ucret ) ;
    a1.durum= 0;
    
    FILE *ptr= fopen("arabalar.dat", "a+b")     ;
    fwrite ( &a1, sizeof(araba ), 1, ptr  ) ;
    fclose(ptr)  ;
    printf("Araba kaydi tamamlandi! \n\n") ;
    
}

void arabaListele( )
{
    system("cls");
    printf("--ARABA LİSTELEME-- \n\n") ;
    araba a1;
    
    FILE *ptr= fopen("arabalar.dat", "r+b")     ;
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "NUMARA", "MARKA", "MODEL-YIL", "UCRET(TL)", "RENK ", "DURUMU"  ) ;
    
    while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
    {
        printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
    }
    fclose(ptr)  ;
    
}

void arabaGuncelle (  )
{
    system("cls");
    printf("--ARABA GUNCELLEME--\n\n") ;
    araba a1;
    int sonuc=0, numara, sayac=0 ;
         
    
    FILE *ptr= fopen("arabalar.dat", "r+b")     ;
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "NUMARA", "MARKA", "MODEL-YIL", "UCRET(TL)", "RENK ", "DURUMU"  ) ;
    
    while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
    {
        printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk ,a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
        if( a1.durum != 1 )
        sonuc=1;
    }
         
    
    if( sonuc==0)
    printf("Otoparkta mevcut arac yoktur!\n\n") ;
    else
    {
        rewind(ptr) ;
        sonuc=0;
        printf("Numara : "); scanf("%d", &numara);
                
        while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
        {
            if( a1.numara== numara )
            {
                system("cls") ;
                printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
                sonuc=1;
                break;
            }
            
            sayac++;
        }
        
        if( sonuc==0)
        printf("%d numarali arac kaydi bulunamadi! \n", numara  );
        else
        {
        rewind(ptr)         ;
        printf("Marka        : ") ; scanf(" %[^\n]s", a1.marka ) ;
        printf("Model (Yil)  : ") ; scanf(" %[^\n]s", a1.model ) ;
        printf("Renk         : ") ; scanf(" %[^\n]s", a1.renk ) ;
        printf("Ucret        : ") ; scanf(" %d", &a1.ucret ) ;
        
        fseek ( ptr, (sayac) * sizeof(araba ), 0 ) ;
        fwrite ( &a1, sizeof(araba ), 1, ptr  ) ;
        printf("Araba Guncelleme islemi tamamlandi! \n\n") ;
        }
        
    }
    
    fclose(ptr)  ;
    
}

void kullaniciParolaBelirle(char parola[5])
{
    int i;

    do
    {
        printf("Parolayı belirle (4 karakter): ");
        scanf(" %[^\n]s", parola);

        if (strlen(parola) != 4)
        {
            printf("Parola 4 karakterli olmalidir!\n");
        }
        for (i = 0; i < 4; i++)
        {
            for (; parola[i] < '0' || parola[i] > '9';)
            {
                printf("Parola sadece rakamlardan olusmalidir!\n");
                break;
            }
        }
    } while (strlen(parola) != 4 || i < 4);
}

void arabaSil ( )
{
    system("cls");
    printf("--ARABA SİLME--\n\n") ;
    araba a1;
    int sonuc=0, numara, sayac=0 ;
         
    
    FILE *ptr= fopen("arabalar.dat", "r+b")     ;
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "NUMARA", "MARKA", "MODEL-YIL", "UCRET(TL)", "RENK ", "DURUMU"  ) ;
    
    while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
    {
        printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
        sonuc=1;
    }
         
    
    if( sonuc==0)
    printf("Otoparkta mevcut arac yok!\n\n") ;
    else
    {
        rewind(ptr) ;
        sonuc=0;
        printf("Numara : "); scanf("%d", &numara);
                
        while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
        {
            if( a1.numara== numara )
            {
                system("cls") ;
                printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk, a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
                sonuc=1;
                break;
            }
            
            sayac++;
        }
        
        if( sonuc==0)
        printf("%d numarali arac kaydi bulunamadi! \n", numara  );
        else
        {
        rewind(ptr)         ;
        FILE *yPtr = fopen("yedek.dat", "w+b") ;
        
        while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
        {
            if( a1.numara != numara )
            {
                system("cls") ;
                printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret,a1.renk,a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
                sonuc=1;
                fwrite ( &a1, sizeof(araba ), 1, yPtr  ) ;
            }
             
        }
        
        fclose(ptr);
        fclose(yPtr) ;
        
        remove("arabalar.dat") ;
        rename( "yedek.dat", "arabalar.dat" ) ;
                
        printf("Araba Silme islemi tamamlandi!\n\n") ;
        }
        
    }
    
    fclose(ptr)  ;
    
    
}
void arabaCikis ( )
{
    system("cls");
    printf("--ARABA CİKİS-- \n\n") ;
    araba a1;
    int sonuc=0, numara, sayac=0 ;
         
    
    FILE *ptr= fopen("arabalar.dat", "r+b")     ;
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "NUMARA", "MARKA", "MODEL-YIL", "UCRET(TL)", "RENK ", "DURUMU"  ) ;
    
    while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
    {
        printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
        if( a1.durum != 1 )
        sonuc=1;
    }
         
    
    if( sonuc==0)
    printf("Otoparkta mevcut arac yok !\n\n") ;
    else
    {
        rewind(ptr) ;
        sonuc=0;
        printf("Numara : "); scanf("%d", &numara);
                
        while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
        {
            if( a1.numara== numara )
            {
                system("cls") ;
                printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
                sonuc=1;
                break;
            }
            
            sayac++;
        }
        
        if( sonuc==0)
        printf("%d numarali arac kaydi bulunamadi! \n", numara  );
        else
        {
            
        rewind(ptr)         ;
        a1.durum=1;
        fseek ( ptr, (sayac) * sizeof(araba ), 0 ) ;
        fwrite ( &a1, sizeof(araba ), 1, ptr  ) ;
        printf("Araba cikis islemi tamamlandi \n\n") ;
        }
        
    }
    
    fclose(ptr)  ;
    
}

void arabaBul ( )
{
    
    system("cls");
    printf("--ARABA BULMA-- \n\n") ;
    araba a1;
    int sonuc=0, numara, sayac=0 ;
         
    
    FILE *ptr= fopen("arabalar.dat", "r+b")     ;
    printf("%-10s%-20s%-20s%-20s%-20s%-20s\n", "NUMARA", "MARKA", "MODEL-YIL", "UCRET(TL)", "RENK ", "DURUMU"  ) ;
    
    while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
    {
        printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
        if( a1.durum != 1 )
        sonuc=1;
    }
         
    
    if( sonuc==0)
    printf("Otoparkta mevcut arac yok !\n\n") ;
    else
    {
        rewind(ptr) ;
        sonuc=0;
        printf("Numara : "); scanf("%d", &numara);
                
        while( fread  ( &a1, sizeof(araba ), 1, ptr  )  !=NULL  )
        {
            if( a1.numara== numara )
            {
                system("cls") ;
                printf("%-10d%-20s%-20s%-20d%-20s%-20s \n", a1.numara, a1.marka, a1.model, a1.ucret, a1.renk,  a1.durum==0 ? "OTOPARKTA" : "CİKTİ" ) ;
                sonuc=1;
                break;
            }
            
            sayac++;
        }
        
        if( sonuc==0)
        printf("%d numarali arac kaydi bulunamadi \n", numara  );
        else
        {
            system("cls") ;
            
        printf("Numara       : %d \n : ", a1.numara ) ;
        printf("Marka        : %s \n : ", a1.marka ) ;
        printf("Model (Yil)  : %s \n : ", a1.model ) ;
        printf("Renk         : %s \n : ", a1.renk ) ;
        printf("Ucret (TL)   : %d \n : ", a1.ucret ) ;
        printf("Durumu       : %d \n : ", a1.durum ) ;
        
             
        }
        
    }
    
    fclose(ptr)  ;
    
    
    
    
    
}



int yetkiliMenu()
{
    int secim;
    
    printf("\n\n--YAPABILECEGINIZ ISLEMLER--\n\n") ;
    
    printf(" 1- Araba ekle \n");
    printf(" 2- Araba Guncelle \n");
    printf(" 3- Araba Sil  \n");
    printf(" 4- Araba Cikis \n");
    printf(" 5- Araba Listele \n");
    printf(" 6- Araba Bul  \n");
    printf("0- Cikis Yap  \n");
    printf("Seciminiz : ") ; scanf("%d", &secim);
    system("cls");
    return secim;
}





void yetkiliGiris()
{
    int secim= yetkiliMenu();
    while( secim != 0 )
    {
        switch(secim )
        {
            case 1: arabaEkle() ; break;
            case 2: arabaGuncelle () ; break;
            case 3: arabaSil ( ) ; break;
            case 4: arabaCikis() ; break;
            case 5: arabaListele() ; break;
            case 6: arabaBul() ; break;
            case 0: break;
            default: printf("Hatali secim ! \n") ; break;
        }
        secim= yetkiliMenu();
    }
    printf("Cikis Yapildi .... ") ;
}


void girisYap()
{
   system("cls");
    char kullaniciAdi[20], belirlenenParola[5], girilenParola[5];

    printf("Giris Ekrani ... \n\n");
    printf("Kullanici Adi : ");
    scanf(" %[^\n]s", kullaniciAdi);

    // Kullanıcıdan belirlenen parolayı almak için ayrı bir fonksiyon çağır
    kullaniciParolaBelirle(belirlenenParola);

    // Kullanıcıdan parolayı almak
    do
    {
        printf("Parola (4 karakter): ");
        scanf(" %[^\n]s", girilenParola);

        if (strlen(girilenParola) != 4 || strcmp(belirlenenParola, girilenParola) != 0)
        {
            printf("Hatali parola! Lutfen tekrar deneyin.\n");
        }
    } while (strlen(girilenParola) != 4 || strcmp(belirlenenParola, girilenParola) != 0);

    // Kullanıcı adı ve parola kontrolü
    if (strcmp(kullaniciAdi, "admin") == 0)
    {
        printf("Giris basarili! \n");
        yetkiliGiris();
    }
    else
        printf("Hatali kullanici adi veya parola! \n");
}


int menu()
{
    int secim;
    printf("\n\n--YAPABILECEGINIZ ISLEMLER--\n\n") ;
    printf("1- Giris Yap \n");
    printf("0- Programi Kapat \n");
    printf("Seciminiz : ") ; scanf("%d", &secim);
    system("cls");
    return secim;
}


int main()
{
    int secim= menu();
    while( secim != 0 )
    {
        switch(secim )
        {
            case 1: girisYap(); break;
            case 0: break;
            default: printf("Hatali secim! \n") ; break;
        }
        secim= menu();
    }
    printf("Program kapatiliyor.... ") ;
    
    
    
    return 0;
}
