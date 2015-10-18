#version 330

//input data from the VBO. Each vertex is 2 floats
in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

out vec2 fragmentPosition;
/* flat */ out vec4 fragmentColor; // "flat" will prevent interpolation
out vec2 fragmentUV;

void main() {
    gl_Position.xy = vertexPosition;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;
    
    fragmentPosition = vertexPosition;
    fragmentColor = vertexColor;
    fragmentUV = vec2( vertexUV.x, 1.0 - vertexUV.y);
}