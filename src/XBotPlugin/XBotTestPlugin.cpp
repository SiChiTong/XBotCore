#include <XBotPlugin/XBotTestPlugin.h>

XBot::XBotTestPlugin::XBotTestPlugin(std::string name,
                                     std::shared_ptr<XBot::IXBotModel> model, 
                                     std::shared_ptr<XBot::IXBotChain> chain) : 
                                     XBotPlugin(name, model, chain)
{

}


bool XBot::XBotTestPlugin::init(void)
{
    DPRINTF("XBotTestPlugin init()\n");
    std::map<int, float> l_arm_link_pos;
    chain->get_chain_link_pos("left_arm", l_arm_link_pos);
    for( auto& j : l_arm_link_pos) {
        DPRINTF("l_arm_link_pos Joint : %d - link pos : %f\n", j.first, j.second);
        l_arm_pos_ref[j.first] = j.second;
    }
    DPRINTF("27_link_pos : %f\n", l_arm_link_pos.at(27));
    l_arm_pos_ref[27] = l_arm_link_pos.at(27) + 0.05;
    
    return true;
}

void XBot::XBotTestPlugin::run(void)
{  
    std::map<int, uint16_t> l_hand_j_rtt;
    chain->get_chain_rtt("left_hand", l_hand_j_rtt);

    for( auto& j : l_hand_j_rtt) {
//         DPRINTF("left_hand Joint : %d - RTT : %d\n", j.first, j.second); // NOTE avoid printing std::string with XENOMAI printf 
    }
    
    std::map<std::string, uint16_t> l_arm_rtt;
    chain->get_chain_rtt("left_arm", l_arm_rtt);

    for( auto& j : l_arm_rtt) {
        std::string j_name = j.first;
        int rtt = j.second;
        int rid = model->joint2Rid(j_name);
//         DPRINTF("left_arm Joint : %d - RTT : %d\n", rid, rtt); // NOTE avoid printing std::string with XENOMAI printf 
    }
    
    std::map<std::string, uint16_t> l_arm_temperature;
    chain->get_chain_max_temperature("left_arm", l_arm_temperature);

    for( auto& j : l_arm_temperature) {
//         DPRINTF("Joint : %d - TEMPERATURE : %d\n",  model->joint2Rid(j.first), j.second); // NOTE avoid printing std::string with XENOMAI printf 
    }
    
    std::map<std::string, int16_t> l_arm_torque;
    chain->get_chain_torque("left_arm", l_arm_torque);

    for( auto& j : l_arm_torque) {
//         DPRINTF("Joint : %d - TORQUE : %d\n", model->joint2Rid(j.first), j.second); // NOTE avoid printing std::string with XENOMAI printf 
    }
    
    

    // NOTE move commented out
    chain->set_chain_pos_ref("left_arm", l_arm_pos_ref);

   
}

bool XBot::XBotTestPlugin::close(void)
{
    DPRINTF("XBotTestPlugin close()\n");
}