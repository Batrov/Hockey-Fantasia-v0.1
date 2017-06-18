uniform float merah;
uniform float ijo;
uniform float biru;
uniform sampler2D texture;

void main()
{
	vec2 pos = gl_TexCoord[0].xy;
    gl_FragColor = vec4(merah,ijo,biru,1.0f) * texture2D(texture, pos);
}