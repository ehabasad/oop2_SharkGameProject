#include "GameObject.h"

void GameObject::setPosition(sf::Vector2f pos)
{
	m_pos = pos;
}

void GameObject::setTexture(sf::Texture pic)
{
	m_pic = pic;
}
