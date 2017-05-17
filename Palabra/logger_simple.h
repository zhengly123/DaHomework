#include<vector>
#include"logger.h"
//µÇÂ½¿ØÖÆ£¨²âÊÔÓÃ)
class LoggerSimple:Logger
{
public:
	LoggerSimple();
	virtual ~LoggerSimple();
	virtual bool Login(const User &user) override;
	virtual bool Signup(const User &user) override;
private:
	std::vector<User> user_list_;
};
