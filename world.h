typedef unsigned char byte;

#ifndef World_H
#define World_H

class World
{
public:
	World(int x, int y);
	~World();
	int getWidth() const;
	int getHeight() const;
	
	byte at(int x, int y) const;
	void set(int x,int y, byte c);
	
	void swap(World* p_world);
private:
	int m_Width;
	int m_Height;
	byte* p_Cells;
};
#endif
	
