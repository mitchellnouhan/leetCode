class Logger {
public:
    int wait;
    unordered_map<string, int> message_to_printTime;

    Logger() {
        this -> wait = 10;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(message_to_printTime.count(message) && timestamp < message_to_printTime[message]){
            return false;
        }
        message_to_printTime[message] = timestamp + this -> wait;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */