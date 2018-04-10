#include <SFML/Graphics.hpp>
#include <math.h>

constexpr float Deg2Rad = ( 1.0 / 57.3 );
//sf::Clock clock;

int main()
{
    //App.SetFramerateLimit(60);
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(100, 100), "My window");

    sf::VertexArray points( sf::Triangles, 10 );
    points[0].position = sf::Vector2f( 0, 0 );
    points[0].color = sf::Color::Green;

	points[ 1 ].position = sf::Vector2f( 100, 100 );
	points[ 1 ].color = sf::Color::Blue;

	points[ 2 ].position = sf::Vector2f( 50, 0 );
	points[ 2 ].color = sf::Color::Red;
    
    float frame = 0;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //float time = clock.restart();   
        
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        frame += 1;

        points[0].position = sf::Vector2f( 50 + 50 * std::cos( frame * Deg2Rad ), 50 + 50 * std::sin( frame * Deg2Rad ) );
	    points[ 1 ].position = sf::Vector2f( 100, 100 );
	    points[ 2 ].position = sf::Vector2f( 50, 0 );

        // draw everything here...
        // window.draw(...);
        window.draw( points );

        // end the current frame
        window.display();
    }

    return 0;
}
