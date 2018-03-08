#include <stdio.h>
struct distance
{
    int feet;
    float inch;
};
void add(struct distance d1,struct distance d2, struct distance *d3); 

int main()
{
    struct distance dist1, dist2, dist3;

    printf("First distance\n");
    printf("Enter feet: ");
//    scanf("%d", &dist1.feet);
    dist1.feet=2;
    printf("Enter inch: ");
//    scanf("%f", &dist1.inch);
    dist1.inch=3;
    printf("Second distance\n");
    printf("Enter feet: ");
//    scanf("%d", &dist2.feet);
    dist2.feet=6;
    printf("Enter inch: ");
//    scanf("%f", &dist2.inch);
    dist2.feet=5;
    add(dist1, dist2, &dist3); 

//passing structure variables dist1 and dist2 by value whereas passing structure variable dist3 by reference
    printf("\nSum of distances = %d\'-%.1f\"", dist3.feet, dist3.inch);

    return 0;
}
void add(struct distance d1,struct distance d2, struct distance *d3) 
{
     //Adding distances d1 and d2 and storing it in d3
     d3->feet = d1.feet + d2.feet;
     d3->inch = d1.inch + d2.inch;

     if (d3->inch >= 12) {     /* if inch is greater or equal to 12, converting it to feet. */
         d3->inch -= 12;
         ++d3->feet;
    }
}