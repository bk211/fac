struct fraction
{
    int num,deno;
};
typedef struct franction fraction;

void affichefrac(fraction f){
    printf("%d / %d\n",f.num, f.deno );
}

fraction inverse(fraction f){
    fraction z;
    z.num=f.demo;
    z.demo=f.num;
    return z;
}