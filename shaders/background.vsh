#version 120

varying vec2 texCoord;

void main() {
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;

    gl_Position = gl_ProjectionMatrix * vertex;
    texCoord = (gl_TextureMatrix[0] * gl_MultiTexCoord0).xy;
}