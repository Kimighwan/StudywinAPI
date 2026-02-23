#pragma once

#define SINGLE(type) public:\
						static type* Instance() { static type instance; return &instance; }\
					private: type(); ~type();

#define fDeltaTime TimerMgr::Instance()->GetFDeltaTime()
#define DeltaTime TimerMgr::Instance()->GetDeltaTime()