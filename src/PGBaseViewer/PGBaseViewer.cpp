/* 
* @Author: Rafael Marinheiro
* @Date:   2014-10-18 22:50:16
* @Last Modified by:   Rafael Marinheiro
* @Last Modified time: 2014-10-18 23:45:37
*/

#include "PGBaseViewer.hpp"

#include <pg_gl.h>

namespace pg{
	PGBaseViewer::PGBaseViewer(QWidget *parent) :
		QGLWidget(parent), m_fullscreen(false){
		this->setWindowTitle("PGBaseViewer");
		this->showNormal();
	}

	PGBaseViewer::~PGBaseViewer(){

	}

	void PGBaseViewer::resizeGL(int w, int h)
	{
		if(h == 0){
			h = 1;
		}

		glViewport(0, 0, w, h);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f,(GLfloat)w/(GLfloat)h, 0.1f, 100.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void PGBaseViewer::initializeGL(){
		glShadeModel(GL_SMOOTH);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	}

	void PGBaseViewer::paintGL(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glTranslatef(-1.5f, 0.0f, -6.0f);	// Move Left 1.5 Units And Into The Screen 6.0

		glBegin(GL_TRIANGLES);				// Drawing Using Triangles
			glVertex3f( 0.0f, 1.0f, 0.0f);		// Top
			glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left
			glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
		glEnd();							// Finished Drawing The Triangle

		glTranslatef(3.0f,0.0f,0.0f);		// Move Right 3 Units

		glBegin(GL_QUADS);					// Draw A Quad
			glVertex3f(-1.0f, 1.0f, 0.0f);		// Top Left
			glVertex3f( 1.0f, 1.0f, 0.0f);		// Top Right
			glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
			glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left
		glEnd();							// Finished Drawing The Quad
	}

	void PGBaseViewer::keyPressEvent(QKeyEvent *event){
		switch(event->key()){
			case Qt::Key_F2:{
				m_fullscreen = !m_fullscreen;
				if(m_fullscreen){
					showFullScreen();
				} else{
					showNormal();
				}
				updateGL();
				break;
			}
			case Qt::Key_Escape:{
				qApp->exit();
				break;
			}
		}
	}
}
