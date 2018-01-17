﻿#ifndef ZOMBIEGAME_OBJECTS
#define ZOMBIEGAME_OBJECTS
#include <sge_reactive.hpp>
#include "sge_shape_circle.hpp"
#include <forward_list>

enum class Category : unsigned short
{
	Player = 1 << 0,
	Human = 1 << 1,
	Zombie = 1 << 2,
	HumanSensor = 1 << 4,
	ZombieSensor = 1 << 5,
	Level = 1 << 15,
};

inline unsigned short operator|(const Category a, const Category b)
{
	return unsigned short(a) | unsigned short(b);
}

inline unsigned short operator|(const unsigned short a, const Category b)
{
	return a | unsigned short(b);
}

inline unsigned short operator&(const Category a, const Category b)
{
	return unsigned short(a) & unsigned short(b);
}

inline unsigned short operator&(const unsigned short a, const Category b)
{
	return a & unsigned short(b);
}

inline bool isCat(b2Fixture* fixture, Category cat)
{
	return fixture->GetFilterData().categoryBits & cat;
}

inline SGE::Shape* getCircle()
{
	static SGE::Circle c(32, false);
	return &c;
}

class Player : public SGE::Reactive
{
public:
	using Reactive::Reactive;
};

class Portal : public SGE::Reactive
{
public:
	using SGE::Reactive::Reactive;

	Portal(float x, float y);
};

class Human : public SGE::Reactive
{
	using BodyList = std::forward_list<Human*>;
	float speed = 5 * 64.f;
	b2Vec2 direction = { 1.f,0.f };
	unsigned int counter = 1;
	unsigned int maxCount = 0;
	bool zombified = false;
	BodyList bodies;
public:
	Human(const float x, const float y);

	Human(const float x, const float y, const unsigned int max);

	void setMaxCount(const unsigned int max);

	unsigned int getCounter();

	b2Vec2 getDirection() const;

	void setDirection(const b2Vec2 vel);

	float getSpeed() const;

	void setSpeed(float s);

	BodyList& getBodies();

	void Zombify();

	inline bool getZombified() const;
};

bool Human::getZombified() const
{
	return this->zombified;
}

class Image : public SGE::Object
{
public:
	using Object::Object;
};

class Pointer : public SGE::Object
{
public:
	Pointer();
};
#endif
