#version 120

// The sfml does not provide normalized uv coordinates, so we have to do it manually
//uniform vec2 size;

varying vec2 vUvs;

void main() {
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;

    gl_Position = gl_ProjectionMatrix * vertex;
    vUvs = gl_Vertex.xy / vec2(512);
}