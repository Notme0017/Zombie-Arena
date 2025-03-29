#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include<SFML/Graphics.hpp>
#include<map>
using namespace std;
using namespace sf;
class Texture_Holder
{
private:
	map<string, Texture> m_Textures;
	//a pointer of the classtype itself
	static Texture_Holder* m_s_Instance;
public:
	Texture_Holder();
	static Texture& GetTexture(string const& filename);
};

#endif

