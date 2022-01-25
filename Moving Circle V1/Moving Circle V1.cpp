#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Moving Circle V1");
	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::Blue);
	circle.setPointCount(1000);
	circle.setPosition(300.f, 300.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			circle.move(0.f, -1.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			circle.move(0.f,1.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			circle.move(-1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			circle.move(1.f, 0.f);
		}
		else
		{
			circle.setPosition(300.f, 300.f);
		}
		// This is the reset to origin part: to remove change "else if" to "if" and remove "else"
		

		window.clear();
		window.draw(circle);
		window.display();
	}

	return 0;
}
