#ifndef __BOID_H__
#define __BOID_H__

#include <ngl/ShaderManager.h>
#include <ngl/TransformStack.h>
#include <ngl/Matrix.h>
#include <ngl/Vector.h>

#ifdef LINUX
        #include <GL/glew.h>
        #include <GL/gl.h>
#endif
#ifdef DARWIN
        #include <OpenGL/gl.h>
#endif


/*! @brief a simple Boid class */
class Boid
{
public :
        /// @brief ctor
        /// @param[in] _pos the position of the boid
        /// @param[in] _vel the velocity of the boid

                    Boid(ngl::Vector _pos,ngl::Vector _vel);
                    Boid();


        /// @brief draw method
        /// @param[in] &_shaderName
        /// @param[in] &_transformStack stores the transformation Matrix for the boid
        /// @param[in] _boidtype sotres the type of boid to be drawn


                    void draw(const std::string &_shaderName,ngl::TransformStack &_transformStack, double _scale,std::string _boidtype) const ;

        /// @brief move method
        /// @param[in] _minspeed minimum speed
        /// @param[in] _maxspeed maximum speed

                    void move(double _minspeed, double _maxspeed);

        /// @brief rotate method to set the rotation values for the boids

                    void rotate();

        /// @brief get position method

             inline ngl::Vector getPos() const {return m_pos;}

        /// @brief get nest position method

             inline ngl::Vector getNextPos() const {return m_nextPos;}

        /// @brief set the velocity of the boid
        /// @param[in] _v velocity to be assigned

             inline void setVelocity(ngl::Vector _v){m_vel=_v;}

        /// @brief update the velocity
        /// @param[in] _v velocity to be added to the current velocity

            inline void updateVelocity(ngl::Vector _v){m_vel+=_v;}

        /// @brief get Velocity of the boid

            inline ngl::Vector getVelocity() const {return m_vel;}

private :
        /// @brief used to store the postion of the boid
                    ngl::Vector m_pos;
        //----------------------------------------------------------------------------------------------------------------------------------------------------

        /// @brief used to store the velocity of the boid
                    ngl::Vector m_vel;
        //----------------------------------------------------------------------------------------------------------------------------------------------------

        /// @brief used to store the last position of the boid
                    ngl::Vector m_lastPos;
        //----------------------------------------------------------------------------------------------------------------------------------------------------

        /// @brief used to store the next position of the boid
                    ngl::Vector m_nextPos;
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        /// @brief used to store the rotation vaues of the boid
                 ngl::Vector m_rotation;
        //----------------------------------------------------------------------------------------------------------------------------------------------------

};

#endif
