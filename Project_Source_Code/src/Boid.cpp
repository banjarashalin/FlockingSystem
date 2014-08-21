#include "Flock.h"
#include "math.h"
#include <ngl/VBOPrimitives.h>


Boid::Boid(ngl::Vector _pos,ngl::Vector _vel)
{
  // set values from params
  m_pos = _pos;
  m_vel = _vel;
}

Boid::Boid()
{
        //m_hit=false;
}

void Boid::move(double _minspeed, double _maxspeed)
{

  m_lastPos=m_pos;
  if (m_vel.length() > _maxspeed)
  {
      m_vel.normalize();
      m_vel=m_vel*_maxspeed;
      //std::cout << "m_vel  ::  " << m_vel.length() << std::endl;
  }
  else if (m_vel.length() < _minspeed)
  {
      m_vel.normalize();
      m_vel=m_vel*_minspeed;
  }
  m_pos+=(m_vel);
  // get the next position
  m_nextPos=m_pos+(m_vel);
}

void Boid::rotate()
{
    ngl::Vector d =  m_pos - m_lastPos;
    float r = d.length();
    float phi = (asin(d.m_y/r) * (180/M_PI));
    float theta = (atan2(d.m_z,d.m_x) * (180/M_PI));
    m_rotation.set(0,-theta,phi,1);
}



void Boid::draw(const std::string  &_shaderName,ngl::TransformStack &_transformStack, double _scale, std::string _boidtype)const
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  ngl::ShaderManager *shader=ngl::ShaderManager::instance();
  // grab an instance of the primitives for drawing
  ngl::VBOPrimitives *prim=ngl::VBOPrimitives::instance();

        _transformStack.pushTransform();
        {
               _transformStack.getCurrentTransform().setRotation(m_rotation);
                _transformStack.getCurrentTransform().setPosition(m_pos);
                _transformStack.getCurrentTransform().setScale(_scale,_scale,_scale);


                shader->setShaderParamFromMatrix(_shaderName,"ModelMatrix",_transformStack.getCurrAndGlobal().getMatrix());
                if (_boidtype == "Sphere")
                {
                    prim->draw("boid");
                }
                else if (_boidtype == "Pyramid")
                {
                    prim->draw("tetrahedron");
                }
                else
                {
                    prim->draw("teapot");
                }

        } // and before a pop
   _transformStack.popTransform();
}
