#version 120

precision mediump float;

uniform vec2 screenSize;

varying vec2 vUvs;

void main() {
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;

    gl_Position = gl_ProjectionMatrix * vertex;
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
    vUvs = vertex.xy / screenSize;
}