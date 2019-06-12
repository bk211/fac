#version 330
//in vec2 vsoTexCoord;
uniform float Centerx;
uniform float Centery;
uniform int largeur;
uniform int hauteur;
uniform float echelle;


uniform sampler2D myTexture;
in  vec2 vsoTexCoord;
out vec4 fragColor;

void main(void) {
    float cx, cy, zx, zy;
    cx = (gl_FragCoord.x/largeur -0.5) * echelle - Centerx ;
    cy = (gl_FragCoord.y/hauteur -0.5) * echelle - Centery;
    zx = cx;
    zy = cy;

    float x,y;
    int i;
    for(i=0; i<255; i++) {
        x = (zx * zx - zy * zy) + cx;
        y = (zy * zx + zx * zy) + cy;

        if (x *x + y*y >4)//si la suite tend vers l'infini
            break;
        //sinon elle est bornee
        zx = x;
        zy = y;
    }

    fragColor = vec4(float(i)/255.0, float(i)/255.0 , float(i)/255.0, 1.0);

}
