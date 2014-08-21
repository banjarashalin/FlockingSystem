#include "GLWindow.h"
#include <iostream>
#include "ngl/Camera.h"
#include "ngl/Light.h"
#include "ngl/Matrix.h"
#include "ngl/Transformation.h"
#include "ngl/TransformStack.h"
#include "ngl/Material.h"
#include "ngl/NGLInit.h"
#include "ngl/VBOPrimitives.h"
#include "ngl/ShaderManager.h"
#include "ngl/Random.h"
#include <boost/foreach.hpp>
#include "ngl/Util.h"
#include "Flock.h"

//-------------------------------------------------------------------------
const static int s_extents=25;
Flock* flockdata= Flock::getInstance();
//-------------------------------------------------------------------------
GLWindow::GLWindow(int _numBoids,QWidget *_parent) : QGLWidget(_parent)
{
    m_maxSpeed = 0.7;
    m_minSpeed = 0.1;
    // set this widget to have the initial keyboard focus
    setFocus();
    // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
    this->resize(_parent->size());
    // Now set the initial GLWindow attributes to default values
    // Roate is false
    m_rotate=false;
    // mouse rotation values set to 0
    m_spinXFace=0;
    m_spinYFace=0;
    m_origX=0;
    m_origY=0;
    m_sphereUpdateTimer=startTimer(40);
    m_animate=false;
          m_checkBoidBoid=true;
          // now create the actual spheres for our program
          m_bbox = new ngl::BBox(ngl::Vector(0,0,0),60,60,60);
          // create vectors for the position and direction
          m_numBoids=_numBoids;
    resetBoids();
}

void GLWindow::resetBoids()
{
        std::vector<Boid>::iterator begin=m_boidArray.begin();
        std::vector<Boid>::iterator end=m_boidArray.end();
  m_boidArray.erase(begin,end);
        ngl::Vector pos(0,0,0);
  ngl::Vector vel;
        ngl::Random *rng=ngl::Random::instance();
        // loop and create the initial particle list
        for(int i=0; i<m_numBoids; ++i)
        {
                vel=rng->getRandomVector();
                // add the boids to the end of the particle list
                m_boidArray.push_back(Boid(rng->getRandomPoint(s_extents,s_extents,s_extents),vel));
        }

}

GLWindow::~GLWindow()
{
  ngl::NGLInit *Init = ngl::NGLInit::instance();
  std::cout<<"Shutting down NGL, removing VBO's and Shaders\n";
  Init->NGLQuit();
}

// This virtual function is called once before the first call to paintGL() or resizeGL(),
//and then once whenever the widget has been assigned a new QGLContext.
// This function should set up any required OpenGL context rendering flags, defining display lists, etc.

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
  // create the lights

  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
   glEnable(GL_DEPTH_TEST);
   // Now we will create a basic Camera from the graphics library
   // This is a static camera so it only needs to be set once
   // First create Values for the camera position
   ngl::Vector From(70,70,70);
   ngl::Vector To(0,0,0);
   ngl::Vector Up(0,1,0);
   ngl::NGLInit *Init = ngl::NGLInit::instance();
   Init->initGlew();
   m_cam= new ngl::Camera(From,To,Up,ngl::PERSPECTIVE);
   // set the shape using FOV 45 Aspect Ratio based on Width and Height
   // The final two are near and far clipping planes of 0.5 and 10
   m_cam->setShape(45,(float)1280.0/720.0,0.5,150,ngl::PERSPECTIVE);
   // now to load the shader and set the values
   // grab an instance of shader manager
   ngl::ShaderManager *shader=ngl::ShaderManager::instance();
   // load a frag and vert shaders
   shader->loadShader("gl3xTest","shaders/Vertex.vs","shaders/Fragment.fs");
   // set this as the active shader
   shader->useShader("gl3xTest");
   // now pass the modelView and projection values to the shader
   shader->setShaderParamFromMatrix("gl3xTest","ViewMatrix",m_cam->getModelView());
   shader->setShaderParamFromMatrix("gl3xTest","projectionMatrix",m_cam->getProjection());
   shader->setShaderParam1i("gl3xTest","Normalize",true);
   shader->setShaderParam1i("gl3xTest","numLightsEnabled",1);

   glEnable(GL_DEPTH_TEST); // for removal of hidden surfaces

   ngl::VBOPrimitives *prim =  ngl::VBOPrimitives::instance();
   prim->createVBOSphere("boid",0.3,8);
  // prim->draw("teapot");
   //prim->createVBOQuadPlane("plane",60,60,30,30,ngl::Vector(0,1,0));

         shader->loadShader("Colour","shaders/Colour.vs","shaders/Colour.fs");

                 // set this as the active shader
           shader->useShader("Colour");
                 shader->setShaderParamFromMatrix("Colour","ViewMatrix",m_cam->getModelView());
           shader->setShaderParamFromMatrix("Colour","projectionMatrix",m_cam->getProjection());

                 shader->setShaderParam4f("Colour","Colour",1,0,1,1);


}

//This virtual function is called whenever the widget has been resized.
// The new size is passed in width and height.
void GLWindow::resizeGL(int _w,int _h)
{
  glViewport(0,0,_w,_h);
   m_cam->setShape(45,(float)_w/_h,0.001,500,ngl::PERSPECTIVE);
  ngl::ShaderManager *shader=ngl::ShaderManager::instance();
  (*shader)["gl3xTest"]->use();
        shader->setShaderParamFromMatrix("gl3xTest","projectionMatrix",m_cam->getProjection());
  (*shader)["Colour"]->use();
        shader->setShaderParamFromMatrix("Colour","projectionMatrix",m_cam->getProjection());

}

//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
void GLWindow::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 // build our transform stack
  ngl::Transformation trans;
  // set the mouse rotation
  trans.setRotation(m_spinXFace,m_spinYFace,0);
  // set this in the TX stack
  m_transformStack.setGlobal(trans);
ngl::VBOPrimitives *prim =  ngl::VBOPrimitives::instance();
  // grab an instance of the primitives for drawing
  //ngl::VBOPrimitives *prim=ngl::VBOPrimitives::instance();
  // Rotation based on the mouse position for our global
  // transform
  // grab an instance of the shader manager
  ngl::ShaderManager *shader=ngl::ShaderManager::instance();
  (*shader)["Colour"]->use();
        m_transformStack.loadGlobalAndCurrentMatrixToShader("Colour","ModelMatrix");

        m_bbox->draw();

        shader->use("gl3xTest");
        ngl::Material m(ngl::BRASS);
        m.use();

        m_transformStack.loadGlobalAndCurrentMatrixToShader("gl3xTest","ModelMatrix");
  shader->setShaderParamFromMatrix("gl3xTest","ModelMatrix",m_transformStack.getCurrAndGlobal().getMatrix());
        BOOST_FOREACH(Boid b, m_boidArray)
        {
                //m_transformStack.getCurrentTransform().setMatrix(b.m_rotation);;
                b.draw("gl3xTest",m_transformStack,m_boidScale,m_boidtype);
        }

}

void GLWindow::update()
{

    //std::vector <Boid> m_neighbourArray;
    int i=0;

    BOOST_FOREACH(Boid &b, m_boidArray)
    {
        flockdata->Cohesion(i,m_boidArray);
        flockdata->Alignment(i,m_boidArray);
        flockdata->Seperation(i,m_boidArray);
        b.updateVelocity(flockdata->calculateVelocity());
        //checkCollisions();
        b.rotate();
        b.move(m_minSpeed,m_maxSpeed);
        ++i;
    }
      checkCollisions();
}


void  GLWindow::checkCollisions()
{
        BBoxCollision();
}

void GLWindow::BBoxCollision()
{
  //create an array of the extents of the bounding box
  float ext[6];
  ext[0]=ext[1]=(m_bbox->height()/2.0f);
  ext[2]=ext[3]=(m_bbox->width()/2.0f);
  ext[4]=ext[5]=(m_bbox->depth()/2.0f);
  // Dot product needs a Vector so we convert The Point Temp into a Vector so we can
  // do a dot product on it
  ngl::Vector p;
  // D is the distance of the Agent from the Plane. If it is less than ext[i] then there is
  // no collision
  GLfloat D;
  // Loop for each sphere in the vector list
  BOOST_FOREACH(Boid &b, m_boidArray)
  {
    p=b.getNextPos();
    //Now we need to check the Sphere agains all 6 planes of the BBOx
    //If a collision is found we change the dir of the Sphere then Break
    for(int i=0; i<6; ++i)
    {
      //to calculate the distance we take the dotporduct of the Plane Normal
      //with the new point P
      D=m_bbox->getNormalArray()[i].dot(p);
      //Now Add the Radius of the sphere to the offsett
      D+=3;
      // If this is greater or equal to the BBox extent /2 then there is a collision
      //So we calculate the Spheres new direction
      if(D >=ext[i])
      {
        //We use the same calculation as in raytracing to determine the
        // the new direction300
        GLfloat x= 2*( b.getVelocity().dot((m_bbox->getNormalArray()[i])));
        ngl::Vector d =m_bbox->getNormalArray()[i]*x;
        b.setVelocity(b.getVelocity()-d);
        //b.setHit();
      }//end of hit test
     }//end of each face test
    }//end of for
//    std::cout<<"m_bbox->maxX() :: "<<m_bbox->maxX()<<std::endl;
//    std::cout<<"m_bbox->minX() :: "<<m_bbox->minX()<<std::endl;
//    std::cout<<"m_bbox->maxY() :: "<<m_bbox->maxY()<<std::endl;
//    std::cout<<"m_bbox->minY() :: "<<m_bbox->minY()<<std::endl;
//    std::cout<<"m_bbox->maxZ() :: "<<m_bbox->maxZ()<<std::endl;
//    std::cout<<"m_bbox->minZ() :: "<<m_bbox->minZ()<<std::endl;
//    BOOST_FOREACH(Boid &b, m_boidArray)
//    {
//        float min = -30;
//        float max = 30;
//        ngl::Vector force = b.getVelocity();
//        ngl::Vector pos = b.getPos();
//                if (pos.m_x < min)
//                {
//                    force.m_x = 1;
//                }
//                if (pos.m_y < min)
//                {
//                    force.m_y = 1;
//                }
//                if (pos.m_z < min)
//                {
//                    force.m_z = 1;
//                }
//                if (pos.m_x > max)
//                {
//                    force.m_x = -1;
//                }
//                if (pos.m_y > max)
//                {
//                    force.m_y = -1;
//                }
//                if (pos.m_z > max)
//                {
//                    force.m_z = -1;
//                }
//                b.updateVelocity(0.001*force);
//        }
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseMoveEvent (
                               QMouseEvent * _event
                              )
{
  // note the method buttons() is the button state when event was called
  // this is different from button() which is used to check which button was
  // pressed when the mousePress/Release event is generated
  if(m_rotate && _event->buttons() == Qt::LeftButton)
  {
    m_spinYFace = ( m_spinYFace + (_event->x() - m_origX) ) % 360 ;
    m_spinXFace = ( m_spinXFace + (_event->y() - m_origY) ) % 360 ;
    m_origX = _event->x();
    m_origY = _event->y();
  }
  // re-draw GL
  updateGL();
}



//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mousePressEvent (
                                QMouseEvent * _event
                               )
{
  // this method is called when the mouse button is pressed in this case we
  // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
  if(_event->button() == Qt::LeftButton)
  {
    m_origX = _event->x();
    m_origY = _event->y();
    m_rotate =true;
  }
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseReleaseEvent (
                                  QMouseEvent * _event
                                 )
{
  // this event is called when the mouse button is released
  // we then set Rotate to false
  if (_event->button() == Qt::LeftButton)
  {
    m_rotate=false;
  }
}

void GLWindow::timerEvent(
                          QTimerEvent *_event
                         )
{
        if(_event->timerId() == m_sphereUpdateTimer)
        {
                if (m_animate !=true)
                {
                        return;
                }
                update();
                updateGL();
        }
}

void GLWindow::keyPress(QKeyEvent *_event)
{

}
void GLWindow::setFlockAlignmentWeight (double _alignWeight)
{
    flockdata->setalignmentWeight(_alignWeight);

}
void GLWindow::setFlockSeperationWeight (double _seperateWeight)
{
    flockdata->setseperationWeight(_seperateWeight);
    std::cout << "Value changes called :: " << _seperateWeight << std::endl;

}
void GLWindow::setFlockCohesionWeight (double _cohesionWeight)
{
    flockdata->setcohesionWeight(_cohesionWeight);
}

void GLWindow::setFlockNeighboutDistance (double _neighbourdistance)
{
    flockdata->setneighbourDistance(_neighbourdistance);
}

void GLWindow::setFlockSeperateDistance (double _seperatedistance)
{
    flockdata->setseperationDistance(_seperatedistance);
}

void GLWindow::setMinSpeed(double _minspeed)
{
    m_minSpeed = _minspeed;
}

void GLWindow::setMaxSpeed(double _maxspeed)
{
    m_maxSpeed = _maxspeed;
}

void GLWindow::addBoids(int _num)
{

        ngl::Random *rng=ngl::Random::instance();
        ngl::Vector _vel;
        for (unsigned int i =0;i<_num;++i)
        {
        _vel=rng->getRandomVector();
        m_boidArray.push_back(Boid(rng->getRandomPoint(s_extents,s_extents,s_extents),_vel));
        ++m_numBoids;
        }
        updateGL();
}

void GLWindow::removeBoids( int _num)
{
        std::vector<Boid>::iterator end=m_boidArray.end();
        for (unsigned int i = 0; i < _num;++i)
        {
        if(--m_numBoids<3)
        {
                m_numBoids=3;
        }
        else
        {
                m_boidArray.erase(end-1,end);

        }
        }
        updateGL();
        update();
}
void GLWindow::setboidScale (double _boidscale)
{
    m_boidScale = _boidscale;
    updateGL();
}
void GLWindow::setboidType (std::string _boidtype)
{
    m_boidtype = _boidtype;
    updateGL();
}

