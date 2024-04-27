
uniform sampler2D texture;
uniform float zDistance;

varying out vec4 fragColor;

void main() {
    vec4 txt = texture2D(texture, gl_TexCoord[0].xy);
    vec3 scatteringTarget = vec3(.9, .9, .9);

    vec3 delta = scatteringTarget - txt;

    fragColor.rgb = txt.rgb + delta * min(1, zDistance / 10);

    fragColor.a = txt.a;
}