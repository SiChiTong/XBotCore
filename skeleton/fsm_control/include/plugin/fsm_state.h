\n    class _STATE_PREFIX_ : public MacroState {\n\n      virtual std::string get_name() const { return "_STATE_PREFIX_"; }\n\n      virtual void run(double time, double period);\n\n      virtual void entry(const XBot::FSM::Message& msg);\n\n      virtual void react(const XBot::FSM::Event& e);\n\n      virtual void exit ();\n\n      private:\n\n\n     };