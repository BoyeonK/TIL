#include "pch.h"
#include "JobTimer.h"

void JobTimer::Reserve(uint64_t tickAfter, weak_ptr<JobQueue> owner, shared_ptr<Job> job) {
	const uint64_t executeTick = ::GetTickCount64() + tickAfter;
	JobData* pjobData = objectPool<JobData>::alloc(owner, job);

	WRITE_RWLOCK;
	_items.push(TimerItem{ executeTick, pjobData });
}

void JobTimer::Distrubute(uint64_t now) {
	//atomic변수이기때문에, exchange가 true로 리턴되면 누군가 이미 함수를 실행한 상황
	if (_distributing.exchange(true) == true)
		return;

	//Lock을 거는 시간을 최소로 하기 위해서
	vector<TimerItem> onTimeItems;
	{
		WRITE_RWLOCK;
		while (_items.empty() == false) {
			const TimerItem& timerItem = _items.top();
			if (now < timerItem.executeTick)
				break;
			onTimeItems.push_back(timerItem);
			_items.pop();
		}
	}

	for (TimerItem& item : onTimeItems) {
		if (shared_ptr<JobQueue> owner = item.pJobData->_owner.lock())
			owner->Push(item.pJobData->_job);

		objectPool<JobData>::dealloc(item.pJobData);
	}

	_distributing.store(false);
}

void JobTimer::Clear() {
	WRITE_RWLOCK;
	while (_items.empty() == false) {
		const TimerItem& timerItem = _items.top();
		objectPool<JobData>::dealloc(timerItem.pJobData);
		_items.pop();
	}
}
