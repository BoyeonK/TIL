#include "pch.h"
#include "JobQueue.h"

void JobQueue::Push(shared_ptr<Job>&& job) {
	const int32_t prevCount = _jobCount.fetch_add(1);
	_jobs.Push(job);
	if (prevCount == 0) {
		Execute();
	}
}

void JobQueue::Execute() {
	while (true) {
		vector<shared_ptr<Job>> jobs;
		_jobs.PopAll(jobs);
		const int32_t jobCount = static_cast<int32_t>(jobs.size());
		for (int32_t i = 0; i < jobCount; i++) {
			jobs[i]->Execute();
		}
		if (_jobCount.fetch_sub(jobCount) == jobCount) {
			return;
		}
	}
}
