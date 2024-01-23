#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures { // I am only providing a "texture"-based enum but you can implement more
	enum ID { Spaceship, Asteroid };
}

template <typename Resource, typename Identifier>
class ResourcecHolder {
public:
	void load(Identifier id, const std::string &fileName); // resource loader
	Resource &get(Identifier id); // resource access
	const Resource &get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>> resourceMap; // resource container
};

template<typename Resource, typename Identifier>
inline void ResourcecHolder<Resource, Identifier>::load(Identifier id, const std::string &fileName) {
	std::unique_ptr<Resource> resource(new Resource); // creating a smart pointer for a new texture
	resource->loadFromFile(fileName); // loading the reource 

	resourceMap.insert(std::make_pair(id, std::move(resource))); // appending the resource with an id into the map
}

template<typename Resource, typename Identifier>
inline Resource &ResourcecHolder<Resource, Identifier>::get(Identifier id) {
	auto found = resourceMap.find(id); // getting a pointer to the resource from the map
	return *found->second; 
}

template<typename Resource, typename Identifier>
inline const Resource &ResourcecHolder<Resource, Identifier>::get(Identifier id) const {
	auto found = resourceMap.find(id); // basically the same
	return *found->second;
}
