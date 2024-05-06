#version 120

uniform sampler2D texture;
uniform float zDistance;

varying vec2 texCoord;

void main() {
    vec4 fragColor = vec4(0.0);
    vec4 txt = texture2D(texture, texCoord);
    vec3 scatteringTarget = vec3(.9, .9, .9);

    vec3 delta = scatteringTarget - txt.rgb;

    fragColor.rgb = txt.rgb + delta * min(1, zDistance / 10);

    fragColor.a = txt.a;

    gl_FragColor = fragColor;
}