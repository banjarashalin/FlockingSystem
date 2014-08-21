#include "Flock.h"
#include "ngl/Vector.h"
#include "ngl/Random.h"
#include <boost/foreach.hpp>
#include <Boid.h>

//float s = 360;

Flock* Flock::m_pinstance = 0;// initialize pointer

Flock* Flock::getInstance()
{
  if (m_pinstance == 0)  // is it the first call?
  {
    m_pinstance = new Flock; // create sole instance
  }
  return m_pinstance; // address of sole instance
}

//void Flock::findNeighbours (int _currentBoidNumber,std::vector <Boid> _boidarray)
//{
//    ngl::Vector distance = 0;
//    GLdouble angle = 0;
//    m_neighbourArray =  _boidarray;
//    _boidarray.clear();
//    ngl::Vector _tempPos = m_neighbourArray[_currentBoidNumber].getPos();
//    m_neighbourArray.erase(m_neighbourArray.begin() + _currentBoidNumber);
//    int i = 1;
//    BOOST_FOREACH(Boid &b, m_neighbourArray)
//    {
//        distance = 0;
//        distance = _tempPos - &b.getPos();
//        angle = 0;
//        angle = _tempPos.angleBetween(&b.getPos()) * 180/M_PI;
//        if (distance.length() < m_neighbour_distance)
//        {
//            ++i;
//        }
//        else
//        {
//            m_neighbourArray.erase(m_neighbourArray.begin()+ i);
//            ++i;
//        }
//     }
//}

void Flock::Cohesion (int i, std::vector <Boid> m_boidArray)
{
    m_cohesion = 0;
    m_cohesion = 0;
    ngl::Vector distance = 0;
    int a =0;
    int b=1;
 int size=m_boidArray.size();

for (a=0;a<size;++a)
 {
        if (a!=i)
     {
          distance = m_boidArray[i].getPos() - m_boidArray[a].getPos();

          if (distance.length() < m_neighbour_distance)

         {
                m_cohesion=m_cohesion + m_boidArray[a].getPos();
                ++b;

            }
     }
        }
m_cohesion=m_cohesion/(b);
m_cohesion=(m_cohesion-m_boidArray[i].getPos())/100;
}
void Flock::Alignment (int i, std::vector <Boid> m_boidArray)
{
    m_alignment=0;
ngl::Vector distance = 0;
    int a =0;
    int b = 1;
 int size=m_boidArray.size();
 for (a=0;a<size;++a)

 {
        if (a!=i)
     {
            distance = m_boidArray[i].getPos() - m_boidArray[a].getPos();

             if (distance.length() < m_neighbour_distance)

            {
            m_alignment = m_alignment+ m_boidArray[a].getVelocity();
            ++b;
        }
     }
}

 m_alignment = m_alignment/(b);
 m_alignment=m_alignment-m_boidArray[i].getVelocity()/8;
}

void Flock::Seperation (int i, std::vector <Boid> m_boidArray)
{
    m_seperation=0;
    ngl::Vector distance = 0;
    int a =0;
 int size=m_boidArray.size();
 for (a=0;a<size;++a)
 {
        if (a!=i)
        {
             distance = m_boidArray[i].getPos() - m_boidArray[a].getPos();

             if (distance.length()< m_seperation_distance)
         {
                    m_seperation = m_seperation - (m_boidArray[i].getPos()- m_boidArray[a].getPos());
         }

 }
}
}

ngl::Vector Flock::calculateVelocity()
{
    ngl::Vector _finalvelocity=0;

    _finalvelocity = ((-1 * (m_seperation_weight/100))*m_seperation)+ ((m_cohesion_weight/100) * m_cohesion) + ((m_alignment_weight/100) * m_alignment);

    if (_finalvelocity.length() > 0.8)
    {
        _finalvelocity.normalize();
        _finalvelocity = _finalvelocity * 0.8;
    }

    return _finalvelocity;
}
