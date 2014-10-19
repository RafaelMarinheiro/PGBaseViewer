/* 
* @Author: Rafael Marinheiro
* @Date:   2014-10-18 22:50:47
* @Last Modified by:   Rafael Marinheiro
* @Last Modified time: 2014-10-18 23:43:23
*/

#ifndef PG_BASE_VIEWER_H
#define PG_BASE_VIEWER_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>

namespace pg{
	class PGBaseViewer : public QGLWidget{
	Q_OBJECT

	public:
		explicit PGBaseViewer(QWidget *parent = 0);
	    ~PGBaseViewer();

	protected:
		//This method handles window resizing
		void resizeGL(int w, int h);

		//This method handles OpenGL initialization
		void initializeGL();

		//This method handle gl painting
		//It will be called after updateGL() is called
		void paintGL();
		void keyPressEvent(QKeyEvent *event);

	private:
		bool m_fullscreen;
	};
}

#endif // PG_BASE_VIEWER_H