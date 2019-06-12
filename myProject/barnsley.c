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
#include "barnsley.h"

/* Prototypes des fonctions statiques contenues dans ce fichier C */
static void init(void);
static void draw(void);
/*!\brief identifiant du programme GLSL */
//static GLuint _pId = 0;
/*!\brief quelques objets géométriques */
static GLuint _screenId = 0;
static int _H,_W;


#define PI 3.14159265


/*!\brief initialise les paramètres OpenGL et les données */
static void init(void) {
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    _H = vp[3];
    _W = vp[2];
    //printf("%d %d\n",_H,_W );
}







/*!\brief dessine dans le contexte OpenGL actif. */
static void draw(void) {
    double x0 = 0, x1;
    double y0 = 0, y1;

    for (int i = 0; i < 100; i++) {
        int p = rand()%100;
        //printf("%d\n", p);
        if (p < 1){
            x1 = 0;
            y1 = 0.16*y0;
        }
        else if(p < 8){
            x1 = 0.2*x0 - 0.26*y0;
            y1 = 0.23*x0 + 0.22*y0 + 1.6;
        }
        else if (p < 15){
            x1 = -0.15*x0 + 0.28*y0;
            y1 = 0.26*x0 + 0.24*y0 + 0.44;
        }
        else{
            x1 = 0.85*x0 + 0.04*y0;
            y1 = -0.04*x0 + 0.85*y0 + 1.6;
        }
        x0 = x1;
        y0 = y1;
        gl4dpPutPixel(100*x1 + _W/2, 80*y1 );
    }
    gl4dpUpdateScreen(NULL);
}




void barnsley(int state){
    switch(state) {
        case GL4DH_INIT:
            _screenId = gl4dpInitScreen();
            gl4dpSetScreen(_screenId);
            init();
            return;
        case GL4DH_FREE:
            return;
        case GL4DH_UPDATE_WITH_AUDIO:
            return;
        default:
            gl4dpSetColor(RGB(255, 0,0 ));
            draw();
            gl4dpUpdateScreen(NULL);
            return;
  }
}
