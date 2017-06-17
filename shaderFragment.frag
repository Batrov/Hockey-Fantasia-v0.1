uniform sampler2D texture;

void main()
{
	vec2 pos = gl_TexCoord[0].xy;
    gl_FragColor = vec4(0.5f,0.0f,0.0f,0.5f) * texture2D(texture, pos);
}