#ifndef __FLOCK_H__
#define __FLOCK_H__
//#include <qobject.h>
//#include <QObject>
#include <ngl/ShaderManager.h>
#include <ngl/TransformStack.h>
#include <ngl/Vector.h>
#include "Boid.h"
#ifdef LINUX
        #include <GL/glew.h>
        #include <GL/gl.h>
#endif
#ifdef DARWIN
        #include <OpenGL/gl.h>
#endif

class Flock
{
      private :
                            inline Flock(){;}
                            inline ~Flock(){;}
                                /// @brie private copy ctor so it can't be called
                                //inline Flock( const Flock &_g ){;}
                                static Flock* m_pinstance;

        /// @brief used to store the seperation vector
                    ngl::Vector m_seperation;

        /// @brief used to store the alignment vector
                    ngl::Vector m_alignment;

        /// @brief used to store the cohesion vector
                    ngl::Vector m_cohesion;

        /// @brief used to store the seperation weight
                    double m_seperation_weight;

        /// @brief used to store the cohesion weight
                    double m_cohesion_weight;

        /// @brief used to store the alignment weight
                    double m_alignment_weight;

        /// @brief used to store the distance used to calculate the neighbours
                    double m_neighbour_distance;

        /// @brief used to store the seperation distance used while calculating the seperation
                    double m_seperation_distance;


                    public :

                          static Flock* getInstance();

                        /// @brief Fucntion to calculate the Seperation Rule

                                                        void Seperation(int i, std::vector <Boid> m_boidarray);
                        //----------------------------------------------------------------------------------------------------------------------

                        /// @brief Fucntion to calculate the Cohesion Rule
                                                        void Cohesion(int i,std::vector <Boid> m_boidarray);
                        //----------------------------------------------------------------------------------------------------------------------
                        /// @brief Fucntion to calculate the Alignment Rule
                                                        void Alignment (int i, std::vector <Boid> m_boidarray);
                        //----------------------------------------------------------------------------------------------------------------------


                                            ngl::Vector calculateVelocity();


                                            inline ngl::Vector getSeperation() const {return m_seperation;}
                                            inline ngl::Vector getAlignment() const {return m_alignment;}
                                            inline ngl::Vector getCohesion() const {return m_cohesion;}
                                            inline void setalignmentWeight(double _alignweight) {m_alignment_weight = _alignweight;}
                                            inline void setseperationWeight(double _seperateweight) {m_seperation_weight = _seperateweight;}
                                            inline void setcohesionWeight(double _cohesionweight) {m_cohesion_weight = _cohesionweight;}
                                            inline void setneighbourDistance(double _neighbourdistance) {m_neighbour_distance = _neighbourdistance;}
                                            inline void setseperationDistance(double _seperatedistance) {m_seperation_distance = _seperatedistance;}

};
#endif
