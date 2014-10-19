/* 
* @Author: Rafael Marinheiro
* @Date:   2014-10-18 22:58:16
* @Last Modified by:   Rafael Marinheiro
* @Last Modified time: 2014-10-18 23:45:40
*/
#include "PGBaseViewer.hpp"
#include <qapplication.h>
#include <cstdio>

int main(int argc, char** argv)
{
		
	// Read command lines arguments.
	QApplication application(argc,argv);
		
	// Instantiate the viewer.
	pg::PGBaseViewer viewer;

	// Make the viewer window visible on screen.
	viewer.show();

	// Run main loop.
	return application.exec();
}