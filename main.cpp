#include "mainwindow.h"

/*! \mainpage The LBlock Building and Large Landscape Simulator
 *
 * \section intro_sec Introduction
 * This is the documentation of the LBlock Building and Large Landscape Simulator.
 * LBlock aims to be a fast tool for architects to be able to render buildings in real
 * time, and walk through them, getting a feel for the dimentions of the building.
 *
 * The input to this program is the floor plan of a structure, which is drawn by the
 * user. This can also be saved to a file, and read later, using an XML based .lbt file
 * format.
 *
 * \author Tejas Dinkar <tejas\@gja.in>
 * \author Thejaswi K <thejask\@gmail.com>
 * \author Sourav Sarkar <sourav87\@gmail.com>
 *
 * \section install_sec Installation
 *
 * \subsection req_sec Requirements
 * The following are the requirements for running the LBlock program
 * \li Qt Libraries (http://www.qtsoftware.com)
 * \li OpenGL libraries (bundled with Qt)
 *
 * Further, if compiling LBlock, the following are needed
 * \li CMake build system (http://www.cmake.org)
 * \li Doxygen for generating documentation (http://www.doxygen.org/)
 * \li Git source configuration management for managing the code base (http://git.or.cz)
 */

int main( int argc, char **argv )
{
	QApplication a(argc,argv);

	MainWindow window;
	window.show();

	return a.exec();
}
