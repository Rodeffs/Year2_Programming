#pragma once

class iNotifyPropertyChanged {
private:
	bool active;

protected:
	void (*functionNPC)();

public:
	explicit iNotifyPropertyChanged(bool act = false, void (*func)() = nullptr) : active{act}, functionNPC{func} {}

	void AddNPCListener() {
		active = true;
	}

	void RemoveNPCListener() {
		active = false;
	}

	bool NPCisActive() {
		return active;
	}

	virtual ~iNotifyPropertyChanged() = default;

	virtual void OnPropertyChanged(void (*f)()) = 0;
};
