#include "ship.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <cmath>

Ship::Ship(){
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(10.0f, 0.0f));
    shape.setPoint(1, sf::Vector2f(-10.0f, 7.5f));
    shape.setPoint(2, sf::Vector2f(-10.0f, -7.5f));

    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(sf::Vector2f(WIDTH/2, HEIGHT/2));
}

void Ship::drawShape(sf::RenderWindow &window){
    window.draw(shape);
}

const sf::ConvexShape& Ship::getShape(){
    return shape;
}

void Ship::update(){
    //checks for ship exceeding bounds
    sf::Vector2f position = shape.getPosition();

    if (position.x < 0)
        position.x = 800;
    else if (position.x > 800)
        position.x = 0.0f;

    if (position.y < 0)
        position.y = 800;
    else if (position.y > 800)
        position.y = 0.0f;
    shape.setPosition(position);
    
    //SAT Collisions

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        angle += (10 * DEG2RAD);
        shape.rotate(10.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        angle -= (10 * DEG2RAD);
        shape.rotate(-10.f);
    }
    // Update velocity based on the ship's orientation if acceleration keys are pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (a < maxAcceleration) {
            a += accelerationRate;
        }
        applyForces();
        moveVel = v;
    }else{
        if(a>0){
            a-=accelerationRate;
        }
    }
    shape.move(moveVel);
}

void Ship::applyForces(){
       // Calculate force using F = ma
    sf::Vector2f f(m * a * cos(angle), m * a * sin(angle));

    // acceleration: change in velocity due to force f on object with mass m
    sf::Vector2f dv = f / m;

    // new velocity if acceleration dv applied
    sf::Vector2f new_v = v + dv;

    // only apply Lorentz factor if acceleration increases speed
    if (std::hypot(new_v.x, new_v.y) > std::hypot(v.x, v.y)) {
        // maximum speed objects may reach (the "speed of light")
        const float c = 4;

        float b = 1 - (std::hypot(v.x, v.y) * std::hypot(v.x, v.y)) / (c * c);
        if (b <= 0) b = 0;

        float lorentz_factor = 1 / std::sqrt(b);
        dv /= lorentz_factor;
    }

    // apply acceleration to object's velocity
    v += dv;

    // Update:
    // Allow acceleration in the forward direction to change the direction
    // of v by using the direction of new_v (without the Lorentz factor)
    // with the magnitude of v (that applies the Lorentz factor).
    if (std::hypot(v.x, v.y) > 0) {
        v = new_v / std::hypot(new_v.x, new_v.y) * std::hypot(v.x, v.y);
    }
    std::cout << v.x << ", " << v.y << std::endl;
}

// https://github.com/OneLoneCoder/Javidx9/blob/master/PixelGameEngine/SmallerProjects/OneLoneCoder_PGE_PolygonCollisions1.cpp
bool Ship::ShapeOverlap_SAT(const sf::ConvexShape& shape1, const sf::ConvexShape& shape2) {
    const sf::ConvexShape* poly1 = &shape1;
    const sf::ConvexShape* poly2 = &shape2;

    for (int shape = 0; shape < 2; shape++) {
        if (shape == 1) {
            poly1 = &shape2;
            poly2 = &shape1;
        }
        for(int a = 0; a < poly1->getPointCount(); a++){
            int b = (a + 1) % poly1->getPointCount();
            sf::Vector2f axisProj = sf::Vector2f(-(poly1->getTransform().transformPoint(poly1->getPoint(b)).y - poly1->getTransform().transformPoint(poly1->getPoint(a)).y), poly1->getTransform().transformPoint(poly1->getPoint(b)).x - poly1->getTransform().transformPoint(poly1->getPoint(a)).x );
            float d = sqrtf(axisProj.x * axisProj.x + axisProj.y * axisProj.y); //distance
            axisProj = sf::Vector2f(axisProj.x / d, axisProj.y/d);

            float min_r1 = INFINITY, max_r1 = -INFINITY;
            for(int p = 0; p < poly1->getPointCount(); p++){
                float q = (poly1->getTransform().transformPoint(poly1->getPoint(p)).x * axisProj.x + poly1->getTransform().transformPoint(poly1->getPoint(p)).y * axisProj.y);
                min_r1 = std::min(min_r1,q);
                max_r1 = std::max(max_r1, q);
            }
            float min_r2 = INFINITY, max_r2 = -INFINITY;
            for(int p = 0; p < poly2->getPointCount(); p++){

                float q = (poly2->getTransform().transformPoint(poly2->getPoint(p)).x * axisProj.x + poly2->getTransform().transformPoint(poly2->getPoint(p)).y * axisProj.y);
                min_r2 = std::min(min_r2,q);
                max_r2 =std::max(max_r2, q);
            }
            if (!(max_r2 >= min_r1 && max_r1 >= min_r2))
				return false;
        }
    }
    return true;
}

bool Ship::sat_test_bullet(const sf::ConvexShape &sp1, const sf::FloatRect &sp2, sf::Vector2f *out_mtv){
	const sf::FloatRect &rectSp1 = sp1.getGlobalBounds();
	const sf::FloatRect &rectSp2 = sp2;
	float proj_x, proj_y, overlap_x, overlap_y;
	
	// test overlap in x axis
	proj_x = std::max(rectSp1.left+rectSp1.width, rectSp2.left+rectSp2.width)-std::min(rectSp1.left, rectSp2.left);
	if(proj_x < rectSp1.width+ rectSp2.width){
		if(out_mtv){
			// calculate mtv in x
			overlap_x = rectSp1.width+ rectSp2.width - proj_x;
		}
		// test overlap in y axis
		proj_y = std::max(rectSp1.top+rectSp1.height, rectSp2.top+rectSp2.height)-std::min(rectSp1.top, rectSp2.top);
		if(proj_y < rectSp1.height+ rectSp2.height){
			if(out_mtv){
				// calculate mtv in y
				overlap_y = rectSp1.height+ rectSp2.height - proj_y;
				out_mtv->x = out_mtv->y = 0;
				
				// choose minimun overlap
				if(overlap_x < overlap_y){
					out_mtv->x = overlap_x * (rectSp1.left < rectSp2.left?-1:1);
				}else{
					out_mtv->y = overlap_y * (rectSp1.top < rectSp2.top?-1:1);
				}
			}
			return true;
		}
	}
	return false;
}

sf::Vector2f Ship::getVelocity(){
    return v;
}

float Ship::getAngle(){
    return angle;
}

sf::Vector2f Ship::getPosition(){
    return shape.getPosition();
}

void Ship::loadLives(sf::RenderWindow &window, int lives){
    int pos = 0;
    for(int i = lives; i > 0; i--){
        sf::Texture img; 
        sf::Sprite sprite;
        if (!img.loadFromFile("./img/ship.png",sf::IntRect(0, 0, 32, 32) ) )
        {
            // error...
        }
        sprite.setTexture(img);
        sprite.setPosition(sf::Vector2f(pos, 0));
        window.draw(sprite);
        pos+=32;
    }
}

void Ship::shipReset(sf::RenderWindow &window){
    sf::sleep(sf::seconds(1));
    shape.setPosition(sf::Vector2f(WIDTH/2, HEIGHT/2));
    v = sf::Vector2f(0.0f, 0.0f);
    moveVel = sf::Vector2f(0.0f, 0.0f);
    angle = 0;
    shape.setRotation(angle);
}
