#pragma once
#include "Job.h"
#include "LockQueue.h"

class JobQueue : public enable_shared_from_this<JobQueue> {
public:
	void DoAsync(CallbackType&& callback) {
		Push({ objectPool<Job>::alloc(std::move(callback)), objectPool<Job>::dealloc });
	}

	template<typename T, typename Ret, typename... Args>
	void DoAsync(Ret(T::*memFunc)(Args...), Args... args) {
		shared_ptr<T> ownerRef = static_pointer_cast<T>(shared_from_this());
		Push({ objectPool<Job>::alloc(ownerRef, memFunc, std::forward<Args>(args)...), objectPool<Job>::dealloc });
	}

	virtual void FlushJob() abstract;

private:
	void Push(shared_ptr<Job>&& job);
	void Execute();

protected:
	LockQueue<shared_ptr<Job>> _jobs;
	atomic<int32_t> _jobCount = 0;
};

