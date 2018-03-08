#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void affiche_tab(int * tab,int n ){
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d, ",*(tab+i));
    }
    printf("\n");
}

void multi_tab(int * tab, int n){
    int i;
    for (i = 0; i < n; ++i)
    {
        *(tab+i) *=2;
    }
}

void divi_tab(int * tab, int n){
    int i;
    for (i = 0; i < n; ++i)
    {
        *(tab+i) /=2.0;
    }
}

int prod_tab(int * tab, int n){
    int i,reponse=1;
    for (i = 0; i < n; ++i)
    {
        reponse *= *(tab+i);
    }
    return reponse;
}

float moy_tab(int *tab, int n){
    int i;
    float somme=0;
    for (i = 0; i < n; ++i)
    {
        somme += *(tab+i);
    }
    return somme/n;
}

int mini_tab(int *tab, int n){
    int i,minimun = *tab;
    for (i = 1; i < n; ++i)
    {
        if (minimun > *(tab+i))
            minimun = *(tab+i);
    }
    return minimun;
}

int mini_tab_index(int *tab, int d,int n){
    int i,reponse = d, minimun = *(tab+d);
    for (i = d; i < n; ++i)
    {
        if (minimun > *(tab+i)){
            minimun = *(tab+i);
            reponse = i;
            }
    }
    return reponse;
}

void echange_val(int *tab, int n, int m){
    int temp = *(tab+n);
    *(tab+n) = *(tab+m);
    *(tab+m) = temp;
}

void tri_tab_croissant(int *tab,int n){
    int i, temp=mini_tab_index(tab,0,n);
    for (i = 0; i < n; ++i)
    {
        if( *(tab+temp) <= *(tab+i)){
            echange_val(tab,temp,i);
            temp= mini_tab_index(tab,i+1,n);
        }

    }
}

void tri_tab_decroissant(int *tab,int n){
    int i, temp=mini_tab_index(tab,0,n);
    for (i = 0; i < n; ++i)
    {
        if( *(tab+temp) <= *(tab+n-i)){
            n--;
            echange_val(tab,temp,n);
            temp= mini_tab_index(tab,i+1,n);
        }

    }
}

void reverse_tab(int *tab,int n){
    int i,j=n-1;
    for (i = 0; i < j; ++i)
    {
        echange_val(tab,i,j);
        j--;
    }
}

int check_char(char a, char b){
    if (a == b)
        return 1;
    return 0;
}

char copy_str(char *a, char *b){
    return 0;
}

void replace_char(char *a, int n){
    for (int i = 0; i < n; ++i)
    {
        if(*(a+i)=='e' || *(a+i)=='E')
            *(a+i)=' ';
    }
}

void extracte(char *ch1,int n,int d,char *ch2){
    int i;
    for (i = 0; i < n; ++i)
    {
        *(ch2+i) = *(ch1+d);
        d++;
    }
}

void del_char(char *ch1,int n){
    int i,j,k;
    for (i = 0; i < n; ++i)
    {
        if( (*(ch1+i) == 'e') || (*(ch1+i)=='E')){
            k=i;
            for (j = i+1; j < n; ++j)
            {
                *(ch1+k) = *(ch1+j);
                k++;
                i--;
            }
        }

    }
}

int count_word(char *tab,int taille,int i,int reponse){
    if(i == taille+1)
        return reponse;
    if( *(tab+i) ==' '){
        reponse++;
    }
    i++;
    return count_word( tab, taille, i, reponse);

}

int count_line(char *tab,int taille,int i,int reponse){
    if(i == taille+1)
        return reponse;
    if( *(tab+i) =='\n'){
        reponse++;
    }
    i++;
    return count_line( tab, taille, i, reponse);

}

int count_any(char *tab, int taille, int i,int reponse){
    if(i == taille+1)
        return reponse;
    if( tab[i] ==' '){
        if( (tab[i+1] >'A') && (tab[i+1]<'z'))
            reponse++;
    }
        
    i++;
    return count_any(tab, taille, i, reponse);
    }

/*         
typedef struct{
    int x1,x2;
    int y1,y2;
    }tvecteur;
*/


struct tvecteur {
    int x1,x2;
    int y1,y2;
};

// on utilise ceci > (struct tvecteur XXX)

void affiche_vec(struct tvecteur abc){
    printf("X1:%d, X2:%d,Y1:%d, Y2:%d,\n",abc.x1, abc.x2, abc.y1, abc.y2);
}


int test_vec_nul(struct tvecteur abc){
    if(!abc.x1 && !abc.x2 && !abc.y1 && !abc.y2)
        return 1;
    return 0;
}

struct tvecteur oppose_vec(struct tvecteur vec){
    struct tvecteur reponse={vec.x2, vec.x1, vec.y2, vec.y1};
    return reponse;
}

struct tvecteur somme_vec(struct tvecteur* vec1,struct tvecteur* vec2){
    struct tvecteur reponse;
    reponse.x1 = vec1->x1 + vec2->x1;
    reponse.x2 = vec1->x2 + vec2->x2;
    reponse.y1 = vec1->y1 + vec2->y1;
    reponse.y2 = vec1->y2 + vec2->y2;
    return reponse;
}

struct tvecteur prod_vec();

void testevecteurs(struct tvecteur xyz){
    printf("rien\n");
}

struct tfraction{
    int numerateur,denominateur;
};

void affiche_frac(struct tfraction *frac){
    printf("%d / %d\n",frac->numerateur,frac->denominateur );
}

float calcul(struct tfraction *frac, int virgule){
    float reponse = 0;
    float numerateur = frac->numerateur;
    float denominateur = frac->denominateur;
    for (int i = 0; i <= virgule; ++i)
    {
        while(numerateur >= denominateur){
            numerateur -= denominateur;
            reponse = reponse + pow(10.0,-i);
            }
            denominateur /=10;        
}   
    return reponse;
}

int mini_tab46(int * tab, int n){
    int i, indice=0;
    for (i = 1; i < n; ++i)
    {
        if (*(tab+indice) > *(tab+i))
            indice = i;
    }
    return *(tab+indice);
}

void tab_dynamique(){
    int taille;
    printf("cb de nombre? \n");
    //scanf("%d",&taille);
    taille=5;
    int *tableau = (int *)malloc(taille * sizeof(int));
    int* p;
    for (int i = 0; i < taille; ++i)
    {
        printf("la valeur?\n");
        //scanf("%d",&tableau[i]);
        tableau[i]=5;
    }

    for (int i = taille-1; i >=0 ; --i)
    {
        printf("%d\n", tableau[i]);
    }

    free(tableau);
}

void tab_2d(){
    int lignes=5,colonnes=10;
    int tableau[lignes][colonnes];
    int i = 0, j;
    for (; i < lignes; ++i)
    {
        for (j=0; j < colonnes ; ++j)
        {
            tableau[i][j] = j+i*10+1;
        }
    }


    for (i = 0; i < lignes; ++i)
    {
        for (j = 0; j < colonnes; ++j)
        {
            printf("%3.d, ",tableau[i][j]);
        }
        printf("\n");
    }

    }

int renverse(int argc, char const *argv[])
{   
    int i;
    for (i = 0; i < argc; ++i)
    {
        if(!argc-i)
        printf("%s ",argv[argc-i]);
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    int tab[10]={1,2, 8, 3, 0, 5, 4, 7, 2, 9};
    renverse();
    //tab_dynamique();
    /*
    printf("%d \n",mini_tab46(p,10));
    char m[13]="un deux trois";
    char z[35]="un\ndeux  trois \n quatre  cinq";
    char b[30]="un \n   \n deux trois";
    struct tvecteur abc;
    struct tvecteur xyz={1,2,3,4};
    struct tvecteur uvw={9,8,7,6};
    struct tvecteur nul={0,0,0,0};
    testevecteurs(xyz);
    abc = somme_vec(&xyz,&uvw);
    affiche_vec(abc);
    struct tfraction machin={3,1};
    affiche_frac(&machin);
    printf("%f\n",calcul(&machin,6) );
    */

    return 0;
}
// 8 28 1 7



