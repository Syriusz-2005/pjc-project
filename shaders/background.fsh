
uniform sampler2D texture;
uniform float zDistance;

varying out vec4 fragColor;

void main() {
    vec4 txt = texture2D(texture, gl_TexCoord[0].xy);
    fragColor = vec4(txt.rgb, txt.a * (1 / zDistance));
}