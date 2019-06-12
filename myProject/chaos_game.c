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
#include "chaos_game.h"

/* Prototypes des fonctions statiques contenues dans ce fichier C */
static void init(void);
/*!\brief quelques objets géométriques */
static GLuint _screen0 = 0,_screen1 = 0,_screen2 = 0;


/*!\brief macro de PI*/
#define PI 3.14159265
static int _H, _W,rX,rY, r,_currentR=0;
static int c1 =0;

/*!\brief initialise les paramètres OpenGL et les données */
static void init(void) {
  GLint vp[4];
  glGetIntegerv(GL_VIEWPORT, vp);
  _H = vp[3];
  _W = vp[2];
  rX = _W/2,rY = _H/2; //coordonnee centre du cercle
  r = rY*9/10; // rayon
}


static void dessin(void) {
  for (int i = 0; i < 10; ++i)
  {
    GLubyte r = rand() % 256, g = rand() % 256, b = rand() % 256;
    gl4dpSetColor(RGB(r, g, b));
    int x = rand()%_H, y = rand() % _W;
    gl4dpPutPixel(x, y);


  }
  gl4dpUpdateScreen(NULL);
}
static void chaos(int *tabX, int* tabY, int n, float r,int cX, int cY, int param, int color){
  int curX = cX, curY = cY;
  int choice = 0, last= 0;
  for (int i = 0; i < 66; ++i)
  {
    switch(param){
      case 1://le point choisit est different du choix precedent
        while (choice == last){
          choice = rand() % n;
        }
        last = choice;
        break;

      case 2:
        while (1)
          choice = rand() % n;
        last = choice;
        break;
      default:// choisit un point au hasard
        choice = rand() % n;
    }


    //calcule du coordonnee du milieu du segment entre ces 2 points
    curX = (curX + tabX[choice]) * r;
    curY = (curY + tabY[choice]) * r;
    //un peu de couleur
    if(color){
        GLubyte r = rand() % 256, g = rand() % 256, b = rand() % 256;
        gl4dpSetColor(RGB(r, g, b));
    }

    gl4dpPutPixel(curX,curY);
    gl4dpUpdateScreen(NULL);
  }
}


static void drawTriangle(void){
  int ns = 3;
  float depart = PI/2;
  int sommetsX[3];
  int sommetsY[3];


  for (int i = 0; i < ns; ++i){//genere les points
    sommetsX[i] = rX + r * cos(depart + 2*PI/ns * i);
    sommetsY[i] = rY + r * sin(depart + 2*PI/ns * i);
    //gl4dpLine(rX,rY,sommetsX[i],sommetsY[i]);
  }

  gl4dpUpdateScreen(NULL);

  for (int i = 0; i < ns; ++i){//dessine le polygone en question
    gl4dpLine(sommetsX[i],sommetsY[i],sommetsX[(i+1)%ns],sommetsY[(i+1)%ns]);
  }
  gl4dpUpdateScreen(NULL);
  //dessine le points
  chaos(sommetsX, sommetsY, ns, 1.0/2, rX,rY,0,1);

}

static void drawFilledCircle(){
    for (int i = 0; i < 5; i++) {
        gl4dpFilledCircle(_W/2,_H/2,_currentR);
        gl4dpUpdateScreen(NULL);
        _currentR++;
    }
}


static void drawSquare(void){
  int ns = 4;
  float depart = 0;//PI/2;
  int sommetsX[4];
  int sommetsY[4];
  for (int i = 0; i < ns; ++i)
  {
    sommetsX[i] = rX + r * cos(depart + 2*PI/ns * i);
    sommetsY[i] = rY + r * sin(depart + 2*PI/ns * i);
  }
  gl4dpUpdateScreen(NULL);

  for (int i = 0; i < ns; ++i)
  {
    gl4dpLine(sommetsX[i],sommetsY[i],sommetsX[(i+1)%ns],sommetsY[(i+1)%ns]);
  }
  gl4dpUpdateScreen(NULL);

  chaos(sommetsX, sommetsY, ns, 1.0/2, rX,rY,1,0);

}

static void drawPenta(void){
  int ns = 5;
  float depart = PI/2;
  int sommetsX[5];
  int sommetsY[5];
  for (int i = 0; i < ns; ++i)
  {
    sommetsX[i] = rX + r * cos(depart + 2*PI/ns * i);
    sommetsY[i] = rY + r * sin(depart + 2*PI/ns * i);
  }
  gl4dpUpdateScreen(NULL);
  for (int i = 0; i < ns; ++i)
  {
    gl4dpLine(sommetsX[i],sommetsY[i],sommetsX[(i+1)%ns],sommetsY[(i+1)%ns]);
    }

    chaos(sommetsX, sommetsY, ns, 1.0/2, rX,rY,1,0);
    gl4dpUpdateScreen(NULL);
}



void random_pixel(int state) {
switch(state) {
  case GL4DH_INIT:
    init();
    return;
  case GL4DH_FREE:
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    return;
  default:
    dessin();
    return;
  }
}

void transition0(int state){
    switch(state) {
      case GL4DH_INIT:
        return;
      case GL4DH_FREE:
        return;
      case GL4DH_UPDATE_WITH_AUDIO:
        return;
      default:
        gl4dpSetColor(RGB(10,10,10));
        for (int i = 0; i < 5; i++) {
            gl4dpLine(c1,0,c1,_H);
            c1++;
        }
        gl4dpUpdateScreen(NULL);
        return;
    }
}


void transition1(int state){
switch(state) {
  case GL4DH_INIT:
    return;
  case GL4DH_FREE:
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    return;
  default:
    gl4dpSetColor(RGB(255, 255, 204));
    drawFilledCircle();
    gl4dpUpdateScreen(NULL);
    return;
  }
}
void transition2(int state){
    switch(state) {
      case GL4DH_INIT:
        return;
      case GL4DH_FREE:
        return;
      case GL4DH_UPDATE_WITH_AUDIO:
        return;
      default:
        gl4dpSetColor(RGB(204,255,255));
        for (int i = 0; i < 5; i++) {
            gl4dpLine(c1,0,c1,_H);
            c1--;
        }
        gl4dpUpdateScreen(NULL);
        return;
    }
}


void triangle(int state){
switch(state) {
  case GL4DH_INIT:
    _screen0 = gl4dpInitScreen();
    gl4dpClearScreenWith(RGB(0, 0, 0));
    init();
    return;
  case GL4DH_FREE:
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    return;
  default:
    drawTriangle();
    gl4dpUpdateScreen(NULL);
    return;
  }
}
void square(int state){
switch(state) {
  case GL4DH_INIT:
    _screen1 = gl4dpInitScreen();
    gl4dpClearScreenWith(RGB(0, 0, 0));
    init();
    return;
  case GL4DH_FREE:
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    return;
  default:
    gl4dpSetColor(RGB(0,255,0));
    drawSquare();
    gl4dpUpdateScreen(NULL);
    return;
  }
}

void penta(int state){
switch(state) {
  case GL4DH_INIT:
    _screen2 = gl4dpInitScreen();
    gl4dpClearScreenWith(RGB(0, 0, 0));
    init();
    return;
  case GL4DH_FREE:
    return;
  case GL4DH_UPDATE_WITH_AUDIO:
    return;
  default:
    gl4dpSetColor(RGB(255,0,0));
    drawPenta();
    gl4dpUpdateScreen(NULL);
    return;
  }
}
