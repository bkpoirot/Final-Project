#ifndef ENEMY_H
#define ENEMY_H

#include "Items.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <time.h>

namespace enemy
{
	class Enemy
	{
		public:
		
		int take_dmg(int damage_taken){m_hitpoints -= damage_taken;}
		
		int attack(Enemy & attackee)
		{ 
			int roll = rand()%20;
			int dmg = 0;
			roll > 10 ? dmg = m_weapon.get_dmg() : dmg = 0;
			attackee.take_dmg(dmg);
			//std::cout<<m_name<<" did "<< dmg<<" damage to "<<attackee.getName()<<"!"<<std::endl;
		}
		
		bool is_dead(){return (m_hitpoints <= 0);}
		
		Enemy(std::string name, int hitpoints, items::Weapon weapon):
			m_name(name),
			m_hitpoints(hitpoints), 
			m_weapon(weapon){}
			
		std::string getName(){return m_name;}
		
		int getHP(){return m_hitpoints;}
		
		
		private:
		std::string m_name;
		int m_hitpoints;
		//int armor_class; maybe???
		items::Weapon m_weapon;
	};

	
	// first argument attacks first
	enemy::Enemy fight( enemy::Enemy &e1, enemy::Enemy &e2)
	{
		while (!((e2.is_dead()) || (e1.is_dead())))
		{
			e1.attack(e2);
			if(!e2.is_dead())
				e2.attack(e1);
		}
		
		if (e2.is_dead())
		{
			std::cout<<e2.getName()<<" has died!"<<std::endl;
			return e1;
		}
		
		else
		{
			std::cout<<e1.getName()<<" has died!"<<std::endl;
			return e2;
		}
	}

}


#endif //ENEMY_H