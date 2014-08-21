#ifndef __GL_WINDOW_H__
#define __GL_WINDOW_H__
//files to be included

#include "Flock.h"
#include <ngl/BBox.h>

#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/TransformStack.h>
#include <ngl/Vector.h>

// must be included after our stuff becuase GLEW needs to be first
#include <QtOpenGL>

//.............................. CLASS DEFINATION ...................................................................//

class GLWindow : public QGLWidget

{

Q_OBJECT        // must include this if you use Qt signals/slots

public :

        /// @brief Constructor for GLWindow
        /// @param [in] _numSpheres the number of spheres to create passed from
        /// main window and main(argv[1])
        /// @param [in] parent the parent window to create the GL context in

            GLWindow(int _numSpheres,QWidget *_parent); // constructor for GLWindow

            ~GLWindow(); // destructor for GLWindow

        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief toggle the Animation of the lights called from main window

                            inline void toggleAnimation(){m_animate^=true;}
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief method called from main window for keyPress

                            void keyPress(QKeyEvent *_event);
        ///------------------------------------------------------------------------------------------------------------------

public slots :
                            void setFlockAlignmentWeight (double _alignWeight);
                            void setFlockSeperationWeight (double _seperateWeight);
                            void setFlockCohesionWeight (double _cohesionWeight);
                            void setFlockNeighboutDistance (double _neighbourdistance);
                            void setFlockSeperateDistance (double _seperatedistance);
                            void setMinSpeed(double _minspeed);
                            void setMaxSpeed(double _maxspeed);
                            void addBoids(int i);
                            void removeBoids( int i);
                            void setboidScale (double _boidscale);
                            void setboidType (std::string _boidtype);
                            void resetBoids();







protected:

        /// @brief  The following methods must be implimented in the sub class
        /// this is called when the window is created
                            void initializeGL();
        ///------------------------------------------------------------------------------------------------------------------------

        /// @brief this is called whenever the window is re-sized
        /// @param[in] _w the width of the resized window
        /// @param[in] _h the height of the resized window
                            void resizeGL(const int _w,const int _h);
        ///------------------------------------------------------------------------------------------------------------------------

        /// @brief this is the main gl drawing routine which is called whenever the window needs to
        /// be re-drawn
                            void paintGL();
        ///------------------------------------------------------------------------------------------------------------------------

private :

                        float m_minSpeed;
                        float m_maxSpeed;
                        double m_boidScale;
                        std::string m_boidtype;

        /// @brief used to store the x rotation mouse value
                            int m_spinXFace;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief used to store the y rotation mouse value
                            int m_spinYFace;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief flag to indicate if the mouse button is pressed when dragging
                            bool m_rotate;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief the previous x mouse value
                            int m_origX;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief the previous y mouse value
                            int m_origY;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief Our Camera
                            ngl::Camera *m_cam;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief timer to change the sphere position by calling update()
                            int m_sphereUpdateTimer;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief our transform stack for drawing the teapots
                            ngl::TransformStack m_transformStack;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief flag to indicate if animation is active or not
                            bool m_animate;
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief a dynamic array to contain our Boids
                            std::vector <Boid> m_boidArray;

        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief the bounding box to contain the Boids
                            ngl::BBox *m_bbox;
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief flag to indicate if we need to do spheresphere checks
                            bool m_checkBoidBoid;
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief the number of Boids we are creating
                            int m_numBoids;
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief this method is called once per frame to update the sphere positions
        /// and do the collision detection
                            void update();
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief this method is called every time a mouse is moved
        /// @param _event the Qt Event structure
                            void mouseMoveEvent (QMouseEvent * _event);
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief this method is called everytime the mouse button is pressed
        /// inherited from QObject and overridden here.
        /// @param _event the Qt Event structure
                            void mousePressEvent (QMouseEvent *_event);
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief this method is called everytime the mouse button is released
        /// inherited from QObject and overridden here.
        /// @param _event the Qt Event structure
                            void mouseReleaseEvent (QMouseEvent *_event);
        ///----------------------------------------------------------------------------------------------------------------------

        /// @brief the timer event triggered from the timers
        /// @param _even the event of the timer triggered by Qt
                            void timerEvent(QTimerEvent *_event);
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief check the collisions
                            void checkCollisions();
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief do the actual sphereSphere collisions
        /// @param[in] _pos1 the position of the first sphere
        /// @param[in] _radius1 the radius of the first sphere
        /// @param[in] _pos2 the position of the second sphere
        /// @param[in] _radius2 the radius of the second sphere
                            bool sphereSphereCollision(ngl::Vector _pos1,GLfloat _radius1,ngl::Vector _pos2,GLfloat _radius2);
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief check the bounding box collisions
                            void BBoxCollision();
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief reset the Boid array
                           // void resetBoids();
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief add a new Boid
                            void addBoid();
        //----------------------------------------------------------------------------------------------------------------------

        /// @brief remove the last Boid added
                            void removeBoid();
        ///----------------------------------------------------------------------------------------------------------------------

};

#endif

