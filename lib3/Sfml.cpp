/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sfml.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:00:10 by bhamidi           #+#    #+#             */
/*   Updated: 2018/05/23 16:45:14 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sfml.hpp"
#include <iostream>

Sfml::~Sfml(void)
{
	this->_stop();
}

Sfml::Sfml(short x, short y)
	: _window()
{
	this->_init(x, y);
}

void	Sfml::_stop(void)
{
	this->_window->close();
	delete this->_window;
}

void	Sfml::_init(short x, short y) 
{
	this->_window = new sf::RenderWindow(sf::VideoMode(600, 800), "Nibbler");
	this->_window->setSize(sf::Vector2u(x * 10, y * 10));
}

eDir	Sfml::getEvent(void) const
{
	static eDir	direction = eDir::Left;
	eDir		tmp = direction;
	sf::Event	event;

	while ( this->_window->pollEvent(event) )
	{
    	switch (event.type)
    	{
			case sf::Event::Closed: direction = eDir::Exit; break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Left:  direction = eDir::Left; break;
					case sf::Keyboard::Right: direction = eDir::Right; break;
					case sf::Keyboard::Up:    direction = eDir::Up; break;
					case sf::Keyboard::Down:  direction = eDir::Down; break;
					default: break;
				}
				break;
			default: break;
    	}
		if (direction % 2 == tmp % 2)
			direction = tmp;
		if (tmp != direction)
			break;
	}
	return direction;
}

void	Sfml::render(Data const & data) const
{
	this->_window->clear(sf::Color::Black);

	sf::RectangleShape rectangle;

	for (auto h = 0; h < data._height; h++)
	{
		for (auto w = 0; w < data._width; w++)
		{
		/*	if (data._map[h][w] == eNum::Blank)
			if (data._map[h][w] == eNum::Wall)
			if (data._map[h][w] == eNum::Snake)
			if (data._map[h][w] == eNum::Head)
			if (data._map[h][w] == eNum::Food)
			*/
			rectangle.setSize(sf::Vector2f(10, 10));
			rectangle.setPosition(w * 30, h * 30);
			rectangle.setFillColor(sf::Color(100, 250, 50));
			this->_window->draw(rectangle);
		}
	}

	this->_window->display();
}

IGraphicLib	*createGraphicLib(short x, short y)
{
	return new Sfml(x, y);
}

void	deleteGraphicLib(IGraphicLib *graphicLib)
{
	delete graphicLib;
}
