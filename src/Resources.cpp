#include "Resources.h"


namespace
{
	AnimationData redGhostData()
	{
		const auto size = sf::Vector2i(40, 40);
		const auto initSpace = sf::Vector2i(1, 2);
		const auto middleSpace = sf::Vector2i(0, 10);

		auto redGhost = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.y += size.y;
			return currentStart;
		};

		redGhost.m_data[Direction::Right].emplace_back(currentStart, size);
		redGhost.m_data[Direction::Right].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Down].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Down].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Left].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Left].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Up].emplace_back(nextStart(), size);
		redGhost.m_data[Direction::Up].emplace_back(nextStart(), size);

		return redGhost;
	}

	AnimationData pacmanData()
	{
		const auto size = sf::Vector2i(40, 40);
		const auto initSpace = sf::Vector2i(851, 2);
		const auto middleSpace = sf::Vector2i(0, 10);

		auto pacman = AnimationData{};
		auto currentStart = initSpace;

		auto nextStart = [&]()
		{
			currentStart += middleSpace;
			currentStart.y += size.y;
			return currentStart;
		};

		pacman.m_data[Direction::Right].emplace_back(currentStart, size);
		pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
		pacman.m_data[Direction::Up].emplace_back(nextStart(), size);

		return pacman;
	}
}

Resources::Resources()
{
	if (!m_spriteSheet.loadFromFile("Pacman.png"))
	{
		std::cout << "ERROR OPENING SPRITE SHEET ! ";
		exit(EXIT_FAILURE);
	}

	m_data[0] = pacmanData();
	m_data[1] = redGhostData();

	loadTexture();
    loadFont();
	loadSound();
}

Resources& Resources::instance()
{
	static auto resources = Resources(); 
	return resources;
}

sf::Texture& Resources::getTexture(GameTexture_t i)
{
	return m_textures[i];
}

void Resources::loadTexture()
{
	m_textures = std::vector <sf::Texture>(TEXTURE_NUMBER, sf::Texture());

	for (int i = 0; i < TEXTURE_NUMBER; i++)
		if (!m_textures[i].loadFromFile(TEXTURE_STRINGS[i]))
		{
			std::cout << "ERROR OPENING ! " << TEXTURE_STRINGS[i];
			exit(EXIT_FAILURE);
		}

}

sf::Sound& Resources::getSound(Sound_t i)
{
	return m_sound[(int)i];
}

sf::Font& Resources::getFont(Font_t i)
{
	return m_font[(int)i];
}

void Resources::loadFont()
{
	if (!m_font[0].loadFromFile("RAVIE.TTF") || 
		!m_font[1].loadFromFile("FORTE.TTF"))
	{
		std::cout << "error opnening (FONT)TTF";
		exit(EXIT_FAILURE);
	}

}

const sf::Texture& Resources::spriteSheet() const
{
	return m_spriteSheet;
}

const AnimationData& Resources::animationData(GameTexture_t i)
{
	if (i == PacmanObj || i == SuperpacmanObj)
		return m_data[0];

	return m_data[1];
}

void Resources::loadSound()
{
	for (int i = 0; i < TOTAL_SOUNDS; i++)
	{
		if (!m_soundBuffer[i].loadFromFile(SOUND_STRING[i]))
		{
			std::cout << "ERROR OPENING ! " << SOUND_STRING[i];
			exit(EXIT_FAILURE);
		}

		m_sound[i].setBuffer(m_soundBuffer[i]);
	}
}

