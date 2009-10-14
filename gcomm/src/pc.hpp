
#include "gcomm/transport.hpp"


namespace gcomm
{
    class PCProto;
    namespace evs
    {
        class Proto;
    } // namespace gcomm

    class PC : public Transport
    {
        Transport* tp;  // GMCast transport
        gcomm::evs::Proto*  evs; // EVS protocol layer
        PCProto*   pc;  // PC protocol layer
        
        PC(const PC&);
        void operator=(const PC&);
        
    public:
        
        PC (const URI&, EventLoop*, Monitor*);
        
        ~PC();
        
        void connect();
        void close();
        
        void handle_up(const int, const ReadBuf*, const size_t, 
                       const ProtoUpMeta*);
        int  handle_down(WriteBuf*, const ProtoDownMeta*);
        
        bool supports_uuid() const;
        const UUID& get_uuid() const;
        
        size_t get_max_msg_size() const;
    };
    
} // namespace gcomm
