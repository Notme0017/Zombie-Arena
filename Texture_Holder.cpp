#include "Texture_Holder.h"
#include<assert.h>

Texture_Holder* Texture_Holder::m_s_Instance = nullptr;
Texture_Holder::Texture_Holder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& Texture_Holder::GetTexture(string const& filename)
{	
	//getting a reference to m_Textures
	//using singleton rule;
	map<string, Texture>& m = m_s_Instance->m_Textures;

	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else {
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}
