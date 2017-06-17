#include "StdAfx.h"
#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject()
	: _isLoaded(false)
{
	//_isLoaded = false; Slightly faster to use the above constructor initialization.
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
	if(_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if(_isLoaded)
	{
		sf::Shader m_shader;

		// Load the shader
		m_shader.loadFromFile("shaderFragment.frag", sf::Shader::Fragment);
		m_shader.setUniform("texture", sf::Shader::CurrentTexture);
		sf::RenderStates states;
		states.shader = &m_shader;
		renderWindow.draw(_sprite,states);
	}
}

void VisibleGameObject::Update(float elapsedTime)
{
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if(_isLoaded)
	{
		_sprite.setPosition(x,y);
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
  if(_isLoaded)
  {
    return _sprite.getPosition();
  }
  return sf::Vector2f();
}

float VisibleGameObject::GetHeight() const
{
	return _sprite.getLocalBounds().height;
}

float VisibleGameObject::GetWidth() const
{
	return _sprite.getLocalBounds().width;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
  return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
  return _isLoaded;
}