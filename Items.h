#ifndef ITEMS_H
#define ITEMS_H
#include<string>


namespace items
{
	
	class Weapon
	{
		public:
		
		Weapon(std::string name, int damage, std::string description): m_name(name), m_damage(damage), m_description(description){} 
		int get_dmg()const{return m_damage;}
		std::string get_name()const{return m_name;}
		std::string get_description()const{return m_description;}
		
		private:
		
		std::string m_description;
		std::string m_name;
		int m_damage;
	};
}

#endif //ITEMS_H