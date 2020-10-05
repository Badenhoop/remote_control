//
// Created by philipp on 13.08.19.
//

#ifndef REMOTE_CONTROL_UTILS_H
#define REMOTE_CONTROL_UTILS_H

namespace remoteControl
{

auto double2duration(double seconds)
{
	long long nanoseconds = seconds * 1000000000.0;
	return std::chrono::nanoseconds{nanoseconds};
}

}

#endif //REMOTE_CONTROL_UTILS_H
