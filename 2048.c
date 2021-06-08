#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void menu(char *l);
void nowyelement(int plan[4][4]);
void ruchprawo(int plan[4][4], int *wynik);
void ruchdol(int plan[4][4], int *wynik);
void ruchlewo(int plan[4][4], int *wynik);
void ruchgora(int plan[4][4], int *wynik);
void pokaz(int plan[4][4], int wynik, int highscore);
int sprawdzruch(int plan[4][4], int plan2[4][4]);
int sprawdzkoniec(int plan[4][4]);
void wpiszruch(int plan[4][4], int plan2[4][4]);
void zapisz(int plan[4][4], int wynik);
void wczytaj(int plan[4][4], int *wynik);
void najw(int *highscore, int wynik);
int main()
{
    srand(time(NULL));
    int i, j, wynik=0, g=0, k=0, highscore, a=4, b=4;
    char x;
    char l;
    int plan[a][b];
    int plan2[a][b];
    menu(&l);
    if(l=='o')
    {
        for (i=0; i<a; i++)
            for (j=0; j<b; j++)
            {
                plan[i][j]=0;
                plan2[i][j]=0;
            }
    }
    else if(l=='v')
        wczytaj(plan, &wynik);
    while(x!='i')
    {
        system("cls");
        najw(&highscore, wynik);
        nowyelement(plan);
        k = sprawdzkoniec(plan);
        if(k==0)
        {
            wpiszruch(plan, plan2);
            pokaz(plan, wynik, highscore);
            while(g!=1)
            {
                scanf(" %c", &x);
                if(x=='a')
                    ruchlewo(plan, &wynik);
                else if (x=='d')
                    ruchprawo(plan, &wynik);
                else if(x=='s')
                    ruchdol(plan, &wynik);
                else if(x=='w')
                    ruchgora(plan, &wynik);
                else if(x=='i')
                {
                    zapisz(plan, wynik);
                    break;
                }
            g = sprawdzruch(plan, plan2);
            }
            g=0;
        }
        else if (k==1)
        {
            printf("KONIEC\n");
            break;
        }
        else if(k==2)
        {
            printf("WYGRANA\n");
            break;
        }
    }
    return 0;
}

void nowyelement(int plan[4][4])
{
    int i,j, b=0, w;
    while(b!=1)
    {
        i = rand() %4;
        j = rand() %4;
        w = rand() %10;
        if(plan[i][j]==0)
        {
            if(w==9)
                plan[i][j]=4;
            else
                plan[i][j]=2;
            b=1;
        }
    }

}

void ruchlewo(int plan[4][4], int *wynik)
{
    int i, j, n=0;
    int tmp[4]= {0,0,0,0};
    for (i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(plan[i][j]!=0)
            {
                tmp[n]=plan[i][j];
                if(tmp[n-1]==tmp[n] && n>=1)
                {
                    tmp[n-1] *= 2;
                    tmp[n]=0;
                    *wynik += tmp[n-1];
                }
                else
                    n += 1;
            }
        }
        n=0;
        for(j=0; j<4; j++)
        {
            plan[i][j]=tmp[j];
            tmp[j]=0;
        }
    }
}

void ruchprawo(int plan[4][4], int *wynik)
{
    int i, j, n=3;
    int tmp[4]= {0,0,0,0};
    for (i=0; i<4; i++)
    {
        for(j=3; j>=0; j--)
        {
            if(plan[i][j]!=0)
            {
                tmp[n]=plan[i][j];
                if(tmp[n+1]==tmp[n] && n<3)
                {
                    tmp[n+1] *= 2;
                    tmp[n]=0;
                    *wynik += tmp[n+1];
                }
                else
                    n -= 1;
            }
        }
        n=3;
        for(j=3; j>=0; j--)
        {
            plan[i][j]=tmp[j];
            tmp[j]=0;
        }
    }
}
void ruchdol(int plan[4][4], int *wynik)
{
    int i, j, n=3;
    int tmp[4]= {0,0,0,0};
    for (j=0; j<4; j++)
    {
        for(i=3; i>=0; i--)
        {
            if(plan[i][j]!=0)
            {
                tmp[n]=plan[i][j];
                if(tmp[n+1]==tmp[n] && n<3)
                {
                    tmp[n+1] *= 2;
                    tmp[n]=0;
                    *wynik += tmp[n+1];
                }
                else
                    n -= 1;
            }
        }
        n=3;
        for(i=3; i>=0; i--)
        {
            plan[i][j]=tmp[i];
            tmp[i]=0;
        }

    }
}
void ruchgora(int plan[4][4], int *wynik)
{
    int i, j, n=0;
    int tmp[4]= {0,0,0,0};
    for (j=0; j<4; j++)
    {
        for(i=0; i<4; i++)
        {
            if(plan[i][j]!=0)
            {
                tmp[n]=plan[i][j];
                if(tmp[n-1]==tmp[n] && n>=1)
                {
                    tmp[n-1] *= 2;
                    tmp[n]=0;
                    *wynik += tmp[n-1];
                }
                else
                    n += 1;
            }
        }
        n=0;
        for(i=0; i<4; i++)
        {
            plan[i][j]=tmp[i];
            tmp[i]=0;
        }
    }
}
void pokaz(int plan[4][4], int wynik, int highscore)
{
    int i, j;
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
            printf("%-5d", plan[i][j]);
        printf("\n\n\n");
    }
    printf("wynik: %d\n", wynik);
    printf("najwyzszy wynik: %d\n", highscore);
    printf("i - zakoncz i zapisz gre");

}
void wpiszruch(int plan[4][4], int plan2[4][4])
{
    int i, j;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            plan2[i][j]=plan[i][j];
}
int sprawdzruch(int plan[4][4], int plan2[4][4])
{
    int i, j, b=0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            if(plan2[i][j]!=plan[i][j])
            {
                b=1;
                break;
            }
    return b;
}
int sprawdzkoniec(int plan[4][4])
{
    int i, j;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            if(plan[i][j]==0)
                return 0;
    for (i=0; i<4; i++)
        for (j=0; j<3; j++)
            if(plan[i][j]==plan[i][j+1])
                return 0;
    for (i=0; i<3; i++)
        for (j=0; j<4; j++)
            if(plan[i][j]==plan[i+1][j])
                return 0;
    for (i=0; i<3; i++)
        for (j=0; j<4; j++)
            if(plan[i][j]==2048)
                return 2;
    return 1;
}
void zapisz(int plan[4][4], int wynik)
{
    int i, j;
    FILE *plik;
    FILE *punkty;
    plik = fopen("zapis.txt", "w");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            fprintf(plik,"%d ",plan[i][j]);
        }
    fprintf(plik,"\n");
    }
    fclose(plik);
    punkty = fopen("punkty.txt", "w");
    fprintf(punkty, "%d", wynik);
    fclose(punkty);
}
void wczytaj(int plan[4][4], int *wynik)
{
    int i, j;
    FILE *plik;
    FILE *punkty;
    plik = fopen("zapis.txt", "r");
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            fscanf(plik,"%d", &plan[i][j]);
    fclose(plik);
    punkty = fopen("punkty.txt", "r");
    fscanf(punkty, "%d", wynik);
    fclose(punkty);
}
void najw(int *highscore, int wynik)
{
    FILE *high;
    high = fopen("high.txt", "r");
    fscanf(high,"%d", highscore);
    fclose(high);
    if(wynik> (*highscore))
    {
        high = fopen("high.txt", "w");
        fprintf(high,"%d",wynik);
        *highscore = wynik;
    }
}
void menu(char *l)
{
    char x;
    printf("2048 by Witok\n");
    printf("Instrukcja obslugi:\n");
    printf("w - ruch planszy w gore, s -ruch planszy w dol\na - ruch planszy w lewo, d - ruch planszy w prawo\n");
    printf("Wcisnij \"o\" zeby rozpoczac nowa gre lub \"i\" zeby wyjsc\n");
    printf("\"v\" zeby wczytac poprzedni zapis");
    scanf( "%c", &x);
    if(x=='o')
        *l='o';
    else if(x=='v')
        *l='v';
    else if(x=='i')
        exit(0);
}