#ifndef GLBOX_H
#define GLBOX_H

#include "texture.h"
#include "item.h"

#include <qgl.h>
#include <QHash>
#include <QString>
#include <QTimer>

class QDomDocument;

/**
 * This represents the OpenGL widget.
 * An object of this widget can be used to generate the 3D model
 * in which we can walk through. This widget is responsible for
 * maintaining the current state (the x, y, z co-ordinates and
 * orientation of the viewer) as well as the motion of the user.
 */
class GLBox : public QGLWidget
{
	Q_OBJECT

    private:
	/**
	 * Add an Object to the model. This is the recommended
	 * way to add an object to the \ref model
	 * \param item The item to be added
	 */
	inline void addObject(Item *item)
	{
		model<<item;
	}

	/// This stores the Document shown
	QDomDocument *doc;

    public:
	/**
	 * This is the Constructor.
	 * \param doc An XML Document that we parse to see objects
	 * \param parent The Widget's Parent (NULL for no parent)
	 */
	GLBox(QDomDocument *doc, QWidget* parent = NULL);

	/// The Destructor
	~GLBox();

    protected:
	/**
	 * This is called when the object is initialized. This function is simply 
	 * responsible for setting up the global parameters of the OpenGL 
	 * environment, such as blending, shading so on.
	 */
	void initializeGL();

	/** 
	 * This is called whenever the GLWidget is updated.
	 * This basically sets the orientation of the viewer, and then
	 * paints all the objects that are defined in the \ref model
	 */
	void paintGL();

	/**
	 * This is called whenever the widget is resized
	 * \param w the new width of the widget
	 * \param h the new height of the widget
	 */
	void resizeGL( int w, int h );

	/**
	 * This is called to generate the model from an XML document.
	 * See the example code below for the usage
	 * \code
	 * QFile file("file.xml");
	 * QDomDocument doc;
	 * doc.setContents(file);
	 * file.close();
	 * drawObject(&doc);
	 * \endcode
	 * \param doc A parsed XML DOM Document
	 */
	void drawObject(const QDomDocument *doc);

	/**
	 * This is called whenever a key is pressed.
	 * \param event A keypress event representing the event
	 */
	virtual void keyPressEvent(QKeyEvent *event);

	/**
	 * This is called whenever the mouse is moved.
	 * This is currently set to be called whenever the mouse moves,
	 * even if there has not been any click (which was the default behavior)
	 * \param event A mouse event representing the event
	 */
	virtual void mouseMoveEvent(QMouseEvent *event);

	/**
	 * This is called when the GLBox is closed
	 * \param event A close event representing the close
	 */
	virtual void closeEvent(QCloseEvent *event);

	/// The x position of the observer
	GLfloat posx;

	/// The y position of the observer
	GLfloat posy;

	/// The z position of the observer
	GLfloat posz;

	/// This stores where the user is looking to y axis (left is +ve)
	int left_right;

	/// This stores where the user is looking to x axis (up is +ve)
	int up_down;

	/// This stores the position of the center of the screen (x)
	int centerx;

	/// This stores the position of the center of the screen (y)
	int centery;

	/**
	 * This is a List of all the textures. All textures that are open
	 * should be stored in this list. This can be done as follows:
	 * \code
	 * textures["name"] = Texture(0xCOLOR, "/path/to/file", xscale, yscale);
	 * use(textures["name"]);
	 * \endcode
	 */
	QHash <QString, Texture> textures;

	/**
	 * This is a list of all the items on screen. This is arguably one of
	 * the most important members of this class. To add an object to this
	 * class, use the \ref addObject method.
	 * \see addObject
	 */
	QList <Item *> model;

	/// This timer refreshes the OpenGL widget every 50ms
	QTimer timer;

    public slots:

    signals:
	void terminated();
};

#endif // GLBOX_H
