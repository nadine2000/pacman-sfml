#pragma once

#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "Global.h"

const int TEXTURE_NUMBER = 15;
const float TEXTURE_WIDTH = 100.f;
const int TOTAL_FONT = 2;
const int TOTAL_SOUNDS = 8;


class Resources 
{
public:
	
	static Resources& instance();

	 Resources(const Resources&) = delete;
	 void operator=(const Resources&) = delete;
	 sf::Texture& getTexture(GameTexture_t i);
	 sf::Font& getFont(Font_t);
	 sf::Sound& getSound(Sound_t);


	 const sf::Texture& spriteSheet() const;
	 const AnimationData& animationData(GameTexture_t i);

private:

	 Resources();

	 std::vector <sf::Texture> m_textures;
	 sf::Font m_font[TOTAL_FONT];
	 sf::SoundBuffer m_soundBuffer[TOTAL_SOUNDS];
	 sf::Sound m_sound[TOTAL_SOUNDS];

	 void loadTexture();
	 void loadFont();
	 void loadSound();

	 sf::Texture m_spriteSheet;
	 AnimationData m_data[2];


	 const std::string SOUND_STRING[TOTAL_SOUNDS] = { "eat.wav", "doors.wav","endtime.wav","wins.wav",
												 "super.wav","gift.wav","lostlife.wav", "lose.wav" };

	 const std::string TEXTURE_STRINGS[TEXTURE_NUMBER] = {"wall.png", "gift.png", "gift1.png", 
		 "gift2.png", "gift3.png", "door.png",
		 "key.png", "cookie.png", "wite.png", 
		 "menu.jpeg", "main.jpg", "help.jpeg",
		 "win.jpeg", "lose.jpg", "timeup.jpeg" };
	
};
