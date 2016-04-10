#ifndef sge_relay_h
#define sge_relay_h

#include "sge_relay_interface.hpp"

namespace SGE {
	class Object;
	class Scene;
	class Director;
	class ObjectManager;
	class SceneID;
	class ObjectID;

	Relay::Relay() {}
	Relay::~Relay() {}

	Relay* Relay::getRelay()
	{
		static Relay* relay = new Relay();
		return relay;
	}

	void Relay::registerManager(ObjectManager* m)
	{
		this->manager = m;
	}

	void Relay::registerDirector(Director* d)
	{
		this->director = d;
	}
	
	void Relay::relayScene(Scene::ID s) {
		this->manager->addScene(s);
	}

	void Relay::relayShowScene(SceneID s)
	{
		if(this->manager->isOnScene())
		{
			throw std::runtime_error("Scene already displayed");
		}
		this->manager->showScene(s);
	}

	void Relay::relaySwapScene(SceneID s)
	{
		if (!this->manager->isOnScene())
		{
			throw std::runtime_error("No scene displayed");
		}
		this->manager->swapScene(s);
	}

	void Relay::relayDeleteScene(Scene::ID s)
	{
	//	this->manager->deleteScene(s);
	}

	long Relay::getNextCounter() {
		return manager->counter++;
	}
}


#endif /* sge_relay_h */