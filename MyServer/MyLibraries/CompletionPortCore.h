#pragma once

class CPObject : public enable_shared_from_this<CPObject> {
public:
	virtual HANDLE GetHandle() abstract;
	virtual void Dispatch(class CPTask* cptask, uint32_t NumOfBytes = 0) abstract;
};

class CPTask : public OVERLAPPED {
public:
	CPTask();
	void Init();

	shared_ptr<CPObject> owner;
};

class CPCore {
public:
	CPCore();
	~CPCore();

	HANDLE GetHandle() { return _handle; }
	bool Register(shared_ptr<CPObject> CPObjectRef);
	bool Dispatch(uint32_t timeoutMs = INFINITE);

private:
	HANDLE _handle;
};

