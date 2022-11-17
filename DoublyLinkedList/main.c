#include <stdio.h>
#include <stdlib.h>

struct n{
    int no;
    char ad[40];
    char soyad[40];
    char bolum[40];
    int sinif;
    struct n * next;
    struct n * prev;
};
typedef struct n node;

void bastir(node *r){
    node * iter = r;
    if(iter == NULL){
        printf("\n\nListe yok edilmistir.Herhangi bir ogrenci kaydi bulunamadi.\n\n");
    }
    while(iter != NULL){
        printf("No : %d  Ad : %s  Soyad : %s  Bolum : %s  Sinif : %d \n",iter->no,iter->ad,iter->soyad,iter->bolum,iter->sinif);
        iter = iter->next;
    }
}


node * createlinklist(node*r ,int n){
    if(n<=0){
        printf("Herhangi bir ogrenci kaydi girmediniz.");
        return r;
    }
    if(r == NULL){ //Daha once herhangi bir node olusturlmamýssa.
        r = (node *)malloc(sizeof(node));
        printf("NUMARA : ");
        scanf("%d",&(r->no));
        printf("AD : ");
        scanf("%s",r->ad);
        printf("SOYAD : ");
        scanf("%s",r->soyad);
        printf("BOLUM : ");
        scanf("%s",r->bolum);
        printf("SINIF : ");
        scanf("%d",&(r->sinif));
        r->next = NULL;
        r->prev = NULL;
        printf("\n");

    }
    node * iter = r;

    if(r != NULL){// Eklencek olan her node sona eklenecek.
            for(int i=1 ; i<n ; i++){
                node * temp = (node*)malloc(sizeof(node));
                printf("NUMARA : ");
                scanf("%d",&(temp->no));
                printf("AD : ");
                scanf("%s",temp->ad);
                printf("SOYAD : ");
                scanf("%s",temp->soyad);
                printf("BOLUM : ");
                scanf("%s",temp->bolum);
                printf("SINIF : ");
                scanf("%d",&temp->sinif);

                iter->next = temp;
                temp->prev = iter;
                temp->next = NULL;
                iter = iter->next;
                temp = NULL;
                printf("\n");
            }
    }
    return r;
}

node * destroylinklist(node *r){
    node *temp = r;
    while(temp != NULL){
        temp = temp->next;
        free(r);
        r = temp;
    }
    return r;
}

node * addNode(node *r){
    int secim;
    printf("Listenin basina eklemek istiyorsaniz '1' girin.\nListenin ortasina eklemek istiyorsaniz '2' girin.\nListenin sonuna eklemek isterseniz '3' girin.");
    scanf("%d",&secim);
    if(secim == 1){
        node * iter = r;
        node * temp = (node *)malloc(sizeof(node));

        printf("NUMARA : ");
        scanf("%d",&(temp->no));
        printf("AD : ");
        scanf("%s",temp->ad);
        printf("SOYAD : ");
        scanf("%s",temp->soyad);
        printf("BOLUM : ");
        scanf("%s",temp->bolum);
        printf("SINIF : ");
        scanf("%d",&(temp->sinif));

        iter->prev = temp;
        temp->next = iter;
        return temp;
    }
    if(secim == 2){
        node*iter = r;
        node * temp = (node *)malloc(sizeof(node));
        printf("Yerleþtirilecek sirayi girin : ");
        int sira ;
        scanf("%d",&sira);
        for(int i=0 ; i<(sira-2) ; i++){
            iter=iter->next;
        }

        printf("NUMARA : ");
        scanf("%d",&(temp->no));
        printf("AD : ");
        scanf("%s",temp->ad);
        printf("SOYAD : ");
        scanf("%s",temp->soyad);
        printf("BOLUM : ");
        scanf("%s",temp->bolum);
        printf("SINIF : ");
        scanf("%d",&(temp->sinif));

        temp->next = iter->next;
        iter->next->prev = temp;
        iter->next = temp;
        temp->prev = iter;
        return r;

    }
    if(secim == 3){
        node*iter = r;
        node*temp = (node *)malloc(sizeof(node));

        while(iter->next != NULL){
            iter = iter->next;
        }
        //node * temp = (node *)malloc(sizeof(node));

        printf("NUMARA : ");
        scanf("%d",&(temp->no));
        printf("AD : ");
        scanf("%s",temp->ad);
        printf("SOYAD : ");
        scanf("%s",temp->soyad);
        printf("BOLUM : ");
        scanf("%s",temp->bolum);
        printf("SINIF : ");
        scanf("%d",&(temp->sinif));

        iter->next =temp;
        temp->prev = iter;
        temp->next = NULL;
        return r;
    }

}

node * deleteNode(node * r,int ogrenciNo){
    node*temp;
    node*iter = r;
    if(r->no == ogrenciNo){
        temp=r;
        r = r->next;
        free(temp);
        return r;
    }
    while(iter->next!=NULL && iter->next->no != ogrenciNo){
        iter =iter->next;

    }
    if(iter -> next == NULL){
        printf("sililnecek eleman bulunamadi");
        return r;
    }
    temp=iter->next;
    iter->next =iter->next->next;
    free(temp);
    if(iter->next != NULL){
        iter->next->prev = iter;
    }
    return r;
}


void searchNote(node * r){
    printf("Hangi ogrenci no'yu sorgulamak istersiniz? Girin : ");
    int pno = scanf("%d",&pno);
    node * iter = r;
    int sayac;
    while(iter->next != NULL){
        if(iter->no == pno){
            printf("Ogrenci var.\n");
            sayac = 1;
            break;
        }
        else{
            sayac = 0;
        }
        iter = iter->next;
        }
        if(sayac == 0){
            printf("Ogrenci yok.\n");
        }
}


int displayList(node *r){
    node * iter = r;
    int sayac = 0;
    while(iter->next != NULL){
        sayac++;
        iter = iter->next;
    }
    printf("%d tane node vardir.\n\n", (sayac+1) );
    return (sayac+1);
}

void menu(){
    printf("MENU                 \n");
    printf("1-Listeyi bastirmak icin.\n");
    printf("2-Link listi yok etmek.\n");
    printf("3-Yeni ogrenci eklemek.\n");
    printf("4-Listeden ogrenci silmek\n");
    printf("5-Listede aradiginiz ogrenci var mi?\n");
    printf("6-Listede kac ogrenci var?\n");
    printf("Cikis icin 0 a basin.");
    printf("Lutfen seciminizi yapiniz : ");
}

void menugelismis(node * r){
    menu();
    int secim ;
    scanf("%d",&secim);

    while(secim !=0){
        scanf("%d",&secim);

        if(secim == 1){
            printf("\n\n");
            bastir(r);
            printf("\n\n");
        }

        if(secim == 2){
            printf("\n\nListe yok edilior...\n");
            r = destroylinklist(r);
            printf("Liste yok edildi.\n\n");
        }

        if(secim == 3){
            printf("\n\nYeni ogrenci ekleniyor..\n");
            r = addNode(r);
            printf("Ogrenci eklendi.\n\n");
        }

        if(secim == 4){
            printf("\n\nListeden ogrenci silinecektir...\n");
            printf("Silinmesini istediginiz ogrencinin numarasini girin. NO : ");
            int ogNo;
            scanf("%d",&ogNo);
            deleteNode(r,ogNo);
            printf("Ogrenci Silindi\n\n");
        }

        if(secim == 5){
            printf("\n\nOgrenci bulunacak...\n");
            searchNote(r);
            printf("Ogrenci bulundu.\n\n");
        }
        if(secim == 6){
            printf("\n\nListedeki ogrenci sayisi bulunuyor...\n");
            displayList(r);
            printf("Ogrenci sayisi bulundu.\n\n");
        }
        menu();
    }
}

int main()
{
    printf("*** DOUBLY LINK LIST ILE OGRENCI LISTESI OLUSTURMA PROGRAMI ****\n");
    printf("Baslangicta kac adet ogrenci olusturacaksiniz? Girin : ");

    node * root;
    root = NULL ;

    int ogAdet;
    scanf("%d",&ogAdet);
    root = createlinklist(root,ogAdet);
    menugelismis(root);

    printf("          !!!TESSEKKURLER!!!          ");

    return 0;
}
