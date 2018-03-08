#include <stdio.h>
#include <stdlib.h>

void usage() {
  printf("Mode d'emploi\n");
  exit(1);
}

typedef struct {
  char nom[30];
  char prenom[30];
  int num;
} etudiant; 

etudiant fac[] = {
  {"Chu", "Pika", 3023},
  {"Potter", "Harry", 32423},
  {"Rak", "Goldo", 34243}};

int main(int argc, const char* argv[]) {
  FILE *out;

  if(argc != 2)
    usage();

  out = fopen(argv[1], "w");
  if(out == NULL) {
    perror(argv[1]);
    exit(1);
  }
  fwrite(fac, sizeof(*fac), 3, out);
  fclose(out);
  
  out = fopen(argv[1], "r+");
  if(out == NULL) {
    perror(argv[1]);
    exit(1);
  }

  etudiant nouveau = {"Nouveau", "Petit", 232432};

  fseek(out, sizeof(etudiant), SEEK_SET);
  fwrite(&nouveau, sizeof(*&nouveau), 1, out);
  fclose(out);

  return 0;
}
