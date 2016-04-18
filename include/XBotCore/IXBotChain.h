/*
   Copyright (C) 2016 Italian Institute of Technology

   Developer:
       Luca Muratore (2016-, luca.muratore@iit.it)
   
*/

/**
 *
 * @author Luca Muratore (2016-, luca.muratore@iit.it)
*/

#ifndef __I_X_BOT_CHAIN_H__
#define __I_X_BOT_CHAIN_H__

#include <map>
#include <string>

namespace XBot
{
    class IXBotChain;
}

/**
 * @brief TBD
 * 
 */
class XBot::IXBotChain
{
    
public:   

    // TBD can be auto-generated based on the RX PDO
    // NOTE getters
    virtual bool get_chain_link_pos(std::string chain_name, std::map<std::string, float>& link_pos) = 0;
    virtual bool get_chain_link_pos(std::string chain_name, std::map<int, float>& link_pos) = 0;
    
    virtual bool get_chain_motor_pos(std::string chain_name, std::map<std::string, float>& motor_pos) = 0;
    virtual bool get_chain_motor_pos(std::string chain_name, std::map<int, float>& motor_pos) = 0;
    
    virtual bool get_chain_link_vel(std::string chain_name, std::map<std::string, float>& link_vel) = 0;
    virtual bool get_chain_link_vel(std::string chain_name, std::map<int, float>& link_vel) = 0;
    
    virtual bool get_chain_motor_vel(std::string chain_name, std::map<std::string, int16_t>& motor_vel) = 0;
    virtual bool get_chain_motor_vel(std::string chain_name, std::map<int, int16_t>& motor_vel) = 0;
    
    virtual bool get_chain_torque(std::string chain_name, std::map<std::string, int16_t>& torque) = 0;
    virtual bool get_chain_torque(std::string chain_name, std::map<int, int16_t>& torque) = 0;
    
    virtual bool get_chain_max_temperature(std::string chain_name, std::map<int, uint16_t>& max_temperature) = 0;    
    virtual bool get_chain_max_temperature(std::string chain_name, std::map<std::string, uint16_t>& max_temperature) = 0;
    
    virtual bool get_chain_fault(std::string chain_name, std::map<int, uint16_t>& fault) = 0;    
    virtual bool get_chain_fault(std::string chain_name, std::map<std::string, uint16_t>& fault) = 0;

    virtual bool get_chain_rtt(std::string chain_name, std::map<int, uint16_t>& rtt) = 0;    
    virtual bool get_chain_rtt(std::string chain_name, std::map<std::string, uint16_t>& rtt) = 0;
    
    virtual bool get_chain_op_idx_ack(std::string chain_name, std::map<int, uint16_t>& op_idx_ack) = 0;    
    virtual bool get_chain_op_idx_ack(std::string chain_name, std::map<std::string, uint16_t>& op_idx_ack) = 0;
    
    virtual bool get_chain_aux(std::string chain_name, std::map<std::string, float>& aux) = 0;
    virtual bool get_chain_aux(std::string chain_name, std::map<int, float>& aux) = 0;
    
    
    // TBD can be auto-generated based on the TX PDO
    // NOTE setters
    virtual bool set_chain_pos_ref(std::string chain_name, const std::map<std::string, float>& pos_ref) = 0;
    virtual bool set_chain_pos_ref(std::string chain_name, const std::map<int, float>& pos_ref) = 0;
    
    virtual bool set_chain_vel_ref(std::string chain_name, const std::map<std::string, int16_t>& vel_ref) = 0;
    virtual bool set_chain_vel_ref(std::string chain_name, const std::map<int, int16_t>& vel_ref) = 0;
    
    virtual bool set_chain_tor_ref(std::string chain_name, const std::map<std::string, int16_t>& tor_ref) = 0;
    virtual bool set_chain_tor_ref(std::string chain_name, const std::map<int, int16_t>& tor_ref) = 0;
    
    virtual bool set_chain_gains(std::string chain_name, const std::map<std::string, std::vector<uint16_t> >& gains) = 0;
    virtual bool set_chain_gains(std::string chain_name, const std::map<int, std::vector<uint16_t> >& gains) = 0;
    
    virtual bool set_chain_fault_ack(std::string chain_name, const std::map<std::string, int16_t>& fault_ack) = 0;
    virtual bool set_chain_fault_ack(std::string chain_name, const std::map<int, int16_t>& fault_ack) = 0;
    
    virtual bool set_chain_ts(std::string chain_name, const std::map<int, uint16_t>& ts) = 0;    
    virtual bool set_chain_ts(std::string chain_name, const std::map<std::string, uint16_t>& ts) = 0;
    
    virtual bool set_chain_op_idx_aux(std::string chain_name, const std::map<int, uint16_t>& op_idx_aux) = 0;    
    virtual bool set_chain_op_idx_aux(std::string chain_name, const std::map<std::string, uint16_t>& op_idx_aux) = 0;
    
    virtual bool set_chain_aux(std::string chain_name, const std::map<std::string, float>& aux) = 0;
    virtual bool set_chain_aux(std::string chain_name, const std::map<int, float>& aux) = 0;

};

#endif //__I_X_BOT_CHAIN_H__