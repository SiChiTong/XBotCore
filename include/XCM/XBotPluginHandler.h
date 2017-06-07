/*
 * Copyright (C) 2017 IIT-ADVR
 * Author: Arturo Laurenzi, Luca Muratore
 * email:  arturo.laurenzi@iit.it, luca.muratore@iit.it
 *
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


#ifndef __XCM_XBOT_PLUGIN_HANDLER_H__
#define __XCM_XBOT_PLUGIN_HANDLER_H__

#include <XBotCore-interfaces/All.h>

#include <XCM/XBotControlPlugin.h>
#include <XCM/TimeProvider.h>
#include <XCM/XBotESCUtils.h>

#include <SharedLibraryClassFactory.h>
#include <SharedLibraryClass.h>

namespace XBot {

    class PluginHandler {

    public:

        typedef std::shared_ptr<PluginHandler> Ptr;

        PluginHandler(RobotInterface::Ptr robot, TimeProvider::Ptr time_provider);

        bool load_plugins(const std::string& plugins_set_name);

        bool init_plugins(XBot::SharedMemory::Ptr shared_memory,
                          std::shared_ptr< IXBotJoint> joint    = nullptr,
                          std::shared_ptr< IXBotFT > ft         = nullptr,
                          std::shared_ptr< IXBotIMU > imu       = nullptr,
                          std::shared_ptr< IXBotModel > model   = nullptr );

        void run();

        void close();

        ~PluginHandler();

    protected:

    private:

        bool init_xddp();
        void run_xddp();

        void fill_robot_state();

        void run_communication_handler();

        bool plugin_can_start(int plugin_idx);

        static bool computeAbsolutePath ( const std::string& input_path,
                                          const std::string& midlle_path,
                                          std::string& absolute_path ); // TBD do it with UTILS

        XBot::TimeProvider::Ptr _time_provider;

        YAML::Node _root_cfg;

        bool _close_was_called;

        // Dynamic loading related variables
        std::vector<std::shared_ptr<shlibpp::SharedLibraryClassFactory<XBot::XBotControlPlugin>>> _rtplugin_factory;
        std::vector<std::string> _rtplugin_names;
        std::vector<std::shared_ptr<shlibpp::SharedLibraryClass<XBot::XBotControlPlugin>>> _rtplugin_vector;
        std::vector<bool> _plugin_init_success;
        std::vector<XBot::SubscriberRT<XBot::Command>> _plugin_command;
        std::vector<XBot::PublisherRT<XBot::Command>> _plugin_status;
        std::vector<std::string> _plugin_state;
        std::vector<bool> _first_loop;

        std::vector<double> _last_time, _time, _period, _elapsed_time;

        std::map<int, XBot::PublisherRT<XBot::RobotState>> _motor_pub_map;
        std::map<int, XBot::RobotState> _robot_state_map;

        std::map<int, XBot::PublisherRT<XBot::RobotFT::pdo_rx>> _ft_pub_map;
        std::map<int, XBot::RobotFT::pdo_rx> _ft_state_map;

        std::map<int, XBot::PublisherRT<XBot::RobotIMU::pdo_rx>> _imu_pub_map;
        std::map<int, XBot::RobotIMU::pdo_rx> _imu_state_map;

        XBot::ESCUtils _esc_utils;

        int _communication_plugin_idx;
        int _logging_plugin_idx;

        RobotInterface::Ptr _robot;
        std::string _path_to_cfg;
        
        bool _is_RT_plugin_handler = false;
    };
}
#endif
