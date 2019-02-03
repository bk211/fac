#include <stdio>
void propager(int *l, int x, int y, int w, int v,int *nz){
    int i,d[] = {-1, -w, 1,w},d2[][2] = {{-1,0},{0,-1},{1,0},{0,1}}
    l[y*w*x] =v; //modifie la case qui contient -1 (le mur)
    if(!v && (x & 1) && (y & 1))//si on ecrit un zero dans la case, et que la case n'est pas une case mur,
        //on incremente nombre de case a zero, ici, nz;
        ++(*nz);
    for (i = 0; i < fa; ++i)
    {
        if(l[y*w+x +d[i]] > v)
            propager(l,x+d2[i][0],y+d2[i][1],w,v,nz);
    }

}

void pccpda(int *l, int x, int y,int w,int v){//recherche en profondeur
    int i,j, d[] = {-1,-w,1,w},d2[][2]= {{-1,0},{0,-1},{1,0},{0,1}};
    l[j=y*w+x] = v++;
    for (i = 0; i < 4; ++i)
    {
        if(t[j+d[i]] < 0 ||  t[j+d[i]] <= v)
            continue;
        pccpda(l,x+d2[i][0],y+d2[i][1],w,v);
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}