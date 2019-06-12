/*!\file window.c
 * \brief géométries lumière diffuse et transformations de base en GL4Dummies
 * \author Farès BELHADJ, amsi@ai.univ-paris8.fr
 * \date April 15 2016 */
#include <stdio.h>
#include <GL4D/gl4dp.h>
#include <GL4D/gl4du.h>
#include <GL4D/gl4dh.h>
#include <GL4D/gl4df.h>
#include <GL4D/gl4duw_SDL2.h>
#include <audioHelper.h>
#include <SDL_ttf.h>
#include <assert.h>
#include <time.h>
/* Prototypes des fonctions statiques contenues dans ce fichier C */
static void init(void);
static void draw(void);
/*!\brief identifiant du programme GLSL */
static GLuint _pId = 0;
/*!\brief quelques objets géométriques */
static GLuint _quad = 0;
static float Centerx= 0;
static float Centery= 0;
static int largeur,hauteur;
static float echelle =3;
static float consty = -0.75;
static float constx = -0.9815648;

/*!\brief initialise les paramètres OpenGL et les données */
static void init(void) {
  _pId  = gl4duCreateProgram("<vs>shaders/mendelbrot.vs", "<fs>shaders/julia.fs", NULL);
  _quad = gl4dgGenQuadf();

}


/*!\brief dessine dans le contexte OpenGL actif. */
static void draw(void) {

  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);
  largeur = vp[2];
  hauteur = vp[3];
  glClear(GL_COLOR_BUFFER_BIT);

  constx +=0.001;
  consty +=0.001;
  int z = rand()%3-1;
  if (constx* constx + consty *consty >1){
        if (constx> 0.75)
            constx = -0.75;
        if (consty >0.75)
            consty = 0.-75;
  }


printf("%f %f\n",constx,consty );
  glUseProgram(_pId);
  glUniform1f(glGetUniformLocation(_pId, "Centerx"), Centerx);
  glUniform1f(glGetUniformLocation(_pId, "Centery"), Centery);
  glUniform1i(glGetUniformLocation(_pId, "largeur"), largeur);
  glUniform1i(glGetUniformLocation(_pId, "hauteur"), hauteur);
  glUniform1f(glGetUniformLocation(_pId, "echelle"), echelle);
  glUniform1i(glGetUniformLocation(_pId, "constx"), constx);
  glUniform1f(glGetUniformLocation(_pId, "consty"), consty);

  gl4dgDraw(_quad);

}


void julia(int state) {
  /* INITIALISEZ VOS VARIABLES */
  switch(state) {
  case GL4DH_INIT:
    srand(time(NULL));
    init();
    /* INITIALISEZ VOTRE ANIMATION (SES VARIABLES <STATIC>s) */
    return;
  case GL4DH_FREE:
    /* LIBERER LA MEMOIRE UTILISEE PAR LES <STATIC>s */
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    /* METTRE A JOUR VOTRE ANIMATION EN FONCTION DU SON */
    return;
  default: /* GL4DH_DRAW */
    draw();
    return;
  }
}
