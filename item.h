#ifndef ITEM_H
#define ITEM_H

#include <qgl.h>

/**
 * This abstract class represents an Item. By itself, this class doesn't have much
 * use, and must be inherited for use. This class provides some functions that all
 * classes must implement, in particular \ref generateList.
 */
class Item
{
    protected:
	/*
	 * This stores the OpenGL Display List.
	 * This is created in \ref compile by \ref generateList. If you wish to force a recompile, set \ref dirty = true
	 */
	GLuint object;

	/// This is the x coordinate of the object. This can be any standard position of the object, but we choose left bottom corner
	GLfloat posx;

	/// This is the y coordinate of the object. This can be any standard position of the object, but we choose left bottom corner
	GLfloat posy;

	/// This is the z coordinate of the object. This can be any standard position of the object, but we choose left bottom corner
	GLfloat posz;

	/// This is the rotation of the object
	GLfloat rotation;

	/**
	 * Forces a recompile of the object. This flag can be set to true if we wish to force
	 * a recompile of the Call List. In this way, we can set up animations, by always
	 * setting the dirty flag. If we reimplement \ref drawObject, however, we should
	 * check to see that it starts with
	 * \code
	 * if (dirty)
	 * 	compile();
	 * \endcode
	 */
	bool dirty;

    public:
	/**
	 * This is the constructor
	 * \param x The x Co-Ordinate of the Object
	 * \param y The y Co-Ordinate of the Object
	 * \param z The z Co-Ordinate of the Object
	 * \param rotation the Rotation of the Object wrt the z axis
	 */
	Item(float x, float y, float z, float rotation = 0.0f);

	/// This is the Destructor
	~Item();

	/**
	 * This function is used to set the position of the object.
	 * \param x The x Co-Ordinate of the Object
	 * \param y The y Co-Ordinate of the Object
	 * \param z The z Co-Ordinate of the Object
	 */
	inline void setPos(float x,float y,float z) { posx=x; posy=y; posz=z; }

	/// Return the X coordinate of the object \return The X coordinate
	inline float getPosX() { return posx; }

	/// Return the Y coordinate of the object \return The Y coordinate
	inline float getPosY() { return posy; }

	/// Return the Z coordinate of the object \return The Z coordinate
	inline float getPosZ() { return posz; }

	/// Get the rotation of the object \return The Rotation
	inline float getRotation() { return rotation; }

	/// Set the rotation of the object \param r The Rotation
	inline void setRotation(float r) { rotation = r; }

	/*
	 * This function compiles the object.
	 * It calls \ref generateList to create the CallList \ref object
	 */
	void compile();

	/**
	 * This is the public function to draw the object. Unless overridden, this simply
	 * moves to the location specified by the given position, and then calls glCallList
	 * to draw the object
	 */
	virtual void drawObject();

	/// This is the member which MUST be overridden, which generates the call list. \see object
	virtual void generateList() = 0;

	/** This method checks if a point collides with this object
	 * \param x The X position of the point
	 * \param y The Y position of the point
	 * \param z The Z position of the point
	 * \return true if there is a collision, false otherwise
	 */
	virtual bool isCollision(float x, float y, float z);
};

#endif
