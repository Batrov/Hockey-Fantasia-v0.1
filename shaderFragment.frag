uniform sampler2D texture;

void main()
{
	vec2 pos = gl_TexCoord[0].xy;
    gl_FragColor = vec4(0.7f,0.0f,0.0f,1.0f) * texture2D(texture, pos);
}