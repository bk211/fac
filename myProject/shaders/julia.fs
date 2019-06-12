#version 330
//in vec2 vsoTexCoord;
uniform float Centerx;
uniform float Centery;
uniform float constx;
uniform float consty;
uniform int largeur;
uniform int hauteur;
uniform float echelle;


uniform sampler2D myTexture;
in  vec2 vsoTexCoord;
out vec4 fragColor;

void main(void) {
    float zx, zy;
    float x,y;
    int i;
    zx = (gl_FragCoord.x/largeur -0.5) * echelle;
    zy = (gl_FragCoord.y/hauteur -0.5) * echelle;

    for(i=0; i<255; i++) {
        x = (zx * zx - zy * zy) + constx;
        y = (zy * zx + zx * zy) + consty;

        if (x *x + y*y >4)//si la suite tend vers l'infini
            break;
        //sinon elle est bornee
        zx = x;
        zy = y;
    }
    fragColor = vec4(1.0, float(i)/255.0 , 1.0, 1.0);

}
