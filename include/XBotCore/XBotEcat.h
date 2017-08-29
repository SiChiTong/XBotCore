/*
   Copyright (C) 2016 Italian Institute of Technology

   Developer:
       Luca Muratore (2016-, luca.muratore@iit.it)
       
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>       
   
*/

/**
 *
 * @author Luca Muratore (2016-, luca.muratore@iit.it)
*/

#ifndef __X_BOT_ECAT_H__
#define __X_BOT_ECAT_H__

//#include <iit/advr/ec_boards_base.h>
#include <XBotCore-interfaces/XBotESC.h>
#include <ec_boards_base.h>
// #include <XBotCore-interfaces/IXBotJoint.h>
// #include <XBotCore-interfaces/IXBotFT.h>
// #include <XBotCore-interfaces/IXBotIMU.h>
// #include <XBotInterface/RobotInterface.h>
// #include <XBotCore-interfaces/IXBotHand.h>

namespace XBot
{
    class XBotEcat;
}

/**
 * @brief XBotCore EtherCAT class.
 * 
 */
class XBot::XBotEcat : public Ec_Thread_Boards_base
                      
{
public:
    
    XBotEcat(const char * config_yaml);
    virtual ~XBotEcat();
   
    /**
     * @brief initialization function called before the EtherCAT OPERATIONAL state : overridden from Ec_Thread_Boards_base
     * 
     * @param  void
     * @return void
     */
    virtual void init_preOP(void) final;
    
    /**
     * @brief initialization function called just after the EtherCAT OPERATIONAL state , it calls the control_init function: overridden from Ec_Thread_Boards_base
     * 
     * @param  void
     * @return void
     */
    virtual void init_OP(void) final;
     
    /**
     * @brief Simply call the control loop function that will be implemented by the derived class: overridden from Ec_Thread_Boards_base
     * 
     * @param  void
     * @return 1 on plugin_handler_loop() success. 0 otherwise
     */
//     virtual int user_loop(void) final;
        
    /**
     * @brief Getter for the thread name
     * 
     * @param  void
     * @return std::string the thread name
     */
//     std::string get_thread_name(void);


protected:
    
    /**
     * @brief Robot control initialization function: called by the init_OP, before the ECAT thread loop: we are in OPERATIE state
     * 
     * @param  void
     * @return void
     */
//     virtual void control_init(void) = 0;

    /**
     * @brief Robot control loop
     * 
     * @param  void
     * @return 1 on success. 0 otherwise
     */
//     virtual int control_loop(void) = 0;
        


private:   
    
    /**
     * @brief The thread name
     * 
     */
//     std::string thread_name;
    
    /**
     * @brief SDO info XDDP Pipes
     * 
     */
//     std::map<int, std::shared_ptr<XDDP_pipe> > sdo_xddps;
    
    /**
     * @brief initialize the SDO XDDP pipes
     * 
     * @return void
     */
//     void init_sdo_xddp();
    
    /**
     * @brief write the sdo_info of the motor boards to the SDP XDDP pipes
     * 
     * @return void
     */
//     void write_sdo_info();
        
    /**
     * @brief Setter for the thread name
     * 
     * @param  std::string the thread name
     * @return void
     */
//     void set_thread_name(std::string);
        
    /**
     * @brief Setter for the thread period
     * 
     * @param  t the task period
     * @return void
     */
//     void set_thread_period(task_period_t t);
    
    /**
     * @brief Setter for the thread priority: RT thread
     * 
     * @param void
     * @return void
     */
//     void set_thread_priority();
    
    //     // NOTE IXBotHand getters/setters
    virtual double get_grasp_state(int hand_id){};
    virtual bool   grasp(int hand_id, double grasp_percentage){};
//     
//     // NOTE IXBotFT getters
    virtual bool get_ft(int ft_id, std::vector< double >& ft, int channels = 6) {};
    virtual bool get_ft_fault(int ft_id, double& fault) {};
    virtual bool get_ft_rtt(int ft_id, double& rtt) {};
//     
//     // NOTE IXBotIMU getters
    virtual bool get_imu(int imu_id, std::vector< double >& lin_acc, std::vector< double >& ang_vel, std::vector< double >& quaternion){};
    virtual bool get_imu_fault(int imu_id, double& fault){};
    virtual bool get_imu_rtt(int imu_id, double& rtt){};

    
    // NOTE IXBotJoint getters
    virtual bool get_link_pos(int joint_id, double& link_pos) {std::cout<<"getlinkpos ECAT"<<std::endl;};
    
    virtual bool get_motor_pos(int joint_id, double& motor_pos) {};
    
    virtual bool get_link_vel(int joint_id, double& link_vel) {};
    
    virtual bool get_motor_vel(int joint_id, double& motor_vel) {};
    
    virtual bool get_torque(int joint_id, double& torque) {};
    
    virtual bool get_temperature(int joint_id, double& temperature) {};
    
    virtual bool get_fault(int joint_id, double& fault) {};
    
    virtual bool get_rtt(int joint_id, double& rtt) {};
    
    virtual bool get_op_idx_ack(int joint_id, double& op_idx_ack) {};
    
    virtual bool get_aux(int joint_id, double& aux) {};
    
    virtual bool get_gains(int joint_id, std::vector< double >& gain_vector) {};
//     
//     // NOTE IXBotJoint setters
    virtual bool set_pos_ref(int joint_id, const double& pos_ref) {};
    
    virtual bool set_vel_ref(int joint_id, const double& vel_ref) {};
    
    virtual bool set_tor_ref(int joint_id, const double& tor_ref) {};
    
    virtual bool set_gains(int joint_id, const std::vector<double>& gains) {};
    
    virtual bool set_fault_ack(int joint_id, const double& fault_ack) {};
    
    virtual bool set_ts(int joint_id, const double& ts) {};
    
    virtual bool set_op_idx_aux(int joint_id, const double& op_idx_aux) {};
    
    virtual bool set_aux(int joint_id, const double& aux) {};

};

#endif //__X_BOT_ECAT_H__
