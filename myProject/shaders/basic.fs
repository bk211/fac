#version 330
uniform sampler2D myTexture;
in  vec2 vsoTexCoord;
out vec4 fragColor;

void main(void) {

    fragColor = vec4(0, 0, 0, 0);
    if (vsoTexCoord.x < 0.5f)
        fragColor = vec4(1, 1, 1.0, 1.0);

}
